%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sloth.tab.h"

/* Flex já gerencia yylineno */
int yylineno;

/* -------------------------------
   INDENTAÇÃO ESTILO PYTHON
   ------------------------------- */

int current_indent = 0;
int indent_stack[100];
int indent_top = 0;
int pending_dedents = 0;
int paren_level = 0;
int tabsize = 8;

/* -------------------------------
   TABELA DE SÍMBOLOS
   ------------------------------- */

#define MAX_SYMBOLS 200
char *symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

int get_symbol_position(const char *id) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i], id) == 0)
            return i;
    }
    symbol_table[symbol_count] = strdup(id);
    return symbol_count++;
}

/* Calcula coluna de indentação */
int compute_indent_column(const char *s) {
    int col = 0;
    for (const char *p = s; *p; ++p) {
        if (*p == ' ')
            col += 1;
        else if (*p == '\t') {
            int add = tabsize - (col % tabsize);
            col += add;
        }
    }
    return col;
}

/* -----------------------------------------------------
   Função opcional para inicializar variáveis do lexer.
   Chame isto no main() do Bison ANTES de yyparse().
   ----------------------------------------------------- */
void init_lexer() {
    indent_top = 0;
    indent_stack[0] = 0;
    pending_dedents = 0;
    paren_level = 0;
}

%}

%option noyywrap
%option yylineno

%x DEDENT_MODE

/* Expressões Regulares */
DIGITO      [0-9]
LETRA       [a-zA-Z_]
ID          {LETRA}({LETRA}|{DIGITO})*
INT         {DIGITO}+
FLOAT       {DIGITO}+\.{DIGITO}+
STRING      (\"[^\"\n]*\"|\'[^\'\n]*\')
COMMENT     \#[^\n]*
WS          [ \t]+

%%

<DEDENT_MODE>"" {
    if (pending_dedents > 0) {
        pending_dedents--;
        if (pending_dedents == 0) BEGIN(INITIAL);
        return T_DEDENT;
    } else {
        BEGIN(INITIAL);
    }
}

^[ \t]*$   { /* linha realmente vazia — não retorna NEWLINE */ }

^[ \t]+ {
    if (paren_level == 0) {
        int newcol = compute_indent_column(yytext);
        int topcol = indent_stack[indent_top];

        if (newcol > topcol) {
            indent_top++;
            indent_stack[indent_top] = newcol;
            return T_INDENT;
        } 
        else if (newcol < topcol) {
            int dedents_needed = 0;
            while (indent_top > 0 && indent_stack[indent_top] > newcol) {
                indent_top--;
                dedents_needed++;
            }
            if (indent_stack[indent_top] != newcol) {
                fprintf(stderr, "Indentation error at line %d\n", yylineno);
                exit(1);
            }
            if (dedents_needed > 0) {
                pending_dedents = dedents_needed - 1;
                if (pending_dedents > 0)
                    BEGIN(DEDENT_MODE);
                return T_DEDENT;
            }
        }
    }
}

^[ \t]* {
    if (paren_level == 0) {
        if (indent_stack[indent_top] > 0) {
            int dedents = 0;
            while (indent_top > 0) { indent_top--; dedents++; }
            pending_dedents = dedents - 1;
            if (pending_dedents > 0) BEGIN(DEDENT_MODE);
            return T_DEDENT;
        }
    }
}

\n {
    if (paren_level == 0)
        return T_NEWLINE;
}

"("   { paren_level++; return T_LPAREN; }
")"   { if (paren_level > 0) paren_level--; return T_RPAREN; }
"["   { paren_level++; return T_LBRACKET; }
"]"   { if (paren_level > 0) paren_level--; return T_RBRACKET; }

{COMMENT}   { /* ignora */ }

"FN"  { return T_FN; }
"IF"  { return T_IF; }
"EL"  { return T_EL; }
"EF"  { return T_EF; }
"FR"  { return T_FR; }
"WL"  { return T_WL; }
"R"   { return T_R; }
"I"   { return T_I; }
"FL"  { return T_FL; }
"S"   { return T_S; }
"T"   { return T_T; }
"F"   { return T_F; }
"PT"  { return T_PT; }
"IN"  { return T_IN; }

"=="  { return T_EQ; }
"!="  { return T_NEQ; }
">="  { return T_GTE; }
"<="  { return T_LTE; }
">"   { return T_GT; }
"<"   { return T_LT; }
"="   { return T_ASSIGN; }
"\+"  { return T_PLUS; }
"-"   { return T_MINUS; }
"%"   { return T_MOD; }
"\*"  { return T_MUL; }
"/"   { return T_DIV; }
"&"   { return T_AND; }
"|"   { return T_OR; }
","   { return T_COMMA; }

{FLOAT}   { yylval.fval = atof(yytext); return T_FLOAT_NUM; }
{INT}     { yylval.ival = atoi(yytext); return T_INT_NUM; }
{STRING}  { yylval.str = strdup(yytext); return T_STRING; }

{ID} {
    yylval.ival = get_symbol_position(yytext);
    return T_ID;
}

{WS}  { /* ignora */ }

. {
    fprintf(stderr, "Erro léxico na linha %d: caractere inesperado '%s'\n",
            yylineno, yytext);
    return T_UNKNOWN;
}

<<EOF>> {
    while (indent_top > 0) {
        indent_top--;
        return T_DEDENT;
    }
    return 0;
}

%%
