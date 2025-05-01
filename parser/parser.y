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

program: headers main '(' ')' '{' stmt_list return_stmt '}'
    ;

headers: INCLUDE headers
   |
   ;

main: datatype ID
    ;

datatype: INT
    | FLOAT
    | CHAR
    | VOID
    ;

stmt_list: /* empty */
    | stmt_list stmt
    ;

stmt: block_stmt
    | if_stmt
    | for_stmt
    | while_stmt
    | expr_stmt
    | decl_stmt
    | print_stmt
    | scan_stmt
    ;

block_stmt: '{' stmt_list '}'
    ;

if_stmt: IF '(' condition ')' stmt %prec LOWER_THAN_ELSE
    | IF '(' condition ')' stmt ELSE stmt
    ;

for_stmt: FOR '(' for_init SEMI for_cond SEMI for_update ')' stmt
    ;

for_init: /* empty */
    | non_decl_expr
    | declaration
    ;

for_cond: /* empty */
    | condition
    ;

for_update: /* empty */
    | non_decl_expr
    ;

non_decl_expr: assign_expr
    | arithmetic_expr
    | unary_expr
    ;

unary_expr: ID UNARY
    | UNARY ID
    ;

while_stmt: WHILE '(' condition ')' stmt
    ;

expr_stmt: non_decl_expr SEMI
    ;

decl_stmt: declaration SEMI
    ;

print_stmt: PRINTFF '(' STR print_args ')' SEMI
    ;

print_args: /* empty */
    | ',' print_arg_list
    ;

print_arg_list: non_decl_expr
    | print_arg_list ',' non_decl_expr
    ;

scan_stmt: SCANFF '(' STR ',' '&' ID ')' SEMI
    ;

condition: boolean_expr
    ;

boolean_expr: boolean_term
    | boolean_expr OR boolean_term
    ;

boolean_term: boolean_factor
    | boolean_term AND boolean_factor
    ;

boolean_factor: TRUE
    | FALSE
    | relation_expr
    | '(' boolean_expr ')'
    ;

relation_expr: arithmetic_expr
    | arithmetic_expr comparison arithmetic_expr
    ;

comparison: LT
    | GT
    | LE
    | GE
    | EQ
    | NE
    ;

declaration: datatype ID
    | datatype ID ASSIGN non_decl_expr
    ;

assign_expr: ID ASSIGN non_decl_expr
    ;

arithmetic_expr: term
    | arithmetic_expr ADD term
    | arithmetic_expr SUBTRACT term
    ;

term: factor
    | term MULTIPLY factor
    | term DIVIDE factor
    | term MODULO factor
    ;

factor: value
    | '(' non_decl_expr ')'
    ;

value: NUMBER
    | FLOAT_NUM
    | STR
    | ID
    | CHAR_LITERAL
    ;

return_stmt: RETURN non_decl_expr SEMI
    | /* empty */
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