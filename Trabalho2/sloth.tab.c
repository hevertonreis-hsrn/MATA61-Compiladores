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
#line 5 "sloth.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define YYDEBUG 1
int yydebug = 1;

/* Protótipos */
int yylex(void);
void yyerror(const char *s);

extern char *symbol_table[];
extern int symbol_count;
extern void init_lexer(void);
extern FILE *yyin;

/* indent */
int indent_level = 0;
void print_indent() {
    for (int i = 0; i < indent_level; i++) printf("    ");
}


#line 97 "sloth.tab.c"

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

#include "sloth.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_FN = 3,                       /* T_FN  */
  YYSYMBOL_T_IF = 4,                       /* T_IF  */
  YYSYMBOL_T_EL = 5,                       /* T_EL  */
  YYSYMBOL_T_EF = 6,                       /* T_EF  */
  YYSYMBOL_T_FR = 7,                       /* T_FR  */
  YYSYMBOL_T_WL = 8,                       /* T_WL  */
  YYSYMBOL_T_R = 9,                        /* T_R  */
  YYSYMBOL_T_IN = 10,                      /* T_IN  */
  YYSYMBOL_T_I = 11,                       /* T_I  */
  YYSYMBOL_T_FL = 12,                      /* T_FL  */
  YYSYMBOL_T_S = 13,                       /* T_S  */
  YYSYMBOL_T_EQ = 14,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 15,                     /* T_NEQ  */
  YYSYMBOL_T_GTE = 16,                     /* T_GTE  */
  YYSYMBOL_T_LTE = 17,                     /* T_LTE  */
  YYSYMBOL_T_GT = 18,                      /* T_GT  */
  YYSYMBOL_T_LT = 19,                      /* T_LT  */
  YYSYMBOL_T_ASSIGN = 20,                  /* T_ASSIGN  */
  YYSYMBOL_T_PLUS = 21,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 22,                   /* T_MINUS  */
  YYSYMBOL_T_MUL = 23,                     /* T_MUL  */
  YYSYMBOL_T_DIV = 24,                     /* T_DIV  */
  YYSYMBOL_T_MOD = 25,                     /* T_MOD  */
  YYSYMBOL_T_AND = 26,                     /* T_AND  */
  YYSYMBOL_T_OR = 27,                      /* T_OR  */
  YYSYMBOL_T_LPAREN = 28,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 29,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACKET = 30,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 31,                /* T_RBRACKET  */
  YYSYMBOL_T_COMMA = 32,                   /* T_COMMA  */
  YYSYMBOL_T_FLOAT_NUM = 33,               /* T_FLOAT_NUM  */
  YYSYMBOL_T_INT_NUM = 34,                 /* T_INT_NUM  */
  YYSYMBOL_T_STRING = 35,                  /* T_STRING  */
  YYSYMBOL_T_ID = 36,                      /* T_ID  */
  YYSYMBOL_T_NEWLINE = 37,                 /* T_NEWLINE  */
  YYSYMBOL_T_INDENT = 38,                  /* T_INDENT  */
  YYSYMBOL_T_DEDENT = 39,                  /* T_DEDENT  */
  YYSYMBOL_T_T = 40,                       /* T_T  */
  YYSYMBOL_T_F = 41,                       /* T_F  */
  YYSYMBOL_T_PT = 42,                      /* T_PT  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_statement_list = 45,            /* statement_list  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_empty_line = 47,                /* empty_line  */
  YYSYMBOL_declaration = 48,               /* declaration  */
  YYSYMBOL_attribution = 49,               /* attribution  */
  YYSYMBOL_print_statement = 50,           /* print_statement  */
  YYSYMBOL_list_literal = 51,              /* list_literal  */
  YYSYMBOL_list_elements_opt = 52,         /* list_elements_opt  */
  YYSYMBOL_list_elements = 53,             /* list_elements  */
  YYSYMBOL_expression = 54,                /* expression  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_factor = 56,                    /* factor  */
  YYSYMBOL_cmp = 57,                       /* cmp  */
  YYSYMBOL_arg_list_opt = 58,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 59,                  /* arg_list  */
  YYSYMBOL_if_statement = 60,              /* if_statement  */
  YYSYMBOL_elif_blocks = 61,               /* elif_blocks  */
  YYSYMBOL_elif_block = 62,                /* elif_block  */
  YYSYMBOL_while_statement = 63,           /* while_statement  */
  YYSYMBOL_for_statement = 64,             /* for_statement  */
  YYSYMBOL_iterable = 65,                  /* iterable  */
  YYSYMBOL_function_def = 66,              /* function_def  */
  YYSYMBOL_param_list_opt = 67,            /* param_list_opt  */
  YYSYMBOL_param_list = 68,                /* param_list  */
  YYSYMBOL_typed_param = 69,               /* typed_param  */
  YYSYMBOL_condition = 70,                 /* condition  */
  YYSYMBOL_relop = 71,                     /* relop  */
  YYSYMBOL_return_statement = 72           /* return_statement  */
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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    90,    91,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   108,   116,   124,   132,   140,   149,
     158,   166,   174,   190,   198,   205,   220,   227,   241,   245,
     246,   250,   251,   259,   260,   261,   266,   267,   273,   279,
     283,   284,   285,   286,   287,   296,   304,   305,   309,   310,
     318,   322,   327,   333,   341,   342,   346,   357,   368,   376,
     377,   385,   390,   391,   395,   396,   400,   401,   402,   410,
     411,   412,   413,   417,   417,   417,   417,   417,   417,   425,
     426,   427,   428
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
  "\"end of file\"", "error", "\"invalid token\"", "T_FN", "T_IF", "T_EL",
  "T_EF", "T_FR", "T_WL", "T_R", "T_IN", "T_I", "T_FL", "T_S", "T_EQ",
  "T_NEQ", "T_GTE", "T_LTE", "T_GT", "T_LT", "T_ASSIGN", "T_PLUS",
  "T_MINUS", "T_MUL", "T_DIV", "T_MOD", "T_AND", "T_OR", "T_LPAREN",
  "T_RPAREN", "T_LBRACKET", "T_RBRACKET", "T_COMMA", "T_FLOAT_NUM",
  "T_INT_NUM", "T_STRING", "T_ID", "T_NEWLINE", "T_INDENT", "T_DEDENT",
  "T_T", "T_F", "T_PT", "$accept", "program", "statement_list",
  "statement", "empty_line", "declaration", "attribution",
  "print_statement", "list_literal", "list_elements_opt", "list_elements",
  "expression", "term", "factor", "cmp", "arg_list_opt", "arg_list",
  "if_statement", "elif_blocks", "elif_block", "while_statement",
  "for_statement", "iterable", "function_def", "param_list_opt",
  "param_list", "typed_param", "condition", "relop", "return_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     207,   -32,   206,   -23,   206,    64,   -20,     8,    10,    11,
     -93,   134,    34,   207,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,    24,   206,   -93,   -93,    38,   236,
     -17,   -93,   -93,    89,    39,   103,    25,    32,    40,   -10,
     -18,   -15,    -5,   145,    44,    -4,   -93,   -93,    90,    16,
     206,   -93,   -93,   -93,   -93,   -93,   -93,   206,   206,   206,
     206,   206,   206,   206,   206,    58,   195,    68,   -93,   -93,
     -93,   -93,   195,   -93,   195,   -93,    74,   -93,   206,    80,
      83,    14,   -93,   -93,    75,    87,    95,    96,   101,   -93,
     -93,    66,   129,   144,   -17,   -17,    66,   -93,   -93,   -93,
     -93,   137,   207,   -93,    66,   146,   207,   149,    18,   154,
      21,   158,   151,   169,    66,   -93,   -93,   -93,   -93,   -93,
     -93,   165,    90,   -93,   206,    17,   168,    71,   -93,   -93,
     -93,   -93,   -93,   -93,   206,   174,   -93,    66,   122,   207,
     -93,    66,   207,   176,   206,   131,   -93,    82,   135,   179,
     127,   189,   -93,   -93,   -93,   207,   192,   198,   148,   207,
     207,   -93,   185,   196,   -93,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     2,     3,    13,     5,     6,    12,     7,
       8,     9,    10,    11,     0,     0,    41,    40,    42,    72,
      35,    39,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     4,    62,     0,
      46,    73,    74,    77,    78,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    79,     0,    15,     0,    16,     0,    17,    29,     0,
       0,     0,    26,    27,     0,     0,     0,     0,    63,    64,
      43,    48,     0,    47,    33,    34,    45,    36,    37,    38,
      70,    69,     0,    60,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,    25,    24,    23,    66,    67,
      68,     0,     0,    44,     0,     0,     0,     0,    20,    18,
      21,    19,    22,    28,     0,     0,    65,    49,    50,     0,
      57,    32,     0,     0,     0,    51,    54,     0,     0,     0,
       0,     0,    55,    58,    61,     0,     0,     0,     0,     0,
       0,    53,     0,     0,    56,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -92,   -13,   -93,   -93,   -93,   -93,    -1,   -93,
     -93,    -2,   108,   186,   -93,   -93,   -93,   -93,   -93,    92,
     -93,   -93,   -93,   -93,   -93,   -93,   119,    -3,   -93,   -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    16,    17,    18,    80,   112,
     113,    29,    30,    31,    32,    92,    93,    19,   145,   146,
      20,    21,   105,    22,    87,    88,    89,    33,    59,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    35,    72,    39,    24,    74,    60,    61,    62,    45,
     125,    57,    58,    34,   127,    76,    40,    57,    58,    73,
       1,     2,    75,    49,     3,     4,     5,    71,     6,     7,
       8,    43,    77,    83,    46,    57,    58,    57,    58,    57,
      58,    81,    57,    58,    41,    90,    42,   147,    91,    66,
     148,   117,    48,     9,    10,   129,   138,    96,   131,    11,
     100,   101,    68,   158,   104,   103,    50,   162,   163,    69,
     108,   107,   110,   109,     1,     2,   114,    70,     3,     4,
       5,    82,     6,     7,     8,     1,     2,    57,    58,     3,
       4,     5,    25,     6,     7,     8,   102,    26,    27,    36,
      28,    84,    85,    86,    37,    38,   106,     9,    10,   111,
     140,   118,    47,    11,    47,    63,    64,   115,     9,    10,
     116,   153,   137,   119,    11,   121,    65,   143,   144,    63,
      64,   120,   141,   122,    47,    47,   151,   144,     1,     2,
      67,   150,     3,     4,     5,    47,     6,     7,     8,    47,
      47,     1,     2,    63,    64,     3,     4,     5,   123,     6,
       7,     8,    25,    63,   156,    94,    95,    26,    27,    44,
      28,     9,    10,    25,   154,    78,   124,    11,    26,    27,
      79,    28,   133,   126,     9,    10,   128,   161,     1,     2,
      11,   130,     3,     4,     5,   132,     6,     7,     8,     1,
       2,   134,   135,     3,     4,     5,   139,     6,     7,     8,
       1,     2,   142,   149,     3,     4,     5,   155,     6,     7,
       8,     9,    10,    25,   164,    78,   157,    11,    26,    27,
     159,    28,     9,    10,    25,   165,   160,   152,    11,    26,
      27,   136,    28,     9,    10,     0,    97,    98,    99,    11,
      51,    52,    53,    54,    55,    56,     0,    57,    58
};

