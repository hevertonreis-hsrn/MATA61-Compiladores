%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* -------------------------------
    ANALISADOR LÉXICO - LINGUAGEM SLOTH
   ------------------------------- */

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

/* Controle de indentação */
int current_indent = 0;
int indent_stack[100];
int indent_top = 0;
int pending_dedents = 0;
int paren_level = 0;
int tabsize = 8;

/* Contador de linhas */
int line_count = 1;

/* Tabela de símbolos */
#define MAX_SYMBOLS 200
char *symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

int yylval;

/* Adiciona identificadores na tabela de símbolos */
int get_symbol_position(const char *id) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i], id) == 0) {
            return i;
        }
    }
    symbol_table[symbol_count] = strdup(id);
    return symbol_count++;
}

/* calcula coluna a partir de string contendo apenas espaços e tabs */
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
%}

/* Opções */
%option noyywrap
%x DEDENT_MODE

/* Expressões regulares */
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
    /* ---------------- DEDENT_MODE: emite DEDENTs pendentes sem consumir input ---------------- */
    if (pending_dedents > 0) {
        pending_dedents--;
        if (pending_dedents == 0) BEGIN(INITIAL);
        printf("<DEDENT>\n");
        return T_DEDENT;
    } else {
        BEGIN(INITIAL);
    }
}

^[ \t]*\n    {
                line_count++;
                /* ignora linha em branco (não gera NEWLINE lógico) */
              }

^[ \t]+      {
                if (paren_level > 0) {
                    /* dentro de parênteses: indentação não conta */
                    /* apenas continue - não produz INDENT/DEDENT */
                } else {
                    int newcol = compute_indent_column(yytext);
                    int topcol = indent_stack[indent_top];
                    if (newcol > topcol) {
                        /* aumento de indent */
                        indent_top++;
                        if (indent_top >= 100) {
                            fprintf(stderr, "Erro: pilha de indentation overflow\n");
                            exit(1);
                        }
                        indent_stack[indent_top] = newcol;
                        printf("<INDENT>\n");
                        return T_INDENT;
                    } else if (newcol == topcol) {
                        /* mesma indent: nada a fazer */
                    } else {
                        /* dedent(s) necessários */
                        int dedents_needed = 0;
                        while (indent_top > 0 && indent_stack[indent_top] > newcol) {
                            indent_top--;
                            dedents_needed++;
                        }
                        if (indent_stack[indent_top] != newcol) {
                            fprintf(stderr, "Indentation error at line %d: unexpected indent level %d\n", line_count, newcol);
                            exit(1);
                        }
                        if (dedents_needed > 0) {
                            pending_dedents = dedents_needed - 1;
                            if (pending_dedents > 0) BEGIN(DEDENT_MODE);
                            printf("<DEDENT>\n");
                            return T_DEDENT;
                        }
                    }
                }
             }

^[ \t]*      {
                /* esta regra pega também o caso sem espaços no início da linha */
                if (paren_level == 0) {
                    int topcol = indent_stack[indent_top];
                    if (topcol > 0) {
                        /* dedenta até 0 */
                        int dedents_needed = 0;
                        while (indent_top > 0) { indent_top--; dedents_needed++; }
                        pending_dedents = dedents_needed - 1;
                        if (pending_dedents > 0) BEGIN(DEDENT_MODE);
                        printf("<DEDENT>\n");
                        return T_DEDENT;
                    }
                }
                /* caso contrário continua normalmente (sem emitir token) */
             }

\r                    { /* ignora carriage return (Windows) */ }

\n            {
                line_count++;
                if (paren_level == 0) {
                    printf("<NEWLINE>\n");
                    return T_NEWLINE;
                } else {
                    /* newline dentro de parênteses -> ignora para estruturação */
                }
            }

