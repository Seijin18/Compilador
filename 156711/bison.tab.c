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
#include "intermediate.h"
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


#line 98 "bison.tab.c"

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
  YYSYMBOL_INPUT = 31,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 32,                    /* OUTPUT  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_programa = 34,                  /* programa  */
  YYSYMBOL_declaracao_lista = 35,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 36,                /* declaracao  */
  YYSYMBOL_var_declaracao = 37,            /* var_declaracao  */
  YYSYMBOL_tipo_especificador = 38,        /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 39,            /* fun_declaracao  */
  YYSYMBOL_params = 40,                    /* params  */
  YYSYMBOL_param_lista = 41,               /* param_lista  */
  YYSYMBOL_param = 42,                     /* param  */
  YYSYMBOL_composto_decl = 43,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 44,         /* local_declaracoes  */
  YYSYMBOL_statement_lista = 45,           /* statement_lista  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_input_stmt = 47,                /* input_stmt  */
  YYSYMBOL_output_stmt = 48,               /* output_stmt  */
  YYSYMBOL_expressao_decl = 49,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 50,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 51,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 52,              /* retorno_decl  */
  YYSYMBOL_expressao = 53,                 /* expressao  */
  YYSYMBOL_var = 54,                       /* var  */
  YYSYMBOL_simples_expressao = 55,         /* simples_expressao  */
  YYSYMBOL_relacional = 56,                /* relacional  */
  YYSYMBOL_soma_expressao = 57,            /* soma_expressao  */
  YYSYMBOL_aditivo = 58,                   /* aditivo  */
  YYSYMBOL_termo = 59,                     /* termo  */
  YYSYMBOL_operador_multiplicativo = 60,   /* operador_multiplicativo  */
  YYSYMBOL_fator = 61,                     /* fator  */
  YYSYMBOL_ativacao = 62,                  /* ativacao  */
  YYSYMBOL_args = 63,                      /* args  */
  YYSYMBOL_arg_lista = 64,                 /* arg_lista  */
  YYSYMBOL_id = 65,                        /* id  */
  YYSYMBOL_num = 66                        /* num  */
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
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    58,    62,    65,    66,    69,    79,    93,
      97,   103,   119,   120,   123,   127,   130,   139,   150,   163,
     171,   174,   182,   185,   186,   187,   188,   189,   190,   191,
     194,   201,   208,   209,   212,   217,   225,   232,   238,   248,
     256,   261,   264,   275,   281,   287,   288,   289,   290,   291,
     292,   295,   300,   305,   306,   309,   314,   319,   320,   323,
     324,   325,   326,   329,   352,   375,   378,   386,   391,   401
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
  "FPAR", "ACOL", "FCOL", "ACHV", "FCHV", "CMT", "INPUT", "OUTPUT",
  "$accept", "programa", "declaracao_lista", "declaracao",
  "var_declaracao", "tipo_especificador", "fun_declaracao", "params",
  "param_lista", "param", "composto_decl", "local_declaracoes",
  "statement_lista", "statement", "input_stmt", "output_stmt",
  "expressao_decl", "selecao_decl", "iteracao_decl", "retorno_decl",
  "expressao", "var", "simples_expressao", "relacional", "soma_expressao",
  "aditivo", "termo", "operador_multiplicativo", "fator", "ativacao",
  "args", "arg_lista", "id", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -7,   -98,   -98,    12,    -7,   -98,   -98,    29,   -98,   -98,
     -98,   -98,    28,   -98,    47,    37,    31,    29,    42,    41,
     -98,   -98,    33,    36,    45,    -7,    63,    61,   -98,   -98,
     -98,   -98,   -98,    -7,   -98,    29,     6,    -4,    65,    68,
      17,   -98,    39,   -98,    69,    70,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,    73,    75,   -98,    66,    67,   -98,
     -98,    35,   -98,    39,    39,   -98,    76,    72,    29,    39,
     -98,    39,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
      39,    39,   -98,   -98,    39,     2,    39,    74,    77,   -98,
     -98,    78,    64,    79,   -98,   -98,    -1,    67,   -98,   -98,
     -98,    80,    83,    81,    44,    44,    85,    87,   -98,    39,
     -98,    94,   -98,   -98,   -98,   -98,    44,   -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    68,     0,     7,     0,     0,    10,     0,     0,    12,
      15,    69,     0,    16,     0,     0,     0,     0,    20,    11,
      14,     8,    17,    22,    19,     0,     0,     0,     0,     0,
       0,    33,     0,    18,     0,     0,    24,    21,    28,    29,
      23,    25,    26,    27,     0,    60,    40,    44,    52,    56,
      61,    41,    62,     0,     0,    37,     0,     0,     0,     0,
      32,     0,    49,    50,    47,    46,    48,    45,    53,    54,
       0,     0,    57,    58,     0,     0,     0,     0,     0,    38,
      59,     0,    41,     0,    39,    60,    43,    51,    55,    64,
      67,     0,    65,     0,     0,     0,     0,     0,    63,     0,
      42,    34,    36,    30,    31,    66,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -98,    97,    58,    11,   -98,   -98,   -98,    86,
      88,   -98,   -98,   -97,   -98,   -98,   -98,   -98,   -98,   -98,
     -40,   -10,   -98,   -98,    30,   -98,    32,   -98,    34,   -98,
     -98,   -98,    -3,    99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      46,    33,    36,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    80,    57,    81,    58,    84,    59,    60,
     101,   102,    61,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      66,     1,    67,     2,    12,    21,    11,   111,   112,    21,
      11,    38,     9,    39,    23,    40,    78,    79,    13,   117,
      21,    11,    15,    87,    88,    17,    42,    99,    41,    93,
      42,    94,    37,    11,    28,    43,    17,    44,    45,    65,
      21,    42,    21,    11,    35,   100,   103,    21,    11,    38,
      13,    39,    14,    40,    15,     1,   -13,    16,    91,    85,
      26,    86,    27,    42,    25,    92,    41,    24,    42,   115,
      95,    95,    28,    28,    95,    44,    45,    72,    73,    74,
      75,    76,    77,    78,    79,    31,    82,    83,    32,    63,
      86,    34,    64,    68,    69,    70,    71,    90,    89,   104,
     116,    10,   105,   106,   107,   108,   109,   113,   110,   114,
      96,    30,    29,    97,    22,     0,     0,     0,    98
};

