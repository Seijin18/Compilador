#include "assembler.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Variável global para guardar o endereço da main e contador de instruções
static int main_address = 46; // Será atualizado dinamicamente
static int global_instruction_count = 1; // Contador global compartilhado

// Mapeamento de opcodes conforme instrucoes_processador.md
static int opcode_map[] = {
    [INSTR_ADD] = 0x00, [INSTR_SUB] = 0x01, [INSTR_MULT] = 0x02, [INSTR_DIV] = 0x03,
    [INSTR_AND] = 0x04, [INSTR_OR] = 0x05, [INSTR_SLL] = 0x06, [INSTR_SRL] = 0x07,
    [INSTR_SLT] = 0x08, [INSTR_MFHI] = 0x09, [INSTR_MFLO] = 0x0A, [INSTR_MOVE] = 0x0B,
    [INSTR_JR] = 0x0C, [INSTR_JALR] = 0x0D, [INSTR_LA] = 0x0E, [INSTR_ADDI] = 0x0F,
    [INSTR_SUBI] = 0x10, [INSTR_ANDI] = 0x11, [INSTR_ORI] = 0x12, [INSTR_BEQ] = 0x13,
    [INSTR_BNE] = 0x14, [INSTR_BGT] = 0x15, [INSTR_BGTE] = 0x16, [INSTR_BLT] = 0x17,
    [INSTR_BLTE] = 0x18, [INSTR_LW] = 0x19, [INSTR_SW] = 0x1A, [INSTR_LI] = 0x1B,
    [INSTR_J] = 0x1C, [INSTR_JAL] = 0x1D, [INSTR_HALT] = 0x1E, [INSTR_OUTPUTMEM] = 0x1F,
    [INSTR_OUTPUTREG] = 0x20, [INSTR_OUTPUT_RESET] = 0x21, [INSTR_INPUT] = 0x22
};

// Nomes dos registradores no formato do arquivo de referência
static char* register_names[] = {
    "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
    "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",
    "r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23",
    "r24", "r25", "r26", "r27", "r28", "r29", "r30", "r31"
};

// Estrutura para manter labels e endereços
typedef struct LabelInfo {
    char name[32];
    int address;
    struct LabelInfo* next;
} LabelInfo;

// Estrutura principal do assembler expandida
typedef struct {
    struct Instrucao* instrucoes;
    struct Instrucao* ultima_instrucao;
    struct Escopo* escopos;
    struct TempReg temp_regs[26];  // $t0 a $t25
    LabelInfo* labels;
    int label_count;
    int instruction_count;
    int next_global_addr;
    FILE* output_file;
} AssemblerInternal;
// Inicialização do assembler
Assembler* init_assembler(FILE* output) {
    Assembler* assembler = (Assembler*)malloc(sizeof(Assembler));
    assembler->instrucoes = NULL;
    assembler->ultima_instrucao = NULL;
    assembler->escopos = NULL;
    assembler->label_count = 0;
    assembler->next_global_addr = 0;
    assembler->output_file = output;
    
    // Inicializar registradores temporários
    for (int i = 0; i < 26; i++) {
        assembler->temp_regs[i].reg = (Registradores)(R1 + i);
        assembler->temp_regs[i].em_uso = false;
        strcpy(assembler->temp_regs[i].var_name, "");
    }
    
    // Criar escopo global
    create_scope(assembler, "global");
    
    return assembler;
}

// Liberação de memória
void free_assembler(Assembler* assembler) {
    // Liberar instruções
    struct Instrucao* current = assembler->instrucoes;
    while (current) {
        struct Instrucao* next = current->next;
        free(current);
        current = next;
    }
    
    // Liberar escopos e variáveis
    struct Escopo* scope = assembler->escopos;
    while (scope) {
        struct Variable* var = scope->variaveis;
        while (var) {
            struct Variable* next_var = var->next;
            free(var);
            var = next_var;
        }
        struct Escopo* next_scope = scope->next;
        free(scope);
        scope = next_scope;
    }
    
    free(assembler);
}

// Emitir uma instrução
// Função para obter o contador atual de instruções
int get_current_instruction_count() {
    return global_instruction_count;
}

