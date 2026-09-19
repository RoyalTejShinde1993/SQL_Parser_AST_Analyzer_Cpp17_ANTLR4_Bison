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
#line 1 "grammar/sql_parser.y"

#include <memory>
#include <string>
#include <vector>
#include "ast.hpp"

void yyerror(const char* s);
int yylex(void);

extern std::unique_ptr<sql::SelectStatement> parsed_statement;

#line 83 "sql_parser.tab.c"

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

#include "sql_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SELECT = 3,                     /* SELECT  */
  YYSYMBOL_DISTINCT = 4,                   /* DISTINCT  */
  YYSYMBOL_COUNT = 5,                      /* COUNT  */
  YYSYMBOL_SUM = 6,                        /* SUM  */
  YYSYMBOL_AVG = 7,                        /* AVG  */
  YYSYMBOL_MIN = 8,                        /* MIN  */
  YYSYMBOL_MAX = 9,                        /* MAX  */
  YYSYMBOL_FROM = 10,                      /* FROM  */
  YYSYMBOL_WHERE = 11,                     /* WHERE  */
  YYSYMBOL_JOIN = 12,                      /* JOIN  */
  YYSYMBOL_INNER = 13,                     /* INNER  */
  YYSYMBOL_LEFT = 14,                      /* LEFT  */
  YYSYMBOL_RIGHT = 15,                     /* RIGHT  */
  YYSYMBOL_FULL = 16,                      /* FULL  */
  YYSYMBOL_CROSS = 17,                     /* CROSS  */
  YYSYMBOL_ON = 18,                        /* ON  */
  YYSYMBOL_ORDER = 19,                     /* ORDER  */
  YYSYMBOL_GROUP = 20,                     /* GROUP  */
  YYSYMBOL_BY = 21,                        /* BY  */
  YYSYMBOL_HAVING = 22,                    /* HAVING  */
  YYSYMBOL_AS = 23,                        /* AS  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_IS = 26,                        /* IS  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_NULL_TOKEN = 28,                /* NULL_TOKEN  */
  YYSYMBOL_IN = 29,                        /* IN  */
  YYSYMBOL_ASC = 30,                       /* ASC  */
  YYSYMBOL_DESC = 31,                      /* DESC  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_LT = 34,                        /* LT  */
  YYSYMBOL_GTE = 35,                       /* GTE  */
  YYSYMBOL_LTE = 36,                       /* LTE  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_STAR = 40,                      /* STAR  */
  YYSYMBOL_SLASH = 41,                     /* SLASH  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_DOT = 43,                       /* DOT  */
  YYSYMBOL_SEMICOLON = 44,                 /* SEMICOLON  */
  YYSYMBOL_IDENT = 45,                     /* IDENT  */
  YYSYMBOL_NUMBER = 46,                    /* NUMBER  */
  YYSYMBOL_STRING = 47,                    /* STRING  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_distinct_opt = 52,              /* distinct_opt  */
  YYSYMBOL_select_list = 53,               /* select_list  */
  YYSYMBOL_table_ref = 54,                 /* table_ref  */
  YYSYMBOL_join_list = 55,                 /* join_list  */
  YYSYMBOL_where_opt = 56,                 /* where_opt  */
  YYSYMBOL_having_opt = 57,                /* having_opt  */
  YYSYMBOL_group_opt = 58,                 /* group_opt  */
  YYSYMBOL_group_list = 59,                /* group_list  */
  YYSYMBOL_in_list = 60,                   /* in_list  */
  YYSYMBOL_order_opt = 61,                 /* order_opt  */
  YYSYMBOL_order_list = 62,                /* order_list  */
  YYSYMBOL_select_alias_opt = 63,          /* select_alias_opt  */
  YYSYMBOL_expr = 64                       /* expr  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      48,    49,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    86,    90,    97,   111,   126,   134,   144,
     157,   161,   174,   187,   200,   213,   226,   241,   245,   252,
     256,   263,   267,   274,   281,   289,   296,   305,   309,   316,
     324,   333,   342,   349,   357,   368,   372,   379,   387,   395,
     403,   411,   419,   424,   432,   440,   455,   470,   478,   488,
     493,   501,   509,   517,   526,   535,   544,   553,   562,   571,
     580,   589,   598,   607,   616
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
  "\"end of file\"", "error", "\"invalid token\"", "SELECT", "DISTINCT",
  "COUNT", "SUM", "AVG", "MIN", "MAX", "FROM", "WHERE", "JOIN", "INNER",
  "LEFT", "RIGHT", "FULL", "CROSS", "ON", "ORDER", "GROUP", "BY", "HAVING",
  "AS", "AND", "OR", "IS", "NOT", "NULL_TOKEN", "IN", "ASC", "DESC", "EQ",
  "GT", "LT", "GTE", "LTE", "NEQ", "PLUS", "MINUS", "STAR", "SLASH",
  "COMMA", "DOT", "SEMICOLON", "IDENT", "NUMBER", "STRING", "'('", "')'",
  "$accept", "statement", "distinct_opt", "select_list", "table_ref",
  "join_list", "where_opt", "having_opt", "group_opt", "group_list",
  "in_list", "order_opt", "order_list", "select_alias_opt", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,    36,     3,   -41,    -1,   -41,    -5,     4,     7,    23,
      33,   -41,    -2,   -41,   -41,    -1,     0,   178,    -1,    -1,
      -1,    -1,    -1,    43,    24,    27,    -1,    45,    -1,    -1,
      -7,    73,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   -41,    60,   105,   123,   141,   159,   -41,
     -41,   -41,   -22,   -41,   178,   -41,   266,   250,    77,   -41,
      58,    -1,   282,   282,   282,   282,   282,   282,   -14,   -14,
      80,    80,   -41,   -41,   -41,   -41,   -41,    67,   -41,    63,
     -41,   -41,    -1,   -40,   232,   -41,    -1,    27,    96,   101,
     106,   107,   108,   102,   -30,    -1,   -41,   232,   103,    27,
      27,    27,    27,    27,   104,   113,   -41,   232,    -1,   118,
     133,   135,   151,   -41,    -1,    -1,   152,   232,    -1,    -1,
      -1,    -1,    81,   232,   232,   166,    82,   232,   232,   232,
     232,    -1,    -1,   -41,   232,   147,   196,    -1,   -41,   -41,
     214,   -41,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     4,     0,     1,     0,     0,     0,     0,
       0,    49,    47,    51,    52,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,    50,
      48,    42,     7,    10,    35,    36,    63,    64,     0,    43,
       0,     0,    57,    58,    59,    60,    61,    62,    53,    54,
      55,    56,    37,    38,    39,    40,    41,     0,     8,    17,
       6,    44,     0,     0,    25,     9,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,    45,    18,     0,     0,
       0,     0,     0,     0,     0,    19,    46,    26,     0,     0,
       0,     0,     0,    16,     0,     0,    27,    11,     0,     0,
       0,     0,    22,    23,    20,     0,     0,    12,    13,    14,
      15,     0,     0,     2,    24,    28,    29,     0,    30,    31,
      32,    33,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,   -41,   -41,   -33,   -41,   -41,   -41,   -41,   -41,
      42,   -41,   -41,   155,    -4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     4,    16,    53,    79,    93,   116,   105,   122,
      83,   126,   135,    43,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      17,    77,    95,     5,     6,     7,     8,     9,    10,    96,
      25,    24,    95,    31,    44,    45,    46,    47,    48,   106,
      58,    59,    54,    78,    56,    57,    41,    42,     1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    11,
       3,    23,    26,    18,    12,    13,    14,    15,    28,    29,
      30,    31,    19,    32,    98,    20,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   109,   110,   111,   112,
     113,    21,    52,    51,    86,    87,    88,    89,    90,    91,
      92,    22,    97,    49,    28,    29,    30,    31,    50,    32,
      55,   107,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    60,    61,   117,    81,    82,    31,    99,    72,
     123,   124,    85,   100,   127,   128,   129,   130,   101,   102,
     103,   108,   104,   131,    94,   114,   133,   134,   136,    28,
      29,    30,    31,   140,    32,   115,   118,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    28,    29,    30,
      31,   119,    32,   120,    73,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    28,    29,    30,    31,   121,
      32,   125,    74,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    28,    29,    30,    31,   132,    32,   137,
      75,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    27,    28,    29,    30,    31,     0,    32,    76,    80,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      28,    29,    30,    31,     0,    32,   138,   139,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    28,    29,
      30,    31,     0,    32,   141,   142,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    28,    29,    30,    31,
       0,    32,     0,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    28,     0,    30,    31,     0,    32,
       0,     0,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    30,    31,     0,    32,     0,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    30,    31,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,    41,    42
};

static const yytype_int16 yycheck[] =
{
       4,    23,    42,     0,     5,     6,     7,     8,     9,    49,
      10,    15,    42,    27,    18,    19,    20,    21,    22,    49,
      27,    28,    26,    45,    28,    29,    40,    41,     3,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    40,
       4,    43,    42,    48,    45,    46,    47,    48,    24,    25,
      26,    27,    48,    29,    87,    48,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    99,   100,   101,   102,
     103,    48,    45,    49,    11,    12,    13,    14,    15,    16,
      17,    48,    86,    40,    24,    25,    26,    27,    45,    29,
      45,    95,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    29,    48,   108,    28,    48,    27,    12,    49,
     114,   115,    45,    12,   118,   119,   120,   121,    12,    12,
      12,    18,    20,    42,    82,    21,    44,   131,   132,    24,
      25,    26,    27,   137,    29,    22,    18,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    24,    25,    26,
      27,    18,    29,    18,    49,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    24,    25,    26,    27,    18,
      29,    19,    49,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    24,    25,    26,    27,    21,    29,    42,
      49,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    23,    24,    25,    26,    27,    -1,    29,    49,    54,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    24,    -1,    26,    27,    -1,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    26,    27,    -1,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    51,     4,    52,     0,     5,     6,     7,     8,
       9,    40,    45,    46,    47,    48,    53,    64,    48,    48,
      48,    48,    48,    43,    64,    10,    42,    23,    24,    25,
      26,    27,    29,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    63,    64,    64,    64,    64,    64,    40,
      45,    49,    45,    54,    64,    45,    64,    64,    27,    28,
      29,    48,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    49,    49,    49,    49,    49,    23,    45,    55,
      63,    28,    48,    60,    64,    45,    11,    12,    13,    14,
      15,    16,    17,    56,    60,    42,    49,    64,    54,    12,
      12,    12,    12,    12,    20,    58,    49,    64,    18,    54,
      54,    54,    54,    54,    21,    22,    57,    64,    18,    18,
      18,    18,    59,    64,    64,    19,    61,    64,    64,    64,
      64,    42,    21,    44,    64,    62,    64,    42,    30,    31,
      64,    30,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    11,     0,     1,     2,     4,     1,     2,     3,
       0,     5,     6,     6,     6,     6,     4,     0,     2,     0,
       2,     0,     3,     1,     3,     1,     3,     0,     3,     1,
       2,     2,     3,     4,     4,     0,     2,     4,     4,     4,
       4,     4,     3,     3,     4,     5,     6,     1,     3,     1,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
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
  case 2: /* statement: SELECT distinct_opt select_list FROM table_ref join_list where_opt group_opt having_opt order_opt SEMICOLON  */