static const yytype_int16 yycheck[] =
{
      13,     4,    20,     5,    36,    20,    23,    24,    25,    11,
     102,    21,    22,    36,   106,    20,    36,    21,    22,    37,
       3,     4,    37,    25,     7,     8,     9,    37,    11,    12,
      13,    20,    37,    37,     0,    21,    22,    21,    22,    21,
      22,    43,    21,    22,    36,    29,    36,   139,    50,    10,
     142,    37,    28,    36,    37,    37,    39,    59,    37,    42,
      63,    64,    37,   155,    66,    66,    28,   159,   160,    37,
      72,    72,    74,    74,     3,     4,    78,    37,     7,     8,
       9,    37,    11,    12,    13,     3,     4,    21,    22,     7,
       8,     9,    28,    11,    12,    13,    38,    33,    34,    35,
      36,    11,    12,    13,    40,    41,    38,    36,    37,    35,
      39,    36,   125,    42,   127,    26,    27,    37,    36,    37,
      37,    39,   124,    36,    42,    29,    37,     5,     6,    26,
      27,    36,   134,    32,   147,   148,     5,     6,     3,     4,
      37,   144,     7,     8,     9,   158,    11,    12,    13,   162,
     163,     3,     4,    26,    27,     7,     8,     9,    29,    11,
      12,    13,    28,    26,    37,    57,    58,    33,    34,    35,
      36,    36,    37,    28,    39,    30,    32,    42,    33,    34,
      35,    36,    31,    37,    36,    37,    37,    39,     3,     4,
      42,    37,     7,     8,     9,    37,    11,    12,    13,     3,
       4,    32,    37,     7,     8,     9,    38,    11,    12,    13,
       3,     4,    38,    37,     7,     8,     9,    38,    11,    12,
      13,    36,    37,    28,    39,    30,    37,    42,    33,    34,
      38,    36,    36,    37,    28,    39,    38,   145,    42,    33,
      34,   122,    36,    36,    37,    -1,    60,    61,    62,    42,
      14,    15,    16,    17,    18,    19,    -1,    21,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     7,     8,     9,    11,    12,    13,    36,
      37,    42,    44,    45,    46,    47,    48,    49,    50,    60,
      63,    64,    66,    72,    36,    28,    33,    34,    36,    54,
      55,    56,    57,    70,    36,    70,    35,    40,    41,    54,
      36,    36,    36,    20,    35,    54,     0,    46,    28,    54,
      28,    14,    15,    16,    17,    18,    19,    21,    22,    71,
      23,    24,    25,    26,    27,    37,    10,    37,    37,    37,
      37,    37,    20,    37,    20,    37,    20,    37,    30,    35,
      51,    54,    37,    37,    11,    12,    13,    67,    68,    69,
      29,    54,    58,    59,    55,    55,    54,    56,    56,    56,
      70,    70,    38,    51,    54,    65,    38,    51,    54,    51,
      54,    35,    52,    53,    54,    37,    37,    37,    36,    36,
      36,    29,    32,    29,    32,    45,    37,    45,    37,    37,
      37,    37,    37,    31,    32,    37,    69,    54,    39,    38,
      39,    54,    38,     5,     6,    61,    62,    45,    45,    37,
      70,     5,    62,    39,    39,    38,    37,    37,    45,    38,
      38,    39,    45,    45,    39,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    49,    50,    50,    51,    52,
      52,    53,    53,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    61,    61,    62,    63,    64,    65,
      65,    66,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     5,     5,
       5,     5,     5,     4,     4,     4,     3,     3,     3,     0,
       1,     1,     3,     3,     3,     1,     3,     3,     3,     1,
       1,     1,     1,     3,     4,     3,     0,     1,     1,     3,
       6,     7,    12,    11,     1,     2,     6,     6,     8,     1,
       1,     9,     0,     1,     1,     3,     2,     2,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3
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
  case 2: /* program: statement_list  */
#line 82 "sloth.y"
        {
            printf("program\n");
            indent_level++;
            print_indent(); printf("statement_list\n");
        }
#line 1287 "sloth.tab.c"
    break;

  case 15: /* declaration: T_I T_ID T_NEWLINE  */
#line 117 "sloth.y"
        {
            print_indent(); printf("declaration\n");
            indent_level++;
            print_indent(); printf("type: int\n");
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-1].ival)]);
            indent_level--;
        }
