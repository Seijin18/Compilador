#include "intermediate.h"
#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int temp_count = 0;

// Helper to create a new temporary variable name
typedef struct TempResult {
    char name[MAX_STR];
    int is_temp;
} TempResult;

static void new_temp(char *buf) {
    snprintf(buf, MAX_STR, "t%d", temp_count++);
}

// Recursively generate intermediate code for the AST rooted at 'node'.
// Returns the name of the variable/temp holding the result (if any).
static TempResult gen(AASNode *node) {
    TempResult res = {"", 0};
    if (!node) return res;

    switch (node->node) {
    case KExp:
        switch (node->exp) {
        case KConst:
            snprintf(res.name, MAX_STR, "%d", node->value);
            res.is_temp = 0;
            return res;
        case KId:
        case KVarId:
            snprintf(res.name, MAX_STR, "%s", node->name);
            res.is_temp = 0;
            return res;
        case KOp: {
            TempResult left = gen(node->children);
            TempResult right = gen(node->children ? node->children->sibling : NULL);
            char temp[MAX_STR];
            new_temp(temp);
            emit(get_token_name(node->token), left.name, right.name, temp);
            snprintf(res.name, MAX_STR, "%s", temp);
            res.is_temp = 1;
            return res;
        }
        default:
            break;
        }
        break;
    case KStmt:
        switch (node->stmt) {
        case KAssign: {
            TempResult rhs = gen(node->children->sibling);
            TempResult lhs = gen(node->children);
            emit("=", rhs.name, "", lhs.name);
            break;
        }
        case KReturn: {
            TempResult val = gen(node->children);
            emit("return", val.name, "", "");
            break;
        }
        case KIf: {
            TempResult cond = gen(node->children);
            emit("if", cond.name, "", "");
            // Then/else blocks can be handled here (not implemented for brevity)
            break;
        }
        case KWhile: {
            TempResult cond = gen(node->children);
            emit("while", cond.name, "", "");
            // Loop body can be handled here (not implemented for brevity)
            break;
        }
        case KCall: {
            // For function calls, emit call and assign result to temp
            char temp[MAX_STR];
            new_temp(temp);
            emit("call", node->name, "", temp);
            snprintf(res.name, MAX_STR, "%s", temp);
            res.is_temp = 1;
            return res;
        }
        default:
            break;
        }
        break;
    }
    // Recursively process siblings
    if (node->sibling) gen(node->sibling);
    return res;
}

void generate_intermediate(AASNode *node) {
    temp_count = 0;
    gen(node);
}
