%{
#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

FILE *fp;
Bloco *buffer = NULL;
Lex *lex;

int openned = 0;
int yylineno;
int valyy;
char yytext[64];


AASNode *root;
SimbCell simbTable[MAX];

int yyerror(char *s);

int yylex(void);

%}

%union {
    int intValue;
    char* stringValue;
    AASNode* node;
}

// %debug

%start programa
%token NUM
%token ID
%token IF ELSE WHILE INT RETURN VOID COMP DIF GT LT GE
%token LE SOMA SUB MULT DIV ATR
%token PTV VIR APAR FPAR ACOL   
%token FCOL ACHV FCHV
%token CMT
%type <node> programa declaracao_lista declaracao var_declaracao tipo_especificador fun_declaracao params param_lista param composto_decl local_declaracoes statement_lista statement expressao_decl selecao_decl iteracao_decl retorno_decl expressao var simples_expressao relacional soma_expressao aditivo termo operador_multiplicativo fator ativacao args arg_lista id num

%left SOMA SUB
%left MULT DIV


%%
programa: declaracao_lista { 
            root = newAASNodeStmt(KProg);
            addAASNode(root, $1);
        }
        ;

declaracao_lista: declaracao_lista declaracao {
                    $$ = $1;
                    addAASNodeSibling($$, $2);
                }
                | declaracao { $$ = $1; }
                ;

declaracao: var_declaracao { $$ = $1; }
          | fun_declaracao { $$ = $1; }
          ;

var_declaracao: tipo_especificador id PTV {
                    $$ = $1;
                    $2->type = $1->type;
                    addAASNode($$, newAASNodeStmt(KVar));
                    $$->children->line = $2->line;
                    $$->children->type = $1->type;
                    $$->children->name = copyString($2->name);
                    $$->children->escopo = copyString("global");

                }
                | tipo_especificador id ACOL num FCOL PTV {
                    $$ = $1;
                    $2->type = $1->type;
                    addAASNode($$, newAASNodeStmt(KVet));
                    $$->children->line = $2->line;
                    $$->children->type = $1->type;
                    $$->children->name = copyString($2->name);
                    $$->children->escopo = copyString("global");
                    addAASNode($$->children, $2); 
                    addAASNode($$->children, $4);
                }
                ;

tipo_especificador: INT { 
                        $$ = newAASNodeExp(KType); 
                        $$->type = KInt; 
                        }
                    | VOID {
                        $$ = newAASNodeExp(KType);
                        $$->type = KVoid;
                    }
                    ;

fun_declaracao: tipo_especificador id APAR params FPAR composto_decl {
        $$ = $1;
        $2->type = $1->type;
        addAASNode($$, newAASNodeStmt(KFunc));
        $$->children->line = $2->line;
        $$->children->type = $1->type;
        $$->children->name = copyString($2->name);
        printf("Funcao: %s\n", $$->children->name);
        $$->children->escopo = copyString("global");
        updateEscopo($4, $$->children->name);
        updateEscopo($6, $$->children->name);
        addAASNode($$->children, $4);
        addAASNode($$->children, $6);
}
    ;

params: param_lista { $$ = $1; }
    | VOID { $$ = NULL; }
    ;

param_lista: param_lista VIR param { 
        $$ = $1;
        addAASNodeSibling($$, $3);
    }
    | param { $$ = $1; }
    ;

param: tipo_especificador id {
        $$ = $1;
        $2->type = $1->type;
        addAASNode($$, newAASNodeStmt(KVar));
        $$->children->line = $2->line;
        $$->children->type = $1->type;
        $$->children->name = copyString($2->name);

    }
    | tipo_especificador id ACOL FCOL {
        $$ = $1;
        $2->type = $1->type;
        addAASNode($$, newAASNodeStmt(KVet));
        $$->children->line = $2->line;
        $$->children->type = $1->type;
        $$->children->name = copyString($2->name);
    }
    ;

composto_decl: ACHV local_declaracoes statement_lista FCHV {
        if ($2 != NULL) {
            $$ = $2;
            addAASNodeSibling($$, $3);
        } else {
            $$ = $3;
        }
    }
    ;

local_declaracoes: local_declaracoes var_declaracao {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = $1;
            addAASNodeSibling($$, $2);
        }
    }
    | { $$ = NULL; }
    ;

statement_lista: statement_lista statement {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = $1;
            addAASNodeSibling($$, $2);
        }
    }
    | { $$ = NULL; }
    ;

statement: expressao_decl { $$ = $1; }
    | composto_decl { $$ = $1; }
    | selecao_decl { $$ = $1; }
    | iteracao_decl { $$ = $1; }
    | retorno_decl { $$ = $1; }
    ;

expressao_decl: expressao PTV { $$ = $1; }
    | PTV { $$ = NULL; }
    ;

selecao_decl: IF APAR expressao FPAR statement {
        $$ = newAASNodeStmt(KIf);
        addAASNode($$, $3);
        addAASNode($$, $5);
    }
    | IF APAR expressao FPAR statement ELSE statement {
        $$ = newAASNodeStmt(KIf);
        addAASNode($$, $3);
        addAASNode($$, $5);
        addAASNode($$, $7);
    }
    ;

iteracao_decl: WHILE APAR expressao FPAR statement{
        $$ = newAASNodeStmt(KWhile);
        addAASNode($$, $3);
        addAASNode($$, $5);
    }
    ;

