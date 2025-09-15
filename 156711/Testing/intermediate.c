#include "intermediate.h"
#include "funcs.h"
#include "bison.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QuadNode {
    char op[16];
    char arg1[32];
    char arg2[32];
    char result[32];
    struct QuadNode* next;
} QuadNode;

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

// Function to check if a node ends with a return statement
static int endsWithReturn(AASNode* node) {
    if (!node) return 0;
    
    // Check if this node is a return statement
    if (node->node == KStmt && node->stmt == KReturn) return 1;
    
    return 0;
}

// Function to check if a node is a comparison operation
static int isComparisonOp(AASNode* node) {
    if (!node || node->node != KExp || node->exp != KOp) return 0;
    
    switch (node->token) {
        case LT:     // <
        case LE:     // <=
        case GT:     // >
        case GE:     // >=
        case COMP:   // ==
        case DIF:    // !=
            return 1;
        default:
            return 0;
    }
}

// Function to get comparison operation string for direct branching
static const char* getComparisonBranch(int token, int negate) {
    if (negate) {
        // For if_f (branch when false), we need the opposite condition
        switch (token) {
            case LT: return "bge";    // branch if >=
            case LE: return "bgt";    // branch if >
            case GT: return "ble";    // branch if <=
            case GE: return "blt";    // branch if <
            case COMP: return "bne";  // branch if !=
            case DIF: return "beq";   // branch if ==
            default: return NULL;
        }
    } else {
        // For if_t (branch when true), direct condition
        switch (token) {
            case LT: return "blt";    // branch if <
            case LE: return "ble";    // branch if <=
            case GT: return "bgt";    // branch if >
            case GE: return "bge";    // branch if >=
            case COMP: return "beq";  // branch if ==
            case DIF: return "bne";   // branch if !=
            default: return NULL;
        }
    }
}

static FILE* quadOut = NULL;

static QuadNode* quadListHead = NULL;
static QuadNode* quadListTail = NULL;

static void emitQuad(const char* op, const char* arg1, const char* arg2, const char* result) {
    // Store in dynamic linked list
    QuadNode* node = (QuadNode*)malloc(sizeof(QuadNode));
    strncpy(node->op, op ? op : " ", 15);
    node->op[15] = '\0';
    strncpy(node->arg1, arg1 ? arg1 : " ", 31);
    node->arg1[31] = '\0';
    strncpy(node->arg2, arg2 ? arg2 : " ", 31);
    node->arg2[31] = '\0';
    strncpy(node->result, result ? result : " ", 31);
    node->result[31] = '\0';
    node->next = NULL;
    if (!quadListHead) {
        quadListHead = node;
        quadListTail = node;
    } else {
        quadListTail->next = node;
        quadListTail = node;
    }
    // Print as before
    if (quadOut) {
        fprintf(quadOut, "(%s,%s,%s,%s)\n", op, arg1 ? arg1 : " ", arg2 ? arg2 : " ", result ? result : " ");
    }
}

// Function to reset and return the head of the quad list
QuadNode* generateIntermediateCodeWithList(AASNode* root, FILE* out) {
    tempCount = 0;
    labelCount = 0;
    quadListHead = NULL;
    quadListTail = NULL;
    quadOut = out;
    if (!root) return NULL;
    // Emit initial goto main
    emitQuad("goto", "main", " ", " ");
    AASNode* node = root->children;
    while (node) {
        genNode(node, out);
        node = node->sibling;
    }
    quadOut = NULL;
    return quadListHead;
}

void generateIntermediateCode(AASNode* root, FILE* out) {
    tempCount = 0;
    labelCount = 0;
    quadOut = out;
    if (!root) return;
    // Emit initial goto main
    emitQuad("goto", "main", " ", " ");
    AASNode* node = root->children;
    while (node) {
        genNode(node, out);
        node = node->sibling;
    }
    quadOut = NULL;
}

