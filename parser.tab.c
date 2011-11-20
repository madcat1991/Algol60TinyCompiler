
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
#line 73 "parser.tab.c"

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
     TBEGIN = 258,
     TEND = 259,
     TOWN = 260,
     TREAL = 261,
     TINTEGER = 262,
     TBOOLEAN = 263,
     TARRAY = 264,
     TSWITCH = 265,
     TPROCEDURE = 266,
     TSTRING = 267,
     TLABEL = 268,
     TVALUE = 269,
     TSTEP = 270,
     TUNTIL = 271,
     TWHILE = 272,
     TCOMMENT = 273,
     TGOTO = 274,
     TIF = 275,
     TTHEN = 276,
     TELSE = 277,
     TFOR = 278,
     TDO = 279,
     TEQUIV = 280,
     TIMPL = 281,
     TOR = 282,
     TAND = 283,
     TNOT = 284,
     TLESS = 285,
     TNOTGREATER = 286,
     TEQUAL = 287,
     TNOTLESS = 288,
     TGREATER = 289,
     TNOTEQUAL = 290,
     TTRUE = 291,
     TFALSE = 292,
     TPOWER = 293,
     TANY_SYMBOL_SEQ_WO_QUOTE = 294,
     TDIGIT = 295,
     TLETTER = 296,
     TASSIGN = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 157 "parser.tab.c"

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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   667

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNRULES -- Number of states.  */
#define YYNSTATES  311

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    61,     2,     2,    47,     2,    64,
      55,    56,    45,    43,    52,    44,    57,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    51,
      58,    59,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    49,    62,    63,     2,     2,     2,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    17,    20,    24,
      26,    30,    33,    36,    40,    42,    44,    46,    48,    51,
      53,    56,    58,    60,    62,    64,    68,    71,    75,    77,
      81,    86,    90,    92,    94,    98,   102,   104,   106,   111,
     113,   115,   119,   123,   128,   134,   136,   137,   141,   143,
     147,   149,   150,   154,   155,   159,   163,   165,   167,   169,
     172,   174,   176,   178,   181,   183,   187,   189,   191,   193,
     195,   197,   199,   201,   203,   207,   209,   211,   212,   214,
     216,   218,   221,   224,   226,   229,   232,   235,   238,   240,
     245,   247,   249,   253,   258,   261,   262,   266,   268,   272,
     274,   279,   281,   283,   285,   287,   289,   293,   296,   300,
     303,   307,   310,   314,   320,   322,   326,   328,   334,   338,
     340,   342,   344,   346,   351,   353,   356,   360,   362,   364,
     366,   370,   372,   374,   376,   378,   380,   384,   386,   388,
     390,   394,   396,   398,   401,   403,   405,   408,   410,   413,
     416,   419,   421,   424,   427,   429,   434,   436,   440,   442,
     446,   448,   452,   454,   458,   460,   463,   465,   467,   469,
     471,   475,   479,   481,   483,   485,   487,   489,   491,   493,
     495,   497,   500,   502,   504,   506,   508,   513,   515,   519,
     521,   523,   526,   528,   531,   534,   536,   538,   540,   542,
     544,   546,   548,   550,   552,   554
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      66,     0,    -1,    67,    -1,    70,    -1,    68,    -1,   103,
      50,    67,    -1,    69,    51,    72,    -1,     3,    73,    -1,
      69,    51,    73,    -1,    71,    -1,   103,    50,    70,    -1,
       3,    72,    -1,   100,     4,    -1,   100,    51,    72,    -1,
      74,    -1,    78,    -1,    86,    -1,    89,    -1,    75,    77,
      -1,    76,    -1,     5,    76,    -1,     6,    -1,     7,    -1,
       8,    -1,   149,    -1,   149,    52,    77,    -1,     9,    79,
      -1,    75,     9,    79,    -1,    80,    -1,    79,    52,    80,
      -1,    81,    53,    82,    54,    -1,    81,    52,    80,    -1,
     155,    -1,    83,    -1,    82,    52,    83,    -1,    85,    50,
      84,    -1,   125,    -1,   125,    -1,    10,    87,    42,    88,
      -1,   155,    -1,   109,    -1,    88,    52,   109,    -1,    11,
      90,    99,    -1,    76,    11,    90,    99,    -1,    91,    92,
      51,    95,    96,    -1,   155,    -1,    -1,    55,    93,    56,
      -1,    94,    -1,    93,   115,    94,    -1,   155,    -1,    -1,
      14,    98,    51,    -1,    -1,    97,    98,    51,    -1,    96,
      97,    98,    -1,    12,    -1,    76,    -1,     9,    -1,    76,
       9,    -1,    13,    -1,    10,    -1,    11,    -1,    76,    11,
      -1,   155,    -1,    98,    52,   155,    -1,   100,    -1,   101,
      -1,   117,    -1,   120,    -1,   102,    -1,    70,    -1,    67,
      -1,   104,    -1,   103,    50,   102,    -1,   155,    -1,   134,
      -1,    -1,   105,    -1,   108,    -1,   112,    -1,   106,   125,
      -1,   106,   138,    -1,   107,    -1,   106,   107,    -1,   148,
      42,    -1,    91,    42,    -1,    19,   109,    -1,   110,    -1,
     119,   110,    22,   109,    -1,   103,    -1,   111,    -1,    55,
     109,    56,    -1,    87,    53,   153,    54,    -1,    91,   113,
      -1,    -1,    55,   114,    56,    -1,   116,    -1,   114,   115,
     116,    -1,    52,    -1,    56,   154,    50,    55,    -1,   124,
      -1,    81,    -1,    87,    -1,    91,    -1,   118,    -1,   118,
      22,   100,    -1,   119,   120,    -1,   103,    50,   117,    -1,
     119,   101,    -1,    20,   138,    21,    -1,   121,   100,    -1,
     103,    50,   120,    -1,    23,   148,    42,   122,    24,    -1,
     123,    -1,   122,    52,   123,    -1,   125,    -1,   125,    15,
     125,    16,   125,    -1,   125,    17,   138,    -1,   125,    -1,
     138,    -1,   109,    -1,   126,    -1,   119,   126,    22,   125,
      -1,   128,    -1,   127,   128,    -1,   126,   127,   128,    -1,
      43,    -1,    44,    -1,   130,    -1,   128,   129,   130,    -1,
      45,    -1,    46,    -1,    47,    -1,   131,    -1,   130,    -1,
     130,    38,   131,    -1,   132,    -1,   148,    -1,   147,    -1,
      55,   125,    56,    -1,   133,    -1,   136,    -1,   133,   136,
      -1,   134,    -1,   135,    -1,   134,   135,    -1,    40,    -1,
     134,    40,    -1,    57,   134,    -1,    48,   137,    -1,   134,
      -1,    43,   134,    -1,    44,   134,    -1,   139,    -1,   119,
     139,    22,   138,    -1,   140,    -1,   139,    25,   140,    -1,
     141,    -1,   140,    26,   141,    -1,   142,    -1,   141,    27,
     142,    -1,   143,    -1,   142,    28,   143,    -1,   144,    -1,
      29,   144,    -1,   156,    -1,   148,    -1,   147,    -1,   145,
      -1,    55,   138,    56,    -1,   126,   146,   126,    -1,    58,
      -1,    59,    -1,    60,    -1,    30,    -1,    31,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    91,   113,    -1,
     149,    -1,   151,    -1,   150,    -1,   155,    -1,    81,    53,
     152,    54,    -1,   153,    -1,   152,    52,   153,    -1,   125,
      -1,    41,    -1,   154,    41,    -1,    41,    -1,   155,    41,
      -1,   155,    40,    -1,    36,    -1,    37,    -1,    58,    -1,
      59,    -1,    60,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    20,    20,    20,    21,    21,    22,    23,    23,    24,
      24,    25,    26,    26,    28,    28,    28,    28,    29,    30,
      30,    31,    31,    31,    32,    32,    33,    33,    34,    34,
      35,    35,    36,    37,    37,    38,    39,    40,    41,    42,
      43,    43,    44,    44,    45,    46,    47,    47,    48,    48,
      49,    50,    50,    51,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    54,    56,    56,    56,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    65,    66,
      67,    67,    67,    68,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    74,    75,
      76,    77,    77,    78,    79,    79,    80,    81,    82,    84,
      84,    84,    85,    85,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    89,    90,    90,    90,    91,    91,    91,
      91,    92,    92,    92,    93,    93,    93,    94,    94,    95,
      96,    97,    97,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   107,   109,   109,   110,   111,   112,   113,   113,   114,
     120,   120,   122,   122,   122,   126,   126,   132,   132,   132,
     132,   132,   132,   132,   132,   132
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TBEGIN", "TEND", "TOWN", "TREAL",
  "TINTEGER", "TBOOLEAN", "TARRAY", "TSWITCH", "TPROCEDURE", "TSTRING",
  "TLABEL", "TVALUE", "TSTEP", "TUNTIL", "TWHILE", "TCOMMENT", "TGOTO",
  "TIF", "TTHEN", "TELSE", "TFOR", "TDO", "TEQUIV", "TIMPL", "TOR", "TAND",
  "TNOT", "TLESS", "TNOTGREATER", "TEQUAL", "TNOTLESS", "TGREATER",
  "TNOTEQUAL", "TTRUE", "TFALSE", "TPOWER", "TANY_SYMBOL_SEQ_WO_QUOTE",
  "TDIGIT", "TLETTER", "TASSIGN", "'+'", "'-'", "'*'", "'/'", "'%'", "'e'",
  "'^'", "':'", "';'", "','", "'['", "']'", "'('", "')'", "'.'", "'<'",
  "'='", "'>'", "'\"'", "'_'", "'`'", "'\\''", "$accept", "program",
  "block", "unlabelled_block", "block_head", "compound_statement",
  "unlabelled_compound", "compound_tail", "declaration",
  "type_declaration", "local_or_own_type", "type", "type_list",
  "array_declaration", "array_list", "array_segment", "array_identifier",
  "bound_pair_list", "bound_pair", "upper_bound", "lower_bound",
  "switch_declaration", "switch_identifier", "switch_list",
  "procedure_declaration", "procedure_heading", "procedure_identifier",
  "formal_parameter_part", "formal_parameter_list", "formal_parameter",
  "value_part", "specification_part", "specifier", "identifier_list",
  "procedure_body", "statement", "unconditional_statement",
  "basic_statement", "label", "unlabelled_basic_statement",
  "assignment_statement", "left_part_list", "left_part", "go_to_statement",
  "designational_expression", "simple_designational_expression",
  "switch_designator", "procedure_statement", "actual_parameter_part",
  "actual_parameter_list", "parameter_delimiter", "actual_parameter",
  "conditional_statement", "if_statement", "if_clause", "for_statement",
  "for_clause", "for_list", "for_list_element", "expression",
  "arithmetic_expression", "simple_arithmetic_expression",
  "adding_operator", "term", "multiplying_operator", "factor", "primary",
  "unsigned_number", "decimal_number", "unsigned_integer",
  "decimal_fraction", "exponential_part", "integer", "boolean_expression",
  "simple_boolean", "implication", "boolean_term", "boolean_factor",
  "boolean_secondary", "boolean_primary", "relation",
  "relational_operator", "function_designator", "variable",
  "simple_variable", "variable_identifier", "subscripted_variable",
  "subscript_list", "subscript_expression", "letter_string", "identifier",
  "logical_value", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    43,    45,    42,    47,    37,   101,    94,
      58,    59,    44,    91,    93,    40,    41,    46,    60,    61,
      62,    34,    95,    96,    39
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    69,    69,    70,
      70,    71,    72,    72,    73,    73,    73,    73,    74,    75,
      75,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    82,    82,    83,    84,    85,    86,    87,
      88,    88,    89,    89,    90,    91,    92,    92,    93,    93,
      94,    95,    95,    96,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    99,   100,   100,   100,
     101,   101,   101,   102,   102,   103,   103,   104,   104,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   109,   109,
     110,   110,   110,   111,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   116,   116,   117,   117,   117,   117,   118,
     119,   120,   120,   121,   122,   122,   123,   123,   123,   124,
     124,   124,   125,   125,   126,   126,   126,   127,   127,   128,
     128,   129,   129,   129,   130,   130,   130,   131,   131,   131,
     131,   132,   132,   132,   133,   133,   133,   134,   134,   135,
     136,   137,   137,   137,   138,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   144,   144,
     144,   145,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   147,   148,   148,   149,   150,   151,   152,   152,   153,
     154,   154,   155,   155,   155,   156,   156,   146,   146,   146,
     146,   146,   146,   146,   146,   146
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     2,     3,     1,
       3,     2,     2,     3,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     3,     2,     3,     1,     3,
       4,     3,     1,     1,     3,     3,     1,     1,     4,     1,
       1,     3,     3,     4,     5,     1,     0,     3,     1,     3,
       1,     0,     3,     0,     3,     3,     1,     1,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     0,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     1,     4,
       1,     1,     3,     4,     2,     0,     3,     1,     3,     1,
       4,     1,     1,     1,     1,     1,     3,     2,     3,     2,
       3,     2,     3,     5,     1,     3,     1,     5,     3,     1,
       1,     1,     1,     4,     1,     2,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     2,     1,     1,     2,     1,     2,     2,
       2,     1,     2,     2,     1,     4,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     4,     1,     3,     1,
       1,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    77,   147,   192,     0,     2,     4,     0,     3,     9,
       0,    76,    75,     0,    21,    22,    23,     0,     0,     0,
       0,     0,     0,    72,    71,    11,     7,    14,     0,    19,
      15,     0,    16,    17,    95,     0,    67,    70,     0,    73,
      78,     0,    83,    79,    80,    68,   105,    77,    69,    77,
       0,   182,   184,   183,    45,     1,    77,     0,   148,   194,
     193,    20,    26,    28,     0,    32,     0,    39,    77,    46,
      45,     0,     0,    90,    87,    88,    91,     0,    75,     0,
     195,   196,   127,   128,     0,     0,     0,    95,     0,     0,
       0,   124,   129,   134,   137,   141,   144,   145,   142,     0,
     154,   156,   158,   160,   162,   164,   169,   139,   138,    45,
     166,     0,    32,     0,    18,    24,   185,     0,     0,    86,
       0,    94,    12,    77,    77,    95,    84,     0,    81,   122,
      82,   138,    77,   109,     0,   107,   111,    85,     6,     8,
       5,    10,     0,     0,     0,     0,    42,    66,     0,     0,
       0,     0,     0,   165,     0,     0,   151,   150,     0,     0,
     149,   181,     0,   175,   176,   177,   178,   179,   180,   172,
     173,   174,     0,     0,     0,   125,   139,   138,   131,   132,
     133,     0,     0,   143,   146,   110,     0,     0,     0,     0,
       0,    27,     0,    77,     0,   189,   122,     0,   187,     0,
     102,   103,    95,   121,     0,    97,     0,   101,   119,   144,
     120,    45,    13,    74,   108,   112,     0,   106,    77,    29,
      31,     0,    33,     0,    37,    38,    40,     0,    48,    50,
      51,    92,     0,     0,   152,   153,   140,   170,     0,   126,
     171,   130,   136,   157,   159,   161,   163,     0,   114,   116,
      25,    43,     0,     0,   186,    99,    96,     0,     0,     0,
      30,     0,     0,    47,     0,     0,    53,    93,    89,   155,
     113,     0,     0,     0,   188,   190,     0,    98,   123,    34,
      35,    36,    41,    49,     0,    64,    58,    61,    62,    56,
      60,    57,    44,     0,   115,     0,   118,   191,     0,    52,
       0,    59,    63,     0,     0,     0,   100,    65,    55,    54,
     117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    23,     6,     7,    24,     9,    25,    26,    27,
      28,    29,   114,    30,    62,    63,    31,   221,   222,   280,
     223,    32,    72,   225,    33,    68,    87,   149,   227,   228,
     266,   292,   293,   284,   146,    35,    36,    37,    73,    39,
      40,    41,    42,    43,   150,    75,    76,    44,   161,   204,
     257,   205,    45,    46,   194,    48,    49,   247,   248,   207,
     158,   196,    90,    91,   181,    92,    93,    94,    95,    96,
      97,    98,   157,   159,   100,   101,   102,   103,   104,   105,
     106,   173,   176,   177,    51,    52,    53,   197,   198,   276,
     109,   110
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -263
static const yytype_int16 yypact[] =
{
      45,   528,  -263,  -263,    67,  -263,  -263,    21,  -263,  -263,
      33,    -1,   116,    38,  -263,  -263,  -263,    37,    37,    37,
     168,   379,    37,  -263,  -263,  -263,  -263,  -263,    28,    87,
    -263,    56,  -263,  -263,    -2,    23,  -263,  -263,    99,  -263,
    -263,   379,  -263,  -263,  -263,  -263,   150,    10,  -263,    39,
      86,  -263,  -263,  -263,   145,  -263,   528,    45,  -263,  -263,
    -263,  -263,   124,  -263,   108,   116,   126,   116,    39,   129,
     116,   168,   128,  -263,  -263,  -263,  -263,    50,    47,   602,
    -263,  -263,  -263,  -263,    78,   379,   165,   155,   569,   560,
     237,   190,   176,  -263,  -263,   177,    24,  -263,  -263,   218,
     216,   220,   217,   226,  -263,  -263,  -263,   248,   325,   175,
    -263,   219,   300,    37,  -263,   207,   116,    37,   139,  -263,
     530,  -263,  -263,    39,    39,    -2,  -263,   569,  -263,   560,
    -263,   290,    39,  -263,   213,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,    37,    37,   139,   168,  -263,  -263,    37,   215,
     214,   139,   269,  -263,   165,   165,    -1,  -263,   240,   242,
      -1,  -263,    70,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,   237,   329,   139,   190,  -263,  -263,  -263,  -263,
    -263,   237,   237,  -263,  -263,  -263,   569,   569,   569,   569,
     139,   124,    37,    39,   329,  -263,   146,    52,  -263,   530,
      56,   128,   155,  -263,    73,  -263,   592,  -263,  -263,   113,
    -263,   407,  -263,  -263,  -263,  -263,   455,  -263,    10,  -263,
    -263,    62,  -263,   254,  -263,   255,  -263,   102,  -263,   116,
     295,  -263,   259,   168,    -1,    -1,  -263,  -263,   379,   190,
     146,   176,  -263,   220,   217,   226,  -263,     8,  -263,   149,
    -263,  -263,    32,   139,  -263,  -263,   278,   530,   139,   139,
    -263,   139,   168,   278,    37,    37,   654,  -263,  -263,  -263,
    -263,   139,   139,   379,  -263,  -263,    -7,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,   198,   116,  -263,  -263,  -263,  -263,
    -263,   208,   654,    37,  -263,   304,  -263,  -263,   267,  -263,
      37,  -263,  -263,    37,   232,   139,  -263,   116,   271,  -263,
    -263
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -263,  -263,     9,  -263,  -263,    16,  -263,   -26,   270,  -263,
    -263,   -11,   141,  -263,   224,   159,   -12,  -263,    89,  -263,
    -263,  -263,   -10,  -263,  -263,   238,   289,  -263,  -263,    90,
    -263,  -263,    68,  -262,   166,   -43,   314,  -103,   396,  -263,
    -263,  -263,   321,  -263,    -9,   -54,  -263,  -263,   330,  -263,
     140,   114,   251,  -263,   106,   -40,  -263,  -263,   107,  -263,
      53,   201,   -77,   -76,  -263,   199,   200,  -263,  -263,   211,
     -58,   286,  -263,   -17,   -62,   197,   205,   210,   204,   322,
    -263,  -263,   306,    14,   -25,  -263,  -263,  -263,  -141,  -263,
       0,  -263
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -186
static const yytype_int16 yytable[] =
{
      12,    54,    61,   115,    99,    64,   136,   135,    66,     5,
     232,    74,   172,     1,   175,    50,     8,    65,    67,    70,
      78,   213,   112,   152,   130,   147,   162,   122,   116,    20,
     138,   304,   270,    22,   297,   108,   111,   113,   184,    58,
     119,   308,     1,   298,    14,    15,    16,    54,     1,    54,
       2,     3,   172,   120,   258,   131,    54,    12,    20,    21,
     271,    50,    22,    50,    58,   162,   140,    55,    54,     3,
      50,    78,    56,   141,   123,    82,    83,    78,     3,     2,
       3,    86,    50,    57,   215,     2,     3,    59,    60,   217,
       2,     3,   238,   108,   128,   186,   239,   212,   117,   108,
     -39,    64,   108,   210,   253,    71,   254,    47,   200,   118,
     201,   203,   274,    65,   259,   213,   260,    70,     2,   172,
     211,   154,   155,    54,    54,   255,    77,    88,   137,   256,
      64,    64,    54,   140,   108,   -76,   226,    50,    50,   172,
     141,   108,    65,    65,   162,    78,    50,   127,   229,   124,
     147,   184,   152,    58,   255,    47,    59,    60,   263,    21,
     143,   144,    47,   172,   272,   -76,   273,   115,   145,   -76,
      86,   195,   132,   208,    47,   172,   142,    77,   215,     2,
       3,   151,    82,    83,   148,    59,    60,    84,    21,    82,
      83,   127,   116,    54,   174,   -75,    86,   224,   -32,   211,
     108,   108,   108,   108,   195,     2,   211,    50,     2,     3,
     120,    11,    11,   108,   182,    59,    60,   301,    54,   302,
     108,   269,    89,    71,   268,    84,   206,   140,   -32,    47,
      47,    11,    50,    78,   141,   178,   179,   180,    47,   185,
     210,   186,   129,   249,   188,   200,   187,   201,   203,   299,
     300,    77,   108,   282,   189,   291,   296,   211,    11,   192,
      11,   190,    78,   218,   229,   285,   230,    11,    11,  -168,
     231,   108,  -168,  -168,  -168,  -168,  -168,     2,     3,    11,
      89,   291,    11,   309,   300,    84,   129,   108,    11,    89,
      34,   233,   174,   285,    86,   156,   236,   160,   237,    47,
     307,   219,   220,   285,   261,   206,   195,   262,    69,   265,
     208,   278,   224,   267,   281,  -167,  -167,  -167,  -167,   275,
     305,   129,   306,   300,   249,   295,   139,   107,   216,  -167,
     125,   209,   137,   250,    11,    11,    34,   191,    34,    77,
      59,    60,  -185,    11,    88,    34,  -167,   107,   279,  -167,
    -167,  -167,  -167,  -167,   283,   193,    11,    34,   310,   251,
     303,   133,   126,   206,   121,   234,   235,   264,    77,     2,
       3,   277,    82,    83,   240,   214,  -167,    84,   294,    88,
     241,   183,   242,   243,   174,   107,    86,    89,    89,    89,
      89,   107,   244,   246,   107,   252,    10,    38,   245,    21,
     129,   153,     0,     0,    11,     0,    69,   216,    79,   202,
     209,     0,    34,    34,     0,    80,    81,   209,     0,     2,
       3,    34,    82,    83,     0,     0,   107,    84,     0,    11,
       0,     0,     0,   107,    85,     0,    86,     0,     0,    89,
       0,     0,     0,   134,    11,    38,     0,    59,    60,     0,
       0,     0,    38,    10,     0,     0,     0,     0,   129,   -32,
     -32,     0,     0,   -32,    38,     0,     0,     0,   209,     0,
       0,     0,     0,    11,    89,     0,     0,   258,     0,     0,
       0,     0,    34,     0,     0,   163,   164,   165,   166,   167,
     168,     0,   107,   107,   107,   107,     0,     0,    82,    83,
       0,     0,     0,     0,     0,   107,     0,    34,     0,     0,
       0,     0,   107,   169,   170,   171,     0,     0,     0,    38,
      38,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     1,     0,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,   107,     0,   202,    20,    21,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,    79,
       0,     0,     0,   107,     0,     0,    80,    81,     2,     3,
       2,     3,     0,    82,    83,     0,     0,     0,    84,   107,
       0,     0,     0,     0,     0,   199,     0,    86,     0,    38,
     163,   164,   165,   166,   167,   168,     0,     0,    79,     0,
       0,     0,     0,    82,    83,    80,    81,     0,     0,     2,
       3,     0,    82,    83,   134,     0,     0,    84,   169,   170,
     171,    79,     0,     0,    85,     0,    86,     0,    80,    81,
       0,     0,     2,     3,     0,    82,    83,     0,    80,    81,
      84,     0,     2,     3,     0,    82,    83,   199,     0,    86,
      84,     0,     0,     0,     0,     0,     0,    85,     0,    86,
      14,    15,    16,   286,   287,   288,   289,   290
};

static const yytype_int16 yycheck[] =
{
       0,     1,    13,    28,    21,    17,    49,    47,    18,     0,
     151,    20,    89,     3,    90,     1,     0,    17,    18,    19,
      20,   124,    22,    77,    41,    68,    88,     4,    28,    19,
      56,   293,    24,    23,    41,    21,    22,     9,    96,    40,
      42,   303,     3,    50,     6,     7,     8,    47,     3,    49,
      40,    41,   129,    55,    22,    41,    56,    57,    19,    20,
      52,    47,    23,    49,    40,   127,    57,     0,    68,    41,
      56,    71,    51,    57,    51,    43,    44,    77,    41,    40,
      41,    57,    68,    50,   124,    40,    41,    40,    41,   132,
      40,    41,    22,    79,    41,    25,   172,   123,    11,    85,
      53,   113,    88,   120,    52,    55,    54,     1,   120,    53,
     120,   120,   253,   113,    52,   218,    54,   117,    40,   196,
     120,    43,    44,   123,   124,    52,    20,    21,    42,    56,
     142,   143,   132,   124,   120,    22,   145,   123,   124,   216,
     124,   127,   142,   143,   206,   145,   132,    41,   148,    50,
     193,   209,   206,    40,    52,    49,    40,    41,    56,    20,
      52,    53,    56,   240,    15,    52,    17,   192,    42,    56,
      57,   118,    22,   120,    68,   252,    52,    71,   218,    40,
      41,    53,    43,    44,    55,    40,    41,    48,    20,    43,
      44,    85,   192,   193,    55,    50,    57,   144,    53,   199,
     186,   187,   188,   189,   151,    40,   206,   193,    40,    41,
      55,     0,     1,   199,    38,    40,    41,     9,   218,    11,
     206,   238,    21,    55,   233,    48,   120,   218,    53,   123,
     124,    20,   218,   233,   218,    45,    46,    47,   132,    21,
     257,    25,    41,   190,    27,   257,    26,   257,   257,    51,
      52,   145,   238,   262,    28,   266,   273,   257,    47,    52,
      49,    42,   262,    50,   264,   265,    51,    56,    57,    21,
      56,   257,    24,    25,    26,    27,    28,    40,    41,    68,
      79,   292,    71,    51,    52,    48,    85,   273,    77,    88,
       1,    22,    55,   293,    57,    84,    56,    86,    56,   193,
     300,   142,   143,   303,    50,   199,   253,    52,    19,    14,
     257,   258,   259,    54,   261,    25,    26,    27,    28,    41,
      16,   120,    55,    52,   271,   272,    56,    21,   127,     4,
      41,   120,    42,   192,   123,   124,    47,   113,    49,   233,
      40,    41,    42,   132,   238,    56,    21,    41,   259,    24,
      25,    26,    27,    28,   264,   117,   145,    68,   305,   193,
     292,    47,    41,   257,    34,   154,   155,   227,   262,    40,
      41,   257,    43,    44,   173,   124,    51,    48,   271,   273,
     181,    95,   182,   186,    55,    79,    57,   186,   187,   188,
     189,    85,   187,   189,    88,   194,     0,     1,   188,    20,
     199,    79,    -1,    -1,   193,    -1,   117,   206,    29,   120,
     199,    -1,   123,   124,    -1,    36,    37,   206,    -1,    40,
      41,   132,    43,    44,    -1,    -1,   120,    48,    -1,   218,
      -1,    -1,    -1,   127,    55,    -1,    57,    -1,    -1,   238,
      -1,    -1,    -1,    47,   233,    49,    -1,    40,    41,    -1,
      -1,    -1,    56,    57,    -1,    -1,    -1,    -1,   257,    52,
      53,    -1,    -1,    56,    68,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,   262,   273,    -1,    -1,    22,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    30,    31,    32,    33,    34,
      35,    -1,   186,   187,   188,   189,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   218,    -1,    -1,
      -1,    -1,   206,    58,    59,    60,    -1,    -1,    -1,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,   238,    -1,   257,    19,    20,    -1,
      20,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,   257,    -1,    -1,    36,    37,    40,    41,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,   273,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    57,    -1,   193,
      30,    31,    32,    33,    34,    35,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    43,    44,    36,    37,    -1,    -1,    40,
      41,    -1,    43,    44,   218,    -1,    -1,    48,    58,    59,
      60,    29,    -1,    -1,    55,    -1,    57,    -1,    36,    37,
      -1,    -1,    40,    41,    -1,    43,    44,    -1,    36,    37,
      48,    -1,    40,    41,    -1,    43,    44,    55,    -1,    57,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    57,
       6,     7,     8,     9,    10,    11,    12,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    40,    41,    66,    67,    68,    69,    70,    71,
     103,   134,   155,     5,     6,     7,     8,     9,    10,    11,
      19,    20,    23,    67,    70,    72,    73,    74,    75,    76,
      78,    81,    86,    89,    91,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   112,   117,   118,   119,   120,   121,
     148,   149,   150,   151,   155,     0,    51,    50,    40,    40,
      41,    76,    79,    80,    81,   155,    87,   155,    90,    91,
     155,    55,    87,   103,   109,   110,   111,   119,   155,    29,
      36,    37,    43,    44,    48,    55,    57,    91,   119,   126,
     127,   128,   130,   131,   132,   133,   134,   135,   136,   138,
     139,   140,   141,   142,   143,   144,   145,   147,   148,   155,
     156,   148,   155,     9,    77,   149,   155,    11,    53,    42,
      55,   113,     4,    51,    50,    91,   107,   119,   125,   126,
     138,   148,    22,   101,   103,   120,   100,    42,    72,    73,
      67,    70,    52,    52,    53,    42,    99,   100,    55,    92,
     109,    53,   110,   144,    43,    44,   134,   137,   125,   138,
     134,   113,   139,    30,    31,    32,    33,    34,    35,    58,
      59,    60,   127,   146,    55,   128,   147,   148,    45,    46,
      47,   129,    38,   136,   135,    21,    25,    26,    27,    28,
      42,    79,    52,    90,   119,   125,   126,   152,   153,    55,
      81,    87,    91,   109,   114,   116,   119,   124,   125,   134,
     138,   155,    72,   102,   117,   120,   126,   100,    50,    80,
      80,    82,    83,    85,   125,    88,   109,    93,    94,   155,
      51,    56,   153,    22,   134,   134,    56,    56,    22,   128,
     126,   130,   131,   140,   141,   142,   143,   122,   123,   125,
      77,    99,   126,    52,    54,    52,    56,   115,    22,    52,
      54,    50,    52,    56,   115,    14,    95,    54,   109,   138,
      24,    52,    15,    17,   153,    41,   154,   116,   125,    83,
      84,   125,   109,    94,    98,   155,     9,    10,    11,    12,
      13,    76,    96,    97,   123,   125,   138,    41,    50,    51,
      52,     9,    11,    97,    98,    16,    55,   155,    98,    51,
     125
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
      

/* Line 1455 of yacc.c  */
#line 1756 "parser.tab.c"
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
#line 141 "parser.y"


main( int argc, char *argv[] )
{ 
    extern FILE *yyin;
    ++argv; 
    --argc;
    yyin = fopen( argv[0], "r" );
    yydebug = 1;
    errors = 0;
    yyparse();
}
    yyerror(char *s) /* Called by yyparse on error */
{
    printf ("%s\n", s);
}

