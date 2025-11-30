/* ===========================================
   ANALISADOR SINTÁTICO - LINGUAGEM SLOTH
   =========================================== */

%{
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
%token T_T T_F T_PT

/* Tipos de não-terminais */
%type <fval> expression term factor cmp

%start program

/* Precedência (da menor para maior) */
%nonassoc T_EL T_EF /* evita conflitos de else/elseif */
/* Operadores Lógicos (menor precedência) */
%left T_OR
%left T_AND
/* Operadores Relacionais */
%nonassoc T_EQ T_NEQ T_GT T_LT T_GTE T_LTE 
/* Operadores Aritméticos */
%left T_PLUS T_MINUS  
%left T_MUL T_DIV T_MOD /* maior precedência de op. binários */

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
    | print_statement       /* <-- adiciona print */
    | empty_line            /* <-- permite linhas vazias */
    ;

/* NEW: linha vazia */
empty_line
    : T_NEWLINE
    ;

/* ========================
   DECLARAÇÃO
   ======================== */

declaration
    : T_I  T_ID T_NEWLINE   /* Declaração simples */
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
    | T_S T_ID T_NEWLINE
        {
            print_indent(); printf("declaration\n");
            indent_level++;
            print_indent(); printf("type: string\n");
            print_indent(); printf("id: %s\n", symbol_table[$2]);
            indent_level--;
        }
    | T_I  T_ID T_ASSIGN expression T_NEWLINE   /* Declaração com inicialização numérica */
        {
            print_indent(); printf("declaration_with_init\n");
            indent_level++;
            print_indent(); printf("type: int\n");
            print_indent(); printf("id: %s\n", symbol_table[$2]);
            print_indent(); printf("initial value: %f\n", $4);
            indent_level--;
        }
    | T_FL T_ID T_ASSIGN expression T_NEWLINE
        {
            print_indent(); printf("declaration_with_init\n");
            indent_level++;
            print_indent(); printf("type: float\n");
            print_indent(); printf("id: %s\n", symbol_table[$2]);
            print_indent(); printf("initial value: %f\n", $4);
            indent_level--;
        }
    | T_I  T_ID T_ASSIGN list_literal T_NEWLINE     /* Declaração de lista */
        {
            print_indent(); printf("declaration_with_list\n");
            indent_level++;
            print_indent(); printf("type: int list\n");
            print_indent(); printf("id: %s\n", symbol_table[$2]);
            indent_level--;
        }
    | T_FL T_ID T_ASSIGN list_literal T_NEWLINE
        {
            print_indent(); printf("declaration_with_list\n");
            indent_level++;
            print_indent(); printf("type: float list\n");
            print_indent(); printf("id: %s\n", symbol_table[$2]);
            indent_level--;
        }
    | T_S T_ID T_ASSIGN T_STRING T_NEWLINE   /* Declaração de string com inicialização */
        {
            print_indent(); printf("declaration_with_init\n");
            indent_level++;
            print_indent(); printf("type: string\n");
            print_indent(); printf("id: %s\n", symbol_table[$2]);
            print_indent(); printf("initial value: %s\n", $4);
            indent_level--;
        }
    ;

/* ========================
   ATRIBUIÇÃO
   ======================== */

attribution
    : T_ID T_ASSIGN expression T_NEWLINE
        {
            print_indent(); printf("attribution\n");
            indent_level++;
            print_indent(); printf("id: %s\n", symbol_table[$1]);
            print_indent(); printf("expression value: %f\n", $3);
            indent_level--;
        }
    | T_ID T_ASSIGN list_literal T_NEWLINE
        {
            print_indent(); printf("attribution (list)\n");
            indent_level++;
            print_indent(); printf("id: %s\n", symbol_table[$1]);
            indent_level--;
        }
    | T_ID T_ASSIGN T_STRING T_NEWLINE
        {
            print_indent(); printf("attribution (string)\n");
            indent_level++;
            print_indent(); printf("id: %s\n", symbol_table[$1]);
            print_indent(); printf("expression value: %s\n", $3);
            indent_level--;
        }
    ;

/* ========================
   PRINT
   ======================== */

print_statement
    : T_PT T_STRING T_NEWLINE
        {
            print_indent(); printf("print_statement\n");
            indent_level++;
            print_indent(); printf("string: %s\n", $2);
            indent_level--;
        }
    | T_PT expression T_NEWLINE
        {
            print_indent(); printf("print_expression\n");
            indent_level++;
            print_indent(); printf("expression value: %f\n", $2);
            indent_level--;
        }
    ;

/* ========================
   LISTAS
   ======================== */

list_literal
    : T_LBRACKET list_elements_opt T_RBRACKET { print_indent(); printf("list_literal\n");}
    ;

list_elements_opt
    : /* vazio */
    | list_elements
    ;

list_elements
    : expression
    | list_elements T_COMMA expression
    ;

/* ========================
   EXPRESSÕES
   ======================== */

expression
    : expression T_PLUS term      { $$ = $1 + $3; }
    | expression T_MINUS term     { $$ = $1 - $3; }
    | term                        { $$ = $1; }
    ;

/* manter term e factor como antes */
term
    : term T_MUL factor           { $$ = $1 * $3; }
    | term T_DIV factor
        {
          if ($3 == 0.0)
              yyerror("Divisão por zero");
          $$ = $1 / $3;
        }
    | term T_MOD factor
        {
          if ($3 == 0.0)
              yyerror("Módulo por zero");
          $$ = fmod($1, $3);
        }
    | factor                      { $$ = $1; }
    ;

factor
    : T_INT_NUM                   { $$ = (double)$1; }
    | T_FLOAT_NUM                 { $$ = $1; }
    | T_ID                        { $$ = 0.0; }
    | T_LPAREN expression T_RPAREN { $$ = $2; }
    | T_ID T_LPAREN arg_list_opt T_RPAREN
        {
            print_indent();
            printf("function_call id=%s\n", symbol_table[$1]);
            $$ = 0.0;
        }
    ;

cmp
    : expression relop expression
        {
            print_indent(); printf("cmp\n");
            $$ = 0.0;
        }
    ;

arg_list_opt
    : /* vazio */
    | arg_list
    ;

arg_list
    : expression
    | arg_list T_COMMA expression
    ;

/* ========================
   IF
   ======================== */

if_statement
    : T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("if_statement\n");
        }
    | T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT
      elif_blocks
        {
            print_indent(); printf("if_elif_statement\n");
        }
    | T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT
      elif_blocks
      T_EL T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("if_elif_else_statement\n");
        }
    | T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT
      T_EL T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("if_else_statement\n");
        }
    ;

