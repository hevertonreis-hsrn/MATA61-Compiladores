/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SLOTH_TAB_H_INCLUDED
# define YY_YY_SLOTH_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_FN = 258,                    /* T_FN  */
    T_IF = 259,                    /* T_IF  */
    T_EL = 260,                    /* T_EL  */
    T_EF = 261,                    /* T_EF  */
    T_FR = 262,                    /* T_FR  */
    T_WL = 263,                    /* T_WL  */
    T_R = 264,                     /* T_R  */
    T_IN = 265,                    /* T_IN  */
    T_I = 266,                     /* T_I  */
    T_FL = 267,                    /* T_FL  */
    T_S = 268,                     /* T_S  */
    T_EQ = 269,                    /* T_EQ  */
    T_NEQ = 270,                   /* T_NEQ  */
    T_GTE = 271,                   /* T_GTE  */
    T_LTE = 272,                   /* T_LTE  */
    T_GT = 273,                    /* T_GT  */
    T_LT = 274,                    /* T_LT  */
    T_ASSIGN = 275,                /* T_ASSIGN  */
    T_PLUS = 276,                  /* T_PLUS  */
    T_MINUS = 277,                 /* T_MINUS  */
    T_MUL = 278,                   /* T_MUL  */
    T_DIV = 279,                   /* T_DIV  */
    T_MOD = 280,                   /* T_MOD  */
    T_AND = 281,                   /* T_AND  */
    T_OR = 282,                    /* T_OR  */
    T_LPAREN = 283,                /* T_LPAREN  */
    T_RPAREN = 284,                /* T_RPAREN  */
    T_LBRACKET = 285,              /* T_LBRACKET  */
    T_RBRACKET = 286,              /* T_RBRACKET  */
    T_COMMA = 287,                 /* T_COMMA  */
    T_FLOAT_NUM = 288,             /* T_FLOAT_NUM  */
    T_INT_NUM = 289,               /* T_INT_NUM  */
    T_STRING = 290,                /* T_STRING  */
    T_ID = 291,                    /* T_ID  */
    T_NEWLINE = 292,               /* T_NEWLINE  */
    T_INDENT = 293,                /* T_INDENT  */
    T_DEDENT = 294,                /* T_DEDENT  */
    T_T = 295,                     /* T_T  */
    T_F = 296,                     /* T_F  */
    T_PT = 297,                    /* T_PT  */
    T_UNKNOWN = 298                /* T_UNKNOWN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "sloth.y"

    int ival;      /* inteiros e índices de símbolo */
    double fval;   /* floats e valores de expressão */
    char *str;     /* strings literais */

#line 113 "sloth.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SLOTH_TAB_H_INCLUDED  */