static const yytype_int8 yycheck[] =
{
      40,     8,    42,    10,     7,     3,     4,   104,   105,     3,
       4,     5,     0,     7,    17,     9,    17,    18,    22,   116,
       3,     4,    26,    63,    64,    14,    24,    25,    22,    69,
      24,    71,    35,     4,    28,    29,    25,    31,    32,    22,
       3,    24,     3,     4,    33,    85,    86,     3,     4,     5,
      22,     7,    24,     9,    26,     8,    25,    10,    68,    24,
      27,    26,    26,    24,    23,    68,    22,    25,    24,   109,
      80,    81,    28,    28,    84,    31,    32,    11,    12,    13,
      14,    15,    16,    17,    18,    22,    19,    20,    27,    24,
      26,    33,    24,    24,    24,    22,    21,    25,    22,    25,
       6,     4,    25,    25,    25,    25,    23,    22,    27,    22,
      80,    25,    24,    81,    15,    -1,    -1,    -1,    84
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    34,    35,    36,    37,    38,    39,     0,
      36,     4,    65,    22,    24,    26,    10,    38,    40,    41,
      42,     3,    66,    65,    25,    23,    27,    26,    28,    43,
      42,    22,    27,    44,    37,    38,    45,    65,     5,     7,
       9,    22,    24,    29,    31,    32,    43,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    57,    59,    61,
      62,    65,    66,    24,    24,    22,    53,    53,    24,    24,
      22,    21,    11,    12,    13,    14,    15,    16,    17,    18,
      56,    58,    19,    20,    60,    24,    26,    53,    53,    22,
      25,    54,    65,    53,    53,    54,    57,    59,    61,    25,
      53,    63,    64,    53,    25,    25,    25,    25,    25,    23,
      27,    46,    46,    22,    22,    53,     6,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    37,    37,    38,
      38,    39,    40,    40,    41,    41,    42,    42,    43,    44,
      44,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      47,    48,    49,    49,    50,    50,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    62,    62,    63,    64,    64,    65,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     2,     1,     5,     7,     5,     2,     3,     3,
       1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     4,     3,     1,     3,     1,     1,     1
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
#line 52 "bison.y"
                           { 
            root = newAASNodeStmt(KProg);
            addAASNode(root, (yyvsp[0].node));
        }
#line 1232 "bison.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 58 "bison.y"
                                              {
                    (yyval.node) = (yyvsp[-1].node);
                    addAASNodeSibling((yyval.node), (yyvsp[0].node));
                }
#line 1241 "bison.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 62 "bison.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1247 "bison.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 65 "bison.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1253 "bison.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 66 "bison.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1259 "bison.tab.c"
    break;

  case 7: /* var_declaracao: tipo_especificador id PTV  */
#line 69 "bison.y"
                                          {
                    (yyval.node) = (yyvsp[-2].node);
                    (yyvsp[-1].node)->type = (yyvsp[-2].node)->type;
                    addAASNode((yyval.node), newAASNodeStmt(KVar));
                    (yyval.node)->children->line = (yyvsp[-1].node)->line;
                    (yyval.node)->children->type = (yyvsp[-2].node)->type;
                    (yyval.node)->children->name = copyString((yyvsp[-1].node)->name);
                    (yyval.node)->children->escopo = copyString("global");

                }
#line 1274 "bison.tab.c"
    break;

  case 8: /* var_declaracao: tipo_especificador id ACOL num FCOL PTV  */
#line 79 "bison.y"
                                                          {
                    (yyval.node) = (yyvsp[-5].node);
                    (yyvsp[-4].node)->type = (yyvsp[-5].node)->type;
                    addAASNode((yyval.node), newAASNodeStmt(KVet));
                    (yyval.node)->children->line = (yyvsp[-4].node)->line;
                    (yyval.node)->children->type = (yyvsp[-5].node)->type;
                    (yyval.node)->children->name = copyString((yyvsp[-4].node)->name);
                    (yyval.node)->children->escopo = copyString("global");
                    (yyval.node)->children->value = (yyvsp[-2].node)->value; // Definir o valor do array
                    addAASNode((yyval.node)->children, (yyvsp[-4].node)); 
                    addAASNode((yyval.node)->children, (yyvsp[-2].node));
                }
#line 1291 "bison.tab.c"
    break;

  case 9: /* tipo_especificador: INT  */
#line 93 "bison.y"
                        { 
                        (yyval.node) = newAASNodeExp(KType); 
                        (yyval.node)->type = KInt; 
                        }
#line 1300 "bison.tab.c"
    break;

  case 10: /* tipo_especificador: VOID  */
#line 97 "bison.y"
                           {
                        (yyval.node) = newAASNodeExp(KType);
                        (yyval.node)->type = KVoid;
                    }
#line 1309 "bison.tab.c"
    break;

  case 11: /* fun_declaracao: tipo_especificador id APAR params FPAR composto_decl  */
#line 103 "bison.y"
                                                                     {
        (yyval.node) = (yyvsp[-5].node);
        (yyvsp[-4].node)->type = (yyvsp[-5].node)->type;
        addAASNode((yyval.node), newAASNodeStmt(KFunc));
        (yyval.node)->children->line = (yyvsp[-4].node)->line;
        (yyval.node)->children->type = (yyvsp[-5].node)->type;
        (yyval.node)->children->name = copyString((yyvsp[-4].node)->name);
        // printf("Funcao: %s\n", $$->children->name);
        (yyval.node)->children->escopo = copyString("global");
        updateEscopo((yyvsp[-2].node), (yyval.node)->children->name);
        updateEscopo((yyvsp[0].node), (yyval.node)->children->name);
        addAASNode((yyval.node)->children, (yyvsp[-2].node));
        addAASNode((yyval.node)->children, (yyvsp[0].node));
}
#line 1328 "bison.tab.c"
    break;

  case 12: /* params: param_lista  */
#line 119 "bison.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1334 "bison.tab.c"
    break;

  case 13: /* params: VOID  */
#line 120 "bison.y"
           { (yyval.node) = NULL; }
#line 1340 "bison.tab.c"
    break;

  case 14: /* param_lista: param_lista VIR param  */
#line 123 "bison.y"
                                   { 
        (yyval.node) = (yyvsp[-2].node);
        addAASNodeSibling((yyval.node), (yyvsp[0].node));
    }
#line 1349 "bison.tab.c"
    break;

  case 15: /* param_lista: param  */
#line 127 "bison.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1355 "bison.tab.c"
    break;

  case 16: /* param: tipo_especificador id  */
#line 130 "bison.y"
                             {
        (yyval.node) = (yyvsp[-1].node);
        (yyvsp[0].node)->type = (yyvsp[-1].node)->type;
        (yyvsp[0].node)->escopo = copyString((yyval.node)->escopo);
        addAASNode((yyval.node), newAASNodeStmt(KVar));
        (yyval.node)->children->line = (yyvsp[0].node)->line;
        (yyval.node)->children->type = (yyvsp[-1].node)->type;
        (yyval.node)->children->name = copyString((yyvsp[0].node)->name);
    }
#line 1369 "bison.tab.c"
    break;

  case 17: /* param: tipo_especificador id ACOL FCOL  */
#line 139 "bison.y"
                                      {
        (yyval.node) = (yyvsp[-3].node);
        (yyvsp[-2].node)->type = (yyvsp[-3].node)->type;
        (yyvsp[-2].node)->escopo = copyString((yyval.node)->escopo);
        addAASNode((yyval.node), newAASNodeStmt(KVet));
        (yyval.node)->children->line = (yyvsp[-2].node)->line;
        (yyval.node)->children->type = (yyvsp[-3].node)->type;
        (yyval.node)->children->name = copyString((yyvsp[-2].node)->name);
    }
#line 1383 "bison.tab.c"
    break;

  case 18: /* composto_decl: ACHV local_declaracoes statement_lista FCHV  */
#line 150 "bison.y"
                                                           {
        (yyval.node) = newAASNodeStmt(KCompound);
        if ((yyvsp[-2].node) != NULL) {
            addAASNode((yyval.node), (yyvsp[-2].node));
            if ((yyvsp[-1].node) != NULL) {
                addAASNodeSibling((yyvsp[-2].node), (yyvsp[-1].node));
            }
        } else if ((yyvsp[-1].node) != NULL) {
            addAASNode((yyval.node), (yyvsp[-1].node));
        }
    }
#line 1399 "bison.tab.c"
    break;

  case 19: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 163 "bison.y"
                                                    {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
            addAASNodeSibling((yyval.node), (yyvsp[0].node));
        }
    }
