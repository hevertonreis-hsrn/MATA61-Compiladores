%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sloth.tab.h"

int yylineno;

typedef enum {
    T_UNKNOWN = 296
} TokenType;

int indent_stack[100];
int indent_top = 0;
int pending_dedents = 0;
int paren_level = 0;
int tabsize = 8;

int line_count = 1;

/* tabela de símbolos */
#define MAX_SYMBOLS 200
char *symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

/* indicador de início de linha */
int at_bol = 1;

/* Função utilitária */
int get_symbol_position(const char *id) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i], id) == 0) return i;
    }
    symbol_table[symbol_count] = strdup(id);
    return symbol_count++;
}

static int count_leading_tabs(const char *s) {
    int n = 0;
    for (const char *p = s; *p; ++p) {
        if (*p == '\t') n++;
        else if (*p == ' ') continue;
        else break;
    }
    return n;
}

void init_lexer() {
    indent_stack[0] = 0;
    indent_top = 0;
    pending_dedents = 0;
    paren_level = 0;
    line_count = 1;
    symbol_count = 0;
    at_bol = 1;
}

static int emit_dedent_if_needed() {
    if (!at_bol) return 0;
    if (paren_level != 0) { at_bol = 0; return 0; }

    if (indent_stack[indent_top] > 0) {
        int dedents_needed = 0;
        while (indent_top > 0) {
            indent_top--;
            dedents_needed++;
        }

        pending_dedents = dedents_needed - 1;

        at_bol = 0;
        return T_DEDENT;
    }
    at_bol = 0;
    return 0;
}

/* Macro auxiliar: chama emit_dedent_if_needed() e garante retorno a INITIAL
   caso não existam mais pending_dedents, ou entra em DEDENT_MODE caso haja. */
#define CHECK_DEDENT() \
    do { \
        int _tok = emit_dedent_if_needed(); \
        if (_tok == T_DEDENT) { \
            yyless(0); \
            if (pending_dedents > 0) { BEGIN(DEDENT_MODE); } \
            else { BEGIN(INITIAL); } \
            return T_DEDENT; \
        } \
    } while (0)

%}

/* opções */
%option noyywrap
%option yylineno
%x DEDENT_MODE

