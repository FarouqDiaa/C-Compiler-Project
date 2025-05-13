%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/symbol_table.h"
#include "../intermediate_code/quadruple.h"
#include "../intermediate_code/utils.h"
#include "../include/semantic_analyzer.h" 



void yyerror(const char *s);
int yylex();
int yywrap();

extern int line_num;

Scope* current_scope = NULL;
bool is_const_declaration = false;
char current_type[50];
char current_function[50] = "";
int has_return_stmt = 0;
int is_number(const char* s) {
    if (!s) return 0;
    for (int i = 0; s[i]; ++i)
        if (!isdigit(s[i])) return 0;
    return 1;
}
int is_float(const char* s) {
    if (!s) return 0;
    int dot = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '.') {
            if (dot) return 0;
            dot = 1;
        } else if (!isdigit(s[i])) return 0;
    }
    return dot;
}
%}

%union {
    int num;
    float fnum;
    char* str;
}

%token <num> NUMBER
%token <fnum> FLOAT_NUM
%token BOOL
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
    {
        Symbol* func_sym = lookup_symbol(current_scope, current_function);
        if (func_sym && strcmp(func_sym->type, "void") != 0 && has_return_stmt == 0) {
            fprintf(stderr, "Error: Non-void function '%s' is missing a return statement\n",
                current_function);
        }
        has_return_stmt = 0; // Reset for next function
    }
    | function_header LPAREN RPAREN compound_stmt
    {
        Symbol* func_sym = lookup_symbol(current_scope, current_function);
        if (func_sym && strcmp(func_sym->type, "void") != 0 && has_return_stmt == 0) {
            fprintf(stderr, "Error: Non-void function '%s' is missing a return statement\n",
                current_function);
        }
        has_return_stmt = 0; // Reset for next function
    }
    ;

function_header:
    datatype ID
    {
        strncpy(current_function, $2, sizeof(current_function) - 1);
        // Check for duplicate function
        Symbol* sym = lookup_symbol(current_scope, $2);
        if (sym) {
            fprintf(stderr, "Error: Function '%s' already declared at line %d\n", $2, line_num);
        } else {
            insert_symbol_in_scope(current_scope, $2, current_type, SYM_FUNCTION, false, line_num);
        }
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
        Symbol* sym = lookup_symbol(current_scope, $2);
        if (sym) {
            fprintf(stderr, "Error: Parameter '%s' already declared at line %d\n", $2, line_num);
        } else {
            insert_symbol_in_scope(current_scope, $2, current_type, SYM_PARAMETER, false, line_num);
            mark_symbol_initialized(current_scope, $2);
        }
    }
    | datatype MULTIPLY ID
    {
        char pointer_type[50];
        snprintf(pointer_type, sizeof(pointer_type), "%s*", current_type);
        Symbol* sym = lookup_symbol(current_scope, $3);
        if (sym) {
            fprintf(stderr, "Error: Parameter '%s' already declared at line %d\n", $3, line_num);
        } else {
            insert_symbol_in_scope(current_scope, $3, pointer_type, SYM_PARAMETER, false, line_num);
            mark_symbol_initialized(current_scope, $3);
        }
    }
    | CONST datatype ID
    {
        char const_type[50];
        snprintf(const_type, sizeof(const_type), "const %s", current_type);
        Symbol* sym = lookup_symbol(current_scope, $3);
        if (sym) {
            fprintf(stderr, "Error: Parameter '%s' already declared at line %d\n", $3, line_num);
        } else {
            insert_symbol_in_scope(current_scope, $3, const_type, SYM_PARAMETER, true, line_num);
            mark_symbol_initialized(current_scope, $3);
        }
    }
    | CONST datatype MULTIPLY ID
    {
        char const_pointer_type[50];
        snprintf(const_pointer_type, sizeof(const_pointer_type), "const %s*", current_type);
        Symbol* sym = lookup_symbol(current_scope, $4);
        if (sym) {
            fprintf(stderr, "Error: Parameter '%s' already declared at line %d\n", $4, line_num);
        } else {
            insert_symbol_in_scope(current_scope, $4, const_pointer_type, SYM_PARAMETER, true, line_num);
            mark_symbol_initialized(current_scope, $4);
        }
    }
    ;