#line 1412 "bison.tab.c"
    break;

  case 20: /* local_declaracoes: %empty  */
#line 171 "bison.y"
      { (yyval.node) = NULL; }
#line 1418 "bison.tab.c"
    break;

  case 21: /* statement_lista: statement_lista statement  */
#line 174 "bison.y"
                                           {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
            addAASNodeSibling((yyval.node), (yyvsp[0].node));
        }
    }
#line 1431 "bison.tab.c"
    break;

  case 22: /* statement_lista: %empty  */
#line 182 "bison.y"
      { (yyval.node) = NULL; }
#line 1437 "bison.tab.c"
    break;

  case 23: /* statement: expressao_decl  */
#line 185 "bison.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1443 "bison.tab.c"
    break;

  case 24: /* statement: composto_decl  */
#line 186 "bison.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1449 "bison.tab.c"
    break;

  case 25: /* statement: selecao_decl  */
#line 187 "bison.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1455 "bison.tab.c"
    break;

  case 26: /* statement: iteracao_decl  */
#line 188 "bison.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1461 "bison.tab.c"
    break;

  case 27: /* statement: retorno_decl  */
#line 189 "bison.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1467 "bison.tab.c"
    break;

  case 28: /* statement: input_stmt  */
#line 190 "bison.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1473 "bison.tab.c"
    break;

  case 29: /* statement: output_stmt  */
