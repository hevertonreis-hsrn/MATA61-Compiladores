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
#line 6 "sloth.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define YYDEBUG 1
int yydebug = 1;

/* --- ESTRUTURAS DA ÁRVORE SINTÁTICA --- */

typedef struct ASTNode {
    char *type;             // Nome da regra (ex: "statement", "if_statement")
    char *value;            // Valor extra (ex: "5", "x", "int") - pode ser NULL
    int child_count;        // Quantidade de filhos
    struct ASTNode **children; // Array de ponteiros para filhos
} ASTNode;

ASTNode *root = NULL; /* Raiz da árvore final */

/* Função para criar um novo nó da árvore */
ASTNode* create_node(char* type, char* value, int child_count, ...) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    if (value) node->value = strdup(value);
    else node->value = NULL;
    
    node->child_count = child_count;
    node->children = NULL;

    if (child_count > 0) {
        node->children = (ASTNode**)malloc(sizeof(ASTNode*) * child_count);
        va_list args;
        va_start(args, child_count);
        for (int i = 0; i < child_count; i++) {
            node->children[i] = va_arg(args, ASTNode*);
        }
        va_end(args);
    }
    return node;
}

/* Função recursiva para imprimir a árvore */
void print_tree(ASTNode* node, int level) {
    if (!node) return;

    // Imprime indentação
    for (int i = 0; i < level; i++) printf("    ");

    // Imprime o Tipo do Nó
    printf("%s", node->type);

    // Se tiver valor extra, imprime embaixo (ou ao lado, dependendo do gosto)
    // Aqui seguiremos o estilo "vertical" do seu requisito
    if (node->value) {
        printf("\n");
        for (int i = 0; i < level + 1; i++) printf("    ");
        printf("%s", node->value);
    }
    printf("\n");

    // Imprime filhos recursivamente
    for (int i = 0; i < node->child_count; i++) {
        print_tree(node->children[i], level + 1);
    }
}

/* Protótipos e Externs */
int yylex(void);
void yyerror(const char *s);
extern char *symbol_table[];
extern int symbol_count;
extern void init_lexer(void);
extern FILE *yyin;