#line 58 "grammar/sql_parser.y"
    {
    auto stmt = new sql::SelectStatement();

    stmt->distinct = (yyvsp[-9].boolean);
    stmt->select_items = std::move(*(yyvsp[-8].items));
    stmt->from = std::move(*(yyvsp[-6].table));
    stmt->joins = std::move(*(yyvsp[-5].joins));
    stmt->where = std::unique_ptr<sql::Expr>((yyvsp[-4].expr));

    for (auto* expr : *(yyvsp[-3].group_exprs)) {
        stmt->group_by.emplace_back(expr);
    }

    stmt->having = std::unique_ptr<sql::Expr>((yyvsp[-2].expr));
    stmt->order_by = std::move(*(yyvsp[-1].orders));

    delete (yyvsp[-8].items);
    delete (yyvsp[-6].table);
    delete (yyvsp[-5].joins);
    delete (yyvsp[-3].group_exprs);
    delete (yyvsp[-1].orders);

    parsed_statement.reset(stmt);
    (yyval.stmt) = stmt;
    }
#line 1282 "sql_parser.tab.c"
    break;

  case 3: /* distinct_opt: %empty  */
#line 86 "grammar/sql_parser.y"
    {
        (yyval.boolean) = false;
    }
#line 1290 "sql_parser.tab.c"
    break;

  case 4: /* distinct_opt: DISTINCT  */
