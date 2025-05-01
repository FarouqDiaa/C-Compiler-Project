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

program: headers main '(' ')' '{' body return_stmt '}'
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

body:
      '{' body '}'
    | FOR '(' for_stmt ')' body
    | WHILE '(' condition ')' body
    | IF '(' condition ')' body %prec LOWER_THAN_ELSE
    | IF '(' condition ')' body ELSE body
    | statement
    | body body
    | PRINTFF '(' STR opt_args ')' SEMI
    | SCANFF '(' STR ',' '&' ID ')' SEMI
    ;

opt_args:                        
        /* empty */
    | ',' arg_list
    ;

arg_list:
        expression
    | arg_list ',' expression
    ;

for_stmt:
        simple_expr SEMI simple_expr SEMI simple_expr
    ;

simple_expr:
        /* empty */
    | expression
    ;

condition: expression comparison expression
    | TRUE 
    | FALSE
    | condition AND condition
    | condition OR condition
    ;

value: NUMBER
     | FLOAT_NUM
     | STR
     | ID
     | CHAR_LITERAL
     ;

comparison: LT
    | GT
    | LE
    | GE
    | EQ
    | NE
    ;

statement: declaration SEMI
    | expression SEMI
    | ID ASSIGN expression SEMI
    | ID comparison expression SEMI
    | ID UNARY SEMI
    | UNARY ID SEMI
    ;

declaration: datatype ID ASSIGN expression
    | datatype ID
    ;

expression:
        ID ASSIGN expression
    | datatype ID ASSIGN expression
    | datatype ID
    | term
    | expression ADD term
    | expression SUBTRACT term
    | ID UNARY
    | UNARY ID
    ;

term: term MULTIPLY factor
    | term DIVIDE factor
    | term MODULO factor     
    | factor
    ;

factor: value
    | '(' expression ')'
    ;

return_stmt: RETURN value SEMI
    |
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
