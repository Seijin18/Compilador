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
    struct ASTNode* children;
    struct ASTNode* sibling;
} ASTNode;

ASTNode* newASTNode(char* type) {
    ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
    node->type = type;
    node->value = NULL;
    node->children = NULL;
    node->sibling = NULL;
    return node;
}

ASTNode* newASTNodeValue(char* type, char* value) {
    ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value;
    node->children = NULL;
    node->sibling = NULL;
    return node;
}

ASTNode* addASTNode(ASTNode* node, ASTNode* child) {
    if (node->children == NULL) {
        node->children = child;
    } else {
        ASTNode* sibling = node->children;
        while (sibling->sibling != NULL) {
            sibling = sibling->sibling;
        }
        sibling->sibling = child;
    }
    return node;
}

void printAST(ASTNode* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    if (node->value != NULL) {
        printf("%s: %s\n", node->type, node->value);
    } else {
        printf("%s\n", node->type);
    }
    if (node->children != NULL) {
        printAST(node->children, depth + 1);
    }
    if (node->sibling != NULL) {
        printAST(node->sibling, depth);
    }
}
/*
void buildSymbolTable(ASTNode* node, SymbolTable* table) {
    if (node->type == NODE_DECLARATION) {
        // Add the identifier to the symbol table
        addSymbol(table, node->children->value, node->sibling->type);
    } else if (node->type == NODE_USAGE) {
        // Look up the identifier in the symbol table
        Symbol* symbol = getSymbol(table, node->value);
        if (symbol == NULL) {
            printf("Error: Variable %s has not been declared\n", node->value);
            exit(1);
        }
    }
    // Recursively build the symbol table for the children of the node
    if (node->children != NULL) {
        buildSymbolTable(node->children, table);
    }
    if (node->sibling != NULL) {
        buildSymbolTable(node->sibling, table);
    }
}

void checkSemantics(ASTNode* node) {
    if (node->type == NODE_ASSIGNMENT) {
        // Check that the variable has been declared
        if (!isDeclared(node->children->value)) {
            printf("Error: Variable %s has not been declared\n", node->children->value);
            exit(1);
        }
        // Check that the types are compatible
        if (!areTypesCompatible(node->children->type, node->sibling->type)) {
            printf("Error: Incompatible types in assignment\n");
            exit(1);
        }
    }
    // Recursively check the children of the node
    if (node->children != NULL) {
        checkSemantics(node->children);
    }
    if (node->sibling != NULL) {
        checkSemantics(node->sibling);
    }
}*/

FILE *fp;
Bloco *buffer = NULL;
int openned = 0;
int yylineno;
int valyy;
char yytext[64];

ASTNode* root; // Declare a global variable to store the root node

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
%token MULTIPLICACAO DIVISAO */

%token <stringValue> NUMERO
%token <stringValue> ID
%token IF ELSE WHILE INT RETURN VOID IGUAL DIFERENTE MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL SOMA SUBTRACAO MULTIPLICACAO DIVISAO ATRIBUICAO PONTO_VIRGULA VIRGULA ABRE_PARENTESE FECHA_PARENTESE ABRE_COLCHETE FECHA_COLCHETE ABRE_CHAVES FECHA_CHAVES YYEOF

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

programa: declaracao_lista YYEOF { $$ = newASTNode("programa"); root = $$; addASTNode($$, $1); }
        ;

declaracao_lista: declaracao_lista declaracao { $$ = newASTNode("declaracao_lista"); addASTNode($$, $1); addASTNode($$, $2); }
                | declaracao { $$ = newASTNode("declaracao_lista"); addASTNode($$, $1); }
                ;

declaracao: var_declaracao { $$ = newASTNode("declaracao"); addASTNode($$, $1); }
          | fun_declaracao { $$ = newASTNode("declaracao"); addASTNode($$, $1); }
          ;

var_declaracao: tipo_especificador ID PONTO_VIRGULA { $$ = newASTNode("var_declaracao"); addASTNode($$, newASTNodeValue("ID", $2)); }
              | tipo_especificador ID ABRE_COLCHETE NUMERO FECHA_COLCHETE PONTO_VIRGULA { $$ = newASTNode("var_declaracao"); addASTNode($$, newASTNodeValue("ID", $2)); }
              ;

tipo_especificador: INT { $$ = newASTNodeValue("tipo_especificador", "int");}
                  | VOID { $$ = newASTNodeValue("tipo_especificador", "void"); }
                  ;

fun_declaracao: tipo_especificador ID ABRE_PARENTESE params FECHA_PARENTESE composto_decl
    { $$ = newASTNode("fun_declaracao"); addASTNode($$, newASTNodeValue("ID", $2)); addASTNode($$, $4); addASTNode($$, $6);}
    ;

params: param_lista
    { $$ = newASTNode("params"); addASTNode($$, $1); }
    | VOID
    { $$ = newASTNodeValue("params", "void"); }
    ;

param_lista: param_lista VIRGULA param
    { $$ = newASTNode("param_lista"); addASTNode($$, $1); addASTNode($$, $3); }
    | param
    ;

param: tipo_especificador ID
    { $$ = newASTNode("param"); addASTNode($$, newASTNodeValue("ID", $2)); }
    | tipo_especificador ID ABRE_COLCHETE FECHA_COLCHETE
    { $$ = newASTNode("param"); addASTNode($$, newASTNodeValue("ID", $2)); }
    ;

composto_decl: ABRE_CHAVES local_declaracoes statement_lista FECHA_CHAVES
    { $$ = newASTNode("composto_decl"); addASTNode($$, $2); addASTNode($$, $3); }
    ;

