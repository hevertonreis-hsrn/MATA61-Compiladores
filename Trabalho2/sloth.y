/* ===========================================
   ANALISADOR SINTÁTICO - LINGUAGEM SLOTH
   =========================================== */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

%}

/* ------------------------------------
   Seção de Declarações do Bison
   ------------------------------------ */

%union {
    int ival;
    double fval;
    char *str;
}

/* TOKENS */
%token T_FN T_IF T_EL T_EF T_FR T_WL T_R T_IN
%token T_I T_FL T_S
%token T_EQ T_NEQ T_GTE T_LTE T_GT T_LT
%token T_ASSIGN
%token T_PLUS T_MINUS T_MUL T_DIV T_MOD
%token T_AND T_OR
%token T_LPAREN T_RPAREN
%token T_LBRACKET T_RBRACKET
%token T_COMMA
%token <fval> T_FLOAT_NUM
%token <ival> T_INT_NUM
%token <str> T_STRING
%token <ival> T_ID
%token T_NEWLINE T_INDENT T_DEDENT
%token T_T T_F T_PT T_UNKNOWN

/* Tipos de não-terminais */
%type <fval> expression term factor

%start program

/* ------------------------------------------------------
   Agora podemos declarar funções que usam os tokens!
   ------------------------------------------------------*/

%code {
void print_token_debug(int token) {
    switch(token) {
        case T_FN: printf("[TOKEN] T_FN\n"); break;
        case T_IF: printf("[TOKEN] T_IF\n"); break;
        case T_EL: printf("[TOKEN] T_EL\n"); break;
        case T_EF: printf("[TOKEN] T_EF\n"); break;
        case T_FR: printf("[TOKEN] T_FR\n"); break;
        case T_WL: printf("[TOKEN] T_WL\n"); break;
        case T_R:  printf("[TOKEN] T_R\n"); break;
        case T_IN: printf("[TOKEN] T_IN\n"); break;

        case T_ID:
            printf("[TOKEN] T_ID (%s)\n", symbol_table[yylval.ival]);
            break;

        case T_INT_NUM:
            printf("[TOKEN] T_INT_NUM (%d)\n", yylval.ival);
            break;

        case T_FLOAT_NUM:
            printf("[TOKEN] T_FLOAT_NUM (%f)\n", yylval.fval);
            break;

        case T_STRING:
            printf("[TOKEN] T_STRING (%s)\n", yylval.str);
            break;

        case T_NEWLINE: printf("[TOKEN] T_NEWLINE\n"); break;
        case T_INDENT:  printf("[TOKEN] T_INDENT\n"); break;
        case T_DEDENT:  printf("[TOKEN] T_DEDENT\n"); break;

        case T_UNKNOWN:
            printf("[TOKEN] T_UNKNOWN (%s)\n", yylval.str);
            break;

        default:
            printf("[TOKEN] outro (%d)\n", token);
    }
}
}

%%

/* ========================
   REGRAS DA GRAMÁTICA
   ======================== */

program
    : statement_list
        {
            printf("program\n");
            indent_level++;
            print_indent(); printf("statement_list\n");
        }
    ;

statement_list
    : statement
    | statement_list statement
    ;

statement
    : declaration
    | attribution
    | if_statement
    | while_statement
    | for_statement
    | function_def
    | return_statement
    ;

/* DECLARAÇÃO */
declaration
    : T_I T_ID T_NEWLINE
        {
            print_indent(); printf("declaration\n");
            indent_level++;
            print_indent(); printf("type: int\n");
            print_indent(); printf("id: %s\n", symbol_table[$2]);
            indent_level--;
        }
    | T_FL T_ID T_NEWLINE
        {
            print_indent(); printf("declaration\n");
            indent_level++;
            print_indent(); printf("type: float\n");
            print_indent(); printf("id: %s\n", symbol_table[$2]);
            indent_level--;
        }
    ;

/* ATRIBUIÇÃO */
attribution
    : T_ID T_ASSIGN expression T_NEWLINE
        {
            print_indent(); printf("attribution\n");
            indent_level++;
            print_indent(); printf("id: %s\n", symbol_table[$1]);
            print_indent(); printf("expression value: %f\n", $3);
            indent_level--;
        }
    ;

/* EXPRESSÕES */
expression
    : expression T_PLUS term   { $$ = $1 + $3; }
    | expression T_MINUS term  { $$ = $1 - $3; }
    | term                     { $$ = $1; }
    ;

term
    : term T_MUL factor        { $$ = $1 * $3; }
    | term T_DIV factor        {
         if ($3 == 0.0)
             yyerror("Divisão por zero");
         $$ = $1 / $3;
    }
    | factor                   { $$ = $1; }
    ;

factor
    : T_INT_NUM                { $$ = (double)$1; }
    | T_FLOAT_NUM              { $$ = $1; }
    | T_ID                     { $$ = 0.0; }
    | T_LPAREN expression T_RPAREN { $$ = $2; }
    ;

/* IF */
if_statement
    : T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("if_statement\n");
        }
    | T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT
      T_EL T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("if_else_statement\n");
        }
    ;

/* WHILE */
while_statement
    : T_WL condition T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("while_statement\n");
        }
    ;

/* FOR */
for_statement
    : T_FR T_ID T_IN expression T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent();
            printf("for_statement iterator=%s\n", symbol_table[$2]);
        }
    ;

/* FUNÇÃO */
function_def
    : T_FN T_ID T_LPAREN param_list_opt T_RPAREN T_NEWLINE
      T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("function_def id=%s\n", symbol_table[$2]);
        }
    ;

param_list_opt
    : /* vazio */
    | param_list
    ;

param_list
    : T_ID
        {
            print_indent(); printf("param: %s\n", symbol_table[$1]);
        }
    | param_list T_COMMA T_ID
        {
            print_indent(); printf("param: %s\n", symbol_table[$3]);
        }
    ;

/* CONDIÇÃO */
condition
    : expression relop expression
        {
            print_indent(); printf("condition\n");
        }
    ;

relop
    : T_EQ | T_NEQ | T_GT | T_LT | T_GTE | T_LTE
    ;

/* RETURN */
return_statement
    : T_R expression T_NEWLINE
        {
            print_indent(); printf("return_statement\n");
        }
    ;

%%

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
