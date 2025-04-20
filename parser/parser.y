%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "semantic_analyzer.h"
int yyerror(char *s);
extern int yylex();
extern int line_num;
%}

%union {
    int num;
    char* str;
}

%token <num> NUM
%token <str> ID
%token IF ELSE WHILE INT FLOAT
%token ASSIGN EQ SEMI

%%

program:
    program stmt
    | stmt
    ;

stmt:
    decl SEMI
    | ID ASSIGN expr SEMI    { check_assignment($1); }
    ;

decl:
    INT ID                   { insert_symbol($2, "int"); }
    | FLOAT ID               { insert_symbol($2, "float"); }
    ;

expr:
    NUM
    | ID                     { check_initialization($1); }
    ;

%%

int yyerror(char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", line_num, s);
    return 0;
}
