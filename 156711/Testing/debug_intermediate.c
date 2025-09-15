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

static QuadNode* quadListHead = NULL;
static QuadNode* quadListTail = NULL;

static void emitQuad(const char* op, const char* arg1, const char* arg2, const char* result) {
    printf("DEBUG QUAD: (%s,%s,%s,%s)\n", op, arg1?arg1:" ", arg2?arg2:" ", result?result:" ");
    
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
        quadListHead = quadListTail = node;
    } else {
        quadListTail->next = node;
        quadListTail = node;
    }
}

// Forward declaration
static char* genNode(AASNode* node, FILE* out);

static char* genNode(AASNode* node, FILE* out) {
    if (!node) return NULL;
    
    switch (node->node) {
        case KStmt:
            switch (node->stmt) {
                case KAssign: {
                    printf("DEBUG: Processing KAssign\n");
                    AASNode* lhsNode = node->children;
                    printf("DEBUG: LHS node->node = %d, node->exp = %d\n", lhsNode->node, lhsNode->exp);
                    printf("DEBUG: KExp = %d, KVetId = %d\n", KExp, KVetId);
                    
                    char* rhs = genNode(node->children->sibling, out);
                    
                    // Check if LHS is array access (KVetId)
                    if (lhsNode->node == KExp && lhsNode->exp == KVetId) {
                        printf("DEBUG: Detected array assignment\n");
                        // Array assignment: array[index] = value
                        char* arrayName = lhsNode->children->name;
                        char* idx = genNode(lhsNode->children->sibling, out);
                        printf("DEBUG: Array=%s, Index=%s, Value=%s\n", arrayName, idx, rhs);
                        emitQuad("store", arrayName, idx, rhs);
                    } else {
                        printf("DEBUG: Detected simple assignment\n");
                        // Simple variable assignment
                        char* lhs = lhsNode->name;
                        emitQuad("asn", rhs, " ", lhs);
                    }
                    return NULL;
                }
                default:
                    return NULL;
            }
            break;
        case KExp:
            switch (node->exp) {
                case KConst: {
                    char* temp = newTemp();
                    char value[32];
                    sprintf(value, "%d", node->value);
                    emitQuad("immed", value, " ", temp);
                    return temp;
                }
                case KVetId: {
                    printf("DEBUG: Processing KVetId for %s\n", node->children->name);
                    char* idx = genNode(node->children->sibling, out);
                    char* temp = newTemp();
                    emitQuad("load", node->children->name, idx, temp);
                    return temp;
                }
                default:
                    return NULL;
            }
            break;
        default:
            return NULL;
    }
    return NULL;
}

void debug_test() {
    printf("Testing debug intermediate code generation...\n");
}