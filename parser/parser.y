%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbol_table.h"
#include "semantic_analyzer.h"

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

%token IF ELSE WHILE FOR
%token INT FLOAT CHAR VOID
%token TRUE FALSE

%token PRINTFF SCANFF
%token RETURN INCLUDE

%token ASSIGN EQ NE LE GE GT LT
%token AND OR

%token ADD SUBTRACT MULTIPLY DIVIDE
%token UNARY
%token SEMI


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

body: FOR '(' statement condition statement ')' '{' body '}'
    | WHILE '(' condition ')' '{' body '}'
    | IF '(' condition ')' '{' body '}' ELSE statement
    | IF '(' condition ')' '{' body '}'
    | statement 
    | body body
    | PRINTFF '(' STR ')' SEMI
    | SCANFF '(' STR ',' '&' ID ')' SEMI
    ;

condition: value comparison value
    | TRUE 
    | FALSE
    | condition AND condition
    | condition OR condition
    ;


value: NUMBER
    | FLOAT_NUM
    | STR
    | ID
    ;

comparison: LT
    | GT
    | LE
    | GE
    | EQ
    | NE
    ;

statement: datatype ID ASSIGN expression SEMI
    | datatype ID SEMI
    | ID ASSIGN expression SEMI 
    | ID comparison expression SEMI
    | ID UNARY SEMI
    | UNARY ID SEMI
    ;

statement: declaration SEMI
    | ID ASSIGN expression SEMI
    | ID UNARY SEMI
    | UNARY ID SEMI
    ;

declaration: datatype ID ASSIGN expression SEMI
    | datatype ID SEMI

expression: expression ADD term
    | expression SUBTRACT term
    | term MULTIPLY factor
    | term DIVIDE factor
    | factor
    ;

factor: value


return_stmt: RETURN value SEMI
    |
    ;


%%

int yyerror(char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", line_num, s);
    return 0;
}
