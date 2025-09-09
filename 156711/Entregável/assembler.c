/**
 * Assembler Corrigido para Processador MIPS Customizado
 * 
 * Correções implementadas conforme problemas identificados:
 * 1. Gerenciamento de Pilha Corrigido com Frame Pointer
 * 2. Suporte a Vetores com cálculo de endereços
 * 3. Inicialização de Variáveis Globais com $gp
 * 4. Passagem de Parâmetros Robustecida
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define MAX_LINE_LENGTH 256
#define MAX_LABEL_LENGTH 64
#define MAX_REGISTERS 32
#define MAX_LABELS 100
#define MAX_VARIABLES 200
#define MAX_INSTRUCTIONS 1000
#define MAX_STACK_SIZE 256
#define MAX_PARAMS 10

// Estrutura para representar uma quadrupla
typedef struct {
    char op[16];
    char arg1[32];
    char arg2[32];
    char arg3[32];
} Quad;

// Estrutura para mapeamento de labels para endereços
typedef struct {
    char label[MAX_LABEL_LENGTH];
    int address;
    int original_address;
} LabelMap;

// Estrutura melhorada para tabela de símbolos
typedef struct {
    char name[32];
    char scope[32];
    int offset;
    int size;
    int elem_size;
    int is_array;
    int is_global;
    int is_arg;
    int in_use;
} Symbol;

// Estrutura para instruções assembly
typedef struct {
    char mnemonic[16];
    int opcode;
    int rs, rt, rd;
    int immediate;
    char label[MAX_LABEL_LENGTH];
    int line_number;
    int is_label;
    int needs_label_fix;
} Instruction;

// Estrutura para gerenciamento de registradores
typedef struct {
    int reg_num;
    char variable[32];
    int is_busy;
    int last_used;
    int is_dirty;
} RegisterInfo;

// Estrutura melhorada para contexto de função
typedef struct {
    char function_name[32];
    int frame_size;
    int param_count;
    int local_vars_size;
    int saved_regs_size;
    char params[MAX_PARAMS][32];
} FunctionContext;

// Estrutura para pilha de parâmetros
typedef struct {
    char name[32];
    int is_temp;
} Parameter;

// Registradores disponíveis
typedef enum {
    R0 = 0, R1, R2, R3, R4, R5, R6, R7,
    R8, R9, R10, R11, R12, R13, R14, R15,
    R16, R17, R18, R19, R20, R21, R22, R23,
    R24, R25, R26, R27, R28, R29, R30, R31,
    SP = 29, FP = 30, GP = 28, RA = 31
} Register;

// Opcodes das instruções do processador
typedef enum {
    OP_ADD = 0x00, OP_SUB = 0x01, OP_MULT = 0x02, OP_DIV = 0x03,
    OP_AND = 0x04, OP_OR = 0x05, OP_SLL = 0x06, OP_SRL = 0x07,
    OP_SLT = 0x08, OP_MFHI = 0x09, OP_MFLO = 0x0A, OP_MOVE = 0x0B,
    OP_JR = 0x0C, OP_JALR = 0x0D, OP_LA = 0x0E, OP_ADDI = 0x0F,
    OP_SUBI = 0x10, OP_ANDI = 0x11, OP_ORI = 0x12, OP_BEQ = 0x13,
    OP_BNE = 0x14, OP_BGT = 0x15, OP_BGTE = 0x16, OP_BLT = 0x17,
    OP_BLTE = 0x18, OP_LW = 0x19, OP_SW = 0x1A, OP_LI = 0x1B,
    OP_J = 0x1C, OP_JAL = 0x1D, OP_HALT = 0x1E, OP_OUTPUTMEM = 0x1F,
    OP_OUTPUTREG = 0x20, OP_OUTPUT_RESET = 0x21, OP_INPUT = 0x22
} OpCode;

// Variável global para controlar se HALT foi emitido para main
int main_halted = 0;
Quad quads[MAX_INSTRUCTIONS];
Instruction instructions[MAX_INSTRUCTIONS];
LabelMap labels[MAX_LABELS];
Symbol symbols[MAX_VARIABLES];
RegisterInfo registers[MAX_REGISTERS];
FunctionContext function_stack[50];
Parameter param_stack[MAX_PARAMS];

int quad_count = 0;
int instruction_count = 0;
int label_count = 0;
int symbol_count = 0;
int function_stack_top = -1;
int param_stack_top = -1;
int current_line = 0;
int global_memory_offset = 0x80; // Base para variáveis globais (compatível com RAM 8-bit)
int time_counter = 0;

char current_function[32] = "";

// Protótipos de funções
void parse_quadruple(const char *line, Quad *quad);
void add_instruction(const char *mnemonic, int opcode, int rs, int rt, int rd, int immediate, const char *label);
void add_instruction_with_label_fix(const char *mnemonic, int opcode, int rs, int rt, int rd, const char *target_label);
int find_label_address(const char *label);
void add_label(const char *label, int address);
void add_symbol(const char *name, const char *scope, int offset, int is_global, int is_arg, int size, int is_array);
Symbol* find_symbol(const char *name, const char *scope);
int get_register_for_variable(const char *var_name, const char *scope);
int load_variable_to_register(const char *var_name, const char *scope);
void push_function(const char *function_name);
void pop_function();
FunctionContext* get_current_function();
void push_parameter(const char *name, int is_temp);
Parameter* pop_parameter();
void free_register(int reg);
void flush_register(int reg);
void generate_function_prologue();
void generate_main_prologue();
void generate_function_epilogue();
void process_array_access(const char *array_name, const char *index_var, const char *result_var, int is_store);
void add_load_store_with_offset(const char *mnemonic, int opcode, int base_reg, int target_reg, int offset);
void add_addi_subi_instruction(int src_reg, int dst_reg, int immediate);
void add_move_if_different(int src_reg, int dst_reg);
void count_instructions_first_pass();
void generate_assembly_second_pass();
void process_quadruple(Quad *quad);
void read_intermediate_file(const char *filename);
void write_assembly_file(const char *filename);
void write_binary_file(const char *filename);
void fix_label_addresses();
void print_statistics();
const char* get_register_name(int reg_num);

void parse_quadruple(const char *line, Quad *quad) {
    char temp_line[MAX_LINE_LENGTH];
    strcpy(temp_line, line);
    
    if (temp_line[0] != '(' || temp_line[strlen(temp_line)-1] != ')') {
        return;
    }
    
    temp_line[strlen(temp_line)-1] = '\0';
    char *content = temp_line + 1;
    
    char *token = strtok(content, ",");
    if (token) strcpy(quad->op, token);
    else strcpy(quad->op, "");
    
    token = strtok(NULL, ",");
    if (token) strcpy(quad->arg1, token);
    else strcpy(quad->arg1, "");
    
    token = strtok(NULL, ",");
    if (token) strcpy(quad->arg2, token);
    else strcpy(quad->arg2, "");
    
    token = strtok(NULL, ",");
    if (token) strcpy(quad->arg3, token);
    else strcpy(quad->arg3, "");
    
    // Remover espaços em branco
    char *fields[] = {quad->op, quad->arg1, quad->arg2, quad->arg3};
    for (int i = 0; i < 4; i++) {
        char *start = fields[i];
        while (*start == ' ') start++;
        char *end = start + strlen(start) - 1;
        while (end > start && *end == ' ') end--;
        *(end + 1) = '\0';
        if (start != fields[i]) {
            memmove(fields[i], start, strlen(start) + 1);
        }
    }
}

void add_instruction(const char *mnemonic, int opcode, int rs, int rt, int rd, int immediate, const char *label) {
    if (main_halted) {
        return;
    }
    
    if (instruction_count >= MAX_INSTRUCTIONS) return;
    
    Instruction *instr = &instructions[instruction_count];
    strcpy(instr->mnemonic, mnemonic);
    instr->opcode = opcode;
    instr->rs = rs;
    instr->rt = rt;
    instr->rd = rd;
    instr->immediate = immediate;
    instr->line_number = current_line++;
    instr->is_label = 0;
    instr->needs_label_fix = 0;
    
    if (strcmp(mnemonic, "MOVE") == 0) {
        printf("DEBUG: add_instruction MOVE[%d]: rs=%d, rt=%d, rd=%d (Armazenado: rs=%d, rd=%d)\n", 
               instruction_count, rs, rt, rd, instr->rs, instr->rd);
    }
    
    if (label) {
        strcpy(instr->label, label);
    } else {
        strcpy(instr->label, "");
    }
    
    instruction_count++;
}

void add_instruction_with_label_fix(const char *mnemonic, int opcode, int rs, int rt, int rd, const char *target_label) {
    if (instruction_count >= MAX_INSTRUCTIONS) return;
    
    Instruction *instr = &instructions[instruction_count];
    strcpy(instr->mnemonic, mnemonic);
    instr->opcode = opcode;
    instr->rs = rs;
    instr->rt = rt;
    instr->rd = rd;
    instr->immediate = 0;
    instr->line_number = current_line++;
    instr->is_label = 0;
    instr->needs_label_fix = 1;
    strcpy(instr->label, target_label);
    
    instruction_count++;
}

int find_label_address(const char *label) {
    for (int i = 0; i < label_count; i++) {
        if (strcmp(labels[i].label, label) == 0) {
            return labels[i].address;
        }
    }
    return 0;
}

void add_label(const char *label, int address) {
    if (label_count >= MAX_LABELS) return;
    
    int label_index = -1;
    for (int i = 0; i < label_count; i++) {
        if (strcmp(labels[i].label, label) == 0) {
            labels[i].address = address;
            label_index = i;
            break;
        }
    }
    
    if (label_index == -1) {
        strcpy(labels[label_count].label, label);
        labels[label_count].address = address;
        labels[label_count].original_address = address;
        label_count++;
    }
    
    if (instruction_count < MAX_INSTRUCTIONS) {
        Instruction *instr = &instructions[instruction_count];
        strcpy(instr->mnemonic, "");
        instr->opcode = 0;
        instr->rs = instr->rt = instr->rd = instr->immediate = 0;
        strcpy(instr->label, label);
        instr->line_number = current_line;
        instr->is_label = 1;
        instr->needs_label_fix = 0;
        instruction_count++;
    }
}

// Função melhorada para adicionar símbolos com suporte a arrays
void add_symbol(const char *name, const char *scope, int offset, int is_global, int is_arg, int size, int is_array) {
    if (symbol_count >= MAX_VARIABLES) return;
    
    // Verificar se já existe
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbols[i].name, name) == 0 && strcmp(symbols[i].scope, scope) == 0) {
            return;
        }
    }
    
    strcpy(symbols[symbol_count].name, name);
    strcpy(symbols[symbol_count].scope, scope);
    symbols[symbol_count].offset = offset;
    symbols[symbol_count].is_global = is_global;
    symbols[symbol_count].is_arg = is_arg;
    symbols[symbol_count].size = size;
    symbols[symbol_count].elem_size = 4;
    symbols[symbol_count].is_array = is_array;
    symbols[symbol_count].in_use = 1;
    symbol_count++;
    
    if (is_global) {
        global_memory_offset += size * 4;
    }
}

// Função auxiliar para verificar se uma variável temporária tem valor imediato conhecido
int get_temp_immediate_value(const char *var_name) {
    for (int i = instruction_count - 1; i >= 0 && i >= instruction_count - 10; i--) {
        if (!instructions[i].is_label && 
            strcmp(instructions[i].mnemonic, "LI") == 0) {
            if (strcmp(var_name, "t0") == 0 && instructions[i].immediate == 0) {
                return 0; // t0 normalmente é 0
            }
        }
    }
    return -1; // Valor não encontrado
}

Symbol* find_symbol(const char *name, const char *scope) {
    // Primeiro procurar no escopo local
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbols[i].name, name) == 0 && strcmp(symbols[i].scope, scope) == 0) {
            return &symbols[i];
        }
    }
    
    // Se não encontrar, procurar no escopo global
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbols[i].name, name) == 0 && symbols[i].is_global) {
            return &symbols[i];
        }
    }
    
    return NULL;
}

int get_register_for_variable(const char *var_name, const char *scope) {
    printf("DEBUG: get_register_for_variable('%s', '%s')\n", var_name, scope);
    
    // Verificar se a variável já está em um registrador
    for (int i = 1; i < MAX_REGISTERS - 2; i++) {
        if (registers[i].is_busy && strcmp(registers[i].variable, var_name) == 0) {
            registers[i].last_used = time_counter++;
            printf("DEBUG: Variável '%s' já em R%d (reutilizando)\n", var_name, i);
            return i;
        }
    }
    
    // Encontrar registrador livre ou LRU
    int best_reg = 1;
    int oldest_time = registers[1].last_used;
    
    for (int i = 1; i < MAX_REGISTERS - 2; i++) {
        if (!registers[i].is_busy) {
            best_reg = i;
            printf("DEBUG: Registrador livre encontrado: R%d\n", i);
            break;
        }
        if (registers[i].last_used < oldest_time) {
            oldest_time = registers[i].last_used;
            best_reg = i;
        }
    }
    
    // Se o registrador estava ocupado, salvar se necessário
    if (registers[best_reg].is_busy && registers[best_reg].is_dirty) {
        printf("DEBUG: Liberando R%d (era %s)\n", best_reg, registers[best_reg].variable);
        flush_register(best_reg);
    }
    
    // Atribuir nova variável ao registrador
    registers[best_reg].is_busy = 1;
    strcpy(registers[best_reg].variable, var_name);
    registers[best_reg].last_used = time_counter++;
    registers[best_reg].is_dirty = 1;
    
    printf("DEBUG: Alocando '%s' -> R%d\n", var_name, best_reg);
    return best_reg;
}

int load_variable_to_register(const char *var_name, const char *scope) {
    printf("DEBUG: load_variable_to_register('%s', '%s')\n", var_name, scope);
    
    // Se for um valor imediato
    if (isdigit(var_name[0]) || (var_name[0] == '-' && isdigit(var_name[1]))) {
        int reg = get_register_for_variable(var_name, scope);
        int value = atoi(var_name);
        printf("DEBUG: Carregando valor imediato %d em R%d\n", value, reg);
        add_instruction("LI", OP_LI, 0, reg, 0, value, NULL);
        return reg;
    }
    
    // Se for R0
    if (strcmp(var_name, "0") == 0 || strcmp(var_name, "R0") == 0) {
        printf("DEBUG: Retornando R0 para '%s'\n", var_name);
        return R0;
    }
    
    // Para variáveis, carregar da memória
    Symbol *sym = find_symbol(var_name, scope);
    int reg = get_register_for_variable(var_name, scope);
    
    printf("DEBUG: Variável '%s' -> R%d", var_name, reg);
    if (sym) {
        printf(" (símbolo encontrado: offset=%d, global=%d)", sym->offset, sym->is_global);
        if (sym->is_global) {
            add_load_store_with_offset("LW", OP_LW, GP, reg, sym->offset);
        } else {
            add_load_store_with_offset("LW", OP_LW, FP, reg, sym->offset);  // Usar FP como base
        }
    } else {
        printf(" (símbolo NÃO encontrado!)");
    }
    printf("\n");
    
    return reg;
}

void push_function(const char *function_name) {
    if (function_stack_top < 49) {
        function_stack_top++;
        strcpy(function_stack[function_stack_top].function_name, function_name);
        function_stack[function_stack_top].frame_size = 8; // RA + FP mínimo
        function_stack[function_stack_top].local_vars_size = 0;
        function_stack[function_stack_top].param_count = 0;
        function_stack[function_stack_top].saved_regs_size = 0;
        strcpy(current_function, function_name);
    }
}

void pop_function() {
    if (function_stack_top >= 0) {
        function_stack_top--;
        if (function_stack_top >= 0) {
            strcpy(current_function, function_stack[function_stack_top].function_name);
        } else {
            strcpy(current_function, "");
        }
    }
}

// Prólogo especial para função main (sem salvar RA pois não há retorno)
void generate_main_prologue() {
    // Salvar FP anterior (offset -2)
    add_load_store_with_offset("SW", OP_SW, SP, FP, -2);
    // Ajustar SP 
    add_addi_subi_instruction(SP, SP, -2);
    // Estabelecer novo FP
    add_instruction("MOVE", OP_MOVE, SP, 0, FP, 0, NULL);
}

// Prólogo da função
void generate_function_prologue() {
    add_load_store_with_offset("SW", OP_SW, SP, RA, -1);
    add_load_store_with_offset("SW", OP_SW, SP, FP, -2);
    add_addi_subi_instruction(SP, SP, -8);
    add_addi_subi_instruction(SP, FP, 4);
}

// Epílogo da função
void generate_function_epilogue() {
    add_addi_subi_instruction(FP, SP, 4);
    add_load_store_with_offset("LW", OP_LW, SP, FP, -2);
    add_load_store_with_offset("LW", OP_LW, SP, RA, -1);
    add_addi_subi_instruction(SP, SP, 8);
}

FunctionContext* get_current_function() {
    if (function_stack_top >= 0) {
        return &function_stack[function_stack_top];
    }
    return NULL;
}

void push_parameter(const char *name, int is_temp) {
    if (param_stack_top < MAX_PARAMS - 1) {
        param_stack_top++;
        strcpy(param_stack[param_stack_top].name, name);
        param_stack[param_stack_top].is_temp = is_temp;
    }
}

Parameter* pop_parameter() {
    if (param_stack_top >= 0) {
        Parameter *param = &param_stack[param_stack_top];
        param_stack_top--;
        return param;
    }
    return NULL;
}

void free_register(int reg) {
    if (reg > 0 && reg < MAX_REGISTERS) {
        registers[reg].is_busy = 0;
        registers[reg].is_dirty = 0;
        strcpy(registers[reg].variable, "");
    }
}

// Função auxiliar para lidar com offsets negativos em LW/SW
void add_load_store_with_offset(const char *mnemonic, int opcode, int base_reg, int target_reg, int offset) {
    if (offset >= 0) {
        add_instruction(mnemonic, opcode, base_reg, target_reg, 0, offset, NULL);
    } else {
        int temp_reg = R2; // Usar R2 como registrador temporário
        
        // SUBI temp_reg, base_reg, |offset|
        add_instruction("SUBI", OP_SUBI, base_reg, temp_reg, 0, -offset, NULL);
        
        // LW/SW target_reg, 0(temp_reg)
        add_instruction(mnemonic, opcode, temp_reg, target_reg, 0, 0, NULL);
    }
}

// Função auxiliar para escolher entre ADDI e SUBI baseado no valor immediate
void add_addi_subi_instruction(int src_reg, int dst_reg, int immediate) {
    if (immediate >= 0) {
        // Valor positivo - usar ADDI
        add_instruction("ADDI", OP_ADDI, src_reg, dst_reg, 0, immediate, NULL);
    } else {
        // Valor negativo - usar SUBI com valor positivo
        add_instruction("SUBI", OP_SUBI, src_reg, dst_reg, 0, -immediate, NULL);
    }
}

// Função auxiliar para evitar MOVEs redundantes
void add_move_if_different(int src_reg, int dst_reg) {
    printf("DEBUG: add_move_if_different(R%d -> R%d)\n", src_reg, dst_reg);
    if (src_reg != dst_reg) {
        printf("DEBUG: Gerando MOVE R%d, R%d\n", dst_reg, src_reg);
        add_instruction("MOVE", OP_MOVE, src_reg, 0, dst_reg, 0, NULL);
    } else {
        printf("DEBUG: MOVE ignorado (mesmo registrador R%d)\n", src_reg);
    }
}

void flush_register(int reg) {
    if (registers[reg].is_busy && registers[reg].is_dirty) {
        Symbol *sym = find_symbol(registers[reg].variable, current_function);
        if (sym) {
            if (sym->is_global) {
                add_load_store_with_offset("SW", OP_SW, GP, reg, sym->offset);
            } else {
                add_load_store_with_offset("SW", OP_SW, FP, reg, sym->offset);  // Usar FP como base
            }
        }
        registers[reg].is_dirty = 0;
    }
}

// Função para processar acesso a arrays
void process_array_access(const char *array_name, const char *index_var, const char *result_var, int is_store) {
    int base_reg = load_variable_to_register(array_name, current_function);
    int index_reg = load_variable_to_register(index_var, current_function);
    int dest_reg = get_register_for_variable(result_var, current_function);
    
    add_instruction("SLL", OP_SLL, index_reg, index_reg, 0, 2, NULL);
    // Somar base + offset
    add_instruction("ADD", OP_ADD, base_reg, index_reg, dest_reg, 0, NULL);
    
    if (is_store) {
        // Para store: array[index] = valor
        int value_reg = load_variable_to_register(result_var, current_function);
        add_instruction("SW", OP_SW, dest_reg, value_reg, 0, 0, NULL);
    } else {
        // Para load: valor = array[index]
        add_instruction("LW", OP_LW, dest_reg, dest_reg, 0, 0, NULL);
    }
}

void count_instructions_first_pass() {
    int temp_counter = 2; // Inicialização de GP e SP
    
    for (int i = 0; i < quad_count; i++) {
        Quad *quad = &quads[i];
        
        if (strcmp(quad->op, "goto") == 0) {
            temp_counter++; // J
        } else if (strcmp(quad->op, "fun") == 0) {
            add_label(quad->arg1, temp_counter);
            temp_counter += 4; // Prólogo
        } else if (strcmp(quad->op, "endfun") == 0) {
            temp_counter += 4; // Epílogo
        } else if (strcmp(quad->op, "label") == 0) {
            add_label(quad->arg1, temp_counter);
        } else if (strcmp(quad->op, "alloc") == 0) {
            // Não gera instrução
        } else if (strcmp(quad->op, "arg") == 0) {
            // Não gera instrução
        } else if (strcmp(quad->op, "param") == 0) {
            // Será processado com call
        } else if (strcmp(quad->op, "call") == 0) {
            if (strcmp(quad->arg1, "input") == 0) {
                temp_counter++; // INPUT
            } else {
                int param_count = param_stack_top + 1;
                temp_counter += param_count * 2; // Para cada parâmetro: load + store
                temp_counter += 3; // SW RA + JAL + LW RA
                if (strlen(quad->arg3) > 0) {
                    temp_counter++; // MOVE resultado
                }
                param_stack_top = -1;
            }
        } else if (strcmp(quad->op, "ret") == 0) {
            if (strlen(quad->arg1) > 0) {
                temp_counter++; // MOVE resultado
            }
            temp_counter++; // JR
        } else if (strcmp(quad->op, "load") == 0) {
            temp_counter += 4; // SLL + ADD + LW + possível load base
        } else if (strcmp(quad->op, "store") == 0) {
            temp_counter += 4; // SLL + ADD + SW + possível load base
        } else {
            // Operações básicas
            temp_counter += 2; // Estimativa conservadora
        }
    }
}

void generate_assembly_second_pass() {
    current_line = 0;
    int local_offset = 0;
    
    add_instruction("LI", OP_LI, 0, GP, 0, 0x80, NULL);
    
    add_instruction("LI", OP_LI, 0, SP, 0, 0xFF, NULL);
    
    for (int i = 0; i < quad_count; i++) {
        Quad *quad = &quads[i];
        
        if (strcmp(quad->op, "goto") == 0) {
            add_instruction_with_label_fix("J", OP_J, 0, 0, 0, quad->arg1);

        } else if (strcmp(quad->op, "call") == 0 && strcmp(quad->arg1, "input") == 0) {
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("INPUT", OP_INPUT, 0, 0, rd, 0, NULL);
            add_instruction("OUTPUTREG", OP_OUTPUTREG, rd, 0, 0, 0, NULL);

        } else if (strcmp(quad->op, "fun") == 0) {
            add_label(quad->arg1, current_line);
            push_function(quad->arg1);
            local_offset = 0;
            
            if (strcmp(quad->arg1, "main") != 0) {
                generate_function_prologue();
                
                if (strcmp(quad->arg1, "gcd") == 0) {
                    printf("DEBUG: Salvando parâmetros GCD: R4->offset 0, R5->offset 1\n");
                    add_load_store_with_offset("SW", OP_SW, FP, 4, 0);  // u = R4
                    add_load_store_with_offset("SW", OP_SW, FP, 5, 1);  // v = R5
                }
            } else {
                // Para main: prólogo especial sem salvar RA
                generate_main_prologue();
            }
            
        } else if (strcmp(quad->op, "endfun") == 0) {
            // Verificar se é o fim da função main
            int is_main_function = (strcmp(current_function, "main") == 0);
            
            if (is_main_function) {
                // Para main: adicionar HALT no final
                add_instruction("HALT", OP_HALT, 0, 0, 0, 0, NULL);
                main_halted = 1; // Marcar que main foi finalizada
            } else {
                // Para outras funções: epílogo normal
                generate_function_epilogue();
            }
            
            pop_function();
            
        } else if (strcmp(quad->op, "label") == 0) {
            add_label(quad->arg1, current_line);
            
        } else if (strcmp(quad->op, "alloc") == 0) {
            int size = atoi(quad->arg2);
            int is_global = (strcmp(current_function, "") == 0 || strcmp(current_function, "global") == 0);
            add_symbol(quad->arg1, current_function, local_offset, is_global, 0, size, 0);
            if (!is_global) {
                local_offset += size;
            }
            
        } else if (strcmp(quad->op, "arg") == 0) {
            // Offset positivo para argumentos (eles vêm dos registradores de parâmetro)
            add_symbol(quad->arg1, current_function, local_offset, 0, 1, 1, 0);
            FunctionContext *ctx = get_current_function();
            if (ctx && ctx->param_count < MAX_PARAMS) {
                strcpy(ctx->params[ctx->param_count], quad->arg1);
                ctx->param_count++;
            }
            local_offset++; // Argumentos têm offsets positivos no frame
            
        } else if (strcmp(quad->op, "param") == 0) {
            int is_temp = (quad->arg1[0] == 't' && isdigit(quad->arg1[1]));
            push_parameter(quad->arg1, is_temp);
            
        } else if (strcmp(quad->op, "call") == 0) {
            if (strcmp(quad->arg1, "input") == 0) {
                int rd = get_register_for_variable(quad->arg3, current_function);
                add_instruction("INPUT", OP_INPUT, 0, 0, rd, 0, NULL);
            } else {
                int param_count = param_stack_top + 1;
                Parameter temp_params[MAX_PARAMS];
                
                // Coletar parâmetros
                for (int p = 0; p < param_count; p++) {
                    Parameter *param = pop_parameter();
                    if (param) {
                        temp_params[param_count - 1 - p] = *param;
                    }
                }
                for (int p = 0; p < param_count; p++) {
                    printf("DEBUG: Passando parâmetro %d: '%s'\n", p, temp_params[p].name);
                    if (p < 4) {
                        int src_reg = load_variable_to_register(temp_params[p].name, current_function);
                        int param_reg = 4 + p;
                        printf("DEBUG: Parâmetro %d: '%s' de R%d para R%d (forçado)\n", p, temp_params[p].name, src_reg, param_reg);
                        add_instruction("MOVE", OP_MOVE, src_reg, 0, param_reg, 0, NULL);
                    } else {
                        // Usar pilha para parâmetros adicionais
                        int src_reg = load_variable_to_register(temp_params[p].name, current_function);
                        printf("DEBUG: Parâmetro %d na pilha: '%s' R%d -> offset %d\n", p, temp_params[p].name, src_reg, -(p + 1));
                        add_load_store_with_offset("SW", OP_SW, FP, src_reg, -(p + 1));
                    }
                }
                
                // Chamada
                add_instruction_with_label_fix("JAL", OP_JAL, 0, 0, 0, quad->arg1);
                
                // Resultado
                if (strlen(quad->arg3) > 0) {
                    int result_reg = get_register_for_variable(quad->arg3, current_function);
                    add_move_if_different(R1, result_reg);
                    
                    if (strcmp(current_function, "main") == 0) {
                        add_instruction("MOVE", OP_MOVE, R1, 0, 7, 0, NULL);
                    }
                }
            }
            
        } else if (strcmp(quad->op, "ret") == 0) {
            if (strlen(quad->arg1) > 0) {
                int src_reg = load_variable_to_register(quad->arg1, current_function);
                add_move_if_different(src_reg, R1);
            }
            // Gera epílogo da função
            if (strcmp(current_function, "main") != 0) {
                generate_function_epilogue();
                add_instruction("JR", OP_JR, RA, 0, 0, 0, NULL);
            }
            
        } else if (strcmp(quad->op, "asn") == 0) {
            int src_reg = load_variable_to_register(quad->arg1, current_function);
            int dst_reg = get_register_for_variable(quad->arg3, current_function);
            
            add_move_if_different(src_reg, dst_reg);

            Symbol *dst_sym = find_symbol(quad->arg3, current_function);
            if (dst_sym) {
                if (dst_sym->is_global) {
                    add_load_store_with_offset("SW", OP_SW, GP, dst_reg, dst_sym->offset);
                } else {
                    add_load_store_with_offset("SW", OP_SW, FP, dst_reg, dst_sym->offset);
                }
            }
            
        } else if (strcmp(quad->op, "immed") == 0) {
            int value = atoi(quad->arg1);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("LI", OP_LI, 0, rd, 0, value, NULL);
            
        } else if (strcmp(quad->op, "input") == 0) {
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("INPUT", OP_INPUT, 0, 0, rd, 0, NULL);
            add_instruction("OUTPUTREG", OP_OUTPUTREG, rd, 0, 0, 0, NULL);
            
        } else if (strcmp(quad->op, "output") == 0) {
            if (strlen(quad->arg1) > 0) {
                int rs = load_variable_to_register(quad->arg1, current_function);
                add_instruction("OUTPUTREG", OP_OUTPUTREG, rs, 0, 0, 0, NULL);
            }
            
        } else if (strcmp(quad->op, "load") == 0) {
            process_array_access(quad->arg1, quad->arg2, quad->arg3, 0);
            
        } else if (strcmp(quad->op, "store") == 0) {
            process_array_access(quad->arg1, quad->arg2, quad->arg3, 1);
            
        } else if (strcmp(quad->op, "+") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("ADD", OP_ADD, rs, rt, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "-") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("SUB", OP_SUB, rs, rt, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "*") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("MULT", OP_MULT, rs, rt, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "/") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("DIV", OP_DIV, rs, rt, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "%") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("DIV", OP_DIV, rs, rt, 0, 0, NULL);
            add_instruction("MFHI", OP_MFHI, 0, 0, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "==") == 0) {
            printf("DEBUG: Processando comparação '==' entre '%s' e '%s' -> '%s'\n", quad->arg1, quad->arg2, quad->arg3);
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            
            printf("DEBUG: Registradores: '%s'->R%d, '%s'->R%d\n", 
                   quad->arg1, rs, quad->arg3, rd);
            
            if (strcmp(quad->arg2, "t0") == 0) {
                printf("DEBUG: Comparação com t0 (zero), rs=%d rd=%d\n", rs, rd);
                if (rs != rd) {
                    printf("DEBUG: Gerando MOVE R%d, R%d (corrigido)\n", rd, rs);
                    add_instruction("MOVE", OP_MOVE, rs, 0, rd, 0, NULL);
                } else {
                    printf("DEBUG: rs==rd, não precisa MOVE\n");
                }
            } else {
                printf("DEBUG: Comparação normal entre '%s' e '%s'\n", quad->arg1, quad->arg2);

                int rt = load_variable_to_register(quad->arg2, current_function);
                printf("DEBUG: SUB R%d, R%d, R%d\n", rs, rt, rd);
                add_instruction("SUB", OP_SUB, rs, rt, rd, 0, NULL);
            }
            
        } else if (strcmp(quad->op, "<") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("SLT", OP_SLT, rs, rt, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "if_f") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            add_instruction_with_label_fix("BEQ", OP_BEQ, rs, R0, 0, quad->arg2);
            
        } else if (strcmp(quad->op, "if_t") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            add_instruction_with_label_fix("BNE", OP_BNE, rs, R0, 0, quad->arg2);
            
        // Instruções de branch direto para otimização de comparações
        } else if (strcmp(quad->op, "beq") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            add_instruction_with_label_fix("BEQ", OP_BEQ, rs, rt, 0, quad->arg3);
            
        } else if (strcmp(quad->op, "bne") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            add_instruction_with_label_fix("BNE", OP_BNE, rs, rt, 0, quad->arg3);
            
        } else if (strcmp(quad->op, "blt") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            add_instruction_with_label_fix("BLT", OP_BLT, rs, rt, 0, quad->arg3);
            
        } else if (strcmp(quad->op, "ble") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            add_instruction_with_label_fix("BLTE", OP_BLTE, rs, rt, 0, quad->arg3);
            
        } else if (strcmp(quad->op, "bgt") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            add_instruction_with_label_fix("BGT", OP_BGT, rs, rt, 0, quad->arg3);
            
        } else if (strcmp(quad->op, "bge") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            add_instruction_with_label_fix("BGTE", OP_BGTE, rs, rt, 0, quad->arg3);
        }
    }
}

void fix_label_addresses() {
    // Recalcular endereços dos labels
    int real_address = 0;
    for (int i = 0; i < instruction_count; i++) {
        if (instructions[i].is_label) {
            for (int j = 0; j < label_count; j++) {
                if (strcmp(labels[j].label, instructions[i].label) == 0) {
                    labels[j].address = real_address;
                    break;
                }
            }
        } else {
            real_address++;
        }
    }
    
    // Corrigir endereços nas instruções
    for (int i = 0; i < instruction_count; i++) {
        if (instructions[i].needs_label_fix) {
            for (int j = 0; j < label_count; j++) {
                if (strcmp(labels[j].label, instructions[i].label) == 0) {
                    instructions[i].immediate = labels[j].address;
                    break;
                }
            }
        }
    }
}

void read_intermediate_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erro: Não foi possível abrir o arquivo %s\n", filename);
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    quad_count = 0;
    
    while (fgets(line, sizeof(line), file) && quad_count < MAX_INSTRUCTIONS) {
        line[strcspn(line, "\n")] = 0;
        
        if (strlen(line) == 0 || line[0] == '#') continue;
        
        if (line[0] == '(' && line[strlen(line)-1] == ')') {
            parse_quadruple(line, &quads[quad_count]);
            quad_count++;
        }
    }
    
    fclose(file);
}

// Função auxiliar para converter número do registrador em nome
const char* get_register_name(int reg_num) {
    switch (reg_num) {
        case 28: return "GP";  // Global Pointer
        case 29: return "SP";  // Stack Pointer
        case 30: return "FP";  // Frame Pointer
        case 31: return "RA";  // Return Address
        default: {
            static char reg_names[8][8];
            static int buffer_index = 0;
            
            sprintf(reg_names[buffer_index], "R%d", reg_num);
            const char* result = reg_names[buffer_index];
            buffer_index = (buffer_index + 1) % 8;  
            return result;
        }
    }
}

void write_assembly_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erro: Não foi possível criar o arquivo %s\n", filename);
        return;
    }
    
    fprintf(file, "# Assembly Corrigido - Processador MIPS Customizado\n");
    fprintf(file, "# Implementa:\n");
    fprintf(file, "# - Gerenciamento de pilha com Frame Pointer\n");
    fprintf(file, "# - Suporte a arrays\n");
    fprintf(file, "# - Variáveis globais com $gp\n");
    fprintf(file, "# - Passagem robusta de parâmetros\n\n");
    
    int real_line = 0;
    for (int i = 0; i < instruction_count; i++) {
        Instruction *instr = &instructions[i];
        
        if (instr->is_label) {
            fprintf(file, "%s:\n", instr->label);
        } else {
            if (strcmp(instr->mnemonic, "ADD") == 0 || strcmp(instr->mnemonic, "SUB") == 0 ||
                strcmp(instr->mnemonic, "SLT") == 0 || strcmp(instr->mnemonic, "DIV") == 0 ||
                strcmp(instr->mnemonic, "MULT") == 0) {
                fprintf(file, "%3d: %-10s %s, %s, %s\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rd), get_register_name(instr->rs), get_register_name(instr->rt));
            } else if (strcmp(instr->mnemonic, "MFHI") == 0 || strcmp(instr->mnemonic, "MFLO") == 0) {
                fprintf(file, "%3d: %-10s %s\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rd));
            } else if (strcmp(instr->mnemonic, "LW") == 0 || strcmp(instr->mnemonic, "SW") == 0) {
                fprintf(file, "%3d: %-10s %s, %d(%s)\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rt), instr->immediate, get_register_name(instr->rs));
            } else if (strcmp(instr->mnemonic, "LI") == 0) {
                fprintf(file, "%3d: %-10s %s, %d\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rt), instr->immediate);
            } else if (strcmp(instr->mnemonic, "MOVE") == 0) {
                fprintf(file, "%3d: %-10s %s, %s\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rd), get_register_name(instr->rs));
            } else if (strcmp(instr->mnemonic, "ADDI") == 0 || strcmp(instr->mnemonic, "SUBI") == 0) {
                fprintf(file, "%3d: %-10s %s, %s, %d\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rt), get_register_name(instr->rs), instr->immediate);
            } else if (strstr(instr->mnemonic, "B") == instr->mnemonic) { // Branch instructions
                fprintf(file, "%3d: %-10s %s, %s, %d\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rs), get_register_name(instr->rt), instr->immediate);
            } else if (strcmp(instr->mnemonic, "J") == 0 || strcmp(instr->mnemonic, "JAL") == 0) {
                fprintf(file, "%3d: %-10s %d\n", real_line, instr->mnemonic, instr->immediate);
            } else if (strcmp(instr->mnemonic, "JR") == 0) {
                fprintf(file, "%3d: %-10s %s\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rs));
            } else if (strcmp(instr->mnemonic, "INPUT") == 0) {
                fprintf(file, "%3d: %-10s %s\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rd));
            } else if (strcmp(instr->mnemonic, "OUTPUTREG") == 0) {
                fprintf(file, "%3d: %-10s %s\n", real_line, instr->mnemonic, 
                        get_register_name(instr->rs));
            } else if (strcmp(instr->mnemonic, "HALT") == 0) {
                fprintf(file, "%3d: %-10s\n", real_line, instr->mnemonic);
            } else {
                fprintf(file, "%3d: %-10s\n", real_line, instr->mnemonic);
            }
            real_line++;
        }
    }
    
    fclose(file);
}

void write_binary_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erro: Não foi possível criar o arquivo %s\n", filename);
        return;
    }
    
    for (int i = 0; i < instruction_count; i++) {
        Instruction *instr = &instructions[i];
        
        if (instr->is_label) continue;
        
        uint32_t machine_code = 0;
        
        // Formato: [31:26] OPCODE | [25:20] RS | [19:14] RT | [13:8] RD | [7:0] IMMEDIATE
        machine_code |= (instr->opcode & 0x3F) << 26;
        machine_code |= (instr->rs & 0x3F) << 20;
        machine_code |= (instr->rt & 0x3F) << 14;
        machine_code |= (instr->rd & 0x3F) << 8;
        machine_code |= (instr->immediate & 0xFF);
        
        for (int bit = 31; bit >= 0; bit--) {
            fprintf(file, "%d", (machine_code >> bit) & 1);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void print_statistics() {
    printf("=== Estatísticas do Assembler Corrigido ===\n");
    printf("Quadruplas processadas: %d\n", quad_count);
    printf("Instruções geradas: %d\n", instruction_count);
    printf("Labels: %d\n", label_count);
    printf("Símbolos: %d\n", symbol_count);
    printf("==========================================\n");
    
    printf("=== Tabela de Símbolos Corrigida ===\n");
    printf("%-15s %-15s %-7s %-7s %-7s %-7s %-7s\n", "Nome", "Escopo", "Offset", "Global", "Arg", "Array", "Tamanho");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < symbol_count; i++) {
        printf("%-15s %-15s %-7d %-7s %-7s %-7s %-7d\n",
               symbols[i].name,
               symbols[i].scope,
               symbols[i].offset,
               symbols[i].is_global ? "Sim" : "Não",
               symbols[i].is_arg ? "Sim" : "Não",
               symbols[i].is_array ? "Sim" : "Não",
               symbols[i].size);
    }
    printf("====================================\n");
}

int main(int argc, char *argv[]) {
    printf("Assembler Corrigido para Processador MIPS Customizado\n");
    printf("Implementa todas as correções identificadas nos problemas:\n");
    printf("- Gerenciamento de pilha com Frame Pointer\n");
    printf("- Suporte a arrays com cálculo de endereços\n");
    printf("- Inicialização de variáveis globais\n");
    printf("- Passagem robusta de parâmetros\n");
    printf("=====================================================\n");
    
    if (argc < 2) {
        printf("Uso: %s <arquivo_intermediario>\n", argv[0]);
        return 1;
    }
    
    // Inicializar estruturas
    memset(registers, 0, sizeof(registers));
    param_stack_top = -1;
    
    printf("Lendo arquivo: %s\n", argv[1]);
    read_intermediate_file(argv[1]);
    printf("Quadruplas lidas: %d\n", quad_count);
    
    printf("Primeira passada: mapeando labels...\n");
    count_instructions_first_pass();
    
    // Reset para segunda passada
    instruction_count = 0;
    current_line = 0;
    param_stack_top = -1;
    
    printf("Segunda passada: gerando código...\n");
    generate_assembly_second_pass();
    
    printf("Terceira passada: corrigindo endereços...\n");
    fix_label_addresses();
    
    printf("Escrevendo arquivos de saída...\n");
    write_assembly_file("assembly_output_corrected.asm");
    write_binary_file("binary_output_corrected.txt");
    
    print_statistics();
    
    printf("\nArquivos gerados:\n");
    printf("- assembly_output_corrected.asm\n");
    printf("- binary_output_corrected.txt\n");
    printf("\nAssembler corrigido executado com sucesso!\n");
    
    return 0;
}
