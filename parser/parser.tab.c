/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/symbol_table.h"
#include "../intermediate_code/quadruple.h"
#include "../intermediate_code/utils.h"
#include "../include/semantic_analyzer.h" 



void yyerror(const char *s);
int yylex();
int yywrap();

extern int line_num;

Scope* current_scope = NULL;
bool is_const_declaration = false;
char current_type[50];
char current_function[50] = "";
int is_number(const char* s) {
    if (!s) return 0;
    for (int i = 0; s[i]; ++i)
        if (!isdigit(s[i])) return 0;
    return 1;
}
int is_float(const char* s) {
    if (!s) return 0;
    int dot = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '.') {
            if (dot) return 0;
            dot = 1;
        } else if (!isdigit(s[i])) return 0;
    }
    return dot;
}

#line 112 "parser/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_FLOAT_NUM = 4,                  /* FLOAT_NUM  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_STR = 7,                        /* STR  */
  YYSYMBOL_CHAR_LITERAL = 8,               /* CHAR_LITERAL  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_DO = 13,                        /* DO  */
  YYSYMBOL_SWITCH = 14,                    /* SWITCH  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_DEFAULT = 16,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 21,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 22,                      /* CHAR  */
  YYSYMBOL_VOID = 23,                      /* VOID  */
  YYSYMBOL_CONST = 24,                     /* CONST  */
  YYSYMBOL_TRUE = 25,                      /* TRUE  */
  YYSYMBOL_FALSE = 26,                     /* FALSE  */
  YYSYMBOL_PRINTFF = 27,                   /* PRINTFF  */
  YYSYMBOL_SCANFF = 28,                    /* SCANFF  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_INCLUDE = 30,                   /* INCLUDE  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_GE = 35,                        /* GE  */
  YYSYMBOL_GT = 36,                        /* GT  */
  YYSYMBOL_LT = 37,                        /* LT  */
  YYSYMBOL_AND = 38,                       /* AND  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_ADD = 41,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 42,                  /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 43,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 44,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 45,                    /* MODULO  */
  YYSYMBOL_UNARY = 46,                     /* UNARY  */
  YYSYMBOL_SEMI = 47,                      /* SEMI  */
  YYSYMBOL_UNARY_INC = 48,                 /* UNARY_INC  */
  YYSYMBOL_UNARY_DEC = 49,                 /* UNARY_DEC  */
  YYSYMBOL_NULL_TOKEN = 50,                /* NULL_TOKEN  */
  YYSYMBOL_LBRACE = 51,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 52,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 53,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 54,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 55,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 56,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 57,                     /* COMMA  */
  YYSYMBOL_COLON = 58,                     /* COLON  */
  YYSYMBOL_QUESTION = 59,                  /* QUESTION  */
  YYSYMBOL_BIT_AND = 60,                   /* BIT_AND  */
  YYSYMBOL_ADD_ASSIGN = 61,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 62,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 63,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 64,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 65,                /* MOD_ASSIGN  */
  YYSYMBOL_LOWER_THAN_ELSE = 66,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_program = 68,                   /* program  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_translation_unit = 70,          /* translation_unit  */
  YYSYMBOL_external_declaration = 71,      /* external_declaration  */
  YYSYMBOL_include_directive = 72,         /* include_directive  */
  YYSYMBOL_function_prototype = 73,        /* function_prototype  */
  YYSYMBOL_function_definition = 74,       /* function_definition  */
  YYSYMBOL_function_header = 75,           /* function_header  */
  YYSYMBOL_parameter_list = 76,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 77,     /* parameter_declaration  */
  YYSYMBOL_compound_stmt = 78,             /* compound_stmt  */
  YYSYMBOL_79_2 = 79,                      /* $@2  */
  YYSYMBOL_datatype = 80,                  /* datatype  */
  YYSYMBOL_stmt_list = 81,                 /* stmt_list  */
  YYSYMBOL_stmt = 82,                      /* stmt  */
  YYSYMBOL_if_stmt = 83,                   /* if_stmt  */
  YYSYMBOL_for_stmt = 84,                  /* for_stmt  */
  YYSYMBOL_85_3 = 85,                      /* $@3  */
  YYSYMBOL_for_init = 86,                  /* for_init  */
  YYSYMBOL_for_cond = 87,                  /* for_cond  */
  YYSYMBOL_for_update = 88,                /* for_update  */
  YYSYMBOL_while_stmt = 89,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 90,             /* do_while_stmt  */
  YYSYMBOL_expr_stmt = 91,                 /* expr_stmt  */
  YYSYMBOL_switch_stmt = 92,               /* switch_stmt  */
  YYSYMBOL_case_list = 93,                 /* case_list  */
  YYSYMBOL_case_stmt = 94,                 /* case_stmt  */
  YYSYMBOL_default_stmt = 95,              /* default_stmt  */
  YYSYMBOL_break_stmt = 96,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 97,             /* continue_stmt  */
  YYSYMBOL_decl_stmt = 98,                 /* decl_stmt  */
  YYSYMBOL_print_stmt = 99,                /* print_stmt  */
  YYSYMBOL_print_args = 100,               /* print_args  */
  YYSYMBOL_arg_list = 101,                 /* arg_list  */
  YYSYMBOL_scan_stmt = 102,                /* scan_stmt  */
  YYSYMBOL_expr = 103,                     /* expr  */
  YYSYMBOL_assign_expr = 104,              /* assign_expr  */
  YYSYMBOL_conditional_expr = 105,         /* conditional_expr  */
  YYSYMBOL_logical_expr = 106,             /* logical_expr  */
  YYSYMBOL_logical_or_expr = 107,          /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 108,         /* logical_and_expr  */
  YYSYMBOL_equality_expr = 109,            /* equality_expr  */
  YYSYMBOL_relational_expr = 110,          /* relational_expr  */
  YYSYMBOL_additive_expr = 111,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 112,      /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 113,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 114,             /* postfix_expr  */
  YYSYMBOL_primary_expr = 115,             /* primary_expr  */
  YYSYMBOL_function_call = 116,            /* function_call  */
  YYSYMBOL_declaration = 117,              /* declaration  */
  YYSYMBOL_const_declarator_list = 118,    /* const_declarator_list  */
  YYSYMBOL_const_declarator = 119,         /* const_declarator  */
  YYSYMBOL_declarator_list = 120,          /* declarator_list  */
  YYSYMBOL_declarator = 121,               /* declarator  */
  YYSYMBOL_return_stmt = 122               /* return_stmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  255

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,    96,   109,   110,   114,   115,   116,   117,
     121,   125,   126,   130,   131,   135,   151,   152,   156,   167,
     179,   191,   208,   207,   219,   220,   221,   222,   223,   224,
     227,   228,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   246,   247,   252,   251,   264,
     265,   266,   269,   270,   273,   274,   277,   280,   283,   286,
     289,   290,   291,   294,   297,   300,   303,   306,   309,   312,
     313,   316,   317,   320,   323,   326,   327,   371,   396,   421,
     446,   471,   496,   523,   524,   553,   558,   562,   571,   575,
     584,   588,   595,   604,   608,   615,   622,   629,   639,   640,
     650,   662,   666,   676,   686,   698,   700,   702,   709,   711,
     713,   717,   722,   733,   746,   765,   771,   777,   781,   785,
     789,   793,   797,   801,   807,   818,   831,   832,   835,   836,
     840,   872,   887,   888,   892,   923,   927,   959,   971,   985,
     986
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "FLOAT_NUM",
  "BOOL", "ID", "STR", "CHAR_LITERAL", "IF", "ELSE", "WHILE", "FOR", "DO",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "INT", "FLOAT",
  "DOUBLE", "CHAR", "VOID", "CONST", "TRUE", "FALSE", "PRINTFF", "SCANFF",
  "RETURN", "INCLUDE", "ASSIGN", "EQ", "NE", "LE", "GE", "GT", "LT", "AND",
  "OR", "NOT", "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE", "MODULO", "UNARY",
  "SEMI", "UNARY_INC", "UNARY_DEC", "NULL_TOKEN", "LBRACE", "RBRACE",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "COMMA", "COLON", "QUESTION",
  "BIT_AND", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "LOWER_THAN_ELSE", "$accept", "program", "$@1",
  "translation_unit", "external_declaration", "include_directive",
  "function_prototype", "function_definition", "function_header",
  "parameter_list", "parameter_declaration", "compound_stmt", "$@2",
  "datatype", "stmt_list", "stmt", "if_stmt", "for_stmt", "$@3",
  "for_init", "for_cond", "for_update", "while_stmt", "do_while_stmt",
  "expr_stmt", "switch_stmt", "case_list", "case_stmt", "default_stmt",
  "break_stmt", "continue_stmt", "decl_stmt", "print_stmt", "print_args",
  "arg_list", "scan_stmt", "expr", "assign_expr", "conditional_expr",
  "logical_expr", "logical_or_expr", "logical_and_expr", "equality_expr",
  "relational_expr", "additive_expr", "multiplicative_expr", "unary_expr",
  "postfix_expr", "primary_expr", "function_call", "declaration",
  "const_declarator_list", "const_declarator", "declarator_list",
  "declarator", "return_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-158)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-16)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -158,    15,   345,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
     213,  -158,   345,  -158,  -158,  -158,  -158,     4,     2,    20,
      25,  -158,   336,   108,    37,    33,  -158,  -158,    66,    96,
      50,  -158,   213,   -33,   -41,  -158,    80,   105,   301,    65,
    -158,    37,   105,    85,    25,    83,  -158,  -158,  -158,   -22,
     358,  -158,   130,  -158,  -158,   309,  -158,  -158,  -158,  -158,
     134,   134,   289,   134,  -158,   105,   134,  -158,  -158,  -158,
    -158,   -27,   112,    14,   132,    92,   -17,  -158,    95,  -158,
    -158,    93,   100,  -158,  -158,   105,  -158,  -158,   146,  -158,
    -158,  -158,  -158,  -158,   105,    45,   105,   105,   105,   105,
     105,   134,  -158,  -158,   -20,  -158,  -158,   110,  -158,   134,
     105,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,  -158,  -158,   131,  -158,  -158,   202,  -158,
    -158,    49,  -158,  -158,  -158,  -158,  -158,  -158,   105,  -158,
     112,   115,    14,   132,   132,    92,    92,    92,    92,   -17,
     -17,  -158,  -158,  -158,   105,   122,   129,   133,   260,   136,
     138,   143,   139,   147,    75,  -158,  -158,    37,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
     144,   154,  -158,  -158,   105,  -158,   134,  -158,   105,   105,
    -158,   201,   105,  -158,  -158,   210,   236,  -158,   199,  -158,
    -158,  -158,  -158,   193,   195,    16,   197,   203,   194,   204,
    -158,   260,   260,   209,  -158,  -158,   105,   207,   105,   205,
     200,   265,  -158,   105,   216,  -158,   219,   243,   285,   260,
     247,  -158,   251,    58,  -158,   245,  -158,   105,  -158,   105,
     254,  -158,  -158,  -158,   269,   263,  -158,   261,  -158,  -158,
     260,  -158,   260,  -158,   260
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    29,    24,    25,    27,    26,    28,
       0,    10,     3,     4,     9,     8,     6,     0,     0,     0,
       0,     5,     0,   134,     0,   126,   132,     7,     0,     0,
     127,   128,     0,     0,     0,    16,     0,     0,     0,   134,
     135,     0,     0,     0,     0,     0,    12,    22,    14,     0,
       0,    18,     0,   115,   116,   114,   117,   118,   119,   120,
       0,     0,     0,     0,   121,     0,     0,   136,    74,    85,
      75,    83,    86,    88,    90,    93,    98,   101,   105,   111,
     123,   114,     0,   133,   130,     0,   129,    20,     0,    30,
      11,    13,    17,    19,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   107,   114,   108,   106,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   137,   131,    21,     0,    76,
     124,     0,    71,    78,    79,    80,    81,    82,     0,   122,
      87,     0,    89,    91,    92,    96,    97,    95,    94,    99,
     100,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    32,     0,    31,    33,
      34,    35,    36,    38,    37,    43,    44,    39,    40,    41,
       0,     0,    42,   125,     0,    77,     0,   138,     0,     0,
      47,     0,     0,    65,    66,     0,     0,   140,     0,    58,
      67,    72,    84,     0,     0,    49,     0,     0,    69,     0,
     139,     0,     0,     0,    50,    51,     0,     0,     0,     0,
       0,    45,    56,    52,     0,    60,    70,     0,     0,     0,
       0,    53,     0,     0,    68,     0,    46,    54,    57,     0,
       0,    59,    61,    62,     0,     0,    55,     0,    30,    73,
       0,    30,    64,    48,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -158,  -158,   306,  -158,  -158,  -158,  -158,  -158,
     271,    28,  -158,    82,  -124,  -157,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,   104,  -158,   -35,    99,   137,  -158,
    -158,   192,   214,    59,   124,    60,   -57,  -158,   286,  -158,
      -2,  -158,   284,  -158,    -7,  -158
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    12,    13,    14,    15,    16,    17,    34,
      35,   166,    89,   167,   128,   168,   169,   170,   205,   213,
     230,   245,   171,   172,   173,   174,   233,   242,   243,   175,
     176,   177,   178,   219,   131,   179,   180,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
     181,    30,    31,    25,    26,   182
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,   191,    67,   102,   103,   105,   106,    84,    23,   108,
      19,   138,   109,    49,    46,     3,    50,    40,    47,    53,
      54,     4,    55,    56,    57,    90,   120,   121,   122,    47,
     107,    28,   110,    95,    83,     5,     6,     7,     8,     9,
      10,    58,    59,    39,   105,    24,   112,   113,    53,    54,
     126,    55,    56,    57,   221,   222,    60,    22,    61,    62,
     132,    48,    63,   151,   152,   153,    64,    27,    29,    65,
      58,    59,   236,   239,   240,   141,    66,    91,    53,    54,
      24,    55,    56,    57,    18,    60,    51,    61,    62,    87,
      41,    63,    20,   253,    18,    64,    37,    42,    65,   130,
      58,    59,    43,   183,    36,    66,   184,    44,    53,    54,
     241,    55,    56,    57,    45,    60,    85,    61,    62,   187,
      38,    63,   197,    52,   252,    64,    88,   254,    65,   198,
      58,    59,    36,   118,   119,    66,    93,    53,    54,    37,
      81,    56,    57,   123,   124,    60,    95,    61,    62,   201,
     111,    63,   127,   203,   204,    64,   125,   207,    65,    58,
      59,   -15,   154,    38,   139,    66,   114,   115,   116,   117,
     214,   143,   144,   186,    60,   188,    61,   101,   149,   150,
      63,   224,   189,   132,    64,   193,   190,    65,   231,   192,
     194,   199,   195,   129,    66,   133,   134,   135,   136,   137,
     196,   200,   246,   215,   247,    53,    54,     4,    55,    56,
      57,   155,   206,   156,   157,   158,   159,   208,     4,   160,
     161,     5,     6,     7,     8,     9,    10,    58,    59,   162,
     163,   164,     5,     6,     7,     8,     9,   185,   145,   146,
     147,   148,    60,   209,    61,    62,   210,   211,    63,   212,
     216,   218,    64,    47,   165,    65,   223,   217,   225,   227,
     228,   220,    66,    53,    54,     4,    55,    56,    57,   155,
     232,   156,   157,   158,   159,   229,   184,   160,   161,     5,
       6,     7,     8,     9,    10,    58,    59,   162,   163,   164,
     234,   235,    53,    54,   237,   104,    56,    57,   238,   244,
      60,   140,    61,    62,    53,    54,    63,    81,    56,    57,
      64,    47,   248,    65,    58,    59,   249,   250,    21,   251,
      66,    92,   226,   202,    82,   142,    58,    59,    86,    60,
       0,    61,   101,     0,     0,    63,     0,     0,     0,    64,
      94,     4,    65,     0,     0,     0,     0,     0,     0,    66,
       4,    64,     0,     0,    65,     5,     6,     7,     8,     9,
      32,     0,    95,     4,     5,     6,     7,     8,     9,    10,
      96,    97,    98,    99,   100,    11,     0,     5,     6,     7,
       8,     9,    32,     0,     0,     0,     0,     0,     0,     0,
      33
};

static const yytype_int16 yycheck[] =
{
       2,   158,    37,    60,    61,    62,    63,    42,     6,    66,
      12,    31,    39,    54,    47,     0,    57,    24,    51,     3,
       4,     5,     6,     7,     8,    47,    43,    44,    45,    51,
      65,     6,    59,    53,    41,    19,    20,    21,    22,    23,
      24,    25,    26,     6,   101,    43,    32,    33,     3,     4,
      85,     6,     7,     8,   211,   212,    40,    53,    42,    43,
      95,    33,    46,   120,   121,   122,    50,    47,    43,    53,
      25,    26,   229,    15,    16,   110,    60,    49,     3,     4,
      43,     6,     7,     8,     2,    40,     6,    42,    43,     6,
      57,    46,    10,   250,    12,    50,    31,    31,    53,    54,
      25,    26,     6,    54,    22,    60,    57,    57,     3,     4,
      52,     6,     7,     8,    32,    40,    31,    42,    43,   154,
      55,    46,    47,    43,   248,    50,    43,   251,    53,   164,
      25,    26,    50,    41,    42,    60,     6,     3,     4,    31,
       6,     7,     8,    48,    49,    40,    53,    42,    43,   184,
      38,    46,     6,   188,   189,    50,    56,   192,    53,    25,
      26,    53,    31,    55,    54,    60,    34,    35,    36,    37,
     205,   112,   113,    58,    40,    53,    42,    43,   118,   119,
      46,   216,    53,   218,    50,    47,    53,    53,   223,    53,
      47,    47,    53,    94,    60,    96,    97,    98,    99,   100,
      53,    47,   237,   205,   239,     3,     4,     5,     6,     7,
       8,     9,    11,    11,    12,    13,    14,     7,     5,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    19,    20,    21,    22,    23,   138,   114,   115,
     116,   117,    40,     7,    42,    43,    47,    54,    46,    54,
      53,    57,    50,    51,    52,    53,    47,    54,    51,    54,
      60,    57,    60,     3,     4,     5,     6,     7,     8,     9,
      54,    11,    12,    13,    14,    10,    57,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      47,     6,     3,     4,    47,     6,     7,     8,    47,    54,
      40,   109,    42,    43,     3,     4,    46,     6,     7,     8,
      50,    51,    58,    53,    25,    26,    47,    54,    12,    58,
      60,    50,   218,   186,    38,   111,    25,    26,    44,    40,
      -1,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,
      31,     5,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,
       5,    50,    -1,    -1,    53,    19,    20,    21,    22,    23,
      24,    -1,    53,     5,    19,    20,    21,    22,    23,    24,
      61,    62,    63,    64,    65,    30,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,    69,     0,     5,    19,    20,    21,    22,    23,
      24,    30,    70,    71,    72,    73,    74,    75,    80,   117,
      80,    71,    53,     6,    43,   120,   121,    47,     6,    43,
     118,   119,    24,    54,    76,    77,    80,    31,    55,     6,
     121,    57,    31,     6,    57,    80,    47,    51,    78,    54,
      57,     6,    43,     3,     4,     6,     7,     8,    25,    26,
      40,    42,    43,    46,    50,    53,    60,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     6,   115,   121,   103,    31,   119,     6,    43,    79,
      47,    78,    77,     6,    31,    53,    61,    62,    63,    64,
      65,    43,   113,   113,     6,   113,   113,   103,   113,    39,
      59,    38,    32,    33,    34,    35,    36,    37,    41,    42,
      43,    44,    45,    48,    49,    56,   103,     6,    81,   104,
      54,   101,   103,   104,   104,   104,   104,   104,    31,    54,
     108,   103,   109,   110,   110,   111,   111,   111,   111,   112,
     112,   113,   113,   113,    31,     9,    11,    12,    13,    14,
      17,    18,    27,    28,    29,    52,    78,    80,    82,    83,
      84,    89,    90,    91,    92,    96,    97,    98,    99,   102,
     103,   117,   122,    54,    57,   104,    58,   103,    53,    53,
      53,    82,    53,    47,    47,    53,    53,    47,   103,    47,
      47,   103,   105,   103,   103,    85,    11,   103,     7,     7,
      47,    54,    54,    86,   103,   117,    53,    54,    57,   100,
      57,    82,    82,    47,   103,    51,   101,    54,    60,    10,
      87,   103,    54,    93,    47,     6,    82,    47,    47,    15,
      16,    52,    94,    95,    54,    88,   103,   103,    58,    47,
      54,    58,    81,    82,    81
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    69,    68,    70,    70,    71,    71,    71,    71,
      72,    73,    73,    74,    74,    75,    76,    76,    77,    77,
      77,    77,    79,    78,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    85,    84,    86,
      86,    86,    87,    87,    88,    88,    89,    90,    91,    92,
      93,    93,    93,    94,    95,    96,    97,    98,    99,   100,
     100,   101,   101,   102,   103,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     109,   109,   109,   110,   110,   110,   110,   110,   111,   111,
     111,   112,   112,   112,   112,   113,   113,   113,   113,   113,
     113,   114,   114,   114,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   121,   121,   122,
     122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     2,     1,     1,
       1,     5,     4,     5,     4,     2,     1,     3,     2,     3,
       3,     4,     0,     4,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     0,    10,     0,
       1,     1,     0,     1,     0,     1,     5,     7,     2,     7,
       0,     2,     2,     4,     3,     2,     2,     2,     6,     0,
       2,     1,     3,     8,     1,     1,     3,     4,     3,     3,
       3,     3,     3,     1,     5,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     2,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     4,     2,     3,     1,     3,
       3,     4,     1,     3,     1,     2,     3,     4,     6,     3,
       2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 96 "parser/parser.y"
    {
        current_scope = create_scope(NULL, SCOPE_GLOBAL);
    }
#line 1442 "parser/parser.tab.c"
    break;

  case 3: /* program: $@1 translation_unit  */