local_declaracoes: local_declaracoes var_declaracao
    { $$ = newASTNode("local_declaracoes"); addASTNode($$, $1); addASTNode($$, $2); }
    | /* empty */
    { $$ = NULL; }
    ;

statement_lista: statement_lista statement
    { $$ = newASTNode("statement_lista"); addASTNode($$, $1); addASTNode($$, $2); }
    | /* empty */
    { $$ = NULL; }
    ;

statement: expressao_decl
    { $$ = newASTNode("statement"); addASTNode($$, $1); }
    | composto_decl
    { $$ = newASTNode("statement"); addASTNode($$, $1); }
    | selecao_decl
    { $$ = newASTNode("statement"); addASTNode($$, $1); }
    | iteracao_decl
    { $$ = newASTNode("statement"); addASTNode($$, $1); }
    | retorno_decl
    { $$ = newASTNode("statement"); addASTNode($$, $1); }
    ;

expressao_decl: expressao PONTO_VIRGULA
    { $$ = newASTNode("expressao_decl"); addASTNode($$, $1); }
    | PONTO_VIRGULA
    { $$ = newASTNodeValue("expressao_decl", ";"); }
    ;

selecao_decl: IF ABRE_PARENTESE expressao FECHA_PARENTESE statement
    { $$ = newASTNode("selecao_decl"); addASTNode($$, $3); addASTNode($$, $5); }
    | IF ABRE_PARENTESE expressao FECHA_PARENTESE statement ELSE statement
    { $$ = newASTNode("selecao_decl"); addASTNode($$, $3); addASTNode($$, $5); addASTNode($$, $7); }
    ;
iteracao_decl: WHILE ABRE_PARENTESE expressao FECHA_PARENTESE statement
    { $$ = newASTNode("iteracao_decl"); addASTNode($$, $3); addASTNode($$, $5); }
    ;

retorno_decl: RETURN PONTO_VIRGULA
    { $$ = newASTNodeValue("retorno_decl", "return"); }
    | RETURN expressao PONTO_VIRGULA
    { $$ = newASTNode("retorno_decl"); addASTNode($$, $2); }
    ;

expressao: var ATRIBUICAO expressao
    { $$ = newASTNode("expressao"); addASTNode($$, $1); addASTNode($$, $3); }
    | simples_expressao
    ;

var: ID
    { $$ = newASTNodeValue("var", $1); }
    | ID ABRE_COLCHETE expressao FECHA_COLCHETE
    { $$ = newASTNode("var"); addASTNode($$, newASTNodeValue("ID", $1)); addASTNode($$, $3); }
    ;

simples_expressao: soma_expressao relacional soma_expressao
    { $$ = newASTNode("simples_expressao"); addASTNode($$, $1); addASTNode($$, $2); addASTNode($$, $3); }
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
    { $$ = newASTNode("soma_expressao"); addASTNode($$, $1); addASTNode($$, $3); }
    | soma_expressao SUBTRACAO termo
    { $$ = newASTNode("soma_expressao"); addASTNode($$, $1); addASTNode($$, $3); }
    | termo
    ;

termo: termo MULTIPLICACAO fator
    { $$ = newASTNode("termo"); addASTNode($$, $1); addASTNode($$, $3); }
    | termo DIVISAO fator
    { $$ = newASTNode("termo"); addASTNode($$, $1); addASTNode($$, $3); }
    | fator
    ;

fator: ABRE_PARENTESE expressao FECHA_PARENTESE
    { $$ = newASTNode("fator"); addASTNode($$, $2); }
    | var
    | ativacao
    | NUMERO
    { $$ = newASTNodeValue("fator", $1); }
    ;

ativacao: ID ABRE_PARENTESE args FECHA_PARENTESE
    { $$ = newASTNode("ativacao"); addASTNode($$, newASTNodeValue("ID", $1)); addASTNode($$, $3); }
    ;

args: arg_lista
    { $$ = newASTNode("args"); addASTNode($$, $1); }
    | /* empty */
    { $$ = NULL; }
    ;

arg_lista: arg_lista VIRGULA expressao
    { $$ = newASTNode("arg_lista"); addASTNode($$, $1); addASTNode($$, $3); }
    | expressao
    ;
%%

int yyerror(char *s) {
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
    fprintf(stderr, "Unexpected token: %s\n", yytext);
    return 0;
}

int yylex(void) {
    if (buffer == NULL)
    {
        allocate_buffer(&buffer);
    }

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
    
    if (openned == 0)
    {
        fp = fopen("teste.txt", "r");
        openned = 1;
    }

    char c;
    int flag = 1;
    int tokentype;
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
        tokentype = lex->token_type;
        /* printf("\nLexema: %s\n", lex->item);
        printf("Token_type: %d\n", lex->token_type);
        printf("Token: %s\n", lex->token);
        printf("Flag: %d\n\n", flag);  */
        yylineno = lex->line;
    }while(flag == 1 && tokentype == 285);
    //printf("\nacabou\n\n");
    if (flag == 0)
    {
        yyerror (YY_("lexical error"));
        return 256;
    }
    else if (flag == -1)
    {
        //printf("E todo mundo morreu\n");
        return 0;
    }

    yylineno = lex->line;
    if (tokentype == 258)
    {
        yylval.intValue = *(lex->item) - '0';
    }
    //yytext = lex->item;
    strcpy(yytext, lex->item);

    deallocate_lexema(lex);

    //printf("Token: %d\n", tokentype);
    return tokentype;
}

int main(void) {
    yyparse();
    //checkSemantics(root);
    printAST(root, 0);
    return 0;
}