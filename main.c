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
    
    get_next_lexema(lex, buffer, fp);
    printf("%s\n", lex->item);
    return 0;
}