#line 1299 "sloth.tab.c"
    break;

  case 16: /* declaration: T_FL T_ID T_NEWLINE  */
#line 125 "sloth.y"
        {
            print_indent(); printf("declaration\n");
            indent_level++;
            print_indent(); printf("type: float\n");
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-1].ival)]);
            indent_level--;
        }
#line 1311 "sloth.tab.c"
    break;

  case 17: /* declaration: T_S T_ID T_NEWLINE  */
#line 133 "sloth.y"
        {
            print_indent(); printf("declaration\n");
            indent_level++;
            print_indent(); printf("type: string\n");
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-1].ival)]);
            indent_level--;
        }
#line 1323 "sloth.tab.c"
    break;

  case 18: /* declaration: T_I T_ID T_ASSIGN expression T_NEWLINE  */
#line 141 "sloth.y"
        {
            print_indent(); printf("declaration_with_init\n");
            indent_level++;
            print_indent(); printf("type: int\n");
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-3].ival)]);
            print_indent(); printf("initial value: %f\n", (yyvsp[-1].fval));
            indent_level--;
        }
#line 1336 "sloth.tab.c"
    break;

  case 19: /* declaration: T_FL T_ID T_ASSIGN expression T_NEWLINE  */
#line 150 "sloth.y"
        {
            print_indent(); printf("declaration_with_init\n");
            indent_level++;
            print_indent(); printf("type: float\n");
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-3].ival)]);
            print_indent(); printf("initial value: %f\n", (yyvsp[-1].fval));
            indent_level--;
        }