#line 100 "parser/parser.y"
    {
        check_unused_symbols(current_scope);
        print_symbol_table(current_scope);
    }
#line 1451 "parser/parser.tab.c"
    break;

  case 15: /* function_header: datatype ID  */
#line 136 "parser/parser.y"
    {
        strncpy(current_function, (yyvsp[0].str), sizeof(current_function) - 1);
        // Check for duplicate function
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].str));
        if (sym) {
            fprintf(stderr, "Error: Function '%s' already declared at line %d\n", (yyvsp[0].str), line_num);
        } else {
            insert_symbol_in_scope(current_scope, (yyvsp[0].str), current_type, SYM_FUNCTION, false, line_num);
        }
    }
#line 1466 "parser/parser.tab.c"
    break;

  case 18: /* parameter_declaration: datatype ID  */
#line 157 "parser/parser.y"
    {
        // Add parameter to symbol table
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].str));
        if (sym) {
            fprintf(stderr, "Error: Parameter '%s' already declared at line %d\n", (yyvsp[0].str), line_num);
        } else {
            insert_symbol_in_scope(current_scope, (yyvsp[0].str), current_type, SYM_PARAMETER, false, line_num);
            mark_symbol_initialized(current_scope, (yyvsp[0].str));
        }
    }
#line 1481 "parser/parser.tab.c"
    break;

  case 19: /* parameter_declaration: datatype MULTIPLY ID  */
