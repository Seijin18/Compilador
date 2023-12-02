#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 64
#define bloom_size 100

typedef enum
{
  SOMA = 1,
  SUBTRACAO = 2,
  MULTIPLICACAO = 3,
  DIVISAO = 4,
  ATRIBUICAO = 5,
  IGUAL = 6,
  DIFERENTE = 7,
  MAIOR = 8,
  MENOR = 9,
  MAIOR_IGUAL = 10,
  MENOR_IGUAL = 11,
  ABRE_PARENTES = 12,
  FECHA_PARENTES = 13,
  ABRE_CHAVES = 14,
  FECHA_CHAVES = 15,
  ABRE_COLCHETES = 16,
  FECHA_COLCHETES = 17,
  PONTO_VIRGULA = 18,
  VIRGULA = 19,
  ABRE_COMENTARIO = 20,
  FECHA_COMENTARIO = 21,
} Token;

int check_whitespace(char c)
{
  if (c == ' ' || c == '\n' || c == '\t')
  {
    return 1;
  }
  return 0;
}

int check_special(char c)
{
  if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ',' || c == '/' || c == '*' || c == '+' || c == '-' || c == '=' || c == '!' || c == '<' || c == '>')
  {
    return 1;
  }
  return 0;
}

int check_special_with_following(char c)
{
  if (c == '=' || c == '!' || c == '<' || c == '>' || c == '/' || c == '*')
  {
    return 1;
  }
  return 0;
}

int check_number(char c)
{
  if (c >= '0' && c <= '9')
  {
    return 1;
  }
  return 0;
}

int check_letter(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
  {
    return 1;
  }
  return 0;
}

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

