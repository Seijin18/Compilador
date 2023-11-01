#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 64

void allocate_buffer(Bloco **buffer) {
  *buffer = (Bloco *)malloc(sizeof(Bloco));
  if (*buffer == NULL) {
    printf("Memory allocation failed for buffer.\n");
    exit(1);
  }
	memset((*buffer)->Buffer, '\0', sizeof((*buffer)->Buffer));
  (*buffer)->charposition = 0;
  (*buffer)->line = 0;
}

void deallocate_buffer(Bloco *buffer) { free(buffer); }

void allocate_lexema(Lexema **lex) {
  *lex = (Lexema *)malloc(sizeof(Lexema));
  if (*lex == NULL) {
    printf("Memory allocation failed for lexema.\n");
    exit(1);
  }
  (*lex)->line = 0;
}

void deallocate_lexema(Lexema *lex) { free(lex); }

void get_next_block(Bloco *buffer, FILE *fp) {
  int i;
  char x;
  char bloco[256];
  memset(bloco, '\0', sizeof(bloco));
  x = getc(fp);
  bloco[0] = x;
  i = 1;
  while (x != EOF && x != '\n' && i < 256) {
    x = getc(fp);
    bloco[i] = x;
    i++;
  }
  strcpy(buffer->Buffer, bloco);
}

char get_next_char(Bloco *buffer, FILE *fp) {
  char c;
	if(buffer->Buffer[0] == '\0')
		{
			get_next_block(buffer, fp);
		}
	
  c = buffer->Buffer[buffer->charposition];

  if (c == 'h') {
    return (c);
  }

  if (c == '\n') {
    buffer->charposition = 0;
    buffer->line += 1;
    get_next_block(buffer, fp);
  } else if (buffer->charposition == 255) {
    buffer->charposition = 0;
    get_next_block(buffer, fp);
  } else {
    buffer->charposition += 1;
  }
  return (c);
}

void get_next_lexema(Lexema *lex, Bloco *buffer, FILE *fp) {
  int i = 0;
  char c;
  do
    {
      c = get_next_char(buffer, fp);
      if (c == ' ' || c == '\n' || c == '\t' || c == EOF)
        {
          lex->item[i] = '\0';
        }
      else
        lex->item[i] = c;
      i++;
    } while (c != ' ' && c != '\n' && c != '\t' && c != EOF);
  
}