#line 168 "parser/parser.y"
    {
        char pointer_type[50];
        snprintf(pointer_type, sizeof(pointer_type), "%s*", current_type);
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].str));
        if (sym) {
            fprintf(stderr, "Error: Parameter '%s' already declared at line %d\n", (yyvsp[0].str), line_num);
        } else {
            insert_symbol_in_scope(current_scope, (yyvsp[0].str), pointer_type, SYM_PARAMETER, false, line_num);
            mark_symbol_initialized(current_scope, (yyvsp[0].str));
        }
    }
#line 1497 "parser/parser.tab.c"
    break;

  case 20: /* parameter_declaration: CONST datatype ID  */
#line 180 "parser/parser.y"
    {
        char const_type[50];
        snprintf(const_type, sizeof(const_type), "const %s", current_type);
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].str));
        if (sym) {
            fprintf(stderr, "Error: Parameter '%s' already declared at line %d\n", (yyvsp[0].str), line_num);
        } else {
            insert_symbol_in_scope(current_scope, (yyvsp[0].str), const_type, SYM_PARAMETER, true, line_num);
            mark_symbol_initialized(current_scope, (yyvsp[0].str));
        }
    }
#line 1513 "parser/parser.tab.c"
    break;

  case 21: /* parameter_declaration: CONST datatype MULTIPLY ID  */
