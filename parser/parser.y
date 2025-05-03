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
    | datatype ID LPAREN RPAREN
    ;

include_directive: INCLUDE
    ;

function_definition: datatype ID LPAREN parameter_list RPAREN compound_stmt
    | datatype ID LPAREN RPAREN compound_stmt
    ;

parameter_list: parameter_declaration
    | parameter_list COMMA parameter_declaration
    ;

parameter_declaration: datatype ID
    | datatype MULTIPLY ID
    | CONST datatype ID
    | CONST datatype MULTIPLY ID
    ;

compound_stmt: LBRACE stmt_list RBRACE
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
    ;

expr: assign_expr
    ;

assign_expr: logical_expr
    | ID ASSIGN assign_expr
    | MULTIPLY ID ASSIGN assign_expr
    | ID ADD_ASSIGN assign_expr
    | ID SUB_ASSIGN assign_expr
    | ID MUL_ASSIGN assign_expr
    | ID DIV_ASSIGN assign_expr
    | ID MOD_ASSIGN assign_expr
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
    | UNARY unary_expr
    | SUBTRACT unary_expr
    | MULTIPLY unary_expr
    | NOT unary_expr
    | BIT_AND unary_expr
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
    | NULL_TOKEN
    | LPAREN expr RPAREN
    | function_call
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

const_declarator: ID ASSIGN expr
    | MULTIPLY ID ASSIGN expr
    ;

declarator_list: declarator
    | declarator_list COMMA declarator
    ;

declarator: ID
    | MULTIPLY declarator
    | ID ASSIGN expr
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
    return result;
}
