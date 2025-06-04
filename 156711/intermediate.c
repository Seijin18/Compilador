#include "intermediate.h"
#include "funcs.h"
#include "bison.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int tempCount = 0;
static int labelCount = 0;

static char* newTemp() {
    char* temp = (char*)malloc(16);
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

static char* newLabel() {
    char* label = (char*)malloc(16);
    sprintf(label, "L%d", labelCount++);
    return label;
}

// Forward declaration
static char* genNode(AASNode* node, FILE* out);

void generateIntermediateCode(AASNode* root, FILE* out) {
    tempCount = 0;
    labelCount = 0;
    if (!root) return;
    AASNode* node = root->children;
    while (node) {
        genNode(node, out);
        node = node->sibling;
    }
}

static char* genNode(AASNode* node, FILE* out) {
    if (!node) return NULL;
    switch (node->node) {
        case KStmt:
            switch (node->stmt) {
                case KAssign: {
                    char* rhs = genNode(node->children->sibling, out);
                    char* lhs = node->children->name;
                    fprintf(out, "%s = %s\n", lhs, rhs);
                    return lhs;
                }
                case KIf: {
                    char* cond = genNode(node->children, out);
                    char* labelElse = newLabel();
                    char* labelEnd = newLabel();
                    fprintf(out, "ifFalse %s goto %s\n", cond, labelElse);
                    genNode(node->children->sibling, out); // then
                    fprintf(out, "goto %s\n", labelEnd);
                    fprintf(out, "%s:\n", labelElse);
                    if (node->children->sibling->sibling)
                        genNode(node->children->sibling->sibling, out); // else
                    fprintf(out, "%s:\n", labelEnd);
                    return NULL;
                }
                case KWhile: {
                    char* labelStart = newLabel();
                    char* labelEnd = newLabel();
                    fprintf(out, "%s:\n", labelStart);
                    char* cond = genNode(node->children, out);
                    fprintf(out, "ifFalse %s goto %s\n", cond, labelEnd);
                    genNode(node->children->sibling, out);
                    fprintf(out, "goto %s\n", labelStart);
                    fprintf(out, "%s:\n", labelEnd);
                    return NULL;
                }
                case KCall: {
                    // Arguments
                    AASNode* arg = node->children;
                    int argCount = 0;
                    char* args[16];
                    while (arg) {
                        args[argCount++] = genNode(arg, out);
                        arg = arg->sibling;
                    }
                    for (int i = 0; i < argCount; i++)
                        fprintf(out, "param %s\n", args[i]);
                    char* temp = newTemp();
                    fprintf(out, "%s = call %s, %d\n", temp, node->name, argCount);
                    return temp;
                }
                case KInput: {
                    char* temp = newTemp();
                    fprintf(out, "%s = input\n", temp);
                    return temp;
                }
                case KOutput: {
                    char* val = genNode(node->children, out);
                    fprintf(out, "output %s\n", val);
                    return NULL;
                }
                case KReturn: {
                    if (node->children)
                        fprintf(out, "return %s\n", genNode(node->children, out));
                    else
                        fprintf(out, "return\n");
                    return NULL;
                }
                case KVar:
                case KVet:
                case KFunc:
                case KProg: {
                    // Declarations, skip or traverse children
                    AASNode* child = node->children;
                    while (child) {
                        genNode(child, out);
                        child = child->sibling;
                    }
                    return NULL;
                }
                default: {
                    // For any other node, traverse children
                    AASNode* child = node->children;
                    while (child) {
                        genNode(child, out);
                        child = child->sibling;
                    }
                    return NULL;
                }
            }
            break;
        case KExp:
            switch (node->exp) {
                case KOp: {
                    char* left = genNode(node->children, out);
                    char* right = genNode(node->children->sibling, out);
                    char* temp = newTemp();
                    char op[4];
                    switch (node->token) {
                        case SOMA: strcpy(op, "+"); break;
                        case SUB: strcpy(op, "-"); break;
                        case MULT: strcpy(op, "*"); break;
                        case DIV: strcpy(op, "/"); break;
                        case LT: strcpy(op, "<"); break;
                        case LE: strcpy(op, "<="); break;
                        case GT: strcpy(op, ">"); break;
                        case GE: strcpy(op, ">="); break;
                        case COMP: strcpy(op, "=="); break;
                        case DIF: strcpy(op, "!="); break;
                        default: strcpy(op, "?"); break;
                    }
                    fprintf(out, "%s = %s %s %s\n", temp, left, op, right);
                    return temp;
                }
                case KConst: {
                    char* temp = newTemp();
                    fprintf(out, "%s = %d\n", temp, node->value);
                    return temp;
                }
                case KId: {
                    return node->name;
                }
                case KVarId: {
                    // Variable access
                    return node->name;
                }
                case KVetId: {
                    // Array access: a[i]
                    char* idx = genNode(node->children->sibling, out);
                    char* temp = newTemp();
                    fprintf(out, "%s = %s[%s]\n", temp, node->children->name, idx);
                    return temp;
                }
                default: {
                    // For any other node, traverse children
                    AASNode* child = node->children;
                    while (child) {
                        genNode(child, out);
                        child = child->sibling;
                    }
                    return NULL;
                }
            }
            break;
        default:
            // For any other node, traverse children
            {
                AASNode* child = node->children;
                while (child) {
                    genNode(child, out);
                    child = child->sibling;
                }
                return NULL;
            }
    }
    return NULL;
}