#line 191 "bison.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1479 "bison.tab.c"
    break;

  case 30: /* input_stmt: INPUT APAR var FPAR PTV  */
#line 194 "bison.y"
                                    {
        (yyval.node) = newAASNodeStmt(KInput);
        addAASNode((yyval.node), (yyvsp[-2].node));
        (yyval.node)->line = (yyvsp[-2].node)->line;
    }
#line 1489 "bison.tab.c"
    break;

  case 31: /* output_stmt: OUTPUT APAR expressao FPAR PTV  */
#line 201 "bison.y"
                                            {
        (yyval.node) = newAASNodeStmt(KOutput);
        addAASNode((yyval.node), (yyvsp[-2].node));
        (yyval.node)->line = (yyvsp[-2].node)->line;
    }
#line 1499 "bison.tab.c"
    break;

  case 32: /* expressao_decl: expressao PTV  */
#line 208 "bison.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1505 "bison.tab.c"
    break;

  case 33: /* expressao_decl: PTV  */
#line 209 "bison.y"
          { (yyval.node) = NULL; }
#line 1511 "bison.tab.c"
    break;

  case 34: /* selecao_decl: IF APAR expressao FPAR statement  */
#line 212 "bison.y"
                                               {
        (yyval.node) = newAASNodeStmt(KIf);
        addAASNode((yyval.node), (yyvsp[-2].node));
        addAASNode((yyval.node), (yyvsp[0].node));
    }