#line 1349 "sloth.tab.c"
    break;

  case 20: /* declaration: T_I T_ID T_ASSIGN list_literal T_NEWLINE  */
#line 159 "sloth.y"
        {
            print_indent(); printf("declaration_with_list\n");
            indent_level++;
            print_indent(); printf("type: int list\n");
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-3].ival)]);
            indent_level--;
        }
#line 1361 "sloth.tab.c"
    break;

  case 21: /* declaration: T_FL T_ID T_ASSIGN list_literal T_NEWLINE  */
#line 167 "sloth.y"
        {
            print_indent(); printf("declaration_with_list\n");
            indent_level++;
            print_indent(); printf("type: float list\n");
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-3].ival)]);
            indent_level--;
        }
#line 1373 "sloth.tab.c"
    break;

  case 22: /* declaration: T_S T_ID T_ASSIGN T_STRING T_NEWLINE  */
#line 175 "sloth.y"
        {
            print_indent(); printf("declaration_with_init\n");
            indent_level++;
            print_indent(); printf("type: string\n");
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-3].ival)]);
            print_indent(); printf("initial value: %s\n", (yyvsp[-1].str));
            indent_level--;
        }
#line 1386 "sloth.tab.c"
    break;

  case 23: /* attribution: T_ID T_ASSIGN expression T_NEWLINE  */
