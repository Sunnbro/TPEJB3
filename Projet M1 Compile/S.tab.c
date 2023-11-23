
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
#line 1 "S.y"

  #include <stddef.h>
  #include "quad.h"
  
  int nb_lignes=1, nb_colonnes=1;
	char sauvType[25];
  int sauvdeb;
  char sauvStruct[25];
  int cptTemp=1;
  
    

/* Line 189 of yacc.c  */
#line 86 "S.tab.c"

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
     dt_div = 258,
     pr_div = 259,
     IF = 260,
     ELSE = 261,
     FOR = 262,
     STRUCT = 263,
     WHILE = 264,
     idf = 265,
     integer = 266,
     flt = 267,
     minus = 268,
     plus = 269,
     times = 270,
     divise = 271,
     G = 272,
     L = 273,
     EQ = 274,
     GE = 275,
     LE = 276,
     DI = 277,
     egl = 278,
     and = 279,
     or = 280,
     not = 281,
     INTEGER = 282,
     FLOAT = 283,
     CONST = 284,
     point = 285,
     vrg = 286,
     pvg = 287,
     Dpoints = 288,
     Pouvr = 289,
     Pferm = 290,
     accol = 291,
     accor = 292,
     baro = 293,
     barf = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 13 "S.y"

         int rxtype;
         char* str;
         struct{
                char* vlr; 
                char* type;
           }Strutype;



