%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/symbol_table.h"
#include "../intermediate_code/quadruple.h"
#include "../intermediate_code/utils.h"


void yyerror(const char *s);
int yylex();
int yywrap();

extern int line_num;

Scope* current_scope = NULL;
bool is_const_declaration = false;
char current_type[50];
char current_function[50] = "";
%}

%union {
    int num;
    float fnum;
    char* str;
}

%token <num> NUMBER
%token <fnum> FLOAT_NUM
%token <str> ID
%token <str> STR
%token <str> CHAR_LITERAL

%type <str> expr assign_expr conditional_expr logical_expr logical_or_expr
%type <str> logical_and_expr equality_expr relational_expr additive_expr
%type <str> multiplicative_expr unary_expr postfix_expr primary_expr function_call

%token IF ELSE WHILE FOR DO
%token SWITCH CASE DEFAULT BREAK CONTINUE
%token INT FLOAT DOUBLE CHAR VOID CONST

%token TRUE FALSE

%token PRINTFF SCANFF
%token RETURN INCLUDE

%token ASSIGN EQ NE LE GE GT LT
%token AND OR NOT

%token ADD SUBTRACT MULTIPLY DIVIDE
%token MODULO
%token UNARY
%token SEMI
%token UNARY_INC UNARY_DEC

%token NULL_TOKEN

%token LBRACE RBRACE
%token LPAREN RPAREN
%token LBRACKET RBRACKET
%token COMMA

%token COLON QUESTION

%token BIT_AND

%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program: 
    {
        current_scope = create_scope(NULL, SCOPE_GLOBAL);
    }
    translation_unit
    {
        check_unused_symbols(current_scope);
        print_symbol_table(current_scope);
    }
    ;

translation_unit:
      external_declaration
    | translation_unit external_declaration
    ;

external_declaration:
      function_definition
    | declaration SEMI
    | function_prototype
    | include_directive
    ;

include_directive:
    INCLUDE
    ;

function_prototype:
    function_header LPAREN parameter_list RPAREN SEMI
    | function_header LPAREN RPAREN SEMI
    ;

function_definition:
    function_header LPAREN parameter_list RPAREN compound_stmt
    | function_header LPAREN RPAREN compound_stmt
    ;

function_header:
    datatype ID
    {
        strncpy(current_function, $2, sizeof(current_function) - 1);
        insert_symbol_in_scope(current_scope, $2, current_type, SYM_FUNCTION, false, line_num);
    }
    ;


parameter_list:
    parameter_declaration
    | parameter_list COMMA parameter_declaration
    ;

parameter_declaration: 
    datatype ID
    {
        // Add parameter to symbol table
        insert_symbol_in_scope(current_scope, $2, current_type, SYM_PARAMETER, false, line_num);
        // Parameters are considered initialized
        mark_symbol_initialized(current_scope, $2);
    }
    | datatype MULTIPLY ID
    {
        // Add pointer parameter
        char pointer_type[50];
        snprintf(pointer_type, sizeof(pointer_type), "%s*", current_type);
        insert_symbol_in_scope(current_scope, $3, pointer_type, SYM_PARAMETER, false, line_num);
        mark_symbol_initialized(current_scope, $3);
    }
    | CONST datatype ID
    {
        // Add const parameter
        char const_type[50];
        snprintf(const_type, sizeof(const_type), "const %s", current_type);
        insert_symbol_in_scope(current_scope, $3, const_type, SYM_PARAMETER, true, line_num);
        mark_symbol_initialized(current_scope, $3);
    }
    | CONST datatype MULTIPLY ID
    {
        // Add const pointer parameter
        char const_pointer_type[50];
        snprintf(const_pointer_type, sizeof(const_pointer_type), "const %s*", current_type);
        insert_symbol_in_scope(current_scope, $4, const_pointer_type, SYM_PARAMETER, true, line_num);
        mark_symbol_initialized(current_scope, $4);
    }
    ;


compound_stmt: 
    LBRACE 
    {
        // Create a new scope for compound statement
        current_scope = enter_scope(current_scope, SCOPE_LOCAL);
    }
    stmt_list RBRACE
    {
        // Exit compound statement scope
        current_scope = exit_scope(current_scope);
    }
    ;

datatype: INT
    | FLOAT
    | CHAR
    | DOUBLE
    | VOID
    ;

stmt_list: /* empty */
    | stmt_list stmt
    ;

stmt: compound_stmt
    | if_stmt
    | for_stmt
    | while_stmt
    | do_while_stmt
    | switch_stmt
    | expr_stmt
    | decl_stmt
    | print_stmt
    | scan_stmt
    | return_stmt
    | break_stmt
    | continue_stmt
    ;

if_stmt: IF LPAREN expr RPAREN stmt %prec LOWER_THAN_ELSE
    | IF LPAREN expr RPAREN stmt ELSE stmt
    ;

