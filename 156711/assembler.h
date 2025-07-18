#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "intermediate.h"
#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Forward declarations (evitando conflito com enum Var em funcs.h)
typedef struct Variable Variable;
typedef struct Escopo Escopo;
typedef struct Instrucao Instrucao;
typedef struct TempReg TempReg;
typedef struct Assembler Assembler;

// Enums para operações e registradores
typedef enum {
    // Aritméticas e Lógicas
    INSTR_ADD, INSTR_SUB, INSTR_MULT, INSTR_DIV, INSTR_AND, INSTR_OR, INSTR_SLL, INSTR_SRL, INSTR_SLT,
    // Movimentação
    INSTR_MFHI, INSTR_MFLO, INSTR_MOVE,
    // Salto
    INSTR_JR, INSTR_JALR, INSTR_J, INSTR_JAL,
    // Imediatas
    INSTR_LA, INSTR_ADDI, INSTR_SUBI, INSTR_ANDI, INSTR_ORI, INSTR_LI,
    // Branch
    INSTR_BEQ, INSTR_BNE, INSTR_BGT, INSTR_BGTE, INSTR_BLT, INSTR_BLTE,
    // Memória
    INSTR_LW, INSTR_SW,
    // I/O
    INSTR_OUTPUTMEM, INSTR_OUTPUTREG, INSTR_OUTPUT_RESET, INSTR_INPUT,
    // Controle
    INSTR_HALT
} Instrucoes;

typedef enum {
    R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15,
    R16, R17, R18, R19, R20, R21, R22, R23, R24, R25, R26, R27, R28, R29, R30, R31,
    // Registradores especiais
    FP = 29,    // Frame Pointer  
    SP = 30,    // Stack Pointer
    RA = 31     // Return Address
} Registradores;

// Estrutura para variáveis
struct Variable {
    char nome[32];
    int tipo;        // 0: int, 1: vetor
    int loc_mem;     // Endereço absoluto ou offset
    int tamanho;     // Para vetores
    struct Variable* next;
};

// Estrutura para escopos
struct Escopo {
    char nome[32];       // "global", "main", "gcd"
    int pos_mem;         // Próxima posição livre no frame
    struct Variable* variaveis;      // Lista de variáveis deste escopo
    struct Escopo* next;
};

// Estrutura para instruções assembly
struct Instrucao {
    Instrucoes op;
    Registradores rs, rt, rd;
    int imediato;
    char label[32];
    struct Instrucao* next;
};

// Estrutura para registradores temporários
struct TempReg {
    char var_name[32];
    Registradores reg;
    bool em_uso;
};

// Estrutura principal do assembler
struct Assembler {
    struct Instrucao* instrucoes;
    struct Instrucao* ultima_instrucao;
    struct Escopo* escopos;
    struct TempReg temp_regs[26];  // $t0 a $t25
    int label_count;
    int next_global_addr;
    FILE* output_file;
};

// Funções principais
Assembler* init_assembler(FILE* output);
void free_assembler(Assembler* assembler);
void generate_assembly(Assembler* assembler, QuadNode* quad_list);
void write_binary_output(Assembler* assembler, FILE* binary_file);

// Funções auxiliares
void emit_instruction(Assembler* assembler, Instrucoes op, Registradores rs, 
                     Registradores rt, Registradores rd, int imediato, const char* label);
Registradores allocate_register(Assembler* assembler, const char* var_name);
void free_register(Assembler* assembler, Registradores reg);
Escopo* find_scope(Assembler* assembler, const char* scope_name);
struct Variable* find_variable(Escopo* scope, const char* var_name);
void add_variable(Escopo* scope, const char* name, int tipo, int tamanho);
Escopo* create_scope(Assembler* assembler, const char* name);

// Funções para conversão de instruções específicas
void process_arithmetic(Assembler* assembler, QuadNode* quad);
void process_assignment(Assembler* assembler, QuadNode* quad);
void process_function_call(Assembler* assembler, QuadNode* quad);
void process_branch(Assembler* assembler, QuadNode* quad);
void process_memory_access(Assembler* assembler, QuadNode* quad);
void process_io(Assembler* assembler, QuadNode* quad);

// Funções utilitárias
char* get_instruction_name(Instrucoes op);
char* get_register_name(Registradores reg);
int get_opcode(Instrucoes op);
bool is_temp_variable(const char* name);
bool is_constant(const char* name);
int get_constant_value(const char* name);
Registradores get_register_by_name(const char* name);

#endif // ASSEMBLER_H
