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
//#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct ASTNode {
    char* type;
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

ASTNode* newASTNode(char* type, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->value = NULL;
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* newASTNodeValue(char* type, char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int yylineno;
int valyy;
char yytext[64];

int yyerror(char *s);

int yylex(void);

#line 114 "bison.tab.c"

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
  YYSYMBOL_17_ = 17,                       /* '+'  */
  YYSYMBOL_18_ = 18,                       /* '-'  */
  YYSYMBOL_19_ = 19,                       /* '*'  */
  YYSYMBOL_20_ = 20,                       /* '/'  */
  YYSYMBOL_21_ = 21,                       /* ';'  */
  YYSYMBOL_22_ = 22,                       /* '['  */
  YYSYMBOL_23_ = 23,                       /* ']'  */
  YYSYMBOL_24_ = 24,                       /* '('  */
  YYSYMBOL_25_ = 25,                       /* ')'  */
  YYSYMBOL_26_ = 26,                       /* ','  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* '='  */
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
  YYSYMBOL_iteracao_decl = 46,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 47,              /* retorno_decl  */
  YYSYMBOL_expressao = 48,                 /* expressao  */
  YYSYMBOL_var = 49,                       /* var  */
  YYSYMBOL_simples_expressao = 50,         /* simples_expressao  */
  YYSYMBOL_relacional = 51,                /* relacional  */
  YYSYMBOL_soma_expressao = 52,            /* soma_expressao  */
  YYSYMBOL_termo = 53,                     /* termo  */
  YYSYMBOL_fator = 54,                     /* fator  */
  YYSYMBOL_ativacao = 55,                  /* ativacao  */
  YYSYMBOL_args = 56,                      /* args  */
  YYSYMBOL_arg_lista = 57                  /* arg_lista  */
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
#define YYLAST   106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


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
      24,    25,    19,    17,    26,    18,     2,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
       2,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    81,    82,    85,    86,    89,    90,    93,
      94,    97,   101,   103,   107,   109,   112,   114,   118,   122,
     125,   128,   131,   134,   136,   138,   140,   142,   146,   148,
     152,   154,   157,   161,   163,   167,   169,   172,   174,   178,
     180,   183,   185,   187,   189,   191,   193,   197,   199,   201,
     204,   206,   208,   211,   213,   214,   215,   219,   223,   226,
     229,   231
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
  "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "'+'", "'-'", "'*'", "'/'", "';'",
  "'['", "']'", "'('", "')'", "','", "'{'", "'}'", "'='", "$accept",
  "programa", "declaracao_lista", "declaracao", "var_declaracao",
  "tipo_especificador", "fun_declaracao", "params", "param_lista", "param",
  "composto_decl", "local_declaracoes", "statement_lista", "statement",
  "expressao_decl", "selecao_decl", "iteracao_decl", "retorno_decl",
  "expressao", "var", "simples_expressao", "relacional", "soma_expressao",
  "termo", "fator", "ativacao", "args", "arg_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,   -61,   -61,    39,     6,   -61,   -61,    -3,   -61,   -61,
     -61,   -61,    48,   -61,    31,    34,     3,    46,    75,    55,
      57,   -61,    28,    59,    58,     5,   -61,    61,   -61,   -61,
     -61,   -61,     5,   -61,    78,     0,    24,   -61,   -14,    62,
      63,    19,   -61,     8,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,    67,    60,   -61,    45,    32,   -61,   -61,     8,     8,
       8,     8,   -61,    69,    66,   -61,     8,   -61,   -61,   -61,
     -61,   -61,   -61,     8,     8,     8,     8,     8,    70,   -61,
      71,    68,    72,    73,   -61,   -61,   -61,   -61,    32,    32,
      56,   -61,   -61,   -61,   -61,     8,    26,    26,   -61,    86,
     -61,    26,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     0,     4,     5,     0,     6,     1,
       2,     3,     0,     7,     0,     0,     0,    10,     0,     0,
      12,    15,     0,    16,     0,     0,     8,     0,    20,    11,
      14,    17,    22,    19,     0,     0,     0,    56,    37,     0,
       0,     0,    29,     0,    18,    24,    21,    23,    25,    26,
      27,     0,    54,    36,    40,    49,    52,    55,     0,    59,
       0,     0,    33,     0,     0,    28,     0,    45,    46,    43,
      42,    44,    41,     0,     0,     0,     0,     0,     0,    61,
       0,    58,     0,     0,    34,    53,    35,    54,    47,    48,
      39,    50,    51,    38,    57,     0,     0,     0,    60,    30,
      32,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,    91,    74,    23,   -61,   -61,   -61,    76,
      79,   -61,   -61,   -60,   -61,   -61,   -61,   -61,   -41,    -9,
     -61,   -61,    25,     2,     1,   -61,   -61,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    19,    20,    21,
      45,    32,    35,    46,    47,    48,    49,    50,    51,    52,
      53,    75,    54,    55,    56,    57,    80,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      63,    12,    64,    37,    38,    39,    10,    40,    58,    41,
      59,    37,    38,     1,     1,     2,     2,    78,    79,    82,
      83,    42,    37,    38,    43,    86,    22,    28,    44,    37,
      38,    39,    43,    40,    16,    41,    99,   100,    18,     9,
      62,   102,     1,    43,    17,    13,    14,    42,    18,    26,
      43,    76,    77,    28,    98,    34,    67,    68,    69,    70,
      71,    72,    73,    74,    87,    87,    87,    87,    87,    13,
      14,   -13,    15,    73,    74,    88,    89,    91,    92,    23,
      24,    27,    36,    25,    31,    28,    60,    61,    65,    66,
      84,    85,   101,    93,    95,    11,    94,    96,    97,     0,
      90,    30,     0,    29,     0,     0,    33
};

static const yytype_int8 yycheck[] =
{
      41,     4,    43,     3,     4,     5,     0,     7,    22,     9,
      24,     3,     4,     8,     8,    10,    10,    58,    59,    60,
      61,    21,     3,     4,    24,    66,    23,    27,    28,     3,
       4,     5,    24,     7,     3,     9,    96,    97,    15,     0,
      21,   101,     8,    24,    10,    21,    22,    21,    25,    21,
      24,    19,    20,    27,    95,    32,    11,    12,    13,    14,
      15,    16,    17,    18,    73,    74,    75,    76,    77,    21,
      22,    25,    24,    17,    18,    73,    74,    76,    77,     4,
      25,    22,     4,    26,    23,    27,    24,    24,    21,    29,
      21,    25,     6,    23,    26,     4,    25,    25,    25,    -1,
      75,    25,    -1,    24,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    31,    32,    33,    34,    35,    36,     0,
       0,    33,     4,    21,    22,    24,     3,    10,    35,    37,
      38,    39,    23,     4,    25,    26,    21,    22,    27,    40,
      39,    23,    41,    34,    35,    42,     4,     3,     4,     5,
       7,     9,    21,    24,    28,    40,    43,    44,    45,    46,
      47,    48,    49,    50,    52,    53,    54,    55,    22,    24,
      24,    24,    21,    48,    48,    21,    29,    11,    12,    13,
      14,    15,    16,    17,    18,    51,    19,    20,    48,    48,
      56,    57,    48,    48,    21,    25,    48,    49,    53,    53,
      52,    54,    54,    23,    25,    26,    25,    25,    48,    43,
      43,     6,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    35,
      35,    36,    37,    37,    38,    38,    39,    39,    40,    41,
      41,    42,    42,    43,    43,    43,    43,    43,    44,    44,
      45,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    51,    51,    51,    51,    52,    52,    52,
      53,    53,    53,    54,    54,    54,    54,    55,    56,    56,
      57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     4,     1,     0,
       3,     1
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
  case 2: /* programa: declaracao_lista $end  */
#line 79 "bison.y"
                                 { (yyval.nodeValue) = newASTNode("programa", (yyvsp[-1].nodeValue), NULL); }
#line 1226 "bison.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 81 "bison.y"
                                              { (yyval.nodeValue) = newASTNode("declaracao_lista", (yyvsp[-1].nodeValue), (yyvsp[0].nodeValue)); }
#line 1232 "bison.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 82 "bison.y"
                             { (yyval.nodeValue) = newASTNode("declaracao_lista", (yyvsp[0].nodeValue), NULL); }
#line 1238 "bison.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 85 "bison.y"
                           { (yyval.nodeValue) = newASTNode("declaracao", (yyvsp[0].nodeValue), NULL); }
#line 1244 "bison.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 86 "bison.y"
                           { (yyval.nodeValue) = newASTNode("declaracao", (yyvsp[0].nodeValue), NULL); }
#line 1250 "bison.tab.c"
    break;

  case 7: /* var_declaracao: tipo_especificador ID ';'  */
#line 89 "bison.y"
                                          { (yyval.nodeValue) = newASTNode("var_declaracao", (yyvsp[-2].nodeValue), newASTNodeValue("ID", (yyvsp[-1].stringValue))); }
#line 1256 "bison.tab.c"
    break;

  case 8: /* var_declaracao: tipo_especificador ID '[' NUMERO ']' ';'  */
#line 90 "bison.y"
                                                         { (yyval.nodeValue) = newASTNode("var_declaracao", (yyvsp[-5].nodeValue), newASTNodeValue("ID", (yyvsp[-4].stringValue))); }
#line 1262 "bison.tab.c"
    break;

  case 9: /* tipo_especificador: INT  */
#line 93 "bison.y"
                        { (yyval.nodeValue) = newASTNodeValue("tipo_especificador", "int"); }
#line 1268 "bison.tab.c"
    break;

  case 10: /* tipo_especificador: VOID  */
#line 94 "bison.y"
                         { (yyval.nodeValue) = newASTNodeValue("tipo_especificador", "void"); }
#line 1274 "bison.tab.c"
    break;

  case 11: /* fun_declaracao: tipo_especificador ID '(' params ')' composto_decl  */
#line 98 "bison.y"
    { (yyval.nodeValue) = newASTNode("fun_declaracao", (yyvsp[-5].nodeValue), newASTNodeValue("ID", (yyvsp[-4].stringValue))); }
#line 1280 "bison.tab.c"
    break;

  case 12: /* params: param_lista  */
#line 102 "bison.y"
    { (yyval.nodeValue) = newASTNode("params", (yyvsp[0].nodeValue), NULL); }
#line 1286 "bison.tab.c"
    break;

  case 13: /* params: VOID  */
#line 104 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("params", "void"); }
#line 1292 "bison.tab.c"
    break;

  case 14: /* param_lista: param_lista ',' param  */
#line 108 "bison.y"
    { (yyval.nodeValue) = newASTNode("param_lista", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1298 "bison.tab.c"
    break;

  case 16: /* param: tipo_especificador ID  */
#line 113 "bison.y"
    { (yyval.nodeValue) = newASTNode("param", (yyvsp[-1].nodeValue), newASTNodeValue("ID", (yyvsp[0].stringValue))); }
#line 1304 "bison.tab.c"
    break;

  case 17: /* param: tipo_especificador ID '[' ']'  */
#line 115 "bison.y"
    { (yyval.nodeValue) = newASTNode("param", (yyvsp[-3].nodeValue), newASTNodeValue("ID", (yyvsp[-2].stringValue))); }
#line 1310 "bison.tab.c"
    break;

  case 18: /* composto_decl: '{' local_declaracoes statement_lista '}'  */
#line 119 "bison.y"
    { (yyval.nodeValue) = newASTNode("composto_decl", (yyvsp[-2].nodeValue), (yyvsp[-1].nodeValue)); }
#line 1316 "bison.tab.c"
    break;

  case 19: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 123 "bison.y"
    { (yyval.nodeValue) = newASTNode("local_declaracoes", (yyvsp[-1].nodeValue), (yyvsp[0].nodeValue)); }
#line 1322 "bison.tab.c"
    break;

  case 20: /* local_declaracoes: %empty  */
#line 125 "bison.y"
    { (yyval.nodeValue) = NULL; }
#line 1328 "bison.tab.c"
    break;

  case 21: /* statement_lista: statement_lista statement  */
#line 129 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement_lista", (yyvsp[-1].nodeValue), (yyvsp[0].nodeValue)); }
#line 1334 "bison.tab.c"
    break;

  case 22: /* statement_lista: %empty  */
#line 131 "bison.y"
    { (yyval.nodeValue) = NULL; }
#line 1340 "bison.tab.c"
    break;

  case 23: /* statement: expressao_decl  */
#line 135 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement", (yyvsp[0].nodeValue), NULL); }
#line 1346 "bison.tab.c"
    break;

  case 24: /* statement: composto_decl  */
#line 137 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement", (yyvsp[0].nodeValue), NULL); }
#line 1352 "bison.tab.c"
    break;

  case 25: /* statement: selecao_decl  */
#line 139 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement", (yyvsp[0].nodeValue), NULL); }
#line 1358 "bison.tab.c"
    break;

  case 26: /* statement: iteracao_decl  */
#line 141 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement", (yyvsp[0].nodeValue), NULL); }
#line 1364 "bison.tab.c"
    break;

  case 27: /* statement: retorno_decl  */
#line 143 "bison.y"
    { (yyval.nodeValue) = newASTNode("statement", (yyvsp[0].nodeValue), NULL); }
#line 1370 "bison.tab.c"
    break;

  case 28: /* expressao_decl: expressao ';'  */
#line 147 "bison.y"
    { (yyval.nodeValue) = newASTNode("expressao_decl", (yyvsp[-1].nodeValue), NULL); }
#line 1376 "bison.tab.c"
    break;

  case 29: /* expressao_decl: ';'  */
#line 149 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("expressao_decl", ";"); }
#line 1382 "bison.tab.c"
    break;

  case 30: /* selecao_decl: IF '(' expressao ')' statement  */
#line 153 "bison.y"
    { (yyval.nodeValue) = newASTNode("selecao_decl", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1388 "bison.tab.c"
    break;

  case 31: /* selecao_decl: IF '(' expressao ')' statement ELSE statement  */
#line 155 "bison.y"
    { (yyval.nodeValue) = newASTNode("selecao_decl", (yyvsp[-4].nodeValue), newASTNode("else", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue))); }
#line 1394 "bison.tab.c"
    break;

  case 32: /* iteracao_decl: WHILE '(' expressao ')' statement  */
#line 158 "bison.y"
    { (yyval.nodeValue) = newASTNode("iteracao_decl", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1400 "bison.tab.c"
    break;

  case 33: /* retorno_decl: RETURN ';'  */
#line 162 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("retorno_decl", "return"); }
#line 1406 "bison.tab.c"
    break;

  case 34: /* retorno_decl: RETURN expressao ';'  */
#line 164 "bison.y"
    { (yyval.nodeValue) = newASTNode("retorno_decl", (yyvsp[-1].nodeValue), NULL); }
#line 1412 "bison.tab.c"
    break;

  case 35: /* expressao: var '=' expressao  */
#line 168 "bison.y"
    { (yyval.nodeValue) = newASTNode("expressao", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1418 "bison.tab.c"
    break;

  case 37: /* var: ID  */
#line 173 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("var", (yyvsp[0].stringValue)); }
#line 1424 "bison.tab.c"
    break;

  case 38: /* var: ID '[' expressao ']'  */
#line 175 "bison.y"
    { (yyval.nodeValue) = newASTNode("var", newASTNodeValue("ID", (yyvsp[-3].stringValue)), (yyvsp[-1].nodeValue)); }
#line 1430 "bison.tab.c"
    break;

  case 39: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 179 "bison.y"
    { (yyval.nodeValue) = newASTNode("simples_expressao", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1436 "bison.tab.c"
    break;

  case 41: /* relacional: MENOR_IGUAL  */
#line 184 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", "<="); }
#line 1442 "bison.tab.c"
    break;

  case 42: /* relacional: MENOR  */
#line 186 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", "<"); }
#line 1448 "bison.tab.c"
    break;

  case 43: /* relacional: MAIOR  */
#line 188 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", ">"); }
#line 1454 "bison.tab.c"
    break;

  case 44: /* relacional: MAIOR_IGUAL  */
#line 190 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", ">="); }
#line 1460 "bison.tab.c"
    break;

  case 45: /* relacional: IGUAL  */
#line 192 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", "=="); }
#line 1466 "bison.tab.c"
    break;

  case 46: /* relacional: DIFERENTE  */
#line 194 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("relacional", "!="); }
#line 1472 "bison.tab.c"
    break;

  case 47: /* soma_expressao: soma_expressao '+' termo  */
#line 198 "bison.y"
    { (yyval.nodeValue) = newASTNode("soma_expressao", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1478 "bison.tab.c"
    break;

  case 48: /* soma_expressao: soma_expressao '-' termo  */
#line 200 "bison.y"
    { (yyval.nodeValue) = newASTNode("soma_expressao", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1484 "bison.tab.c"
    break;

  case 50: /* termo: termo '*' fator  */
#line 205 "bison.y"
    { (yyval.nodeValue) = newASTNode("termo", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1490 "bison.tab.c"
    break;

  case 51: /* termo: termo '/' fator  */
#line 207 "bison.y"
    { (yyval.nodeValue) = newASTNode("termo", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1496 "bison.tab.c"
    break;

  case 53: /* fator: '(' expressao ')'  */
#line 212 "bison.y"
    { (yyval.nodeValue) = newASTNode("fator", (yyvsp[-1].nodeValue), NULL); }
#line 1502 "bison.tab.c"
    break;

  case 56: /* fator: NUMERO  */
#line 216 "bison.y"
    { (yyval.nodeValue) = newASTNodeValue("fator", (yyvsp[0].stringValue)); }
#line 1508 "bison.tab.c"
    break;

  case 57: /* ativacao: ID '(' args ')'  */
#line 220 "bison.y"
    { (yyval.nodeValue) = newASTNode("ativacao", newASTNodeValue("ID", (yyvsp[-3].stringValue)), (yyvsp[-1].nodeValue)); }
#line 1514 "bison.tab.c"
    break;

  case 58: /* args: arg_lista  */
#line 224 "bison.y"
    { (yyval.nodeValue) = newASTNode("args", (yyvsp[0].nodeValue), NULL); }
#line 1520 "bison.tab.c"
    break;

  case 59: /* args: %empty  */
#line 226 "bison.y"
    { (yyval.nodeValue) = NULL; }
#line 1526 "bison.tab.c"
    break;

  case 60: /* arg_lista: arg_lista ',' expressao  */
#line 230 "bison.y"
    { (yyval.nodeValue) = newASTNode("arg_lista", (yyvsp[-2].nodeValue), (yyvsp[0].nodeValue)); }
#line 1532 "bison.tab.c"
    break;


#line 1536 "bison.tab.c"

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

#line 233 "bison.y"


int yyerror(char *s) {
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
    fprintf(stderr, "Unexpected token: %s\n", yytext);
    return 0;
}

int yylex(void) {
    Bloco *buffer;
    allocate_buffer(&buffer);

    Lexema *lex;
    allocate_lexema(&lex);

    Lista ht[MAX];
    Tabela_Inicia(ht, MAX);
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

    FILE *fp;
    fp = fopen("teste.txt", "r");

    char c;
    int flag = 1;
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
        printf("Lexema: %s\n", lex->item);
        printf("Token_Num: %d\n", lex->token_type);
        printf("Token: %s\n", lex->token);
        printf("Flag: %d\n\n", flag);
    }while(lex->token_type != 284 && flag != -1 && flag != 0);
    if (flag == 0)
    {
        yyerror (YY_("lexical error"));
        return -1;
    }
    else if (flag == -1)
    {
        printf("E todo mundo morreu\n");
        return 0;
    }

    yylineno = lex->line;
    if (Get_Token_Type(lex->token) == 258)
    {
        yylval.intValue = *(lex->item) - '0';
    }
    //yytext = lex->item;
    strcpy(yytext, lex->item);

    deallocate_lexema(lex);

    return lex->token_type;
}

int main(void) {
    yyparse();
    return 0;
}
