#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include "funcs.h"
#include <stdio.h>

typedef struct QuadNode QuadNode;

QuadNode* generateIntermediateCodeWithList(AASNode *root, FILE *out);
void generateIntermediateCode(AASNode *root, FILE *out);

#endif // INTERMEDIATE_H
