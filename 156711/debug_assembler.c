#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_intermediario>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Erro: Não foi possível abrir o arquivo %s\n", argv[1]);
        return 1;
    }
    
    char line[MAX_LINE_LENGTH];
    int total_lines = 0;
    int quad_lines = 0;
    
    printf("=== Debug do Arquivo ===\n");
    
    while (fgets(line, sizeof(line), file)) {
        total_lines++;
        // Remover quebra de linha
        line[strcspn(line, "\n")] = 0;
        
        printf("Linha %d: '%s' (len=%zu)", total_lines, line, strlen(line));
        
        // Pular linhas vazias ou comentários
        if (strlen(line) == 0 || line[0] == '#') {
            printf(" -> VAZIA/COMENTÁRIO\n");
            continue;
        }
        
        // Verificar se é uma quadrupla válida
        if (line[0] == '(' && line[strlen(line)-1] == ')') {
            quad_lines++;
            printf(" -> QUADRUPLA %d\n", quad_lines);
        } else {
            printf(" -> NÃO É QUADRUPLA\n");
        }
    }
    
    fclose(file);
    
    printf("\n=== Resumo ===\n");
    printf("Total de linhas: %d\n", total_lines);
    printf("Quadruplas encontradas: %d\n", quad_lines);
    
    return 0;
}
