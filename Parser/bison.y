%{
#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

FILE *fp;
Bloco *buffer = NULL;
Lex *lex;

int openned = 0;
int yylineno;
int valyy;
char yytext[64];

// SymbolTable* TabelaSimbolos;
AASNode *root;

int yyerror(char *s);

int yylex(void);

%}

%union {
    int intValue;
    char* stringValue;
}

%start programa
%token NUM
%token ID
%token IF ELSE WHILE INT RETURN VOID COMP DIF GT LT GE
%token LE SOMA SUB MULT DIV ATR
%token PTV VIR APAR FPAR ACOL 
%token FCOL ACHV FCHV
%token CMT

%left SOMA SUB
%left MULT DIV



%%
programa: declaracao_lista
        ;

declaracao_lista: declaracao_lista declaracao
                | declaracao 
                ;

declaracao: var_declaracao 
          | fun_declaracao 
          ;

var_declaracao: tipo_especificador ID PTV 
                | tipo_especificador ID ACOL NUM FCOL PTV
              ;

tipo_especificador: INT
                  | VOID
                  ;

fun_declaracao: tipo_especificador ID APAR params FPAR composto_decl
    ;

params: param_lista
    | VOID
    ;

param_lista: param_lista VIR param
    | param
    ;

param: tipo_especificador ID
    | tipo_especificador ID ACOL FCOL
    ;

composto_decl: ACHV local_declaracoes statement_lista FCHV
    ;

local_declaracoes: local_declaracoes var_declaracao
    |
    ;

statement_lista: statement_lista statement
    |
    ;

statement: expressao_decl
    | composto_decl
    | selecao_decl
    | iteracao_decl
    | retorno_decl
    ;

expressao_decl: expressao PTV
    | PTV
    ;

selecao_decl: IF APAR expressao FPAR statement
    | IF APAR expressao FPAR statement ELSE statement
    ;

iteracao_decl: WHILE APAR expressao FPAR statement
    ;

retorno_decl: RETURN PTV
    | RETURN expressao PTV
    ;


expressao: var ATR expressao
    | simples_expressao
    ;

var: ID
    | ID ACOL expressao FCOL
    ;

simples_expressao: soma_expressao relacional soma_expressao
    | soma_expressao
    ;


relacional: LE
    | LT
    | GT
    | GE
    | COMP
    | DIF
    ;

soma_expressao: soma_expressao aditivo termo
    | termo
    ;

aditivo: SOMA
       | SUB
       ;

termo: termo operador_multiplicativo fator
    | fator
    ;

operador_multiplicativo: MULT
                       | DIV
                       ;

fator: APAR expressao FPAR
    | var
    | ativacao
    | NUM
    ;

ativacao: ID APAR args FPAR
    | ID APAR FPAR
    ;

args: arg_lista
    ;

arg_lista: arg_lista VIR expressao
    | expressao
    ;
%%
int yyerror(char *s) {
    if (lex->token == ER) {
        printf("%s '%s' INVALIDO [linha: %d, coluna: %d]\n", s, lex->lexema, lex->line + 1, lex->column);
    } else {
        printf("%s '%s' INVALIDO [linha: %d]\n", s, lex->lexema, lex->line + 1);
    }
    return 0;
}

int yylex(void) {
    int token;

    do {
        token = get_lexema(buffer, lex, fp);
        if (token == ER) {
            yyerror("ERRO LEXICO:");
            return ER;
        }
    } while (token == CMT);
    strcpy(yytext, lex->lexema);
    yylineno = lex->line;
    if (token == NUM) {
        yylval.intValue = atoi(lex->lexema);
    }
    return token;
}

int main(int argc, char *argv[]) {
    int option = -1;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    for(int i = 0; i < argc; i++) {
        if(argv[i][0] == '-') {
            if (argv[i][1] == 'l' || argv[i][1] == 'L') {
                option = 0;
            } else if (argv[i][1] == 'p' || argv[i][1] == 'P') {
                option = 1;
            } else if (argv[i][1] == 's' || argv[i][1] == 'S') {
                option = 2;
            }
            else {
                printf("Invalid option\n");
                return 1;
            }
        }
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int buffer_size = 20;
    buffer = allocate_buffer(buffer_size);
    if (buffer == NULL) {
        return 1;
    }

    lex = allocate_lex();
    int token;
    char *token_name;
    
    if (option == 0) {
        do{
            token = yylex();
            token_name = get_token_name(token);
            if (token == ER) {
                break;
            }
            else {
                printf("%s\t'%s' \t[linha: %d]\n", token_name, lex->lexema, lex->line + 1);
            }
            
        } while (token != EOF && token != ER);
    } else if (option == 1) {
        yyparse();
    }

    fclose(fp);
    deallocate_buffer(buffer);
    deallocate_lex(lex);

    return 0;
}