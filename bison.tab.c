/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison.y"

#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

FILE *fp;
Bloco *buffer = NULL;
Lista ht[MAX];
Lexema *lex;
int openned = 0;
int yylineno;
int valyy;
char yytext[64];

SymbolTable* TabelaSimbolos;
ASTNode* root; 

int yyerror(char *s);

int yylex(void);


#line 97 "bison.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMERO = 3,                     /* NUMERO  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_IGUAL = 11,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 12,                 /* DIFERENTE  */
  YYSYMBOL_MAIOR = 13,                     /* MAIOR  */
  YYSYMBOL_MENOR = 14,                     /* MENOR  */
  YYSYMBOL_MAIOR_IGUAL = 15,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 16,               /* MENOR_IGUAL  */
  YYSYMBOL_SOMA = 17,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 18,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 19,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 20,                   /* DIVISAO  */
  YYSYMBOL_ATRIBUICAO = 21,                /* ATRIBUICAO  */
  YYSYMBOL_PONTO_VIRGULA = 22,             /* PONTO_VIRGULA  */
  YYSYMBOL_VIRGULA = 23,                   /* VIRGULA  */
  YYSYMBOL_ABRE_PARENTESE = 24,            /* ABRE_PARENTESE  */
  YYSYMBOL_FECHA_PARENTESE = 25,           /* FECHA_PARENTESE  */
  YYSYMBOL_ABRE_COLCHETE = 26,             /* ABRE_COLCHETE  */
  YYSYMBOL_FECHA_COLCHETE = 27,            /* FECHA_COLCHETE  */
  YYSYMBOL_ABRE_CHAVES = 28,               /* ABRE_CHAVES  */
  YYSYMBOL_FECHA_CHAVES = 29,              /* FECHA_CHAVES  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_programa = 31,                  /* programa  */
  YYSYMBOL_declaracao_lista = 32,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 33,                /* declaracao  */
  YYSYMBOL_var_declaracao = 34,            /* var_declaracao  */
  YYSYMBOL_tipo_especificador = 35,        /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 36,            /* fun_declaracao  */
  YYSYMBOL_params = 37,                    /* params  */
  YYSYMBOL_param_lista = 38,               /* param_lista  */
  YYSYMBOL_param = 39,                     /* param  */
  YYSYMBOL_composto_decl = 40,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 41,         /* local_declaracoes  */
  YYSYMBOL_statement_lista = 42,           /* statement_lista  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_expressao_decl = 44,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 45,              /* selecao_decl  */
  YYSYMBOL_selecao_decl_else = 46,         /* selecao_decl_else  */
  YYSYMBOL_iteracao_decl = 47,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 48,              /* retorno_decl  */
  YYSYMBOL_expressao = 49,                 /* expressao  */
  YYSYMBOL_var = 50,                       /* var  */
  YYSYMBOL_simples_expressao = 51,         /* simples_expressao  */
  YYSYMBOL_relacional = 52,                /* relacional  */
  YYSYMBOL_soma_expressao = 53,            /* soma_expressao  */
  YYSYMBOL_termo = 54,                     /* termo  */
  YYSYMBOL_fator = 55,                     /* fator  */
  YYSYMBOL_ativacao = 56,                  /* ativacao  */
  YYSYMBOL_args = 57,                      /* args  */
  YYSYMBOL_arg_lista = 58                  /* arg_lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    60,    61,    64,    65,    68,    69,    72,
      73,    76,    80,    82,    86,    88,    91,    93,    97,   101,
     104,   107,   110,   113,   115,   117,   119,   121,   125,   127,
     131,   135,   138,   141,   145,   147,   151,   153,   156,   158,
     162,   164,   167,   169,   171,   173,   175,   177,   181,   183,
     185,   188,   190,   192,   195,   197,   198,   199,   203,   207,
     210,   213,   215
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMERO", "ID", "IF",
  "ELSE", "WHILE", "INT", "RETURN", "VOID", "IGUAL", "DIFERENTE", "MAIOR",
  "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "SOMA", "SUBTRACAO",
  "MULTIPLICACAO", "DIVISAO", "ATRIBUICAO", "PONTO_VIRGULA", "VIRGULA",
  "ABRE_PARENTESE", "FECHA_PARENTESE", "ABRE_COLCHETE", "FECHA_COLCHETE",
  "ABRE_CHAVES", "FECHA_CHAVES", "$accept", "programa", "declaracao_lista",
  "declaracao", "var_declaracao", "tipo_especificador", "fun_declaracao",
  "params", "param_lista", "param", "composto_decl", "local_declaracoes",
  "statement_lista", "statement", "expressao_decl", "selecao_decl",
  "selecao_decl_else", "iteracao_decl", "retorno_decl", "expressao", "var",
  "simples_expressao", "relacional", "soma_expressao", "termo", "fator",
  "ativacao", "args", "arg_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,   -85,   -85,     1,    13,   -85,   -85,     9,   -85,   -85,
     -85,   -16,   -85,    42,    34,    29,    60,    50,    53,   -85,
      51,    54,    49,    13,    57,    55,   -85,   -85,   -85,   -85,
     -85,    13,   -85,    77,     0,    40,   -85,    39,    59,    61,
      11,   -85,    23,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
      62,    65,   -85,    28,    48,   -85,   -85,    23,    23,    23,
      23,   -85,    66,    64,   -85,    23,   -85,   -85,   -85,   -85,
     -85,   -85,    23,    23,    23,    23,    23,   -85,    67,    68,
      63,    69,    70,   -85,   -85,   -85,   -85,    48,    48,    52,
     -85,   -85,   -85,    23,   -85,    27,    27,   -85,    81,   -85,
      27,   -85,   -85
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     7,     0,     0,    10,     0,     0,    12,    15,
       0,    16,     0,     0,     0,     0,    20,    11,    14,     8,
      17,    22,    19,     0,     0,     0,    57,    38,     0,     0,
       0,    29,     0,    18,    24,    21,    23,    25,    26,    27,
       0,    55,    37,    41,    50,    53,    56,    60,     0,     0,
       0,    34,     0,     0,    28,     0,    46,    47,    44,    43,
      45,    42,     0,     0,     0,     0,     0,    62,     0,    59,
       0,     0,     0,    35,    54,    36,    55,    48,    49,    40,
      51,    52,    58,     0,    39,     0,     0,    61,    32,    33,
       0,    30,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -85,    89,    71,    25,   -85,   -85,   -85,    73,
      75,   -85,   -85,   -84,   -85,   -85,   -85,   -85,   -85,   -40,
     -15,   -85,   -85,    24,    -1,    -2,   -85,   -85,   -85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    17,    18,    19,
      44,    31,    34,    45,    46,    47,   101,    48,    49,    50,
      51,    52,    74,    53,    54,    55,    56,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,     9,    63,    36,    37,    38,    12,    39,    13,    40,
      14,    98,    99,    11,    36,    37,   102,    77,    80,    81,
      82,     1,    41,     2,    42,    85,    36,    37,    26,    43,
      36,    37,    38,    61,    39,    42,    40,    20,    16,    66,
      67,    68,    69,    70,    71,    72,    73,    42,    16,    41,
       1,    42,    15,    97,   -13,    26,    33,    86,    86,    86,
      86,    86,    12,    57,    21,    58,    14,    75,    76,    72,
      73,    87,    88,    90,    91,    22,    23,    26,    24,    29,
      25,    35,    30,    59,    64,    60,    65,   100,    83,    84,
      94,    93,    92,    10,    95,    96,    28,    27,    89,     0,
       0,     0,    32
};

static const yytype_int8 yycheck[] =
{
      40,     0,    42,     3,     4,     5,    22,     7,    24,     9,
      26,    95,    96,     4,     3,     4,   100,    57,    58,    59,
      60,     8,    22,    10,    24,    65,     3,     4,    28,    29,
       3,     4,     5,    22,     7,    24,     9,     3,    13,    11,
      12,    13,    14,    15,    16,    17,    18,    24,    23,    22,
       8,    24,    10,    93,    25,    28,    31,    72,    73,    74,
      75,    76,    22,    24,     4,    26,    26,    19,    20,    17,
      18,    72,    73,    75,    76,    25,    23,    28,    27,    22,
      26,     4,    27,    24,    22,    24,    21,     6,    22,    25,
      27,    23,    25,     4,    25,    25,    23,    22,    74,    -1,
      -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    31,    32,    33,    34,    35,    36,     0,
      33,     4,    22,    24,    26,    10,    35,    37,    38,    39,
       3,     4,    25,    23,    27,    26,    28,    40,    39,    22,
      27,    41,    34,    35,    42,     4,     3,     4,     5,     7,
       9,    22,    24,    29,    40,    43,    44,    45,    47,    48,
      49,    50,    51,    53,    54,    55,    56,    24,    26,    24,
      24,    22,    49,    49,    22,    21,    11,    12,    13,    14,
      15,    16,    17,    18,    52,    19,    20,    49,    57,    58,
      49,    49,    49,    22,    25,    49,    50,    54,    54,    53,
      55,    55,    25,    23,    27,    25,    25,    49,    43,    43,
       6,    46,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    35,
      35,    36,    37,    37,    38,    38,    39,    39,    40,    41,
      41,    42,    42,    43,    43,    43,    43,    43,    44,    44,
      45,    46,    46,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    54,    54,    54,    55,    55,    55,    55,    56,    57,
      57,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       6,     2,     0,     5,     2,     3,     3,     1,     1,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     4,     1,
       0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: declaracao_lista  */
