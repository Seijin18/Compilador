%{
#include <stdio.h>
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
%}

%union {
    int intValue;
    char* stringValue;
    ASTNode* nodeValue;
}

%token <stringValue> ID
%token <intValue> NUM
%token INT VOID
%token <stringValue> IF ELSE WHILE RETURN
%token <stringValue> LE LT GT GE EQ NE

%type <nodeValue> programa
%type <nodeValue> declaracao_lista
%type <nodeValue> declaracao
%type <nodeValue> var_declaracao
%type <nodeValue> tipo_especificador
%type <nodeValue> fun_declaracao params param_lista param composto_decl
%type <nodeValue> local_declaracoes statement_lista statement expressao_decl
%type <nodeValue> selecao_decl iteracao_decl retorno_decl expressao var
%type <nodeValue> simples_expressao relacional soma_expressao soma termo mult
%type <nodeValue> fator ativacao args arg_lista


%%

programa: declaracao_lista { $$ = newASTNode("programa", $1, NULL); };

declaracao_lista: declaracao_lista declaracao { $$ = newASTNode("declaracao_lista", $1, $2); }
                | declaracao { $$ = newASTNode("declaracao_lista", $1, NULL); }
                ;

declaracao: var_declaracao { $$ = newASTNode("declaracao", $1, NULL); }
          | fun_declaracao { $$ = newASTNode("declaracao", $1, NULL); }
          ;

var_declaracao: tipo_especificador ID ';' { $$ = newASTNode("var_declaracao", $1, newASTNodeValue("ID", $2)); }
              | tipo_especificador ID '[' NUM ']' ';' { $$ = newASTNode("var_declaracao", $1, newASTNodeValue("ID", $2)); }
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

relacional: LE
    { $$ = newASTNodeValue("relacional", "<="); }
    | LT
    { $$ = newASTNodeValue("relacional", "<"); }
    | GT
    { $$ = newASTNodeValue("relacional", ">"); }
    | GE
    { $$ = newASTNodeValue("relacional", ">="); }
    | EQ
    { $$ = newASTNodeValue("relacional", "=="); }
    | NE
    { $$ = newASTNodeValue("relacional", "!="); }
    ;

soma_expressao: soma_expressao soma termo
    { $$ = newASTNode("soma_expressao", $1, $3); }
    | termo
    ;

soma: '+'
    { $$ = newASTNodeValue("soma", "+"); }
    | '-'
    { $$ = newASTNodeValue("soma", "-"); }
    ;

termo: termo mult fator
    { $$ = newASTNode("termo", $1, $3); }
    | fator
    ;

mult: '*'
    { $$ = newASTNodeValue("mult", "*"); }
    | '/'
    { $$ = newASTNodeValue("mult", "/"); }
    ;

fator: '(' expressao ')'
    { $$ = newASTNode("fator", $2, NULL); }
    | var
    | ativacao
    | NUM
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
    fprintf(stderr, "error: %s\n", s);
    return 0;
}

int main(void) {
    yyparse();
    return 0;
}