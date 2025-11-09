/* ===========================================
   ANALISADOR SINTÁTICO - LINGUAGEM SLOTH
   =========================================== */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Protótipos */
int yylex(void);
void yyerror(const char *s);

/* Função auxiliar para imprimir árvore com indentação */
int indent_level = 0;
void print_indent() {
    for (int i = 0; i < indent_level; i++) printf("    ");
}
%}

/* ------------------------------------
   Seção de Declarações do Bison
   ------------------------------------ */

%union {
    char *id;
    double valor;
}

/* Tokens vindos do Flex */
%token T_FN T_IF T_EL T_EF T_FR T_WL T_R
%token T_I T_FL T_S
%token T_EQ T_NEQ T_GTE T_LTE T_GT T_LT
%token T_ASSIGN
%token T_PLUS T_MINUS T_MUL T_DIV T_MOD
%token T_AND T_OR
%token T_LPAREN T_RPAREN
%token T_LBRACKET T_RBRACKET
%token T_COMMA
%token T_FLOAT_NUM T_INT_NUM T_STRING
%token T_ID
%token T_NEWLINE T_INDENT T_DEDENT

%start program

%%

/* ========================
   REGRAS DA GRAMÁTICA
   ======================== */

/* PROGRAMA PRINCIPAL */
program
    : statement_list
        {
            printf("program\n");
            indent_level++;
            print_indent(); printf("statement_list\n");
            indent_level++;
        }
    ;

/* LISTA DE COMANDOS */
statement_list
    : statement
    | statement_list statement
    ;

/* COMANDO GENÉRICO */
statement
    : declaration
    | attribution
    | if_statement
    | while_statement
    | for_statement
    | function_def
    | return_statement
    ;

/* DECLARAÇÃO DE VARIÁVEL */
declaration
    : T_I T_ID T_NEWLINE
        {
            print_indent(); printf("declaration\n");
            indent_level++;
            print_indent(); printf("type: int\n");
            print_indent(); printf("id: %s\n", yytext);
            indent_level--;
        }
    | T_FL T_ID T_NEWLINE
        {
            print_indent(); printf("declaration\n");
            indent_level++;
            print_indent(); printf("type: float\n");
            print_indent(); printf("id: %s\n", yytext);
            indent_level--;
        }
    ;

/* ATRIBUIÇÃO */
attribution
    : T_ID T_ASSIGN expression T_NEWLINE
        {
            print_indent(); printf("attribution\n");
            indent_level++;
            print_indent(); printf("id: %s\n", yytext);
            print_indent(); printf("expression\n");
            indent_level--;
        }
    ;

/* EXPRESSÕES ARITMÉTICAS */
expression
    : expression T_PLUS term   { /* soma */ }
    | expression T_MINUS term  { /* sub */ }
    | term
    ;

term
    : term T_MUL factor        { /* mult */ }
    | term T_DIV factor        { /* div */ }
    | factor
    ;

factor
    : T_INT_NUM
    | T_FLOAT_NUM
    | T_ID
    | T_LPAREN expression T_RPAREN
    ;

/* CONDICIONAL IF/ELSE/ELIF */
if_statement
    : T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("if_statement\n");
            indent_level++;
            print_indent(); printf("condition\n");
            indent_level++;
            print_indent(); printf("(expressão booleana)\n");
            indent_level--;
            print_indent(); printf("then_block\n");
            indent_level++;
            print_indent(); printf("(statements)\n");
            indent_level -= 2;
        }
    | T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT T_EL T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("if_else_statement\n");
            indent_level++;
            print_indent(); printf("condition\n");
            indent_level++;
            print_indent(); printf("(expressão booleana)\n");
            indent_level--;
            print_indent(); printf("then_block\n");
            indent_level++;
            print_indent(); printf("(statements)\n");
            indent_level--;
            print_indent(); printf("else_block\n");
            indent_level++;
            print_indent(); printf("(statements)\n");
            indent_level -= 2;
        }
    ;

/* LAÇO WHILE */
while_statement
    : T_WL condition T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("while_statement\n");
            indent_level++;
            print_indent(); printf("condition\n");
            indent_level++;
            print_indent(); printf("(expressão booleana)\n");
            indent_level--;
            print_indent(); printf("body\n");
            indent_level++;
            print_indent(); printf("(statements)\n");
            indent_level -= 2;
        }
    ;

/* LAÇO FOR */
for_statement
    : T_FR T_ID T_IN expression T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("for_statement\n");
            indent_level++;
            print_indent(); printf("iterator: %s\n", yytext);
            print_indent(); printf("range_expression\n");
            indent_level++;
            print_indent(); printf("(expressão)\n");
            indent_level--;
            print_indent(); printf("body\n");
            indent_level++;
            print_indent(); printf("(statements)\n");
            indent_level -= 2;
        }
    ;

/* DEFINIÇÃO DE FUNÇÃO */
function_def
    : T_FN T_ID T_LPAREN param_list_opt T_RPAREN T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("function_def\n");
            indent_level++;
            print_indent(); printf("id: %s\n", yytext);
            print_indent(); printf("parameters\n");
            indent_level++;
            print_indent(); printf("(param_list)\n");
            indent_level--;
            print_indent(); printf("body\n");
            indent_level++;
            print_indent(); printf("(statements)\n");
            indent_level -= 2;
        }
    ;

param_list_opt
    : /* vazio */
    | param_list
    ;

param_list
    : T_ID
    | param_list T_COMMA T_ID
    ;

/* CONDIÇÃO (relacional) */
condition
    : expression relop expression
    ;

relop
    : T_EQ | T_NEQ | T_GT | T_LT | T_GTE | T_LTE
    ;

/* RETORNO DE FUNÇÃO */
return_statement
    : T_R expression T_NEWLINE
        {
            print_indent(); printf("return_statement\n");
            indent_level++;
            print_indent(); printf("expression\n");
            indent_level--;
        }
    ;

%%

/* ==============================
   SEÇÃO DE CÓDIGO DO USUÁRIO
   ============================== */

int main() {
    printf("=== Iniciando análise sintática da linguagem Sloth ===\n");
    return yyparse();
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