/* Line 214 of yacc.c  */
#line 172 "S.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 184 "S.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    17,    19,    21,    24,    27,    30,
      33,    34,    38,    45,    47,    51,    55,    59,    61,    68,
      69,    75,    79,    80,    86,    90,    92,    95,    96,    98,
     100,   102,   104,   109,   117,   124,   128,   132,   134,   138,
     142,   144,   149,   151,   155,   157,   161,   165,   169,   172,
     176,   180,   184,   188,   192,   196,   198,   200,   202,   203,
     213,   214,   215,   222,   223,   224,   234,   235,   236,   237,
     249,   255
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    -1,    10,    42,    36,     3,    36,    44,
      37,     4,    36,    55,    37,    37,    -1,    28,    -1,    27,
      -1,    45,    44,    -1,    47,    44,    -1,    49,    44,    -1,
      52,    44,    -1,    -1,    43,    46,    32,    -1,    43,    10,
      38,    11,    39,    32,    -1,    10,    -1,    10,    31,    46,
      -1,    29,    48,    32,    -1,    10,    23,    62,    -1,    10,
      -1,     8,    36,    50,    37,    10,    32,    -1,    -1,    43,
      10,    32,    51,    50,    -1,    43,    10,    32,    -1,    -1,
       8,    10,    53,    54,    32,    -1,    10,    31,    54,    -1,
      10,    -1,    56,    55,    -1,    -1,    63,    -1,    57,    -1,
      68,    -1,    71,    -1,    10,    23,    58,    32,    -1,    10,
      38,    11,    39,    23,    58,    32,    -1,    10,    30,    10,
      23,    58,    32,    -1,    58,    14,    59,    -1,    58,    13,
      59,    -1,    59,    -1,    59,    15,    60,    -1,    59,    16,
      60,    -1,    60,    -1,    10,    38,    11,    39,    -1,    10,
      -1,    10,    30,    10,    -1,    62,    -1,    34,    58,    35,
      -1,    61,    25,    61,    -1,    61,    24,    61,    -1,    26,
      61,    -1,    61,    17,    58,    -1,    61,    18,    58,    -1,
      61,    19,    58,    -1,    61,    20,    58,    -1,    61,    21,
      58,    -1,    61,    22,    58,    -1,    58,    -1,    12,    -1,
      11,    -1,    -1,     5,    34,    61,    35,    64,    36,    55,
      37,    65,    -1,    -1,    -1,     6,    36,    66,    55,    67,
      37,    -1,    -1,    -1,     9,    69,    34,    61,    70,    35,
      36,    55,    37,    -1,    -1,    -1,    -1,    75,    33,    11,
      72,    76,    35,    73,    36,    55,    74,    37,    -1,     7,
      34,    10,    33,    11,    -1,    33,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    45,    49,    50,    53,    53,    53,    53,
      54,    56,    57,    65,    69,    76,    78,    94,   100,   105,
     105,   111,   119,   119,   128,   137,   146,   146,   149,   150,
     151,   152,   158,   191,   228,   263,   272,   282,   286,   296,
     308,   312,   331,   347,   362,   372,   378,   386,   394,   399,
     407,   414,   423,   430,   438,   446,   452,   457,   465,   465,
     473,   477,   473,   483,   484,   483,   503,   509,   514,   502,
     520,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "dt_div", "pr_div", "IF", "ELSE", "FOR",
  "STRUCT", "WHILE", "idf", "integer", "flt", "minus", "plus", "times",
  "divise", "G", "L", "EQ", "GE", "LE", "DI", "egl", "and", "or", "not",
  "INTEGER", "FLOAT", "CONST", "point", "vrg", "pvg", "Dpoints", "Pouvr",
  "Pferm", "accol", "accor", "baro", "barf", "$accept", "S", "$@1", "TYPE",
  "dec", "dec_var", "list_variables", "dec_cst", "ent", "def_struc",
  "defst", "$@2", "dec_struc", "$@3", "decst", "list_inst", "INST",
  "Affectation", "expressionArith", "terme", "facteur", "ExpCondition",
  "val", "IF_STATEMENT", "$@4", "elsebloc", "$@5", "$@6",
  "WHILE_STATEMENT", "$@7", "$@8", "for_boucle", "$@9", "$@10", "$@11",
  "FORA", "FORB", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    41,    43,    43,    44,    44,    44,    44,
      44,    45,    45,    46,    46,    47,    48,    48,    49,    51,
      50,    50,    53,    52,    54,    54,    55,    55,    56,    56,
      56,    56,    57,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    64,    63,
      66,    67,    65,    69,    70,    68,    72,    73,    74,    71,
      75,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,    12,     1,     1,     2,     2,     2,     2,
       0,     3,     6,     1,     3,     3,     3,     1,     6,     0,
       5,     3,     0,     5,     3,     1,     2,     0,     1,     1,
       1,     1,     4,     7,     6,     3,     3,     1,     3,     3,
       1,     4,     1,     3,     1,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     0,     9,
       0,     0,     6,     0,     0,     9,     0,     0,     0,    11,
       5,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     0,     0,    10,     0,     5,
       4,     0,     0,     0,    10,    10,    10,    10,    22,     0,
      17,     0,    13,     0,     0,     6,     7,     8,     9,     0,
       0,     0,     0,    15,     0,     0,    11,     0,    25,     0,
       0,     0,    57,    56,    16,    13,    14,     0,    27,     0,
      23,    19,     0,     0,     0,     0,    63,     0,     0,    27,
      29,    28,    30,    31,     0,    24,     0,    18,    12,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    20,    42,
       0,     0,    55,    37,    40,     0,    44,     0,     0,     0,
       0,     0,     3,    66,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,    64,    32,     0,     0,     0,    43,     0,    45,
      36,    35,    38,    39,    49,    50,    51,    52,    53,    54,
      47,    46,     0,    70,     0,     0,     0,     0,     0,    41,
      27,     0,    34,     0,    71,    67,     0,    27,    33,     0,
       0,     0,    27,     0,    59,    65,    68,    60,     0,    27,
      69,    61,     0,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    12,    13,    14,    23,    15,    21,    16,
      31,    66,    17,    29,    39,    58,    59,    60,    82,    83,
      84,    85,    86,    61,   132,   154,   159,   162,    62,    71,
     134,    63,   116,   149,   158,    64,   138
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
      -3,   -72,    12,   -15,   -72,    39,     2,    17,    -7,   -72,
     -72,    48,    57,    70,    17,    17,    17,    17,   -72,   -10,
      51,    40,    33,    76,   105,   -72,   -72,   -72,   -72,   100,
     101,    75,    15,   -72,   103,   104,   -72,    78,    85,    86,
      88,   107,   -72,   -72,   -72,    90,   -72,    80,    68,   100,
     -72,    89,    91,    92,    93,    94,   -72,    38,    95,    68,
     -72,   -72,   -72,   -72,    96,   -72,   -10,   -72,   -72,    -6,
     112,    97,     3,   115,   119,    98,   -72,   122,   -72,   -14,
      -6,     3,    49,    64,   -72,    35,   -72,   106,    -6,     9,
     111,    99,   -72,   -72,   126,   129,    77,    -5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,    -6,    -6,
     -72,   130,    65,   -72,     3,   114,   109,   -72,   108,   -72,
      64,    64,   -72,   -72,    49,    49,    49,    49,    49,    49,
      77,    77,   110,   -72,   113,    34,     3,   133,   116,   -72,
      68,   117,   -72,    37,   -72,   -72,   118,    68,   -72,   120,
     138,   121,    68,   123,   -72,   -72,   -72,   -72,   124,    68,
     -72,   -72,   125,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   -17,    87,   -72,   131,   -72,   -72,   -72,
      79,   -72,   -72,   -72,   127,   -59,   -72,   -72,   -71,     7,
      -9,   -69,   128,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -22