elif_blocks
    : elif_block
    | elif_blocks elif_block
    ;

elif_block
    : T_EF condition T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("elif_block\n");
        }
    ;

/* ========================
   WHILE
   ======================== */

while_statement
    : T_WL condition T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("while_statement\n");
        }
    ;

/* ========================
   FOR
   ======================== */

for_statement
    : T_FR T_ID T_IN iterable T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent();
            printf("for_statement iterator=%s\n", symbol_table[$2]);
        }
    ;

iterable
    : expression
    | list_literal
    ;

/* ========================
   FUNÇÕES
   ======================== */

function_def
    : T_FN T_ID T_LPAREN param_list_opt T_RPAREN T_NEWLINE
      T_INDENT statement_list T_DEDENT { print_indent(); printf("function_def id=%s\n", symbol_table[$2]);}
    ;

param_list_opt
    : /* vazio */
    | param_list
    ;

param_list
    : typed_param
    | param_list T_COMMA typed_param
    ;

typed_param
    : T_I  T_ID   { print_indent(); printf("param: %s %s\n", "I",  symbol_table[$2]); }
    | T_FL T_ID   { print_indent(); printf("param: %s %s\n", "FL", symbol_table[$2]); }
    | T_S  T_ID   { print_indent(); printf("param: %s %s\n", "S",  symbol_table[$2]); }
    ;

/* ========================
   CONDIÇÃO
   ======================== */

condition
    : condition T_OR condition       { print_indent(); printf("condition OR\n"); }
    | condition T_AND condition      { print_indent(); printf("condition AND\n"); }
    | cmp                            { print_indent(); printf("condition (cmp)\n"); }
    | expression                     { print_indent(); printf("condition (expr)\n"); }
    ;

relop
    : T_EQ | T_NEQ | T_GT | T_LT | T_GTE | T_LTE
    ;

/* ========================
   RETURN
   ======================== */

return_statement
    : T_R expression T_NEWLINE { print_indent(); printf("return_statement\n"); }
    | T_R T_STRING T_NEWLINE { print_indent(); printf("return_statement (string)\n");}
    | T_R T_T T_NEWLINE { print_indent(); printf("return_statement (True)\n");}
    | T_R T_F T_NEWLINE { print_indent(); printf("return_statement (False)\n");}
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