#line 192 "parser/parser.y"
    {
        char const_pointer_type[50];
        snprintf(const_pointer_type, sizeof(const_pointer_type), "const %s*", current_type);
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].str));
        if (sym) {
            fprintf(stderr, "Error: Parameter '%s' already declared at line %d\n", (yyvsp[0].str), line_num);
        } else {
            insert_symbol_in_scope(current_scope, (yyvsp[0].str), const_pointer_type, SYM_PARAMETER, true, line_num);
            mark_symbol_initialized(current_scope, (yyvsp[0].str));
        }
    }
#line 1529 "parser/parser.tab.c"
    break;

  case 22: /* $@2: %empty  */
#line 208 "parser/parser.y"
    {
        // Create a new scope for compound statement
        current_scope = enter_scope(current_scope, SCOPE_LOCAL);
    }
#line 1538 "parser/parser.tab.c"
    break;

  case 23: /* compound_stmt: LBRACE $@2 stmt_list RBRACE  */
#line 213 "parser/parser.y"
    {
        // Exit compound statement scope
        current_scope = exit_scope(current_scope);
    }
#line 1547 "parser/parser.tab.c"
    break;

  case 24: /* datatype: INT  */
#line 219 "parser/parser.y"
                { strcpy(current_type, "int"); }
#line 1553 "parser/parser.tab.c"
    break;

  case 25: /* datatype: FLOAT  */
#line 220 "parser/parser.y"
                { strcpy(current_type, "float"); }
#line 1559 "parser/parser.tab.c"
    break;

  case 26: /* datatype: CHAR  */
#line 221 "parser/parser.y"
                { strcpy(current_type, "char"); }
#line 1565 "parser/parser.tab.c"
    break;

  case 27: /* datatype: DOUBLE  */
#line 222 "parser/parser.y"
                { strcpy(current_type, "double"); }
#line 1571 "parser/parser.tab.c"
    break;

  case 28: /* datatype: VOID  */
#line 223 "parser/parser.y"
                { strcpy(current_type, "void"); }
#line 1577 "parser/parser.tab.c"
    break;

  case 29: /* datatype: BOOL  */
#line 224 "parser/parser.y"
                { strcpy(current_type, "bool"); }
#line 1583 "parser/parser.tab.c"
    break;

  case 47: /* $@3: %empty  */