static const yytype_int16 yytable[] =
{
      76,    89,    30,    18,    79,    42,    43,     1,    98,    99,
      97,    96,     4,    79,    42,    43,    94,     9,    10,   112,
      80,     5,    98,    99,    95,     8,    42,    43,    81,    19,
     119,   124,   125,   126,   127,   128,   129,    81,     7,   130,
     131,   113,     6,   135,     9,    10,    11,    98,    99,    30,
      98,    99,   102,   103,   104,   105,   106,   107,    20,   108,
     109,    72,    98,    99,    34,   143,   142,    22,    73,   148,
     110,    35,    33,    54,    32,    55,    74,    56,    57,   100,
     101,   146,   102,   103,   104,   105,   106,   107,   151,   108,
     109,   122,   123,   156,   102,   103,   104,   105,   106,   107,
     161,    25,    26,    27,    28,   120,   121,    24,    36,    37,
      38,    40,    41,    45,    48,    47,    49,    52,    50,    53,
      51,    34,    87,    67,    68,    90,   -21,    69,    70,    77,
      91,    88,    75,    93,   114,    92,   117,   136,   115,   111,
     118,   133,   137,   144,   153,    78,   140,   139,   141,     0,
       0,   145,     0,   147,     0,   150,   152,     0,   155,   157,
      44,   160,   163,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65
};

