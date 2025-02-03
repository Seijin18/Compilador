#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AC -9
#define ER -10

#define MAX 255


typedef enum {KStmt, KExp} NodeKind;
typedef enum {KIf, KWhile, KAssign, KReturn, KCall, KVar, KVet, KFunc, KProg} StmtKind;
typedef enum {KOp, KConst, KId, KType, KVarId, KVetId} ExpKind;
typedef enum {KInt, KVoid} TypeKind;
typedef enum {Var, Func} IdKind;

extern char simbolos[];

typedef struct Bloco_buffer Bloco;
struct Bloco_buffer {
    char *buffer;
    int char_pos;
    int line;
    int column;
    int size;
};

typedef struct Lexema Lex;
struct Lexema 
{
    char *lexema;
    int token;
    int line;
    int column;
};

typedef struct AASNode AASNode;
struct AASNode {
    struct AASNode* children;
    struct AASNode* sibling;
    int token;
    int value;
    char *name;
    int line;
    char *escopo;
    NodeKind node;
    StmtKind stmt;
    ExpKind exp;
    TypeKind type;
};

typedef struct SimbCell SimbCell;
struct SimbCell {
    char *name;
    char *escopo;
    TypeKind type;
    IdKind IdKind;
    int line;
    struct SimbCell *next;
    struct SimbCell *sibling;
};

char *get_token_name(int token);
Bloco *allocate_buffer(int size);
void deallocate_buffer(Bloco *buffer);
char get_next_char(Bloco *buffer, FILE *file);
void load_buffer(Bloco *buffer, FILE *file);
void replace_print(Bloco *buffer, int size);
int is_symbol(char ch);
int is_char(char ch);
int is_digit(char ch);
int is_space(char ch);
Lex *allocate_lex();
void deallocate_lex(Lex *lex);
void clear_lex(Lex *lex);
int check_token(int table_state);
int get_token(Lex *lex, Bloco *buffer, FILE *file);
int get_lexema(Bloco *buffer, Lex *lex, FILE *file);
AASNode *newAASNode(StmtKind kstmt, ExpKind kexp);
AASNode *newAASNodeExp(ExpKind kexp);
AASNode *newAASNodeStmt(StmtKind kstmt);
AASNode *addAASNode(AASNode *node, AASNode *child);
AASNode *addAASNodeSibling(AASNode *node, AASNode *sibling);
void updateEscopo(AASNode *node, char *escopo);
void printAAS(AASNode *node, int depth);
void deallocateAAS(AASNode *node);

char *copyString(char *src);
char *getTypeName(TypeKind type);

static int hash(char *name);
SimbCell *searchTabSimb(SimbCell *tab, char *name, char *escopo);
int insertTabSimb(SimbCell *tab, AASNode *node);
int buildTabSimb(SimbCell *tab, AASNode *node);
void printTabSimb(SimbCell *tabSimb, AASNode *node);
void deallocateTabSimb(SimbCell *tabSimb);

#endif