/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
    SWITCH = 267,                  /* SWITCH  */
    CASE = 268,                    /* CASE  */
    DEFAULT = 269,                 /* DEFAULT  */
    BREAK = 270,                   /* BREAK  */
    CONTINUE = 271,                /* CONTINUE  */
    INT = 272,                     /* INT  */
    FLOAT = 273,                   /* FLOAT  */
    CHAR = 274,                    /* CHAR  */
    VOID = 275,                    /* VOID  */
    TRUE = 276,                    /* TRUE  */
    FALSE = 277,                   /* FALSE  */
    PRINTFF = 278,                 /* PRINTFF  */
    SCANFF = 279,                  /* SCANFF  */
    RETURN = 280,                  /* RETURN  */
    INCLUDE = 281,                 /* INCLUDE  */
    ASSIGN = 282,                  /* ASSIGN  */
    EQ = 283,                      /* EQ  */
    NE = 284,                      /* NE  */
    LE = 285,                      /* LE  */
    GE = 286,                      /* GE  */
    GT = 287,                      /* GT  */
    LT = 288,                      /* LT  */
    AND = 289,                     /* AND  */
    OR = 290,                      /* OR  */
    ADD = 291,                     /* ADD  */
    SUBTRACT = 292,                /* SUBTRACT  */
    MULTIPLY = 293,                /* MULTIPLY  */
    DIVIDE = 294,                  /* DIVIDE  */
    MODULO = 295,                  /* MODULO  */
    UNARY = 296,                   /* UNARY  */
    SEMI = 297,                    /* SEMI  */
    NULL_TOKEN = 298,              /* NULL_TOKEN  */
    LEFT_SQUARE_BRACE = 299,       /* LEFT_SQUARE_BRACE  */
    RIGHT_SQUARE_BRACE = 300,      /* RIGHT_SQUARE_BRACE  */
    ADD_ASSIGN = 301,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 302,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 303,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 304,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 305,              /* MOD_ASSIGN  */
    LOWER_THAN_ELSE = 306          /* LOWER_THAN_ELSE  */
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

#line 121 "parser/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_PARSER_TAB_H_INCLUDED  */
