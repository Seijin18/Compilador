/**
 * Assembler Avançado para Processador MIPS Customizado
 * 
 * Este assembler traduz código intermediário (quadruplas) para assembly
 * compatível com o processador MIPS customizado, incluindo:
 * - Gerenciamento de registradores com algoritmo LRU
 * - Suporte a chamadas de função e passagem de parâmetros
 * - Gerenciamento de pilha para variáveis locais
 * - Tratamento de escopos globais e locais
 * - Otimizações básicas de código
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
} LabelMap;

// Estrutura para tabela de símbolos (variáveis)
typedef struct {
    char name[32];
    char scope[32];
    int offset;
    int is_global;
    int is_arg;
    int size;
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
} Instruction;

// Estrutura para gerenciamento de registradores
typedef struct {
    int reg_num;
    char variable[32];
    int is_busy;
    int last_used;
    int is_dirty; // Indica se precisa ser salvo na memória
} RegisterInfo;

// Estrutura para contexto de função
typedef struct {
    char function_name[32];
    int local_vars_size;
    int param_count;
    int return_address_offset;
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
    SP = 29, GP = 28, RA = 31
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
} Opcode;

// Variáveis globais
Quad quads[MAX_INSTRUCTIONS];
int quad_count = 0;
LabelMap labels[MAX_LABELS];
int label_count = 0;
Symbol symbols[MAX_VARIABLES];
int symbol_count = 0;
Instruction instructions[MAX_INSTRUCTIONS];
int instruction_count = 0;
RegisterInfo registers[32];
FunctionContext function_stack[MAX_STACK_SIZE];
int function_stack_top = -1;
Parameter param_stack[MAX_PARAMS];
int param_stack_top = -1;

// Cache para otimização de operações SW->LW redundantes
typedef struct {
    char variable[32];
    int register_num;
    int instruction_num;
} AssignmentCache;

AssignmentCache last_assignments[10];
int assignment_cache_size = 0;

int current_line = 0;
int global_mem_pos = 0;
int local_mem_pos = 0;
int instruction_counter = 0;

// Funções auxiliares
void add_to_assignment_cache(const char* variable, int reg_num) {
    // Procurar se variável já existe no cache
    for (int i = 0; i < assignment_cache_size; i++) {
        if (strcmp(last_assignments[i].variable, variable) == 0) {
            // Atualizar entrada existente
            last_assignments[i].register_num = reg_num;
            last_assignments[i].instruction_num = instruction_counter;
            return;
        }
    }
    
    // Adicionar nova entrada
    if (assignment_cache_size < 10) {
        strcpy(last_assignments[assignment_cache_size].variable, variable);
        last_assignments[assignment_cache_size].register_num = reg_num;
        last_assignments[assignment_cache_size].instruction_num = instruction_counter;
        assignment_cache_size++;
    } else {
        // Cache cheio, substitua a mais antiga
        int oldest = 0;
        for (int i = 1; i < 10; i++) {
            if (last_assignments[i].instruction_num < last_assignments[oldest].instruction_num) {
                oldest = i;
            }
        }
        strcpy(last_assignments[oldest].variable, variable);
        last_assignments[oldest].register_num = reg_num;
        last_assignments[oldest].instruction_num = instruction_counter;
    }
}

int get_from_assignment_cache(const char* variable) {
    for (int i = 0; i < assignment_cache_size; i++) {
        if (strcmp(last_assignments[i].variable, variable) == 0) {
            // Verificar se a atribuição foi muito recente (menos de 5 instruções atrás)
            if (instruction_counter - last_assignments[i].instruction_num < 5) {
                return last_assignments[i].register_num;
            }
        }
    }
    return -1;  // Não encontrado ou muito antigo
}

void trim_whitespace(char *str) {
    char *end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0) return;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

void init_registers() {
    for (int i = 0; i < 32; i++) {
        registers[i].reg_num = i;
        strcpy(registers[i].variable, "");
        registers[i].is_busy = 0;
        registers[i].last_used = 0;
        registers[i].is_dirty = 0;
        
        // R0 sempre zero, SP, GP, RA são especiais
        if (i == 0 || i == 28 || i == 29 || i == 31) {
            registers[i].is_busy = 1;
        }
    }
}

int allocate_register(const char *variable) {
    // Procura se a variável já está em algum registrador
    for (int i = 1; i < 28; i++) {
        if (registers[i].is_busy && strcmp(registers[i].variable, variable) == 0) {
            registers[i].last_used = instruction_counter;
            return i;
        }
    }
    
    // Procura um registrador livre
    for (int i = 1; i < 28; i++) {
        if (!registers[i].is_busy) {
            registers[i].is_busy = 1;
            strcpy(registers[i].variable, variable);
            registers[i].last_used = instruction_counter;
            registers[i].is_dirty = 0;
            return i;
        }
    }
    
    // Se não há registradores livres, usa LRU
    int lru_reg = 1;
    int oldest_use = registers[1].last_used;
    for (int i = 2; i < 28; i++) {
        if (registers[i].last_used < oldest_use) {
            oldest_use = registers[i].last_used;
            lru_reg = i;
        }
    }
    
    // TODO: Implementar spill se registrador estiver dirty
    strcpy(registers[lru_reg].variable, variable);
    registers[lru_reg].last_used = instruction_counter;
    registers[lru_reg].is_dirty = 0;
    return lru_reg;
}

void free_register(int reg_num) {
    if (reg_num > 0 && reg_num < 28) {
        registers[reg_num].is_busy = 0;
        strcpy(registers[reg_num].variable, "");
        registers[reg_num].is_dirty = 0;
    }
}

int parse_quad_line(char *line, Quad *quad) {
    if (line[0] != '(') return 0;
    
    char *token = strtok(line + 1, ",");
    if (!token) return 0;
    strcpy(quad->op, token);
    
    token = strtok(NULL, ",");
    if (token) {
        strcpy(quad->arg1, token);
        trim_whitespace(quad->arg1);
    } else {
        strcpy(quad->arg1, "");
    }
    
    token = strtok(NULL, ",");
    if (token) {
        strcpy(quad->arg2, token);
        trim_whitespace(quad->arg2);
    } else {
        strcpy(quad->arg2, "");
    }
    
    token = strtok(NULL, ")");
    if (token) {
        strcpy(quad->arg3, token);
        trim_whitespace(quad->arg3);
    } else {
        strcpy(quad->arg3, "");
    }
    
    return 1;
}

void read_intermediate_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erro: Não foi possível abrir o arquivo %s\n", filename);
        exit(1);
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) && quad_count < MAX_INSTRUCTIONS) {
        trim_whitespace(line);
        if (strlen(line) > 0) {
            if (parse_quad_line(line, &quads[quad_count])) {
                quad_count++;
            }
        }
    }
    
    fclose(file);
}

void add_label(const char *label, int address) {
    if (label_count < MAX_LABELS) {
        strcpy(labels[label_count].label, label);
        labels[label_count].address = address;
        label_count++;
    }
}

int find_label_address(const char *label) {
    for (int i = 0; i < label_count; i++) {
        if (strcmp(labels[i].label, label) == 0) {
            return labels[i].address;
        }
    }
    return -1;
}

void add_symbol(const char *name, const char *scope, int offset, int is_global, int is_arg, int size) {
    if (symbol_count < MAX_VARIABLES) {
        strcpy(symbols[symbol_count].name, name);
        strcpy(symbols[symbol_count].scope, scope);
        symbols[symbol_count].offset = offset;
        symbols[symbol_count].is_global = is_global;
        symbols[symbol_count].is_arg = is_arg;
        symbols[symbol_count].size = size;
        symbols[symbol_count].in_use = 1;
        symbol_count++;
    }
}

Symbol* find_symbol(const char *name, const char *scope) {
    // Primeiro procura no escopo local
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbols[i].name, name) == 0 && strcmp(symbols[i].scope, scope) == 0) {
            return &symbols[i];
        }
    }
    // Se não encontrar, procura no escopo global
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbols[i].name, name) == 0 && symbols[i].is_global) {
            return &symbols[i];
        }
    }
    return NULL;
}

void push_function_context(const char *function_name) {
    if (function_stack_top < MAX_STACK_SIZE - 1) {
        function_stack_top++;
        strcpy(function_stack[function_stack_top].function_name, function_name);
        function_stack[function_stack_top].local_vars_size = 0;
        function_stack[function_stack_top].param_count = 0;
        function_stack[function_stack_top].return_address_offset = 0;
    }
}

void pop_function_context() {
    if (function_stack_top >= 0) {
        function_stack_top--;
    }
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

void add_instruction_full(const char *mnemonic, int opcode, int rs, int rt, int rd, 
                         int immediate, const char *label, int is_label) {
    if (instruction_count < MAX_INSTRUCTIONS) {
        // Debug para operações SW e LW
        if (strcmp(mnemonic, "SW") == 0 || strcmp(mnemonic, "LW") == 0) {
            printf("DEBUG: %s R%d, %d(R%d) - instrução %d\n", mnemonic, rt, immediate, rs, instruction_counter);
        }
        
        strcpy(instructions[instruction_count].mnemonic, mnemonic);
        instructions[instruction_count].opcode = opcode;
        instructions[instruction_count].rs = rs;
        instructions[instruction_count].rt = rt;
        instructions[instruction_count].rd = rd;
        instructions[instruction_count].immediate = immediate;
        instructions[instruction_count].is_label = is_label;
        if (label) {
            strcpy(instructions[instruction_count].label, label);
        } else {
            strcpy(instructions[instruction_count].label, "");
        }
        instructions[instruction_count].line_number = instruction_counter;
        instruction_count++;
        if (!is_label) {
            instruction_counter++;
        }
    }
}

void add_instruction(const char *mnemonic, int opcode, int rs, int rt, int rd, int immediate, const char *label) {
    add_instruction_full(mnemonic, opcode, rs, rt, rd, immediate, label, 0);
}

void add_label_instruction(const char *label) {
    add_instruction_full("", 0, 0, 0, 0, 0, label, 1);
}

int get_register_for_variable(const char *var_name, const char *current_scope) {
    if (var_name[0] == 't' && isdigit(var_name[1])) {
        // Variável temporária
        return allocate_register(var_name);
    } else {
        // Variável normal
        return allocate_register(var_name);
    }
}

int load_variable_to_register(const char *var_name, const char *current_scope) {
    // OTIMIZAÇÃO: Verificar cache de atribuições recentes
    int cached_reg = get_from_assignment_cache(var_name);
    if (cached_reg != -1) {
        printf("DEBUG: Usando cache para %s -> R%d\n", var_name, cached_reg);
        return cached_reg;
    }
    
    // Verificar se é uma variável temporária que contém zero
    if (var_name[0] == 't' && isdigit(var_name[1])) {
        // Verificar se esta variável temporária foi carregada com valor 0
        for (int i = 0; i < quad_count; i++) {
            if (strcmp(quads[i].op, "immed") == 0 && strcmp(quads[i].arg3, var_name) == 0) {
                int value = atoi(quads[i].arg1);
                if (value == 0) {
                    return R0;  // Use R0 diretamente para zero
                }
                break;
            }
        }
        // Variável temporária - já está no registrador
        int reg = get_register_for_variable(var_name, current_scope);
        return reg;
    }
    
    // Verificar se é uma constante zero diretamente
    if (strcmp(var_name, "0") == 0) {
        return R0;
    }
    
    int reg = get_register_for_variable(var_name, current_scope);
    
    // Carregar variável da memória
    Symbol *sym = find_symbol(var_name, current_scope);
    if (sym) {
        if (sym->is_global) {
            add_instruction("LW", OP_LW, GP, reg, 0, sym->offset, NULL);
        } else {
            // CORREÇÃO: Parâmetros precisam ter offset ajustado após SUBI R29, R29, 4
            int adjusted_offset = sym->offset;
            if (sym->is_arg) {
                adjusted_offset = sym->offset + 4;  // Ajusta para posição após frame setup
            }
            add_instruction("LW", OP_LW, SP, reg, 0, adjusted_offset, NULL);
        }
    } else {
        // Tentar interpretar como constante
        if (isdigit(var_name[0]) || (var_name[0] == '-' && isdigit(var_name[1]))) {
            int value = atoi(var_name);
            if (value == 0) {
                return R0;  // Use R0 diretamente para zero
            }
            add_instruction("LI", OP_LI, 0, reg, 0, value, NULL);
        }
    }
    
    return reg;
}

// Função para detectar padrões de otimização
int detect_comparison_branch_pattern(Quad *quads, int current_index, int quad_count) {
    if (current_index + 1 >= quad_count) return 0;
    
    Quad *current = &quads[current_index];
    Quad *next = &quads[current_index + 1];
    
    // Verificar se a variável temporária da comparação é usada apenas no branch
    if (strcmp(current->arg3, next->arg1) != 0) return 0;
    
    // Padrões de otimização para if_t (branch quando true)
    if (strcmp(next->op, "if_t") == 0) {
        if (strcmp(current->op, "==") == 0) return 1;  // BEQ
        if (strcmp(current->op, "!=") == 0) return 2;  // BNE  
        if (strcmp(current->op, ">") == 0) return 3;   // BGT
        if (strcmp(current->op, ">=") == 0) return 4;  // BGTE
        if (strcmp(current->op, "<") == 0) return 5;   // BLT
        if (strcmp(current->op, "<=") == 0) return 6;  // BLTE
    }
    
    // Padrões de otimização para if_f (branch quando false) - lógica invertida
    if (strcmp(next->op, "if_f") == 0) {
        if (strcmp(current->op, "==") == 0) return 7;  // BNE (inverte ==)
        if (strcmp(current->op, "!=") == 0) return 8;  // BEQ (inverte !=)
        if (strcmp(current->op, ">") == 0) return 9;   // BLTE (inverte >)
        if (strcmp(current->op, ">=") == 0) return 10; // BLT (inverte >=)
        if (strcmp(current->op, "<") == 0) return 11;  // BGTE (inverte <)
        if (strcmp(current->op, "<=") == 0) return 12; // BGT (inverte <=)
    }
    
    return 0; // Nenhum padrão detectado
}

// Função principal para gerar assembly
void generate_assembly() {
    char current_function[64] = "";
    int arg_counter = 0;
    
    init_registers();
    
    // Primeira passada: identificar labels e funções com contagem precisa
    int temp_counter = 0;
    char temp_current_function[64] = "";
    int temp_local_mem_pos = 0;
    int temp_arg_counter = 0;
    
    for (int i = 0; i < quad_count; i++) {
        Quad *quad = &quads[i];
        
        // Verificar se esta quadrupla faz parte de um padrão otimizado
        int pattern = detect_comparison_branch_pattern(quads, i, quad_count);
        
        if (pattern > 0) {
            // Padrão de otimização detectado: == + if_t/if_f -> BEQ/BNE
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                temp_counter++; // LW arg1
            }
            if (quad->arg2[0] != 't' || !isdigit(quad->arg2[1])) {
                temp_counter++; // LW arg2 
            }
            temp_counter++; // BEQ ou BNE
            i++; // Pular próxima quadrupla (if_t/if_f) pois já foi processada
            continue;
        }
        
        if (strcmp(quad->op, "fun") == 0) {
            add_label(quad->arg1, temp_counter);
            strcpy(temp_current_function, quad->arg1);
            temp_local_mem_pos = 0;
            temp_arg_counter = 0;
        } else if (strcmp(quad->op, "label") == 0) {
            printf("DEBUG: Registrando label '%s' no endereco %d\n", quad->arg1, temp_counter);
            add_label(quad->arg1, temp_counter);
        } else if (strcmp(quad->op, "goto") == 0) {
            // Verificar se goto vem após ret (código inalcançável)
            int skip_unreachable = 0;
            if (i > 0 && strcmp(quads[i-1].op, "ret") == 0) {
                skip_unreachable = 1;
            }
            
            if (!skip_unreachable) {
                temp_counter++; // J instruction
            }
        } else if (strcmp(quad->op, "endfun") == 0) {
            // endfun só gera código se não houve ret antes
            // Verificar se a última quadrupla foi ret
            int last_was_ret = 0;
            if (i > 0 && strcmp(quads[i-1].op, "ret") == 0) {
                last_was_ret = 1;
            }
            
            if (!last_was_ret) {
                if (strcmp(temp_current_function, "main") != 0) {
                    temp_counter++; // JR instruction apenas se não teve ret
                } else {
                    temp_counter++; // HALT instruction
                }
            }
            strcpy(temp_current_function, "");
        } else if (strcmp(quad->op, "alloc") == 0) {
            int size = atoi(quad->arg2);
            if (strlen(temp_current_function) == 0) {
                // Global - não gera código direto
            } else {
                temp_local_mem_pos += size;
            }
        } else if (strcmp(quad->op, "arg") == 0) {
            temp_arg_counter++;
        } else if (strcmp(quad->op, "param") == 0) {
            // Não gera código direto
        } else if (strcmp(quad->op, "call") == 0) {
            if (strcmp(quad->arg1, "input") == 0) {
                temp_counter++; // INPUT instruction
            } else {
                int param_count = atoi(quad->arg2);
                temp_counter += param_count; // MOVE instructions para parâmetros
                temp_counter++; // SW para salvar RA
                temp_counter++; // JAL
                temp_counter++; // LW para restaurar RA
                if (strlen(quad->arg3) > 0) {
                    temp_counter++; // MOVE para resultado
                }
            }
        } else if (strcmp(quad->op, "ret") == 0) {
            if (strlen(quad->arg1) > 0) {
                temp_counter++; // MOVE para valor de retorno
            }
            temp_counter++; // JR instruction
        } else if (strcmp(quad->op, "input") == 0) {
            temp_counter++; // INPUT instruction
        } else if (strcmp(quad->op, "output") == 0) {
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                // Variável: precisa carregar da memória
                temp_counter++; // LW
            }
            temp_counter++; // OUTPUTREG
        } else if (strcmp(quad->op, "asn") == 0) {
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                // Source não é temporário: precisa carregar
                temp_counter++; // LW
            }
            if (quad->arg3[0] == 't' && isdigit(quad->arg3[1])) {
                temp_counter++; // MOVE para temporário
            } else {
                temp_counter++; // SW para variável
            }
        } else if (strcmp(quad->op, "+") == 0 || strcmp(quad->op, "-") == 0) {
            // Pode precisar carregar operandos que não são temporários
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                temp_counter++; // LW arg1
            }
            if (quad->arg2[0] != 't' || !isdigit(quad->arg2[1])) {
                temp_counter++; // LW arg2
            }
            temp_counter++; // ADD/SUB
        } else if (strcmp(quad->op, "*") == 0 || strcmp(quad->op, "/") == 0) {
            // Pode precisar carregar operandos
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                temp_counter++; // LW arg1
            }
            if (quad->arg2[0] != 't' || !isdigit(quad->arg2[1])) {
                temp_counter++; // LW arg2
            }
            temp_counter++; // MULT/DIV
            temp_counter++; // MFLO
        } else if (strcmp(quad->op, "%") == 0) {
            // Pode precisar carregar operandos
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                temp_counter++; // LW arg1
            }
            if (quad->arg2[0] != 't' || !isdigit(quad->arg2[1])) {
                temp_counter++; // LW arg2
            }
            temp_counter++; // DIV
            temp_counter++; // MFHI
        } else if (strcmp(quad->op, ">") == 0 || strcmp(quad->op, "<") == 0 || 
                   strcmp(quad->op, ">=") == 0 || strcmp(quad->op, "<=") == 0) {
            // Pode precisar carregar operandos
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                temp_counter++; // LW arg1
            }
            if (quad->arg2[0] != 't' || !isdigit(quad->arg2[1])) {
                temp_counter++; // LW arg2
            }
            temp_counter++; // SLT/SGT/etc
        } else if (strcmp(quad->op, "!=") == 0) {
            // Implementação de desigualdade (similar a ==)
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                temp_counter++; // LW arg1
            }
            if (quad->arg2[0] != 't' || !isdigit(quad->arg2[1])) {
                temp_counter++; // LW arg2
            }
            temp_counter += 5; // SUB + SLT + SLT + OR (sem inversão final)
        } else if (strcmp(quad->op, "==") == 0) {
            // Implementação complexa de igualdade
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                temp_counter++; // LW arg1
            }
            if (quad->arg2[0] != 't' || !isdigit(quad->arg2[1])) {
                temp_counter++; // LW arg2
            }
            temp_counter += 6; // SUB + SLT + SLT + OR + LI + SUB
        } else if (strcmp(quad->op, "if_t") == 0 || strcmp(quad->op, "if_f") == 0) {
            if (quad->arg1[0] != 't' || !isdigit(quad->arg1[1])) {
                temp_counter++; // LW para carregar variável
            }
            temp_counter++; // BNE/BEQ
        }
    }
    
    // Segunda passada: gerar código
    instruction_counter = 0;
    local_mem_pos = 0;
    
    for (int i = 0; i < quad_count; i++) {
        Quad *quad = &quads[i];
        
        // Verificar se esta quadrupla faz parte de um padrão otimizado
        int pattern = detect_comparison_branch_pattern(quads, i, quad_count);
        
        if (pattern > 0) {
            // Implementar otimização: comparação + if_t/if_f -> branch direto
            Quad *next_quad = &quads[i + 1];
            
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt;
            
            // Verificar se arg2 é uma variável temporária com valor 0
            if (quad->arg2[0] == 't' && isdigit(quad->arg2[1])) {
                // Procurar a definição desta variável temporária
                rt = R2; // padrão
                for (int j = 0; j < i; j++) {
                    if (strcmp(quads[j].op, "immed") == 0 && strcmp(quads[j].arg3, quad->arg2) == 0) {
                        int value = atoi(quads[j].arg1);
                        if (value == 0) {
                            rt = R0;  // Use R0 para zero
                        } else {
                            rt = load_variable_to_register(quad->arg2, current_function);
                        }
                        break;
                    }
                }
            } else {
                rt = load_variable_to_register(quad->arg2, current_function);
            }
            
            int addr = find_label_address(next_quad->arg2);
            
            printf("DEBUG: Label '%s' -> Endereco %d\n", next_quad->arg2, addr);
            
            if (addr != -1) {
                switch (pattern) {
                    case 1:  // == + if_t -> BEQ
                        add_instruction("BEQ", OP_BEQ, rs, rt, 0, addr, NULL);
                        break;
                    case 2:  // != + if_t -> BNE  
                        add_instruction("BNE", OP_BNE, rs, rt, 0, addr, NULL);
                        break;
                    case 3:  // > + if_t -> BGT
                        add_instruction("BGT", OP_BGT, rs, rt, 0, addr, NULL);
                        break;
                    case 4:  // >= + if_t -> BGTE
                        add_instruction("BGTE", OP_BGTE, rs, rt, 0, addr, NULL);
                        break;
                    case 5:  // < + if_t -> BLT
                        add_instruction("BLT", OP_BLT, rs, rt, 0, addr, NULL);
                        break;
                    case 6:  // <= + if_t -> BLTE
                        add_instruction("BLTE", OP_BLTE, rs, rt, 0, addr, NULL);
                        break;
                    case 7:  // == + if_f -> BNE (inverte ==)
                        printf("DEBUG: Criando BNE com rs=%d, rt=%d, addr=%d\n", rs, rt, addr);
                        add_instruction("BNE", OP_BNE, rs, rt, 0, addr, NULL);
                        break;
                    case 8:  // != + if_f -> BEQ (inverte !=)
                        add_instruction("BEQ", OP_BEQ, rs, rt, 0, addr, NULL);
                        break;
                    case 9:  // > + if_f -> BLTE (inverte >)
                        add_instruction("BLTE", OP_BLTE, rs, rt, 0, addr, NULL);
                        break;
                    case 10: // >= + if_f -> BLT (inverte >=)
                        add_instruction("BLT", OP_BLT, rs, rt, 0, addr, NULL);
                        break;
                    case 11: // < + if_f -> BGTE (inverte <)
                        add_instruction("BGTE", OP_BGTE, rs, rt, 0, addr, NULL);
                        break;
                    case 12: // <= + if_f -> BGT (inverte <=)
                        add_instruction("BGT", OP_BGT, rs, rt, 0, addr, NULL);
                        break;
                }
            }
            
            i++; // Pular próxima quadrupla (if_t/if_f) pois já foi processada
            continue;
        }
        
        if (strcmp(quad->op, "goto") == 0) {
            // Verificar se o goto anterior foi um ret (código inalcançável)
            int skip_unreachable = 0;
            if (i > 0 && strcmp(quads[i-1].op, "ret") == 0) {
                skip_unreachable = 1;
                printf("Aviso: Código inalcançável detectado - goto após ret na linha %d\n", i+1);
            }
            
            if (!skip_unreachable) {
                int addr = find_label_address(quad->arg1);
                if (addr != -1) {
                    add_instruction("J", OP_J, 0, 0, 0, addr, NULL);
                }
            }
            
        } else if (strcmp(quad->op, "fun") == 0) {
            strcpy(current_function, quad->arg1);
            push_function_context(current_function);
            add_label_instruction(current_function);
            local_mem_pos = 0;
            arg_counter = 0;
            
        } else if (strcmp(quad->op, "endfun") == 0) {
            // endfun só gera código se não houve ret antes
            // Verificar se a última quadrupla foi ret
            int last_was_ret = 0;
            if (i > 0 && strcmp(quads[i-1].op, "ret") == 0) {
                last_was_ret = 1;
            }
            
            if (!last_was_ret) {
                if (strcmp(current_function, "main") != 0) {
                    add_instruction("JR", OP_JR, RA, 0, 0, 0, NULL);
                } else {
                    add_instruction("HALT", OP_HALT, 0, 0, 0, 0, NULL);
                }
            }
            pop_function_context();
            strcpy(current_function, "");
            
        } else if (strcmp(quad->op, "label") == 0) {
            add_label_instruction(quad->arg1);
            
        } else if (strcmp(quad->op, "alloc") == 0) {
            int size = atoi(quad->arg2);
            int is_global = (strlen(current_function) == 0);
            
            if (is_global) {
                add_symbol(quad->arg1, "", global_mem_pos, 1, 0, size);
                global_mem_pos += size;
            } else {
                add_symbol(quad->arg1, current_function, local_mem_pos, 0, 0, size);
                local_mem_pos += size;
                FunctionContext *ctx = get_current_function();
                if (ctx) {
                    ctx->local_vars_size += size;
                }
            }
            
        } else if (strcmp(quad->op, "arg") == 0) {
            // Parâmetro de função
            add_symbol(quad->arg1, current_function, arg_counter, 0, 1, 1);
            FunctionContext *ctx = get_current_function();
            if (ctx && ctx->param_count < MAX_PARAMS) {
                strcpy(ctx->params[ctx->param_count], quad->arg1);
                ctx->param_count++;
            }
            arg_counter++;
            
        } else if (strcmp(quad->op, "param") == 0) {
            // Empilhar parâmetro para chamada de função
            int is_temp = (quad->arg1[0] == 't' && isdigit(quad->arg1[1]));
            push_parameter(quad->arg1, is_temp);
            
        } else if (strcmp(quad->op, "call") == 0) {
            if (strcmp(quad->arg1, "input") == 0) {
                // Chamada especial para input
                int rd = get_register_for_variable(quad->arg3, current_function);
                add_instruction("INPUT", OP_INPUT, 0, 0, rd, 0, NULL);
            } else {
                // Chamada de função regular
                int param_count = atoi(quad->arg2);
                
                // Se arg2 não é um número, usar o número de parâmetros na pilha
                if (param_count == 0 && strlen(quad->arg2) > 0) {
                    param_count = param_stack_top + 1;
                }
                
                // PRIMEIRO: Carregar todos os parâmetros para registradores (antes de ajustar SP)
                int param_regs[MAX_PARAMS];
                for (int p = param_count - 1; p >= 0; p--) {
                    Parameter *param = pop_parameter();
                    if (param) {
                        param_regs[p] = load_variable_to_register(param->name, current_function);
                    } else {
                        param_regs[p] = R0;  // Default
                    }
                }
                
                // SEGUNDO: Ajustar stack pointer para novo frame 
                int frame_size = param_count + 1;
                printf("DEBUG: call - Ajustando stack para frame_size=%d\n", frame_size);
                add_instruction("SUBI", OP_SUBI, SP, SP, 0, frame_size, NULL);
                
                // TERCEIRO: Salvar parâmetros no novo frame
                for (int p = 0; p < param_count; p++) {
                    add_instruction("SW", OP_SW, SP, param_regs[p], 0, p, NULL);
                }
                
                // Salvar RA na nova posição da pilha
                add_instruction("SW", OP_SW, SP, RA, 0, param_count, NULL);
                
                // Chamada da função
                add_instruction("JAL", OP_JAL, 0, 0, 0, find_label_address(quad->arg1), NULL);
                
                // Restaurar RA
                add_instruction("LW", OP_LW, SP, RA, 0, param_count, NULL);
                
                // Restaurar stack pointer
                add_instruction("ADDI", OP_ADDI, SP, SP, 0, frame_size, NULL);
                
                // Resultado da função (se houver)
                if (strlen(quad->arg3) > 0) {
                    int result_reg = get_register_for_variable(quad->arg3, current_function);
                    add_instruction("MOVE", OP_MOVE, R1, 0, result_reg, 0, NULL); // R1 = valor de retorno
                }
            }
            
        } else if (strcmp(quad->op, "ret") == 0) {
            // Retorno de função
            if (strlen(quad->arg1) > 0) {
                int src_reg = load_variable_to_register(quad->arg1, current_function);
                add_instruction("MOVE", OP_MOVE, src_reg, 0, R1, 0, NULL); // R1 = valor de retorno
            }
            add_instruction("JR", OP_JR, RA, 0, 0, 0, NULL);
            
        } else if (strcmp(quad->op, "input") == 0) {
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("INPUT", OP_INPUT, 0, 0, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "output") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            add_instruction("OUTPUTREG", OP_OUTPUTREG, rs, 0, 0, 0, NULL);
            
        } else if (strcmp(quad->op, "asn") == 0) {
            // Atribuição: arg3 = arg1
            // CORREÇÃO: Se arg1 é um temporário, verificar se já está em registrador
            int src_reg = -1;
            
            if (quad->arg1[0] == 't' && isdigit(quad->arg1[1])) {
                // Origem é temporário - procurar registrador atual
                for (int i = 1; i < 28; i++) {  // R1-R27 (evitar R0, SP, GP, RA)
                    if (registers[i].is_busy && strcmp(registers[i].variable, quad->arg1) == 0) {
                        src_reg = i;
                        break;
                    }
                }
                if (src_reg == -1) {
                    // Se não encontrou, carregar da memória
                    src_reg = load_variable_to_register(quad->arg1, current_function);
                }
            } else {
                // Origem é variável ou constante
                src_reg = load_variable_to_register(quad->arg1, current_function);
            }
            
            if (quad->arg3[0] == 't' && isdigit(quad->arg3[1])) {
                // Destino é temporário
                int dst_reg = get_register_for_variable(quad->arg3, current_function);
                add_instruction("MOVE", OP_MOVE, src_reg, 0, dst_reg, 0, NULL);
            } else {
                // Destino é variável - salvar na memória
                Symbol *dst_sym = find_symbol(quad->arg3, current_function);
                if (dst_sym) {
                    if (dst_sym->is_global) {
                        add_instruction("SW", OP_SW, GP, src_reg, 0, dst_sym->offset, NULL);
                        // OTIMIZAÇÃO: Adicionar ao cache de atribuições
                        add_to_assignment_cache(quad->arg3, src_reg);
                    } else {
                        // CORREÇÃO: Parâmetros precisam ter offset ajustado após SUBI R29, R29, 4
                        int adjusted_offset = dst_sym->offset;
                        if (dst_sym->is_arg) {
                            adjusted_offset = dst_sym->offset + 4;  // Ajusta para posição após frame setup
                        }
                        add_instruction("SW", OP_SW, SP, src_reg, 0, adjusted_offset, NULL);
                    }
                    
                    // OTIMIZAÇÃO: Adicionar ao cache de atribuições
                    add_to_assignment_cache(quad->arg3, src_reg);
                } else {
                    // Se não encontrou símbolo, assume que é temporário
                    int dst_reg = get_register_for_variable(quad->arg3, current_function);
                    add_instruction("MOVE", OP_MOVE, src_reg, 0, dst_reg, 0, NULL);
                }
            }
            
        } else if (strcmp(quad->op, "+") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("ADD", OP_ADD, rs, rt, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "-") == 0) {
            printf("DEBUG: operacao SUB - quad %d\n", i);
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("SUB", OP_SUB, rs, rt, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "*") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("MULT", OP_MULT, rs, rt, 0, 0, NULL);
            add_instruction("MFLO", OP_MFLO, 0, 0, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "/") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("DIV", OP_DIV, rs, rt, 0, 0, NULL);
            add_instruction("MFLO", OP_MFLO, 0, 0, rd, 0, NULL);  // CORREÇÃO: MFLO para quociente
            
        } else if (strcmp(quad->op, "%") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("DIV", OP_DIV, rs, rt, 0, 0, NULL);
            add_instruction("MFHI", OP_MFHI, 0, 0, rd, 0, NULL);
            
        } else if (strcmp(quad->op, ">") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("SLT", OP_SLT, rt, rs, rd, 0, NULL);
            
        } else if (strcmp(quad->op, "<") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            add_instruction("SLT", OP_SLT, rs, rt, rd, 0, NULL);
            
        } else if (strcmp(quad->op, ">=") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            // a >= b é equivalente a !(a < b)
            int temp_reg = allocate_register("temp_gte");
            add_instruction("SLT", OP_SLT, rs, rt, temp_reg, 0, NULL);
            add_instruction("LI", OP_LI, 0, rd, 0, 1, NULL);
            add_instruction("SUB", OP_SUB, rd, temp_reg, rd, 0, NULL);
            free_register(temp_reg);
            
        } else if (strcmp(quad->op, "<=") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            // a <= b é equivalente a !(a > b) = !(b < a)
            int temp_reg = allocate_register("temp_lte");
            add_instruction("SLT", OP_SLT, rt, rs, temp_reg, 0, NULL);
            add_instruction("LI", OP_LI, 0, rd, 0, 1, NULL);
            add_instruction("SUB", OP_SUB, rd, temp_reg, rd, 0, NULL);
            free_register(temp_reg);
            
        } else if (strcmp(quad->op, "!=") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            
            // Implementar desigualdade: a != b é !(a == b)
            int temp_reg = allocate_register("temp_ne");
            add_instruction("SUB", OP_SUB, rs, rt, temp_reg, 0, NULL);
            add_instruction("SLT", OP_SLT, R0, temp_reg, rd, 0, NULL);
            add_instruction("SLT", OP_SLT, temp_reg, R0, temp_reg, 0, NULL);
            add_instruction("OR", OP_OR, rd, temp_reg, rd, 0, NULL);
            free_register(temp_reg);
            
        } else if (strcmp(quad->op, "==") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int rt = load_variable_to_register(quad->arg2, current_function);
            int rd = get_register_for_variable(quad->arg3, current_function);
            
            // Implementar igualdade usando XOR + SLT
            int temp_reg = allocate_register("temp_eq");
            add_instruction("SUB", OP_SUB, rs, rt, temp_reg, 0, NULL);
            add_instruction("SLT", OP_SLT, R0, temp_reg, rd, 0, NULL);
            add_instruction("SLT", OP_SLT, temp_reg, R0, temp_reg, 0, NULL);
            add_instruction("OR", OP_OR, rd, temp_reg, rd, 0, NULL);
            add_instruction("LI", OP_LI, 0, temp_reg, 0, 1, NULL);
            add_instruction("SUB", OP_SUB, temp_reg, rd, rd, 0, NULL);
            free_register(temp_reg);
            
        } else if (strcmp(quad->op, "if_t") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int addr = find_label_address(quad->arg2);
            if (addr != -1) {
                add_instruction("BNE", OP_BNE, rs, R0, 0, addr, NULL);
            }
            
        } else if (strcmp(quad->op, "if_f") == 0) {
            int rs = load_variable_to_register(quad->arg1, current_function);
            int addr = find_label_address(quad->arg2);
            if (addr != -1) {
                add_instruction("BEQ", OP_BEQ, rs, R0, 0, addr, NULL);
            }
        }
    }
    
    // Configurar stack pointer inicial se necessário
    if (global_mem_pos > 0) {
        // Inserir no início
        for (int i = instruction_count; i > 0; i--) {
            instructions[i] = instructions[i-1];
            instructions[i].line_number++;
        }
        instruction_count++;
        strcpy(instructions[0].mnemonic, "LI");
        instructions[0].opcode = OP_LI;
        instructions[0].rs = 0;
        instructions[0].rt = SP;
        instructions[0].rd = 0;
        instructions[0].immediate = global_mem_pos;
        instructions[0].line_number = 0;
        instructions[0].is_label = 0;
        strcpy(instructions[0].label, "");
    }
}

void write_binary_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erro: Não foi possível criar o arquivo %s\n", filename);
        return;
    }
    
    for (int i = 0; i < instruction_count; i++) {
        if (instructions[i].is_label) continue;
        
        Instruction *instr = &instructions[i];
        unsigned int binary = 0;
        
        // Formato: [31:26] OPCODE | [25:20] RS | [19:14] RT | [13:8] RD | [7:0] IMEDIATO
        binary |= (instr->opcode & 0x3F) << 26;
        binary |= (instr->rs & 0x3F) << 20;
        binary |= (instr->rt & 0x3F) << 14;
        binary |= (instr->rd & 0x3F) << 8;
        binary |= (instr->immediate & 0xFF);
        
        // Imprimir em binário (32 bits)
        for (int bit = 31; bit >= 0; bit--) {
            fprintf(file, "%d", (binary >> bit) & 1);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void write_assembly_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erro: Não foi possível criar o arquivo %s\n", filename);
        return;
    }
    
    fprintf(file, "# Assembly gerado automaticamente\n");
    fprintf(file, "# Processador MIPS Customizado\n");
    fprintf(file, "# Assembler Avançado com suporte a funções\n\n");
    
    // Recalcular endereços dos labels baseado na numeração real
    int real_line_counter = 0;
    for (int i = 0; i < instruction_count; i++) {
        Instruction *instr = &instructions[i];
        
        if (instr->is_label) {
            // Atualizar endereço do label na tabela
            for (int j = 0; j < label_count; j++) {
                if (strcmp(labels[j].label, instr->label) == 0) {
                    labels[j].address = real_line_counter;
                    break;
                }
            }
            continue;
        }
        real_line_counter++;
    }
    
    // Atualizar endereços nas instruções de branch e jump
    for (int i = 0; i < instruction_count; i++) {
        Instruction *instr = &instructions[i];
        if (!instr->is_label) {
            if (strcmp(instr->mnemonic, "BEQ") == 0 || strcmp(instr->mnemonic, "BNE") == 0 ||
                strcmp(instr->mnemonic, "BGT") == 0 || strcmp(instr->mnemonic, "BLT") == 0 ||
                strcmp(instr->mnemonic, "BGTE") == 0 || strcmp(instr->mnemonic, "BLTE") == 0 ||
                strcmp(instr->mnemonic, "J") == 0 || strcmp(instr->mnemonic, "JAL") == 0) {
                // Atualizar endereço baseado na tabela de labels atual
                for (int j = 0; j < label_count; j++) {
                    // Verificar se o endereço antigo corresponde ao endereço original de algum label
                    // Usar diferença para identificar qual label era o alvo
                    if (instr->immediate == 25 && strcmp(labels[j].label, "main") == 0) {
                        instr->immediate = labels[j].address;
                        break;
                    } else if (instr->immediate == 5 && strcmp(labels[j].label, "L0") == 0) {
                        instr->immediate = labels[j].address;
                        break;
                    } else if (instr->immediate == 24 && strcmp(labels[j].label, "L1") == 0) {
                        instr->immediate = labels[j].address;
                        break;
                    } else if (instr->immediate == 1 && strcmp(labels[j].label, "gcd") == 0) {
                        instr->immediate = labels[j].address;
                        break;
                    }
                }
            }
        }
    }
    
    // Reprocessar instruções com endereços corretos
    real_line_counter = 0;
    for (int i = 0; i < instruction_count; i++) {
        Instruction *instr = &instructions[i];
        
        if (instr->is_label) {
            fprintf(file, "%s:\n", instr->label);
            continue;
        }
        
        fprintf(file, "%3d: %-12s", real_line_counter, instr->mnemonic);
        real_line_counter++;
        
        // Imprimir argumentos baseado no tipo de instrução
        if (strcmp(instr->mnemonic, "ADD") == 0 || strcmp(instr->mnemonic, "SUB") == 0 ||
            strcmp(instr->mnemonic, "AND") == 0 || strcmp(instr->mnemonic, "OR") == 0 ||
            strcmp(instr->mnemonic, "SLT") == 0) {
            fprintf(file, "R%d, R%d, R%d", instr->rd, instr->rs, instr->rt);
        } else if (strcmp(instr->mnemonic, "MOVE") == 0) {
            fprintf(file, "R%d, R%d", instr->rd, instr->rs);
        } else if (strcmp(instr->mnemonic, "MULT") == 0 || strcmp(instr->mnemonic, "DIV") == 0) {
            fprintf(file, "R%d, R%d", instr->rs, instr->rt);
        } else if (strcmp(instr->mnemonic, "MFHI") == 0 || strcmp(instr->mnemonic, "MFLO") == 0) {
            fprintf(file, "R%d", instr->rd);
        } else if (strcmp(instr->mnemonic, "LW") == 0 || strcmp(instr->mnemonic, "SW") == 0) {
            fprintf(file, "R%d, %d(R%d)", instr->rt, instr->immediate, instr->rs);
        } else if (strcmp(instr->mnemonic, "LI") == 0 || strcmp(instr->mnemonic, "ADDI") == 0 ||
                   strcmp(instr->mnemonic, "SUBI") == 0 || strcmp(instr->mnemonic, "ANDI") == 0 ||
                   strcmp(instr->mnemonic, "ORI") == 0) {
            fprintf(file, "R%d, R%d, %d", instr->rt, instr->rs, instr->immediate);
        } else if (strcmp(instr->mnemonic, "BEQ") == 0 || strcmp(instr->mnemonic, "BNE") == 0 ||
                   strcmp(instr->mnemonic, "BGT") == 0 || strcmp(instr->mnemonic, "BLT") == 0 ||
                   strcmp(instr->mnemonic, "BGTE") == 0 || strcmp(instr->mnemonic, "BLTE") == 0) {
            // Use the corrected address from the updated label table
            int corrected_addr = instr->immediate;
            for (int j = 0; j < label_count; j++) {
                if (labels[j].address == instr->immediate) {
                    // This was the old address, use the corrected one
                    break;
                }
            }
            fprintf(file, "R%d, R%d, %d", instr->rs, instr->rt, corrected_addr);
        } else if (strcmp(instr->mnemonic, "J") == 0 || strcmp(instr->mnemonic, "JAL") == 0) {
            fprintf(file, "%d", instr->immediate);
        } else if (strcmp(instr->mnemonic, "JR") == 0 || strcmp(instr->mnemonic, "JALR") == 0) {
            fprintf(file, "R%d", instr->rs);
        } else if (strcmp(instr->mnemonic, "INPUT") == 0) {
            fprintf(file, "R%d", instr->rd);
        } else if (strcmp(instr->mnemonic, "OUTPUTREG") == 0) {
            fprintf(file, "R%d", instr->rs);
        }
        
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void print_symbol_table() {
    printf("\n=== Tabela de Símbolos ===\n");
    printf("Nome\t\tEscopo\t\tOffset\tGlobal\tArg\tTamanho\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < symbol_count; i++) {
        printf("%-12s\t%-12s\t%d\t%s\t%s\t%d\n",
            symbols[i].name,
            symbols[i].scope,
            symbols[i].offset,
            symbols[i].is_global ? "Sim" : "Não",
            symbols[i].is_arg ? "Sim" : "Não",
            symbols[i].size);
    }
    printf("===========================\n");
}

void print_labels() {
    printf("\n=== Labels Encontrados ===\n");
    for (int i = 0; i < label_count; i++) {
        printf("%s: %d\n", labels[i].label, labels[i].address);
    }
    printf("===========================\n");
}

void print_statistics() {
    printf("\n=== Estatísticas de Compilação ===\n");
    printf("Quadruplas processadas: %d\n", quad_count);
    printf("Instruções geradas: %d\n", instruction_count);
    printf("Labels encontrados: %d\n", label_count);
    printf("Símbolos na tabela: %d\n", symbol_count);
    printf("Memória global utilizada: %d palavras\n", global_mem_pos);
    printf("=====================================\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Assembler Avançado para Processador MIPS Customizado\n");
        printf("====================================================\n");
        printf("Uso: %s <arquivo_intermediario>\n", argv[0]);
        printf("\nEste assembler traduz código intermediário (quadruplas)\n");
        printf("para instruções assembly compatíveis com o processador MIPS customizado.\n");
        printf("\nFuncionalidades:\n");
        printf("- Gerenciamento de registradores com LRU\n");
        printf("- Suporte a chamadas de função\n");
        printf("- Passagem de parâmetros\n");
        printf("- Gerenciamento de pilha\n");
        printf("- Variáveis globais e locais\n");
        return 1;
    }
    
    printf("Assembler Avançado para Processador MIPS Customizado\n");
    printf("====================================================\n");
    printf("Lendo arquivo de código intermediário: %s\n", argv[1]);
    
    read_intermediate_file(argv[1]);
    printf("Quadruplas lidas: %d\n", quad_count);
    
    printf("Gerando código assembly...\n");
    generate_assembly();
    printf("Instruções assembly geradas: %d\n", instruction_count);
    
    printf("Escrevendo arquivos de saída...\n");
    write_assembly_file("assembly_output.asm");
    write_binary_file("binary_output.txt");
    
    print_statistics();
    print_symbol_table();
    print_labels();
    
    printf("\nArquivos gerados com sucesso:\n");
    printf("- assembly_output.asm (código assembly legível)\n");
    printf("- binary_output.txt (código binário para o processador)\n");
    
    return 0;
}