#line 91 "grammar/sql_parser.y"
    {
        (yyval.boolean) = true;
    }
#line 1298 "sql_parser.tab.c"
    break;

  case 5: /* select_list: expr select_alias_opt  */
#line 98 "grammar/sql_parser.y"
    {
        auto items = new std::vector<sql::SelectItem>();
        items->emplace_back();
        items->back().expr.reset((yyvsp[-1].expr));

        if ((yyvsp[0].str)) {
            items->back().alias = *(yyvsp[0].str);
            delete (yyvsp[0].str);
        }

        (yyval.items) = items;
    }
#line 1315 "sql_parser.tab.c"
    break;

  case 6: /* select_list: select_list COMMA expr select_alias_opt  */
#line 112 "grammar/sql_parser.y"
    {
        (yyvsp[-3].items)->emplace_back();
        (yyvsp[-3].items)->back().expr.reset((yyvsp[-1].expr));

        if ((yyvsp[0].str)) {
            (yyvsp[-3].items)->back().alias = *(yyvsp[0].str);
            delete (yyvsp[0].str);
        }

        (yyval.items) = (yyvsp[-3].items);
    }
#line 1331 "sql_parser.tab.c"
    break;

  case 7: /* table_ref: IDENT  */
#line 127 "grammar/sql_parser.y"
    {
        auto table = new sql::TableRef();
        table->name = *(yyvsp[0].str);
        delete (yyvsp[0].str);
        (yyval.table) = table;
    }