char get_next_char(Bloco *buffer, FILE *fp)
{
  char c;
  if (buffer->Buffer[0] == '\0')
  {
    get_next_block(buffer, fp);
  }

  c = buffer->Buffer[buffer->charposition];

  if (c == 'h')
  {
    return (c);
  }

  if (c == '\n')
  {
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

void retract(Bloco *buffer)
{
  if (buffer->charposition == 0)
  {
    buffer->charposition = 255;
    buffer->line -= 1;
  }
  else
  {
    buffer->charposition -= 1;
  }
}

// void get_next_lexema(Lexema *lex, Bloco *buffer, FILE *fp)
// {
//   int i = 0;
//   int estado = 0;
//   char c;
//   int lex_sum = 0;
//   do
//   {
//     c = get_next_char(buffer, fp);
//     lex_sum += c;
//     switch (estado)
//     {
//     case 0:
//     {
//       if (c >= '0' && c <= '9')
//       {
//         estado = 1;
//       }
//       else if (c >= 'a' && c <= 'z')
//       {
//         estado = 2;
//       }
//       else
//       {
//         estado = 3;
//       }
//     }
//     case 1:
//     {
//       if (c >= '0' && c <= '9')
//       {
//         estado = 1;
//       }
//       else
//       {
//         estado = 4;
//       }
//     }
//     case 2:
//     {
//       if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
//       {
//         estado = 2;
//       }
//       else
//       {
//         estado = 4;
//       }
//     }

//     default:
//       break;
//     }
//     if (c == ' ' || c == '\n' || c == '\t' || c == EOF)
//     {
//       lex->item[i] = '\0';
//       lex->line = buffer->line;
//       switch (estado)
//       {
//       case 1:
//       {
//         strcpy(lex->token, "NUM");
//         break;
//       }
//       case 2:
//       {
//         strcpy(lex->token, "ID");
//         break;
//       }
//       case 3: // tabela de simbolos
//       {
//         strcpy(lex->token, );
//         break;
//       }
//       }
//     }
//     else
//       lex->item[i] = c;
//     i++;
//   } while (c != ' ' && c != '\n' && c != '\t' && c != EOF);

//   lex->lex_sum = lex_sum;
// }

int convert_char_to_table(char c)
{
  if (check_letter(c))
  {
    return 0;
  }
  if (check_number(c))
  {
    return 1;
  }
  if (check_special(c))
  {
    switch (c)
    {
    case '+':
      return 2;
    case '-':
      return 3;
    case '*':
      return 4;
    case '/':
      return 5;
    case '=':
      return 6;
    case '!':
      return 7;
    case '<':
      return 8;
    case '>':
      return 9;
    case '(':
      return 10;
    case ')':
      return 11;
    case '{':
      return 12;
    case '}':
      return 13;
    case '[':
      return 14;
    case ']':
      return 15;
    case ';':
      return 16;
    case ',':
      return 17;
    default:
      return -1;
    }
  }
}

/*Get lexema função dirigido por tabela*/
void get_next_lexema_tabela(Lexema *lex, Bloco *buffer, FILE *fp, int **tabela)
{
  int i = 0;
  int estado = 0;
  char c;
  int lex_sum = 0;
  int table_value;
  do
  {
    c = get_next_char(buffer, fp);
    lex_sum += c;
    table_value = convert_char_to_table(c);
    estado = tabela[estado][table_value];
    if (check_whitespace(c) || check_special(c))
    {
      if (!(check_special_with_following(c) && (estado == 9 || estado == 10 || estado == 13 || estado == 14)))
      {
        if (check_special(c) && i > 0)
        {
          retract(buffer);
        }
        lex->item[i] = '\0';
        lex->line = buffer->line;
        lex->lex_sum = lex_sum;
        switch (estado)
        {
        case 1:
        {
          strcpy(lex->token, "NUM");
          break;
        }
        case 2:
        {
          strcpy(lex->token, "VERIFICAR");
          break;
        }
        case 3: // ID with number
        {
          strcpy(lex->token, "ID");
          break;
        }
        case 4: // SOMA
        {
          strcpy(lex->token, "SOMA");
          break;
        }
        case 5: // SUBTRACAO
        {
          strcpy(lex->token, "SUBTRACAO");
          break;
        }
        case 6: // MULTIPLICACAO
        {
          strcpy(lex->token, "MULTIPLICACAO");

          break;
        }
        case 7: // DIVISAO
        {
          strcpy(lex->token, "DIVISAO");
          break;
        }
        case 8: // ATRIBUICAO
        {
          strcpy(lex->token, "ATRIBUICAO");
          break;
        }
        case 9: // IGUAL
        {
          strcpy(lex->token, "IGUAL");
          break;
        }
        case 10: // DIFERENTE
        {
          strcpy(lex->token, "DIFERENTE");
          break;
        }
        case 11: // MAIOR
        {
          strcpy(lex->token, "MAIOR");
          break;
        }
        case 12: // MENOR
        {
          strcpy(lex->token, "MENOR");
          break;
        }
        case 13: // MAIOR_IGUAL
        {
          strcpy(lex->token, "MAIOR_IGUAL");
          break;
        }
        case 14: // MENOR_IGUAL
        {
          strcpy(lex->token, "MENOR_IGUAL");
          break;
        }
        case 15: // ABRE_PARENTES
        {
          strcpy(lex->token, "ABRE_PARENTES");
          break;
        }
        case 16: // FECHA_PARENTES
        {
          strcpy(lex->token, "FECHA_PARENTES");
          break;
        }
        case 17: // ABRE_CHAVES
        {
          strcpy(lex->token, "ABRE_CHAVES");
          break;
        }
        case 18: // FECHA_CHAVES
        {
          strcpy(lex->token, "FECHA_CHAVES");
          break;
        }
        case 19: // ABRE_COLCHETES
        {
          strcpy(lex->token, "ABRE_COLCHETES");
          break;
        }
        case 20: // FECHA_COLCHETES
        {
          strcpy(lex->token, "FECHA_COLCHETES");
          break;
        }
        case 21: // PONTO_VIRGULA
        {
          strcpy(lex->token, "PONTO_VIRGULA");
          break;
        }
        case 22: // VIRGULA
        {
          strcpy(lex->token, "VIRGULA");
          break;
        }
        case 23: // COMENTARIO
        {
          while (c != EOF)
          {
            c = get_next_char(buffer, fp);
            if (c == '*')
            {
              c = get_next_char(buffer, fp);
              if (c == '/')
              {
                strcpy(lex->token, "COMENTARIO");
                lex_sum = -1;
                break;
              }
            }
            if (c == /)
            {
              c = get_next_char(buffer, fp);
              if (c == '*')
              {
                strcpy(lex->token, "ERRO");
                lex_sum = -1;
                break;
              }
            }
          }

          break;
        }
        default: // ERRO
        {
          strcpy(lex->token, "ERRO");
          lex_sum = -1;
          break;
        }
        }
      }
    }
    else
    {
      lex->item[i] = c;
    }
    i++;
  } while (c != ' ' && c != '\n' && c != '\t' && c != EOF);
}

unsigned int hash(int lex_sum) // Divisão
{
  return lex_sum % bloom_size;
}

BloomFilter *allocate_BloomFilter()
{
  BloomFilter *filter = (BloomFilter *)malloc(sizeof(BloomFilter));
  filter->array = (unsigned char *)calloc(bloom_size, sizeof(unsigned char));
  return filter;
}

void add_BloomFilter(BloomFilter *filter, int lex_sum)
{
  unsigned int hash_value = hash(lex_sum);
  filter->array[hash_value / 8] |= 1 << (hash_value % 8);
}

int check_BloomFilter(BloomFilter *filter, int lex_sum)
{
  unsigned int hash_value = hash(lex_sum);
  if (!(filter->array[hash_value / 8] & (1 << (hash_value % 8))))
  {
    return 0;
  }
  return 1;
}