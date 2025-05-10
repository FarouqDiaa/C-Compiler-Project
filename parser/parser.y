%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "semantic_analyzer.h" // Added include for semantic analyzer
#include "symbol_table.h"      // Added include for symbol table

void yyerror(const char *s);
int yylex();
int yywrap();

extern int line_num;

// Track the current type for declarations
char current_type[20] = "";
%}

%union {
    int num;
    float fnum;
    char* str;
    char* type;  // For tracking expression types
}

%token <num> NUMBER
%token <fnum> FLOAT_NUM
%token <str> ID
%token <str> STR
%token <str> CHAR_LITERAL

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

/* Type information for expressions */
%type <type> expr assign_expr conditional_expr logical_expr logical_or_expr
%type <type> logical_and_expr equality_expr relational_expr additive_expr 
%type <type> multiplicative_expr unary_expr postfix_expr primary_expr
%type <str> datatype function_call

%%

program: translation_unit
    ;

translation_unit: external_declaration
    | translation_unit external_declaration
    ;

external_declaration: function_definition
    | declaration SEMI
    | function_prototype SEMI
    | include_directive
    ;

function_prototype: datatype ID LPAREN parameter_list RPAREN
    {
        insert_symbol($2, "function");
    }
    | datatype ID LPAREN RPAREN
    {
        insert_symbol($2, "function");
    }
    ;

include_directive: INCLUDE
    ;

function_definition: datatype ID LPAREN parameter_list RPAREN compound_stmt
    {
        insert_symbol($2, "function");
    }
    | datatype ID LPAREN RPAREN compound_stmt
    {
        insert_symbol($2, "function");
    }
    ;

parameter_list: parameter_declaration
    | parameter_list COMMA parameter_declaration
    ;

parameter_declaration: datatype ID
    {
        insert_symbol($2, $1);
        check_assignment($2); // Parameters are considered initialized
    }
    | datatype MULTIPLY ID
    {
        char type[30];
        sprintf(type, "%s*", $1);
        insert_symbol($3, type);
        check_assignment($3); // Parameters are considered initialized
    }
    | CONST datatype ID
    {
        char type[30];
        sprintf(type, "const %s", $2);
        insert_symbol($3, type);
        check_assignment($3); // Parameters are considered initialized
    }
    | CONST datatype MULTIPLY ID
    {
        char type[30];
        sprintf(type, "const %s*", $2);
        insert_symbol($4, type);
        check_assignment($4); // Parameters are considered initialized
    }
    ;

compound_stmt: LBRACE stmt_list RBRACE
    ;

datatype: INT { $$ = strdup("int"); }
    | FLOAT { $$ = strdup("float"); }
    | CHAR { $$ = strdup("char"); }
    | DOUBLE { $$ = strdup("double"); }
    | VOID { $$ = strdup("void"); }
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

for_stmt: FOR LPAREN for_init SEMI for_cond SEMI for_update RPAREN stmt
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
    {
        check_assignment($6); // Mark variable as initialized after scanf
    }
    ;

expr: assign_expr
    { $$ = $1; }
    ;