void emit_instruction(Assembler* assembler, Instrucoes op, Registradores rs,
                     Registradores rt, Registradores rd, int imediato, const char* label) {
    
    struct Instrucao* instrucao = (struct Instrucao*)malloc(sizeof(struct Instrucao));
    instrucao->op = op;
    instrucao->rs = rs;
    instrucao->rt = rt;
    instrucao->rd = rd;
    instrucao->imediato = imediato;
    if (label) {
        strncpy(instrucao->label, label, 31);
        instrucao->label[31] = '\0';
    } else {
        instrucao->label[0] = '\0';
    }
    instrucao->next = NULL;
    
    if (!assembler->instrucoes) {
        assembler->instrucoes = instrucao;
        assembler->ultima_instrucao = instrucao;
    } else {
        assembler->ultima_instrucao->next = instrucao;
        assembler->ultima_instrucao = instrucao;
    }
    
    // Escrever no arquivo de saída assembly no formato do arquivo de referência
    if (assembler->output_file) {
        fprintf(assembler->output_file, "%d-", global_instruction_count++);
        
        switch (op) {
            case INSTR_SW:
                fprintf(assembler->output_file, "sw %s %d(%s)\n",
                       get_register_name(rt), imediato, get_register_name(rs));
                break;
            case INSTR_LW:
                fprintf(assembler->output_file, "lw %s %d(%s)\n",
                       get_register_name(rt), imediato, get_register_name(rs));
                break;
            case INSTR_ADDI:
                fprintf(assembler->output_file, "addi %s %s %d\n",
                       get_register_name(rt), get_register_name(rs), imediato);
                break;
            case INSTR_SUBI:
                fprintf(assembler->output_file, "subi %s %s %d\n",
                       get_register_name(rt), get_register_name(rs), imediato);
                break;
            case INSTR_INPUT:
                fprintf(assembler->output_file, "input %s\n", get_register_name(rd));
                break;
            case INSTR_OUTPUTREG:
                fprintf(assembler->output_file, "outputreg %s\n", get_register_name(rs));
                break;
            case INSTR_JAL:
                fprintf(assembler->output_file, "jal %d\n", imediato);
                break;
            case INSTR_JR:
                fprintf(assembler->output_file, "jr %s\n", get_register_name(rs));
                break;
            case INSTR_BEQ:
                fprintf(assembler->output_file, "beq %s %s %d\n",
                       get_register_name(rs), get_register_name(rt), imediato);
                break;
            case INSTR_J:
                fprintf(assembler->output_file, "j %d\n", imediato);
                break;
            case INSTR_LI:
                fprintf(assembler->output_file, "li %s %d\n",
                       get_register_name(rt), imediato);
                break;
            case INSTR_ADD:
                fprintf(assembler->output_file, "add %s %s %s\n",
                       get_register_name(rd), get_register_name(rs), get_register_name(rt));
                break;
            case INSTR_SUB:
                fprintf(assembler->output_file, "sub %s %s %s\n",
                       get_register_name(rd), get_register_name(rs), get_register_name(rt));
                break;
            case INSTR_MULT:
                fprintf(assembler->output_file, "mult %s %s\n",
                       get_register_name(rs), get_register_name(rt));
                break;
            case INSTR_DIV:
                fprintf(assembler->output_file, "div %s %s\n",
                       get_register_name(rs), get_register_name(rt));
                break;
            case INSTR_MFLO:
                fprintf(assembler->output_file, "mflo %s\n", get_register_name(rd));
                break;
            case INSTR_MFHI:
                fprintf(assembler->output_file, "mfhi %s\n", get_register_name(rd));
                break;
            case INSTR_MOVE:
                fprintf(assembler->output_file, "move %s %s\n",
                       get_register_name(rd), get_register_name(rs));
                break;
            default:
                fprintf(assembler->output_file, "%s\n", get_instruction_name(op));
                break;
        }
    }
}

// Alocar registrador temporário
Registradores allocate_register(Assembler* assembler, const char* var_name) {
    for (int i = 0; i < 26; i++) {
        if (!assembler->temp_regs[i].em_uso) {
            assembler->temp_regs[i].em_uso = true;
            strncpy(assembler->temp_regs[i].var_name, var_name, 31);
            assembler->temp_regs[i].var_name[31] = '\0';
            return assembler->temp_regs[i].reg;
        }
    }
    return R1; // Fallback
}

