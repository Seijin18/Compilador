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
#include <unistd.h>

FILE *fp;
Bloco *buffer = NULL;
Lex *lex;

int openned = 0;
int yylineno;
int valyy;
char yytext[64];


AASNode *root;
SimbCell simbTable[MAX];

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
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_COMP = 11,                      /* COMP  */
  YYSYMBOL_DIF = 12,                       /* DIF  */
  YYSYMBOL_GT = 13,                        /* GT  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_SOMA = 17,                      /* SOMA  */
  YYSYMBOL_SUB = 18,                       /* SUB  */
  YYSYMBOL_MULT = 19,                      /* MULT  */
  YYSYMBOL_DIV = 20,                       /* DIV  */
  YYSYMBOL_ATR = 21,                       /* ATR  */
  YYSYMBOL_PTV = 22,                       /* PTV  */
  YYSYMBOL_VIR = 23,                       /* VIR  */
  YYSYMBOL_APAR = 24,                      /* APAR  */
  YYSYMBOL_FPAR = 25,                      /* FPAR  */
  YYSYMBOL_ACOL = 26,                      /* ACOL  */
  YYSYMBOL_FCOL = 27,                      /* FCOL  */
  YYSYMBOL_ACHV = 28,                      /* ACHV  */
  YYSYMBOL_FCHV = 29,                      /* FCHV  */
  YYSYMBOL_CMT = 30,                       /* CMT  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_programa = 32,                  /* programa  */
  YYSYMBOL_declaracao_lista = 33,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 34,                /* declaracao  */
  YYSYMBOL_var_declaracao = 35,            /* var_declaracao  */
  YYSYMBOL_tipo_especificador = 36,        /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 37,            /* fun_declaracao  */
  YYSYMBOL_params = 38,                    /* params  */
  YYSYMBOL_param_lista = 39,               /* param_lista  */
  YYSYMBOL_param = 40,                     /* param  */
  YYSYMBOL_composto_decl = 41,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 42,         /* local_declaracoes  */
  YYSYMBOL_statement_lista = 43,           /* statement_lista  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_expressao_decl = 45,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 46,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 47,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 48,              /* retorno_decl  */
  YYSYMBOL_expressao = 49,                 /* expressao  */
  YYSYMBOL_var = 50,                       /* var  */
  YYSYMBOL_simples_expressao = 51,         /* simples_expressao  */
  YYSYMBOL_relacional = 52,                /* relacional  */
  YYSYMBOL_soma_expressao = 53,            /* soma_expressao  */
  YYSYMBOL_aditivo = 54,                   /* aditivo  */
  YYSYMBOL_termo = 55,                     /* termo  */
  YYSYMBOL_operador_multiplicativo = 56,   /* operador_multiplicativo  */
  YYSYMBOL_fator = 57,                     /* fator  */
  YYSYMBOL_ativacao = 58,                  /* ativacao  */
  YYSYMBOL_args = 59,                      /* args  */
  YYSYMBOL_arg_lista = 60,                 /* arg_lista  */
  YYSYMBOL_id = 61,                        /* id  */
  YYSYMBOL_num = 62                        /* num  */
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
#define YYLAST   103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    56,    60,    63,    64,    67,    77,    90,
      94,   100,   116,   117,   120,   124,   127,   136,   146,   156,
     164,   167,   175,   178,   179,   180,   181,   182,   185,   186,
     189,   194,   202,   209,   213,   220,   226,   231,   232,   240,
     246,   252,   253,   254,   255,   256,   257,   260,   265,   270,
     271,   274,   279,   284,   285,   288,   289,   290,   291,   294,
     302,   311,   314,   322,   327,   335
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "IF",
  "ELSE", "WHILE", "INT", "RETURN", "VOID", "COMP", "DIF", "GT", "LT",
  "GE", "LE", "SOMA", "SUB", "MULT", "DIV", "ATR", "PTV", "VIR", "APAR",
  "FPAR", "ACOL", "FCOL", "ACHV", "FCHV", "CMT", "$accept", "programa",
  "declaracao_lista", "declaracao", "var_declaracao", "tipo_especificador",
  "fun_declaracao", "params", "param_lista", "param", "composto_decl",
  "local_declaracoes", "statement_lista", "statement", "expressao_decl",
  "selecao_decl", "iteracao_decl", "retorno_decl", "expressao", "var",
  "simples_expressao", "relacional", "soma_expressao", "aditivo", "termo",
  "operador_multiplicativo", "fator", "ativacao", "args", "arg_lista",
  "id", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      51,   -52,   -52,    15,    51,   -52,   -52,    19,   -52,   -52,
     -52,   -52,   -16,   -52,    63,    27,    11,    19,    21,    54,
     -52,   -52,    53,    28,    50,    51,    57,    55,   -52,   -52,
     -52,   -52,   -52,    51,   -52,    19,     9,    -5,    59,    60,
      31,   -52,    38,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      64,    66,   -52,    52,    30,   -52,   -52,    48,   -52,    38,
      38,   -52,    67,    56,   -52,    38,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,    38,    38,   -52,   -52,    38,    23,
      38,    65,    68,   -52,   -52,   -52,   -52,    58,    30,   -52,
     -52,   -52,    69,    62,    61,     0,     0,   -52,    38,   -52,
      85,   -52,   -52,     0,   -52
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    64,     0,     7,     0,     0,    10,     0,     0,    12,
      15,    65,     0,    16,     0,     0,     0,     0,    20,    11,
      14,     8,    17,    22,    19,     0,     0,     0,     0,     0,
       0,    29,     0,    18,    24,    21,    23,    25,    26,    27,
       0,    56,    36,    40,    48,    52,    57,    37,    58,     0,
       0,    33,     0,     0,    28,     0,    45,    46,    43,    42,
      44,    41,    49,    50,     0,     0,    53,    54,     0,     0,
       0,     0,     0,    34,    55,    35,    56,    39,    47,    51,
      60,    63,     0,    61,     0,     0,     0,    59,     0,    38,
      30,    32,    62,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,    88,    70,    18,   -52,   -52,   -52,    71,
      73,   -52,   -52,   -51,   -52,   -52,   -52,   -52,   -40,   -18,
     -52,   -52,    24,   -52,    20,   -52,    22,   -52,   -52,   -52,
      -6,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      44,    33,    36,    45,    46,    47,    48,    49,    50,    51,
      52,    74,    53,    75,    54,    78,    55,    56,    92,    93,
      57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    12,    63,    21,    11,    38,    13,    39,    14,    40,
      15,    23,    21,    11,    38,     9,    39,    13,    40,    81,
      82,    15,    41,    11,    42,    85,    21,    11,    28,    37,
      21,    41,    17,    42,    21,    11,   -13,    28,    43,    91,
      94,    21,    11,    17,   100,   101,    24,    42,    90,    76,
      77,    35,   104,    61,    27,    42,    86,    86,   102,     1,
      86,     2,    42,    66,    67,    68,    69,    70,    71,    72,
      73,     1,    79,    16,    80,    72,    73,    25,    28,    31,
      26,    84,    32,    59,    60,    98,    64,    65,    99,    83,
      95,   103,    10,    96,    97,    88,    30,    29,    87,    22,
      89,     0,     0,    34
};