#line 1342 "sql_parser.tab.c"
    break;

  case 8: /* table_ref: IDENT IDENT  */
#line 135 "grammar/sql_parser.y"
    {
        auto table = new sql::TableRef();
        table->name = *(yyvsp[-1].str);
        table->alias = *(yyvsp[0].str);
        delete (yyvsp[-1].str);
        delete (yyvsp[0].str);
        (yyval.table) = table;
    }
#line 1355 "sql_parser.tab.c"
    break;

  case 9: /* table_ref: IDENT AS IDENT  */
#line 145 "grammar/sql_parser.y"
    {
        auto table = new sql::TableRef();
        table->name = *(yyvsp[-2].str);
        table->alias = *(yyvsp[0].str);
        delete (yyvsp[-2].str);
        delete (yyvsp[0].str);
        (yyval.table) = table;
    }
#line 1368 "sql_parser.tab.c"
    break;

  case 10: /* join_list: %empty  */
#line 157 "grammar/sql_parser.y"
    {
        (yyval.joins) = new std::vector<sql::JoinClause>();
    }
#line 1376 "sql_parser.tab.c"
    break;

  case 11: /* join_list: join_list JOIN table_ref ON expr  */
#line 162 "grammar/sql_parser.y"
    {
        sql::JoinClause join;
        join.type = sql::JoinType::INNER;
        join.table = std::move(*(yyvsp[-2].table));
        join.condition.reset((yyvsp[0].expr));

        (yyvsp[-4].joins)->push_back(std::move(join));

        delete (yyvsp[-2].table);
        (yyval.joins) = (yyvsp[-4].joins);
    }
#line 1392 "sql_parser.tab.c"
    break;

  case 12: /* join_list: join_list INNER JOIN table_ref ON expr  */
#line 175 "grammar/sql_parser.y"
    {
        sql::JoinClause join;
        join.type = sql::JoinType::INNER;
        join.table = std::move(*(yyvsp[-2].table));
        join.condition.reset((yyvsp[0].expr));

        (yyvsp[-5].joins)->push_back(std::move(join));

        delete (yyvsp[-2].table);
        (yyval.joins) = (yyvsp[-5].joins);
    }