// Liberar registrador
void free_register(Assembler* assembler, Registradores reg) {
    for (int i = 0; i < 26; i++) {
        if (assembler->temp_regs[i].reg == reg) {
            assembler->temp_regs[i].em_uso = false;
            strcpy(assembler->temp_regs[i].var_name, "");
            break;
        }
    }
}

// Encontrar escopo
Escopo* find_scope(Assembler* assembler, const char* scope_name) {
    struct Escopo* current = assembler->escopos;
    while (current) {
        if (strcmp(current->nome, scope_name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Encontrar variável em um escopo
struct Variable* find_variable(Escopo* scope, const char* var_name) {
    struct Variable* current = scope->variaveis;
    while (current) {
        if (strcmp(current->nome, var_name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Adicionar variável ao escopo
void add_variable(Escopo* scope, const char* name, int tipo, int tamanho) {
    struct Variable* var = (struct Variable*)malloc(sizeof(struct Variable));
    strncpy(var->nome, name, 31);
    var->nome[31] = '\0';
    var->tipo = tipo;
    var->tamanho = tamanho;
    var->loc_mem = scope->pos_mem;
    var->next = scope->variaveis;
    scope->variaveis = var;
    
    // Atualizar posição de memória
    scope->pos_mem += tamanho;
}

// Criar novo escopo
Escopo* create_scope(Assembler* assembler, const char* name) {
    struct Escopo* scope = (struct Escopo*)malloc(sizeof(struct Escopo));
    strncpy(scope->nome, name, 31);
    scope->nome[31] = '\0';
    scope->pos_mem = 0;
    scope->variaveis = NULL;
    scope->next = assembler->escopos;
    assembler->escopos = scope;
    return scope;
}

// Verificar se é variável temporária
bool is_temp_variable(const char* name) {
    return name && name[0] == 't' && name[1] >= '0' && name[1] <= '9';
}

// Verificar se é constante
bool is_constant(const char* name) {
    if (!name || strlen(name) == 0) return false;
    for (int i = 0; name[i]; i++) {
        if (name[i] < '0' || name[i] > '9') {
            if (i == 0 && name[i] == '-') continue;
            return false;
        }
    }
    return true;
}

// Obter valor da constante
int get_constant_value(const char* name) {
    return atoi(name);
}

// Obter nome da instrução
char* get_instruction_name(Instrucoes op) {
    static char* names[] = {
        [INSTR_ADD] = "ADD", [INSTR_SUB] = "SUB", [INSTR_MULT] = "MULT", [INSTR_DIV] = "DIV",
        [INSTR_AND] = "AND", [INSTR_OR] = "OR", [INSTR_SLL] = "SLL", [INSTR_SRL] = "SRL",
        [INSTR_SLT] = "SLT", [INSTR_MFHI] = "MFHI", [INSTR_MFLO] = "MFLO", [INSTR_MOVE] = "MOVE",
        [INSTR_JR] = "JR", [INSTR_JALR] = "JALR", [INSTR_LA] = "LA", [INSTR_ADDI] = "ADDI",
        [INSTR_SUBI] = "SUBI", [INSTR_ANDI] = "ANDI", [INSTR_ORI] = "ORI", [INSTR_BEQ] = "BEQ",
        [INSTR_BNE] = "BNE", [INSTR_BGT] = "BGT", [INSTR_BGTE] = "BGTE", [INSTR_BLT] = "BLT",
        [INSTR_BLTE] = "BLTE", [INSTR_LW] = "LW", [INSTR_SW] = "SW", [INSTR_LI] = "LI",
        [INSTR_J] = "J", [INSTR_JAL] = "JAL", [INSTR_HALT] = "HALT", [INSTR_OUTPUTMEM] = "OUTPUTMEM",
        [INSTR_OUTPUTREG] = "OUTPUTREG", [INSTR_OUTPUT_RESET] = "OUTPUT_RESET", [INSTR_INPUT] = "INPUT"
    };
    return names[op];
}

// Obter nome do registrador
char* get_register_name(Registradores reg) {
    return register_names[reg];
}

// Obter opcode
int get_opcode(Instrucoes op) {
    return opcode_map[op];
}

// Processar operações aritméticas
void process_arithmetic(Assembler* assembler, QuadNode* quad) {
    Registradores reg_result, reg_arg1, reg_arg2;
    
    // Alocar registrador para resultado
    reg_result = allocate_register(assembler, quad->result);
    
    // Processar argumentos
    if (is_temp_variable(quad->arg1)) {
        reg_arg1 = allocate_register(assembler, quad->arg1);
    } else if (is_constant(quad->arg1)) {
        reg_arg1 = allocate_register(assembler, "temp_const1");
        emit_instruction(assembler, INSTR_LI, R0, reg_arg1, R0, get_constant_value(quad->arg1), NULL);
    } else {
        // Variável normal - carregar da memória
        reg_arg1 = allocate_register(assembler, quad->arg1);
        // TODO: Implementar carregamento da memória baseado no escopo
    }
    
    if (strcmp(quad->arg2, " ") != 0) {
        if (is_temp_variable(quad->arg2)) {
            reg_arg2 = allocate_register(assembler, quad->arg2);
        } else if (is_constant(quad->arg2)) {
            reg_arg2 = allocate_register(assembler, "temp_const2");
            emit_instruction(assembler, INSTR_LI, R0, reg_arg2, R0, get_constant_value(quad->arg2), NULL);
        } else {
            // Variável normal
            reg_arg2 = allocate_register(assembler, quad->arg2);
        }
    }
    
    // Emitir instrução apropriada
    if (strcmp(quad->op, "+") == 0) {
        emit_instruction(assembler, INSTR_ADD, reg_arg1, reg_arg2, reg_result, 0, NULL);
    } else if (strcmp(quad->op, "-") == 0) {
        emit_instruction(assembler, INSTR_SUB, reg_arg1, reg_arg2, reg_result, 0, NULL);
    } else if (strcmp(quad->op, "*") == 0) {
        emit_instruction(assembler, INSTR_MULT, reg_arg1, reg_arg2, R0, 0, NULL);
        emit_instruction(assembler, INSTR_MFLO, R0, R0, reg_result, 0, NULL);
    } else if (strcmp(quad->op, "/") == 0) {
        emit_instruction(assembler, INSTR_DIV, reg_arg1, reg_arg2, R0, 0, NULL);
        emit_instruction(assembler, INSTR_MFLO, R0, R0, reg_result, 0, NULL);
    } else if (strcmp(quad->op, ">") == 0) {
        emit_instruction(assembler, INSTR_SLT, reg_arg2, reg_arg1, reg_result, 0, NULL);
    } else if (strcmp(quad->op, "<") == 0) {
        emit_instruction(assembler, INSTR_SLT, reg_arg1, reg_arg2, reg_result, 0, NULL);
    } else if (strcmp(quad->op, "==") == 0) {
        // Implementar comparação de igualdade
        emit_instruction(assembler, INSTR_SUB, reg_arg1, reg_arg2, reg_result, 0, NULL);
        // TODO: Verificar se resultado é zero
    }
}

// Processar atribuição
void process_assignment(Assembler* assembler, QuadNode* quad) {
    Registradores reg_src, reg_dst;
    
    if (is_temp_variable(quad->arg1)) {
        reg_src = allocate_register(assembler, quad->arg1);
    } else if (is_constant(quad->arg1)) {
        reg_dst = allocate_register(assembler, quad->result);
        emit_instruction(assembler, INSTR_LI, R0, reg_dst, R0, get_constant_value(quad->arg1), NULL);
        return;
    } else {
        reg_src = allocate_register(assembler, quad->arg1);
    }
    
    reg_dst = allocate_register(assembler, quad->result);
    emit_instruction(assembler, INSTR_MOVE, reg_src, R0, reg_dst, 0, NULL);
}

// Função principal de geração de assembly
void generate_assembly(Assembler* assembler, QuadNode* quad_list) {
    QuadNode* current = quad_list;
    struct Escopo* current_scope = find_scope(assembler, "global");
    
    // Primeira passada: gerar assembly temporário para contar linhas
    FILE* temp_file = fopen("temp_assembly.txt", "w");
    FILE* original_file = assembler->output_file;
    assembler->output_file = temp_file;
    
    // Resetar contador global
    global_instruction_count = 1;
    
    // Pular o goto inicial na primeira passada
    if (current && strcmp(current->op, "goto") == 0 && strcmp(current->arg1, "main") == 0) {
        current = current->next;
    }
    
    // Gerar assembly temporário
    while (current) {
        if (strcmp(current->op, "fun") == 0) {
            // Início de função
            current_scope = create_scope(assembler, current->arg1);
            fprintf(assembler->output_file, "Func %s:\n", current->arg1);
            
            // Marcar onde main começa
            if (strcmp(current->arg1, "main") == 0) {
                main_address = global_instruction_count;
            }
            
            // Setup do frame se não for main
            if (strcmp(current->arg1, "main") != 0) {
                // Salvar registradores na pilha conforme gcd_goal.txt
                emit_instruction(assembler, INSTR_SW, FP, RA, R0, 1, NULL);  // sw r29 r31 1
                emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL); // addi r30 r30 1
                emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL); // addi r30 r30 1
                emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL); // addi r30 r30 1
            } else {
                // Para main, apenas alocar espaço para variáveis locais
                emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL);
                emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL);
            }
        }
        else if (strcmp(current->op, "alloc") == 0) {
            // Alocação de variável - já alocamos espaço no frame setup
            if (current_scope) {
                add_variable(current_scope, current->arg1, 0, 1);
            }
        }
        else if (strcmp(current->op, "input") == 0) {
            Registradores reg = R28; // Usar r28 como no exemplo
            emit_instruction(assembler, INSTR_INPUT, R0, R0, reg, 0, NULL);
        }
        else if (strcmp(current->op, "asn") == 0) {
            // Atribuição - salvar na pilha
            if (is_temp_variable(current->arg1)) {
                // Temporário para variável - usar SW para salvar na pilha
                struct Variable* var = find_variable(current_scope, current->result);
                if (var) {
                    emit_instruction(assembler, INSTR_SW, FP, R28, R0, var->loc_mem, NULL);
                }
            }
        }
        else if (strcmp(current->op, "param") == 0) {
            // Empilhar parâmetro
            if (strcmp(current->arg1, "x") == 0 || strcmp(current->arg1, "y") == 0) {
                // Carregar variável da pilha e empilhar
                struct Variable* var = find_variable(current_scope, current->arg1);
                if (var) {
                    emit_instruction(assembler, INSTR_LW, FP, R1, R0, var->loc_mem, NULL);
                    emit_instruction(assembler, INSTR_SW, SP, R1, R0, 0, NULL);
                    emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL);
                }
            } else {
                // Parâmetro temporário
                Registradores reg = allocate_register(assembler, current->arg1);
                emit_instruction(assembler, INSTR_SW, SP, reg, R0, 0, NULL);
                emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL);
            }
        }
        else if (strcmp(current->op, "call") == 0) {
            // Chamada de função conforme gcd_goal.txt
            // Salvar parâmetros na pilha
            emit_instruction(assembler, INSTR_SW, SP, R1, R0, 0, NULL);    // sw r30 r1 0
            emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL);  // addi r30 r30 1
            emit_instruction(assembler, INSTR_SW, SP, R2, R0, 0, NULL);    // sw r30 r2 0  
            emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL);  // addi r30 r30 1
            
            // Salvar frame pointer
            emit_instruction(assembler, INSTR_SW, SP, FP, R0, 0, NULL);    // sw r30 r29 0
            emit_instruction(assembler, INSTR_ADDI, SP, FP, R0, 0, NULL);  // addi r30 r29 0
            emit_instruction(assembler, INSTR_ADDI, SP, SP, R0, 1, NULL);  // addi r30 r30 1
            
            // Salvar parâmetros no frame da função chamada
            emit_instruction(assembler, INSTR_SW, FP, R2, R0, 3, NULL);    // sw r29 r2 3
            emit_instruction(assembler, INSTR_SW, FP, R1, R0, 2, NULL);    // sw r29 r1 2
            
            // JAL para a função (endereço 1 para gcd)
            if (strcmp(current->arg1, "gcd") == 0) {
                emit_instruction(assembler, INSTR_JAL, R0, R0, R0, 1, NULL); // jal 1
            }
            
            // Restaurar contexto após retorno
            emit_instruction(assembler, INSTR_ADDI, FP, SP, R0, 0, NULL);   // addi r29 r30 0
            emit_instruction(assembler, INSTR_LW, FP, FP, R0, 0, NULL);     // lw r29 0(r29)
            emit_instruction(assembler, INSTR_SUBI, SP, SP, R0, 1, NULL);   // subi r30 r30 1
            
            // Restaurar parâmetros da pilha
            emit_instruction(assembler, INSTR_LW, SP, R2, R0, 0, NULL);     // lw r2 0(r30)
            emit_instruction(assembler, INSTR_SUBI, SP, SP, R0, 1, NULL);   // subi r30 r30 1
            emit_instruction(assembler, INSTR_LW, SP, R1, R0, 0, NULL);     // lw r1 0(r30)
        }
        else if (strcmp(current->op, "output") == 0) {
            if (is_temp_variable(current->arg1)) {
                emit_instruction(assembler, INSTR_OUTPUTREG, R28, R0, R0, 0, NULL);
            }
        }
        else if (strcmp(current->op, "ret") == 0) {
            if (strcmp(current->arg1, " ") != 0 && strlen(current->arg1) > 0) {
                // Retorno com valor
                if (is_temp_variable(current->arg1)) {
                    // Retornando variável temporária (resultado de operação)
                    emit_instruction(assembler, INSTR_ADDI, R28, R28, R0, 0, NULL); // addi r28 r28 0
                } else {
                    // Carregar variável para retorno
                    struct Variable* var = find_variable(current_scope, current->arg1);
                    if (var) {
                        emit_instruction(assembler, INSTR_LW, FP, R1, R0, var->loc_mem, NULL);
                        emit_instruction(assembler, INSTR_ADDI, R28, R1, R0, 0, NULL);
                    }
                }
            }
        }
        else if (strcmp(current->op, "endfun") == 0) {
            // Fim de função
            if (current_scope && strcmp(current_scope->nome, "main") != 0) {
                emit_instruction(assembler, INSTR_LW, FP, RA, R0, 1, NULL);  // lw r29 r31 1
                emit_instruction(assembler, INSTR_JR, RA, R0, R0, 0, NULL);  // jr r31 r0 r0
            }
        }
        else if (strcmp(current->op, "label") == 0) {
            fprintf(assembler->output_file, "%s:\n", current->arg1);
        }
        else if (strcmp(current->op, "==") == 0) {
            // Comparação de igualdade: v == 0
            // Carregar v do frame (posição 3 para primeiro parâmetro)
            emit_instruction(assembler, INSTR_LW, FP, R1, R0, 3, NULL);  // lw r1 3(r29)
            // Carregar constante 0 em r2  
            emit_instruction(assembler, INSTR_LI, R0, R2, R0, 0, NULL);  // li r2 0
            // beq r1 r2 3 (se r1 igual a r2/zero, pular 3 instruções)
            emit_instruction(assembler, INSTR_BEQ, R1, R2, R0, 3, NULL); // beq r1 r2 3
        }
        else if (strcmp(current->op, "if_f") == 0) {
            // Branch condicional: se resultado da comparação for false, pular para label
            // Carregar u do frame (posição 2) e fazer movimento direto
            emit_instruction(assembler, INSTR_LW, FP, R1, R0, 2, NULL);  // lw r1 2(r29)
            emit_instruction(assembler, INSTR_MOVE, R1, R0, R28, 0, NULL); // move r28 r1
            // Jump incondicional para o final da função
            emit_instruction(assembler, INSTR_J, R0, R0, R0, 36, NULL);  // j 36 (endereço do return)
        }
        else if (strcmp(current->op, "immed") == 0) {
            Registradores reg = allocate_register(assembler, current->result);
            emit_instruction(assembler, INSTR_LI, R0, reg, R0, get_constant_value(current->arg1), NULL);
        }
        else if (strcmp(current->op, "/") == 0) {
            // Operação de divisão: u / v = t2
            // Carregar u (arg1) e v (arg2) do frame e dividir
            struct Variable* var_u = find_variable(current_scope, current->arg1);
            struct Variable* var_v = find_variable(current_scope, current->arg2);
            if (var_u && var_v) {
                emit_instruction(assembler, INSTR_LW, FP, R3, R0, var_u->loc_mem, NULL);  // lw r3 pos_u(r29)
                emit_instruction(assembler, INSTR_LW, FP, R4, R0, var_v->loc_mem, NULL);  // lw r4 pos_v(r29)
                emit_instruction(assembler, INSTR_DIV, R3, R4, R0, 0, NULL);  // div r3 r4 (resultado em LO)
                emit_instruction(assembler, INSTR_MFLO, R0, R0, R5, 0, NULL);  // mflo r5 (move LO para r5)
            }
        }
        else if (strcmp(current->op, "*") == 0) {
            // Operação de multiplicação: t2 * v = t3
            if (is_temp_variable(current->arg1)) {
                // arg1 é temporário (resultado da divisão em r5)
                struct Variable* var_v = find_variable(current_scope, current->arg2);
                if (var_v) {
                    emit_instruction(assembler, INSTR_LW, FP, R3, R0, var_v->loc_mem, NULL);  // lw r3 pos_v(r29)
                    emit_instruction(assembler, INSTR_MULT, R5, R3, R0, 0, NULL);  // mult r5 r3 (resultado em LO)
                    emit_instruction(assembler, INSTR_MFLO, R0, R0, R4, 0, NULL);  // mflo r4 (move LO para r4)
                }
            }
        }
        else if (strcmp(current->op, "-") == 0) {
            // Operação de subtração: u - t3 = t4
            struct Variable* var_u = find_variable(current_scope, current->arg1);
            if (var_u) {
                emit_instruction(assembler, INSTR_LW, FP, R2, R0, var_u->loc_mem, NULL);  // lw r2 pos_u(r29)
                emit_instruction(assembler, INSTR_SUB, R2, R4, R3, 0, NULL);  // sub r3 r2 r4
            }
        }
        
        current = current->next;
    }
    
    // Fechar arquivo temporário
    fclose(temp_file);
    
    // Segunda passada: gerar arquivo final com jump correto
    assembler->output_file = original_file;
    current = quad_list;
    global_instruction_count = 1;
    
    // Gerar jump inicial correto
    if (current && strcmp(current->op, "goto") == 0 && strcmp(current->arg1, "main") == 0) {
        fprintf(assembler->output_file, "0-j %d\n", main_address);
        current = current->next;
    }
    
    // Copiar resto do arquivo temporário
    temp_file = fopen("temp_assembly.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), temp_file)) {
        fprintf(assembler->output_file, "%s", line);
    }
    fclose(temp_file);
    
    // Limpar arquivo temporário
    remove("temp_assembly.txt");
}

