/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "pc.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "y.tab.h"

extern int yylex();
extern int yyerror(char*);


FILE* yyin;


#line 81 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INUM = 258,
    RNUM = 259,
    PROGRAM = 260,
    ID = 261,
    VAR = 262,
    BBEGIN = 263,
    END = 264,
    PROCEDURE = 265,
    FUNCTION = 266,
    DOTS = 267,
    ARRAY = 268,
    OF = 269,
    INTEGER = 270,
    REAL = 271,
    RELOP = 272,
    EQ = 273,
    NE = 274,
    LT = 275,
    LE = 276,
    GT = 277,
    GE = 278,
    ASSIGNOP = 279,
    ADDOP = 280,
    PLUS = 281,
    MINUS = 282,
    OR = 283,
    MULOP = 284,
    STAR = 285,
    SLASH = 286,
    AND = 287,
    NOT = 288,
    IF = 289,
    THEN = 290,
    ELSE = 291,
    WHILE = 292,
    FOR = 293,
    DO = 294
  };
#endif
/* Tokens.  */
#define INUM 258
#define RNUM 259
#define PROGRAM 260
#define ID 261
#define VAR 262
#define BBEGIN 263
#define END 264
#define PROCEDURE 265
#define FUNCTION 266
#define DOTS 267
#define ARRAY 268
#define OF 269
#define INTEGER 270
#define REAL 271
#define RELOP 272
#define EQ 273
#define NE 274
#define LT 275
#define LE 276
#define GT 277
#define GE 278
#define ASSIGNOP 279
#define ADDOP 280
#define PLUS 281
#define MINUS 282
#define OR 283
#define MULOP 284
#define STAR 285
#define SLASH 286
#define AND 287
#define NOT 288
#define IF 289
#define THEN 290
#define ELSE 291
#define WHILE 292
#define FOR 293
#define DO 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "pc.y" /* yacc.c:355  */

    int ival; //NUM
    double dval; //REAL
    int opval; //RELOP ADDOP MULOP
    char* sval; //ID
    tree* tval;

#line 207 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   107

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    44,     2,    43,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    82,    83,    87,    88,    92,    93,    97,
      98,   102,   103,   107,   111,   112,   116,   117,   121,   122,
     126,   130,   131,   135,   136,   140,   141,   142,   143,   144,
     145,   150,   151,   155,   156,   160,   161,   165,   166,   170,
     171,   172,   176,   177,   181,   182,   183,   184,   185,   186,
     187
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INUM", "RNUM", "PROGRAM", "ID", "VAR",
  "BBEGIN", "END", "PROCEDURE", "FUNCTION", "DOTS", "ARRAY", "OF",
  "INTEGER", "REAL", "RELOP", "EQ", "NE", "LT", "LE", "GT", "GE",
  "ASSIGNOP", "ADDOP", "PLUS", "MINUS", "OR", "MULOP", "STAR", "SLASH",
  "AND", "NOT", "IF", "THEN", "ELSE", "WHILE", "FOR", "DO", "'('", "')'",
  "';'", "'.'", "','", "':'", "'['", "']'", "$accept", "program",
  "identifier_list", "declarations", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "arguments", "parameter_list", "compound_statement",
  "optional_statements", "statement_list", "statement", "variable",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      40,    41,    59,    46,    44,    58,    91,    93
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,    28,    38,    21,   -92,    65,   -92,    14,    30,    67,
     -92,   -92,    68,    65,    20,    -2,    17,    70,    71,    32,
     -92,    35,    34,    -7,     4,     4,   -92,    72,    37,   -92,
      56,   -92,    42,    42,   -92,    68,   -92,    40,   -92,   -92,
      41,   -92,     4,     4,   -92,   -92,   -24,     8,     8,     4,
      49,     1,    58,   -92,    50,   -92,    17,     4,    65,    46,
      45,    20,    88,   -92,    15,   -92,    47,     4,     4,    58,
     -92,    51,    17,     4,     8,     8,    17,   -92,   -92,    18,
      24,   -92,    52,   -92,    81,   -92,     4,   -92,    16,    48,
     -92,    60,    73,    58,   -92,   -92,    34,   -92,    65,    55,
      96,   -92,   -92,   -92,    17,   -92,    25,   -92,    53,   -92,
      34,    87,   -92,    52,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       6,     4,    12,     0,     0,     0,    22,     0,     0,     0,
       6,     0,     0,    33,     0,     0,    27,     0,    21,    23,
       0,    26,    17,    17,    11,    12,     2,     0,     9,    10,
       0,     7,     0,     0,    47,    48,    44,     0,     0,     0,
       0,    37,    39,    42,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     5,     0,    35,     0,     0,     0,    40,
      50,     0,     0,     0,     0,     0,     0,    24,    25,     0,
       0,    15,     0,    13,     0,    34,     0,    32,     0,     0,
      49,    28,    38,    41,    43,    30,     0,    16,     0,     0,
       0,    36,    45,    46,     0,    18,     0,    14,     0,    29,
       0,     0,    19,     0,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -13,    82,   -91,   -81,    69,   -92,   -92,    74,
     -92,    -8,   -92,   -92,   -52,   -92,   -92,    36,   -22,    33,
     -38,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    40,    41,    14,    19,    20,    59,
      80,    26,    27,    28,    29,    30,    31,    64,    65,    51,
      52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    99,    50,    54,    77,   105,    21,    44,    45,    69,
      46,    44,    45,    70,    46,     1,    67,   -31,    73,   112,
      91,    66,    68,    23,    95,    16,    74,    71,    16,    47,
      17,    18,   114,    42,     3,    78,    93,    48,     4,    43,
      94,    48,     9,    22,    49,    79,    89,    37,    49,    38,
      39,    24,   109,    83,    25,     8,    85,   102,     9,    86,
      86,     5,     9,    96,   101,    97,    98,    38,    39,     9,
     110,     6,    10,    11,    34,    13,    32,    33,    36,    56,
      57,    55,    58,    63,    72,   106,    62,    75,    81,    76,
      82,    84,    90,   100,    87,   103,   104,   107,    74,   108,
     111,   113,    35,    88,    61,     0,    92,    60
};