#line 57 "bison.y"
                           { (yyval.nodeValue) = newASTNode("programa"); root = (yyval.nodeValue); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1213 "bison.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 60 "bison.y"
                                              { (yyval.nodeValue) = newASTNode("declaracao_lista"); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1219 "bison.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 61 "bison.y"
                             { (yyval.nodeValue) = newASTNode("declaracao_lista"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1225 "bison.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 64 "bison.y"
                           { (yyval.nodeValue) = newASTNode("declaracao"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1231 "bison.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 65 "bison.y"
                           { (yyval.nodeValue) = newASTNode("declaracao"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1237 "bison.tab.c"
    break;

  case 7: /* var_declaracao: tipo_especificador ID PONTO_VIRGULA  */
#line 68 "bison.y"
                                                    { (yyval.nodeValue) = newASTNode("var_declaracao"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), newASTNodeValue("ID", (yyvsp[-1].stringValue))); }
#line 1243 "bison.tab.c"
    break;

  case 8: /* var_declaracao: tipo_especificador ID ABRE_COLCHETE NUMERO FECHA_COLCHETE PONTO_VIRGULA  */
#line 69 "bison.y"
                                                                                        { (yyval.nodeValue) = newASTNode("var_declaracao"); addASTNode((yyval.nodeValue), (yyvsp[-5].nodeValue)); addASTNode((yyval.nodeValue), newASTNodeValue("ID", (yyvsp[-4].stringValue))); }
#line 1249 "bison.tab.c"
    break;

  case 9: /* tipo_especificador: INT  */
#line 72 "bison.y"
                        { (yyval.nodeValue) = newASTNodeValue("tipo_especificador", "int");}
#line 1255 "bison.tab.c"
    break;

  case 10: /* tipo_especificador: VOID  */
#line 73 "bison.y"
                         { (yyval.nodeValue) = newASTNodeValue("tipo_especificador", "void"); }
#line 1261 "bison.tab.c"
    break;

  case 11: /* fun_declaracao: tipo_especificador ID ABRE_PARENTESE params FECHA_PARENTESE composto_decl  */
#line 77 "bison.y"
    { (yyval.nodeValue) = newASTNode("fun_declaracao"); addASTNode((yyval.nodeValue), (yyvsp[-5].nodeValue)); addASTNode((yyval.nodeValue), newASTNodeValue("ID", (yyvsp[-4].stringValue))); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue));}
#line 1267 "bison.tab.c"
    break;

  case 12: /* params: param_lista  */
#line 81 "bison.y"
    { (yyval.nodeValue) = newASTNode("params"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1273 "bison.tab.c"
    break;

  case 13: /* params: VOID  */
#line 83 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("params", "void"); }
#line 1279 "bison.tab.c"
    break;

  case 14: /* param_lista: param_lista VIRGULA param  */
#line 87 "bison.y"
    { (yyval.nodeValue) = newASTNode("param_lista"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1285 "bison.tab.c"
    break;

  case 16: /* param: tipo_especificador ID  */
#line 92 "bison.y"
    { (yyval.nodeValue) = newASTNode("param"); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); addASTNode((yyval.nodeValue), newASTNodeValue("ID", (yyvsp[0].stringValue))); }
#line 1291 "bison.tab.c"
    break;

  case 17: /* param: tipo_especificador ID ABRE_COLCHETE FECHA_COLCHETE  */
#line 94 "bison.y"
    { (yyval.nodeValue) = newASTNode("param"); addASTNode((yyval.nodeValue), (yyvsp[-3].nodeValue)); addASTNode((yyval.nodeValue), newASTNodeValue("ID", (yyvsp[-2].stringValue))); }
#line 1297 "bison.tab.c"
    break;

  case 18: /* composto_decl: ABRE_CHAVES local_declaracoes statement_lista FECHA_CHAVES  */
#line 98 "bison.y"
    { (yyval.nodeValue) = newASTNode("composto_decl"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); }
#line 1303 "bison.tab.c"
    break;

  case 19: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 102 "bison.y"
    { (yyval.nodeValue) = newASTNode("local_declaracoes"); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1309 "bison.tab.c"
    break;

  case 20: /* local_declaracoes: %empty  */
#line 104 "bison.y"
    { (yyval.nodeValue) = NULL; }
#line 1315 "bison.tab.c"
    break;

  case 21: /* statement_lista: statement_lista statement  */
#line 108 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement_lista"); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1321 "bison.tab.c"
    break;

  case 22: /* statement_lista: %empty  */
#line 110 "bison.y"
    { (yyval.nodeValue) = NULL; }
#line 1327 "bison.tab.c"
    break;

  case 23: /* statement: expressao_decl  */
#line 114 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1333 "bison.tab.c"
    break;

  case 24: /* statement: composto_decl  */
#line 116 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1339 "bison.tab.c"
    break;

  case 25: /* statement: selecao_decl  */
#line 118 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1345 "bison.tab.c"
    break;

  case 26: /* statement: iteracao_decl  */
#line 120 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1351 "bison.tab.c"
    break;

  case 27: /* statement: retorno_decl  */
#line 122 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1357 "bison.tab.c"
    break;

  case 28: /* expressao_decl: expressao PONTO_VIRGULA  */
#line 126 "bison.y"
    { (yyval.nodeValue) = newASTNode("expressao_decl"); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); }
#line 1363 "bison.tab.c"
    break;

  case 29: /* expressao_decl: PONTO_VIRGULA  */
#line 128 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("expressao_decl", ";"); }
#line 1369 "bison.tab.c"
    break;

  case 30: /* selecao_decl: IF ABRE_PARENTESE expressao FECHA_PARENTESE statement selecao_decl_else  */
#line 132 "bison.y"
    { (yyval.nodeValue) = newASTNode("If"); addASTNode((yyval.nodeValue), (yyvsp[-3].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1375 "bison.tab.c"
    break;

  case 31: /* selecao_decl_else: ELSE statement  */
#line 136 "bison.y"
    { (yyval.nodeValue) = newASTNode("Else"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1381 "bison.tab.c"
    break;

  case 32: /* selecao_decl_else: %empty  */
#line 138 "bison.y"
    { (yyval.nodeValue) = NULL; }
#line 1387 "bison.tab.c"
    break;

  case 33: /* iteracao_decl: WHILE ABRE_PARENTESE expressao FECHA_PARENTESE statement  */
#line 142 "bison.y"
    { (yyval.nodeValue) = newASTNode("iteracao_decl"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1393 "bison.tab.c"
    break;

  case 34: /* retorno_decl: RETURN PONTO_VIRGULA  */
#line 146 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("retorno_decl", "return"); }
#line 1399 "bison.tab.c"
    break;

  case 35: /* retorno_decl: RETURN expressao PONTO_VIRGULA  */
#line 148 "bison.y"
    { (yyval.nodeValue) = newASTNode("retorno_decl"); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); }
#line 1405 "bison.tab.c"
    break;

  case 36: /* expressao: var ATRIBUICAO expressao  */
#line 152 "bison.y"
    { (yyval.nodeValue) = newASTNode("expressao"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1411 "bison.tab.c"
    break;

  case 38: /* var: ID  */
#line 157 "bison.y"
    { (yyval.nodeValue) = newASTNode("var"); addASTNode((yyval.nodeValue), newASTNodeValue("ID", (yyvsp[0].stringValue))); }
#line 1417 "bison.tab.c"
    break;

  case 39: /* var: ID ABRE_COLCHETE expressao FECHA_COLCHETE  */
#line 159 "bison.y"
    { (yyval.nodeValue) = newASTNode("var"); addASTNode((yyval.nodeValue), newASTNodeValue("ID", (yyvsp[-3].stringValue))); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); }
#line 1423 "bison.tab.c"
    break;

  case 40: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 163 "bison.y"
    { (yyval.nodeValue) = newASTNode("simples_expressao"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1429 "bison.tab.c"
    break;

  case 42: /* relacional: MENOR_IGUAL  */
#line 168 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", "<="); }
#line 1435 "bison.tab.c"
    break;

  case 43: /* relacional: MENOR  */
#line 170 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", "<"); }
#line 1441 "bison.tab.c"
    break;

  case 44: /* relacional: MAIOR  */
#line 172 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", ">"); }
#line 1447 "bison.tab.c"
    break;

  case 45: /* relacional: MAIOR_IGUAL  */
#line 174 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", ">="); }
#line 1453 "bison.tab.c"
    break;

  case 46: /* relacional: IGUAL  */
#line 176 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", "=="); }
#line 1459 "bison.tab.c"
    break;

  case 47: /* relacional: DIFERENTE  */
#line 178 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", "!="); }
#line 1465 "bison.tab.c"
    break;

  case 48: /* soma_expressao: soma_expressao SOMA termo  */
#line 182 "bison.y"
    { (yyval.nodeValue) = newASTNode("Soma"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1471 "bison.tab.c"
    break;

  case 49: /* soma_expressao: soma_expressao SUBTRACAO termo  */
#line 184 "bison.y"
    { (yyval.nodeValue) = newASTNode("Sub"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1477 "bison.tab.c"
    break;

  case 51: /* termo: termo MULTIPLICACAO fator  */
#line 189 "bison.y"
    { (yyval.nodeValue) = newASTNode("Mult"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1483 "bison.tab.c"
    break;

  case 52: /* termo: termo DIVISAO fator  */
#line 191 "bison.y"
    { (yyval.nodeValue) = newASTNode("Div"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1489 "bison.tab.c"
    break;

  case 54: /* fator: ABRE_PARENTESE expressao FECHA_PARENTESE  */
#line 196 "bison.y"
    { (yyval.nodeValue) = newASTNode("fator"); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); }
#line 1495 "bison.tab.c"
    break;

  case 57: /* fator: NUMERO  */
#line 200 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("fator", (yyvsp[0].stringValue)); }
#line 1501 "bison.tab.c"
    break;

  case 58: /* ativacao: ID ABRE_PARENTESE args FECHA_PARENTESE  */
#line 204 "bison.y"
    { (yyval.nodeValue) = newASTNode("ativacao"); addASTNode((yyval.nodeValue), newASTNodeValue("ID", (yyvsp[-3].stringValue))); addASTNode((yyval.nodeValue), (yyvsp[-1].nodeValue)); }
#line 1507 "bison.tab.c"
    break;

  case 59: /* args: arg_lista  */
#line 208 "bison.y"
    { (yyval.nodeValue) = newASTNode("args"); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1513 "bison.tab.c"
    break;

  case 60: /* args: %empty  */
#line 210 "bison.y"
    { (yyval.nodeValue) = NULL; }
#line 1519 "bison.tab.c"
    break;

  case 61: /* arg_lista: arg_lista VIRGULA expressao  */
#line 214 "bison.y"
    { (yyval.nodeValue) = newASTNode("arg_lista"); addASTNode((yyval.nodeValue), (yyvsp[-2].nodeValue)); addASTNode((yyval.nodeValue), (yyvsp[0].nodeValue)); }
#line 1525 "bison.tab.c"
    break;


#line 1529 "bison.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 217 "bison.y"


int yyerror(char *s) {
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
    fprintf(stderr, "Unexpected token at position: %d\n", buffer->charposition);
    return 0;
}

int yylex(void) {
    if (buffer == NULL)
    {
        allocate_buffer(&buffer);
    }
    
    if (openned == 0)
    {
        fp = fopen("teste.txt", "r");
        openned = 1;
    }

    char c;
    int flag = 1;
    int tokentype;
    int tabela[28][19] = {
        { 3, 1, 4, 5, 6, 7, 8,22,21,15,16,19,20,17,18,12,11,21, 0},
        {-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        { 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 4},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 6},
        {-1,-1,-1,-1,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 7},
        {-1,-1,-1,-1,-1,-1, 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 8},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 9},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10},
        {-1,-1,-1,-1,-1,-1,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11},
        {-1,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,17},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22},
        {23,23,23,23,26,27,23,23,23,23,23,23,23,23,23,23,23,23,23},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,24},
        {23,23,23,23,23,26,23,23,23,23,23,23,23,23,23,23,23,23,25},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,26},
        {23,23,23,23,-1,23,23,23,23,23,23,23,23,23,23,23,23,23,27}};
    do{
        flag = get_next_lexema_tabela(lex, buffer, fp, tabela, ht);
        lex->token_type = Get_Token_Type(lex->token);
        tokentype = lex->token_type;
        yylineno = lex->line;
    }while(flag == 1 && tokentype == 285);

    if (flag == -1)
    {
        yyerror (YY_("lexical error"));
        return 256;
    }
    else if (flag == 0)
    {
        return 0;
    }

    yylineno = lex->line;
    if (tokentype == 258)
    {
        yylval.intValue = *(lex->item) - '0';
    }
    strcpy(yytext, lex->item);

    return tokentype;
}

int main(void) {
    allocate_lexema(&lex);
    Tabela_Inicia(ht, MAX);

    // Inserting reserved words into the hash table
    int Char_Value;
    Char_Value = Get_Char_Value("if");
    Insere_Hash(Char_Value, "IF", ht, MAX);
    Char_Value = Get_Char_Value("else");
    Insere_Hash(Char_Value, "ELSE", ht, MAX);
    Char_Value = Get_Char_Value("while");
    Insere_Hash(Char_Value, "WHILE", ht, MAX);
    Char_Value = Get_Char_Value("return");
    Insere_Hash(Char_Value, "RETURN", ht, MAX);
    Char_Value = Get_Char_Value("int");
    Insere_Hash(Char_Value, "INT", ht, MAX);
    Char_Value = Get_Char_Value("void");
    Insere_Hash(Char_Value, "VOID", ht, MAX);

    yyparse();
    printAST(root, 0);
    //semanticAnalysis(root, &TabelaSimbolos);
    deallocate_lexema(lex);
    deallocate_buffer(buffer);
    Deallocate_Tabela(ht, MAX);
    return 0;
}