compound_stmt: 
    LBRACE 
    {
        current_scope = enter_scope(current_scope, SCOPE_LOCAL);
        current_scope->return_count = 0; // Reset return count for new scope
    }
    stmt_list RBRACE
    {
        current_scope = exit_scope(current_scope);
    }
    ;

datatype: INT   { strcpy(current_type, "int"); }
    | FLOAT     { strcpy(current_type, "float"); }
    | CHAR      { strcpy(current_type, "char"); }
    | DOUBLE    { strcpy(current_type, "double"); }
    | VOID      { strcpy(current_type, "void"); }
    | BOOL      { strcpy(current_type, "bool"); }
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
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            // Type compatibility check
            const char* left_type = sym->type;
            const char* right_type = NULL;
            Symbol* right_sym = lookup_symbol(current_scope, $3);

            // Detect if $3 is a literal (number, char, etc.)
            if (right_sym) {
                right_type = right_sym->type;
            } else if ($3 && strlen($3) == 3 && $3[0] == '\'' && $3[2] == '\'') {
                // It's a char literal like 'c'
                right_type = "char";
            } else if (is_number($3)) {
                right_type = "int";
            } else if (is_float($3)) {
                right_type = "float";
            } else {
                right_type = current_type; // fallback, but not ideal
            }

            if (!check_type_compatibility(left_type, right_type)) {
                fprintf(stderr, "Error: Type mismatch in assignment to '%s' at line %d ('%s' = '%s')\n",
                        $1, line_num, left_type, right_type);
            }
            mark_symbol_used(current_scope, $1);
            mark_symbol_initialized(current_scope, $1);
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        $1, line_num);
            }
            char* temp = nextTemp();
            Quadruple* quad = createQuadruple(QuadOp_ASSIGN, $3, NULL, temp);
            addQuadruple(quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup($1));
            addQuadruple(assign);
            $$ = strdup($1);
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
            char* temp = nextTemp();
            Quadruple* quad = createQuadruple(QuadOp_ASSIGN, $4, NULL, temp);
            addQuadruple(quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup($2));
            addQuadruple(assign);
            $$ = strdup($2);

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
            char* temp = nextTemp();
            Quadruple* add_quad = createQuadruple(QuadOp_ADD, strdup($1), strdup($3), temp);
            addQuadruple(add_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup($1));
            addQuadruple(assign);
            $$ = strdup($1);

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
            char* temp = nextTemp();
            Quadruple* sub_quad = createQuadruple(QuadOp_SUB, strdup($1), strdup($3), temp);
            addQuadruple(sub_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup($1));
            addQuadruple(assign);
            $$ = strdup($1);

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
            char* temp = nextTemp();
            Quadruple* mul_quad = createQuadruple(QuadOp_MUL, strdup($1), strdup($3), temp);
            addQuadruple(mul_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup($1));
            addQuadruple(assign);
            $$ = strdup($1);

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
            char* temp = nextTemp();
            Quadruple* div_quad = createQuadruple(QuadOp_DIV, strdup($1), strdup($3), temp);
            addQuadruple(div_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup($1));
            addQuadruple(assign);
            $$ = strdup($1);

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
            char* temp = nextTemp();
            Quadruple* mod_quad = createQuadruple(QuadOp_MOD, strdup($1), strdup($3), temp);
            addQuadruple(mod_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup($1));
            addQuadruple(assign);
            $$ = strdup($1);

        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", $1, line_num);
        }
    }
    ;

