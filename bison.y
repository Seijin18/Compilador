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
%token '+' '-' '*' '/' '=' ';' ',' '(' ')' '[' ']' '{' '}'
%token '*' '/' */

%token <stringValue> NUMERO
%token <stringValue> ID
%token IF ELSE WHILE INT RETURN VOID IGUAL DIFERENTE MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL YYEOF

%left '+' '-'
%left '*' '/'

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

programa: declaracao_lista YYEOF { $$ = newASTNode("programa", $1, NULL); };

declaracao_lista: declaracao_lista declaracao { $$ = newASTNode("declaracao_lista", $1, $2); }
                | declaracao { $$ = newASTNode("declaracao_lista", $1, NULL); }
                ;

declaracao: var_declaracao { $$ = newASTNode("declaracao", $1, NULL); }
          | fun_declaracao { $$ = newASTNode("declaracao", $1, NULL); }
          ;

var_declaracao: tipo_especificador ID ';' { $$ = newASTNode("var_declaracao", $1, newASTNodeValue("ID", $2)); }
              | tipo_especificador ID '[' NUMERO ']' ';' { $$ = newASTNode("var_declaracao", $1, newASTNodeValue("ID", $2)); }
              ;

tipo_especificador: INT { $$ = newASTNodeValue("tipo_especificador", "int"); }
                  | VOID { $$ = newASTNodeValue("tipo_especificador", "void"); }
                  ;

fun_declaracao: tipo_especificador ID '(' params ')' composto_decl
    { $$ = newASTNode("fun_declaracao", $1, newASTNodeValue("ID", $2)); }
    ;

params: param_lista
    { $$ = newASTNode("params", $1, NULL); }
    | VOID
    { $$ = newASTNodeValue("params", "void"); }
    ;

param_lista: param_lista ',' param
    { $$ = newASTNode("param_lista", $1, $3); }
    | param
    ;

param: tipo_especificador ID
    { $$ = newASTNode("param", $1, newASTNodeValue("ID", $2)); }
    | tipo_especificador ID '[' ']'
    { $$ = newASTNode("param", $1, newASTNodeValue("ID", $2)); }
    ;

composto_decl: '{' local_declaracoes statement_lista '}'
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

expressao_decl: expressao ';'
    { $$ = newASTNode("expressao_decl", $1, NULL); }
    | ';'
    { $$ = newASTNodeValue("expressao_decl", ";"); }
    ;

selecao_decl: IF '(' expressao ')' statement
    { $$ = newASTNode("selecao_decl", $3, $5); }
    | IF '(' expressao ')' statement ELSE statement
    { $$ = newASTNode("selecao_decl", $3, newASTNode("else", $5, $7)); }
    ;
iteracao_decl: WHILE '(' expressao ')' statement
    { $$ = newASTNode("iteracao_decl", $3, $5); }
    ;

retorno_decl: RETURN ';'
    { $$ = newASTNodeValue("retorno_decl", "return"); }
    | RETURN expressao ';'
    { $$ = newASTNode("retorno_decl", $2, NULL); }
    ;

expressao: var '=' expressao
    { $$ = newASTNode("expressao", $1, $3); }
    | simples_expressao
    ;

var: ID
    { $$ = newASTNodeValue("var", $1); }
    | ID '[' expressao ']'
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

soma_expressao: soma_expressao '+' termo
    { $$ = newASTNode("soma_expressao", $1, $3); }
    | soma_expressao '-' termo
    { $$ = newASTNode("soma_expressao", $1, $3); }
    | termo
    ;

termo: termo '*' fator
    { $$ = newASTNode("termo", $1, $3); }
    | termo '/' fator
    { $$ = newASTNode("termo", $1, $3); }
    | fator
    ;

fator: '(' expressao ')'
    { $$ = newASTNode("fator", $2, NULL); }
    | var
    | ativacao
    | NUMERO
    { $$ = newASTNodeValue("fator", $1); }
    ;

ativacao: ID '(' args ')'
    { $$ = newASTNode("ativacao", newASTNodeValue("ID", $1), $3); }
    ;

args: arg_lista
    { $$ = newASTNode("args", $1, NULL); }
    | /* empty */
    { $$ = NULL; }
    ;

arg_lista: arg_lista ',' expressao
    { $$ = newASTNode("arg_lista", $1, $3); }
    | expressao
    ;
%%

int yyerror(char *s) {
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
    fprintf(stderr, "Unexpected token: %s\n", yytext);
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
        printf("Lexema: %s\n", lex->item);
        printf("Token_Num: %d\n", lex->token_type);
        printf("Token: %s\n", lex->token);
        printf("Flag: %d\n\n", flag);
    }while(lex->token_type != 284 && flag != -1 && flag != 0);
    if (flag == 0)
    {
        yyerror (YY_("lexical error"));
        return -1;
    }
    else if (flag == -1)
    {
        printf("E todo mundo morreu\n");
        return 0;
    }

    yylineno = lex->line;
    if (Get_Token_Type(lex->token) == 258)
    {
        yylval.intValue = *(lex->item) - '0';
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