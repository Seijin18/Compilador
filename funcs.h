#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>

typedef struct Lexema_inst Lexema;

typedef struct Bloco_Buffer Bloco;

typedef struct Tabela_Simbolos Tabela;

typedef struct BloomFilter BFilter;

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
int get_next_lexema_tabela(Lexema *lex, Bloco *buffer, FILE *fp, int tabela[28][19], BFilter *bf);
unsigned int hash(int lex_sum);
BFilter* allocate_BloomFilter();
void deallocate_BloomFilter(BFilter* bf);
void add_BloomFilter(BFilter* bf, char *item);
int check_BloomFilter(BFilter* bf, int lex_sum);


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
