#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 100
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
    printf("Numero: %c\n", c);
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
  memset((*lex)->item, '\0', sizeof((*lex)->item));
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
    case ',':
      return 7;
    case ';':
      return 8;
    case '(':
      return 9;
    case ')':
      return 10;
    case '[':
      return 11;
    case ']':
      return 12;
    case '{':
      return 13;
    case '}':
      return 14;
    case '<':
      return 15;
    case '>':
      return 16;
    case '!':
      return 17;
    default:
      return -1;
    }
  }
  if (c == EOF || check_whitespace(c))
  {
    return 18;
  }
  return -1;
}

/*Get lexema função dirigido por tabela*/
int get_next_lexema_tabela(Lexema *lex, Bloco *buffer, FILE *fp, int tabela[28][19], Lista *ht)
{
  int i = 0;
  int estado = 0;
  char c;
  int lex_sum = 0;
  int ht_position = -1;
  int table_value = -1;

  c = get_next_char(buffer, fp);
  if (check_whitespace(c))
  {
    while (check_whitespace(c))
    {
      c = get_next_char(buffer, fp);
    }
  }
  retract(buffer);
  do
  {
    c = get_next_char(buffer, fp);

    lex->item[i] = c;
    table_value = convert_char_to_table(c); // Converte o char para o valor da tabela
    estado = tabela[estado][table_value];   // Pega o estado atual e o valor da tabela e retorna o novo estado

    printf("Caracter: %c\n", c);
    printf("Table value: %d\n", table_value);
    printf("Estado: %d\n", estado);

    if (check_whitespace(c) || check_special(c) || c == EOF) // Se for espaço em branco ou caracter especial
    {
      if (check_whitespace(c) || c == EOF)
      {
        retract(buffer);
      }
      lex->item[i] = '\0';
      lex->line = buffer->line;
      lex_sum = Get_Char_Value(lex->item);

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
      case 3: // ID sem numero
      {
        ht_position = Pesquisa_Hash(lex_sum, ht, tam);
        if (ht_position == -1)
        {
          strcpy(lex->token, "ID");
        }
        else
        {
          strcpy(lex->token, ht[ht_position].Primeiro->Item);
        }
        
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
        c = get_next_char(buffer, fp);
        if (c == '=')
        {
          strcpy(lex->token, "IGUAL");
        }
        else
        {
          strcpy(lex->token, "ATRIBUICAO");
          retract(buffer);
        }
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
        c = get_next_char(buffer, fp);
        if (c == '=')
        {
          strcpy(lex->token, "MAIOR_IGUAL");
        }
        else
        {
          strcpy(lex->token, "MAIOR");
          retract(buffer);
        }
        break;
      }
      case 12: // MENOR
      {
        c = get_next_char(buffer, fp);
        if (c == '=')
        {
          strcpy(lex->token, "MENOR_IGUAL");
        }
        else
        {
          strcpy(lex->token, "MENOR");
          retract(buffer);
        }
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
          lex->item[i] = c;
          i++;
          if (c == '*')
          {
            c = get_next_char(buffer, fp);
            lex->item[i] = c;
            if (c == '/')
            {
              strcpy(lex->token, "COMENTARIO");
              lex_sum = -1;
              break;
            }
          }
          if (c == '/')
          {
            c = get_next_char(buffer, fp);
            lex->item[i] = c;
            if (c == '*')
            {
              strcpy(lex->token, "ERRO");
              lex_sum = -1;
              break;
            }
          }
        }
        lex->item[i + 1] = '\0';
        break;
      }

      default: // ERRO
      {
        strcpy(lex->token, "ERRO");
        lex_sum = 0;
        break;
      }
      }
    }
    else
    {
      lex->item[i] = c;
    }
    i++;
  } while (c != ' ' && c != '\n' && c != '\t' && c != EOF);
  if (c == EOF)
    {
      return -1;
    }
  return 1;
}

unsigned int hash(int lex_sum) // Divisão
{
  return lex_sum % bloom_size;
}

BFilter *allocate_BloomFilter()
{
  BFilter *filter = (BFilter *)malloc(sizeof(BFilter));
  filter->array = (unsigned char *)calloc(bloom_size, sizeof(unsigned char));
  return filter;
}

void deallocate_BloomFilter(BFilter *filter)
{
  free(filter->array);
  free(filter);
}

void add_BloomFilter(BFilter *filter, char *lexema)
{
  int lex_sum = 0;
  for (int i = 0; i < strlen(lexema); i++)
  {
    lex_sum += lexema[i];
  }
  unsigned int hash_value = hash(lex_sum);
  filter->array[hash_value / 8] |= (1 << (hash_value % 8));
}

int check_BloomFilter(BFilter *filter, int lex_sum)
{
  unsigned int hash_value = hash(lex_sum);
  if (!(filter->array[hash_value / 8] & (1 << (hash_value % 8))))
  {
    return 0;
  }
  return 1;
}





int Get_Char_Value(char *c)
{
  int sum = 0;
  int i;
  int len = 0;
  while (c[len] != '\0') {
    sum += c[len];
    len++;
  }
  return sum;
}


//Função que cria nó com informação passada
Node* Cria_Node(int key, char *item)
{
  Node *node;
  node = malloc(sizeof(Node));
  node->Prox = NULL;
  node->Value = key;
  node->Item = item;
  return node;
}

//Inicia Lista
void Lista_Inicia(Lista *Lista)
{
  Node *Aux;
  Lista->Tamanho = 0;
  Lista->Primeiro = NULL;
}

//Função que insere elementos na lista como em fila
void Lista_Insere(Lista *Lista, int key, char *item)
{
  Node *node;
  node = Cria_Node(key, item);
  if(Lista->Primeiro == NULL)
    {
        Lista_Inicia(Lista);
        Lista->Primeiro = node;
        Lista->Tamanho++;
        return;
    }
  node->Prox = Lista->Primeiro;
  Lista->Primeiro = node;
  Lista->Tamanho ++;
}

int Seleciona_Chave(int chave, int tamanho)
{
    return chave % tamanho;
}

int Pesquisa_Hash(int chave, Lista *Tabela, int tamanho)
{
  int Position;
  Position = Seleciona_Chave(chave, tamanho);
  Node *Aux = Tabela[Position].Primeiro;
  while(Aux != NULL)
    {
        if(Aux->Value == chave)
            {
                return Position;
            }
        Aux = Aux->Prox;
    }
  return -1;
}

int Insere_Hash(int chave, char *item, Lista *tabela, int tamanho)
{
    int Position;
    Position = Seleciona_Chave(chave, tamanho);
    if (&tabela[Position].Primeiro == NULL)
        {
            Lista_Inicia(&tabela[Position]);
            Lista_Insere(&tabela[Position], chave, item);
            return 1;
        }
    else
        {
            Lista_Insere(&tabela[Position], chave, item);
            return 1;
        }
}

void Tabela_Inicia(Lista *Tabela, int tamanho)
{
  int i;
  for(i = 0; i < tamanho; i++)
    {
        Lista_Inicia(&Tabela[i]);
    }
}

void Deallocate_Tabela(Lista *Tabela, int tamanho)
{
  int i;
  for(i = 0; i < tamanho; i++)
    {
        free(Tabela[i].Primeiro);
    }
  free(Tabela);
}