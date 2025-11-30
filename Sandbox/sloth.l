%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* -------------------------------
    ANALISADOR LÉXICO - LINGUAGEM SLOTH
   ------------------------------- */

/* Definições de tokens  */
typedef enum {
    T_FN = 258,
    T_IF = 259,
    T_EL = 260,
    T_EF = 261,
    T_FR = 262,
    T_WL = 263,
    T_R = 264,
    T_I = 265,
    T_FL = 266,
    T_S = 267,
    T_T = 268,
    T_F = 269,
    T_PT = 270,
    T_IN = 271,
    T_EQ = 272,
    T_NEQ = 273,
    T_GTE = 274,
    T_LTE = 275,
    T_GT = 276,
    T_LT = 277,
    T_ASSIGN = 278,
    T_PLUS = 279,
    T_MINUS = 280,
    T_MOD = 281,
    T_MUL = 282,
    T_DIV = 283,
    T_AND = 284,
    T_OR = 285,
    T_LPAREN = 286,
    T_RPAREN = 287,
    T_LBRACKET = 288,
    T_RBRACKET = 289,
    T_COMMA = 290,
    T_FLOAT_NUM = 291,
    T_INT_NUM = 292,
    T_STRING = 293,
    T_ID = 294,
    T_NEWLINE = 295,
    T_INDENT = 297,
    T_DEDENT = 298,
    T_UNKNOWN = 296
} TokenType;

/* -------------------------------
   Estado do lexer / indentação
   ------------------------------- */

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

int yylval;

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

        printf("<DEDENT>\n");
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
        printf("<DEDENT>\n");
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
            printf("<INDENT tabs=%d>\n", newlevel);
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
                printf("<DEDENT tabs=%d>\n", newlevel);
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
        printf("<NEWLINE>\n");
        return T_NEWLINE;
    }
}

"("        { CHECK_DEDENT(); paren_level++; printf("<LPAREN>\n"); at_bol = 0; return T_LPAREN; }
")"        { CHECK_DEDENT(); if (paren_level > 0) paren_level--; printf("<RPAREN>\n"); at_bol = 0; return T_RPAREN; }
"["        { CHECK_DEDENT(); paren_level++; printf("<LBRACKET>\n"); at_bol = 0; return T_LBRACKET; }
"]"        { CHECK_DEDENT(); if (paren_level > 0) paren_level--; printf("<RBRACKET>\n"); at_bol = 0; return T_RBRACKET; }
"{"        { CHECK_DEDENT(); paren_level++; printf("<LBRACE>\n"); at_bol = 0; return '{'; }
"}"        { CHECK_DEDENT(); if (paren_level > 0) paren_level--; printf("<RBRACE>\n"); at_bol = 0; return '}'; }

{COMMENT}  { CHECK_DEDENT(); at_bol = 0; /* ignora comentário */ }

"FN"       { CHECK_DEDENT(); printf("<FN>\n"); at_bol = 0; return T_FN; }
"IF"       { CHECK_DEDENT(); printf("<IF>\n"); at_bol = 0; return T_IF; }
"EL"       { CHECK_DEDENT(); printf("<EL>\n"); at_bol = 0; return T_EL; }
"EF"       { CHECK_DEDENT(); printf("<EF>\n"); at_bol = 0; return T_EF; }
"FR"       { CHECK_DEDENT(); printf("<FR>\n"); at_bol = 0; return T_FR; }
"WL"       { CHECK_DEDENT(); printf("<WL>\n"); at_bol = 0; return T_WL; }
"R"        { CHECK_DEDENT(); printf("<R>\n"); at_bol = 0; return T_R; }
"I"        { CHECK_DEDENT(); printf("<I>\n"); at_bol = 0; return T_I; }
"FL"       { CHECK_DEDENT(); printf("<FL>\n"); at_bol = 0; return T_FL; }
"S"        { CHECK_DEDENT(); printf("<S>\n"); at_bol = 0; return T_S; }
"T"        { CHECK_DEDENT(); printf("<T>\n"); at_bol = 0; return T_T; }
"F"        { CHECK_DEDENT(); printf("<F>\n"); at_bol = 0; return T_F; }
"PT"       { CHECK_DEDENT(); printf("<PT>\n"); at_bol = 0; return T_PT; }
"IN"       { CHECK_DEDENT(); printf("<IN>\n"); at_bol = 0; return T_IN; }