#line 1408 "sql_parser.tab.c"
    break;

  case 13: /* join_list: join_list LEFT JOIN table_ref ON expr  */
#line 188 "grammar/sql_parser.y"
    {
        sql::JoinClause join;
        join.type = sql::JoinType::LEFT;
        join.table = std::move(*(yyvsp[-2].table));
        join.condition.reset((yyvsp[0].expr));

        (yyvsp[-5].joins)->push_back(std::move(join));

        delete (yyvsp[-2].table);
        (yyval.joins) = (yyvsp[-5].joins);
    }
#line 1424 "sql_parser.tab.c"
    break;

  case 14: /* join_list: join_list RIGHT JOIN table_ref ON expr  */
#line 201 "grammar/sql_parser.y"
    {
        sql::JoinClause join;
        join.type = sql::JoinType::RIGHT;
        join.table = std::move(*(yyvsp[-2].table));
        join.condition.reset((yyvsp[0].expr));

        (yyvsp[-5].joins)->push_back(std::move(join));

        delete (yyvsp[-2].table);
        (yyval.joins) = (yyvsp[-5].joins);
    }
#line 1440 "sql_parser.tab.c"
    break;

  case 15: /* join_list: join_list FULL JOIN table_ref ON expr  */
#line 214 "grammar/sql_parser.y"
    {
        sql::JoinClause join;
        join.type = sql::JoinType::FULL;
        join.table = std::move(*(yyvsp[-2].table));
        join.condition.reset((yyvsp[0].expr));

        (yyvsp[-5].joins)->push_back(std::move(join));

        delete (yyvsp[-2].table);
        (yyval.joins) = (yyvsp[-5].joins);
    }
#line 1456 "sql_parser.tab.c"
    break;

  case 16: /* join_list: join_list CROSS JOIN table_ref  */
#line 227 "grammar/sql_parser.y"
    {
        sql::JoinClause join;
        join.type = sql::JoinType::CROSS;
        join.table = std::move(*(yyvsp[0].table));

        (yyvsp[-3].joins)->push_back(std::move(join));

        delete (yyvsp[0].table);
        (yyval.joins) = (yyvsp[-3].joins);
    }
#line 1471 "sql_parser.tab.c"
    break;

  case 17: /* where_opt: %empty  */
#line 241 "grammar/sql_parser.y"
    {
        (yyval.expr) = nullptr;
    }
#line 1479 "sql_parser.tab.c"
    break;

  case 18: /* where_opt: WHERE expr  */