#line 148 "sloth.tab.c"

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
  YYSYMBOL_declaration = 47,               /* declaration  */
  YYSYMBOL_attribution = 48,               /* attribution  */
  YYSYMBOL_print_statement = 49,           /* print_statement  */
  YYSYMBOL_function_def = 50,              /* function_def  */
  YYSYMBOL_param_list_opt = 51,            /* param_list_opt  */
  YYSYMBOL_param_list = 52,                /* param_list  */
  YYSYMBOL_typed_param = 53,               /* typed_param  */
  YYSYMBOL_if_statement = 54,              /* if_statement  */
  YYSYMBOL_elif_blocks = 55,               /* elif_blocks  */
  YYSYMBOL_elif_block = 56,                /* elif_block  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_term = 58,                      /* term  */
  YYSYMBOL_factor = 59,                    /* factor  */
  YYSYMBOL_condition = 60,                 /* condition  */
  YYSYMBOL_logical_expression = 61,        /* logical_expression  */
  YYSYMBOL_logical_term = 62,              /* logical_term  */
  YYSYMBOL_logical_factor = 63,            /* logical_factor  */
  YYSYMBOL_cmp = 64,                       /* cmp  */
  YYSYMBOL_relop = 65,                     /* relop  */
  YYSYMBOL_return_statement = 66,          /* return_statement  */
  YYSYMBOL_while_statement = 67,           /* while_statement  */
  YYSYMBOL_for_statement = 68,             /* for_statement  */
  YYSYMBOL_iterable = 69,                  /* iterable  */
  YYSYMBOL_list_literal = 70,              /* list_literal  */
  YYSYMBOL_list_elements_opt = 71,         /* list_elements_opt  */
  YYSYMBOL_list_elements = 72,             /* list_elements  */
  YYSYMBOL_arg_list_opt = 73,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 74                   /* arg_list  */
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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
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
       0,   139,   139,   147,   151,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   175,   181,   187,   194,   201,   208,
     215,   230,   236,   242,   255,   259,   270,   282,   283,   287,
     289,   294,   295,   296,   304,   309,   313,   320,   322,   327,
     336,   337,   338,   342,   343,   344,   345,   349,   354,   359,
     361,   364,   375,   380,   382,   387,   389,   394,   396,   401,
     408,   409,   410,   411,   412,   413,   421,   425,   429,   434,
     441,   443,   450,   451,   455,   460,   461,   465,   467,   472,
     473,   477,   479
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
  "statement", "declaration", "attribution", "print_statement",
  "function_def", "param_list_opt", "param_list", "typed_param",
  "if_statement", "elif_blocks", "elif_block", "expression", "term",
  "factor", "condition", "logical_expression", "logical_term",
  "logical_factor", "cmp", "relop", "return_statement", "while_statement",
  "for_statement", "iterable", "list_literal", "list_elements_opt",
  "list_elements", "arg_list_opt", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,   -29,   192,   -22,   192,   167,     1,    16,    24,    38,
     -99,    93,    32,    27,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,    37,   192,   -99,   -99,    45,   195,    22,
     -99,    56,    50,    84,   -99,   -99,   102,    87,   100,   103,
     121,    -4,    -9,    -8,    33,   145,   126,     5,   -99,   -99,
     105,   -16,   192,   -99,   -99,   -99,   -99,   -99,   -99,   192,
     192,   192,   192,   192,   192,    44,   192,   192,   134,   138,
     -99,   -99,   -99,   -99,   134,   -99,   192,   -99,   151,   -99,
     192,   154,    34,   162,   -99,   -99,   179,   182,   183,   194,
     197,   -99,   -99,    46,   201,   199,    22,    22,    46,   -99,
     -99,   -99,    27,    84,   -99,    46,   196,   -99,    27,    67,
     198,   132,   200,    46,   203,   204,   -99,   -99,   -99,   -99,
     -99,   -99,   202,   105,   -99,   192,    12,   205,    72,   -99,
     -99,   -99,   -99,   -99,   192,   206,   -99,    46,   160,    27,
     -99,    46,    27,   208,   192,   177,   -99,    83,    94,   209,
     211,   212,   -99,   -99,   -99,    27,   213,   214,   135,    27,
      27,   -99,   148,   185,   -99,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     2,     3,     5,     6,    12,    10,     7,
      11,     8,     9,     0,     0,    48,    47,    49,    58,    42,
      46,     0,    52,    54,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     4,
      27,     0,    79,    60,    61,    64,    65,    62,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,    66,     0,    14,     0,    15,     0,    16,
      75,     0,     0,     0,    24,    25,     0,     0,     0,     0,
      28,    29,    50,    81,     0,    80,    40,    41,    59,    43,
      44,    45,     0,    53,    55,    72,     0,    73,     0,     0,
       0,     0,     0,    77,     0,    76,    22,    21,    23,    31,
      32,    33,     0,     0,    51,     0,     0,     0,     0,    17,
      18,    19,    20,    74,     0,     0,    30,    82,    34,     0,
      70,    78,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,    38,    71,    26,     0,     0,     0,     0,     0,
       0,    36,     0,     0,    39,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -98,   -13,   -99,   -99,   -99,   -99,   -99,   -99,
     109,   -99,   -99,    95,    -2,    40,   142,    -3,   -99,   172,
     174,   -99,   -99,   -99,   -99,   -99,   -99,   -66,   -99,   -99,
     -99,   -99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    16,    17,    18,    89,    90,
      91,    19,   145,   146,    28,    29,    30,    31,    32,    33,
      34,    35,    61,    20,    21,    22,   106,    83,   114,   115,
      94,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    37,   107,    41,   126,    59,    60,    23,   110,    47,
     128,    74,    76,    92,    36,     1,     2,    59,    60,     3,
       4,     5,    51,     6,     7,     8,    59,    60,    75,    77,
       1,     2,    48,    73,     3,     4,     5,    42,     6,     7,
       8,   147,    85,    82,   148,    62,    63,    64,     9,    10,
      93,   138,    43,    78,    11,    59,    60,   158,    45,    98,
      44,   162,   163,     9,    10,    50,   105,    59,    60,    11,
      79,   117,   109,    52,   111,     1,     2,    66,   113,     3,
       4,     5,   102,     6,     7,     8,     1,     2,    59,    60,
       3,     4,     5,    65,     6,     7,     8,     1,     2,    96,
      97,     3,     4,     5,   129,     6,     7,     8,     9,    10,
      67,   140,    68,    49,    11,    49,    86,    87,    88,     9,
      10,    24,   153,   137,    69,    11,    25,    26,    46,    27,
       9,    10,   141,   154,    49,    49,    11,    70,     1,     2,
      71,   150,     3,     4,     5,    49,     6,     7,     8,    49,
      49,     1,     2,    59,    60,     3,     4,     5,    72,     6,
       7,     8,    24,    84,    80,   143,   144,    25,    26,   131,
      27,     9,    10,    24,   161,    80,   108,    11,    25,    26,
      81,    27,   151,   144,     9,    10,   112,   164,     1,     2,
      11,   116,     3,     4,     5,    24,     6,     7,     8,   118,
      25,    26,    38,    27,    99,   100,   101,    39,    40,    53,
      54,    55,    56,    57,    58,   119,    59,    60,   120,   121,
      24,     9,    10,   122,   165,    25,    26,    11,    27,   123,
     124,   125,   136,   127,   133,   130,   134,   132,   103,   135,
     152,   104,     0,   139,   142,   149,     0,   155,   156,   157,
       0,   159,   160
};

