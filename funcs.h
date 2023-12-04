#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>

typedef struct Lexema_inst Lexema;

typedef struct Bloco_Buffer Bloco;

typedef struct Tabela_Simbolos Tabela;

typedef struct Lista_Hash Lista;

typedef struct Lista_Node Node;

int check_whitespace(char c);
int check_special(char c);
int check_special_with_following(char c);
int check_number(char c);
int check_letter(char c);
void allocate_buffer(Bloco **buffer);
void deallocate_buffer(Bloco *buffer);
void allocate_lexema(Lexema **lex);
void deallocate_lexema(Lexema *lex);
void get_next_block(Bloco *buffer, FILE *fp);
char get_next_char(Bloco *buffer, FILE *fp);
void retract(Bloco *buffer);
int convert_char_to_table(char c);
int get_next_lexema_tabela(Lexema *lex, Bloco *buffer, FILE *fp, int tabela[28][19], Lista *ht);
unsigned int hash(int lex_sum);
int Get_Char_Value(char *c);
int Get_Token_Type(char *c);
Node* Cria_Node(int key, char *item);
void Lista_Inicia(Lista *Lista);
void Lista_Insere(Lista *Lista, int key, char *item);
int Seleciona_Chave(int chave, int tamanho);
int Pesquisa_Hash(int chave, Lista *Tabela, int tamanho);
int Insere_Hash(int chave, char *item, Lista *tabela, int tamanho);
void Tabela_Inicia(Lista *tabela, int tamanho);
void Deallocate_Tabela(Lista *tabela, int tamanho);


struct Bloco_Buffer {
  char Buffer[256];
  int charposition;
  int line;
};

struct Lexema_inst {
  char item[64];
  char token[64];
  int token_type;
  int line;
  int lex_sum;
};

struct Tabela_Simbolos {
  char item[64];
  char token[64];
  int line;
  Tabela *next;
};

struct Lista_Hash{
  Node *Primeiro;
  int Tamanho;
};

struct Lista_Node{
  int Value;
  char *Item;
  Node *Prox;
};

#endif