#line 252 "parser/parser.y"
    {
        // Create a new scope for the for loop and its init statement
        current_scope = enter_scope(current_scope, SCOPE_LOCAL);
    }
#line 1592 "parser/parser.tab.c"
    break;

  case 48: /* for_stmt: FOR LPAREN $@3 for_init SEMI for_cond SEMI for_update RPAREN stmt  */
#line 257 "parser/parser.y"
    {
        // Exit the for loop scope
        print_symbol_table(current_scope);
        current_scope = exit_scope(current_scope);
    }
#line 1602 "parser/parser.tab.c"
    break;

  case 76: /* assign_expr: ID ASSIGN assign_expr  */
#line 328 "parser/parser.y"
    {   
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym) {
            // Type compatibility check
            const char* left_type = sym->type;
            const char* right_type = NULL;
            Symbol* right_sym = lookup_symbol(current_scope, (yyvsp[0].str));

            // Detect if $3 is a literal (number, char, etc.)
            if (right_sym) {
                right_type = right_sym->type;
            } else if ((yyvsp[0].str) && strlen((yyvsp[0].str)) == 3 && (yyvsp[0].str)[0] == '\'' && (yyvsp[0].str)[2] == '\'') {
                // It's a char literal like 'c'
                right_type = "char";
            } else if (is_number((yyvsp[0].str))) {
                right_type = "int";
            } else if (is_float((yyvsp[0].str))) {
                right_type = "float";
            } else {
                right_type = current_type; // fallback, but not ideal
            }

            if (!check_type_compatibility(left_type, right_type)) {
                fprintf(stderr, "Error: Type mismatch in assignment to '%s' at line %d ('%s' = '%s')\n",
                        (yyvsp[-2].str), line_num, left_type, right_type);
            }
            mark_symbol_used(current_scope, (yyvsp[-2].str));
            mark_symbol_initialized(current_scope, (yyvsp[-2].str));
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        (yyvsp[-2].str), line_num);
            }
            char* temp = nextTemp();
            Quadruple* quad = createQuadruple(QuadOp_ASSIGN, (yyvsp[0].str), NULL, temp);
            addQuadruple(quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup((yyvsp[-2].str)));
            addQuadruple(assign);
            (yyval.str) = strdup((yyvsp[-2].str));
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1650 "parser/parser.tab.c"
    break;

  case 77: /* assign_expr: MULTIPLY ID ASSIGN assign_expr  */
#line 372 "parser/parser.y"
    {
        // Handle pointer dereference assignment
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym) {
            mark_symbol_used(current_scope, (yyvsp[-2].str));
            // Don't mark as initialized, since we're dereferencing
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        (yyvsp[-2].str), line_num);
            }
            char* temp = nextTemp();
            Quadruple* quad = createQuadruple(QuadOp_ASSIGN, (yyvsp[0].str), NULL, temp);
            addQuadruple(quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup((yyvsp[-2].str)));
            addQuadruple(assign);
            (yyval.str) = strdup((yyvsp[-2].str));

        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1679 "parser/parser.tab.c"
    break;

  case 78: /* assign_expr: ID ADD_ASSIGN assign_expr  */
#line 397 "parser/parser.y"
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym) {
            mark_symbol_used(current_scope, (yyvsp[-2].str));
            mark_symbol_initialized(current_scope, (yyvsp[-2].str));
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        (yyvsp[-2].str), line_num);
            }
            char* temp = nextTemp();
            Quadruple* add_quad = createQuadruple(QuadOp_ADD, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
            addQuadruple(add_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup((yyvsp[-2].str)));
            addQuadruple(assign);
            (yyval.str) = strdup((yyvsp[-2].str));

        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1708 "parser/parser.tab.c"
    break;

  case 79: /* assign_expr: ID SUB_ASSIGN assign_expr  */
#line 422 "parser/parser.y"
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym) {
            mark_symbol_used(current_scope, (yyvsp[-2].str));
            mark_symbol_initialized(current_scope, (yyvsp[-2].str));
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        (yyvsp[-2].str), line_num);
            }
            char* temp = nextTemp();
            Quadruple* sub_quad = createQuadruple(QuadOp_SUB, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
            addQuadruple(sub_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup((yyvsp[-2].str)));
            addQuadruple(assign);
            (yyval.str) = strdup((yyvsp[-2].str));

        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1737 "parser/parser.tab.c"
    break;

  case 80: /* assign_expr: ID MUL_ASSIGN assign_expr  */
#line 447 "parser/parser.y"
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym) {
            mark_symbol_used(current_scope, (yyvsp[-2].str));
            mark_symbol_initialized(current_scope, (yyvsp[-2].str));
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        (yyvsp[-2].str), line_num);
            }
            char* temp = nextTemp();
            Quadruple* mul_quad = createQuadruple(QuadOp_MUL, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
            addQuadruple(mul_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup((yyvsp[-2].str)));
            addQuadruple(assign);
            (yyval.str) = strdup((yyvsp[-2].str));

        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1766 "parser/parser.tab.c"
    break;

  case 81: /* assign_expr: ID DIV_ASSIGN assign_expr  */
#line 472 "parser/parser.y"
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym) {
            mark_symbol_used(current_scope, (yyvsp[-2].str));
            mark_symbol_initialized(current_scope, (yyvsp[-2].str));
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        (yyvsp[-2].str), line_num);
            }
            char* temp = nextTemp();
            Quadruple* div_quad = createQuadruple(QuadOp_DIV, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
            addQuadruple(div_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup((yyvsp[-2].str)));
            addQuadruple(assign);
            (yyval.str) = strdup((yyvsp[-2].str));

        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1795 "parser/parser.tab.c"
    break;

  case 82: /* assign_expr: ID MOD_ASSIGN assign_expr  */
#line 497 "parser/parser.y"
    {
        // Mark variable as used and initialized
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym) {
            mark_symbol_used(current_scope, (yyvsp[-2].str));
            mark_symbol_initialized(current_scope, (yyvsp[-2].str));
            
            // Check if trying to modify a constant
            if (sym->is_const) {
                fprintf(stderr, "Error: Cannot modify const variable '%s' at line %d\n", 
                        (yyvsp[-2].str), line_num);
            }
            char* temp = nextTemp();
            Quadruple* mod_quad = createQuadruple(QuadOp_MOD, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
            addQuadruple(mod_quad);

            Quadruple* assign = createQuadruple(QuadOp_ASSIGN, temp, NULL, strdup((yyvsp[-2].str)));
            addQuadruple(assign);
            (yyval.str) = strdup((yyvsp[-2].str));

        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1824 "parser/parser.tab.c"
    break;

  case 84: /* conditional_expr: logical_or_expr QUESTION expr COLON conditional_expr  */
#line 525 "parser/parser.y"
    {
        char* temp = nextTemp();
        char* label_true = nextLabel();
        char* label_false = nextLabel();
        char* label_end = nextLabel();

        // Generate code for the conditional expression
        Quadruple* jmp_false = createQuadruple(QuadOp_JEQ, strdup((yyvsp[-4].str)), "0", label_false);
        addQuadruple(jmp_false);

        Quadruple* assign_true = createQuadruple(QuadOp_ASSIGN, strdup((yyvsp[-2].str)), NULL, temp);
        addQuadruple(assign_true);
        Quadruple* jmp_end = createQuadruple(QuadOp_JMP, label_end, NULL, NULL);
        addQuadruple(jmp_end);

        Quadruple* label_false_quad = createQuadruple(QuadOp_LABEL, label_false, NULL, NULL);
        addQuadruple(label_false_quad);

        Quadruple* assign_false = createQuadruple(QuadOp_ASSIGN, strdup((yyvsp[0].str)), NULL, temp);
        addQuadruple(assign_false);

        Quadruple* label_end_quad = createQuadruple(QuadOp_LABEL, label_end, NULL, NULL);
        addQuadruple(label_end_quad);

        (yyval.str) = temp;
    }
#line 1855 "parser/parser.tab.c"
    break;

  case 85: /* logical_expr: conditional_expr  */
#line 554 "parser/parser.y"
    {
        (yyval.str) = (yyvsp[0].str);
    }
#line 1863 "parser/parser.tab.c"
    break;

  case 86: /* logical_or_expr: logical_and_expr  */
#line 559 "parser/parser.y"
    {
        (yyval.str) = (yyvsp[0].str);
    }
#line 1871 "parser/parser.tab.c"
    break;

  case 87: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 563 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* or_quad = createQuadruple(QuadOp_OR, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(or_quad);
        (yyval.str) = temp;
    }
#line 1882 "parser/parser.tab.c"
    break;

  case 88: /* logical_and_expr: equality_expr  */
#line 572 "parser/parser.y"
    {
        (yyval.str) = (yyvsp[0].str);
    }
#line 1890 "parser/parser.tab.c"
    break;

  case 89: /* logical_and_expr: logical_and_expr AND equality_expr  */
#line 576 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* and_quad = createQuadruple(QuadOp_AND, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(and_quad);
        (yyval.str) = temp;
    }
#line 1901 "parser/parser.tab.c"
    break;

  case 90: /* equality_expr: relational_expr  */
#line 585 "parser/parser.y"
    {
        (yyval.str) = (yyvsp[0].str);
    }
#line 1909 "parser/parser.tab.c"
    break;

  case 91: /* equality_expr: equality_expr EQ relational_expr  */
#line 589 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* eq_quad = createQuadruple(QuadOp_EQ, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(eq_quad);
        (yyval.str) = temp;
    }
#line 1920 "parser/parser.tab.c"
    break;

  case 92: /* equality_expr: equality_expr NE relational_expr  */
#line 596 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* ne_quad = createQuadruple(QuadOp_NE, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(ne_quad);
        (yyval.str) = temp;
    }