static const yytype_int8 yycheck[] =
{
      40,     7,    42,     3,     4,     5,    22,     7,    24,     9,
      26,    17,     3,     4,     5,     0,     7,    22,     9,    59,
      60,    26,    22,     4,    24,    65,     3,     4,    28,    35,
       3,    22,    14,    24,     3,     4,    25,    28,    29,    79,
      80,     3,     4,    25,    95,    96,    25,    24,    25,    19,
      20,    33,   103,    22,    26,    24,    74,    75,    98,     8,
      78,    10,    24,    11,    12,    13,    14,    15,    16,    17,
      18,     8,    24,    10,    26,    17,    18,    23,    28,    22,
      27,    25,    27,    24,    24,    23,    22,    21,    27,    22,
      25,     6,     4,    25,    25,    75,    25,    24,    74,    15,
      78,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    32,    33,    34,    35,    36,    37,     0,
      34,     4,    61,    22,    24,    26,    10,    36,    38,    39,
      40,     3,    62,    61,    25,    23,    27,    26,    28,    41,
      40,    22,    27,    42,    35,    36,    43,    61,     5,     7,
       9,    22,    24,    29,    41,    44,    45,    46,    47,    48,
      49,    50,    51,    53,    55,    57,    58,    61,    62,    24,
      24,    22,    49,    49,    22,    21,    11,    12,    13,    14,
      15,    16,    17,    18,    52,    54,    19,    20,    56,    24,
      26,    49,    49,    22,    25,    49,    50,    53,    55,    57,
      25,    49,    59,    60,    49,    25,    25,    25,    23,    27,
      44,    44,    49,     6,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    35,    36,
      36,    37,    38,    38,    39,    39,    40,    40,    41,    42,
      42,    43,    43,    44,    44,    44,    44,    44,    45,    45,
      46,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    57,    57,    58,
      58,    59,    60,    60,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       3,     1,     3,     1,     1,     1
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
#line 50 "bison.y"
                           { 
            root = newAASNodeStmt(KProg);
            addAASNode(root, (yyvsp[0].node));
        }
#line 1221 "bison.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 56 "bison.y"
                                              {
                    (yyval.node) = (yyvsp[-1].node);
                    addAASNodeSibling((yyval.node), (yyvsp[0].node));
                }
#line 1230 "bison.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 60 "bison.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1236 "bison.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 63 "bison.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1242 "bison.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 64 "bison.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1248 "bison.tab.c"
    break;

  case 7: /* var_declaracao: tipo_especificador id PTV  */
#line 67 "bison.y"
                                          {
                    (yyval.node) = (yyvsp[-2].node);
                    (yyvsp[-1].node)->type = (yyvsp[-2].node)->type;
                    addAASNode((yyval.node), newAASNodeStmt(KVar));
                    (yyval.node)->children->line = (yyvsp[-1].node)->line;
                    (yyval.node)->children->type = (yyvsp[-2].node)->type;
                    (yyval.node)->children->name = copyString((yyvsp[-1].node)->name);
                    (yyval.node)->children->escopo = copyString("global");

                }
#line 1263 "bison.tab.c"
    break;

  case 8: /* var_declaracao: tipo_especificador id ACOL num FCOL PTV  */
#line 77 "bison.y"
                                                          {
                    (yyval.node) = (yyvsp[-5].node);
                    (yyvsp[-4].node)->type = (yyvsp[-5].node)->type;
                    addAASNode((yyval.node), newAASNodeStmt(KVet));
                    (yyval.node)->children->line = (yyvsp[-4].node)->line;
                    (yyval.node)->children->type = (yyvsp[-5].node)->type;
                    (yyval.node)->children->name = copyString((yyvsp[-4].node)->name);
                    (yyval.node)->children->escopo = copyString("global");
                    addAASNode((yyval.node)->children, (yyvsp[-4].node)); 
                    addAASNode((yyval.node)->children, (yyvsp[-2].node));
                }
#line 1279 "bison.tab.c"
    break;

  case 9: /* tipo_especificador: INT  */
#line 90 "bison.y"
                        { 
                        (yyval.node) = newAASNodeExp(KType); 
                        (yyval.node)->type = KInt; 
                        }
#line 1288 "bison.tab.c"
    break;

  case 10: /* tipo_especificador: VOID  */
#line 94 "bison.y"
                           {
                        (yyval.node) = newAASNodeExp(KType);
                        (yyval.node)->type = KVoid;
                    }
#line 1297 "bison.tab.c"
    break;

  case 11: /* fun_declaracao: tipo_especificador id APAR params FPAR composto_decl  */
#line 100 "bison.y"
                                                                     {
        (yyval.node) = (yyvsp[-5].node);
        (yyvsp[-4].node)->type = (yyvsp[-5].node)->type;
        addAASNode((yyval.node), newAASNodeStmt(KFunc));
        (yyval.node)->children->line = (yyvsp[-4].node)->line;
        (yyval.node)->children->type = (yyvsp[-5].node)->type;
        (yyval.node)->children->name = copyString((yyvsp[-4].node)->name);
        printf("Funcao: %s\n", (yyval.node)->children->name);
        (yyval.node)->children->escopo = copyString("global");
        updateEscopo((yyvsp[-2].node), (yyval.node)->children->name);
        updateEscopo((yyvsp[0].node), (yyval.node)->children->name);
        addAASNode((yyval.node)->children, (yyvsp[-2].node));
        addAASNode((yyval.node)->children, (yyvsp[0].node));
}
#line 1316 "bison.tab.c"
    break;

  case 12: /* params: param_lista  */
#line 116 "bison.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1322 "bison.tab.c"
    break;

  case 13: /* params: VOID  */
#line 117 "bison.y"
           { (yyval.node) = NULL; }
#line 1328 "bison.tab.c"
    break;

  case 14: /* param_lista: param_lista VIR param  */
#line 120 "bison.y"
                                   { 
        (yyval.node) = (yyvsp[-2].node);
        addAASNodeSibling((yyval.node), (yyvsp[0].node));
    }
#line 1337 "bison.tab.c"
    break;

  case 15: /* param_lista: param  */
#line 124 "bison.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1343 "bison.tab.c"
    break;

  case 16: /* param: tipo_especificador id  */
#line 127 "bison.y"
                             {
        (yyval.node) = (yyvsp[-1].node);
        (yyvsp[0].node)->type = (yyvsp[-1].node)->type;
        addAASNode((yyval.node), newAASNodeStmt(KVar));
        (yyval.node)->children->line = (yyvsp[0].node)->line;
        (yyval.node)->children->type = (yyvsp[-1].node)->type;
        (yyval.node)->children->name = copyString((yyvsp[0].node)->name);

    }
#line 1357 "bison.tab.c"
    break;

  case 17: /* param: tipo_especificador id ACOL FCOL  */
#line 136 "bison.y"
                                      {
        (yyval.node) = (yyvsp[-3].node);
        (yyvsp[-2].node)->type = (yyvsp[-3].node)->type;
        addAASNode((yyval.node), newAASNodeStmt(KVet));
        (yyval.node)->children->line = (yyvsp[-2].node)->line;
        (yyval.node)->children->type = (yyvsp[-3].node)->type;
        (yyval.node)->children->name = copyString((yyvsp[-2].node)->name);
    }
#line 1370 "bison.tab.c"
    break;

  case 18: /* composto_decl: ACHV local_declaracoes statement_lista FCHV  */
#line 146 "bison.y"
                                                           {
        if ((yyvsp[-2].node) != NULL) {
            (yyval.node) = (yyvsp[-2].node);
            addAASNodeSibling((yyval.node), (yyvsp[-1].node));
        } else {
            (yyval.node) = (yyvsp[-1].node);
        }
    }
#line 1383 "bison.tab.c"
    break;

  case 19: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 156 "bison.y"
                                                    {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
            addAASNodeSibling((yyval.node), (yyvsp[0].node));
        }
    }
