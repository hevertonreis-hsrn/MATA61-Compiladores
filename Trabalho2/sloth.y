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

/* Funções/variáveis providas pelo scanner (sloth.l) */
extern char *symbol_table[];
extern int symbol_count;
extern void init_lexer(void);
extern FILE *yyin;

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
    int ival;      /* inteiros e índices de símbolo */
    double fval;   /* floats e valores de expressão */
    char *str;     /* strings literais */
}

/* Tokens vindos do Flex (com seus atributos) */
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

/* não-terminais com tipo */
%type <fval> expression term factor

%start program

%%

/* ========================
   REGRAS DA GRAMÁTICA
   ======================== */

/* PROGRAMA PRINCIPAL */
program
    : statement_list
        {
            /* Cabeçalho da árvore */
            printf("program\n");
            indent_level++;
            print_indent(); printf("statement_list\n");
            /* statement_list já imprimirá seus statements com base no indent_level atual */
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

/* DECLARAÇÃO DE VARIÁVEL (tipo e nome) */
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

/* ATRIBUIÇÃO (variável simples) */
attribution
    : T_ID T_ASSIGN expression T_NEWLINE
        {
            print_indent(); printf("attribution\n");
            indent_level++;
            print_indent(); printf("id: %s\n", symbol_table[$1]);
            print_indent(); printf("expression\n");
            indent_level++;
            print_indent(); printf("value: %f\n", $3);
            indent_level -= 2;
        }
    ;

/* EXPRESSÕES ARITMÉTICAS (avalia o valor numérico para uso em prints) */
expression
    : expression T_PLUS term   { $$ = $1 + $3; }
    | expression T_MINUS term  { $$ = $1 - $3; }
    | term                     { $$ = $1; }
    ;

term
    : term T_MUL factor        { $$ = $1 * $3; }
    | term T_DIV factor        {
                                   if ($3 == 0.0) {
                                       yyerror("Divisao por zero (avaliacao de expressao)"); $$ = 0.0;
                                   } else $$ = $1 / $3;
                               }
    | factor                   { $$ = $1; }
    ;

factor
    : T_INT_NUM                { $$ = (double)$1; }
    | T_FLOAT_NUM              { $$ = $1; }
    | T_ID                     {
                                  /* variável: não avaliamos valor (ainda), colocamos 0.0
                                     mas imprimimos a referência se desejado quando reduzido em contextos */
                                  $$ = 0.0;
                              }
    | T_LPAREN expression T_RPAREN { $$ = $2; }
    ;

/* CONDICIONAL IF / IF-ELSE */
if_statement
    : T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("if_statement\n");
            indent_level++;
            print_indent(); printf("condition\n");
            indent_level++;
            /* imprimimos forma simplificada da condição (a árvore detalhada pode ser expandida) */
            print_indent(); printf("(relational expression)\n");
            indent_level -= 2;
            print_indent(); printf("then_block\n");
            indent_level++;
            /* statements inside then_block were printed by statement_list */
            indent_level--;
        }
    | T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT T_EL T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("if_else_statement\n");
            indent_level++;
            print_indent(); printf("condition\n");
            indent_level++;
            print_indent(); printf("(relational expression)\n");
            indent_level -= 2;
            print_indent(); printf("then_block\n");
            indent_level++;
            /* then statements printed by nested statement_list */
            indent_level--;
            print_indent(); printf("else_block\n");
            indent_level++;
            /* else statements printed by nested statement_list */
            indent_level--;
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
            print_indent(); printf("(relational expression)\n");
            indent_level -= 2;
            print_indent(); printf("body\n");
            indent_level++;
            /* body statements printed by statement_list */
            indent_level--;
        }
    ;

/* LAÇO FOR (FR <id> IN expression NEWLINE INDENT body DEDENT) */
for_statement
    : T_FR T_ID T_IN expression T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("for_statement\n");
            indent_level++;
            print_indent(); printf("iterator: %s\n", symbol_table[$2]);
            print_indent(); printf("range_expression\n");
            indent_level++;
            print_indent(); printf("(expression)\n");
            indent_level -= 1;
            print_indent(); printf("body\n");
            indent_level++;
            /* body printed by statement_list */
            indent_level--;
        }
    ;

/* DEFINIÇÃO DE FUNÇÃO */
function_def
    : T_FN T_ID T_LPAREN param_list_opt T_RPAREN T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            print_indent(); printf("function_def\n");
            indent_level++;
            print_indent(); printf("id: %s\n", symbol_table[$2]);
            print_indent(); printf("parameters\n");
            indent_level++;
            print_indent(); printf("(param_list)\n");
            indent_level--;
            print_indent(); printf("body\n");
            indent_level++;
            /* body printed by statement_list */
            indent_level--;
            indent_level--;
        }
    ;

/* parâmetros opcionais */
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

/* CONDIÇÃO (relacional simples) */
condition
    : expression relop expression
    {
        /* imprime estrutura simplificada da condição */
        print_indent(); printf("condition\n");
        indent_level++;
        print_indent(); printf("left_expr (computed?)\n");
        print_indent(); printf("relop\n");
        indent_level++;
        print_indent(); /* print symbol of relop */
        printf("(relop)\n");
        indent_level--;
        print_indent(); printf("right_expr (computed?)\n");
        indent_level--;
    }
    ;

/* operadores relacionais */
relop
    : T_EQ
    | T_NEQ
    | T_GT
    | T_LT
    | T_GTE
    | T_LTE
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

int main(int argc, char **argv) {
    FILE *infile = NULL;
    if (argc > 1) {
        infile = fopen(argv[1], "r");
        if (!infile) {
            fprintf(stderr, "Erro ao abrir arquivo '%s'\n", argv[1]);
            return 1;
        }
        yyin = infile;
    }

    /* Inicializa o lexer (pilha de indentação, etc.) */
    init_lexer();

    printf("=== Iniciando análise sintática da linguagem Sloth ===\n");
    int res = yyparse();

    /* libera tabela de símbolos alocada pelo lexer */
    for (int i = 0; i < symbol_count; i++) {
        free(symbol_table[i]);
    }

    if (infile) fclose(infile);
    return res;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}
