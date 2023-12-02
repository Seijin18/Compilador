#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Bloco *buffer;
    allocate_buffer(&buffer);
    Lexema *lex;
    allocate_lexema(&lex);
    FILE *fp;
    fp = fopen("teste.txt", "r");
    char c;
    int tabela[24][19];
    tabela[0][0] = 1;

    get_next_lexema_tabela(lex, buffer, fp);
    printf("%s\n", lex->item);
    return 0;
}