#line 191 "sloth.y"
        {
            print_indent(); printf("attribution\n");
            indent_level++;
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-3].ival)]);
            print_indent(); printf("expression value: %f\n", (yyvsp[-1].fval));
            indent_level--;
        }
#line 1398 "sloth.tab.c"
    break;

  case 24: /* attribution: T_ID T_ASSIGN list_literal T_NEWLINE  */
#line 199 "sloth.y"
        {
            print_indent(); printf("attribution (list)\n");
            indent_level++;
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-3].ival)]);
            indent_level--;
        }
#line 1409 "sloth.tab.c"
    break;

  case 25: /* attribution: T_ID T_ASSIGN T_STRING T_NEWLINE  */
#line 206 "sloth.y"
        {
            print_indent(); printf("attribution (string)\n");
            indent_level++;
            print_indent(); printf("id: %s\n", symbol_table[(yyvsp[-3].ival)]);
            print_indent(); printf("expression value: %s\n", (yyvsp[-1].str));
            indent_level--;
        }
#line 1421 "sloth.tab.c"
    break;

  case 26: /* print_statement: T_PT T_STRING T_NEWLINE  */
#line 221 "sloth.y"
        {
            print_indent(); printf("print_statement\n");
            indent_level++;
            print_indent(); printf("string: %s\n", (yyvsp[-1].str));
            indent_level--;
        }
#line 1432 "sloth.tab.c"
    break;

  case 27: /* print_statement: T_PT expression T_NEWLINE  */
#line 228 "sloth.y"
        {
            print_indent(); printf("print_expression\n");
            indent_level++;
            print_indent(); printf("expression value: %f\n", (yyvsp[-1].fval));
            indent_level--;
        }
#line 1443 "sloth.tab.c"
    break;

  case 28: /* list_literal: T_LBRACKET list_elements_opt T_RBRACKET  */