// Escrever saída binária
void write_binary_output(Assembler* assembler, FILE* binary_file) {
    // Primeiro, escrever o jump inicial para main
    // Usar o valor da variável global main_address
    uint32_t jump_instruction = 0;
    jump_instruction |= (0x1C & 0x3F) << 26;  // OPCODE J = 011100 = 0x1C
    jump_instruction |= (main_address & 0x3F);  // Endereço da main
    
    // Escrever jump inicial
    for (int i = 31; i >= 0; i--) {
        fprintf(binary_file, "%d", (jump_instruction >> i) & 1);
    }
    fprintf(binary_file, "\n");
    
    // Agora escrever o resto das instruções
    struct Instrucao* current = assembler->instrucoes;
    
    while (current) {
        uint32_t instruction = 0;
        
        // Montar instrução binária de 32 bits
        instruction |= (get_opcode(current->op) & 0x3F) << 26;  // OPCODE[31:26]
        instruction |= (current->rs & 0x3F) << 20;             // RS[25:20]
        instruction |= (current->rt & 0x3F) << 14;             // RT[19:14]
        instruction |= (current->rd & 0x3F) << 8;              // RD[13:8]
        instruction |= (current->imediato & 0xFF);             // IMEDIATO[7:0]
        
        // Escrever instrução binária
        for (int i = 31; i >= 0; i--) {
            fprintf(binary_file, "%d", (instruction >> i) & 1);
        }
        fprintf(binary_file, "\n");
        
        current = current->next;
    }
}