"("           { paren_level++; printf("<LPAREN>\n"); return T_LPAREN; }
")"           { if (paren_level > 0) paren_level--; printf("<RPAREN>\n"); return T_RPAREN; }
"["           { paren_level++; printf("<LBRACKET>\n"); return T_LBRACKET; }
"]"           { if (paren_level > 0) paren_level--; printf("<RBRACKET>\n"); return T_RBRACKET; }
"{"           { paren_level++; printf("<LBRACE>\n"); return '{'; }
"}"           { if (paren_level > 0) paren_level--; printf("<RBRACE>\n"); return '}'; }

{COMMENT}             { /* ignora comentário */ }

"FN"                  { printf("<FN>\n"); return T_FN; }
"IF"                  { printf("<IF>\n"); return T_IF; }
"EL"                  { printf("<EL>\n"); return T_EL; }
"EF"                  { printf("<EF>\n"); return T_EF; }
"FR"                  { printf("<FR>\n"); return T_FR; }
"WL"                  { printf("<WL>\n"); return T_WL; }
"R"                   { printf("<R>\n"); return T_R; }
"I"                   { printf("<I>\n"); return T_I; }
"FL"                  { printf("<FL>\n"); return T_FL; }
"S"                   { printf("<S>\n"); return T_S; }
"T"                   { printf("<T>\n"); return T_T; }
"F"                   { printf("<F>\n"); return T_F; }
"PT"                  { printf("<PT>\n"); return T_PT; }
"IN"                  { printf("<IN>\n"); return T_IN; }

"=="                  { printf("<EQ>\n"); return T_EQ; }
"!="                  { printf("<NEQ>\n"); return T_NEQ; }
">="                  { printf("<GTE>\n"); return T_GTE; }
"<="                  { printf("<LTE>\n"); return T_LTE; }
">"                   { printf("<GT>\n"); return T_GT; }
"<"                   { printf("<LT>\n"); return T_LT; }
"="                   { printf("<ASSIGN>\n"); return T_ASSIGN; }
"\+"                  { printf("<PLUS>\n"); return T_PLUS; }
"-"                   { printf("<MINUS>\n"); return T_MINUS; }
"%"                   { printf("<MOD>\n"); return T_MOD; }
"\*"                  { printf("<MUL>\n"); return T_MUL; }
"/"                   { printf("<DIV>\n"); return T_DIV; }
"&"                   { printf("<AND>\n"); return T_AND; }
"|"                   { printf("<OR>\n"); return T_OR; }

","                   { printf("<COMMA>\n"); return T_COMMA; }

{FLOAT}               { printf("<FLOAT, %s>\n", yytext); return T_FLOAT_NUM; }
{INT}                 { printf("<INT, %s>\n", yytext); return T_INT_NUM; }

{STRING}              { printf("<STRING, %s>\n", yytext); return T_STRING; }

{ID}                  {
                        yylval = get_symbol_position(yytext);
                        printf("<ID, %s, symidx=%d>\n", yytext, yylval);
                        return T_ID;
                      }

{WS}                  { /* ignora espaços/tabs no meio da linha */ }

.                     { printf("Erro Léxico (linha %d): caractere inesperado '%s'\n", line_count, yytext); return T_UNKNOWN; }

<<EOF>>               {
                        /* emite dedents necessários para voltar ao nível 0 */
                        while (indent_top > 0) {
                            indent_top--;
                            printf("<DEDENT>\n");
                        }
                        /* final */
                        return 0;
                    }

%%

int main(int argc, char **argv) {
    /* inicializa pilha de indentação (nível 0) */
    indent_stack[0] = 0;
    indent_top = 0;
    pending_dedents = 0;
    paren_level = 0;

    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file) yyin = file;
    }

    printf("=== Iniciando análise léxica da linguagem Sloth ===\n\n");

    int token;
    while ((token = yylex())) { /* vazio - prints já são feitos nas regras */ }

    printf("\n\n--- Tabela de Símbolos ---\n");
    printf("Posição | Identificador\n");
    printf("-------------------------\n");
    for (int i = 0; i < symbol_count; i++)
        printf("%-7d | %s\n", i, symbol_table[i]);
    printf("-------------------------\n");

    for (int i = 0; i < symbol_count; i++)
        free(symbol_table[i]);

    return 0;
}
