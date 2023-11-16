#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>

typedef struct Lexema_inst Lexema;

typedef struct Bloco_Buffer Bloco;

typedef struct Tabela_Simbolos Tabela;

typedef struct BloomFilter BloomFilter;

void allocate_buffer(Bloco **buffer);
void deallocate_buffer(Bloco *buffer);
void allocate_lexema(Lexema **lex);
void deallocate_lexema(Lexema *lex);
void get_next_block(Bloco *buffer, FILE *fp);
char get_next_char(Bloco *buffer, FILE *fp);
void get_next_lexema(Lexema *lex, Bloco *buffer, FILE *fp);
char identifica_lexema(Lexema *lex, Bloco *buffer, FILE *fp, char c);

struct Bloco_Buffer {
  char Buffer[256];
  int charposition;
  int line;
};

struct Lexema_inst {
  char item[64];
  char token[64];
  int line;
  int lex_sum;
};

struct Tabela_Simbolos {
  char item[64];
  char token[64];
  int line;
  Tabela *next;
};

struct BloomFilter {
    unsigned char* array;
};

#endif