conditional_expr: logical_or_expr
    | logical_or_expr QUESTION expr COLON conditional_expr
    {
        char* temp = nextTemp();
        char* label_true = nextLabel();
        char* label_false = nextLabel();
        char* label_end = nextLabel();

        // Generate code for the conditional expression
        Quadruple* jmp_false = createQuadruple(QuadOp_JEQ, strdup($1), "0", label_false);
        addQuadruple(jmp_false);

        Quadruple* assign_true = createQuadruple(QuadOp_ASSIGN, strdup($3), NULL, temp);
        addQuadruple(assign_true);
        Quadruple* jmp_end = createQuadruple(QuadOp_JMP, label_end, NULL, NULL);
        addQuadruple(jmp_end);

        Quadruple* label_false_quad = createQuadruple(QuadOp_LABEL, label_false, NULL, NULL);
        addQuadruple(label_false_quad);

        Quadruple* assign_false = createQuadruple(QuadOp_ASSIGN, strdup($5), NULL, temp);
        addQuadruple(assign_false);

        Quadruple* label_end_quad = createQuadruple(QuadOp_LABEL, label_end, NULL, NULL);
        addQuadruple(label_end_quad);

        $$ = temp;
    }
    ;

 logical_expr: conditional_expr
    {
        $$ = $1;
    }

 logical_or_expr: logical_and_expr
    {
        $$ = $1;
    }
    | logical_or_expr OR logical_and_expr
    {
        char* temp = nextTemp();
        Quadruple* or_quad = createQuadruple(QuadOp_OR, strdup($1), strdup($3), temp);
        addQuadruple(or_quad);
        $$ = temp;
    }
    ;
 
 logical_and_expr: equality_expr
    {
        $$ = $1;
    }
    | logical_and_expr AND equality_expr
    {
        char* temp = nextTemp();
        Quadruple* and_quad = createQuadruple(QuadOp_AND, strdup($1), strdup($3), temp);
        addQuadruple(and_quad);
        $$ = temp;
    }
    ;
 
 equality_expr: relational_expr
    {
        $$ = $1;
    }
    | equality_expr EQ relational_expr
    {
        char* temp = nextTemp();
        Quadruple* eq_quad = createQuadruple(QuadOp_EQ, strdup($1), strdup($3), temp);
        addQuadruple(eq_quad);
        $$ = temp;
    }
    | equality_expr NE relational_expr
    {
        char* temp = nextTemp();
        Quadruple* ne_quad = createQuadruple(QuadOp_NE, strdup($1), strdup($3), temp);
        addQuadruple(ne_quad);
        $$ = temp;
    }
    ;
 
 relational_expr: additive_expr
    {
        $$ = $1;
    }
    | relational_expr LT additive_expr
    {
        char* temp = nextTemp();
        Quadruple* lt_quad = createQuadruple(QuadOp_LT, strdup($1), strdup($3), temp);
        addQuadruple(lt_quad);
        $$ = temp;
    }
    | relational_expr GT additive_expr
    {
        char* temp = nextTemp();
        Quadruple* gt_quad = createQuadruple(QuadOp_GT, strdup($1), strdup($3), temp);
        addQuadruple(gt_quad);
        $$ = temp;
    }
    | relational_expr LE additive_expr
    {
        char* temp = nextTemp();
        Quadruple* le_quad = createQuadruple(QuadOp_LTE, strdup($1), strdup($3), temp);
        addQuadruple(le_quad);
        $$ = temp;
    }
    | relational_expr GE additive_expr
    {
        char* temp = nextTemp();
        Quadruple* ge_quad = createQuadruple(QuadOp_GTE, strdup($1), strdup($3), temp);
        addQuadruple(ge_quad);
        $$ = temp;
    }
    ;


additive_expr: multiplicative_expr
    | additive_expr ADD multiplicative_expr
    {
        char* temp = nextTemp();
        Quadruple* add_quad = createQuadruple(QuadOp_ADD, strdup($1), strdup($3), temp);
        addQuadruple(add_quad);

        $$ = temp;

        printf("additive_expr: ADD\n");
    }
    | additive_expr SUBTRACT multiplicative_expr
    {
        char* temp = nextTemp();
        Quadruple* add_quad = createQuadruple(QuadOp_SUB, strdup($1), strdup($3), temp);
        addQuadruple(add_quad);

        $$ = temp;

        printf("additive_expr: ADD\n");
    }
    ;

 multiplicative_expr: unary_expr
    {
        $$ = $1;
    }
     | multiplicative_expr MULTIPLY unary_expr
    {
        char* temp = nextTemp();
        Quadruple* mul_quad = createQuadruple(QuadOp_MUL, strdup($1), strdup($3), temp);
        addQuadruple(mul_quad);

        $$ = temp;

        printf("multiplicative_expr: MUL\n");
    }
     | multiplicative_expr DIVIDE unary_expr
    {
        char* temp = nextTemp();
        Quadruple* div_quad = createQuadruple(QuadOp_DIV, strdup($1), strdup($3), temp);
        addQuadruple(div_quad);

        $$ = temp;

        printf("multiplicative_expr: DIV\n");
    }
     | multiplicative_expr MODULO unary_expr
    {
        char* temp = nextTemp();
        Quadruple* mod_quad = createQuadruple(QuadOp_MOD, strdup($1), strdup($3), temp);
        addQuadruple(mod_quad);

        $$ = temp;

        printf("multiplicative_expr: MOD\n");
    }
    ;

