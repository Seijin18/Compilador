#include "intermediate.h"
#include "funcs.h"
#include "bison.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern AASNode* root;

int main() {
    FILE* fp = fopen("gcd.c", "r");
    if (!fp) {
        printf("Erro ao abrir gcd.c\n");
        return 1;
    }
    
    printf("Iniciando parse...\n");
    // Simular o processo de parsing
    // Aqui você precisaria inicializar o lexer e parser
    
    if (root) {
        printf("Root existe, tentando gerar código intermediário...\n");
        FILE* fout = fopen("debug_intermediate.txt", "w");
        if (fout) {
            generateIntermediateCode(root, fout);
            fclose(fout);
            printf("Código intermediário gerado com sucesso!\n");
        } else {
            printf("Erro ao criar arquivo de saída\n");
        }
    } else {
        printf("Root é NULL!\n");
    }
    
    return 0;
}
