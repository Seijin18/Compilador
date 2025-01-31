#include "funcs.h"
#include "bison.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AC -9
#define ER -10

char simbolos[] = {'+', '-', '*', '/', '<', '>', '=', '!', ';', ',', '(', ')', '[', ']', '{', '}'}; // Define the variable


// Flag
int read_next = 1;

char *get_token_name(int token)
{
    switch (token)
    {
    case ID:
        return "ID";
    case NUM:
        return "NUM";
    case ELSE:
        return "ELSE";
    case IF:
        return "IF";
    case INT:
        return "INT";
    case RETURN:
        return "RETURN";
    case VOID:
        return "VOID";
    case WHILE:
        return "WHILE";
    case SOMA:
        return "SOMA";
    case SUB:
        return "SUB";
    case MULT:
        return "MULT";
    case DIV:
        return "DIV";
    case ATR:
        return "ATR";
    case COMP:
        return "COMP";
    case DIF:
        return "DIF";
    case GT:
        return "GT";
    case LT:
        return "LT";
    case GE:
        return "GE";
    case LE:
        return "LE";
    case PTV:
        return "PTV";
    case VIR:
        return "VIR";
    case APAR:
        return "APAR";
    case FPAR:
        return "FPAR";
    case ACOL:
        return "ACOL";
    case FCOL:
        return "FCOL";
    case ACHV:
        return "ACHV";
    case FCHV:
        return "FCHV";
    case CMT:
        return "CMT";
    case EOF:
        return "EOF";
    default:
        return "ERRO";
    }
}


// Letra: 0
// Digito: 1
// White space: 2
// Simbolo: 3 - 18


