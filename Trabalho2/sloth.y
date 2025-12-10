/* ===========================================
   ANALISADOR SINTÁTICO - LINGUAGEM SLOTH
   Gera Árvore Sintática (AST)
   =========================================== */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//#define YYDEBUG 1
//int yydebug = 1;

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

%}

/* ------------------------------------
   Seção de Declarações do Bison
   ------------------------------------ */

%union {
    int ival;
    double fval;
    char *str;
    struct ASTNode *node; /* Novo tipo para carregar nós da árvore */
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

/* Agora todos os não-terminais retornam um NÓ DA ÁRVORE */
%type <node> program statement_list statement declaration attribution 
%type <node> if_statement elif_blocks elif_block while_statement for_statement
%type <node> function_def param_list_opt param_list typed_param
%type <node> return_statement print_statement iterable
%type <node> expression term factor cmp condition list_literal list_elements_opt list_elements relop arg_list_opt arg_list

%type <node> logical_expression
%type <node> logical_term
%type <node> logical_factor

%start program

/* Precedência */
%nonassoc T_EL T_EF
%left T_OR
%left T_AND
%nonassoc T_EQ T_NEQ T_GT T_LT T_GTE T_LTE 
%left T_PLUS T_MINUS  
%left T_MUL T_DIV T_MOD 

%%

/* ========================
   REGRAS DA GRAMÁTICA
   ======================== */

program
    : statement_list
        {
            $$ = create_node("program", NULL, 1, $1);
            root = $$; /* Salva na raiz global para imprimir no main */
        }
    ;

statement_list
    : statement
        {
            $$ = create_node("statement_list", NULL, 1, $1);
        }
    | statement_list statement
        {
            /* Cria um nó lista que agrupa o anterior e o novo */
            $$ = create_node("statement_list", NULL, 2, $1, $2);
        }
    ;

statement
    : declaration       { $$ = create_node("statement", NULL, 1, $1); }
    | attribution       { $$ = create_node("statement", NULL, 1, $1); }
    | if_statement      { $$ = create_node("statement", NULL, 1, $1); }
    | while_statement   { $$ = create_node("statement", NULL, 1, $1); }
    | for_statement     { $$ = create_node("statement", NULL, 1, $1); }
    | function_def      { $$ = create_node("statement", NULL, 1, $1); }
    | return_statement  { $$ = create_node("statement", NULL, 1, $1); }
    | print_statement   { $$ = create_node("statement", NULL, 1, $1); }
    | T_NEWLINE         { $$ = NULL; /* Ignora linhas vazias na árvore ou retorna nó vazio */ }
    ;

/* ========================
   DECLARAÇÃO
   ======================== */

declaration
    : T_I T_ID T_NEWLINE
        {
            $$ = create_node("declaration", NULL, 2, 
                    create_node("INT", NULL, 0),
                    create_node(symbol_table[$2], NULL, 0));
        }
    | T_FL T_ID T_NEWLINE
        {
            $$ = create_node("declaration", NULL, 2, 
                    create_node("FLOAT", NULL, 0),
                    create_node(symbol_table[$2], NULL, 0));
        }
    | T_S T_ID T_NEWLINE
        {
            $$ = create_node("declaration", NULL, 2, 
                    create_node("STRING", NULL, 0),
                    create_node(symbol_table[$2], NULL, 0));
        }
    /* Declaração com inicialização */
    | T_I T_ID T_ASSIGN expression T_NEWLINE
        {
            $$ = create_node("declaration", NULL, 3, 
                    create_node("INT", NULL, 0),
                    create_node(symbol_table[$2], NULL, 0),
                    $4);
        }
    | T_I T_ID T_ASSIGN list_literal T_NEWLINE
        {
            $$ = create_node("declaration_list", NULL, 3, 
                    create_node("INT_LIST", NULL, 0),
                    create_node(symbol_table[$2], NULL, 0),
                    $4);
        }
    | T_FL T_ID T_ASSIGN expression T_NEWLINE 
        {
            $$ = create_node("declaration_init", NULL, 3, 
                    create_node("FLOAT", NULL, 0),
                    create_node(symbol_table[$2], NULL, 0),
                    $4);
        }
    | T_S T_ID T_ASSIGN T_STRING T_NEWLINE
        {
            $$ = create_node("declaration_init_string", NULL, 3, 
                    create_node("STRING", NULL, 0),
                    create_node(symbol_table[$2], NULL, 0),
                    create_node("string_literal", $4, 0)
                );
        }
    ;

/* ========================
   ATRIBUIÇÃO
   ======================== */

attribution
    : T_ID T_ASSIGN expression T_NEWLINE
        {
            $$ = create_node("attribution", NULL, 2,
                    create_node(symbol_table[$1], NULL, 0),
                    $3);
        }
    | T_ID T_ASSIGN T_STRING T_NEWLINE
        {
            $$ = create_node("attribution", NULL, 2,
                    create_node(symbol_table[$1], NULL, 0),
                    create_node("string_literal", $3, 0));
        }
    | T_ID T_ASSIGN list_literal T_NEWLINE
        {
             $$ = create_node("attribution_list", NULL, 2,
                    create_node(symbol_table[$1], NULL, 0),
                    $3);
        }
    ;

/* ========================
   PRINT
   ======================== */

print_statement
    : T_PT T_STRING T_NEWLINE
        {
             $$ = create_node("print_statement", NULL, 1, create_node("string", $2, 0));
        }
    | T_PT expression T_NEWLINE
        {
             $$ = create_node("print_statement", NULL, 1, $2);
        }
    ;

/* ========================
   FUNÇÕES
   ======================== */

function_def
    : T_FN T_ID T_LPAREN param_list_opt T_RPAREN T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            $$ = create_node("function_def", NULL, 4,
                    create_node("FN", NULL, 0),
                    create_node("id", symbol_table[$2], 0),
                    $4, /* param_list */
                    $8  /* body */
            );
        }
    ;