#line 241 "sloth.y"
                                              { print_indent(); printf("list_literal\n");}
#line 1449 "sloth.tab.c"
    break;

  case 33: /* expression: expression T_PLUS term  */
#line 259 "sloth.y"
                                  { (yyval.fval) = (yyvsp[-2].fval) + (yyvsp[0].fval); }
#line 1455 "sloth.tab.c"
    break;

  case 34: /* expression: expression T_MINUS term  */
#line 260 "sloth.y"
                                  { (yyval.fval) = (yyvsp[-2].fval) - (yyvsp[0].fval); }
#line 1461 "sloth.tab.c"
    break;

  case 35: /* expression: term  */
#line 261 "sloth.y"
                                  { (yyval.fval) = (yyvsp[0].fval); }
#line 1467 "sloth.tab.c"
    break;

  case 36: /* term: term T_MUL factor  */
#line 266 "sloth.y"
                                  { (yyval.fval) = (yyvsp[-2].fval) * (yyvsp[0].fval); }
#line 1473 "sloth.tab.c"
    break;

  case 37: /* term: term T_DIV factor  */
#line 268 "sloth.y"
        {
          if ((yyvsp[0].fval) == 0.0)
              yyerror("Divisão por zero");
          (yyval.fval) = (yyvsp[-2].fval) / (yyvsp[0].fval);
        }
#line 1483 "sloth.tab.c"
    break;

  case 38: /* term: term T_MOD factor  */
#line 274 "sloth.y"
        {
          if ((yyvsp[0].fval) == 0.0)
              yyerror("Módulo por zero");
          (yyval.fval) = fmod((yyvsp[-2].fval), (yyvsp[0].fval));
        }
#line 1493 "sloth.tab.c"
    break;

  case 39: /* term: factor  */
#line 279 "sloth.y"
                                  { (yyval.fval) = (yyvsp[0].fval); }
#line 1499 "sloth.tab.c"
    break;

  case 40: /* factor: T_INT_NUM  */
#line 283 "sloth.y"
                                  { (yyval.fval) = (double)(yyvsp[0].ival); }
#line 1505 "sloth.tab.c"
    break;

  case 41: /* factor: T_FLOAT_NUM  */
#line 284 "sloth.y"
                                  { (yyval.fval) = (yyvsp[0].fval); }
#line 1511 "sloth.tab.c"
    break;

  case 42: /* factor: T_ID  */
#line 285 "sloth.y"
                                  { (yyval.fval) = 0.0; }
#line 1517 "sloth.tab.c"
    break;

  case 43: /* factor: T_LPAREN expression T_RPAREN  */
#line 286 "sloth.y"
                                   { (yyval.fval) = (yyvsp[-1].fval); }
#line 1523 "sloth.tab.c"
    break;

  case 44: /* factor: T_ID T_LPAREN arg_list_opt T_RPAREN  */
#line 288 "sloth.y"
        {
            print_indent();
            printf("function_call id=%s\n", symbol_table[(yyvsp[-3].ival)]);
            (yyval.fval) = 0.0;
        }
#line 1533 "sloth.tab.c"
    break;

  case 45: /* cmp: expression relop expression  */
#line 297 "sloth.y"
        {
            print_indent(); printf("cmp\n");
            (yyval.fval) = 0.0;
        }
#line 1542 "sloth.tab.c"
    break;

  case 50: /* if_statement: T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 319 "sloth.y"
        {
            print_indent(); printf("if_statement\n");
        }
#line 1550 "sloth.tab.c"
    break;

  case 51: /* if_statement: T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT elif_blocks  */
#line 324 "sloth.y"
        {
            print_indent(); printf("if_elif_statement\n");
        }
