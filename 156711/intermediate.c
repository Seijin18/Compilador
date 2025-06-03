#include "intermediate.h"
#include <stdio.h>
#include <string.h>

Quadruple code[MAX_CODE];
int code_index = 0;

// Emit a new quadruple (intermediate code instruction)
void emit(const char *op, const char *arg1, const char *arg2, const char *result) {
    if (code_index >= MAX_CODE) return;
    strncpy(code[code_index].op, op, MAX_STR - 1);
    strncpy(code[code_index].arg1, arg1, MAX_STR - 1);
    strncpy(code[code_index].arg2, arg2, MAX_STR - 1);
    strncpy(code[code_index].result, result, MAX_STR - 1);
    code[code_index].op[MAX_STR-1] = '\0';
    code[code_index].arg1[MAX_STR-1] = '\0';
    code[code_index].arg2[MAX_STR-1] = '\0';
    code[code_index].result[MAX_STR-1] = '\0';
    code_index++;
}

// Print all generated intermediate code
void print_intermediate_code() {
    printf("Intermediate Code (Quadruples):\n");
    for (int i = 0; i < code_index; i++) {
        printf("%3d: (%s, %s, %s, %s)\n", i, code[i].op, code[i].arg1, code[i].arg2, code[i].result);
    }
}