#line 1396 "bison.tab.c"
    break;

  case 20: /* local_declaracoes: %empty  */
#line 164 "bison.y"
      { (yyval.node) = NULL; }
#line 1402 "bison.tab.c"
    break;

  case 21: /* statement_lista: statement_lista statement  */
#line 167 "bison.y"
                                           {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
            addAASNodeSibling((yyval.node), (yyvsp[0].node));
        }
    }
#line 1415 "bison.tab.c"
    break;

  case 22: /* statement_lista: %empty  */
#line 175 "bison.y"
      { (yyval.node) = NULL; }
#line 1421 "bison.tab.c"
    break;

  case 23: /* statement: expressao_decl  */
#line 178 "bison.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1427 "bison.tab.c"
    break;

  case 24: /* statement: composto_decl  */
#line 179 "bison.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1433 "bison.tab.c"
    break;

  case 25: /* statement: selecao_decl  */
#line 180 "bison.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1439 "bison.tab.c"
    break;

  case 26: /* statement: iteracao_decl  */
#line 181 "bison.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1445 "bison.tab.c"
    break;

  case 27: /* statement: retorno_decl  */
#line 182 "bison.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1451 "bison.tab.c"
    break;

  case 28: /* expressao_decl: expressao PTV  */
#line 185 "bison.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1457 "bison.tab.c"
    break;

  case 29: /* expressao_decl: PTV  */