param_list_opt
    : /* vazio */   { $$ = create_node("parameter_list", "empty", 0); }
    | param_list    { $$ = $1; }
    ;

param_list
    : typed_param
        { $$ = create_node("parameter_list", NULL, 1, $1); }
    | param_list T_COMMA typed_param
        { $$ = create_node("parameter_list", NULL, 2, $1, $3); }
    ;

typed_param
    : T_I T_ID  { $$ = create_node("param", NULL, 2, create_node("INT", NULL, 0), create_node(symbol_table[$2], NULL, 0)); }
    | T_FL T_ID { $$ = create_node("param", NULL, 2, create_node("FLOAT", NULL, 0), create_node(symbol_table[$2], NULL, 0)); }
    | T_S T_ID  { $$ = create_node("param", NULL, 2, create_node("STRING", NULL, 0), create_node(symbol_table[$2], NULL, 0)); }
    ;

/* ========================
   IF / ELSE
   ======================== */

if_statement
    : T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            $$ = create_node("if_statement", NULL, 2, $2, $5);
        }
    /* RECONEXÃO: IF com ELIF e ELSE */
    | T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT elif_blocks T_EL T_NEWLINE T_INDENT statement_list T_DEDENT
        {
             $$ = create_node("if_elif_else", NULL, 4, $2, $5, $7, $11);
        }
    | T_IF condition T_NEWLINE T_INDENT statement_list T_DEDENT T_EL T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            $$ = create_node("if_else_statement", NULL, 3, $2, $5, $10);
        }
    ;

elif_blocks
    : elif_block 
        { $$ = $1; }
    | elif_blocks elif_block 
        { $$ = create_node("elif_list", NULL, 2, $1, $2); }
    ;

elif_block
    : T_EF condition T_NEWLINE T_INDENT statement_list T_DEDENT 
        { $$ = create_node("elif_block", NULL, 2, $2, $5); }
    ;

/* ========================
   EXPRESSÕES (CONVERSÃO DE VALOR PARA NÓ)
   ======================== */

expression
    : expression T_PLUS term  { $$ = create_node("expr", "+", 2, $1, $3); }
    | expression T_MINUS term { $$ = create_node("expr", "-", 2, $1, $3); }
    | term                    { $$ = $1; }
    ;

term
    : term T_MUL factor       { $$ = create_node("term", "*", 2, $1, $3); }
    | term T_DIV factor       { $$ = create_node("term", "/", 2, $1, $3); }
    | term T_MOD factor       { $$ = create_node("term", "%", 2, $1, $3); }
    | factor                  { $$ = $1; }
    ;