static const yytype_int8 yycheck[] =
{
      13,    82,    24,    25,    56,    96,    14,     3,     4,    47,
       6,     3,     4,    48,     6,     5,    40,    24,    17,   110,
      72,    43,    46,     6,    76,     8,    25,    49,     8,    25,
      10,    11,   113,    40,     6,    57,    74,    33,     0,    46,
      75,    33,    44,    45,    40,    58,    68,    13,    40,    15,
      16,    34,   104,    61,    37,    41,    41,    41,    44,    44,
      44,    40,    44,    45,    86,    41,    42,    15,    16,    44,
      45,     6,    42,     6,    42,     7,     6,     6,    43,    42,
      24,     9,    40,    42,    35,    98,    46,    29,    42,    39,
      45,     3,    41,    12,    47,    47,    36,    42,    25,     3,
      47,    14,    20,    67,    35,    -1,    73,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    49,     6,     0,    40,     6,    50,    41,    44,
      42,     6,    51,     7,    54,    50,     8,    10,    11,    55,
      56,    59,    45,     6,    34,    37,    59,    60,    61,    62,
      63,    64,     6,     6,    42,    51,    43,    13,    15,    16,
      52,    53,    40,    46,     3,     4,     6,    25,    33,    40,
      66,    67,    68,    69,    66,     9,    42,    24,    40,    57,
      57,    54,    46,    42,    65,    66,    66,    40,    46,    68,
      69,    66,    35,    17,    25,    29,    39,    62,    66,    50,
      58,    42,    45,    59,     3,    41,    44,    47,    65,    66,
      41,    62,    67,    68,    69,    62,    45,    41,    42,    53,
      12,    66,    41,    47,    36,    52,    50,    42,     3,    62,
      45,    47,    52,    14,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    56,    56,    57,    57,    58,    58,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     0,     1,     8,     1,
       1,     3,     0,     4,     6,     4,     3,     0,     3,     5,
       3,     1,     0,     1,     3,     3,     1,     1,     4,     6,
       4,     1,     4,     1,     4,     1,     3,     1,     3,     1,
       2,     3,     1,     3,     1,     4,     4,     1,     1,     3,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 78 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(0,0,(yyvsp[-6].tval),(yyvsp[-3].tval),(yyvsp[-2].tval),(yyvsp[-1].tval)); printTree((yyval.tval)); initCodeGen(); treeCheck((yyval.tval));}