for_stmt: 
    FOR LPAREN 
    {
        // Create a new scope for the for loop and its init statement
        current_scope = enter_scope(current_scope, SCOPE_LOCAL);
    }
    for_init SEMI for_cond SEMI for_update RPAREN stmt
    {
        // Exit the for loop scope
        print_symbol_table(current_scope);
        current_scope = exit_scope(current_scope);
    }
    ;

for_init: /* empty */
    | expr
    | declaration
    ;

for_cond: /* empty */
    | expr
    ;

for_update: /* empty */
    | expr
    ;

while_stmt: WHILE LPAREN expr RPAREN stmt
    ;

do_while_stmt: DO stmt WHILE LPAREN expr RPAREN SEMI
    ;

expr_stmt: expr SEMI
    ;

switch_stmt: SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE
    ;

case_list: /* empty */
    | case_list case_stmt
    | case_list default_stmt
    ;

case_stmt: CASE expr COLON stmt_list
    ;

default_stmt: DEFAULT COLON stmt_list
    ;

break_stmt: BREAK SEMI
    ;

continue_stmt: CONTINUE SEMI
    ;

decl_stmt: declaration SEMI
    ;

print_stmt: PRINTFF LPAREN STR print_args RPAREN SEMI
    ;

print_args: /* empty */
    | COMMA arg_list
    ;

arg_list: expr
    | arg_list COMMA expr
    ;

scan_stmt: SCANFF LPAREN STR COMMA BIT_AND ID RPAREN SEMI
    ;

expr: assign_expr
    ;

assign_expr: logical_expr
    | ID ASSIGN assign_expr
    {   
        //printf($1);
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            mark_symbol_used(current_scope, $1);
            mark_symbol_initialized(current_scope, $1);
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        $1, line_num);
            }
            //createQuadruple("=", $3, NULL, $1);
            $$ = $1;
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", $1, line_num);
        }
    }
    | MULTIPLY ID ASSIGN assign_expr
    {
        // Handle pointer dereference assignment
        Symbol* sym = lookup_symbol(current_scope, $2);
        if (sym) {
            mark_symbol_used(current_scope, $2);
            // Don't mark as initialized, since we're dereferencing
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        $2, line_num);
            }
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", $2, line_num);
        }
    }
    | ID ADD_ASSIGN assign_expr
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            mark_symbol_used(current_scope, $1);
            mark_symbol_initialized(current_scope, $1);
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        $1, line_num);
            }
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", $1, line_num);
        }
    }
    | ID SUB_ASSIGN assign_expr
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            mark_symbol_used(current_scope, $1);
            mark_symbol_initialized(current_scope, $1);
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        $1, line_num);
            }
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", $1, line_num);
        }
    }
    | ID MUL_ASSIGN assign_expr
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            mark_symbol_used(current_scope, $1);
            mark_symbol_initialized(current_scope, $1);
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        $1, line_num);
            }
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", $1, line_num);
        }
    }
    | ID DIV_ASSIGN assign_expr
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            mark_symbol_used(current_scope, $1);
            mark_symbol_initialized(current_scope, $1);
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        $1, line_num);
            }
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", $1, line_num);
        }
    }
    | ID MOD_ASSIGN assign_expr
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            mark_symbol_used(current_scope, $1);
            mark_symbol_initialized(current_scope, $1);
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        $1, line_num);
            }
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", $1, line_num);
        }
    }
    ;

conditional_expr: logical_or_expr
    | logical_or_expr QUESTION expr COLON conditional_expr
    ;

logical_expr: conditional_expr
    ;

logical_or_expr: logical_and_expr
    | logical_or_expr OR logical_and_expr
    ;

logical_and_expr: equality_expr
    | logical_and_expr AND equality_expr
    ;

equality_expr: relational_expr
    | equality_expr EQ relational_expr
    | equality_expr NE relational_expr
    ;

relational_expr: additive_expr
    | relational_expr LT additive_expr
    | relational_expr GT additive_expr
    | relational_expr LE additive_expr
    | relational_expr GE additive_expr
    ;

additive_expr: multiplicative_expr
    | additive_expr ADD multiplicative_expr
    | additive_expr SUBTRACT multiplicative_expr
    ;

multiplicative_expr: unary_expr
    | multiplicative_expr MULTIPLY unary_expr
    | multiplicative_expr DIVIDE unary_expr
    | multiplicative_expr MODULO unary_expr
    ;

unary_expr: postfix_expr
    { $$ = $1; }
    | UNARY unary_expr
    { $$ = $2; } // Propagate the value
    | SUBTRACT unary_expr
    { $$ = $2; } // Propagate the value
    | MULTIPLY unary_expr
    { $$ = $2; } // Propagate the value
    | NOT unary_expr
    { $$ = $2; } // Propagate the value
    | BIT_AND unary_expr
    { $$ = $2; } // Propagate the value
    ;