#line 1931 "parser/parser.tab.c"
    break;

  case 93: /* relational_expr: additive_expr  */
#line 605 "parser/parser.y"
    {
        (yyval.str) = (yyvsp[0].str);
    }
#line 1939 "parser/parser.tab.c"
    break;

  case 94: /* relational_expr: relational_expr LT additive_expr  */
#line 609 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* lt_quad = createQuadruple(QuadOp_LT, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(lt_quad);
        (yyval.str) = temp;
    }
#line 1950 "parser/parser.tab.c"
    break;

  case 95: /* relational_expr: relational_expr GT additive_expr  */
#line 616 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* gt_quad = createQuadruple(QuadOp_GT, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(gt_quad);
        (yyval.str) = temp;
    }
#line 1961 "parser/parser.tab.c"
    break;

  case 96: /* relational_expr: relational_expr LE additive_expr  */
#line 623 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* le_quad = createQuadruple(QuadOp_LTE, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(le_quad);
        (yyval.str) = temp;
    }
#line 1972 "parser/parser.tab.c"
    break;

  case 97: /* relational_expr: relational_expr GE additive_expr  */
#line 630 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* ge_quad = createQuadruple(QuadOp_GTE, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(ge_quad);
        (yyval.str) = temp;
    }
#line 1983 "parser/parser.tab.c"
    break;

  case 99: /* additive_expr: additive_expr ADD multiplicative_expr  */
#line 641 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* add_quad = createQuadruple(QuadOp_ADD, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(add_quad);

        (yyval.str) = temp;

        printf("additive_expr: ADD\n");
    }
#line 1997 "parser/parser.tab.c"
    break;

  case 100: /* additive_expr: additive_expr SUBTRACT multiplicative_expr  */
#line 651 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* add_quad = createQuadruple(QuadOp_SUB, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(add_quad);

        (yyval.str) = temp;

        printf("additive_expr: ADD\n");
    }
#line 2011 "parser/parser.tab.c"
    break;

  case 101: /* multiplicative_expr: unary_expr  */
#line 663 "parser/parser.y"
    {
        (yyval.str) = (yyvsp[0].str);
    }
#line 2019 "parser/parser.tab.c"
    break;

  case 102: /* multiplicative_expr: multiplicative_expr MULTIPLY unary_expr  */
#line 667 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* mul_quad = createQuadruple(QuadOp_MUL, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(mul_quad);

        (yyval.str) = temp;

        printf("multiplicative_expr: MUL\n");
    }
#line 2033 "parser/parser.tab.c"
    break;

  case 103: /* multiplicative_expr: multiplicative_expr DIVIDE unary_expr  */
#line 677 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* div_quad = createQuadruple(QuadOp_DIV, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(div_quad);

        (yyval.str) = temp;

        printf("multiplicative_expr: DIV\n");
    }
#line 2047 "parser/parser.tab.c"
    break;

  case 104: /* multiplicative_expr: multiplicative_expr MODULO unary_expr  */
#line 687 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* mod_quad = createQuadruple(QuadOp_MOD, strdup((yyvsp[-2].str)), strdup((yyvsp[0].str)), temp);
        addQuadruple(mod_quad);

        (yyval.str) = temp;

        printf("multiplicative_expr: MOD\n");
    }
#line 2061 "parser/parser.tab.c"
    break;

  case 105: /* unary_expr: postfix_expr  */
#line 699 "parser/parser.y"
    { (yyval.str) = (yyvsp[0].str); }
#line 2067 "parser/parser.tab.c"
    break;

  case 106: /* unary_expr: UNARY unary_expr  */
#line 701 "parser/parser.y"
    { (yyval.str) = (yyvsp[0].str); }
#line 2073 "parser/parser.tab.c"
    break;

  case 107: /* unary_expr: SUBTRACT unary_expr  */