static const yytype_int16 yycheck[] =
{
      13,     4,    68,     5,   102,    21,    22,    36,    74,    11,
     108,    20,    20,    29,    36,     3,     4,    21,    22,     7,
       8,     9,    24,    11,    12,    13,    21,    22,    37,    37,
       3,     4,     0,    37,     7,     8,     9,    36,    11,    12,
      13,   139,    37,    45,   142,    23,    24,    25,    36,    37,
      52,    39,    36,    20,    42,    21,    22,   155,    20,    61,
      36,   159,   160,    36,    37,    28,    68,    21,    22,    42,
      37,    37,    74,    28,    76,     3,     4,    27,    80,     7,
       8,     9,    38,    11,    12,    13,     3,     4,    21,    22,
       7,     8,     9,    37,    11,    12,    13,     3,     4,    59,
      60,     7,     8,     9,    37,    11,    12,    13,    36,    37,
      26,    39,    10,   126,    42,   128,    11,    12,    13,    36,
      37,    28,    39,   125,    37,    42,    33,    34,    35,    36,
      36,    37,   134,    39,   147,   148,    42,    37,     3,     4,
      37,   144,     7,     8,     9,   158,    11,    12,    13,   162,
     163,     3,     4,    21,    22,     7,     8,     9,    37,    11,
      12,    13,    28,    37,    30,     5,     6,    33,    34,    37,
      36,    36,    37,    28,    39,    30,    38,    42,    33,    34,
      35,    36,     5,     6,    36,    37,    35,    39,     3,     4,
      42,    37,     7,     8,     9,    28,    11,    12,    13,    37,
      33,    34,    35,    36,    62,    63,    64,    40,    41,    14,
      15,    16,    17,    18,    19,    36,    21,    22,    36,    36,
      28,    36,    37,    29,    39,    33,    34,    42,    36,    32,
      29,    32,   123,    37,    31,    37,    32,    37,    66,    37,
     145,    67,    -1,    38,    38,    37,    -1,    38,    37,    37,
      -1,    38,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     7,     8,     9,    11,    12,    13,    36,
      37,    42,    44,    45,    46,    47,    48,    49,    50,    54,
      66,    67,    68,    36,    28,    33,    34,    36,    57,    58,
      59,    60,    61,    62,    63,    64,    36,    60,    35,    40,
      41,    57,    36,    36,    36,    20,    35,    57,     0,    46,
      28,    57,    28,    14,    15,    16,    17,    18,    19,    21,
      22,    65,    23,    24,    25,    37,    27,    26,    10,    37,
      37,    37,    37,    37,    20,    37,    20,    37,    20,    37,
      30,    35,    57,    70,    37,    37,    11,    12,    13,    51,
      52,    53,    29,    57,    73,    74,    58,    58,    57,    59,
      59,    59,    38,    62,    63,    57,    69,    70,    38,    57,
      70,    57,    35,    57,    71,    72,    37,    37,    37,    36,
      36,    36,    29,    32,    29,    32,    45,    37,    45,    37,
      37,    37,    37,    31,    32,    37,    53,    57,    39,    38,
      39,    57,    38,     5,     6,    55,    56,    45,    45,    37,
      60,     5,    56,    39,    39,    38,    37,    37,    45,    38,
      38,    39,    45,    45,    39,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    48,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    53,    53,    53,    54,    54,    54,    55,    55,    56,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    66,
      67,    68,    69,    69,    70,    71,    71,    72,    72,    73,
      73,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     5,     5,     5,
       5,     4,     4,     4,     3,     3,     9,     0,     1,     1,
       3,     2,     2,     2,     6,    12,    11,     1,     2,     6,
       3,     3,     1,     3,     3,     3,     1,     1,     1,     1,
       3,     4,     1,     3,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       6,     8,     1,     1,     3,     0,     1,     1,     3,     0,
       1,     1,     3
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
#line 140 "sloth.y"
        {
            (yyval.node) = create_node("program", NULL, 1, (yyvsp[0].node));
            root = (yyval.node); /* Salva na raiz global para imprimir no main */
        }
#line 1342 "sloth.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 148 "sloth.y"
        {
            (yyval.node) = create_node("statement_list", NULL, 1, (yyvsp[0].node));
        }
#line 1350 "sloth.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 152 "sloth.y"
        {
            /* Cria um nó lista que agrupa o anterior e o novo */
            (yyval.node) = create_node("statement_list", NULL, 2, (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1359 "sloth.tab.c"
    break;

  case 5: /* statement: declaration  */
#line 159 "sloth.y"
                        { (yyval.node) = create_node("statement", NULL, 1, (yyvsp[0].node)); }
#line 1365 "sloth.tab.c"
    break;

  case 6: /* statement: attribution  */
#line 160 "sloth.y"
                        { (yyval.node) = create_node("statement", NULL, 1, (yyvsp[0].node)); }
#line 1371 "sloth.tab.c"
    break;

  case 7: /* statement: if_statement  */
#line 161 "sloth.y"
                        { (yyval.node) = create_node("statement", NULL, 1, (yyvsp[0].node)); }
#line 1377 "sloth.tab.c"
    break;

  case 8: /* statement: while_statement  */
#line 162 "sloth.y"
                        { (yyval.node) = create_node("statement", NULL, 1, (yyvsp[0].node)); }
#line 1383 "sloth.tab.c"
    break;

  case 9: /* statement: for_statement  */
#line 163 "sloth.y"
                        { (yyval.node) = create_node("statement", NULL, 1, (yyvsp[0].node)); }
#line 1389 "sloth.tab.c"
    break;

  case 10: /* statement: function_def  */
#line 164 "sloth.y"
                        { (yyval.node) = create_node("statement", NULL, 1, (yyvsp[0].node)); }
#line 1395 "sloth.tab.c"
    break;

  case 11: /* statement: return_statement  */
#line 165 "sloth.y"
                        { (yyval.node) = create_node("statement", NULL, 1, (yyvsp[0].node)); }
#line 1401 "sloth.tab.c"
    break;

  case 12: /* statement: print_statement  */
#line 166 "sloth.y"
                        { (yyval.node) = create_node("statement", NULL, 1, (yyvsp[0].node)); }
#line 1407 "sloth.tab.c"
    break;

  case 13: /* statement: T_NEWLINE  */
#line 167 "sloth.y"
                        { (yyval.node) = NULL; /* Ignora linhas vazias na árvore ou retorna nó vazio */ }
#line 1413 "sloth.tab.c"
    break;

  case 14: /* declaration: T_I T_ID T_NEWLINE  */
#line 176 "sloth.y"
        {
            (yyval.node) = create_node("declaration", NULL, 2, 
                    create_node("INT", NULL, 0),
                    create_node(symbol_table[(yyvsp[-1].ival)], NULL, 0));
        }
#line 1423 "sloth.tab.c"
    break;

  case 15: /* declaration: T_FL T_ID T_NEWLINE  */
#line 182 "sloth.y"
        {
            (yyval.node) = create_node("declaration", NULL, 2, 
                    create_node("FLOAT", NULL, 0),
                    create_node(symbol_table[(yyvsp[-1].ival)], NULL, 0));
        }
#line 1433 "sloth.tab.c"
    break;

  case 16: /* declaration: T_S T_ID T_NEWLINE  */
#line 188 "sloth.y"
        {
            (yyval.node) = create_node("declaration", NULL, 2, 
                    create_node("STRING", NULL, 0),
                    create_node(symbol_table[(yyvsp[-1].ival)], NULL, 0));
        }
#line 1443 "sloth.tab.c"
    break;

  case 17: /* declaration: T_I T_ID T_ASSIGN expression T_NEWLINE  */
#line 195 "sloth.y"
        {
            (yyval.node) = create_node("declaration", NULL, 3, 
                    create_node("INT", NULL, 0),
                    create_node(symbol_table[(yyvsp[-3].ival)], NULL, 0),
                    (yyvsp[-1].node));
        }
#line 1454 "sloth.tab.c"
    break;

  case 18: /* declaration: T_I T_ID T_ASSIGN list_literal T_NEWLINE  */
#line 202 "sloth.y"
        {
            (yyval.node) = create_node("declaration_list", NULL, 3, 
                    create_node("INT_LIST", NULL, 0),
                    create_node(symbol_table[(yyvsp[-3].ival)], NULL, 0),
                    (yyvsp[-1].node));
        }
#line 1465 "sloth.tab.c"
    break;

  case 19: /* declaration: T_FL T_ID T_ASSIGN expression T_NEWLINE  */
#line 209 "sloth.y"
        {
            (yyval.node) = create_node("declaration_init", NULL, 3, 
                    create_node("FLOAT", NULL, 0),
                    create_node(symbol_table[(yyvsp[-3].ival)], NULL, 0),
                    (yyvsp[-1].node));
        }
#line 1476 "sloth.tab.c"
    break;

  case 20: /* declaration: T_S T_ID T_ASSIGN T_STRING T_NEWLINE  */
#line 216 "sloth.y"
        {
            (yyval.node) = create_node("declaration_init_string", NULL, 3, 
                    create_node("STRING", NULL, 0),
                    create_node(symbol_table[(yyvsp[-3].ival)], NULL, 0),
                    create_node("string_literal", (yyvsp[-1].str), 0)
                );
        }
#line 1488 "sloth.tab.c"
    break;

  case 21: /* attribution: T_ID T_ASSIGN expression T_NEWLINE  */
#line 231 "sloth.y"
        {
            (yyval.node) = create_node("attribution", NULL, 2,
                    create_node(symbol_table[(yyvsp[-3].ival)], NULL, 0),
                    (yyvsp[-1].node));
        }
#line 1498 "sloth.tab.c"
    break;

  case 22: /* attribution: T_ID T_ASSIGN T_STRING T_NEWLINE  */
#line 237 "sloth.y"
        {
            (yyval.node) = create_node("attribution", NULL, 2,
                    create_node(symbol_table[(yyvsp[-3].ival)], NULL, 0),
                    create_node("string_literal", (yyvsp[-1].str), 0));
        }
#line 1508 "sloth.tab.c"
    break;

  case 23: /* attribution: T_ID T_ASSIGN list_literal T_NEWLINE  */
#line 243 "sloth.y"
        {
             (yyval.node) = create_node("attribution_list", NULL, 2,
                    create_node(symbol_table[(yyvsp[-3].ival)], NULL, 0),
                    (yyvsp[-1].node));
        }
#line 1518 "sloth.tab.c"
    break;

  case 24: /* print_statement: T_PT T_STRING T_NEWLINE  */
#line 256 "sloth.y"
        {
             (yyval.node) = create_node("print_statement", NULL, 1, create_node("string", (yyvsp[-1].str), 0));
        }
#line 1526 "sloth.tab.c"
    break;

  case 25: /* print_statement: T_PT expression T_NEWLINE  */
#line 260 "sloth.y"
        {
             (yyval.node) = create_node("print_statement", NULL, 1, (yyvsp[-1].node));
        }
#line 1534 "sloth.tab.c"
    break;

  case 26: /* function_def: T_FN T_ID T_LPAREN param_list_opt T_RPAREN T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 271 "sloth.y"
        {
            (yyval.node) = create_node("function_def", NULL, 4,
                    create_node("FN", NULL, 0),
                    create_node("id", symbol_table[(yyvsp[-7].ival)], 0),
                    (yyvsp[-5].node), /* param_list */
                    (yyvsp[-1].node)  /* body */
            );
        }
#line 1547 "sloth.tab.c"
    break;

  case 27: /* param_list_opt: %empty  */
#line 282 "sloth.y"
                    { (yyval.node) = create_node("parameter_list", "empty", 0); }
#line 1553 "sloth.tab.c"
    break;

  case 28: /* param_list_opt: param_list  */
#line 283 "sloth.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1559 "sloth.tab.c"
    break;

  case 29: /* param_list: typed_param  */
#line 288 "sloth.y"
        { (yyval.node) = create_node("parameter_list", NULL, 1, (yyvsp[0].node)); }
#line 1565 "sloth.tab.c"
    break;

  case 30: /* param_list: param_list T_COMMA typed_param  */
#line 290 "sloth.y"
        { (yyval.node) = create_node("parameter_list", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1571 "sloth.tab.c"
    break;

  case 31: /* typed_param: T_I T_ID  */
#line 294 "sloth.y"
                { (yyval.node) = create_node("param", NULL, 2, create_node("INT", NULL, 0), create_node(symbol_table[(yyvsp[0].ival)], NULL, 0)); }
#line 1577 "sloth.tab.c"
    break;

  case 32: /* typed_param: T_FL T_ID  */
#line 295 "sloth.y"
                { (yyval.node) = create_node("param", NULL, 2, create_node("FLOAT", NULL, 0), create_node(symbol_table[(yyvsp[0].ival)], NULL, 0)); }
#line 1583 "sloth.tab.c"
    break;

  case 33: /* typed_param: T_S T_ID  */
#line 296 "sloth.y"
                { (yyval.node) = create_node("param", NULL, 2, create_node("STRING", NULL, 0), create_node(symbol_table[(yyvsp[0].ival)], NULL, 0)); }
#line 1589 "sloth.tab.c"
    break;

  case 34: /* if_statement: T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 305 "sloth.y"
        {
            (yyval.node) = create_node("if_statement", NULL, 2, (yyvsp[-4].node), (yyvsp[-1].node));
        }
#line 1597 "sloth.tab.c"
    break;

  case 35: /* if_statement: T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT elif_blocks T_EL T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 310 "sloth.y"
        {
             (yyval.node) = create_node("if_elif_else", NULL, 4, (yyvsp[-10].node), (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-1].node));
        }
#line 1605 "sloth.tab.c"
    break;

  case 36: /* if_statement: T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT T_EL T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 314 "sloth.y"
        {
            (yyval.node) = create_node("if_else_statement", NULL, 3, (yyvsp[-9].node), (yyvsp[-6].node), (yyvsp[-1].node));
        }
#line 1613 "sloth.tab.c"
    break;

  case 37: /* elif_blocks: elif_block  */
#line 321 "sloth.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1619 "sloth.tab.c"
    break;

  case 38: /* elif_blocks: elif_blocks elif_block  */
#line 323 "sloth.y"
        { (yyval.node) = create_node("elif_list", NULL, 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1625 "sloth.tab.c"
    break;

  case 39: /* elif_block: T_EF condition T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 328 "sloth.y"
        { (yyval.node) = create_node("elif_block", NULL, 2, (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1631 "sloth.tab.c"
    break;

  case 40: /* expression: expression T_PLUS term  */
#line 336 "sloth.y"
                              { (yyval.node) = create_node("expr", "+", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1637 "sloth.tab.c"
    break;

  case 41: /* expression: expression T_MINUS term  */
#line 337 "sloth.y"
                              { (yyval.node) = create_node("expr", "-", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1643 "sloth.tab.c"
    break;

  case 42: /* expression: term  */
#line 338 "sloth.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1649 "sloth.tab.c"
    break;

  case 43: /* term: term T_MUL factor  */
#line 342 "sloth.y"
                              { (yyval.node) = create_node("term", "*", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1655 "sloth.tab.c"
    break;

  case 44: /* term: term T_DIV factor  */
#line 343 "sloth.y"
                              { (yyval.node) = create_node("term", "/", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1661 "sloth.tab.c"
    break;

  case 45: /* term: term T_MOD factor  */
#line 344 "sloth.y"
                              { (yyval.node) = create_node("term", "%", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1667 "sloth.tab.c"
    break;

  case 46: /* term: factor  */
#line 345 "sloth.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1673 "sloth.tab.c"
    break;

  case 47: /* factor: T_INT_NUM  */
#line 350 "sloth.y"
        { 
            char buffer[20]; sprintf(buffer, "%d", (yyvsp[0].ival));
            (yyval.node) = create_node("int", buffer, 0); 
        }
#line 1682 "sloth.tab.c"
    break;

  case 48: /* factor: T_FLOAT_NUM  */
#line 355 "sloth.y"
        { 
            char buffer[20]; sprintf(buffer, "%.2f", (yyvsp[0].fval));
            (yyval.node) = create_node("float", buffer, 0); 
        }
#line 1691 "sloth.tab.c"
    break;

  case 49: /* factor: T_ID  */
#line 360 "sloth.y"
        { (yyval.node) = create_node("id", symbol_table[(yyvsp[0].ival)], 0); }
#line 1697 "sloth.tab.c"
    break;

  case 50: /* factor: T_LPAREN expression T_RPAREN  */
#line 362 "sloth.y"
        { (yyval.node) = (yyvsp[-1].node); }
#line 1703 "sloth.tab.c"
    break;

  case 51: /* factor: T_ID T_LPAREN arg_list_opt T_RPAREN  */
#line 365 "sloth.y"
        {
            /* Se arg_list_opt for NULL, passamos 0 filhos para evitar erro, ou tratamos na create_node */
            if ((yyvsp[-1].node) == NULL)
                (yyval.node) = create_node("function_call", symbol_table[(yyvsp[-3].ival)], 0);
            else
                (yyval.node) = create_node("function_call", symbol_table[(yyvsp[-3].ival)], 1, (yyvsp[-1].node));
        }
#line 1715 "sloth.tab.c"
    break;

  case 52: /* condition: logical_expression  */
#line 376 "sloth.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1721 "sloth.tab.c"
    break;

  case 53: /* logical_expression: logical_expression T_OR logical_term  */
#line 381 "sloth.y"
        { (yyval.node) = create_node("LOGIC_OR", "OR", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1727 "sloth.tab.c"
    break;

  case 54: /* logical_expression: logical_term  */
#line 383 "sloth.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1733 "sloth.tab.c"
    break;

  case 55: /* logical_term: logical_term T_AND logical_factor  */
#line 388 "sloth.y"
        { (yyval.node) = create_node("LOGIC_AND", "AND", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1739 "sloth.tab.c"
    break;

  case 56: /* logical_term: logical_factor  */
#line 390 "sloth.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1745 "sloth.tab.c"
    break;

  case 57: /* logical_factor: cmp  */
#line 395 "sloth.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1751 "sloth.tab.c"
    break;

  case 58: /* logical_factor: expression  */
#line 397 "sloth.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1757 "sloth.tab.c"
    break;

  case 59: /* cmp: expression relop expression  */
#line 402 "sloth.y"
    {
        (yyval.node) = create_node("comparison", NULL, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1765 "sloth.tab.c"
    break;

  case 60: /* relop: T_EQ  */
#line 408 "sloth.y"
            { (yyval.node) = create_node("relop", "==", 0); }
#line 1771 "sloth.tab.c"
    break;

  case 61: /* relop: T_NEQ  */
#line 409 "sloth.y"
            { (yyval.node) = create_node("relop", "!=", 0); }
#line 1777 "sloth.tab.c"
    break;

  case 62: /* relop: T_GT  */
#line 410 "sloth.y"
            { (yyval.node) = create_node("relop", ">", 0); }
#line 1783 "sloth.tab.c"
    break;

  case 63: /* relop: T_LT  */
#line 411 "sloth.y"
            { (yyval.node) = create_node("relop", "<", 0); }
#line 1789 "sloth.tab.c"
    break;

  case 64: /* relop: T_GTE  */
#line 412 "sloth.y"
            { (yyval.node) = create_node("relop", ">=", 0); }
#line 1795 "sloth.tab.c"
    break;

  case 65: /* relop: T_LTE  */
#line 413 "sloth.y"
            { (yyval.node) = create_node("relop", "<=", 0); }
#line 1801 "sloth.tab.c"
    break;

  case 66: /* return_statement: T_R expression T_NEWLINE  */
#line 422 "sloth.y"
        {
            (yyval.node) = create_node("return_statement", NULL, 2, create_node("R", NULL, 0), (yyvsp[-1].node));
        }
#line 1809 "sloth.tab.c"
    break;

  case 67: /* return_statement: T_R T_STRING T_NEWLINE  */
#line 426 "sloth.y"
        {
            (yyval.node) = create_node("return_statement", NULL, 2, create_node("R", NULL, 0), create_node("string", (yyvsp[-1].str), 0));
        }
#line 1817 "sloth.tab.c"
    break;

  case 68: /* return_statement: T_R T_T T_NEWLINE  */
#line 430 "sloth.y"
        { 
            (yyval.node) = create_node("return_boolean", NULL, 2, create_node("R", NULL, 0), create_node("TRUE", NULL, 0));
        }
#line 1825 "sloth.tab.c"
    break;

  case 69: /* return_statement: T_R T_F T_NEWLINE  */
#line 435 "sloth.y"
        { 
            (yyval.node) = create_node("return_boolean", NULL, 2, create_node("R", NULL, 0), create_node("FALSE", NULL, 0));
        }
#line 1833 "sloth.tab.c"
    break;

  case 70: /* while_statement: T_WL condition T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 441 "sloth.y"
                                                                           { (yyval.node) = create_node("while", NULL, 2, (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1839 "sloth.tab.c"
    break;

  case 71: /* for_statement: T_FR T_ID T_IN iterable T_NEWLINE T_INDENT statement_list T_DEDENT  */
#line 444 "sloth.y"
        {
            (yyval.node) = create_node("for_statement", symbol_table[(yyvsp[-6].ival)], 3, create_node("IN", NULL, 0), (yyvsp[-4].node), (yyvsp[-1].node));
        }
#line 1847 "sloth.tab.c"
    break;

  case 72: /* iterable: expression  */
#line 450 "sloth.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1853 "sloth.tab.c"
    break;

  case 73: /* iterable: list_literal  */
#line 451 "sloth.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1859 "sloth.tab.c"
    break;

  case 74: /* list_literal: T_LBRACKET list_elements_opt T_RBRACKET  */
#line 456 "sloth.y"
        { (yyval.node) = create_node("list_literal", NULL, 1, (yyvsp[-1].node)); }
#line 1865 "sloth.tab.c"
    break;

  case 75: /* list_elements_opt: %empty  */
#line 460 "sloth.y"
                     { (yyval.node) = NULL; }
#line 1871 "sloth.tab.c"
    break;

  case 76: /* list_elements_opt: list_elements  */
#line 461 "sloth.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1877 "sloth.tab.c"
    break;

  case 77: /* list_elements: expression  */
#line 466 "sloth.y"
        { (yyval.node) = create_node("list_item", NULL, 1, (yyvsp[0].node)); }
#line 1883 "sloth.tab.c"
    break;

  case 78: /* list_elements: list_elements T_COMMA expression  */
#line 468 "sloth.y"
        { (yyval.node) = create_node("list_item", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1889 "sloth.tab.c"
    break;

  case 79: /* arg_list_opt: %empty  */
#line 472 "sloth.y"
                  { (yyval.node) = NULL; }
#line 1895 "sloth.tab.c"
    break;

  case 80: /* arg_list_opt: arg_list  */
#line 473 "sloth.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1901 "sloth.tab.c"
    break;

  case 81: /* arg_list: expression  */
#line 478 "sloth.y"
        { (yyval.node) = create_node("arg", NULL, 1, (yyvsp[0].node)); }
#line 1907 "sloth.tab.c"
    break;

  case 82: /* arg_list: arg_list T_COMMA expression  */
#line 480 "sloth.y"
        { (yyval.node) = create_node("arg", NULL, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1913 "sloth.tab.c"
    break;


#line 1917 "sloth.tab.c"

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

#line 483 "sloth.y"


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

    if (res == 0 && root != NULL) {
        printf("\n--- Arvore Sintatica Gerada ---\n");
        print_tree(root, 0);
    } else {
        printf("\nFalha na geracao da arvore.\n");
    }

    // Limpeza simples (num compilador real, teríamos uma função free_tree)
    for (int i = 0; i < symbol_count; i++)
        free(symbol_table[i]);

    if (infile) fclose(infile);
    return res;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
