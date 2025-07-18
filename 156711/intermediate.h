#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include "funcs.h"
#include <stdio.h>

typedef struct QuadNode {
    char op[16];
    char arg1[32];
    char arg2[32];
    char result[32];
    struct QuadNode* next;
} QuadNode;

QuadNode* generateIntermediateCodeWithList(AASNode *root, FILE *out);
void generateIntermediateCode(AASNode *root, FILE *out);
void printQuadList(QuadNode* head, FILE* out);

#endif // INTERMEDIATE_H