unary_expr: postfix_expr
    { $$ = $1; }
    | UNARY unary_expr
    { $$ = $2; } // Propagate the value
    | SUBTRACT unary_expr
    {
        char* temp = nextTemp();
        Quadruple* neg_quad = createQuadruple(QuadOp_NEG, strdup($2), NULL, temp);
        addQuadruple(neg_quad);
        $$ = temp;
    }
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
    {
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (!sym) {
            fprintf(stderr, "Error: Undeclared function '%s' at line %d\n", $1, line_num);
        } else if (sym->kind != SYM_FUNCTION) {
            fprintf(stderr, "Error: '%s' is not a function at line %d\n", $1, line_num);
        } else {
            mark_symbol_used(current_scope, $1);
        }
    }
    | ID LPAREN arg_list RPAREN
    {
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (!sym) {
            fprintf(stderr, "Error: Undeclared function '%s' at line %d\n", $1, line_num);
        } else if (sym->kind != SYM_FUNCTION) {
            fprintf(stderr, "Error: '%s' is not a function at line %d\n", $1, line_num);
        } else {
            mark_symbol_used(current_scope, $1);
        }
    }
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
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            fprintf(stderr, "Error: Const variable '%s' already declared at line %d\n", $1, line_num);
        } else {
            // Type compatibility check for const initialization
            const char* left_type = current_type;
            const char* right_type = NULL;
            Symbol* right_sym = lookup_symbol(current_scope, $3);
                        if (right_sym) {
                right_type = right_sym->type;
            } else if ($3 && strlen($3) == 3 && $3[0] == '\'' && $3[2] == '\'') {
                right_type = "char";
            } else if (is_number($3)) {
                right_type = "int";
            } else if (is_float($3)) {
                right_type = "float";
            } else {
                right_type = current_type; // fallback, but not ideal
            }

            if (!check_type_compatibility(left_type, right_type)) {
                fprintf(stderr, "Error: Type mismatch in assignment to '%s' at line %d ('%s' = '%s')\n",
                        $1, line_num, left_type, right_type);
            }
            insert_symbol_in_scope(current_scope, $1, current_type, SYM_VARIABLE, true, line_num);
            mark_symbol_initialized(current_scope, $1);
            Quadruple* quad = createQuadruple(QuadOp_ASSIGN, $3, NULL, strdup($1));
            addQuadruple(quad);
        }
    }
    | MULTIPLY ID ASSIGN expr
    {
        // Pointer const variable (optional: handle as needed)
        Symbol* sym = lookup_symbol(current_scope, $2);
        if (sym) {
            fprintf(stderr, "Error: Const pointer variable '%s' already declared at line %d\n", $2, line_num);
        } else {
            char pointer_type[50];
            snprintf(pointer_type, sizeof(pointer_type), "%s*", current_type);
            insert_symbol_in_scope(current_scope, $2, pointer_type, SYM_VARIABLE, true, line_num);
            mark_symbol_initialized(current_scope, $2);
        }
    }
    ;

declarator_list: declarator
    | declarator_list COMMA declarator
    ;

