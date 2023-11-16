#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 64
#define bloom_size 100

void allocate_buffer(Bloco **buffer) 
{
  *buffer = (Bloco *)malloc(sizeof(Bloco));
  if (*buffer == NULL) 
  {
    printf("Memory allocation failed for buffer.\n");
    exit(1);
  }
	memset((*buffer)->Buffer, '\0', sizeof((*buffer)->Buffer));
  (*buffer)->charposition = 0;
  (*buffer)->line = 0;
}

void deallocate_buffer(Bloco *buffer) { free(buffer); }

void allocate_lexema(Lexema **lex) 
{
  *lex = (Lexema *)malloc(sizeof(Lexema));
  if (*lex == NULL) 
  {
    printf("Memory allocation failed for lexema.\n");
    exit(1);
  }
  (*lex)->line = 0;
}

void deallocate_lexema(Lexema *lex) { free(lex); }

void get_next_block(Bloco *buffer, FILE *fp) 
{
  int i;
  char x;
  char bloco[256];
  memset(bloco, '\0', sizeof(bloco));
  x = getc(fp);
  bloco[0] = x;
  i = 1;
  while (x != EOF && x != '\n' && i < 256) 
  {
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

  if (c == 'h') 
  {
    return (c);
  }

  if (c == '\n') {
    buffer->charposition = 0;
    buffer->line += 1;
    get_next_block(buffer, fp);
  } 
  
  else if (buffer->charposition == 255) 
  {
    buffer->charposition = 0;
    get_next_block(buffer, fp);
  } 
  
  else 
  {
    buffer->charposition += 1;
  }
  return (c);
}

void get_next_lexema(Lexema *lex, Bloco *buffer, FILE *fp) 
{
  int i = 0;
  int estado = 0;
  char c;
  int lex_sum = 0;
  do
    {
      c = get_next_char(buffer, fp);
      lex_sum += c;
      switch (estado)
      {
      case 0:
        {
          if(c >= '0' && c <= '9')
            {
              estado = 1;
            }
          else if(c >= 'a' && c <= 'z')
            {
              estado = 2;
            }
          else
            {
              estado = 3;
            }
        } 
        case 1:
        {
          if(c >= '0' && c <= '9')
            {
              estado = 1;
            }
          else
            {
              estado = 4;
            }
        }
        case 2:
        {
          if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            {
              estado = 2;
            }
          else
            {
              estado = 4;
            }
        }
      
      default:
        break;
      }
      if (c == ' ' || c == '\n' || c == '\t' || c == EOF)
        {
          lex->item[i] = '\0';
          lex->line = buffer->line;
          switch (estado)
          {
          case 1:
            {
              strcpy(lex->token, "NUM");
              break;
            }
          case 2:
            {
              strcpy(lex->token, "ID");
              break;
            }
          case 3: // tabela de simbolos
            {
              strcpy(lex->token, );
              break;
            }
          }
        }
      else
        lex->item[i] = c;
      i++;
    } while (c != ' ' && c != '\n' && c != '\t' && c != EOF);

  lex->lex_sum = lex_sum;
}

BloomFilter* allocate_BloomFilter() 
{
    BloomFilter* filter = (BloomFilter*)malloc(sizeof(BloomFilter));
    filter->array = (unsigned char*)calloc(bloom_size, sizeof(unsigned char));
    return filter;
}

unsigned int hash(int lex_sum) // Divisão
{
    return lex_sum % bloom_size;
}

void add_BloomFilter(BloomFilter* filter, int lex_sum) 
{
    unsigned int hash = hash(lex_sum);
    filter->array[hash / 8] |= 1 << (hash % 8);
}

int check_BloomFilter(BloomFilter* filter, int lex_sum) 
{
    unsigned int hash = hash(lex_sum);
    if (!(filter->array[hash / 8] & (1 << (hash % 8)))) 
    {
        return 0;
    }
    return 1;
}