#line 246 "grammar/sql_parser.y"
    {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1487 "sql_parser.tab.c"
    break;

  case 19: /* having_opt: %empty  */
#line 252 "grammar/sql_parser.y"
    {
        (yyval.expr) = nullptr;
    }
#line 1495 "sql_parser.tab.c"
    break;

  case 20: /* having_opt: HAVING expr  */
#line 257 "grammar/sql_parser.y"
    {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1503 "sql_parser.tab.c"
    break;

  case 21: /* group_opt: %empty  */
#line 263 "grammar/sql_parser.y"
    {
        (yyval.group_exprs) = new std::vector<sql::Expr*>();
    }
#line 1511 "sql_parser.tab.c"
    break;

  case 22: /* group_opt: GROUP BY group_list  */
#line 268 "grammar/sql_parser.y"
    {
        (yyval.group_exprs) = (yyvsp[0].group_exprs);
    }
#line 1519 "sql_parser.tab.c"
    break;

  case 23: /* group_list: expr  */
#line 275 "grammar/sql_parser.y"
    {
        auto groups = new std::vector<sql::Expr*>();
        groups->push_back((yyvsp[0].expr));
        (yyval.group_exprs) = groups;
    }
#line 1529 "sql_parser.tab.c"
    break;

  case 24: /* group_list: group_list COMMA expr  */
#line 282 "grammar/sql_parser.y"
    {
        (yyvsp[-2].group_exprs)->push_back((yyvsp[0].expr));
        (yyval.group_exprs) = (yyvsp[-2].group_exprs);
    }
#line 1538 "sql_parser.tab.c"
    break;

  case 25: /* in_list: expr  */
#line 290 "grammar/sql_parser.y"
    {
        auto values = new std::vector<sql::Expr*>();
        values->push_back((yyvsp[0].expr));
        (yyval.expr_list) = values;
    }
#line 1548 "sql_parser.tab.c"
    break;

  case 26: /* in_list: in_list COMMA expr  */
#line 297 "grammar/sql_parser.y"
    {
        (yyvsp[-2].expr_list)->push_back((yyvsp[0].expr));
        (yyval.expr_list) = (yyvsp[-2].expr_list);
    }
#line 1557 "sql_parser.tab.c"
    break;

  case 27: /* order_opt: %empty  */
#line 305 "grammar/sql_parser.y"
    {
        (yyval.orders) = new std::vector<sql::OrderItem>();
    }
#line 1565 "sql_parser.tab.c"
    break;

  case 28: /* order_opt: ORDER BY order_list  */
#line 310 "grammar/sql_parser.y"
    {
        (yyval.orders) = (yyvsp[0].orders);
    }
#line 1573 "sql_parser.tab.c"
    break;

  case 29: /* order_list: expr  */
#line 317 "grammar/sql_parser.y"
    {
        auto orders = new std::vector<sql::OrderItem>();
        orders->emplace_back();
        orders->back().expr.reset((yyvsp[0].expr));
        (yyval.orders) = orders;
    }
#line 1584 "sql_parser.tab.c"
    break;

  case 30: /* order_list: expr ASC  */
#line 325 "grammar/sql_parser.y"
    {
        auto orders = new std::vector<sql::OrderItem>();
        orders->emplace_back();
        orders->back().expr.reset((yyvsp[-1].expr));
        orders->back().descending = false;
        (yyval.orders) = orders;
    }
#line 1596 "sql_parser.tab.c"
    break;

  case 31: /* order_list: expr DESC  */
#line 334 "grammar/sql_parser.y"
    {
        auto orders = new std::vector<sql::OrderItem>();
        orders->emplace_back();
        orders->back().expr.reset((yyvsp[-1].expr));
        orders->back().descending = true;
        (yyval.orders) = orders;
    }
#line 1608 "sql_parser.tab.c"
    break;

  case 32: /* order_list: order_list COMMA expr  */
#line 343 "grammar/sql_parser.y"
    {
        (yyvsp[-2].orders)->emplace_back();
        (yyvsp[-2].orders)->back().expr.reset((yyvsp[0].expr));
        (yyval.orders) = (yyvsp[-2].orders);
    }
#line 1618 "sql_parser.tab.c"
    break;

  case 33: /* order_list: order_list COMMA expr ASC  */
#line 350 "grammar/sql_parser.y"
    {
        (yyvsp[-3].orders)->emplace_back();
        (yyvsp[-3].orders)->back().expr.reset((yyvsp[-1].expr));
        (yyvsp[-3].orders)->back().descending = false;
        (yyval.orders) = (yyvsp[-3].orders);
    }
#line 1629 "sql_parser.tab.c"
    break;

  case 34: /* order_list: order_list COMMA expr DESC  */
#line 358 "grammar/sql_parser.y"
    {
        (yyvsp[-3].orders)->emplace_back();
        (yyvsp[-3].orders)->back().expr.reset((yyvsp[-1].expr));
        (yyvsp[-3].orders)->back().descending = true;
        (yyval.orders) = (yyvsp[-3].orders);
    }
#line 1640 "sql_parser.tab.c"
    break;

  case 35: /* select_alias_opt: %empty  */
#line 368 "grammar/sql_parser.y"
    {
        (yyval.str) = nullptr;
    }
#line 1648 "sql_parser.tab.c"
    break;

  case 36: /* select_alias_opt: AS IDENT  */
#line 373 "grammar/sql_parser.y"
    {
        (yyval.str) = (yyvsp[0].str);
    }
#line 1656 "sql_parser.tab.c"
    break;

  case 37: /* expr: COUNT '(' expr ')'  */
#line 380 "grammar/sql_parser.y"
    {
        auto expr = new sql::FunctionCall();
        expr->name = "COUNT";
        expr->argument.reset((yyvsp[-1].expr));
        (yyval.expr) = expr;
    }
#line 1667 "sql_parser.tab.c"
    break;

  case 38: /* expr: SUM '(' expr ')'  */
#line 388 "grammar/sql_parser.y"
    {
        auto expr = new sql::FunctionCall();
        expr->name = "SUM";
        expr->argument.reset((yyvsp[-1].expr));
        (yyval.expr) = expr;
    }
#line 1678 "sql_parser.tab.c"
    break;

  case 39: /* expr: AVG '(' expr ')'  */
#line 396 "grammar/sql_parser.y"
    {
        auto expr = new sql::FunctionCall();
        expr->name = "AVG";
        expr->argument.reset((yyvsp[-1].expr));
        (yyval.expr) = expr;
    }
#line 1689 "sql_parser.tab.c"
    break;

  case 40: /* expr: MIN '(' expr ')'  */
#line 404 "grammar/sql_parser.y"
    {
        auto expr = new sql::FunctionCall();
        expr->name = "MIN";
        expr->argument.reset((yyvsp[-1].expr));
        (yyval.expr) = expr;
    }
#line 1700 "sql_parser.tab.c"
    break;

  case 41: /* expr: MAX '(' expr ')'  */
#line 412 "grammar/sql_parser.y"
    {
        auto expr = new sql::FunctionCall();
        expr->name = "MAX";
        expr->argument.reset((yyvsp[-1].expr));
        (yyval.expr) = expr;
    }
#line 1711 "sql_parser.tab.c"
    break;

  case 42: /* expr: '(' expr ')'  */
#line 420 "grammar/sql_parser.y"
    {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1719 "sql_parser.tab.c"
    break;

  case 43: /* expr: expr IS NULL_TOKEN  */
#line 425 "grammar/sql_parser.y"
    {
        auto expr = new sql::NullCheckExpr();
        expr->expression.reset((yyvsp[-2].expr));
        expr->is_not = false;
        (yyval.expr) = expr;
    }
#line 1730 "sql_parser.tab.c"
    break;

  case 44: /* expr: expr IS NOT NULL_TOKEN  */
#line 433 "grammar/sql_parser.y"
    {
        auto expr = new sql::NullCheckExpr();
        expr->expression.reset((yyvsp[-3].expr));
        expr->is_not = true;
        (yyval.expr) = expr;
    }
#line 1741 "sql_parser.tab.c"
    break;

  case 45: /* expr: expr IN '(' in_list ')'  */
#line 441 "grammar/sql_parser.y"
    {
        auto expr = new sql::InExpr();
        expr->expression.reset((yyvsp[-4].expr));

        for (auto* value : *(yyvsp[-1].expr_list)) {
            expr->values.emplace_back(value);
        }

        delete (yyvsp[-1].expr_list);

        expr->is_not = false;
        (yyval.expr) = expr;
    }
#line 1759 "sql_parser.tab.c"
    break;

  case 46: /* expr: expr NOT IN '(' in_list ')'  */
#line 456 "grammar/sql_parser.y"
    {
        auto expr = new sql::InExpr();
        expr->expression.reset((yyvsp[-5].expr));

        for (auto* value : *(yyvsp[-1].expr_list)) {
            expr->values.emplace_back(value);
        }

        delete (yyvsp[-1].expr_list);

        expr->is_not = true;
        (yyval.expr) = expr;
    }
#line 1777 "sql_parser.tab.c"
    break;

  case 47: /* expr: IDENT  */
#line 471 "grammar/sql_parser.y"
    {
        auto expr = new sql::ColumnRef();
        expr->column = *(yyvsp[0].str);
        delete (yyvsp[0].str);
        (yyval.expr) = expr;
    }
#line 1788 "sql_parser.tab.c"
    break;

  case 48: /* expr: IDENT DOT IDENT  */
#line 479 "grammar/sql_parser.y"
    {
        auto expr = new sql::ColumnRef();
        expr->table = *(yyvsp[-2].str);
        expr->column = *(yyvsp[0].str);
        delete (yyvsp[-2].str);
        delete (yyvsp[0].str);
        (yyval.expr) = expr;
    }
#line 1801 "sql_parser.tab.c"
    break;

  case 49: /* expr: STAR  */
#line 489 "grammar/sql_parser.y"
    {
        (yyval.expr) = new sql::WildcardRef();
    }
#line 1809 "sql_parser.tab.c"
    break;

  case 50: /* expr: IDENT DOT STAR  */
#line 494 "grammar/sql_parser.y"
    {
        auto expr = new sql::WildcardRef();
        expr->table = *(yyvsp[-2].str);
        delete (yyvsp[-2].str);
        (yyval.expr) = expr;
    }
#line 1820 "sql_parser.tab.c"
    break;

  case 51: /* expr: NUMBER  */
#line 502 "grammar/sql_parser.y"
    {
        auto expr = new sql::Literal();
        expr->value = *(yyvsp[0].str);
        delete (yyvsp[0].str);
        (yyval.expr) = expr;
    }
#line 1831 "sql_parser.tab.c"
    break;

  case 52: /* expr: STRING  */
#line 510 "grammar/sql_parser.y"
    {
        auto expr = new sql::Literal();
        expr->value = *(yyvsp[0].str);
        delete (yyvsp[0].str);
        (yyval.expr) = expr;
    }
#line 1842 "sql_parser.tab.c"
    break;

  case 53: /* expr: expr PLUS expr  */
#line 518 "grammar/sql_parser.y"
    {
        auto expr = new sql::ArithmeticExpr();
        expr->op = "+";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1854 "sql_parser.tab.c"
    break;

  case 54: /* expr: expr MINUS expr  */
#line 527 "grammar/sql_parser.y"
    {
        auto expr = new sql::ArithmeticExpr();
        expr->op = "-";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1866 "sql_parser.tab.c"
    break;

  case 55: /* expr: expr STAR expr  */
#line 536 "grammar/sql_parser.y"
    {
        auto expr = new sql::ArithmeticExpr();
        expr->op = "*";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1878 "sql_parser.tab.c"
    break;

  case 56: /* expr: expr SLASH expr  */
#line 545 "grammar/sql_parser.y"
    {
        auto expr = new sql::ArithmeticExpr();
        expr->op = "/";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1890 "sql_parser.tab.c"
    break;

  case 57: /* expr: expr EQ expr  */
#line 554 "grammar/sql_parser.y"
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "=";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1902 "sql_parser.tab.c"
    break;

  case 58: /* expr: expr GT expr  */
#line 563 "grammar/sql_parser.y"
    {
        auto expr = new sql::BinaryExpr();
        expr->op = ">";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1914 "sql_parser.tab.c"
    break;

  case 59: /* expr: expr LT expr  */
#line 572 "grammar/sql_parser.y"
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "<";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1926 "sql_parser.tab.c"
    break;

  case 60: /* expr: expr GTE expr  */
#line 581 "grammar/sql_parser.y"
    {
        auto expr = new sql::BinaryExpr();
        expr->op = ">=";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1938 "sql_parser.tab.c"
    break;

  case 61: /* expr: expr LTE expr  */
#line 590 "grammar/sql_parser.y"
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "<=";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1950 "sql_parser.tab.c"
    break;

  case 62: /* expr: expr NEQ expr  */
#line 599 "grammar/sql_parser.y"
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "!=";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1962 "sql_parser.tab.c"
    break;

  case 63: /* expr: expr AND expr  */
#line 608 "grammar/sql_parser.y"
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "AND";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1974 "sql_parser.tab.c"
    break;

  case 64: /* expr: expr OR expr  */
#line 617 "grammar/sql_parser.y"
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "OR";
        expr->left.reset((yyvsp[-2].expr));
        expr->right.reset((yyvsp[0].expr));
        (yyval.expr) = expr;
    }
#line 1986 "sql_parser.tab.c"
    break;


#line 1990 "sql_parser.tab.c"

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

#line 626 "grammar/sql_parser.y"


void yyerror(const char* s)
{
    (void)s;
}
