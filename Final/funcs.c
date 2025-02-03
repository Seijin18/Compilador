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

// Char buffer
char c = '\0';

// Semantic Error
char *semantic_error = NULL;

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
    {2, 1, 0, 3, 4, 5, 6, 12, 11, 7, 9, 15, 16, 17, 18, 19, 20, 21, 22},          // 0
    {ER, 1, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC},  // 1
    {2, ER, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC},  // 2
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 3
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 4
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 5
    {AC, AC, AC, AC, AC, 23, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 6
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, 8, AC, AC, AC, AC, AC, AC, AC, AC, AC},  // 7
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 8
    {ER, ER, ER, ER, ER, ER, ER, ER, ER, 10, ER, ER, ER, ER, ER, ER, ER, ER, ER}, // 9
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 10
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, 13, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 11
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, 14, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 12
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 13
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 14
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 15
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 16
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 17
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 18
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 19
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 20
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 21
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}, // 22
    {23, 23, 23, 23, 23, 25, 24, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23}, // 23
    {23, 23, 23, 23, 23, ER, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23}, // 24
    {23, 23, 23, 23, 23, 23, 26, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23}, // 25
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC}  // 26
};

Bloco *allocate_buffer(int size)
{
    Bloco *buffer = malloc(sizeof(Bloco));
    if (buffer == NULL)
    {
        printf("Error allocating memory\n");
        return NULL;
    }

    buffer->buffer = malloc(sizeof(char) * size);
    if (buffer->buffer == NULL)
    {
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

void deallocate_buffer(Bloco *buffer)
{
    free(buffer->buffer);
    free(buffer);
}

char get_next_char(Bloco *buffer, FILE *file)
{
    char ch;
    ch = buffer->buffer[buffer->char_pos];
    buffer->column += 1;
    if (ch == '\0')
    {
        load_buffer(buffer, file);
        ch = buffer->buffer[buffer->char_pos];
    }
    if (ch == '\n')
    {
        buffer->column = 0;
        buffer->line++;
    }

    buffer->char_pos++;
    return ch;
}

void load_buffer(Bloco *buffer, FILE *file)
{
    char ch;
    buffer->char_pos = 0;
    do
    {
        ch = fgetc(file);
        buffer->buffer[buffer->char_pos] = ch;
        buffer->char_pos++;
    } while (c != EOF && ch != '\n' && buffer->char_pos < buffer->size - 2);

    if (ch == EOF && buffer->char_pos < buffer->size - 2)
    {
        buffer->buffer[buffer->char_pos] = EOF;
    }
    else
    {
        buffer->buffer[buffer->char_pos] = '\0';
    }

    buffer->char_pos = 0;
}

void replace_print(Bloco *buffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        if ('A' <= buffer->buffer[i] && buffer->buffer[i] <= 'Z')
        {
            buffer->buffer[i] = buffer->buffer[i] + 32;
        }
        else if ('a' <= buffer->buffer[i] && buffer->buffer[i] <= 'z')
        {
            buffer->buffer[i] = buffer->buffer[i] - 32;
        }
    }

    printf("%s\n", buffer->buffer);
}

int is_symbol(char ch)
{
    for (int i = 0; i < 16; i++)
    {
        if (ch == simbolos[i])
        {
            return i + 3;
        }
    }
    return 0;
}

int is_char(char ch)
{
    if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
    {
        return 1;
    }
    return 0;
}

int is_digit(char ch)
{
    if ('0' <= ch && ch <= '9')
    {
        return 1;
    }
    return 0;
}

int is_space(char ch)
{
    if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\0' || ch == '\r' || ch == '\v' || ch == '\f' || ch == '\b' || ch == EOF)
    {
        return 1;
    }
    return 0;
}

Lex *allocate_lex()
{
    Lex *lex = malloc(sizeof(Lex));
    if (lex == NULL)
    {
        printf("Error allocating memory\n");
        return NULL;
    }

    lex->lexema = malloc(sizeof(char) * 64);
    if (lex->lexema == NULL)
    {
        printf("Error allocating memory\n");
        free(lex);
        return NULL;
    }

    lex->token = 0;
    lex->line = 0;
    lex->column = 0;

    return lex;
}

void deallocate_lex(Lex *lex)
{
    free(lex->lexema);
    free(lex);
}

void clear_lex(Lex *lex)
{
    for (int i = 0; i < 64; i++)
    {
        lex->lexema[i] = '\0';
    }
    lex->token = 0;
    lex->line = 0;
}

int check_token(int table_state)
{
    switch (table_state)
    {
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

int check_keyword(char *lexema)
{
    if (strcmp(lexema, "else") == 0)
    {
        return ELSE;
    }
    else if (strcmp(lexema, "if") == 0)
    {
        return IF;
    }
    else if (strcmp(lexema, "int") == 0)
    {
        return INT;
    }
    else if (strcmp(lexema, "return") == 0)
    {
        return RETURN;
    }
    else if (strcmp(lexema, "void") == 0)
    {
        return VOID;
    }
    else if (strcmp(lexema, "while") == 0)
    {
        return WHILE;
    }
    return ID;
}

int get_terminal(char ch)
{
    if (is_char(ch))
    {
        return 0;
    }
    else if (is_digit(ch))
    {
        return 1;
    }
    else if (is_space(ch))
    {
        return 2;
    }
    else if (is_symbol(ch))
    {
        return is_symbol(ch);
    }
    return ER;
}

int get_token(Lex *lex, Bloco *buffer, FILE *file)
{
    int state = 0;
    int table_state = 0;
    int i = 0;

    while (state != ER)
    {
        if (c == EOF && !read_next)
        {
            return EOF;
        }
        if (read_next)
        {
            c = get_next_char(buffer, file);
            if (c == EOF)
            {
                read_next = 0;
                table_state = dfa[state][2];
                if (table_state == ER)
                {
                    return ER;
                }
                else if (table_state == AC)
                {
                    return check_token(state);
                }
                return ER;
            }
        }
        read_next = 1;
        table_state = dfa[state][get_terminal(c)];
        if (table_state == ER)
        {
            return ER;
        }
        else if (table_state == AC)
        {
            read_next = 0;
            lex->lexema[i] = '\0';
            return check_token(state);
        }
        if (!is_space(c))
        {
            lex->lexema[i] = c;
            i++;
        }
        state = table_state;
    }
    return ER;
}

int get_lexema(Bloco *buffer, Lex *lex, FILE *file)
{
    int i = 0;
    clear_lex(lex);
    if (buffer->buffer[buffer->char_pos] == '\0')
    {
        load_buffer(buffer, file);
    }

    lex->token = get_token(lex, buffer, file);
    lex->line = buffer->line;
    lex->column = buffer->column - 1;

    if (lex->token == ID)
    {
        lex->token = check_keyword(lex->lexema);
    }

    if (lex->token == ER)
    {
        return ER;
    }
    if (lex->token == EOF)
    {
        return EOF;
    }

    // printf("Lex: %s\n", lex->lexema);
    // printf("Token: %d\n", lex->token);
    // printf("Line: %d\n", lex->line + 1);
    // printf("Column: %d\n\n", lex->column);
    return lex->token;
}

AASNode *newAASNode(StmtKind kstmt, ExpKind kexp)
{
    AASNode *node = calloc(1, sizeof(AASNode));
    if (node == NULL)
    {
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

AASNode *newAASNodeExp(ExpKind kexp)
{
    AASNode *node = calloc(1, sizeof(AASNode));
    if (node == NULL)
    {
        printf("Error allocating memory\n");
        return NULL;
    }

    node->children = NULL;
    node->sibling = NULL;
    node->token = 0;
    node->value = 0;
    node->name = NULL;
    node->line = 0;
    node->node = KExp;
    node->stmt = -1;
    node->exp = kexp;
    node->type = KInt;

    return node;
}

AASNode *newAASNodeStmt(StmtKind kstmt)
{
    AASNode *node = calloc(1, sizeof(AASNode));
    if (node == NULL)
    {
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
    node->exp = -1;
    node->type = KInt;

    return node;
}

AASNode *addAASNode(AASNode *node, AASNode *child)
{
    if (node->children == NULL)
    {
        node->children = child;
    }
    else
    {
        AASNode *temp = node->children;
        while (temp->sibling != NULL)
        {
            temp = temp->sibling;
        }
        temp->sibling = child;
    }
    return node;
}

AASNode *addAASNodeSibling(AASNode *node, AASNode *sibling)
{
    AASNode *temp = node;
    while (temp->sibling != NULL)
    {
        temp = temp->sibling;
    }
    temp->sibling = sibling;
    return node;
}

void updateEscopo(AASNode *node, char *escopo)
{
    if (node == NULL)
    {
        return;
    }

    while (node != NULL)
    {
        node->escopo = copyString(escopo);
        // printf("Name: %s, Escopo: %s\n", node->name, node->escopo);
        if (node->children != NULL)
        {
            updateEscopo(node->children, escopo);
        }
        node = node->sibling;
    }

    // AASNode *child = node->children;
    // while (child != NULL) {
    //     node->escopo = escopo;
    //     printf("Name: %s, Escopo: %s\n", node->name, node->escopo);
    //     updateEscopo(child, escopo);
    //     child = child->sibling;
    // }
}

void printAAS(AASNode *node, int depth)
{
    if (node == NULL)
    {
        return;
    }

    for (int i = 0; i < depth; i++)
    {
        printf("----");
    }

    switch (node->node)
    {
    case KStmt:
        printf("Stmt: ");
        switch (node->stmt)
        {
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
            printf("Return: %s\n", getTypeName(node->type));
            break;
        case KCall:
            printf("Call\n");
            break;
        case KVar:
            printf("Var\n");
            break;
        case KVet:
            printf("Vet\n");
            break;
        case KFunc:
            printf("Func: %s\n", node->name);
            break;
        case KProg:
            printf("Prog\n");
            break;
        }
        break;
    case KExp:
        printf("Exp: ");
        switch (node->exp)
        {
        case KOp:
            printf("Op: %s\n", get_token_name(node->token));
            break;
        case KConst:
            printf("Const: %d\n", node->value);
            break;
        case KId:
            printf("Id: %s\n", node->name);
            break;
        case KType:
            printf("Type: %s\n", getTypeName(node->type));
            break;
        case KVarId:
            printf("VarId: %s\n", node->name);
            break;
        case KVetId:
            printf("VetId\n");
            break;
        }
        break;
    }

    AASNode *child;
    child = node->children;
    while (child != NULL)
    {
        printAAS(child, depth + 1);
        child = child->sibling;
    }
}

void deallocateAAS(AASNode *node)
{
    if (node == NULL)
    {
        return;
    }

    AASNode *child = node->children;
    while (child != NULL)
    {
        AASNode *temp = child;
        child = child->sibling;
        deallocateAAS(temp);
    }

    // printf("Deallocating node: %s\n", node->name ? node->name : "(null)");
    // printf("Name address: %p\n", node->name);
    // printf("Escopo address: %p\n", node->escopo);
    if (node->name != NULL)
    {
        free(node->name);
        node->name = NULL; // Set to NULL to avoid double free
    }
    if (node->escopo != NULL)
    {
        free(node->escopo);
        node->escopo = NULL; // Set to NULL to avoid double free
    }
    free(node);
}

char *copyString(char *src)
{
    int n;
    char *dest;
    if (src == NULL)
    {
        dest = NULL;
        return dest;
    }
    n = strlen(src);
    dest = calloc(n + 1, sizeof(char));
    if (dest == NULL)
    {
        printf("Error allocating memory to the destination string\n");
        return dest;
    }
    strncpy(dest, src, n);
    return dest;
}

char *getTypeName(TypeKind type)
{
    switch (type)
    {
    case KInt:
        return "int";
    case KVoid:
        return "void";
    default:
        return "ERRO";
    }
}

static int hash(char *name)
{
    if (name == NULL)
    {
        return -1;
    }

    int temp = 0;
    int i = 0;
    while (name[i] != '\0')
    {
        temp = ((temp << 4) + name[i]) % MAX;
        ++i;
    }
    return temp;
}

SimbCell *searchTabSimb(SimbCell *tab, char *name, char *escopo)
{
    int h = hash(name);
    SimbCell *cell, *sibling;
    cell = &tab[h];
    while (cell != NULL)
    {
        if (cell->name == NULL)
        {
            return NULL;
        }
        if (strcmp(cell->name, name) == 0)
        {
            if ((strcmp(cell->escopo, escopo) == 0) || (strcmp(cell->escopo, "global") == 0))
            {
                return cell;
            }
            else
            {
                sibling = cell->sibling;
                while (sibling != NULL)
                {
                    if (strcmp(sibling->name, name) == 0)
                    {
                        if ((strcmp(sibling->escopo, escopo) == 0 || strcmp(sibling->escopo, "global") == 0))
                        {
                            return sibling;
                        }
                    }
                    sibling = sibling->sibling;
                }
            }
        }
        cell = cell->next;
    }
    return NULL;
}

void insertHash(SimbCell *tab, char *name, char *escopo, TypeKind type, IdKind kind, int line, int hash)
{
    if (name == NULL)
    {
        return;
    }
    SimbCell *cell = &tab[hash];
    if (cell->name == NULL)
    {
        cell->name = copyString(name);
        cell->escopo = copyString(escopo);
        cell->type = type;
        cell->IdKind = kind;
        cell->line = line;
        cell->next = NULL;
        cell->sibling = NULL;
        return;
    }

    SimbCell *newCell = (SimbCell *)calloc(1, sizeof(SimbCell));
    if (newCell == NULL)
    {
        printf("Error allocating memory\n");
        return;
    }

    newCell->name = copyString(name);
    newCell->escopo = copyString(escopo);
    newCell->type = type;
    newCell->IdKind = kind;
    newCell->line = line;
    newCell->next = NULL;
    newCell->sibling = NULL;

    while (cell->next != NULL && strcmp(cell->name, name) != 0)
    { // Verificar se a célula já existe
        cell = cell->next;
    }
    if (cell->next == NULL)
    {
        cell->next = newCell;
    }
    else
    {
        SimbCell *sibling = cell->sibling;
        if (sibling == NULL)
        {
            cell->sibling = newCell;
        }
        else
        {
            while (sibling->next != NULL)
            {
                sibling = sibling->sibling;
            }
            sibling->sibling = newCell;
        }
    }
}

int insertTabSimb(SimbCell *tab, AASNode *node)
{
    int h = hash(node->name);
    if (h == -1)
    {
        return 0; // Pular a inserção
    }

    switch (node->node)
    {
    case KStmt:
        if (node->stmt == KVar || node->stmt == KVet)
        {
            if (node->type == KVoid)
            {
                semantic_error = "Declaracao de tipo void para a variavel";
                return -1;
            }
            if (searchTabSimb(tab, node->name, node->escopo) != NULL)
            {
                semantic_error = "Redeclaração da variável";
                return -1;
            }
            else
            {
                insertHash(tab, node->name, node->escopo, node->type, Var, node->line, h);
                return 1;
            }
        }
        else if (node->stmt == KFunc)
        {
            if (searchTabSimb(tab, node->name, "global") != NULL)
            {
                semantic_error = "Redeclaração da função";
                return -1;
            }
            else
            {
                insertHash(tab, node->name, "global", node->type, Func, node->line, h);
                return 1;
            }
        }
        else if (node->stmt == KCall)
        {
            SimbCell *aux = searchTabSimb(tab, node->name, "global");
            if (aux == NULL)
            { // Verificar se a função foi declarada
                semantic_error = "Função não declarada";
                return -1;
            }
            else if (node->children != NULL)
            {
                AASNode *child = node->children;
                while (child != NULL)
                {
                    if (child->stmt == KCall)
                    {
                        SimbCell *aux = searchTabSimb(tab, child->name, "global");
                        if (aux == NULL)
                        {
                            semantic_error = "Função não declarada";
                            free(node->name);
                            node->name = copyString(child->name);
                            return -1;
                        }
                        else if (aux->type == KVoid)
                        {
                            semantic_error = "Tipos incompatíveis";
                            return -1;
                        }
                    }
                    child = child->sibling;
                }
            }               
            {
                insertHash(tab, node->name, node->escopo, node->type, Func, node->line, h);
                return 1;
            }
        }
        else if (node->stmt == KAssign)
        {
            if (node->type == KVoid)
            {
                semantic_error = "Atribuição de tipo void para a variável";
                return -1;
            }
            else if (node->children->sibling->stmt == KCall)
            {
                SimbCell *aux = searchTabSimb(tab, node->children->sibling->name, "global");
                if (aux == NULL)
                {
                    semantic_error = "Função não declarada";
                    free(node->name);
                    node->name = copyString(node->children->sibling->name);
                    return -1;
                }
                else if (aux->type != node->type)
                {
                    semantic_error = "Atribuição com tipos incompatíveis";
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
            else if (node->type != node->children->type != node->children->sibling->type)
            {
                semantic_error = "Tipos incompatíveis";
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else if (node->stmt == KReturn)
        {
            SimbCell *aux = searchTabSimb(tab, node->escopo, "global");
            if (aux->type != node->type)
            {
                semantic_error = "Retorno com tipos incompatíveis";
                return -1;
            }
            else
            {
                return 1;
            }
        }
        break;

    case KExp:
        if (node->exp == KVarId || node->exp == KVetId)
        {
            SimbCell *aux = searchTabSimb(tab, node->name, node->escopo);
            if (aux == NULL)
            {
                aux = searchTabSimb(tab, node->name, "global");
                if (aux == NULL)
                {
                    semantic_error = "Variável não declarada";
                    return -1;
                }
                else
                {
                    insertHash(tab, node->name, "global", node->type, Var, node->line, h);
                    return 1;
                }
            }
            else
            {
                insertHash(tab, node->name, node->escopo, node->type, Var, node->line, h);
                return 1;
            }
        }
        break;
    }
}

int buildTabSimb(SimbCell *tabSimb, AASNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    char kind[9];

    AASNode *child = node->children;
    int k = 0;
    while (child != NULL)
    { // alterar a lógica de inserção para buildar a tabela de símbolos (problema possivelmente na recursao)
        k = insertTabSimb(tabSimb, child);
        if (k == -1)
        {
            printf("%s: %s [linha: %d]\n", semantic_error, child->name, child->line + 1);
            return -1;
        }
        else if (k == 1)
        {
            if (child->stmt == KVar || child->stmt == KVet || child->exp == KVarId || child->exp == KVetId || child->exp == KId)
            {
                strcpy(kind, "Variable");
            }
            else
            {
                strcpy(kind, "Function");
            }

            printf("%s;\t%s;\t%s;\t%s;\t\t%d\n", child->name, child->escopo, getTypeName(child->type), kind, child->line + 1);
        }
        if (buildTabSimb(tabSimb, child) == -1)
        {
            return -1;
        }
        child = child->sibling;
    }
}

void printTabSimb(SimbCell *tabSimb, AASNode *node)
{
    printf("Formato da Tabela de Simbolos:\n");
    printf("Nome;\tEscopo;\tTipo;\tTipo de Identificador;\tLinha\n");
    buildTabSimb(tabSimb, node);
}

void deallocateTabSimb(SimbCell *tabSimb)
{
    for (int i = 0; i < MAX; i++)
    {
        SimbCell *cell = &tabSimb[i];
        while (cell != NULL)
        {
            SimbCell *temp = cell;
            cell = cell->next;
            SimbCell *sibling = temp->sibling;
            while (sibling != NULL)
            {
                SimbCell *siblingTemp = sibling;
                sibling = sibling->sibling;
                if (siblingTemp->name != NULL)
                {
                    free(siblingTemp->name);
                    temp->name = NULL;
                }
                if (siblingTemp->escopo != NULL)
                {
                    free(siblingTemp->escopo);
                    temp->escopo = NULL;
                }
                free(siblingTemp);
            }
            if (temp->name != NULL)
            {
                free(temp->name);
                temp->name = NULL;
            }
            if (temp->escopo != NULL)
            {
                free(temp->escopo);
                temp->escopo = NULL;
            }
            if (temp != &tabSimb[i])
            {
                free(temp);
            }
        }
    }
}