declarator:
    ID
    {
        // First check if already declared in current scope
        bool is_redeclaration = false;
        Symbol* sym = lookup_symbol(current_scope, $1);
        
        if (sym) {
            // If found in current scope, it's a redeclaration
            if (sym->scope_depth == current_scope->depth) {
                fprintf(stderr, "Error: Redeclaration of '%s' at line %d (previously declared at line %d)\n", 
                        $1, line_num, sym->line_number);
                is_redeclaration = true;
            } 
            // If found in IMMEDIATE parent and it's a parameter, it's shadowing a parameter
            else if (sym->kind == SYM_PARAMETER && 
                     current_scope->parent && 
                     sym->scope_depth == current_scope->parent->depth &&
                     // Make sure we're still in the same function
                     strcmp(current_function, "") != 0 &&
                     strstr(sym->name, current_function) != NULL) {
                fprintf(stderr, "Error: Local variable '%s' at line %d shadows parameter declared at line %d\n", 
                        $1, line_num, sym->line_number);
                is_redeclaration = true;
            }
        }
        
        if (!is_redeclaration) {
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
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym && sym->scope_depth == current_scope->depth) {
            fprintf(stderr, "Error: Variable '%s' already declared at line %d\n", $1, line_num);
        } else {
            // Type compatibility check for initialization
            const char* left_type = current_type;
            const char* right_type = NULL;
            Symbol* right_sym = lookup_symbol(current_scope, $3);
                        if (right_sym) {
                right_type = right_sym->type;
            } else if ($3 && strlen($3) == 3 && $3[0] == '\'' && $3[2] == '\'') {
                right_type = "char";
            } else if (is_number($3)) {
                right_type = "int";
            } else if (is_float($3)) {
                right_type = "float";
            } else {
                right_type = current_type; // fallback, but not ideal
            }

            if (!check_type_compatibility(left_type, right_type)) {
                fprintf(stderr, "Error: Type mismatch in assignment to '%s' at line %d ('%s' = '%s')\n",
                        $1, line_num, left_type, right_type);
            }
            insert_symbol_in_scope(current_scope, $1, current_type, SYM_VARIABLE, is_const_declaration, line_num);
            mark_symbol_initialized(current_scope, $1);
            Quadruple* quad = createQuadruple(QuadOp_ASSIGN, $3, NULL, strdup($1));
            addQuadruple(quad);
        }
    }
    | ID LBRACKET primary_expr RBRACKET
    {
        // Array declaration (optional: handle array size/type)
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            fprintf(stderr, "Error: Array '%s' already declared at line %d\n", $1, line_num);
        } else {
            char array_type[50];
            snprintf(array_type, sizeof(array_type), "%s[]", current_type);
            insert_symbol_in_scope(current_scope, $1, array_type, SYM_VARIABLE, is_const_declaration, line_num);
        }
    }
    | ID LBRACKET primary_expr RBRACKET ASSIGN expr
    {
        // Array declaration with initialization (optional: handle as needed)
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym) {
            fprintf(stderr, "Error: Array '%s' already declared at line %d\n", $1, line_num);
        } else {
            char array_type[50];
            snprintf(array_type, sizeof(array_type), "%s[]", current_type);
            insert_symbol_in_scope(current_scope, $1, array_type, SYM_VARIABLE, is_const_declaration, line_num);
            mark_symbol_initialized(current_scope, $1);
        }
    }
    ;
return_stmt: RETURN expr SEMI
    {
        // Track return count in current scope
        current_scope->return_count++;
        if (current_scope->return_count > 1) {
            fprintf(stderr, "Warning: Multiple return statements in the same scope at line %d\n", line_num);
        }
        has_return_stmt = 1;
        Symbol* func_sym = lookup_symbol(current_scope, current_function);
        const char* func_return_type = func_sym ? func_sym->type : NULL;
        const char* return_expr_type = NULL;
        Symbol* expr_sym = lookup_symbol(current_scope, $2);
        if (expr_sym) {
            return_expr_type = expr_sym->type;
        } else if ($2 && strlen($2) == 3 && $2[0] == '\'' && $2[2] == '\'') {
            return_expr_type = "char";
        } else if (is_number($2)) {
            return_expr_type = "int";
        } else if (is_float($2)) {
            return_expr_type = "float";
        } else {
            return_expr_type = current_type; // fallback
        }
        if (func_return_type && !check_type_compatibility(func_return_type, return_expr_type)) {
            fprintf(stderr, "Error: Return type mismatch in function '%s' at line %d ('%s' expected, got '%s')\n",
                current_function, line_num, func_return_type, return_expr_type);
        }
    }
    | RETURN SEMI
    {
        current_scope->return_count++;
        if (current_scope->return_count > 1) {
            fprintf(stderr, "Warning: Multiple return statements in the same scope at line %d\n", line_num);
        }
        has_return_stmt = 1;
        Symbol* func_sym = lookup_symbol(current_scope, current_function);
        if (func_sym && strcmp(func_sym->type, "void") != 0) {
            fprintf(stderr, "Warning: Non-void function '%s' should return a value at line %d\n",
                current_function, line_num);
        }
    }
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