"=="       { CHECK_DEDENT(); printf("<EQ>\n"); at_bol = 0; return T_EQ; }
"!="       { CHECK_DEDENT(); printf("<NEQ>\n"); at_bol = 0; return T_NEQ; }
">="       { CHECK_DEDENT(); printf("<GTE>\n"); at_bol = 0; return T_GTE; }
"<="       { CHECK_DEDENT(); printf("<LTE>\n"); at_bol = 0; return T_LTE; }
">"        { CHECK_DEDENT(); printf("<GT>\n"); at_bol = 0; return T_GT; }
"<"        { CHECK_DEDENT(); printf("<LT>\n"); at_bol = 0; return T_LT; }
"="        { CHECK_DEDENT(); printf("<ASSIGN>\n"); at_bol = 0; return T_ASSIGN; }
"\+"       { CHECK_DEDENT(); printf("<PLUS>\n"); at_bol = 0; return T_PLUS; }
"-"        { CHECK_DEDENT(); printf("<MINUS>\n"); at_bol = 0; return T_MINUS; }
"%"        { CHECK_DEDENT(); printf("<MOD>\n"); at_bol = 0; return T_MOD; }
"\*"       { CHECK_DEDENT(); printf("<MUL>\n"); at_bol = 0; return T_MUL; }
"/"        { CHECK_DEDENT(); printf("<DIV>\n"); at_bol = 0; return T_DIV; }
"&"        { CHECK_DEDENT(); printf("<AND>\n"); at_bol = 0; return T_AND; }
"|"        { CHECK_DEDENT(); printf("<OR>\n"); at_bol = 0; return T_OR; }

","        { CHECK_DEDENT(); printf("<COMMA>\n"); at_bol = 0; return T_COMMA; }

{FLOAT}    { CHECK_DEDENT(); printf("<FLOAT %s>\n", yytext); at_bol = 0; return T_FLOAT_NUM; }
{INT}      { CHECK_DEDENT(); printf("<INT %s>\n", yytext); at_bol = 0; return T_INT_NUM; }
{STRING}   { CHECK_DEDENT(); printf("<STRING %s>\n", yytext); at_bol = 0; return T_STRING; }

{ID}       {
    CHECK_DEDENT();
    yylval = get_symbol_position(yytext);
    printf("<ID %s idx=%d>\n", yytext, yylval);
    at_bol = 0;
    return T_ID;
}

[ \t]+     { at_bol = 0; }

.          { printf("Erro Lexico (linha %d): caractere inesperado '%s'\n", line_count, yytext); return T_UNKNOWN; }

<<EOF>>    {
    while (indent_top > 0) {
        indent_top--;
        printf("<DEDENT>\n");
    }
    return 0;
}

%%

/* um pequeno main para testes independentes do parser */
int main(int argc, char **argv) {
    init_lexer();
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) yyin = f;
    }

    printf("=== Iniciando análise léxica da linguagem Sloth (tabs-based indent) ===\n\n");
    int tok;
    while ((tok = yylex())) {
        /* os prints são feitos nas regras; aqui apenas itera */
    }

    printf("\n--- Tabela de Símbolos ---\n");
    printf("Posição | Identificador\n");
    printf("-------------------------\n");
    for (int i = 0; i < symbol_count; i++)
        printf("%-7d | %s\n", i, symbol_table[i]);
    printf("-------------------------\n");

    for (int i = 0; i < symbol_count; i++) free(symbol_table[i]);
    return 0;
}
