#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include "funcs.h"

#define MAX_CODE 1024
#define MAX_STR 64

// Quadruple structure for intermediate code
typedef struct {
    char op[MAX_STR];
    char arg1[MAX_STR];
    char arg2[MAX_STR];
    char result[MAX_STR];
} Quadruple;

extern Quadruple code[MAX_CODE];
extern int code_index;

void emit(const char *op, const char *arg1, const char *arg2, const char *result);
void print_intermediate_code();
void generate_intermediate(AASNode *node);

#endif // INTERMEDIATE_H