#line 1521 "bison.tab.c"
    break;

  case 35: /* selecao_decl: IF APAR expressao FPAR statement ELSE statement  */
#line 217 "bison.y"
                                                      {
        (yyval.node) = newAASNodeStmt(KIf);
        addAASNode((yyval.node), (yyvsp[-4].node));
        addAASNode((yyval.node), (yyvsp[-2].node));
        addAASNode((yyval.node), (yyvsp[0].node));
    }
#line 1532 "bison.tab.c"
    break;

  case 36: /* iteracao_decl: WHILE APAR expressao FPAR statement  */
#line 225 "bison.y"
                                                  {
        (yyval.node) = newAASNodeStmt(KWhile);
        addAASNode((yyval.node), (yyvsp[-2].node));
        addAASNode((yyval.node), (yyvsp[0].node));
    }
#line 1542 "bison.tab.c"
    break;

  case 37: /* retorno_decl: RETURN PTV  */
#line 232 "bison.y"
                         { 
        (yyval.node) = newAASNodeStmt(KReturn);
        (yyval.node)->name = copyString("void");
        (yyval.node)->type = KVoid;
        (yyval.node)->line = lex->line;
    }
#line 1553 "bison.tab.c"
    break;

  case 38: /* retorno_decl: RETURN expressao PTV  */
#line 238 "bison.y"
                           {
        (yyval.node) = newAASNodeStmt(KReturn);
        (yyval.node)->name = copyString("int");
        (yyval.node)->type = (yyvsp[-1].node)->type;
        (yyval.node)->line = (yyvsp[-1].node)->line;
        addAASNode((yyval.node), (yyvsp[-1].node));
    }
#line 1565 "bison.tab.c"
    break;

  case 39: /* expressao: var ATR expressao  */
