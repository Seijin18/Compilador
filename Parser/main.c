#include "funcs.h"
#include "bison.tab.h"
#include <stdio.h>
#include <stdlib.h>

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

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int buffer_size = 20;
    Bloco *buffer = allocate_buffer(buffer_size);
    if (buffer == NULL) {
        return 1;
    }

    Lex *lexema = allocate_lex();
    int token;
    char *token_name;
    
    if (option == 0) {
        do{
            token = get_lexema(buffer, lexema, file);
            if(token == ER) {
                // printf("Error getting lexema\n");
                break;
            }
            token_name = get_token_name(token);
            printf("%s\t'%s' \t[linha: %d]\n", token_name, lexema->lexema, lexema->line + 1);
        } while (token != EOF);
    } else if (option == 1) {
        yyparse();
    }

    fclose(file);
    deallocate_buffer(buffer);
    deallocate_lex(lexema);

    return 0;
}