assign_expr: logical_expr 
    { $$ = $1; }
    | ID ASSIGN assign_expr
    {
        check_assignment($1); // Mark variable as initialized
        check_type_compatibility($1, $3); // Check if types are compatible
        
        // Get the variable's type for the result type
        char type[20];
        if (get_symbol_type($1, type)) {
            $$ = strdup(type);
        } else {
            $$ = strdup("int"); // Default type
        }
    }
    | MULTIPLY ID ASSIGN assign_expr
    {
        check_assignment($2); // Mark variable as initialized
        
        // Get the variable's type for the result type
        char type[20];
        if (get_symbol_type($2, type)) {
            if (strstr(type, "*") == NULL) {
                printf("Error at line %d: Cannot dereference non-pointer variable '%s'.\n", line_num, $2);
            }
            // Remove the pointer for assignment type
            char base_type[20];
            strncpy(base_type, type, strcspn(type, "*"));
            base_type[strcspn(type, "*")] = '\0';
            check_type_compatibility(base_type, $4);
            $$ = strdup(base_type);
        } else {
            $$ = strdup("int"); // Default type
        }
    }
    | ID ADD_ASSIGN assign_expr
    {
        check_initialization($1); // Check if variable is initialized
        check_assignment($1); // Mark variable as initialized
        
        // Get the variable's type
        char type[20];
        if (get_symbol_type($1, type)) {
            if (strcmp(type, "int") != 0 && strcmp(type, "float") != 0) {
                printf("Error at line %d: '+=' operator requires numeric operands.\n", line_num);
            }
            check_type_compatibility($1, $3);
            $$ = strdup(type);
        } else {
            $$ = strdup("int"); // Default type
        }
    }
    | ID SUB_ASSIGN assign_expr
    {
        check_initialization($1); // Check if variable is initialized
        check_assignment($1); // Mark variable as initialized
        
        // Get the variable's type
        char type[20];
        if (get_symbol_type($1, type)) {
            if (strcmp(type, "int") != 0 && strcmp(type, "float") != 0) {
                printf("Error at line %d: '-=' operator requires numeric operands.\n", line_num);
            }
            check_type_compatibility($1, $3);
            $$ = strdup(type);
        } else {
            $$ = strdup("int"); // Default type
        }
    }
    | ID MUL_ASSIGN assign_expr
    {
        check_initialization($1); // Check if variable is initialized
        check_assignment($1); // Mark variable as initialized
        
        // Get the variable's type
        char type[20];
        if (get_symbol_type($1, type)) {
            if (strcmp(type, "int") != 0 && strcmp(type, "float") != 0) {
                printf("Error at line %d: '*=' operator requires numeric operands.\n", line_num);
            }
            check_type_compatibility($1, $3);
            $$ = strdup(type);
        } else {
            $$ = strdup("int"); // Default type
        }
    }
    | ID DIV_ASSIGN assign_expr
    {
        check_initialization($1); // Check if variable is initialized
        check_assignment($1); // Mark variable as initialized
        
        // Get the variable's type
        char type[20];
        if (get_symbol_type($1, type)) {
            if (strcmp(type, "int") != 0 && strcmp(type, "float") != 0) {
                printf("Error at line %d: '/=' operator requires numeric operands.\n", line_num);
            }
            check_type_compatibility($1, $3);
            $$ = strdup(type);
        } else {
            $$ = strdup("int"); // Default type
        }
    }
    | ID MOD_ASSIGN assign_expr
    {
        check_initialization($1); // Check if variable is initialized
        check_assignment($1); // Mark variable as initialized
        
        // Get the variable's type
        char type[20];
        if (get_symbol_type($1, type)) {
            if (strcmp(type, "int") != 0) {
                printf("Error at line %d: '%%=' operator requires integer operands.\n", line_num);
            }
            if (strcmp($3, "int") != 0) {
                printf("Error at line %d: '%%=' operator requires integer operands.\n", line_num);
            }
            $$ = strdup("int");
        } else {
            $$ = strdup("int"); // Default type
        }
    }
    ;

conditional_expr: logical_or_expr
    { $$ = $1; }
    | logical_or_expr QUESTION expr COLON conditional_expr
    {
        // The result type depends on the types of both expressions
        if (is_type_compatible($3, $5) || is_type_compatible($5, $3)) {
            // If one type can be converted to the other, use the wider type
            if (strcmp($3, "float") == 0 || strcmp($5, "float") == 0) {
                $$ = strdup("float");
            } else {
                $$ = strdup("int");
            }
        } else {
            printf("Error at line %d: Incompatible types in conditional expression.\n", line_num);
            $$ = strdup("int"); // Default type
        }
    }
    ;

logical_expr: conditional_expr
    { $$ = $1; }
    ;

logical_or_expr: logical_and_expr
    { $$ = $1; }
    | logical_or_expr OR logical_and_expr
    {
        $$ = strdup("int"); // Logical OR always results in int (boolean)
    }
    ;

logical_and_expr: equality_expr
    { $$ = $1; }
    | logical_and_expr AND equality_expr
    {
        $$ = strdup("int"); // Logical AND always results in int (boolean)
    }
    ;

equality_expr: relational_expr
    { $$ = $1; }
    | equality_expr EQ relational_expr
    {
        // Check if the types can be compared
        if (!is_type_compatible($1, $3) && !is_type_compatible($3, $1)) {
            printf("Error at line %d: Cannot compare '%s' with '%s'.\n", 
                   line_num, $1, $3);
        }
        $$ = strdup("int"); // Comparison always results in int (boolean)
    }
    | equality_expr NE relational_expr
    {
        // Check if the types can be compared
        if (!is_type_compatible($1, $3) && !is_type_compatible($3, $1)) {
            printf("Error at line %d: Cannot compare '%s' with '%s'.\n", 
                   line_num, $1, $3);
        }
        $$ = strdup("int"); // Comparison always results in int (boolean)
    }
    ;

