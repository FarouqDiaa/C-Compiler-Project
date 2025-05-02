%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../parser/parser.tab.h"

int line_num = 1;
%}

alpha [a-zA-Z]
digit [0-9]
alnum [a-zA-Z0-9]
space [ \t]

%%

"#include"[ ]*"<"[^>]*">" { return INCLUDE; }

"int"       { return INT; }
"float"     { return FLOAT; }
"char"      { return CHAR; }
"void"      { return VOID; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"return"    { return RETURN; }
"printf"    { return PRINTFF; }
"scanf"     { return SCANFF; }
"true"      { return TRUE; }
"false"     { return FALSE; }

"switch"    { return SWITCH; }
"case"      { return CASE; }
"default"   { return DEFAULT; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }
"NULL"  { return NULL_TOKEN; }

{alpha}({alnum}|_)*   { 
    yylval.str = strdup(yytext);
    return ID; 
}

{digit}+    { 
    yylval.num = atoi(yytext);
    return NUMBER; 
}

{digit}+\.{digit}+    { 
    yylval.fnum = atof(yytext);
    return FLOAT_NUM; 
}

\"[^"]*\"   { 
    yylval.str = strdup(yytext);
    return STR; 
}

\'([^\\']|\\.)\' {
    yylval.str = strdup(yytext);
    return CHAR_LITERAL;
}


"=="    { return EQ; }
"!="    { return NE; }
"<="    { return LE; }
">="    { return GE; }
">"     { return GT; }
"<"     { return LT; }
"&&"    { return AND; }
"||"    { return OR; }
"!"     { return '!'; }
":"     { return ':'; }
"?"     { return '?'; }

"="     { return ASSIGN; }
"+"     { return ADD; }
"-"     { return SUBTRACT; }
"*"     { return MULTIPLY; }
"%"     { return MODULO; }
"/"     { return DIVIDE; }
"++"    { return UNARY; }
"--"    { return UNARY; }
";"     { return SEMI; }

"{"     { return '{'; }
"}"     { return '}'; }
"("     { return '('; }
")"     { return ')'; }
","     { return ','; }
"&"     { return '&'; }
"["     { return '['; }
"]"     { return ']'; }
"+="    { return ADD_ASSIGN; }
"-="    { return SUB_ASSIGN; }
"*="    { return MUL_ASSIGN; }
"/="    { return DIV_ASSIGN; }
"%="    { return MOD_ASSIGN; }

"//".*  { /* Single line comment, do nothing */ }

"\n"    { line_num++; }
{space} { /* Ignore whitespace */ }

.       { printf("Lexical error on line %d: Unknown token %s\n", line_num, yytext); }

%%

int yywrap() {
    return 1;
}