#line 248 "bison.y"
                             {
        (yyval.node) = newAASNodeStmt(KAssign);
        (yyval.node)->name = copyString((yyvsp[-2].node)->name);
        (yyval.node)->type = (yyvsp[-2].node)->type;
        (yyval.node)->line = (yyvsp[-2].node)->line;
        addAASNode((yyval.node), (yyvsp[-2].node));
        addAASNode((yyval.node), (yyvsp[0].node));
    }
#line 1578 "bison.tab.c"
    break;

  case 40: /* expressao: simples_expressao  */
#line 256 "bison.y"
                        {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1586 "bison.tab.c"
    break;

  case 41: /* var: id  */
#line 261 "bison.y"
        { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1594 "bison.tab.c"
    break;

  case 42: /* var: id ACOL expressao FCOL  */
#line 264 "bison.y"
                             {
        (yyval.node) = newAASNodeExp(KVetId);
        (yyval.node)->type = (yyvsp[-3].node)->type;
        (yyval.node)->line = (yyvsp[-3].node)->line;
        (yyval.node)->name = copyString((yyvsp[-3].node)->name);
        (yyval.node)->escopo = copyString((yyvsp[-3].node)->escopo);
        addAASNode((yyval.node), (yyvsp[-3].node));
        addAASNode((yyval.node), (yyvsp[-1].node));
    }
#line 1608 "bison.tab.c"
    break;

  case 43: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 275 "bison.y"
                                                            {
    (yyval.node) = (yyvsp[-1].node);
    (yyval.node)->type = KInt;
    addAASNode((yyval.node), (yyvsp[-2].node));
    addAASNode((yyval.node), (yyvsp[0].node));
}
#line 1619 "bison.tab.c"
    break;

  case 44: /* simples_expressao: soma_expressao  */
#line 281 "bison.y"
                     {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1627 "bison.tab.c"
    break;

  case 45: /* relacional: LE  */
#line 287 "bison.y"
               { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = LE; }
#line 1633 "bison.tab.c"
    break;

  case 46: /* relacional: LT  */
#line 288 "bison.y"
         { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = LT; }
#line 1639 "bison.tab.c"
    break;

  case 47: /* relacional: GT  */
#line 289 "bison.y"
         { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = GT; }
#line 1645 "bison.tab.c"
    break;

  case 48: /* relacional: GE  */
#line 290 "bison.y"
         { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = GE; }
#line 1651 "bison.tab.c"
    break;

  case 49: /* relacional: COMP  */
#line 291 "bison.y"
           { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = COMP; }
#line 1657 "bison.tab.c"
    break;

  case 50: /* relacional: DIF  */
#line 292 "bison.y"
          { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = DIF; }
#line 1663 "bison.tab.c"
    break;

  case 51: /* soma_expressao: soma_expressao aditivo termo  */
#line 295 "bison.y"
                                             {
    (yyval.node) = (yyvsp[-1].node);
    addAASNode((yyval.node), (yyvsp[-2].node));
    addAASNode((yyval.node), (yyvsp[0].node));
}
#line 1673 "bison.tab.c"
    break;

  case 52: /* soma_expressao: termo  */
#line 300 "bison.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1681 "bison.tab.c"
    break;

  case 53: /* aditivo: SOMA  */
#line 305 "bison.y"
              { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = SOMA; (yyval.node)->type = KInt; }
#line 1687 "bison.tab.c"
    break;

  case 54: /* aditivo: SUB  */
#line 306 "bison.y"
             { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = SUB; (yyval.node)->type = KInt; }
#line 1693 "bison.tab.c"
    break;

  case 55: /* termo: termo operador_multiplicativo fator  */
#line 309 "bison.y"
                                           {
    (yyval.node) = (yyvsp[-1].node);
    addAASNode((yyval.node), (yyvsp[-2].node));
    addAASNode((yyval.node), (yyvsp[0].node));
}
#line 1703 "bison.tab.c"
    break;

  case 56: /* termo: fator  */
#line 314 "bison.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1711 "bison.tab.c"
    break;

  case 57: /* operador_multiplicativo: MULT  */
#line 319 "bison.y"
                              { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = MULT; (yyval.node)->type = KInt; }
#line 1717 "bison.tab.c"
    break;

  case 58: /* operador_multiplicativo: DIV  */
#line 320 "bison.y"
                             { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = DIV; (yyval.node)->type = KInt; }
#line 1723 "bison.tab.c"
    break;

  case 59: /* fator: APAR expressao FPAR  */
#line 323 "bison.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1729 "bison.tab.c"
    break;

  case 60: /* fator: var  */
#line 324 "bison.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1735 "bison.tab.c"
    break;

  case 61: /* fator: ativacao  */
#line 325 "bison.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1741 "bison.tab.c"
    break;

  case 62: /* fator: num  */
#line 326 "bison.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1747 "bison.tab.c"
    break;

  case 63: /* ativacao: id APAR args FPAR  */
#line 329 "bison.y"
                            {
    if (strcmp((yyvsp[-3].node)->name, "input") == 0) {
        (yyval.node) = newAASNodeStmt(KInput);
        (yyval.node)->type = KInt;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString("input");
    } else if (strcmp((yyvsp[-3].node)->name, "output") == 0) {
        (yyval.node) = newAASNodeStmt(KOutput);
        (yyval.node)->type = KVoid;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString("output");
        addAASNode((yyval.node), (yyvsp[-1].node));
    } else {
        (yyval.node) = newAASNodeStmt(KCall);
        (yyval.node)->type = (yyvsp[-3].node)->type;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString((yyvsp[-3].node)->name);
        addAASNode((yyval.node), (yyvsp[-1].node));
    }
}
#line 1775 "bison.tab.c"
    break;

  case 64: /* ativacao: id APAR FPAR  */
#line 352 "bison.y"
               {
    if (strcmp((yyvsp[-2].node)->name, "input") == 0) {
        (yyval.node) = newAASNodeStmt(KInput);
        (yyval.node)->type = KInt;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString("input");
    } else if (strcmp((yyvsp[-2].node)->name, "output") == 0) {
        (yyval.node) = newAASNodeStmt(KOutput);
        (yyval.node)->type = KVoid;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString("output");
    } else {
        (yyval.node) = newAASNodeStmt(KCall);
        (yyval.node)->type = (yyvsp[-2].node)->type;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString((yyvsp[-2].node)->name);
    }
}
#line 1801 "bison.tab.c"
    break;

  case 65: /* args: arg_lista  */
#line 375 "bison.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1807 "bison.tab.c"
    break;

  case 66: /* arg_lista: arg_lista VIR expressao  */
#line 378 "bison.y"
                                   {
        if ((yyvsp[-2].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-2].node);
            addAASNodeSibling((yyval.node), (yyvsp[0].node));
        }
    }
#line 1820 "bison.tab.c"
    break;

  case 67: /* arg_lista: expressao  */
#line 386 "bison.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1828 "bison.tab.c"
    break;

  case 68: /* id: ID  */
#line 391 "bison.y"
       {
        (yyval.node) = newAASNodeExp(KId);
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->type = KInt;
        (yyval.node)->name = copyString(lex->lexema);
        (yyval.node)->escopo = copyString("global");
    }
#line 1841 "bison.tab.c"
    break;

  case 69: /* num: NUM  */
#line 401 "bison.y"
         {
        (yyval.node) = newAASNodeExp(KConst);
        (yyval.node)->value = atoi(lex->lexema);
        (yyval.node)->type = KInt;
        (yyval.node)->line = lex->line;
        (yyval.node)->token = lex->token;
        (yyval.node)->escopo = copyString("global");
    }
#line 1854 "bison.tab.c"
    break;


#line 1858 "bison.tab.c"

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

#line 410 "bison.y"

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
    return token;
}

int main(int argc, char *argv[]) {
    int option = -1;
    int run_all = 0;
    if (argc < 2) { // Verifica se o arquivo foi passado como argumento
        printf("Usage: %s <filename> [-l|-p|-s]\n", argv[0]);
        return 1;
    }

    // Verifica se alguma flag foi passada
    for(int i = 0; i < argc; i++) {
        if(argv[i][0] == '-') {
            if (argv[i][1] == 'l' || argv[i][1] == 'L') { // Análise léxica
                option = 0;
            } else if (argv[i][1] == 'p' || argv[i][1] == 'P') { // Análise sintática
                option = 1;
            } else if (argv[i][1] == 's' || argv[i][1] == 'S') { // Análise semântica
                option = 2;
            } else {
                printf("Invalid option\n");
                return 1;
            }
        }
    }

    // Se nenhuma flag foi passada, executa todos os analisadores
    if (option == -1) {
        run_all = 1;
    }

    fp = fopen(argv[1], "r"); // Abre o arquivo
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

    // Adiciona funções built-in input e output na tabela de símbolos
    AASNode *inputFunc = newAASNodeStmt(KFunc);
    inputFunc->name = copyString("input");
    inputFunc->type = KInt; // ou KVoid, dependendo do seu design
    inputFunc->escopo = copyString("global");
    insertTabSimb(simbTable, inputFunc);
    AASNode *outputFunc = newAASNodeStmt(KFunc);
    outputFunc->name = copyString("output");
    outputFunc->type = KVoid;
    outputFunc->escopo = copyString("global");
    insertTabSimb(simbTable, outputFunc);
    AASNode *readKeypadFunc = newAASNodeStmt(KFunc);
    readKeypadFunc->name = copyString("read_keypad");
    readKeypadFunc->type = KInt;
    readKeypadFunc->escopo = copyString("global");
    insertTabSimb(simbTable, readKeypadFunc);
    AASNode *serialWriteFunc = newAASNodeStmt(KFunc);
    serialWriteFunc->name = copyString("serial_write");
    serialWriteFunc->type = KVoid;
    serialWriteFunc->escopo = copyString("global");
    insertTabSimb(simbTable, serialWriteFunc);

    if (run_all) {
        yyparse();
        // Print tree to file
        FILE *ftree = fopen("tree.txt", "w");
        if (ftree && root) {
            printAAS(root, 0, ftree);
            fclose(ftree);
            printf("Tree written to tree.txt\n");
        } else {
            printf("Could not write tree.\n");
        }
        // Print symbol table to file
        FILE *fsymb = fopen("symbol_table.txt", "w");
        if (fsymb && root) {
            printTabSimb(simbTable, root, fsymb);
            fclose(fsymb);
            printf("Symbol table written to symbol_table.txt\n");
        } else {
            printf("Could not write symbol table.\n");
        }
        FILE *finter = fopen("intermediate.txt", "w");
        if (finter && root) {
            QuadNode* quadList = generateIntermediateCodeWithList(root, finter);
            printQuadList(quadList, stdout); // Print all quads to stdout
            fclose(finter);
            printf("Intermediate code written to intermediate.txt\n");
        } else {
            printf("Could not write intermediate code.\n");
        }
    } else if (option == 0) { // Análise léxica
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
        FILE *ftree = fopen("tree.txt", "w");
        if (ftree && root) {
            printAAS(root, 0, ftree);
            fclose(ftree);
            printf("Tree written to tree.txt\n");
        } else {
            printf("Could not write tree.\n");
        }
    } else if (option == 2) { // Análise semântica
        yyparse();
        if (root == NULL) {
            printf("Erro na análise sintática\n");
            return 1;
        }
        else {
            FILE *fsymb = fopen("symbol_table.txt", "w");
            if (fsymb && root) {
                printTabSimb(simbTable, root, fsymb);
                fclose(fsymb);
                printf("Symbol table written to symbol_table.txt\n");
            } else {
                printf("Could not write symbol table.\n");
            }
        }
    }

    fclose(fp);

    /*Desalocação de memória*/
    deallocate_buffer(buffer);
    deallocate_lex(lex);
    if (root != NULL) {
        deallocateAAS(root);
    }
    deallocateTabSimb(simbTable);

    return 0;
}