#line 1558 "sloth.tab.c"
    break;

  case 52: /* if_statement: T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT elif_blocks T_EL T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 330 "sloth.y"
        {
            print_indent(); printf("if_elif_else_statement\n");
        }
#line 1566 "sloth.tab.c"
    break;

  case 53: /* if_statement: T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT T_EL T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 335 "sloth.y"
        {
            print_indent(); printf("if_else_statement\n");
        }
#line 1574 "sloth.tab.c"
    break;

  case 56: /* elif_block: T_EF condition T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 347 "sloth.y"
        {
            print_indent(); printf("elif_block\n");
        }
#line 1582 "sloth.tab.c"
    break;

  case 57: /* while_statement: T_WL condition T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 358 "sloth.y"
        {
            print_indent(); printf("while_statement\n");
        }
#line 1590 "sloth.tab.c"
    break;

  case 58: /* for_statement: T_FR T_ID T_IN iterable T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 369 "sloth.y"
        {
            print_indent();
            printf("for_statement iterator=%s\n", symbol_table[(yyvsp[-6].ival)]);
        }
#line 1599 "sloth.tab.c"
    break;

  case 61: /* function_def: T_FN T_ID T_LPAREN param_list_opt T_RPAREN T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 386 "sloth.y"
                                       { print_indent(); printf("function_def id=%s\n", symbol_table[(yyvsp[-7].ival)]);}
#line 1605 "sloth.tab.c"
    break;

  case 66: /* typed_param: T_I T_ID  */
#line 400 "sloth.y"
                  { print_indent(); printf("param: %s %s\n", "I",  symbol_table[(yyvsp[0].ival)]); }
#line 1611 "sloth.tab.c"
    break;

  case 67: /* typed_param: T_FL T_ID  */
#line 401 "sloth.y"
                  { print_indent(); printf("param: %s %s\n", "FL", symbol_table[(yyvsp[0].ival)]); }
#line 1617 "sloth.tab.c"
    break;

  case 68: /* typed_param: T_S T_ID  */
#line 402 "sloth.y"
                  { print_indent(); printf("param: %s %s\n", "S",  symbol_table[(yyvsp[0].ival)]); }
#line 1623 "sloth.tab.c"
    break;

  case 69: /* condition: condition T_OR condition  */
#line 410 "sloth.y"
                                     { print_indent(); printf("condition OR\n"); }
#line 1629 "sloth.tab.c"
    break;

  case 70: /* condition: condition T_AND condition  */
#line 411 "sloth.y"
                                     { print_indent(); printf("condition AND\n"); }
#line 1635 "sloth.tab.c"
    break;

  case 71: /* condition: cmp  */
#line 412 "sloth.y"
                                     { print_indent(); printf("condition (cmp)\n"); }
#line 1641 "sloth.tab.c"
    break;

  case 72: /* condition: expression  */
#line 413 "sloth.y"
                                     { print_indent(); printf("condition (expr)\n"); }
#line 1647 "sloth.tab.c"
    break;

  case 79: /* return_statement: T_R expression T_NEWLINE  */
#line 425 "sloth.y"
                               { print_indent(); printf("return_statement\n"); }
#line 1653 "sloth.tab.c"
    break;

  case 80: /* return_statement: T_R T_STRING T_NEWLINE  */
#line 426 "sloth.y"
                             { print_indent(); printf("return_statement (string)\n");}
#line 1659 "sloth.tab.c"
    break;

  case 81: /* return_statement: T_R T_T T_NEWLINE  */
#line 427 "sloth.y"
                        { print_indent(); printf("return_statement (True)\n");}
#line 1665 "sloth.tab.c"
    break;

  case 82: /* return_statement: T_R T_F T_NEWLINE  */
#line 428 "sloth.y"
                        { print_indent(); printf("return_statement (False)\n");}
#line 1671 "sloth.tab.c"
    break;


#line 1675 "sloth.tab.c"

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

#line 431 "sloth.y"


/* ==============================
   CÓDIGO FINAL
   ============================== */

int main(int argc, char **argv) {
    yydebug = 1;

    FILE *infile = NULL;

    if (argc > 1) {
        infile = fopen(argv[1], "r");
        if (!infile) {
            fprintf(stderr, "Erro ao abrir arquivo '%s'\n", argv[1]);
            return 1;
        }
        yyin = infile;
    }

    init_lexer();

    printf("=== Iniciando análise sintática da linguagem Sloth ===\n");

    int res = yyparse();

    for (int i = 0; i < symbol_count; i++)
        free(symbol_table[i]);

    if (infile) fclose(infile);
    return res;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