#line 186 "bison.y"
          { (yyval.node) = NULL; }
#line 1463 "bison.tab.c"
    break;

  case 30: /* selecao_decl: IF APAR expressao FPAR statement  */
#line 189 "bison.y"
                                               {
        (yyval.node) = newAASNodeStmt(KIf);
        addAASNode((yyval.node), (yyvsp[-2].node));
        addAASNode((yyval.node), (yyvsp[0].node));
    }
#line 1473 "bison.tab.c"
    break;

  case 31: /* selecao_decl: IF APAR expressao FPAR statement ELSE statement  */
#line 194 "bison.y"
                                                      {
        (yyval.node) = newAASNodeStmt(KIf);
        addAASNode((yyval.node), (yyvsp[-4].node));
        addAASNode((yyval.node), (yyvsp[-2].node));
        addAASNode((yyval.node), (yyvsp[0].node));
    }
#line 1484 "bison.tab.c"
    break;

  case 32: /* iteracao_decl: WHILE APAR expressao FPAR statement  */
#line 202 "bison.y"
                                                  {
        (yyval.node) = newAASNodeStmt(KWhile);
        addAASNode((yyval.node), (yyvsp[-2].node));
        addAASNode((yyval.node), (yyvsp[0].node));
    }
#line 1494 "bison.tab.c"
    break;

  case 33: /* retorno_decl: RETURN PTV  */