retorno_decl: RETURN PTV { 
        $$ = newAASNodeStmt(KReturn);
        $$->type = KVoid;
    }   
    | RETURN expressao PTV {
        $$ = newAASNodeStmt(KReturn);
        addAASNode($$, $2);
    }
    ;


expressao: var ATR expressao {
        $$ = newAASNodeStmt(KAssign);
        $$->type = $1->type;
        addAASNode($$, $1);
        addAASNode($$, $3);
    }
    | simples_expressao {
        $$ = $1;
    }
    ;

var: id { $$ = $1; }
    | id ACOL expressao FCOL {
        $$ = newAASNodeExp(KVetId);
        $$->type = $1->type;
        addAASNode($$, $1);
        addAASNode($$, $3);
    }
    ;

simples_expressao: soma_expressao relacional soma_expressao {
    $$ = $2;
    $$->type = KInt;
    addAASNode($$, $1);
    addAASNode($$, $3);
}
    | soma_expressao {
        $$ = $1;
    }
    ;


relacional: LE { $$ = newAASNodeExp(KOp); $$->token = LE; }
    | LT { $$ = newAASNodeExp(KOp); $$->token = LT; }
    | GT { $$ = newAASNodeExp(KOp); $$->token = GT; }
    | GE { $$ = newAASNodeExp(KOp); $$->token = GE; }
    | COMP { $$ = newAASNodeExp(KOp); $$->token = COMP; }
    | DIF { $$ = newAASNodeExp(KOp); $$->token = DIF; }
    ;

soma_expressao: soma_expressao aditivo termo {
    $$ = $2;
    addAASNode($$, $1);
    addAASNode($$, $3);
}
    | termo {
        $$ = $1;
    }
    ;

aditivo: SOMA { $$ = newAASNodeExp(KOp); $$->token = SOMA; $$->type = KInt; }    
       | SUB { $$ = newAASNodeExp(KOp); $$->token = SUB; $$->type = KInt; }
       ;

termo: termo operador_multiplicativo fator {
    $$ = $2;
    addAASNode($$, $1);
    addAASNode($$, $3);
}
    | fator {
        $$ = $1;
    }
    ;

operador_multiplicativo: MULT { $$ = newAASNodeExp(KOp); $$->token = MULT; $$->type = KInt; }
                       | DIV { $$ = newAASNodeExp(KOp); $$->token = DIV; $$->type = KInt; }
                       ;

fator: APAR expressao FPAR { $$ = $2; }
    | var { $$ = $1; }
    | ativacao { $$ = $1; }
    | num { $$ = $1; }
    ;

ativacao: id APAR args FPAR {
        $$ = newAASNodeStmt(KCall);
        $$->type = $1->type;
        $$->token = lex->token;
        $$->line = lex->line;
        $$->name = copyString($1->name);
        addAASNode($$, $3);
    }
    | id APAR FPAR {
        $$ = newAASNodeStmt(KCall);
        $$->type = $1->type;
        $$->token = lex->token;
        $$->line = lex->line;
        $$->name = copyString($1->name);
    }
    ;

args: arg_lista { $$ = $1; }
    ;

arg_lista: arg_lista VIR expressao {
        if ($1 == NULL) {
            $$ = $3;
        } else {
            $$ = $1;
            addAASNodeSibling($$, $3);
        }
    }
    | expressao {
        $$ = $1;
    }
    ;

id: ID {
        $$ = newAASNodeExp(KId);
        $$->token = lex->token;
        $$->line = lex->line;
        $$->name = copyString(lex->lexema);
    }
    ;

num: NUM {
        $$ = newAASNodeExp(KConst);
        $$->value = atoi(lex->lexema);
        $$->type = KInt;
        $$->line = lex->line;
        $$->token = lex->token;
    }

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
    // printf("\nLexema: %s\nToken: %d\n", lex->lexema, lex->token);
    return token;
}

int main(int argc, char *argv[]) {
    int option = -1;
    
    /*
    yydebug = 1;

    FILE *debug_file = fopen("debug_log.txt", "w");
    if (debug_file == NULL) {
        perror("Failed to open debug log file");
        return EXIT_FAILURE;
    }

    // Redirect stderr to the debug file
    if (dup2(fileno(debug_file), fileno(stderr)) == -1) {
        perror("Failed to redirect stderr");
        fclose(debug_file);
        return EXIT_FAILURE;
    }*/

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    for(int i = 0; i < argc; i++) { // Seleciona opção entre -l, -p e -s
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

    /*Inicialização do buffer*/
    int buffer_size = 20; 
    buffer = allocate_buffer(buffer_size);
    if (buffer == NULL) {
        return 1;
    }

    /*Inicialização do lex*/
    lex = allocate_lex();
    int token;
    char *token_name;
    
    if (option == 0) { // Análise léxica
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
    } else if (option == 1) { // Análise sintática
        yyparse();
        printAAS(root, 0);
    } else if (option == 2) { // Análise semântica
        yyparse();
        if (root == NULL) {
            printf("Erro na análise sintática\n");
            return 1;
        }
        else {
            buildTabSimb(simbTable, root);
        }
    }

    fclose(fp);
    deallocate_buffer(buffer);
    deallocate_lex(lex);
    deallocateAAS(root);

    // fclose(debug_file);
    return 0;
}