relational_expr: additive_expr
    { $$ = $1; }
    | relational_expr LT additive_expr
    {
        // Check if the types can be compared
        if (!is_type_compatible($1, $3) && !is_type_compatible($3, $1)) {
            printf("Error at line %d: Cannot compare '%s' with '%s'.\n", 
                   line_num, $1, $3);
        }
        $$ = strdup("int"); // Comparison always results in int (boolean)
    }
    | relational_expr GT additive_expr
    {
        // Check if the types can be compared
        if (!is_type_compatible($1, $3) && !is_type_compatible($3, $1)) {
            printf("Error at line %d: Cannot compare '%s' with '%s'.\n", 
                   line_num, $1, $3);
        }
        $$ = strdup("int"); // Comparison always results in int (boolean)
    }
    | relational_expr LE additive_expr
    {
        // Check if the types can be compared
        if (!is_type_compatible($1, $3) && !is_type_compatible($3, $1)) {
            printf("Error at line %d: Cannot compare '%s' with '%s'.\n", 
                   line_num, $1, $3);
        }
        $$ = strdup("int"); // Comparison always results in int (boolean)
    }
    | relational_expr GE additive_expr
    {
        // Check if the types can be compared
        if (!is_type_compatible($1, $3) && !is_type_compatible($3, $1)) {
            printf("Error at line %d: Cannot compare '%s' with '%s'.\n", 
                   line_num, $1, $3);
        }
        $$ = strdup("int"); // Comparison always results in int (boolean)
    }
    ;

additive_expr: multiplicative_expr
    { $$ = $1; }
    | additive_expr ADD multiplicative_expr
    {
        $$ = strdup(check_binary_op_types($1, $3, "+"));
    }
    | additive_expr SUBTRACT multiplicative_expr
    {
        $$ = strdup(check_binary_op_types($1, $3, "-"));
    }
    ;

multiplicative_expr: unary_expr
    { $$ = $1; }
    | multiplicative_expr MULTIPLY unary_expr
    {
        $$ = strdup(check_binary_op_types($1, $3, "*"));
    }
    | multiplicative_expr DIVIDE unary_expr
    {
        $$ = strdup(check_binary_op_types($1, $3, "/"));
    }
    | multiplicative_expr MODULO unary_expr
    {
        $$ = strdup(check_binary_op_types($1, $3, "%"));
    }
    ;

unary_expr: postfix_expr
    { $$ = $1; }
    | UNARY unary_expr
    {
        // For increment/decrement, the operand must be a variable
        if (strcmp($2, "int") != 0 && strcmp($2, "float") != 0 && strcmp($2, "char") != 0) {
            printf("Error at line %d: Increment/decrement requires numeric operand.\n", line_num);
        }
        $$ = $2;
    }
    | SUBTRACT unary_expr
    {
        // Negation requires numeric operand
        if (strcmp($2, "int") != 0 && strcmp($2, "float") != 0) {
            printf("Error at line %d: Unary minus requires numeric operand.\n", line_num);
        }
        $$ = $2;
    }
    | MULTIPLY unary_expr
    {
        // Dereference requires pointer
        if (strstr($2, "*") == NULL) {
            printf("Error at line %d: Cannot dereference non-pointer type.\n", line_num);
            $$ = strdup("int"); // Default to prevent cascading errors
        } else {
            // Get the base type (remove the pointer)
            char base_type[20];
            strncpy(base_type, $2, strcspn($2, "*"));
            base_type[strcspn($2, "*")] = '\0';
            $$ = strdup(base_type);
        }
    }
    | NOT unary_expr
    {
        $$ = strdup("int"); // Logical NOT always results in int (boolean)
    }
    | BIT_AND unary_expr
    {
        // Taking address of variable - result is a pointer to the type
        char ptr_type[30];
        sprintf(ptr_type, "%s*", $2);
        $$ = strdup(ptr_type);
    }
    ;

postfix_expr: primary_expr
    { $$ = $1; }
    | postfix_expr UNARY
    {
        // For increment/decrement, the operand must be a variable
        if (strcmp($1, "int") != 0 && strcmp($1, "float") != 0 && strcmp($1, "char") != 0) {
            printf("Error at line %d: Increment/decrement requires numeric operand.\n", line_num);
        }
        $$ = $1;
    }
    ;