#line 209 "bison.y"
                         { 
        (yyval.node) = newAASNodeStmt(KReturn);
        (yyval.node)->type = KVoid;
    }
#line 1503 "bison.tab.c"
    break;

  case 34: /* retorno_decl: RETURN expressao PTV  */
#line 213 "bison.y"
                           {
        (yyval.node) = newAASNodeStmt(KReturn);
        addAASNode((yyval.node), (yyvsp[-1].node));
    }
#line 1512 "bison.tab.c"
    break;

  case 35: /* expressao: var ATR expressao  */
#line 220 "bison.y"
                             {
        (yyval.node) = newAASNodeStmt(KAssign);
        (yyval.node)->type = (yyvsp[-2].node)->type;
        addAASNode((yyval.node), (yyvsp[-2].node));
        addAASNode((yyval.node), (yyvsp[0].node));
    }
#line 1523 "bison.tab.c"
    break;

  case 36: /* expressao: simples_expressao  */
#line 226 "bison.y"
                        {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1531 "bison.tab.c"
    break;

  case 37: /* var: id  */
#line 231 "bison.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1537 "bison.tab.c"
    break;

  case 38: /* var: id ACOL expressao FCOL  */
#line 232 "bison.y"
                             {
        (yyval.node) = newAASNodeExp(KVetId);
        (yyval.node)->type = (yyvsp[-3].node)->type;
        addAASNode((yyval.node), (yyvsp[-3].node));
        addAASNode((yyval.node), (yyvsp[-1].node));
    }
#line 1548 "bison.tab.c"
    break;

  case 39: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 240 "bison.y"
                                                            {
    (yyval.node) = (yyvsp[-1].node);
    (yyval.node)->type = KInt;
    addAASNode((yyval.node), (yyvsp[-2].node));
    addAASNode((yyval.node), (yyvsp[0].node));
}
#line 1559 "bison.tab.c"
    break;

  case 40: /* simples_expressao: soma_expressao  */
#line 246 "bison.y"
                     {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1567 "bison.tab.c"
    break;

  case 41: /* relacional: LE  */
#line 252 "bison.y"
               { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = LE; }
#line 1573 "bison.tab.c"
    break;

  case 42: /* relacional: LT  */
#line 253 "bison.y"
         { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = LT; }
#line 1579 "bison.tab.c"
    break;

  case 43: /* relacional: GT  */
#line 254 "bison.y"
         { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = GT; }
#line 1585 "bison.tab.c"
    break;

  case 44: /* relacional: GE  */
#line 255 "bison.y"
         { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = GE; }
#line 1591 "bison.tab.c"
    break;

  case 45: /* relacional: COMP  */
#line 256 "bison.y"
           { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = COMP; }
#line 1597 "bison.tab.c"
    break;

  case 46: /* relacional: DIF  */
#line 257 "bison.y"
          { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = DIF; }
#line 1603 "bison.tab.c"
    break;

  case 47: /* soma_expressao: soma_expressao aditivo termo  */
#line 260 "bison.y"
                                             {
    (yyval.node) = (yyvsp[-1].node);
    addAASNode((yyval.node), (yyvsp[-2].node));
    addAASNode((yyval.node), (yyvsp[0].node));
}
#line 1613 "bison.tab.c"
    break;

  case 48: /* soma_expressao: termo  */
#line 265 "bison.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1621 "bison.tab.c"
    break;

  case 49: /* aditivo: SOMA  */
#line 270 "bison.y"
              { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = SOMA; (yyval.node)->type = KInt; }
#line 1627 "bison.tab.c"
    break;

  case 50: /* aditivo: SUB  */
#line 271 "bison.y"
             { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = SUB; (yyval.node)->type = KInt; }
#line 1633 "bison.tab.c"
    break;

  case 51: /* termo: termo operador_multiplicativo fator  */
#line 274 "bison.y"
                                           {
    (yyval.node) = (yyvsp[-1].node);
    addAASNode((yyval.node), (yyvsp[-2].node));
    addAASNode((yyval.node), (yyvsp[0].node));
}
#line 1643 "bison.tab.c"
    break;

  case 52: /* termo: fator  */
#line 279 "bison.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1651 "bison.tab.c"
    break;

  case 53: /* operador_multiplicativo: MULT  */
#line 284 "bison.y"
                              { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = MULT; (yyval.node)->type = KInt; }
#line 1657 "bison.tab.c"
    break;

  case 54: /* operador_multiplicativo: DIV  */
#line 285 "bison.y"
                             { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = DIV; (yyval.node)->type = KInt; }
#line 1663 "bison.tab.c"
    break;

  case 55: /* fator: APAR expressao FPAR  */
#line 288 "bison.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1669 "bison.tab.c"
    break;

  case 56: /* fator: var  */
#line 289 "bison.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1675 "bison.tab.c"
    break;

  case 57: /* fator: ativacao  */
#line 290 "bison.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1681 "bison.tab.c"
    break;

  case 58: /* fator: num  */
#line 291 "bison.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1687 "bison.tab.c"
    break;

  case 59: /* ativacao: id APAR args FPAR  */
#line 294 "bison.y"
                            {
        (yyval.node) = newAASNodeStmt(KCall);
        (yyval.node)->type = (yyvsp[-3].node)->type;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString((yyvsp[-3].node)->name);
        addAASNode((yyval.node), (yyvsp[-1].node));
    }
#line 1700 "bison.tab.c"
    break;

  case 60: /* ativacao: id APAR FPAR  */
#line 302 "bison.y"
                   {
        (yyval.node) = newAASNodeStmt(KCall);
        (yyval.node)->type = (yyvsp[-2].node)->type;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString((yyvsp[-2].node)->name);
    }
#line 1712 "bison.tab.c"
    break;

  case 61: /* args: arg_lista  */
#line 311 "bison.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1718 "bison.tab.c"
    break;

  case 62: /* arg_lista: arg_lista VIR expressao  */
#line 314 "bison.y"
                                   {
        if ((yyvsp[-2].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-2].node);
            addAASNodeSibling((yyval.node), (yyvsp[0].node));
        }
    }
#line 1731 "bison.tab.c"
    break;

  case 63: /* arg_lista: expressao  */
#line 322 "bison.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1739 "bison.tab.c"
    break;

  case 64: /* id: ID  */
#line 327 "bison.y"
       {
        (yyval.node) = newAASNodeExp(KId);
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString(lex->lexema);
    }
#line 1750 "bison.tab.c"
    break;

  case 65: /* num: NUM  */
#line 335 "bison.y"
         {
        (yyval.node) = newAASNodeExp(KConst);
        (yyval.node)->value = atoi(lex->lexema);
        (yyval.node)->type = KInt;
        (yyval.node)->line = lex->line;
        (yyval.node)->token = lex->token;
    }
#line 1762 "bison.tab.c"
    break;


#line 1766 "bison.tab.c"

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

#line 343 "bison.y"

int yyerror(char *s) {
    if (lex->token == ER) {
        printf("%s '%s' INVALIDO [linha: %d, coluna: %d]\n", s, lex->lexema, lex->line + 1, lex->column);
    } else {
        printf("%s '%s' INVALIDO [linha: %d]\n", s, lex->lexema, lex->line + 1);
    }
    return 0;
}

int yylex(void) {
    int token;

    do {
        token = get_lexema(buffer, lex, fp);
        if (token == ER) {
            yyerror("ERRO LEXICO:");
            return ER;
        }
    } while (token == CMT);
    strcpy(yytext, lex->lexema);
    yylineno = lex->line;
    if (token == NUM) {
        yylval.intValue = atoi(lex->lexema);
    }
    // printf("\nLexema: %s\nToken: %d\n", lex->lexema, lex->token);
    return token;
}

int main(int argc, char *argv[]) {
    int option = -1;
    
    /*
    yydebug = 1;

    FILE *debug_file = fopen("debug_log.txt", "w");
    if (debug_file == NULL) {
        perror("Failed to open debug log file");
        return EXIT_FAILURE;
    }

    // Redirect stderr to the debug file
    if (dup2(fileno(debug_file), fileno(stderr)) == -1) {
        perror("Failed to redirect stderr");
        fclose(debug_file);
        return EXIT_FAILURE;
    }*/

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    for(int i = 0; i < argc; i++) { // Seleciona opção entre -l, -p e -s
        if(argv[i][0] == '-') {
            if (argv[i][1] == 'l' || argv[i][1] == 'L') {
                option = 0;
            } else if (argv[i][1] == 'p' || argv[i][1] == 'P') {
                option = 1;
            } else if (argv[i][1] == 's' || argv[i][1] == 'S') {
                option = 2;
            }
            else {
                printf("Invalid option\n");
                return 1;
            }
        }
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    /*Inicialização do buffer*/
    int buffer_size = 20; 
    buffer = allocate_buffer(buffer_size);
    if (buffer == NULL) {
        return 1;
    }

    /*Inicialização do lex*/
    lex = allocate_lex();
    int token;
    char *token_name;
    
    if (option == 0) { // Análise léxica
        do{
            token = yylex();
            token_name = get_token_name(token);
            if (token == ER) {
                break;
            }
            else {
                printf("%s\t'%s' \t[linha: %d]\n", token_name, lex->lexema, lex->line + 1);
            }
            
        } while (token != EOF && token != ER);
    } else if (option == 1) { // Análise sintática
        yyparse();
        printAAS(root, 0);
    } else if (option == 2) { // Análise semântica
        yyparse();
        if (root == NULL) {
            printf("Erro na análise sintática\n");
            return 1;
        }
        else {
            buildTabSimb(simbTable, root);
        }
    }

    fclose(fp);
    deallocate_buffer(buffer);
    deallocate_lex(lex);
    deallocateAAS(root);

    // fclose(debug_file);
    return 0;
}