factor
    : T_INT_NUM               
        { 
            char buffer[20]; sprintf(buffer, "%d", $1);
            $$ = create_node("int", buffer, 0); 
        }
    | T_FLOAT_NUM             
        { 
            char buffer[20]; sprintf(buffer, "%.2f", $1);
            $$ = create_node("float", buffer, 0); 
        }
    | T_ID                    
        { $$ = create_node("id", symbol_table[$1], 0); }
    | T_LPAREN expression T_RPAREN 
        { $$ = $2; }
    /* RECONEXÃO: Chamada de função */
    | T_ID T_LPAREN arg_list_opt T_RPAREN
        {
            /* Se arg_list_opt for NULL, passamos 0 filhos para evitar erro, ou tratamos na create_node */
            if ($3 == NULL)
                $$ = create_node("function_call", symbol_table[$1], 0);
            else
                $$ = create_node("function_call", symbol_table[$1], 1, $3);
        }
    ;

condition
    : logical_expression
        { $$ = $1; }
    ;

logical_expression
    : logical_expression T_OR logical_term
        { $$ = create_node("LOGIC_OR", "OR", 2, $1, $3); }
    | logical_term
        { $$ = $1; }
    ;

logical_term
    : logical_term T_AND logical_factor
        { $$ = create_node("LOGIC_AND", "AND", 2, $1, $3); }
    | logical_factor
        { $$ = $1; }
    ;

logical_factor
    : cmp
        { $$ = $1; } // Comparação relacional (ex: soma > 15)
    | expression // Uma expression (que pode ser T_T, T_F, ou chamada_de_funcao())
        { $$ = $1; }
    ;

cmp
    : expression relop expression
    {
        $$ = create_node("comparison", NULL, 3, $1, $2, $3);
    }
    ;

relop
    : T_EQ  { $$ = create_node("relop", "==", 0); }
    | T_NEQ { $$ = create_node("relop", "!=", 0); }
    | T_GT  { $$ = create_node("relop", ">", 0); }
    | T_LT  { $$ = create_node("relop", "<", 0); }
    | T_GTE { $$ = create_node("relop", ">=", 0); }
    | T_LTE { $$ = create_node("relop", "<=", 0); }
    ;

/* ========================
   RETURN
   ======================== */

return_statement
    : T_R expression T_NEWLINE
        {
            $$ = create_node("return_statement", NULL, 2, create_node("R", NULL, 0), $2);
        }
    | T_R T_STRING T_NEWLINE
        {
            $$ = create_node("return_statement", NULL, 2, create_node("R", NULL, 0), create_node("string", $2, 0));
        }
    | T_R T_T T_NEWLINE 
        { 
            $$ = create_node("return_boolean", NULL, 2, create_node("R", NULL, 0), create_node("TRUE", NULL, 0));
        }
    
    | T_R T_F T_NEWLINE 
        { 
            $$ = create_node("return_boolean", NULL, 2, create_node("R", NULL, 0), create_node("FALSE", NULL, 0));
        }
    ;

/* Regras vazias para completar a compilação (simplificadas para o exemplo) */
while_statement: T_WL condition T_NEWLINE T_INDENT statement_list T_DEDENT { $$ = create_node("while", NULL, 2, $2, $5); };
for_statement
    : T_FR T_ID T_IN iterable T_NEWLINE T_INDENT statement_list T_DEDENT
        {
            $$ = create_node("for_statement", symbol_table[$2], 3, create_node("IN", NULL, 0), $4, $7);
        }
    ;

iterable
    : expression    { $$ = $1; }
    | list_literal  { $$ = $1; } /* Reconecta a lista ao for loop */
    ;
    
list_literal
    : T_LBRACKET list_elements_opt T_RBRACKET 
        { $$ = create_node("list_literal", NULL, 1, $2); }
    ;

list_elements_opt
    : /* vazio */    { $$ = NULL; }
    | list_elements  { $$ = $1; }
    ;

list_elements
    : expression 
        { $$ = create_node("list_item", NULL, 1, $1); }
    | list_elements T_COMMA expression
        { $$ = create_node("list_item", NULL, 2, $1, $3); }
    ;

arg_list_opt
    : /* vazio */ { $$ = NULL; }
    | arg_list    { $$ = $1; }
    ;

arg_list
    : expression 
        { $$ = create_node("arg", NULL, 1, $1); }
    | arg_list T_COMMA expression
        { $$ = create_node("arg", NULL, 2, $1, $3); }
    ;

%%

/* ==============================
   CÓDIGO FINAL
   ============================== */

int main(int argc, char **argv) {
    //yydebug = 1;

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