#line 1379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(1,0); (yyval.tval)->attribute->sval=(yyvsp[0].sval);}
#line 1385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 83 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(1,1,(yyvsp[-2].tval)); (yyval.tval)->attribute->sval=(yyvsp[0].sval);}
#line 1391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 87 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(2,0,(yyvsp[-5].tval),(yyvsp[-3].tval),(yyvsp[-1].tval));}
#line 1397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 88 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(2,1);}
#line 1403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(3,0,(yyvsp[0].tval));}
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(3,1,(yyvsp[0].tval)); (yyval.tval)->attribute->ab = mkArrayBounds((yyvsp[-5].ival),(yyvsp[-3].ival));}
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(4,0);}
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 98 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(4,1);}
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 102 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(5,0,(yyvsp[-2].tval),(yyvsp[-1].tval));}
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 103 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(5,1);}
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(6,0,(yyvsp[-3].tval),(yyvsp[-2].tval),(yyvsp[-1].tval),(yyvsp[0].tval));}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 111 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(7,0,(yyvsp[-3].tval),(yyvsp[-1].tval)); (yyval.tval)->attribute->sval=(yyvsp[-4].sval);}
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(7,1,(yyvsp[-1].tval)); (yyval.tval)->attribute->sval=(yyvsp[-2].sval);}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 116 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(8,0,(yyvsp[-1].tval));}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(8,1);}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 121 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(9,0,(yyvsp[-2].tval),(yyvsp[0].tval));}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 122 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(9,1,(yyvsp[-4].tval),(yyvsp[-2].tval),(yyvsp[0].tval));}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 126 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(10,0,(yyvsp[-1].tval));}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 130 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(11,0,(yyvsp[0].tval));}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 131 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(11,1);}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 135 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(12,0,(yyvsp[0].tval));}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 136 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(12,1,(yyvsp[-2].tval),(yyvsp[0].tval));}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 140 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(13,0,(yyvsp[-2].tval),(yyvsp[0].tval));}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 141 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(13,1,(yyvsp[0].tval));}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 142 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(13,2,(yyvsp[0].tval));}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 143 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(13,3,(yyvsp[-2].tval),(yyvsp[0].tval));}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 144 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(13,4,(yyvsp[-4].tval),(yyvsp[-2].tval),(yyvsp[0].tval));}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 145 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(13,5,(yyvsp[-2].tval),(yyvsp[0].tval));}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 150 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(14,0); (yyval.tval)->attribute->sval=(yyvsp[0].sval);}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 151 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(14,1,(yyvsp[-1].tval)); (yyval.tval)->attribute->sval=(yyvsp[-3].sval);}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 155 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(15,0); (yyval.tval)->attribute->sval=(yyvsp[0].sval);}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 156 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(15,1,(yyvsp[-1].tval)); (yyval.tval)->attribute->sval=(yyvsp[-3].sval);}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 160 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(16,0,(yyvsp[0].tval));}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 161 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(16,1,(yyvsp[-2].tval),(yyvsp[0].tval));}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 165 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(17,0,(yyvsp[0].tval));}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 166 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(17,1,(yyvsp[-2].tval),(yyvsp[0].tval)); (yyval.tval)->attribute->opval=(yyvsp[-1].opval);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 170 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(18,0,(yyvsp[0].tval));}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 171 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(18,1,(yyvsp[0].tval)); (yyval.tval)->attribute->opval=(yyvsp[-1].opval);}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 172 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(18,2,(yyvsp[-2].tval),(yyvsp[0].tval)); (yyval.tval)->attribute->opval=(yyvsp[-1].opval);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 176 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(19,0,(yyvsp[0].tval));}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 177 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(19,1,(yyvsp[-2].tval),(yyvsp[0].tval)); (yyval.tval)->attribute->opval=(yyvsp[-1].opval);}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 181 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(20,0); (yyval.tval)->attribute->sval=(yyvsp[0].sval);}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 182 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(20,1,(yyvsp[-1].tval)); (yyval.tval)->attribute->sval=(yyvsp[-3].sval);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 183 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(20,2,(yyvsp[-1].tval)); (yyval.tval)->attribute->sval=(yyvsp[-3].sval);}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 184 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(20,3); (yyval.tval)->attribute->ival=(yyvsp[0].ival);}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 185 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(20,4); (yyval.tval)->attribute->dval=(yyvsp[0].dval);}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 186 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(20,5,(yyvsp[-1].tval));}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 187 "pc.y" /* yacc.c:1646  */
    {(yyval.tval) = mktree(20,6,(yyvsp[0].tval));}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1671 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 191 "pc.y" /* yacc.c:1906  */


int main(int argc, char** argv) {

    filename = argv[1];
    fprintf(stderr,"%s",filename);
    yyin = fopen(filename,"r");
    yyparse();


}
