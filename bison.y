%{
#include "funcs.h"
//#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct ASTNode {
    char* type;
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

ASTNode* newASTNode(char* type, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->value = NULL;
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* newASTNodeValue(char* type, char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int yylineno;
int valyy;
char yytext[64];

int yyerror(char *s);

int yylex(void);
%}

%union {
    int intValue;
    char* stringValue;
    ASTNode* nodeValue;
}

/* %token <stringValue> ID
%token <intValue> NUM
%token INT VOID
%token <stringValue> IF ELSE WHILE RETURN
%token <stringValue> LE LT GT GE EQ NE
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO ATRIBUICAO PONTO_VIRGULA VIRGULA ABRE_PARENTESE FECHA_PARENTESE ABRE_COLCHETE FECHA_COLCHETE ABRE_CHAVES FECHA_CHAVES
%token '*' '/' */

%token <stringValue> NUMERO
%token <stringValue> ID
%token IF ELSE WHILE INT RETURN VOID SOMA SUBTRACAO MULTIPLICACAO DIVISAO ATRIBUICAO IGUAL DIFERENTE MAIOR MENOR ABRE_PARENTESE FECHA_PARENTESE ABRE_CHAVES FECHA_CHAVES ABRE_COLCHETE FECHA_COLCHETE PONTO_VIRGULA VIRGULA   MAIOR_IGUAL MENOR_IGUAL

%left SOMA SUBTRACAO
%left MULTIPLICACAO DIVISAO

%type <nodeValue> programa
%type <nodeValue> declaracao_lista
%type <nodeValue> declaracao
%type <nodeValue> var_declaracao
%type <nodeValue> tipo_especificador
%type <nodeValue> fun_declaracao params param_lista param composto_decl
%type <nodeValue> local_declaracoes statement_lista statement expressao_decl
%type <nodeValue> selecao_decl iteracao_decl retorno_decl expressao var
%type <nodeValue> simples_expressao relacional soma_expressao termo
%type <nodeValue> fator ativacao args arg_lista


%%

programa: declaracao_lista { $$ = newASTNode("programa", $1, NULL); };

declaracao_lista: declaracao_lista declaracao { $$ = newASTNode("declaracao_lista", $1, $2); }
                | declaracao { $$ = newASTNode("declaracao_lista", $1, NULL); }
                ;

declaracao: var_declaracao { $$ = newASTNode("declaracao", $1, NULL); }
          | fun_declaracao { $$ = newASTNode("declaracao", $1, NULL); }
          ;

var_declaracao: tipo_especificador ID PONTO_VIRGULA { $$ = newASTNode("var_declaracao", $1, newASTNodeValue("ID", $2)); }
              | tipo_especificador ID ABRE_COLCHETE NUMERO ABRE_COLCHETE PONTO_VIRGULA { $$ = newASTNode("var_declaracao", $1, newASTNodeValue("ID", $2)); }
              ;

tipo_especificador: INT { $$ = newASTNodeValue("tipo_especificador", "int"); }
                  | VOID { $$ = newASTNodeValue("tipo_especificador", "void"); }
                  ;

fun_declaracao: tipo_especificador ID ABRE_PARENTESE params ABRE_PARENTESE composto_decl
    { $$ = newASTNode("fun_declaracao", $1, newASTNodeValue("ID", $2)); }
    ;

params: param_lista
    { $$ = newASTNode("params", $1, NULL); }
    | VOID
    { $$ = newASTNodeValue("params", "void"); }
    ;

param_lista: param_lista VIRGULA param
    { $$ = newASTNode("param_lista", $1, $3); }
    | param
    ;

param: tipo_especificador ID
    { $$ = newASTNode("param", $1, newASTNodeValue("ID", $2)); }
    | tipo_especificador ID ABRE_COLCHETE FECHA_COLCHETE
    { $$ = newASTNode("param", $1, newASTNodeValue("ID", $2)); }
    ;

composto_decl: ABRE_CHAVES local_declaracoes statement_lista FECHA_CHAVES
    { $$ = newASTNode("composto_decl", $2, $3); }
    ;

local_declaracoes: local_declaracoes var_declaracao
    { $$ = newASTNode("local_declaracoes", $1, $2); }
    | /* empty */
    { $$ = NULL; }
    ;

statement_lista: statement_lista statement
    { $$ = newASTNode("statement_lista", $1, $2); }
    | /* empty */
    { $$ = NULL; }
    ;

statement: expressao_decl
    { $$ = newASTNode("statement", $1, NULL); }
    | composto_decl
    { $$ = newASTNode("statement", $1, NULL); }
    | selecao_decl
    { $$ = newASTNode("statement", $1, NULL); }
    | iteracao_decl
    { $$ = newASTNode("statement", $1, NULL); }
    | retorno_decl
    { $$ = newASTNode("statement", $1, NULL); }
    ;

expressao_decl: expressao PONTO_VIRGULA
    { $$ = newASTNode("expressao_decl", $1, NULL); }
    | PONTO_VIRGULA
    { $$ = newASTNodeValue("expressao_decl", ";"); }
    ;

selecao_decl: IF ABRE_PARENTESE expressao FECHA_PARENTESE statement
    { $$ = newASTNode("selecao_decl", $3, $5); }
    | IF ABRE_PARENTESE expressao FECHA_PARENTESE statement ELSE statement
    { $$ = newASTNode("selecao_decl", $3, newASTNode("else", $5, $7)); }
    ;
iteracao_decl: WHILE ABRE_PARENTESE expressao FECHA_PARENTESE statement
    { $$ = newASTNode("iteracao_decl", $3, $5); }
    ;

retorno_decl: RETURN PONTO_VIRGULA
    { $$ = newASTNodeValue("retorno_decl", "return"); }
    | RETURN expressao PONTO_VIRGULA
    { $$ = newASTNode("retorno_decl", $2, NULL); }
    ;

expressao: var ATRIBUICAO expressao
    { $$ = newASTNode("expressao", $1, $3); }
    | simples_expressao
    ;

var: ID
    { $$ = newASTNodeValue("var", $1); }
    | ID ABRE_COLCHETE expressao ABRE_COLCHETE
    { $$ = newASTNode("var", newASTNodeValue("ID", $1), $3); }
    ;

simples_expressao: soma_expressao relacional soma_expressao
    { $$ = newASTNode("simples_expressao", $1, $3); }
    | soma_expressao
    ;

relacional: MENOR_IGUAL
    { $$ = newASTNodeValue("relacional", "<="); }
    | MENOR
    { $$ = newASTNodeValue("relacional", "<"); }
    | MAIOR
    { $$ = newASTNodeValue("relacional", ">"); }
    | MAIOR_IGUAL
    { $$ = newASTNodeValue("relacional", ">="); }
    | IGUAL
    { $$ = newASTNodeValue("relacional", "=="); }
    | DIFERENTE
    { $$ = newASTNodeValue("relacional", "!="); }
    ;

soma_expressao: soma_expressao SOMA termo
    { $$ = newASTNode("soma_expressao", $1, $3); }
    | soma_expressao SUBTRACAO termo
    { $$ = newASTNode("soma_expressao", $1, $3); }
    | termo
    ;

termo: termo MULTIPLICACAO fator
    { $$ = newASTNode("termo", $1, $3); }
    | termo DIVISAO fator
    { $$ = newASTNode("termo", $1, $3); }
    | fator
    ;

fator: ABRE_PARENTESE expressao FECHA_PARENTESE
    { $$ = newASTNode("fator", $2, NULL); }
    | var
    | ativacao
    | NUMERO
    { $$ = newASTNodeValue("fator", $1); }
    ;

ativacao: ID ABRE_PARENTESE args FECHA_PARENTESE
    { $$ = newASTNode("ativacao", newASTNodeValue("ID", $1), $3); }
    ;

args: arg_lista
    { $$ = newASTNode("args", $1, NULL); }
    | /* empty */
    { $$ = NULL; }
    ;

arg_lista: arg_lista VIRGULA expressao
    { $$ = newASTNode("arg_lista", $1, $3); }
    | expressao
    ;
%%

int yyerror(char *s) {
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
    fprintf(stderr, "error: %s\n", s);
    return 0;
}

int yylex(void) {
    Bloco *buffer;
    allocate_buffer(&buffer);

    Lexema *lex;
    allocate_lexema(&lex);

    Lista ht[MAX];
    Tabela_Inicia(ht, MAX);
    int Char_Value;
    Char_Value = Get_Char_Value("if");
    Insere_Hash(Char_Value, "IF", ht, MAX);
    Char_Value = Get_Char_Value("else");
    Insere_Hash(Char_Value, "ELSE", ht, MAX);
    Char_Value = Get_Char_Value("while");
    Insere_Hash(Char_Value, "WHILE", ht, MAX);
    Char_Value = Get_Char_Value("return");
    Insere_Hash(Char_Value, "RETURN", ht, MAX);
    Char_Value = Get_Char_Value("int");
    Insere_Hash(Char_Value, "INT", ht, MAX);
    Char_Value = Get_Char_Value("void");
    Insere_Hash(Char_Value, "VOID", ht, MAX);

    FILE *fp;
    fp = fopen("teste.txt", "r");

    char c;
    int flag = 1;
    int tabela[28][19] = {
        { 3, 1, 4, 5, 6, 7, 8,22,21,15,16,19,20,17,18,12,11,21, 0},
        {-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        { 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 4},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 6},
        {-1,-1,-1,-1,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 7},
        {-1,-1,-1,-1,-1,-1, 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 8},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 9},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10},
        {-1,-1,-1,-1,-1,-1,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11},
        {-1,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,17},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22},
        {23,23,23,23,26,27,23,23,23,23,23,23,23,23,23,23,23,23,23},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,24},
        {23,23,23,23,23,26,23,23,23,23,23,23,23,23,23,23,23,23,25},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,26},
        {23,23,23,23,-1,23,23,23,23,23,23,23,23,23,23,23,23,23,27}};

    do{
        flag = get_next_lexema_tabela(lex, buffer, fp, tabela, ht);
        lex->token_type = Get_Token_Type(lex->token);
    }while(lex->token_type != 281 && flag != -1 && flag != 0);
        
    if (flag == 0)
    {
        printf("Erro lexico na linha %d\n", lex->line);
        return -1;
    }
    else if (flag == -1)
    {
        return 0;
    }

    yylineno = lex->line;
    if (Get_Token_Type(lex->token) == 258)
    {
        yyval.intValue = *(lex->item) - '0';
    }
    //yytext = lex->item;
    strcpy(yytext, lex->item);

    deallocate_lexema(lex);

    return lex->token_type;
}

int main(void) {
    yyparse();
    return 0;
}