// DFA
int dfa[27][19] = {
    { 2, 1, 0, 3, 4, 5, 6,12,11, 7, 9,15,16,17,18,19,20,21,22}, // 0
    {ER, 1,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 1
    { 2,ER,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 2
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 3
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 4
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 5
    {AC,AC,AC,AC,AC,23,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 6
    {AC,AC,AC,AC,AC,AC,AC,AC,AC, 8,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 7
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 8
    {ER,ER,ER,ER,ER,ER,ER,ER,ER,10,ER,ER,ER,ER,ER,ER,ER,ER,ER}, // 9
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 10
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,13,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 11
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,14,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 12
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 13
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 14
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 15
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 16
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 17
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 18
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 19
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 20
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 21
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC}, // 22
    {23,23,23,23,23,25,24,23,23,23,23,23,23,23,23,23,23,23,23}, // 23
    {23,23,23,23,23,ER,23,23,23,23,23,23,23,23,23,23,23,23,23}, // 24
    {23,23,23,23,23,23,26,23,23,23,23,23,23,23,23,23,23,23,23}, // 25
    {AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC,AC} // 26
};

Bloco *allocate_buffer(int size) {
    Bloco *buffer = malloc(sizeof(Bloco));
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return NULL;
    }

    buffer->buffer = malloc(sizeof(char) * size);
    if (buffer->buffer == NULL) {
        printf("Error allocating memory\n");
        free(buffer);
        return NULL;
    }

    buffer->buffer[0] = '\0';
    buffer->char_pos = 0;
    buffer->line = 0;
    buffer->size = size;

    return buffer;
}

void deallocate_buffer(Bloco *buffer) {
    free(buffer->buffer);
    free(buffer);
}

char get_next_char(Bloco *buffer, FILE *file) {
    char c;
    c = buffer->buffer[buffer->char_pos];
    buffer->column += 1;
    if (c == '\0') {
        load_buffer(buffer, file);
        c = buffer->buffer[buffer->char_pos];
    }
    if(c == '\n') {
        buffer->column = 0;
        buffer->line++;
    }

    buffer->char_pos++;
    return c;
}

void load_buffer(Bloco *buffer, FILE *file) {
    char c;
    buffer->char_pos = 0;
    do{
        c = fgetc(file);
        buffer->buffer[buffer->char_pos] = c;
        buffer->char_pos++;
    } while (c != EOF && c != '\n' && buffer->char_pos < buffer->size - 2);

    if(c == EOF && buffer->char_pos < buffer->size - 2) {
        buffer->buffer[buffer->char_pos] = EOF;
    }
    else{
        buffer->buffer[buffer->char_pos] = '\0';
    }
    
    buffer->char_pos = 0;
}

void replace_print(Bloco *buffer, int size) {
    for (int i = 0; i < size; i++) {
        if ('A'<=buffer->buffer[i] && buffer->buffer[i]<='Z') {
            buffer->buffer[i] = buffer->buffer[i] + 32;
        } else if ('a'<=buffer->buffer[i] && buffer->buffer[i]<='z') {
            buffer->buffer[i] = buffer->buffer[i] - 32;
        }
    }

    printf("%s\n", buffer->buffer);
}

int is_symbol(char c) {
    for (int i = 0; i < 16; i++) {
        if (c == simbolos[i]) {
            return i + 3;
        }
    }
    return 0;
}

int is_char(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        return 1;
    }
    return 0;
}

int is_digit(char c) {
    if ('0' <= c && c <= '9') {
        return 1;
    }
    return 0;
}

int is_space(char c) {
    if (c == ' ' || c == '\n' || c == '\t' || c == '\0' || c == '\r' || c == '\v' || c == '\f' || c == '\b' || c == EOF)
    {
        return 1;
    }
    return 0;
}

Lex *allocate_lex() {
    Lex *lex = malloc(sizeof(Lex));
    if (lex == NULL) {
        printf("Error allocating memory\n");
        return NULL;
    }

    lex->lexema = malloc(sizeof(char) * 64);
    if (lex->lexema == NULL) {
        printf("Error allocating memory\n");
        free(lex);
        return NULL;
    }

    lex->token = 0;
    lex->line = 0;
    lex->column = 0;

    return lex;
}

void deallocate_lex(Lex *lex) {
    free(lex->lexema);
    free(lex);
}

void clear_lex(Lex *lex) {
    for (int i = 0; i < 64; i++) {
        lex->lexema[i] = '\0';
    }
    lex->token = 0;
    lex->line = 0;
}

int check_token(int table_state) {
    switch (table_state) {
        case 1:
            return NUM;
        case 2:
            return ID;
        case 3:
            return SOMA;
        case 4:
            return SUB;
        case 5:
            return MULT;
        case 6:
            return DIV;
        case 7:
            return ATR;
        case 8:
            return COMP;
        case 10:
            return DIF;
        case 11:
            return GT;
        case 12:
            return LT;
        case 13:
            return GE;
        case 14:
            return LE;
        case 15:
            return PTV;
        case 16:
            return VIR;
        case 17:
            return APAR;
        case 18:
            return FPAR;
        case 19:
            return ACOL;
        case 20:
            return FCOL;
        case 21:
            return ACHV;
        case 22:
            return FCHV;
        case 26:
            return CMT;
        default:
            return -1;
    }
}

int check_keyword(char *lexema) {
    if (strcmp(lexema, "else") == 0) {
        return ELSE;
    }
    else if (strcmp(lexema, "if") == 0) {
        return IF;
    }
    else if (strcmp(lexema, "int") == 0) {
        return INT;
    }
    else if (strcmp(lexema, "return") == 0) {
        return RETURN;
    }
    else if (strcmp(lexema, "void") == 0) {
        return VOID;
    }
    else if (strcmp(lexema, "while") == 0) {
        return WHILE;
    }
    return ID;
}

int get_terminal(char c) {
    if (is_char(c)) {
        return 0;
    }
    else if (is_digit(c)) {
        return 1;
    }
    else if (is_space(c)) {
        return 2;
    }
    else if (is_symbol(c)) {
        return is_symbol(c);
    }
    return ER;
}

int get_token(Lex *lex, Bloco *buffer, FILE *file)
{
    int state = 0;
    int table_state = 0;
    int i = 0;
    char c;

    while(state != ER) {
        if (c == EOF && !read_next) {
            return EOF;
        }
        if (read_next) {
            c = get_next_char(buffer, file);
            if (c == EOF) {
                read_next = 0;
                table_state = dfa[state][2];
                if (table_state == ER) {
                    return ER;
                }
                else if (table_state == AC) {
                    return check_token(state);
                }
                return ER;
            }
        }
        read_next = 1;
        table_state = dfa[state][get_terminal(c)];
        if (table_state == ER) {
            return ER;
        }
        else if (table_state == AC) {
            read_next = 0;
            lex->lexema[i] = '\0';
            return check_token(state);
        }
        if(!is_space(c))
        {
            lex->lexema[i] = c;
            i++;
        }
        state = table_state;
    }
    return ER;
}

int get_lexema(Bloco *buffer, Lex *lex, FILE *file) {
    int i = 0;
    clear_lex(lex);
    if (buffer->buffer[buffer->char_pos] == '\0') {
        load_buffer(buffer, file);
    }

    lex->token = get_token(lex, buffer, file);
    lex->line = buffer->line;
    lex->column = buffer->column - 1;

    if(lex->token == ID) {
        lex->token = check_keyword(lex->lexema);
    }

    if(lex->token == ER) {
        return ER;
    }
    if(lex->token == EOF) {
        return EOF;
    }
    
    // printf("Lex: %s\n", lex->lexema);
    // printf("Token: %d\n", lex->token);
    // printf("Line: %d\n", lex->line + 1);
    // printf("Column: %d\n\n", lex->column);
    return lex->token;
}

AASNode *newAASNode(StmtKind kstmt, ExpKind kexp) {
    AASNode *node = malloc(sizeof(AASNode));
    if (node == NULL) {
        printf("Error allocating memory\n");
        return NULL;
    }

    node->children = NULL;
    node->sibling = NULL;
    node->token = 0;
    node->value = 0;
    node->name = NULL;
    node->line = 0;
    node->node = KStmt;
    node->stmt = kstmt;
    node->exp = kexp;
    node->type = KInt;

    return node;
}

AASNode *addAASNode(AASNode *node, AASNode *child) {
    if (node->children == NULL) {
        node->children = child;
    }
    else {
        AASNode *temp = node->children;
        while (temp->sibling != NULL) {
            temp = temp->sibling;
        }
        temp->sibling = child;
    }
    return node;
}

void printAAS(AASNode *node, int depth) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("-");
    }

    switch (node->node){
        case KStmt:
            printf("Stmt: ");
            switch (node->stmt) {
                case KIf:
                    printf("If\n");
                    break;
                case KWhile:
                    printf("While\n");
                    break;
                case KAssign:
                    printf("Assign\n");
                    break;
                case KReturn:
                    printf("Return\n");
                    break;
                case KCall:
                    printf("Call\n");
                    break;
                case KVar:
                    printf("Var\n");
                    break;
                case Kvet:
                    printf("Vet\n");
                    break;
                case KFunc:
                    printf("Func\n");
                    break;
            }
            break;
        case KExp:
            printf("Exp: ");
            switch (node->exp) {
                case KOp:
                    printf("Op\n");
                    break;
                case KConst:
                    printf("Const\n");
                    break;
                case KId:
                    printf("Id: %s\n", node->name);
                    break;
                case KType:
                    printf("Type\n");
                    break;
                case KVarId:
                    printf("VarId\n");
                    break;
                case KVetID:
                    printf("VetId\n");
                    break;
            }
            break;
    }

    AASNode *child = node->children;
    while (child != NULL) {
        printAAS(child, depth + 1);
        child = child->sibling;
    }
}

void deallocateAAS(AASNode *node) {
    if (node == NULL) {
        return;
    }

    AASNode *child = node->children;
    while (child != NULL) {
        AASNode *temp = child;
        child = child->sibling;
        deallocateAAS(temp);
    }

    free(node);
}