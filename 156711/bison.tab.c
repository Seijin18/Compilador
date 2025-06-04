
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
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



/* Line 189 of yacc.c  */
#line 101 "bison.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     ID = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     INT = 263,
     RETURN = 264,
     VOID = 265,
     COMP = 266,
     DIF = 267,
     GT = 268,
     LT = 269,
     GE = 270,
     LE = 271,
     SOMA = 272,
     SUB = 273,
     MULT = 274,
     DIV = 275,
     ATR = 276,
     PTV = 277,
     VIR = 278,
     APAR = 279,
     FPAR = 280,
     ACOL = 281,
     FCOL = 282,
     ACHV = 283,
     FCHV = 284,
     CMT = 285,
     INPUT = 286,
     OUTPUT = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "bison.y"

    int intValue;
    char* stringValue;
    AASNode* node;



/* Line 214 of yacc.c  */
#line 177 "bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 189 "bison.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    25,
      27,    29,    36,    38,    40,    44,    46,    49,    54,    59,
      62,    63,    66,    67,    69,    71,    73,    75,    77,    79,
      81,    87,    93,    96,    98,   104,   112,   118,   121,   125,
     129,   131,   133,   138,   142,   144,   146,   148,   150,   152,
     154,   156,   160,   162,   164,   166,   170,   172,   174,   176,
     180,   182,   184,   186,   191,   195,   197,   201,   203,   205
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    35,    36,    -1,    36,    -1,
      37,    -1,    39,    -1,    38,    65,    22,    -1,    38,    65,
      26,    66,    27,    22,    -1,     8,    -1,    10,    -1,    38,
      65,    24,    40,    25,    43,    -1,    41,    -1,    10,    -1,
      41,    23,    42,    -1,    42,    -1,    38,    65,    -1,    38,
      65,    26,    27,    -1,    28,    44,    45,    29,    -1,    44,
      37,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,    43,
      -1,    50,    -1,    51,    -1,    52,    -1,    47,    -1,    48,
      -1,    31,    24,    54,    25,    22,    -1,    32,    24,    53,
      25,    22,    -1,    53,    22,    -1,    22,    -1,     5,    24,
      53,    25,    46,    -1,     5,    24,    53,    25,    46,     6,
      46,    -1,     7,    24,    53,    25,    46,    -1,     9,    22,
      -1,     9,    53,    22,    -1,    54,    21,    53,    -1,    55,
      -1,    65,    -1,    65,    26,    53,    27,    -1,    57,    56,
      57,    -1,    57,    -1,    16,    -1,    14,    -1,    13,    -1,
      15,    -1,    11,    -1,    12,    -1,    57,    58,    59,    -1,
      59,    -1,    17,    -1,    18,    -1,    59,    60,    61,    -1,
      61,    -1,    19,    -1,    20,    -1,    24,    53,    25,    -1,
      54,    -1,    62,    -1,    66,    -1,    65,    24,    63,    25,
      -1,    65,    24,    25,    -1,    64,    -1,    64,    23,    53,
      -1,    53,    -1,     4,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    58,    62,    65,    66,    69,    79,    92,
      96,   102,   118,   119,   122,   126,   129,   138,   149,   159,
     167,   170,   178,   181,   182,   183,   184,   185,   186,   187,
     190,   197,   204,   205,   208,   213,   221,   228,   234,   244,
     252,   257,   260,   271,   277,   283,   284,   285,   286,   287,
     288,   291,   296,   301,   302,   305,   310,   315,   316,   319,
     320,   321,   322,   325,   348,   371,   374,   382,   387,   397
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "IF", "ELSE", "WHILE",
  "INT", "RETURN", "VOID", "COMP", "DIF", "GT", "LT", "GE", "LE", "SOMA",
  "SUB", "MULT", "DIV", "ATR", "PTV", "VIR", "APAR", "FPAR", "ACOL",
  "FCOL", "ACHV", "FCHV", "CMT", "INPUT", "OUTPUT", "$accept", "programa",
  "declaracao_lista", "declaracao", "var_declaracao", "tipo_especificador",
  "fun_declaracao", "params", "param_lista", "param", "composto_decl",
  "local_declaracoes", "statement_lista", "statement", "input_stmt",
  "output_stmt", "expressao_decl", "selecao_decl", "iteracao_decl",
  "retorno_decl", "expressao", "var", "simples_expressao", "relacional",
  "soma_expressao", "aditivo", "termo", "operador_multiplicativo", "fator",
  "ativacao", "args", "arg_lista", "id", "num", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    37,    37,    38,
      38,    39,    40,    40,    41,    41,    42,    42,    43,    44,
      44,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      47,    48,    49,    49,    50,    50,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    62,    62,    63,    64,    64,    65,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     2,     1,     5,     7,     5,     2,     3,     3,
       1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     4,     3,     1,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
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

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      46,    33,    36,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    80,    57,    81,    58,    84,    59,    60,
     101,   102,    61,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -98,    97,    58,    11,   -98,   -98,   -98,    86,
      88,   -98,   -98,   -97,   -98,   -98,   -98,   -98,   -98,   -98,
     -40,   -10,   -98,   -98,    30,   -98,    32,   -98,    34,   -98,
     -98,   -98,    -3,    99
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -14
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

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 52 "bison.y"
    { 
            root = newAASNodeStmt(KProg);
            addAASNode(root, (yyvsp[(1) - (1)].node));
        ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 58 "bison.y"
    {
                    (yyval.node) = (yyvsp[(1) - (2)].node);
                    addAASNodeSibling((yyval.node), (yyvsp[(2) - (2)].node));
                ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 62 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 65 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 66 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 69 "bison.y"
    {
                    (yyval.node) = (yyvsp[(1) - (3)].node);
                    (yyvsp[(2) - (3)].node)->type = (yyvsp[(1) - (3)].node)->type;
                    addAASNode((yyval.node), newAASNodeStmt(KVar));
                    (yyval.node)->children->line = (yyvsp[(2) - (3)].node)->line;
                    (yyval.node)->children->type = (yyvsp[(1) - (3)].node)->type;
                    (yyval.node)->children->name = copyString((yyvsp[(2) - (3)].node)->name);
                    (yyval.node)->children->escopo = copyString("global");

                ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 79 "bison.y"
    {
                    (yyval.node) = (yyvsp[(1) - (6)].node);
                    (yyvsp[(2) - (6)].node)->type = (yyvsp[(1) - (6)].node)->type;
                    addAASNode((yyval.node), newAASNodeStmt(KVet));
                    (yyval.node)->children->line = (yyvsp[(2) - (6)].node)->line;
                    (yyval.node)->children->type = (yyvsp[(1) - (6)].node)->type;
                    (yyval.node)->children->name = copyString((yyvsp[(2) - (6)].node)->name);
                    (yyval.node)->children->escopo = copyString("global");
                    addAASNode((yyval.node)->children, (yyvsp[(2) - (6)].node)); 
                    addAASNode((yyval.node)->children, (yyvsp[(4) - (6)].node));
                ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 92 "bison.y"
    { 
                        (yyval.node) = newAASNodeExp(KType); 
                        (yyval.node)->type = KInt; 
                        ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 96 "bison.y"
    {
                        (yyval.node) = newAASNodeExp(KType);
                        (yyval.node)->type = KVoid;
                    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 102 "bison.y"
    {
        (yyval.node) = (yyvsp[(1) - (6)].node);
        (yyvsp[(2) - (6)].node)->type = (yyvsp[(1) - (6)].node)->type;
        addAASNode((yyval.node), newAASNodeStmt(KFunc));
        (yyval.node)->children->line = (yyvsp[(2) - (6)].node)->line;
        (yyval.node)->children->type = (yyvsp[(1) - (6)].node)->type;
        (yyval.node)->children->name = copyString((yyvsp[(2) - (6)].node)->name);
        // printf("Funcao: %s\n", $$->children->name);
        (yyval.node)->children->escopo = copyString("global");
        updateEscopo((yyvsp[(4) - (6)].node), (yyval.node)->children->name);
        updateEscopo((yyvsp[(6) - (6)].node), (yyval.node)->children->name);
        addAASNode((yyval.node)->children, (yyvsp[(4) - (6)].node));
        addAASNode((yyval.node)->children, (yyvsp[(6) - (6)].node));
;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 118 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 119 "bison.y"
    { (yyval.node) = NULL; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 122 "bison.y"
    { 
        (yyval.node) = (yyvsp[(1) - (3)].node);
        addAASNodeSibling((yyval.node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 126 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 129 "bison.y"
    {
        (yyval.node) = (yyvsp[(1) - (2)].node);
        (yyvsp[(2) - (2)].node)->type = (yyvsp[(1) - (2)].node)->type;
        (yyvsp[(2) - (2)].node)->escopo = copyString((yyval.node)->escopo);
        addAASNode((yyval.node), newAASNodeStmt(KVar));
        (yyval.node)->children->line = (yyvsp[(2) - (2)].node)->line;
        (yyval.node)->children->type = (yyvsp[(1) - (2)].node)->type;
        (yyval.node)->children->name = copyString((yyvsp[(2) - (2)].node)->name);
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 138 "bison.y"
    {
        (yyval.node) = (yyvsp[(1) - (4)].node);
        (yyvsp[(2) - (4)].node)->type = (yyvsp[(1) - (4)].node)->type;
        (yyvsp[(2) - (4)].node)->escopo = copyString((yyval.node)->escopo);
        addAASNode((yyval.node), newAASNodeStmt(KVet));
        (yyval.node)->children->line = (yyvsp[(2) - (4)].node)->line;
        (yyval.node)->children->type = (yyvsp[(1) - (4)].node)->type;
        (yyval.node)->children->name = copyString((yyvsp[(2) - (4)].node)->name);
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 149 "bison.y"
    {
        if ((yyvsp[(2) - (4)].node) != NULL) {
            (yyval.node) = (yyvsp[(2) - (4)].node);
            addAASNodeSibling((yyval.node), (yyvsp[(3) - (4)].node));
        } else {
            (yyval.node) = (yyvsp[(3) - (4)].node);
        }
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 159 "bison.y"
    {
        if ((yyvsp[(1) - (2)].node) == NULL) {
            (yyval.node) = (yyvsp[(2) - (2)].node);
        } else {
            (yyval.node) = (yyvsp[(1) - (2)].node);
            addAASNodeSibling((yyval.node), (yyvsp[(2) - (2)].node));
        }
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 167 "bison.y"
    { (yyval.node) = NULL; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 170 "bison.y"
    {
        if ((yyvsp[(1) - (2)].node) == NULL) {
            (yyval.node) = (yyvsp[(2) - (2)].node);
        } else {
            (yyval.node) = (yyvsp[(1) - (2)].node);
            addAASNodeSibling((yyval.node), (yyvsp[(2) - (2)].node));
        }
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 178 "bison.y"
    { (yyval.node) = NULL; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 181 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 182 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 183 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 184 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 185 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 186 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 187 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 190 "bison.y"
    {
        (yyval.node) = newAASNodeStmt(KInput);
        addAASNode((yyval.node), (yyvsp[(3) - (5)].node));
        (yyval.node)->line = (yyvsp[(3) - (5)].node)->line;
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 197 "bison.y"
    {
        (yyval.node) = newAASNodeStmt(KOutput);
        addAASNode((yyval.node), (yyvsp[(3) - (5)].node));
        (yyval.node)->line = (yyvsp[(3) - (5)].node)->line;
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 204 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 205 "bison.y"
    { (yyval.node) = NULL; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 208 "bison.y"
    {
        (yyval.node) = newAASNodeStmt(KIf);
        addAASNode((yyval.node), (yyvsp[(3) - (5)].node));
        addAASNode((yyval.node), (yyvsp[(5) - (5)].node));
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 213 "bison.y"
    {
        (yyval.node) = newAASNodeStmt(KIf);
        addAASNode((yyval.node), (yyvsp[(3) - (7)].node));
        addAASNode((yyval.node), (yyvsp[(5) - (7)].node));
        addAASNode((yyval.node), (yyvsp[(7) - (7)].node));
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 221 "bison.y"
    {
        (yyval.node) = newAASNodeStmt(KWhile);
        addAASNode((yyval.node), (yyvsp[(3) - (5)].node));
        addAASNode((yyval.node), (yyvsp[(5) - (5)].node));
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 228 "bison.y"
    { 
        (yyval.node) = newAASNodeStmt(KReturn);
        (yyval.node)->name = copyString("void");
        (yyval.node)->type = KVoid;
        (yyval.node)->line = lex->line;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 234 "bison.y"
    {
        (yyval.node) = newAASNodeStmt(KReturn);
        (yyval.node)->name = copyString("int");
        (yyval.node)->type = (yyvsp[(2) - (3)].node)->type;
        (yyval.node)->line = (yyvsp[(2) - (3)].node)->line;
        addAASNode((yyval.node), (yyvsp[(2) - (3)].node));
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 244 "bison.y"
    {
        (yyval.node) = newAASNodeStmt(KAssign);
        (yyval.node)->name = copyString((yyvsp[(1) - (3)].node)->name);
        (yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
        (yyval.node)->line = (yyvsp[(1) - (3)].node)->line;
        addAASNode((yyval.node), (yyvsp[(1) - (3)].node));
        addAASNode((yyval.node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 252 "bison.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 257 "bison.y"
    { 
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 260 "bison.y"
    {
        (yyval.node) = newAASNodeExp(KVetId);
        (yyval.node)->type = (yyvsp[(1) - (4)].node)->type;
        (yyval.node)->line = (yyvsp[(1) - (4)].node)->line;
        (yyval.node)->name = copyString((yyvsp[(1) - (4)].node)->name);
        (yyval.node)->escopo = copyString((yyvsp[(1) - (4)].node)->escopo);
        addAASNode((yyval.node), (yyvsp[(1) - (4)].node));
        addAASNode((yyval.node), (yyvsp[(3) - (4)].node));
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 271 "bison.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
    (yyval.node)->type = KInt;
    addAASNode((yyval.node), (yyvsp[(1) - (3)].node));
    addAASNode((yyval.node), (yyvsp[(3) - (3)].node));
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 277 "bison.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 283 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = LE; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 284 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = LT; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 285 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = GT; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 286 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = GE; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 287 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = COMP; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 288 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = DIF; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 291 "bison.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
    addAASNode((yyval.node), (yyvsp[(1) - (3)].node));
    addAASNode((yyval.node), (yyvsp[(3) - (3)].node));
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 296 "bison.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 301 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = SOMA; (yyval.node)->type = KInt; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 302 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = SUB; (yyval.node)->type = KInt; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 305 "bison.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
    addAASNode((yyval.node), (yyvsp[(1) - (3)].node));
    addAASNode((yyval.node), (yyvsp[(3) - (3)].node));
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 310 "bison.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 315 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = MULT; (yyval.node)->type = KInt; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 316 "bison.y"
    { (yyval.node) = newAASNodeExp(KOp); (yyval.node)->token = DIV; (yyval.node)->type = KInt; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 319 "bison.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 320 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 321 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 322 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 325 "bison.y"
    {
    if (strcmp((yyvsp[(1) - (4)].node)->name, "input") == 0) {
        (yyval.node) = newAASNodeStmt(KInput);
        (yyval.node)->type = KInt;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString("input");
    } else if (strcmp((yyvsp[(1) - (4)].node)->name, "output") == 0) {
        (yyval.node) = newAASNodeStmt(KOutput);
        (yyval.node)->type = KVoid;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString("output");
        addAASNode((yyval.node), (yyvsp[(3) - (4)].node));
    } else {
        (yyval.node) = newAASNodeStmt(KCall);
        (yyval.node)->type = (yyvsp[(1) - (4)].node)->type;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString((yyvsp[(1) - (4)].node)->name);
        addAASNode((yyval.node), (yyvsp[(3) - (4)].node));
    }
;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 348 "bison.y"
    {
    if (strcmp((yyvsp[(1) - (3)].node)->name, "input") == 0) {
        (yyval.node) = newAASNodeStmt(KInput);
        (yyval.node)->type = KInt;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString("input");
    } else if (strcmp((yyvsp[(1) - (3)].node)->name, "output") == 0) {
        (yyval.node) = newAASNodeStmt(KOutput);
        (yyval.node)->type = KVoid;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString("output");
    } else {
        (yyval.node) = newAASNodeStmt(KCall);
        (yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->name = copyString((yyvsp[(1) - (3)].node)->name);
    }
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 371 "bison.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 374 "bison.y"
    {
        if ((yyvsp[(1) - (3)].node) == NULL) {
            (yyval.node) = (yyvsp[(3) - (3)].node);
        } else {
            (yyval.node) = (yyvsp[(1) - (3)].node);
            addAASNodeSibling((yyval.node), (yyvsp[(3) - (3)].node));
        }
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 382 "bison.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 387 "bison.y"
    {
        (yyval.node) = newAASNodeExp(KId);
        (yyval.node)->token = lex->token;
        (yyval.node)->line = lex->line;
        (yyval.node)->type = KInt;
        (yyval.node)->name = copyString(lex->lexema);
        (yyval.node)->escopo = copyString("global");
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 397 "bison.y"
    {
        (yyval.node) = newAASNodeExp(KConst);
        (yyval.node)->value = atoi(lex->lexema);
        (yyval.node)->type = KInt;
        (yyval.node)->line = lex->line;
        (yyval.node)->token = lex->token;
        (yyval.node)->escopo = copyString("global");
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2181 "bison.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 406 "bison.y"

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
            generateIntermediateCode(root, finter);
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
