#ifndef FUNCS_H
#define FUNCS_H

#include "bison.tab.h"
#include <stdio.h>

#define AC -9
#define ER -10

extern char simbolos[];

typedef struct Bloco_buffer {
    char *buffer;
    int char_pos;
    int line;
    int column;
    int size;
} Bloco;

typedef struct Lexema 
{
    char *lexema;
    int token;
    int line;
    int column;
} Lex;


typedef enum {KStmt, KExp} NodeKind;
typedef enum {KIf, KWhile, KAssign, KReturn, KCall, KVar, Kvet, KFunc} StmtKind;
typedef enum {KOp, KConst, KId, KType, KVarId, KVetID} ExpKind;
typedef enum {KInt, KVoid} TypeKind;

typedef struct AASNode
{
    struct AASNode* children;
    struct AASNode* sibling;
    int token;
    int value;
    char *name;
    int line;
    NodeKind node;
    StmtKind stmt;
    ExpKind exp;
    TypeKind type;
} AASNode;


char *get_token_name(int token);
Bloco *allocate_buffer(int size);
void deallocate_buffer(Bloco *buffer);
char get_next_char(Bloco *buffer, FILE *file);
void load_buffer(Bloco *buffer, FILE *file);
void replace_print(Bloco *buffer, int size);
int is_symbol(char c);
int is_char(char c);
int is_digit(char c);
int is_space(char c);
Lex *allocate_lex();
void deallocate_lex(Lex *lex);
void clear_lex(Lex *lex);
int check_token(int table_state);
int get_token(Lex *lex, Bloco *buffer, FILE *file);
int get_lexema(Bloco *buffer, Lex *lex, FILE *file);
AASNode *newAASNode(StmtKind kstmt, ExpKind kexp);
AASNode *addAASNode(AASNode *node, AASNode *child);
void printAAS(AASNode *node, int depth);
void deallocateAAS(AASNode *node);


#endif