static char* genNode(AASNode* node, FILE* out) {
    if (!node) return NULL;
    switch (node->node) {
        case KStmt:
            switch (node->stmt) {
                case KFunc: {
                    // Function declaration: (fun, name, , )
                    emitQuad("fun", node->name, " ", " ");
                    // Emit all parameter (arg,...) quads before allocs/body
                    AASNode* child = node->children;
                    AASNode* bodyStart = NULL;
                    while (child) {
                        if (child->node == KStmt && (child->stmt == KVar || child->stmt == KVet)) {
                            emitQuad("arg", child->name, " ", " ");
                        } else {
                            // First non-param child is the start of the body
                            if (!bodyStart) bodyStart = child;
                        }
                        child = child->sibling;
                    }
                    // Now process the function body (all non-param children)
                    child = bodyStart;
                    while (child) {
                        genNode(child, out);
                        child = child->sibling;
                    }
                    emitQuad("endfun", " ", " ", " ");
                    return NULL;
                }
                case KProg: {
                    // Traverse children (functions, globals)
                    AASNode* child = node->children;
                    while (child) {
                        genNode(child, out);
                        child = child->sibling;
                    }
                    return NULL;
                }
                case KAssign: {
                    char* rhs = genNode(node->children->sibling, out);
                    AASNode* lhsNode = node->children;
                    
                    // Check if LHS is array access (KVetId)
                    if (lhsNode->node == KExp && lhsNode->exp == KVetId) {
                        // Array assignment: array[index] = value
                        char* arrayName = lhsNode->children->name;
                        char* idx = genNode(lhsNode->children->sibling, out);
                        emitQuad("store", arrayName, idx, rhs);
                    } else {
                        // Simple variable assignment
                        char* lhs = lhsNode->name;
                        emitQuad("asn", rhs, " ", lhs);
                    }
                    return NULL;
                }
                case KIf: {
                    AASNode* condNode = node->children;
                    char* labelElse = newLabel();
                    char* labelEnd = newLabel();
                    
                    // Check if condition is a direct comparison
                    if (isComparisonOp(condNode)) {
                        // Generate direct branch instruction
                        char* left = genNode(condNode->children, out);
                        char* right = genNode(condNode->children->sibling, out);
                        const char* branchOp = getComparisonBranch(condNode->token, 1); // negate=1 for if_f
                        
                        if (branchOp) {
                            emitQuad(branchOp, left, right, labelElse);
                        } else {
                            // Fallback to original method
                            char* cond = genNode(condNode, out);
                            emitQuad("if_f", cond, labelElse, " ");
                        }
                    } else {
                        // Original method for non-comparison conditions
                        char* cond = genNode(condNode, out);
                        emitQuad("if_f", cond, labelElse, " ");
                    }
                    
                    // Generate the 'then' block
                    AASNode* thenBlock = node->children->sibling;
                    genNode(thenBlock, out);
                    
                    // Only generate goto if the 'then' block doesn't end with return
                    if (!endsWithReturn(thenBlock)) {
                        emitQuad("goto", labelEnd, " ", " ");
                    }
                    
                    emitQuad("label", labelElse, " ", " ");
                    if (node->children->sibling->sibling)
                        genNode(node->children->sibling->sibling, out); // else
                    emitQuad("label", labelEnd, " ", " ");
                    return NULL;
                }
                case KWhile: {
                    char* labelStart = newLabel();
                    char* labelEnd = newLabel();
                    emitQuad("label", labelStart, " ", " ");
                    char* cond = genNode(node->children, out);
                    emitQuad("if_f", cond, labelEnd, " ");
                    genNode(node->children->sibling, out);
                    emitQuad("goto", labelStart, " ", " ");
                    emitQuad("label", labelEnd, " ", " ");
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
                        emitQuad("param", args[i], " ", " ");
                    char* temp = newTemp();
                    emitQuad("call", node->name, argCount == 0 ? "0" : args[0], temp); // argCount in arg2 if needed
                    return temp;
                }
                case KInput: {
                    char* temp = newTemp();
                    emitQuad("input", " ", " ", temp);
                    return temp;
                }
                case KOutput: {
                    char* val = genNode(node->children, out);
                    emitQuad("output", val, "0", " ");
                    return NULL;
                }
                case KReturn: {
                    if (node->children)
                        emitQuad("ret", genNode(node->children, out), " ", " ");
                    else
                        emitQuad("ret", " ", " ", " ");
                    return NULL;
                }
                case KVar: {
                    // Variable declaration: (alloc, name, 1, )
                    emitQuad("alloc", node->name, "1", " ");
                    return NULL;
                }
                case KVet: {
                    // Array declaration: (alloc, name, size, )
                    char size[16];
                    if (node->children && node->children->sibling) {
                        // Array with explicit size: int arr[5]
                        sprintf(size, "%d", node->children->sibling->value);
                    } else {
                        // Default size for arrays without explicit size
                        sprintf(size, "10");
                    }
                    emitQuad("alloc", node->name, size, " ");
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
                    char op[8];
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
                    emitQuad(op, left, right, temp);
                    return temp;
                }
                case KConst: {
                    char* temp = newTemp();
                    char val[16];
                    sprintf(val, "%d", node->value);
                    emitQuad("immed", val, " ", temp);
                    return temp;
                }
                case KId: {
                    return node->name;
                }
                case KVarId: {
                    return node->name;
                }
                case KVetId: {
                    char* idx = genNode(node->children->sibling, out);
                    char* temp = newTemp();
                    emitQuad("load", node->children->name, idx, temp);
                    return temp;
                }
                default: {
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

void printQuadList(QuadNode* head, FILE* out) {
    QuadNode* curr = head;
    while (curr) {
        fprintf(out, "(%s,%s,%s,%s)\n", curr->op, curr->arg1, curr->arg2, curr->result);
        curr = curr->next;
    }
}
