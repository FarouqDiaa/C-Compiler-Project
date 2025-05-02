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
    ID = 260,                      /* ID  */
    STR = 261,                     /* STR  */
    CHAR_LITERAL = 262,            /* CHAR_LITERAL  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    WHILE = 265,                   /* WHILE  */
    FOR = 266,                     /* FOR  */
    DO = 267,                      /* DO  */
    SWITCH = 268,                  /* SWITCH  */
    CASE = 269,                    /* CASE  */
    DEFAULT = 270,                 /* DEFAULT  */
    BREAK = 271,                   /* BREAK  */
    CONTINUE = 272,                /* CONTINUE  */
    INT = 273,                     /* INT  */
    FLOAT = 274,                   /* FLOAT  */
    DOUBLE = 275,                  /* DOUBLE  */
    CHAR = 276,                    /* CHAR  */
    VOID = 277,                    /* VOID  */
    CONST = 278,                   /* CONST  */
    TRUE = 279,                    /* TRUE  */
    FALSE = 280,                   /* FALSE  */
    PRINTFF = 281,                 /* PRINTFF  */
    SCANFF = 282,                  /* SCANFF  */
    RETURN = 283,                  /* RETURN  */
    INCLUDE = 284,                 /* INCLUDE  */
    ASSIGN = 285,                  /* ASSIGN  */
    EQ = 286,                      /* EQ  */
    NE = 287,                      /* NE  */
    LE = 288,                      /* LE  */
    GE = 289,                      /* GE  */
    GT = 290,                      /* GT  */
    LT = 291,                      /* LT  */
    AND = 292,                     /* AND  */
    OR = 293,                      /* OR  */
    ADD = 294,                     /* ADD  */
    SUBTRACT = 295,                /* SUBTRACT  */
    MULTIPLY = 296,                /* MULTIPLY  */
    DIVIDE = 297,                  /* DIVIDE  */
    MODULO = 298,                  /* MODULO  */
    UNARY = 299,                   /* UNARY  */
    SEMI = 300,                    /* SEMI  */
    NULL_TOKEN = 301,              /* NULL_TOKEN  */
    LEFT_SQUARE_BRACE = 302,       /* LEFT_SQUARE_BRACE  */
    RIGHT_SQUARE_BRACE = 303,      /* RIGHT_SQUARE_BRACE  */
    ADD_ASSIGN = 304,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 305,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 306,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 307,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 308,              /* MOD_ASSIGN  */
    LOWER_THAN_ELSE = 309          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser/parser.y"

    int num;
    float fnum;
    char* str;

#line 124 "parser/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_TAB_H_INCLUDED  */