primary_expr: ID
    {
        check_initialization($1); // Check if variable is initialized
        record_variable_usage($1); // Record that the variable was used
        
        // Get the variable's type
        char type[20];
        if (get_symbol_type($1, type)) {
            $$ = strdup(type);
        } else {
            printf("Error at line %d: Undeclared variable '%s'.\n", line_num, $1);
            $$ = strdup("int"); // Default to prevent cascading errors
        }
    }
    | NUMBER { $$ = strdup("int"); }
    | FLOAT_NUM { $$ = strdup("float"); }
    | STR { $$ = strdup("string"); }
    | CHAR_LITERAL { $$ = strdup("char"); }
    | TRUE { $$ = strdup("int"); }  // Boolean true is an integer
    | FALSE { $$ = strdup("int"); } // Boolean false is an integer
    | NULL_TOKEN { $$ = strdup("void*"); } // NULL is a void pointer
    | LPAREN expr RPAREN { $$ = $2; }
    | function_call { $$ = $1; }
    ;

function_call: ID LPAREN RPAREN
    {
        // Get function return type
        char type[20];
        if (get_symbol_type($1, type)) {
            if (strcmp(type, "function") != 0) {
                printf("Error at line %d: '%s' is not a function.\n", line_num, $1);
            }
            $$ = strdup("int"); // Default return type for now
        } else {
            printf("Error at line %d: Undefined function '%s'.\n", line_num, $1);
            $$ = strdup("int"); // Default return type
        }
    }
    | ID LPAREN arg_list RPAREN
    {
        // Get function return type
        char type[20];
        if (get_symbol_type($1, type)) {
            if (strcmp(type, "function") != 0) {
                printf("Error at line %d: '%s' is not a function.\n", line_num, $1);
            }
            $$ = strdup("int"); // Default return type for now
        } else {
            printf("Error at line %d: Undefined function '%s'.\n", line_num, $1);
            $$ = strdup("int"); // Default return type
        }
    }
    ;

declaration: datatype declarator_list
    {
        strcpy(current_type, $1); // Save the current type for declarator_list
    }
    | CONST datatype const_declarator_list
    {
        char const_type[30];
        sprintf(const_type, "const %s", $2);
        strcpy(current_type, const_type);
    }
    ;

const_declarator_list: const_declarator
    | const_declarator_list COMMA const_declarator
    ;

const_declarator: ID ASSIGN expr
    {
        // The current_type is already set in the declaration rule
        insert_symbol($1, current_type);
        check_assignment($1); // Mark as initialized
        check_type_compatibility($1, $3);
    }
    | MULTIPLY ID ASSIGN expr
    {
        char ptr_type[30];
        sprintf(ptr_type, "%s*", current_type);
        insert_symbol($2, ptr_type);
        check_assignment($2); // Mark as initialized
        
        // Check if proper type for pointer assignment
        if (strcmp($4, "void*") != 0 && strstr($4, "*") == NULL) {
            printf("Error at line %d: Cannot assign non-pointer value to pointer.\n", line_num);
        }
    }
    ;

declarator_list: declarator
    | declarator_list COMMA declarator
    ;

declarator: ID
    {
        // Just declare the variable with the current type
        insert_symbol($1, current_type);
    }
    | MULTIPLY declarator
    {
        // Handled in nested declarator
    }
    | ID ASSIGN expr
    {
        // Declare and initialize
        insert_symbol($1, current_type);
        check_assignment($1); // Mark as initialized
        check_type_compatibility($1, $3);
    }
    | ID LBRACKET primary_expr RBRACKET
    {
        // Array declaration
        char array_type[30];
        sprintf(array_type, "%s[]", current_type);
        insert_symbol($1, array_type);
        
        // Check if array size is an integer
        if (strcmp($3, "int") != 0) {
            printf("Error at line %d: Array size must be an integer.\n", line_num);
        }
    }
    | ID LBRACKET primary_expr RBRACKET ASSIGN expr
    {
        // Array declaration with initialization
        char array_type[30];
        sprintf(array_type, "%s[]", current_type);
        insert_symbol($1, array_type);
        check_assignment($1); // Mark as initialized
        
        // Check if array size is an integer
        if (strcmp($3, "int") != 0) {
            printf("Error at line %d: Array size must be an integer.\n", line_num);
        }
        
        // Check if initializer is compatible
        if (strcmp($6, "string") == 0 && strcmp(current_type, "char") == 0) {
            // Allow string initialization for char arrays
        } else {
            printf("Error at line %d: Invalid array initializer type.\n", line_num);
        }
    }
    ;

return_stmt: RETURN expr SEMI
    {
        // Ideally would check if the return type matches the function's declared return type
    }
    | RETURN SEMI
    {
        // Void return
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", line_num, s);
}

int main() {
    printf("Parsing started...\n");
    init_semantic_analyzer();  // Initialize the semantic analyzer
    int result = yyparse();
    if (result == 0) {
        printf("Parsing completed successfully.\n");
        semantic_analysis();   // Run semantic analysis after parsing
    }
    return result;
}