static const yytype_int16 yycheck[] =
{
      59,    72,    19,    10,    10,    11,    12,    10,    13,    14,
      81,    80,     0,    10,    11,    12,    30,    27,    28,    88,
      26,    36,    13,    14,    38,     8,    11,    12,    34,    36,
      35,   102,   103,   104,   105,   106,   107,    34,    36,   108,
     109,    32,     3,   114,    27,    28,    29,    13,    14,    66,
      13,    14,    17,    18,    19,    20,    21,    22,    10,    24,
      25,    23,    13,    14,    31,   136,    32,    10,    30,    32,
      35,    38,    32,     5,    23,     7,    38,     9,    10,    15,
      16,   140,    17,    18,    19,    20,    21,    22,   147,    24,
      25,   100,   101,   152,    17,    18,    19,    20,    21,    22,
     159,    14,    15,    16,    17,    98,    99,    37,    32,     4,
      10,    10,    37,    10,    36,    11,    31,    10,    32,    39,
      32,    31,    10,    32,    32,    10,    37,    34,    34,    33,
      11,    34,    37,    11,    23,    37,    10,    23,    39,    33,
      11,    11,    33,    10,     6,    66,    36,    39,    35,    -1,
      -1,    35,    -1,    36,    -1,    37,    36,    -1,    37,    36,
      32,    37,    37,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    41,    42,     0,    36,     3,    36,     8,    27,
      28,    29,    43,    44,    45,    47,    49,    52,    10,    36,
      10,    48,    10,    46,    37,    44,    44,    44,    44,    53,
      43,    50,    23,    32,    31,    38,    32,     4,    10,    54,
      10,    37,    11,    12,    62,    10,    46,    11,    36,    31,
      32,    32,    10,    39,     5,     7,     9,    10,    55,    56,
      57,    63,    68,    71,    75,    54,    51,    32,    32,    34,
      34,    69,    23,    30,    38,    37,    55,    33,    50,    10,
      26,    34,    58,    59,    60,    61,    62,    10,    34,    58,
      10,    11,    37,    11,    30,    38,    61,    58,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    24,    25,
      35,    33,    61,    32,    23,    39,    72,    10,    11,    35,
      59,    59,    60,    60,    58,    58,    58,    58,    58,    58,
      61,    61,    64,    11,    70,    58,    23,    33,    76,    39,
      36,    35,    32,    58,    10,    35,    55,    36,    32,    73,
      37,    55,    36,     6,    65,    37,    55,    36,    74,    66,
      37,    55,    67,    37
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
#line 45 "S.y"
    {insererVal((yyvsp[(1) - (1)].str),"nomprog");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 46 "S.y"
    { printf(" Le programme est correcte syntaxiquement \n"); YYACCEPT; ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 49 "S.y"
    {(yyval.rxtype)=2; strcpy(sauvType, "float");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 50 "S.y"
    {(yyval.rxtype)=0; strcpy(sauvType, "integer");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 57 "S.y"
    { if(Existe((yyvsp[(2) - (6)].str))!=0)   { 
                                if(atoi((yyvsp[(4) - (6)].str))>0){insererTYPE((yyvsp[(2) - (6)].str),sauvType);insererTaille((yyvsp[(2) - (6)].str),(yyvsp[(1) - (6)].rxtype),atoi((yyvsp[(4) - (6)].str)));}
                                 
                                else{printf("\n Taille Tableau incorrecte: doit etre superieure a 0 \n");}
  }else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(2) - (6)].str),nb_lignes,nb_colonnes);
                              ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 65 "S.y"
    { if(Existe((yyvsp[(1) - (1)].str))!=0)   { insererTYPE((yyvsp[(1) - (1)].str),sauvType);  }
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(1) - (1)].str),nb_lignes,nb_colonnes);
                              ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 69 "S.y"
    { if(Existe((yyvsp[(1) - (3)].str))!=0)   { insererTYPE((yyvsp[(1) - (3)].str),sauvType);}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(1) - (3)].str),nb_lignes,nb_colonnes);
                              ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 78 "S.y"
    { if(Existe((yyvsp[(1) - (3)].str))!=0)   { insererTYPE((yyvsp[(1) - (3)].str),"CONST");
                                           //float ab;
                                          // ab = $3.vlr[0];
                                        //  if($3.vlr == NULL){
                                          //printf("\n ici C'EST NULLL ici \n");
                                         // }
                                          //insererVal($1,"RAS");
                                          insererVal((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].Strutype).vlr);
                                           
                                           //float flt;
                                           //flt=atof($3.vlr);
                                          // insererVal($1,flt);
                                            }
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(1) - (3)].str),nb_lignes,nb_colonnes);
                              ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 94 "S.y"
    { if(Existe((yyvsp[(1) - (1)].str))!=0)   { insererTYPE((yyvsp[(1) - (1)].str),"CONST");insererVal((yyvsp[(1) - (1)].str),"RAS");}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(1) - (1)].str),nb_lignes,nb_colonnes);
                              ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 100 "S.y"
    {if(Existe((yyvsp[(5) - (6)].str))!=0){insererTYPE((yyvsp[(5) - (6)].str),"STRUCT");}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(5) - (6)].str),nb_lignes,nb_colonnes);
                              ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 105 "S.y"
    {if(Existe((yyvsp[(2) - (3)].str))!=0)   {  insererTYPE((yyvsp[(2) - (3)].str),sauvType); insererVal((yyvsp[(2) - (3)].str),"VarEnrg");}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(2) - (3)].str),nb_lignes,nb_colonnes);
                              ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 111 "S.y"
    { if(Existe((yyvsp[(2) - (3)].str))!=0)   { insererTYPE((yyvsp[(2) - (3)].str),sauvType); insererVal((yyvsp[(2) - (3)].str),"VarEnrg");}//printf(" JE SUIS UN %s !!!",sauvType);}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(2) - (3)].str),nb_lignes,nb_colonnes);
                              ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 119 "S.y"
    {if(Existe((yyvsp[(2) - (2)].str))==0) { //verifie si idf est bien declare
                                strcpy(sauvStruct,(yyvsp[(2) - (2)].str));
                                
                              }
                                else{
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n",(yyvsp[(2) - (2)].str),nb_lignes,nb_colonnes);
                              }
                              ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 128 "S.y"
    {if(Existe((yyvsp[(1) - (3)].str))!=0) { 
  //printf("JE SUIS ICIIIIIIIIIIIIIIII \n");
 
  
  insererTYPE((yyvsp[(1) - (3)].str),sauvStruct);}
else{
                                 printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(1) - (3)].str),nb_lignes,nb_colonnes);
}
                              ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 137 "S.y"
    {if(Existe((yyvsp[(1) - (1)].str))!=0) { insererTYPE((yyvsp[(1) - (1)].str),sauvStruct);}
else{
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",(yyvsp[(1) - (1)].str),nb_lignes,nb_colonnes);
}
                              ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 158 "S.y"
    {//verifier que c declare 
                                if(Existe((yyvsp[(1) - (4)].str))!=0)
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", (yyvsp[(1) - (4)].str), nb_lignes, nb_colonnes);

                                else //verifier que ce n'est pas une constante
                                  {if(GetNature((yyvsp[(1) - (4)].str))==0)
                                        printf(" \n Erreur semantique: Impossible de modifier la Constante %s a la ligne %d et a la colonne %d \n",(yyvsp[(1) - (4)].str),nb_lignes,nb_colonnes);
                                     else{ 
                                      printf("\n \n -------------TYPE VAR IDF1: %s----------    .%s. \n \n",(yyvsp[(1) - (4)].str),GetType((yyvsp[(1) - (4)].str)));
                                     printf("\n \n -------------TYPE VAR IDF2: ----------    .%s. \n \n",(yyvsp[(3) - (4)].Strutype).type);
                                
                                if(strcmp((yyvsp[(3) - (4)].Strutype).type, "") != 0 && strcmp(GetType((yyvsp[(1) - (4)].str)), "") != 0 )
                                
                                      {
                                        if(strcmp(GetType((yyvsp[(1) - (4)].str)),(yyvsp[(3) - (4)].Strutype).type)!=0)//si les 2 types differents
                                      { printf("\n Erreur semantique : Incompatibilite des types \n");

           
                                            }
                                        else{
                                          insererVal((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].Strutype).vlr);
                                          //inserer val pcq les types sont compatibles
                                          //inserer($1,$3.vlr);                                          

                                        }    }
                             // 


                                     }    }
                       createQuad("=",(yyvsp[(3) - (4)].Strutype).vlr,"",(yyvsp[(1) - (4)].str));
                      ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 191 "S.y"
    {if(Existe((yyvsp[(1) - (7)].str))!=0){
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", (yyvsp[(1) - (7)].str), nb_lignes, nb_colonnes);

               }
               else{
               // printf("\n \n -------------TYPE VAR IDF1: %s----------    .%s. \n \n",$1,GetType($1));
                                
                             if(strcmp((yyvsp[(6) - (7)].Strutype).type, "") != 0 && strcmp(GetType((yyvsp[(1) - (7)].str)), "") != 0 )
                             {//printf("les deux arguments de l'affectation sont des string || 3.type= %s et 1= %s !",$3.type,GetType($1));
                             if(strcmp(GetType((yyvsp[(1) - (7)].str)),(yyvsp[(6) - (7)].Strutype).type)!=0)

        { printf("\n Erreur semantique : Incompatibilite des types \n");

           
        }
        else{
          if(Validindex((yyvsp[(1) - (7)].str),(yyvsp[(3) - (7)].str))==0){
                                printf(" \n Index Incorrect non compris entre 0 et la taille du tableau \n");
                              }
                            else{insererValTab((yyvsp[(1) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(6) - (7)].Strutype).vlr);
                             char* format = "[%s]";
                             char suffix[strlen(format) + strlen((yyvsp[(3) - (7)].str)) - 1]; // alloue de la memoire pour la chaîne suffixe
                             sprintf(suffix, format, (yyvsp[(3) - (7)].str));
                             char* result = malloc(strlen((yyvsp[(1) - (7)].str)) + strlen(suffix) + 1);
                              strcpy(result, (yyvsp[(1) - (7)].str));
                              strcat(result, suffix);
                              (yyvsp[(1) - (7)].str)=result;
                              //insererValTab($1,$3,$6.vlr);
                              createQuad("=",(yyvsp[(6) - (7)].Strutype).vlr,"",(yyvsp[(1) - (7)].str));}


}}
               }
                              ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 228 "S.y"
    {//verifier que c declare 
                                if(Existe((yyvsp[(1) - (6)].str))!=0 || Existe((yyvsp[(3) - (6)].str))!=0 || Existe(GetType((yyvsp[(1) - (6)].str)))!=0 ) //exmple: Nri type Nomstr
                                  printf("\n Erreur semantique : IDF NON DECLARE a la ligne %d et à la colonne %d \n",  nb_lignes, nb_colonnes);

                                else //struct existe 
                                  {
                                      printf("\n \n -------------TYPE VAR IDF1: %s----------    .%s. \n \n",(yyvsp[(3) - (6)].str),GetType((yyvsp[(3) - (6)].str)));
                                     printf("\n \n -------------TYPE VAR IDF2: ----------    .%s. \n \n",(yyvsp[(5) - (6)].Strutype).type);
                                
                                if(strcmp((yyvsp[(5) - (6)].Strutype).type, "") != 0 && strcmp(GetType((yyvsp[(3) - (6)].str)), "") != 0 )
                                
                                      {
                                        if(strcmp(GetType((yyvsp[(3) - (6)].str)),(yyvsp[(5) - (6)].Strutype).type)!=0)//si les 2 types differents
                                      { printf("\n Erreur semantique : Incompatibilite des types \n");

           
                                            }
                                        else{
                                          char enrg[10];
                                          sprintf(enrg,"%s.%s",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str));
                                          EntiteInsert(enrg,"IDF",GetType((yyvsp[(3) - (6)].str)),0,0);
                                          insererVal(enrg,(yyvsp[(5) - (6)].Strutype).vlr);
                                          //inserer val pcq les types sont compatibles
                                          //inserer($1,$3.vlr);                                          
                                          createQuad("=",(yyvsp[(5) - (6)].Strutype).vlr,"",enrg);
                                        }    }
                             // 


                                         }
                       
                      ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 263 "S.y"
    {if((yyvsp[(1) - (3)].Strutype).type=="integer" && (yyvsp[(3) - (3)].Strutype).type=="integer")//si l'un des 2 est un float donc res est float 
              {(yyval.Strutype).type="integer";}
              else if((yyvsp[(1) - (3)].Strutype).type=="float" || (yyvsp[(3) - (3)].Strutype).type=="float") (yyval.Strutype).type="float";
              (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);          //(terme plus terme)=(+,$1.vlr,$3.vlr,$$.vlr)    terme($$.vlr=T1) plus terme ($$.vlr=3)   (+,$1.vlr,$3.vlr,$$.vlr)          
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
                                          createQuad("+",(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
                                          cptTemp++;
                      ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 272 "S.y"
    {if((yyvsp[(1) - (3)].Strutype).type=="integer" && (yyvsp[(3) - (3)].Strutype).type=="integer")//si l'un des 2 est un float donc res est float 
              {(yyval.Strutype).type="integer";}
              else if((yyvsp[(1) - (3)].Strutype).type=="float" || (yyvsp[(3) - (3)].Strutype).type=="float") (yyval.Strutype).type="float";
              (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
                                          createQuad("-",(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
                                          cptTemp++;
                      ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 282 "S.y"
    {(yyval.Strutype).type=(yyvsp[(1) - (1)].Strutype).type;
            (yyval.Strutype).vlr=(yyvsp[(1) - (1)].Strutype).vlr;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 286 "S.y"
    {if((yyvsp[(1) - (3)].Strutype).type=="integer" && (yyvsp[(3) - (3)].Strutype).type=="integer")//si l'un des 2 est un float donc res est float 
              {(yyval.Strutype).type="integer";}
              else if((yyvsp[(1) - (3)].Strutype).type=="float" || (yyvsp[(3) - (3)].Strutype).type=="float") (yyval.Strutype).type="float";
             
              (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
                                          createQuad("*",(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
                                          cptTemp++;
            ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 296 "S.y"
    {if((yyvsp[(1) - (3)].Strutype).type=="integer" && (yyvsp[(3) - (3)].Strutype).type=="integer")//si l'un des 2 est un float donc res est float 
              {(yyval.Strutype).type="integer";}
              else if((yyvsp[(1) - (3)].Strutype).type=="float" || (yyvsp[(3) - (3)].Strutype).type=="float") (yyval.Strutype).type="float";
             if(strcmp((yyvsp[(3) - (3)].Strutype).vlr,"0")==0){ printf("\n Erreur semantique : Division par 0 \n");
}
             
              (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
                                          createQuad("/",(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
                                          cptTemp++;
            ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 308 "S.y"
    { (yyval.Strutype).type=(yyvsp[(1) - (1)].Strutype).type;
                      (yyval.Strutype).vlr=(yyvsp[(1) - (1)].Strutype).vlr;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 313 "S.y"
    {if(Existe((yyvsp[(1) - (4)].str))!=0)
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", (yyvsp[(1) - (4)].str), nb_lignes, nb_colonnes);

                             else{//verifier que l'index compris dans la taille du tab
                              if(Validindex((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str))==0){
                                printf(" \n Index Incorrect non compris entre 0 et la taille du tableau \n");
                              }
                              (yyval.Strutype).type=GetType((yyvsp[(1) - (4)].str));
                             char* format = "[%s]";
                             char suffix[strlen(format) + strlen((yyvsp[(3) - (4)].str)) - 1]; // alloue de la memoire pour la chaîne suffixe
                             sprintf(suffix, format, (yyvsp[(3) - (4)].str));
                             char* result = malloc(strlen((yyvsp[(1) - (4)].str)) + strlen(suffix) + 1);
                              strcpy(result, (yyvsp[(1) - (4)].str));
                              strcat(result, suffix);
                              (yyval.Strutype).vlr=result;}
                             
                              ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 332 "S.y"
    {if(Existe((yyvsp[(1) - (1)].str))!=0)
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", (yyvsp[(1) - (1)].str), nb_lignes, nb_colonnes);

                              
                    else{
                    
                    //  printf("\n \n -------------TYPE VAR IDF2: %s----------    .%s. \n \n",$1,GetType($1));
                      if(strcmp(GetType((yyvsp[(1) - (1)].str)),"integer")==0||strcmp(GetType((yyvsp[(1) - (1)].str)),"float")==0){
                        (yyval.Strutype).vlr=strdup((yyvsp[(1) - (1)].str));//strdup(GetVal($1)); //get val retourne la valeur de l'idf2  idf=idf2
                        (yyval.Strutype).type=GetType((yyvsp[(1) - (1)].str)); 
                      }
                    }
                    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 347 "S.y"
    {//verifier que c declare 
                                if(Existe((yyvsp[(1) - (3)].str))!=0 || Existe((yyvsp[(3) - (3)].str))!=0 || Existe(GetType((yyvsp[(1) - (3)].str)))!=0 ) //exmple: Nri type Nomstr
                                  printf("\n Erreur semantique : IDF NON DECLARE a la ligne %d et à la colonne %d \n",  nb_lignes, nb_colonnes);

                                else{
                                  if(strcmp(GetType((yyvsp[(3) - (3)].str)),"integer")==0||strcmp(GetType((yyvsp[(3) - (3)].str)),"float")==0){
                        char enrg[10];
                        sprintf(enrg,"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
                        (yyval.Strutype).vlr=strdup(enrg);//strdup(GetVal($1)); //get val retourne la valeur de l'idf2  idf=idf2
                        (yyval.Strutype).type=GetType((yyvsp[(3) - (3)].str)); 
                      }

                                }
                                ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 362 "S.y"
    {
                     //if(strcmp($1.type,"integer")==0)printf("comparaison marche avec string strcmp");
                    // printf("\n \n -------------TYPE VALEUR IDF2: ------------    .%s. \n \n",$1.type);
                     // if(strcmp(GetType($1),"integer")==0||strcmp(GetType($1),"float")==0){
                     (yyval.Strutype).vlr=strdup((yyvsp[(1) - (1)].Strutype).vlr); 
                     
                       (yyval.Strutype).type=(yyvsp[(1) - (1)].Strutype).type; 
                      
                    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 372 "S.y"
    {(yyval.Strutype).type=(yyvsp[(2) - (3)].Strutype).type; (yyval.Strutype).vlr=strdup((yyvsp[(2) - (3)].Strutype).vlr);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 380 "S.y"
    {
             (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
            sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
            createQuadL(2,(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
            cptTemp++;
            ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 388 "S.y"
    {
              (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
            sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
            createQuadL(3,(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
            cptTemp++;
            ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 394 "S.y"
    {//$2.vlr=strdup($$.vlr);
            sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
            createQuadL(1,(yyvsp[(2) - (2)].Strutype).vlr,"",(yyval.Strutype).vlr);
            cptTemp++;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 400 "S.y"
    {
                (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
              createQuadA(6,(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
              cptTemp++;
            ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 408 "S.y"
    {
                (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
              createQuadA(5,(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
              cptTemp++;
            ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 416 "S.y"
    {
                (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
              createQuadA(1,(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
              cptTemp++;
            ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 424 "S.y"
    {
              (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
              createQuadA(3,(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
              cptTemp++;
            ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 431 "S.y"
    {
                (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
              createQuadA(4,(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
              cptTemp++;
            ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 439 "S.y"
    {
                (yyvsp[(1) - (3)].Strutype).vlr=strdup((yyval.Strutype).vlr);
              sprintf((yyval.Strutype).vlr,"T%d",cptTemp);
              createQuadA(2,(yyvsp[(1) - (3)].Strutype).vlr,(yyvsp[(3) - (3)].Strutype).vlr,(yyval.Strutype).vlr);
              cptTemp++;
            ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 447 "S.y"
    {(yyval.Strutype).vlr=strdup((yyvsp[(1) - (1)].Strutype).vlr);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 452 "S.y"
    {(yyval.Strutype).type = (char *) malloc(sizeof(char) * 7); // 7 = longueur maximale de "float" + 1 pour le caractère nul
        strcpy((yyval.Strutype).type, "float");
        (yyval.Strutype).vlr = (char *) malloc(sizeof(char) * 8);
        strcpy((yyval.Strutype).vlr, (yyvsp[(1) - (1)].str));
        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 457 "S.y"
    {(yyval.Strutype).type = (char *) malloc(sizeof(char) * 8); // 8 = longueur maximale de "integer" + 1 pour le caractère nul
        strcpy((yyval.Strutype).type, "integer");
        (yyval.Strutype).vlr = (char *) malloc(sizeof(char) * 8);
        strcpy((yyval.Strutype).vlr, (yyvsp[(1) - (1)].str));
        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 465 "S.y"
    { 
          empiler_Int(&pile2,qc-1);
                                     // pile 2 fiha les sauvdeb, apres ndirlo update f fin du THEN
                                    

          ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 473 "S.y"
    {
            QuadR[atoi(depiler(&pile2))].opd1=ToSTR(qc+1); //update quad cond li yb3et lel ELSE (qc raho f pile2)
            empiler_Int(&pile1,qc);
            createQuad("BR","","","");// creer quad BR vide pour fin ta3 THEN, il faut empiler bach nwlilo
            ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 477 "S.y"
    {
           
            QuadR[atoi(depiler(&pile1))].opd1=ToSTR(qc); //update du quad BR hada Quad FIN 
            ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 483 "S.y"
    {empiler_Int(&pile1,qc);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 484 "S.y"
    { empiler_Int(&pile2,qc-1); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 486 "S.y"
    {createQuad("BR",depiler(&pile1),"",""); //quad br pour retour a la cond debut
                         
                      /*   int qtemp=atoi(depiler(&pile2)); //exception condition AND et OR car ya 2 quads win mise a jour des opt1
                          if(strcmp(QuadR[qtemp].opt,"BZ")==0 && !strcmp(QuadR[qtemp+1].opt,"BZ")==0)
                          {QuadR[qtemp-1].opd1=ToSTR(qc);
                           QuadR[qtemp].opd1=ToSTR(qc); }

                         //else if(strcmp(QuadR[qtemp].opt,"BNZ")==0 && !strcmp(QuadR[qtemp+1].opt,"BNZ")==0){}
                         else{ */
                          QuadR[atoi(depiler(&pile2))].opd1=ToSTR(qc);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 503 "S.y"
    { empiler_Int(&pile1,qc); //Les BR fla fin ywlo hna pour incrementer
                createQuad("+",(yyvsp[(3) - (3)].str),"",(yyvsp[(1) - (3)].Strutype).vlr);
                empiler_Int(&pile3,qc);
              createQuadA(4,(yyvsp[(1) - (3)].Strutype).vlr,"","");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 509 "S.y"
    {empiler_Int(&pile2,qc-1);
                
               
              ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 514 "S.y"
    {createQuad("BR",depiler(&pile1),"","");   // creer quad bach nwelo l avant l'incrementation (debuter nouvelle iteration)
              QuadR[atoi(depiler(&pile2))].opd1=ToSTR(qc);  //  mise a jour 2eme arg (opd1) fl BR li yb3et l la fin ki tkoun la condition non satisfaite
                          ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 521 "S.y"
    { if(Existe((yyvsp[(3) - (5)].str))!=0)
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", (yyvsp[(3) - (5)].str), nb_lignes, nb_colonnes);

                              
                    else{
                createQuad("=",(yyvsp[(5) - (5)].str),"",(yyvsp[(3) - (5)].str));
              createQuad("BR",ToSTR(qc+2),"","");
              (yyval.Strutype).vlr=strdup((yyvsp[(3) - (5)].str));
              } ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 531 "S.y"
    {//$$.vlr=strdup($2);
 if(Existe((yyvsp[(2) - (2)].str))!=0)
                    printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", (yyvsp[(2) - (2)].str), nb_lignes, nb_colonnes);
                    else{
QuadR[atoi(depiler(&pile3))].res=strdup((yyvsp[(2) - (2)].str));};}
    break;



/* Line 1455 of yacc.c  */
#line 2209 "S.tab.c"
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
#line 536 "S.y"


int main ()
{
   initialisation();
   yyparse(); 
   afficherTSidf();//AFFICHAGE TS IDF+CST
   printf("\n -----------------------Quadruples Avant Optimisation-------------------------- \n");
   displayQuad();//affichage quads avant optimisation
   optimisation();// optimisation des quads
   printf("\n -----------------------Quadruples Apres Optimisation-------------------------- \n");
   displayQuad(); //affichage quads apres optimisation
   //afficherTSsuite();//AFFICHAGE TS Mots cles+ Seps
   ToAssembly();//generer fichier ASM 
   return 0;
}
yywrap () {}
int yyerror ( char*  msg )  
{
   printf ("Erreur Syntaxique a ligne %d a colonne %d \n", nb_lignes,nb_colonnes);
}