/* regexps */
DIGITO      [0-9]
LETRA       [a-zA-Z_]
ID          {LETRA}({LETRA}|{DIGITO})*
INT         {DIGITO}+
FLOAT       {DIGITO}+\.{DIGITO}+ 
STRING      (\"[^\"\n]*\"|\'[^\'\n]*\')
COMMENT     \#[^\n]*

%%

<DEDENT_MODE>. {
    /* Casa qualquer caractere em DEDENT_MODE para garantir que o ECHO não ocorra */
    yyless(0); /* Devolve o caractere que casou para a stream de entrada */

    if (pending_dedents > 0) {
        pending_dedents--;
        if (pending_dedents == 0) BEGIN(INITIAL);
        return T_DEDENT;
    }

    /* Se não houver mais pendentes, volta para INITIAL e deixa o caractere ser processado */
    BEGIN(INITIAL);
    yyless(yyleng); /* Não faz nada, já está no buffer, só para fins de clareza */
}

^[ \t]*\n    {
    line_count++;
    at_bol = 1;
}

^[ \t]+      {
    if (paren_level > 0) {
        /* dentro de parênteses: não considera indentação para blocos */
        at_bol = 0;
    } else {
        int newlevel = count_leading_tabs(yytext);
        int top = indent_stack[indent_top];

        if (newlevel > top) {
            indent_top++;
            if (indent_top >= 100) {
                fprintf(stderr, "Erro: pilha de indentation overflow\n");
                exit(1);
            }
            indent_stack[indent_top] = newlevel;
            at_bol = 0;
            return T_INDENT;
        } else if (newlevel < top) {
            int dedents_needed = 0;
            while (indent_top > 0 && indent_stack[indent_top] > newlevel) {
                indent_top--;
                dedents_needed++;
            }
            if (indent_stack[indent_top] != newlevel) {
                fprintf(stderr,
                    "Indentation error at line %d: unexpected indent level %d (top=%d)\n",
                    line_count, newlevel, indent_stack[indent_top]);
                exit(1);
            }
            if (dedents_needed > 0) {
                pending_dedents = dedents_needed - 1;
                if (pending_dedents > 0) BEGIN(DEDENT_MODE);
                at_bol = 0;
                return T_DEDENT;
            }
        } else {
            at_bol = 0;
        }
    }
}

\r { /* ignora carriage returns do Windows */ }

\n {
    line_count++;
    at_bol = 1;
    if (paren_level == 0) {
        return T_NEWLINE;
    }
}

"("        { CHECK_DEDENT(); paren_level++; at_bol = 0; return T_LPAREN; }
")"        { CHECK_DEDENT(); if (paren_level > 0) paren_level--; at_bol = 0; return T_RPAREN; }
"["        { CHECK_DEDENT(); paren_level++; at_bol = 0; return T_LBRACKET; }
"]"        { CHECK_DEDENT(); if (paren_level > 0) paren_level--; at_bol = 0; return T_RBRACKET; }

{COMMENT}  { CHECK_DEDENT(); at_bol = 0; /* ignora comentário */ }

"FN"       { CHECK_DEDENT(); at_bol = 0; return T_FN; }
"IF"       { CHECK_DEDENT(); at_bol = 0; return T_IF; }
"EL"       { CHECK_DEDENT(); at_bol = 0; return T_EL; }
"EF"       { CHECK_DEDENT(); at_bol = 0; return T_EF; }
"FR"       { CHECK_DEDENT(); at_bol = 0; return T_FR; }
"WL"       { CHECK_DEDENT(); at_bol = 0; return T_WL; }
"R"        { CHECK_DEDENT(); at_bol = 0; return T_R; }
"I"        { CHECK_DEDENT(); at_bol = 0; return T_I; }
"FL"       { CHECK_DEDENT(); at_bol = 0; return T_FL; }
"S"        { CHECK_DEDENT(); at_bol = 0; return T_S; }
"T"        { CHECK_DEDENT(); at_bol = 0; return T_T; }
"F"        { CHECK_DEDENT(); at_bol = 0; return T_F; }
"PT"       { CHECK_DEDENT(); at_bol = 0; return T_PT; }
"IN"       { CHECK_DEDENT(); at_bol = 0; return T_IN; }

"=="       { CHECK_DEDENT(); at_bol = 0; return T_EQ; }
"!="       { CHECK_DEDENT(); at_bol = 0; return T_NEQ; }
">="       { CHECK_DEDENT(); at_bol = 0; return T_GTE; }
"<="       { CHECK_DEDENT(); at_bol = 0; return T_LTE; }
">"        { CHECK_DEDENT(); at_bol = 0; return T_GT; }
"<"        { CHECK_DEDENT(); at_bol = 0; return T_LT; }
"="        { CHECK_DEDENT(); at_bol = 0; return T_ASSIGN; }
"\+"       { CHECK_DEDENT(); at_bol = 0; return T_PLUS; }
"-"        { CHECK_DEDENT(); at_bol = 0; return T_MINUS; }
"%"        { CHECK_DEDENT(); at_bol = 0; return T_MOD; }
"\*"       { CHECK_DEDENT(); at_bol = 0; return T_MUL; }
"/"        { CHECK_DEDENT(); at_bol = 0; return T_DIV; }
"&"        { CHECK_DEDENT(); at_bol = 0; return T_AND; }
"|"        { CHECK_DEDENT(); at_bol = 0; return T_OR; }

","        { CHECK_DEDENT(); at_bol = 0; return T_COMMA; }

{FLOAT}    { CHECK_DEDENT(); yylval.fval = atof(yytext); at_bol = 0; return T_FLOAT_NUM; }
{INT}      { CHECK_DEDENT(); yylval.ival = atoi(yytext); at_bol = 0; return T_INT_NUM; }
{STRING}   { CHECK_DEDENT(); yylval.str = strdup(yytext); at_bol = 0; return T_STRING; }

{ID}       {
    CHECK_DEDENT();
    yylval.ival = get_symbol_position(yytext);
    at_bol = 0;
    return T_ID;
}

[ \t]+     { at_bol = 0; }

.          { fprintf(stderr, "Erro léxico na linha %d: caractere inesperado '%s'\n", yylineno, yytext); return T_UNKNOWN; }

<<EOF>>    {
    while (indent_top > 0) {
        indent_top--;
        return T_DEDENT;
    }
    return 0;
}

%%
