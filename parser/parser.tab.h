/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    FLOAT_NUM = 259,               /* FLOAT_NUM  */
    BOOL = 260,                    /* BOOL  */
    ID = 261,                      /* ID  */
    STR = 262,                     /* STR  */
    CHAR_LITERAL = 263,            /* CHAR_LITERAL  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    WHILE = 266,                   /* WHILE  */
    FOR = 267,                     /* FOR  */
    DO = 268,                      /* DO  */
    SWITCH = 269,                  /* SWITCH  */
    CASE = 270,                    /* CASE  */
    DEFAULT = 271,                 /* DEFAULT  */
    BREAK = 272,                   /* BREAK  */
    CONTINUE = 273,                /* CONTINUE  */
    INT = 274,                     /* INT  */
    FLOAT = 275,                   /* FLOAT  */
    DOUBLE = 276,                  /* DOUBLE  */
    CHAR = 277,                    /* CHAR  */
    VOID = 278,                    /* VOID  */
    CONST = 279,                   /* CONST  */
    TRUE = 280,                    /* TRUE  */
    FALSE = 281,                   /* FALSE  */
    PRINTFF = 282,                 /* PRINTFF  */
    SCANFF = 283,                  /* SCANFF  */
    RETURN = 284,                  /* RETURN  */
    INCLUDE = 285,                 /* INCLUDE  */
    ASSIGN = 286,                  /* ASSIGN  */
    EQ = 287,                      /* EQ  */
    NE = 288,                      /* NE  */
    LE = 289,                      /* LE  */
    GE = 290,                      /* GE  */
    GT = 291,                      /* GT  */
    LT = 292,                      /* LT  */
    AND = 293,                     /* AND  */
    OR = 294,                      /* OR  */
    NOT = 295,                     /* NOT  */
    ADD = 296,                     /* ADD  */
    SUBTRACT = 297,                /* SUBTRACT  */
    MULTIPLY = 298,                /* MULTIPLY  */
    DIVIDE = 299,                  /* DIVIDE  */
    MODULO = 300,                  /* MODULO  */
    UNARY = 301,                   /* UNARY  */
    SEMI = 302,                    /* SEMI  */
    UNARY_INC = 303,               /* UNARY_INC  */
    UNARY_DEC = 304,               /* UNARY_DEC  */
    NULL_TOKEN = 305,              /* NULL_TOKEN  */
    LBRACE = 306,                  /* LBRACE  */
    RBRACE = 307,                  /* RBRACE  */
    LPAREN = 308,                  /* LPAREN  */
    RPAREN = 309,                  /* RPAREN  */
    LBRACKET = 310,                /* LBRACKET  */
    RBRACKET = 311,                /* RBRACKET  */
    COMMA = 312,                   /* COMMA  */
    COLON = 313,                   /* COLON  */
    QUESTION = 314,                /* QUESTION  */
    BIT_AND = 315,                 /* BIT_AND  */
    ADD_ASSIGN = 316,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 317,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 318,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 319,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 320,              /* MOD_ASSIGN  */
    LOWER_THAN_ELSE = 321          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "parser/parser.y"

    int num;
    float fnum;
    char* str;

#line 136 "parser/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_TAB_H_INCLUDED  */