#line 703 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* neg_quad = createQuadruple(QuadOp_NEG, strdup((yyvsp[0].str)), NULL, temp);
        addQuadruple(neg_quad);
        (yyval.str) = temp;
    }
#line 2084 "parser/parser.tab.c"
    break;

  case 108: /* unary_expr: MULTIPLY unary_expr  */
#line 710 "parser/parser.y"
    { (yyval.str) = (yyvsp[0].str); }
#line 2090 "parser/parser.tab.c"
    break;

  case 109: /* unary_expr: NOT unary_expr  */
#line 712 "parser/parser.y"
    { (yyval.str) = (yyvsp[0].str); }
#line 2096 "parser/parser.tab.c"
    break;

  case 110: /* unary_expr: BIT_AND unary_expr  */
#line 714 "parser/parser.y"
    { (yyval.str) = (yyvsp[0].str); }
#line 2102 "parser/parser.tab.c"
    break;

  case 111: /* postfix_expr: primary_expr  */
#line 718 "parser/parser.y"
    {
        (yyval.str) = (yyvsp[0].str);
    }
#line 2110 "parser/parser.tab.c"
    break;

  case 112: /* postfix_expr: postfix_expr UNARY_INC  */
#line 723 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* assign_temp = createQuadruple(QuadOp_ASSIGN, strdup((yyvsp[-1].str)), NULL, temp);
        addQuadruple(assign_temp);

        Quadruple* increment = createQuadruple(QuadOp_ADD, strdup((yyvsp[-1].str)), strdup("1"), strdup((yyvsp[-1].str)));
        addQuadruple(increment);

        (yyval.str) = temp;
    }
#line 2125 "parser/parser.tab.c"
    break;

  case 113: /* postfix_expr: postfix_expr UNARY_DEC  */
#line 734 "parser/parser.y"
    {
        char* temp = nextTemp();
        Quadruple* assign_temp = createQuadruple(QuadOp_ASSIGN, strdup((yyvsp[-1].str)), NULL, temp);
        addQuadruple(assign_temp);

        Quadruple* decrement = createQuadruple(QuadOp_SUB, strdup((yyvsp[-1].str)), strdup("1"), strdup((yyvsp[-1].str)));
        addQuadruple(decrement);

        (yyval.str) = temp;
    }
#line 2140 "parser/parser.tab.c"
    break;

  case 114: /* primary_expr: ID  */
#line 747 "parser/parser.y"
    { 
        printf("primary_expr: ID = %s\n", (yyvsp[0].str));
        // Mark the symbol as used when referenced
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].str));
        if (sym) {
            mark_symbol_used(current_scope, (yyvsp[0].str));
            
            // Also check if it's been initialized
            if (!sym->is_initialized) {
                fprintf(stderr, "Warning: Variable '%s' used before initialization at line %d\n", 
                        (yyvsp[0].str), line_num);
            }
            (yyval.str) = strdup((yyvsp[0].str)); // Assign the identifier's name to $$
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[0].str), line_num);
            (yyval.str) = strdup("0"); // Or some default value, like "0"
        }
    }
#line 2163 "parser/parser.tab.c"
    break;

  case 115: /* primary_expr: NUMBER  */
#line 766 "parser/parser.y"
    {
        char* num_str = (char*)malloc(20);
        sprintf(num_str, "%d", (yyvsp[0].num));
        (yyval.str) = num_str;
    }
#line 2173 "parser/parser.tab.c"
    break;

  case 116: /* primary_expr: FLOAT_NUM  */
#line 772 "parser/parser.y"
    {
        char* float_str = (char*)malloc(50);
        sprintf(float_str, "%f", (yyvsp[0].fnum));
        (yyval.str) = float_str;
    }
#line 2183 "parser/parser.tab.c"
    break;

  case 117: /* primary_expr: STR  */
#line 778 "parser/parser.y"
    {
        (yyval.str) = strdup((yyvsp[0].str));
    }
#line 2191 "parser/parser.tab.c"
    break;

  case 118: /* primary_expr: CHAR_LITERAL  */
#line 782 "parser/parser.y"
    {
        (yyval.str) = strdup((yyvsp[0].str));
    }
#line 2199 "parser/parser.tab.c"
    break;

  case 119: /* primary_expr: TRUE  */
#line 786 "parser/parser.y"
    {
        (yyval.str) = strdup("1");
    }
#line 2207 "parser/parser.tab.c"
    break;

  case 120: /* primary_expr: FALSE  */
#line 790 "parser/parser.y"
    {
        (yyval.str) = strdup("0");
    }
#line 2215 "parser/parser.tab.c"
    break;

  case 121: /* primary_expr: NULL_TOKEN  */
#line 794 "parser/parser.y"
    {
        (yyval.str) = strdup("0");
    }
#line 2223 "parser/parser.tab.c"
    break;

  case 122: /* primary_expr: LPAREN expr RPAREN  */
#line 798 "parser/parser.y"
    {
        (yyval.str) = (yyvsp[-1].str);
    }
#line 2231 "parser/parser.tab.c"
    break;

  case 123: /* primary_expr: function_call  */
#line 802 "parser/parser.y"
    {
        (yyval.str) = strdup((yyvsp[0].str));
    }
#line 2239 "parser/parser.tab.c"
    break;

  case 124: /* function_call: ID LPAREN RPAREN  */
#line 808 "parser/parser.y"
    {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (!sym) {
            fprintf(stderr, "Error: Undeclared function '%s' at line %d\n", (yyvsp[-2].str), line_num);
        } else if (sym->kind != SYM_FUNCTION) {
            fprintf(stderr, "Error: '%s' is not a function at line %d\n", (yyvsp[-2].str), line_num);
        } else {
            mark_symbol_used(current_scope, (yyvsp[-2].str));
        }
    }
#line 2254 "parser/parser.tab.c"
    break;

  case 125: /* function_call: ID LPAREN arg_list RPAREN  */
#line 819 "parser/parser.y"
    {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-3].str));
        if (!sym) {
            fprintf(stderr, "Error: Undeclared function '%s' at line %d\n", (yyvsp[-3].str), line_num);
        } else if (sym->kind != SYM_FUNCTION) {
            fprintf(stderr, "Error: '%s' is not a function at line %d\n", (yyvsp[-3].str), line_num);
        } else {
            mark_symbol_used(current_scope, (yyvsp[-3].str));
        }
    }
#line 2269 "parser/parser.tab.c"
    break;

  case 130: /* const_declarator: ID ASSIGN expr  */