postfix_expr: primary_expr
    {
        $$ = $1;
    }
    | postfix_expr UNARY_INC
    {
        char* temp = nextTemp();
        Quadruple* assign_temp = createQuadruple(QuadOp_ASSIGN, strdup($1), NULL, temp);
        addQuadruple(assign_temp);

        Quadruple* increment = createQuadruple(QuadOp_ADD, strdup($1), strdup("1"), strdup($1));
        addQuadruple(increment);

        $$ = temp;
    }
    | postfix_expr UNARY_DEC
    {
        char* temp = nextTemp();
        Quadruple* assign_temp = createQuadruple(QuadOp_ASSIGN, strdup($1), NULL, temp);
        addQuadruple(assign_temp);

        Quadruple* decrement = createQuadruple(QuadOp_SUB, strdup($1), strdup("1"), strdup($1));
        addQuadruple(decrement);

        $$ = temp;
    }
    ;

primary_expr: ID
    { 
        printf("primary_expr: ID = %s\n", $1);
        // Mark the symbol as used when referenced
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            mark_symbol_used(current_scope, $1);
            
            // Also check if it's been initialized
            if (!sym->is_initialized) {
                fprintf(stderr, "Warning: Variable '%s' used before initialization at line %d\n", 
                        $1, line_num);
            }
            $$ = strdup($1); // Assign the identifier's name to $$
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", $1, line_num);
            $$ = strdup("0"); // Or some default value, like "0"
        }
    }
    | NUMBER
    {
        char* num_str = (char*)malloc(20);
        sprintf(num_str, "%d", $1);
        $$ = num_str;
    }
    | FLOAT_NUM
    {
        char* float_str = (char*)malloc(50);
        sprintf(float_str, "%f", $1);
        $$ = float_str;
    }
    | STR
    {
        $$ = strdup($1);
    }
    | CHAR_LITERAL
    {
        $$ = strdup($1);
    }
    | TRUE
    {
        $$ = strdup("1");
    }
    | FALSE
    {
        $$ = strdup("0");
    }
    | NULL_TOKEN
    {
        $$ = strdup("0");
    }
    | LPAREN expr RPAREN
    {
        $$ = $2;
    }
    | function_call
    {
        $$ = strdup($1);
    }
    ;

function_call: ID LPAREN RPAREN
    | ID LPAREN arg_list RPAREN
    ;

declaration: datatype declarator_list
    | CONST datatype const_declarator_list
    ;

const_declarator_list: const_declarator
    | const_declarator_list COMMA const_declarator
    ;

const_declarator:
    ID ASSIGN expr
    {
        printf("const_declarator: ID = %s, EXPR = %s\n", $1, $3);
        // Add const variable to symbol table and mark as initialized
        insert_symbol_in_scope(current_scope, $1, current_type, SYM_VARIABLE, true, line_num);
        mark_symbol_initialized(current_scope, $1);
        // Generate quadruple: ID = expr
        Quadruple* quad = createQuadruple(QuadOp_ASSIGN, $3, NULL, strdup($1));
        addQuadruple(quad);
    }
    | MULTIPLY ID ASSIGN expr
    {
        // Handle pointer dereference assignment
        // Generate quadruple: *ID = expr
        // ... (Implementation for pointer dereference assignment) ...
    }
    ;

declarator_list: declarator
    | declarator_list COMMA declarator
    ;

declarator:
    ID
    {
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            fprintf(stderr, "error: Variable '%s' is initialized before \n",
                        $1);
        } else {
            // Add variable to symbol table
            insert_symbol_in_scope(current_scope, $1, current_type, SYM_VARIABLE, is_const_declaration, line_num);
        }
    }
    | MULTIPLY declarator
    {
        // ... (Implementation for pointer declaration) ...
    }
    | ID ASSIGN expr
    {
        // Add variable to symbol table (if not already there)
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (!sym) {
            insert_symbol_in_scope(current_scope, $1, current_type, SYM_VARIABLE, is_const_declaration, line_num);
        }

        // Generate quadruple: ID = expr
        Quadruple* quad = createQuadruple(QuadOp_ASSIGN, $3, NULL, strdup($1));
        addQuadruple(quad);
    }
    | ID LBRACKET primary_expr RBRACKET
    | ID LBRACKET primary_expr RBRACKET ASSIGN expr
    ;

return_stmt: RETURN expr SEMI
    | RETURN SEMI
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", line_num, s);
}

int main() {
    printf("Parsing started...\n");
    int result = yyparse();
    if (result == 0) {
        printf("Parsing completed successfully.\n");
    }
    printQuadruples();
    return result;
}