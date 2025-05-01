%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void yyerror(const char *s);
int yylex();
int yywrap();

extern int line_num;
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

%token IF ELSE WHILE FOR
%token INT FLOAT CHAR VOID
%token TRUE FALSE

%token PRINTFF SCANFF
%token RETURN INCLUDE

%token ASSIGN EQ NE LE GE GT LT
%token AND OR

%token ADD SUBTRACT MULTIPLY DIVIDE
%token MODULO
%token UNARY
%token SEMI

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program: translation_unit
    ;

translation_unit: external_declaration
    | translation_unit external_declaration
    ;

external_declaration: function_definition
    | declaration SEMI
    | include_directive
    ;

include_directive: INCLUDE
    ;

function_definition: datatype ID '(' parameter_list ')' compound_stmt
    | datatype ID '(' ')' compound_stmt
    ;

parameter_list: parameter_declaration
    | parameter_list ',' parameter_declaration
    ;

parameter_declaration: datatype ID
    ;

compound_stmt: '{' stmt_list '}'
    ;

datatype: INT
    | FLOAT
    | CHAR
    | VOID
    ;

stmt_list: /* empty */
    | stmt_list stmt
    ;

stmt: compound_stmt
    | if_stmt
    | for_stmt
    | while_stmt
    | expr_stmt
    | decl_stmt
    | print_stmt
    | scan_stmt
    | return_stmt
    ;

if_stmt: IF '(' expr ')' stmt %prec LOWER_THAN_ELSE
    | IF '(' expr ')' stmt ELSE stmt
    ;

for_stmt: FOR '(' for_init SEMI for_cond SEMI for_update ')' stmt
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

while_stmt: WHILE '(' expr ')' stmt
    ;

expr_stmt: expr SEMI
    ;

decl_stmt: declaration SEMI
    ;

print_stmt: PRINTFF '(' STR print_args ')' SEMI
    ;

print_args: /* empty */
    | ',' arg_list
    ;

arg_list: expr
    | arg_list ',' expr
    ;

scan_stmt: SCANFF '(' STR ',' '&' ID ')' SEMI
    ;

expr: assign_expr
    ;

assign_expr: logical_expr
    | ID ASSIGN assign_expr
    ;

logical_expr: logical_or_expr
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
    | UNARY unary_expr
    ;

postfix_expr: primary_expr
    | postfix_expr UNARY
    ;

primary_expr: ID
    | NUMBER
    | FLOAT_NUM
    | STR
    | CHAR_LITERAL
    | TRUE
    | FALSE
    | '(' expr ')'
    | function_call
    ;

function_call: ID '(' ')'
    | ID '(' arg_list ')'
    ;

declaration: datatype ID
    | datatype ID ASSIGN expr
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
    return result;
}