#line 841 "parser/parser.y"
    {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym) {
            fprintf(stderr, "Error: Const variable '%s' already declared at line %d\n", (yyvsp[-2].str), line_num);
        } else {
            // Type compatibility check for const initialization
            const char* left_type = current_type;
            const char* right_type = NULL;
            Symbol* right_sym = lookup_symbol(current_scope, (yyvsp[0].str));
                        if (right_sym) {
                right_type = right_sym->type;
            } else if ((yyvsp[0].str) && strlen((yyvsp[0].str)) == 3 && (yyvsp[0].str)[0] == '\'' && (yyvsp[0].str)[2] == '\'') {
                right_type = "char";
            } else if (is_number((yyvsp[0].str))) {
                right_type = "int";
            } else if (is_float((yyvsp[0].str))) {
                right_type = "float";
            } else {
                right_type = current_type; // fallback, but not ideal
            }

            if (!check_type_compatibility(left_type, right_type)) {
                fprintf(stderr, "Error: Type mismatch in assignment to '%s' at line %d ('%s' = '%s')\n",
                        (yyvsp[-2].str), line_num, left_type, right_type);
            }
            insert_symbol_in_scope(current_scope, (yyvsp[-2].str), current_type, SYM_VARIABLE, true, line_num);
            mark_symbol_initialized(current_scope, (yyvsp[-2].str));
            Quadruple* quad = createQuadruple(QuadOp_ASSIGN, (yyvsp[0].str), NULL, strdup((yyvsp[-2].str)));
            addQuadruple(quad);
        }
    }
#line 2305 "parser/parser.tab.c"
    break;

  case 131: /* const_declarator: MULTIPLY ID ASSIGN expr  */
#line 873 "parser/parser.y"
    {
        // Pointer const variable (optional: handle as needed)
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym) {
            fprintf(stderr, "Error: Const pointer variable '%s' already declared at line %d\n", (yyvsp[-2].str), line_num);
        } else {
            char pointer_type[50];
            snprintf(pointer_type, sizeof(pointer_type), "%s*", current_type);
            insert_symbol_in_scope(current_scope, (yyvsp[-2].str), pointer_type, SYM_VARIABLE, true, line_num);
            mark_symbol_initialized(current_scope, (yyvsp[-2].str));
        }
    }
#line 2322 "parser/parser.tab.c"
    break;

  case 134: /* declarator: ID  */
#line 893 "parser/parser.y"
    {
        // First check if already declared in current scope
        bool is_redeclaration = false;
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].str));
        
        if (sym) {
            // If found in current scope, it's a redeclaration
            if (sym->scope_depth == current_scope->depth) {
                fprintf(stderr, "Error: Redeclaration of '%s' at line %d (previously declared at line %d)\n", 
                        (yyvsp[0].str), line_num, sym->line_number);
                is_redeclaration = true;
            } 
            // If found in IMMEDIATE parent and it's a parameter, it's shadowing a parameter
            else if (sym->kind == SYM_PARAMETER && 
                     current_scope->parent && 
                     sym->scope_depth == current_scope->parent->depth &&
                     // Make sure we're still in the same function
                     strcmp(current_function, "") != 0 &&
                     strstr(sym->name, current_function) != NULL) {
                fprintf(stderr, "Error: Local variable '%s' at line %d shadows parameter declared at line %d\n", 
                        (yyvsp[0].str), line_num, sym->line_number);
                is_redeclaration = true;
            }
        }
        
        if (!is_redeclaration) {
            // Add variable to symbol table
            insert_symbol_in_scope(current_scope, (yyvsp[0].str), current_type, SYM_VARIABLE, is_const_declaration, line_num);
        }
    }
#line 2357 "parser/parser.tab.c"
    break;

  case 135: /* declarator: MULTIPLY declarator  */
#line 924 "parser/parser.y"
    {
        // ... (Implementation for pointer declaration) ...
    }
#line 2365 "parser/parser.tab.c"
    break;

  case 136: /* declarator: ID ASSIGN expr  */
#line 928 "parser/parser.y"
    {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].str));
        if (sym && sym->scope_depth == current_scope->depth) {
            fprintf(stderr, "Error: Variable '%s' already declared at line %d\n", (yyvsp[-2].str), line_num);
        } else {
            // Type compatibility check for initialization
            const char* left_type = current_type;
            const char* right_type = NULL;
            Symbol* right_sym = lookup_symbol(current_scope, (yyvsp[0].str));
                        if (right_sym) {
                right_type = right_sym->type;
            } else if ((yyvsp[0].str) && strlen((yyvsp[0].str)) == 3 && (yyvsp[0].str)[0] == '\'' && (yyvsp[0].str)[2] == '\'') {
                right_type = "char";
            } else if (is_number((yyvsp[0].str))) {
                right_type = "int";
            } else if (is_float((yyvsp[0].str))) {
                right_type = "float";
            } else {
                right_type = current_type; // fallback, but not ideal
            }

            if (!check_type_compatibility(left_type, right_type)) {
                fprintf(stderr, "Error: Type mismatch in assignment to '%s' at line %d ('%s' = '%s')\n",
                        (yyvsp[-2].str), line_num, left_type, right_type);
            }
            insert_symbol_in_scope(current_scope, (yyvsp[-2].str), current_type, SYM_VARIABLE, is_const_declaration, line_num);
            mark_symbol_initialized(current_scope, (yyvsp[-2].str));
            Quadruple* quad = createQuadruple(QuadOp_ASSIGN, (yyvsp[0].str), NULL, strdup((yyvsp[-2].str)));
            addQuadruple(quad);
        }
    }
#line 2401 "parser/parser.tab.c"
    break;

  case 137: /* declarator: ID LBRACKET primary_expr RBRACKET  */
#line 960 "parser/parser.y"
    {
        // Array declaration (optional: handle array size/type)
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-3].str));
        if (sym) {
            fprintf(stderr, "Error: Array '%s' already declared at line %d\n", (yyvsp[-3].str), line_num);
        } else {
            char array_type[50];
            snprintf(array_type, sizeof(array_type), "%s[]", current_type);
            insert_symbol_in_scope(current_scope, (yyvsp[-3].str), array_type, SYM_VARIABLE, is_const_declaration, line_num);
        }
    }
#line 2417 "parser/parser.tab.c"
    break;

  case 138: /* declarator: ID LBRACKET primary_expr RBRACKET ASSIGN expr  */
#line 972 "parser/parser.y"
    {
        // Array declaration with initialization (optional: handle as needed)
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-5].str));
        if (sym) {
            fprintf(stderr, "Error: Array '%s' already declared at line %d\n", (yyvsp[-5].str), line_num);
        } else {
            char array_type[50];
            snprintf(array_type, sizeof(array_type), "%s[]", current_type);
            insert_symbol_in_scope(current_scope, (yyvsp[-5].str), array_type, SYM_VARIABLE, is_const_declaration, line_num);
            mark_symbol_initialized(current_scope, (yyvsp[-5].str));
        }
    }
#line 2434 "parser/parser.tab.c"
    break;


#line 2438 "parser/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 989 "parser/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", line_num, s);
}

int main() {
    printf("Parsing started...\n");
    int result = yyparse();
    if (result == 0) {
        printf("Parsing completed successfully.\n");
    }
    printQuadruples();
    return result;
}
