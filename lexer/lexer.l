%{
#include "y.tab.h"
#include <stdio.h>
int line_num = 1;
%}

digit   [0-9]
id      [a-zA-Z_][a-zA-Z0-9_]*

%%

"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"int"       { return INT; }
"float"     { return FLOAT; }
{id}        { yylval.str = strdup(yytext); return ID; }
{digit}+    { yylval.num = atoi(yytext); return NUM; }
"=="        { return EQ; }
"="         { return ASSIGN; }
";"         { return SEMI; }
"\n"        { line_num++; }
[ \t\r]+    { /* skip whitespace */ }
.           { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() { return 1; }
