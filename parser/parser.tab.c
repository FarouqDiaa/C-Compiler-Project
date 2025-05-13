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

void yyerror(const char *s);
int yylex();
int yywrap();

extern int line_num;

Scope* current_scope = NULL;
bool is_const_declaration = false;
char current_type[50];
char current_function[50] = "";

#line 90 "parser/parser.tab.c"

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
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_STR = 6,                        /* STR  */
  YYSYMBOL_CHAR_LITERAL = 7,               /* CHAR_LITERAL  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_DO = 12,                        /* DO  */
  YYSYMBOL_SWITCH = 13,                    /* SWITCH  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_FLOAT = 19,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 20,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 21,                      /* CHAR  */
  YYSYMBOL_VOID = 22,                      /* VOID  */
  YYSYMBOL_CONST = 23,                     /* CONST  */
  YYSYMBOL_TRUE = 24,                      /* TRUE  */
  YYSYMBOL_FALSE = 25,                     /* FALSE  */
  YYSYMBOL_PRINTFF = 26,                   /* PRINTFF  */
  YYSYMBOL_SCANFF = 27,                    /* SCANFF  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_INCLUDE = 29,                   /* INCLUDE  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NE = 32,                        /* NE  */
  YYSYMBOL_LE = 33,                        /* LE  */
  YYSYMBOL_GE = 34,                        /* GE  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_LT = 36,                        /* LT  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_NOT = 39,                       /* NOT  */
  YYSYMBOL_ADD = 40,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 41,                  /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 42,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 43,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 44,                    /* MODULO  */
  YYSYMBOL_UNARY = 45,                     /* UNARY  */
  YYSYMBOL_SEMI = 46,                      /* SEMI  */
  YYSYMBOL_NULL_TOKEN = 47,                /* NULL_TOKEN  */
  YYSYMBOL_LBRACE = 48,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 49,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 50,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 51,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 52,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 53,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 54,                     /* COMMA  */
  YYSYMBOL_COLON = 55,                     /* COLON  */
  YYSYMBOL_QUESTION = 56,                  /* QUESTION  */
  YYSYMBOL_BIT_AND = 57,                   /* BIT_AND  */
  YYSYMBOL_ADD_ASSIGN = 58,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 59,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 60,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 61,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 62,                /* MOD_ASSIGN  */
  YYSYMBOL_LOWER_THAN_ELSE = 63,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_program = 65,                   /* program  */
  YYSYMBOL_66_1 = 66,                      /* $@1  */
  YYSYMBOL_translation_unit = 67,          /* translation_unit  */
  YYSYMBOL_external_declaration = 68,      /* external_declaration  */
  YYSYMBOL_include_directive = 69,         /* include_directive  */
  YYSYMBOL_function_prototype = 70,        /* function_prototype  */
  YYSYMBOL_function_definition = 71,       /* function_definition  */
  YYSYMBOL_function_header = 72,           /* function_header  */
  YYSYMBOL_parameter_list = 73,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 74,     /* parameter_declaration  */
  YYSYMBOL_compound_stmt = 75,             /* compound_stmt  */
  YYSYMBOL_76_2 = 76,                      /* $@2  */
  YYSYMBOL_datatype = 77,                  /* datatype  */
  YYSYMBOL_stmt_list = 78,                 /* stmt_list  */
  YYSYMBOL_stmt = 79,                      /* stmt  */
  YYSYMBOL_if_stmt = 80,                   /* if_stmt  */
  YYSYMBOL_for_stmt = 81,                  /* for_stmt  */
  YYSYMBOL_82_3 = 82,                      /* $@3  */
  YYSYMBOL_for_init = 83,                  /* for_init  */
  YYSYMBOL_for_cond = 84,                  /* for_cond  */
  YYSYMBOL_for_update = 85,                /* for_update  */
  YYSYMBOL_while_stmt = 86,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 87,             /* do_while_stmt  */
  YYSYMBOL_expr_stmt = 88,                 /* expr_stmt  */
  YYSYMBOL_switch_stmt = 89,               /* switch_stmt  */
  YYSYMBOL_case_list = 90,                 /* case_list  */
  YYSYMBOL_case_stmt = 91,                 /* case_stmt  */
  YYSYMBOL_default_stmt = 92,              /* default_stmt  */
  YYSYMBOL_break_stmt = 93,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 94,             /* continue_stmt  */
  YYSYMBOL_decl_stmt = 95,                 /* decl_stmt  */
  YYSYMBOL_print_stmt = 96,                /* print_stmt  */
  YYSYMBOL_print_args = 97,                /* print_args  */
  YYSYMBOL_arg_list = 98,                  /* arg_list  */
  YYSYMBOL_scan_stmt = 99,                 /* scan_stmt  */
  YYSYMBOL_expr = 100,                     /* expr  */
  YYSYMBOL_assign_expr = 101,              /* assign_expr  */
  YYSYMBOL_conditional_expr = 102,         /* conditional_expr  */
  YYSYMBOL_logical_expr = 103,             /* logical_expr  */
  YYSYMBOL_logical_or_expr = 104,          /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 105,         /* logical_and_expr  */
  YYSYMBOL_equality_expr = 106,            /* equality_expr  */
  YYSYMBOL_relational_expr = 107,          /* relational_expr  */
  YYSYMBOL_additive_expr = 108,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 109,      /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 110,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 111,             /* postfix_expr  */
  YYSYMBOL_primary_expr = 112,             /* primary_expr  */
  YYSYMBOL_function_call = 113,            /* function_call  */
  YYSYMBOL_declaration = 114,              /* declaration  */
  YYSYMBOL_const_declarator_list = 115,    /* const_declarator_list  */
  YYSYMBOL_const_declarator = 116,         /* const_declarator  */
  YYSYMBOL_declarator_list = 117,          /* declarator_list  */
  YYSYMBOL_declarator = 118,               /* declarator  */
  YYSYMBOL_return_stmt = 119               /* return_stmt  */
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
#define YYLAST   432

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  253

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    68,    79,    80,    84,    85,    86,    87,
      91,    95,    96,   100,   101,   105,   114,   115,   119,   126,
     134,   142,   155,   154,   166,   167,   168,   169,   170,   173,
     174,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   192,   193,   198,   197,   210,   211,
     212,   215,   216,   219,   220,   223,   226,   229,   232,   235,
     236,   237,   240,   243,   246,   249,   252,   255,   258,   259,
     262,   263,   266,   269,   272,   273,   290,   307,   324,   341,
     358,   375,   394,   395,   398,   401,   402,   405,   406,   409,
     410,   411,   414,   415,   416,   417,   418,   421,   422,   423,
     426,   427,   428,   429,   432,   433,   434,   435,   436,   437,
     440,   441,   444,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   471,   472,   475,   476,   479,   480,   484,   490,
     493,   494,   498,   511,   512,   513,   514,   517,   518
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
  "ID", "STR", "CHAR_LITERAL", "IF", "ELSE", "WHILE", "FOR", "DO",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "INT", "FLOAT",
  "DOUBLE", "CHAR", "VOID", "CONST", "TRUE", "FALSE", "PRINTFF", "SCANFF",
  "RETURN", "INCLUDE", "ASSIGN", "EQ", "NE", "LE", "GE", "GT", "LT", "AND",
  "OR", "NOT", "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE", "MODULO", "UNARY",
  "SEMI", "NULL_TOKEN", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "COMMA", "COLON", "QUESTION", "BIT_AND", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "LOWER_THAN_ELSE", "$accept", "program", "$@1", "translation_unit",
  "external_declaration", "include_directive", "function_prototype",
  "function_definition", "function_header", "parameter_list",
  "parameter_declaration", "compound_stmt", "$@2", "datatype", "stmt_list",
  "stmt", "if_stmt", "for_stmt", "$@3", "for_init", "for_cond",
  "for_update", "while_stmt", "do_while_stmt", "expr_stmt", "switch_stmt",
  "case_list", "case_stmt", "default_stmt", "break_stmt", "continue_stmt",
  "decl_stmt", "print_stmt", "print_args", "arg_list", "scan_stmt", "expr",
  "assign_expr", "conditional_expr", "logical_expr", "logical_or_expr",
  "logical_and_expr", "equality_expr", "relational_expr", "additive_expr",
  "multiplicative_expr", "unary_expr", "postfix_expr", "primary_expr",
  "function_call", "declaration", "const_declarator_list",
  "const_declarator", "declarator_list", "declarator", "return_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-171)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-16)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -171,    29,   150,  -171,  -171,  -171,  -171,  -171,  -171,   137,
    -171,   150,  -171,  -171,  -171,  -171,   -15,    -3,    43,    19,
    -171,    91,     0,    21,    40,  -171,  -171,    88,   115,    70,
    -171,   137,    34,   -29,  -171,    22,   327,    12,     1,  -171,
      21,   327,    93,    19,    27,  -171,  -171,  -171,    69,   168,
    -171,   126,  -171,  -171,   102,  -171,  -171,  -171,  -171,   351,
     351,   375,   351,  -171,   327,   351,  -171,  -171,  -171,  -171,
      16,   112,    14,   100,    30,   101,  -171,   108,  -171,  -171,
     124,   122,  -171,  -171,   327,  -171,  -171,   171,  -171,  -171,
    -171,  -171,  -171,   327,   272,   327,   327,   327,   327,   327,
     351,  -171,  -171,   -16,  -171,  -171,   130,  -171,   351,   327,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,  -171,   147,  -171,  -171,    80,  -171,  -171,    24,
    -171,  -171,  -171,  -171,  -171,  -171,   327,  -171,   112,   127,
      14,   100,   100,    30,    30,    30,    30,   101,   101,  -171,
    -171,  -171,   327,   133,   134,   142,   200,   143,   148,   149,
     146,   159,   296,  -171,  -171,    21,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,   151,   152,
    -171,  -171,   327,  -171,   351,  -171,   327,   327,  -171,   190,
     327,  -171,  -171,   208,   209,  -171,   183,  -171,  -171,  -171,
    -171,   179,   180,   248,   182,   184,   186,   189,  -171,   200,
     200,   187,  -171,  -171,   327,   188,   327,   193,   177,   228,
    -171,   327,   195,  -171,   202,   192,   244,   200,   212,  -171,
     213,     6,  -171,   210,  -171,   327,  -171,   327,   205,  -171,
    -171,  -171,   216,   214,  -171,   219,  -171,  -171,   200,  -171,
     200,  -171,   200
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    24,    25,    27,    26,    28,     0,
      10,     3,     4,     9,     8,     6,     0,     0,     0,     0,
       5,     0,   132,     0,   124,   130,     7,     0,     0,   125,
     126,     0,     0,     0,    16,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,    12,    22,    14,     0,     0,
      18,     0,   113,   114,   112,   115,   116,   117,   118,     0,
       0,     0,     0,   119,     0,     0,   134,    73,    84,    74,
      82,    85,    87,    89,    92,    97,   100,   104,   110,   121,
     112,     0,   131,   128,     0,   127,    20,     0,    29,    11,
      13,    17,    19,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   106,   112,   107,   105,     0,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   135,   129,    21,     0,    75,   122,     0,
      70,    77,    78,    79,    80,    81,     0,   120,    86,     0,
      88,    90,    91,    95,    96,    94,    93,    98,    99,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    31,     0,    30,    32,    33,    34,
      35,    37,    36,    42,    43,    38,    39,    40,     0,     0,
      41,   123,     0,    76,     0,   136,     0,     0,    46,     0,
       0,    64,    65,     0,     0,   138,     0,    57,    66,    71,
      83,     0,     0,    48,     0,     0,    68,     0,   137,     0,
       0,     0,    49,    50,     0,     0,     0,     0,     0,    44,
      55,    51,     0,    59,    69,     0,     0,     0,     0,    52,
       0,     0,    67,     0,    45,    53,    56,     0,     0,    58,
      60,    61,     0,     0,    54,     0,    29,    72,     0,    29,
      63,    47,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,   252,  -171,  -171,  -171,  -171,  -171,
     215,    17,  -171,     2,  -170,  -153,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,    64,  -171,   -36,   -55,    97,  -171,
    -171,   174,   173,    36,    25,    48,   -53,  -171,   247,  -171,
      -1,  -171,   242,  -171,    37,  -171
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    11,    12,    13,    14,    15,    16,    33,
      34,   164,    88,   165,   126,   166,   167,   168,   203,   211,
     228,   243,   169,   170,   171,   172,   231,   240,   241,   173,
     174,   175,   176,   217,   129,   177,   178,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
     179,    29,    30,    24,    25,   180
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    18,    22,   189,    17,    83,   101,   102,   104,   105,
      18,    19,   107,    17,   136,    52,    53,    80,    55,    56,
     237,   238,    48,    35,    27,    49,    38,    50,   106,     3,
      36,    36,    86,    44,    94,    21,    57,    58,   127,    23,
     131,   132,   133,   134,   135,   111,   112,   104,   124,    47,
     -15,    35,    37,    37,   108,   239,   219,   220,   130,    63,
      39,    28,    64,    23,    51,    90,   149,   150,   151,    87,
     117,   118,   109,   139,   234,   181,   250,    82,   182,   252,
      45,   183,    46,    52,    53,    54,    55,    56,   153,    26,
     154,   155,   156,   157,    40,   251,   158,   159,     4,     5,
       6,     7,     8,     9,    57,    58,   160,   161,   162,     4,
       5,     6,     7,     8,    31,    89,   185,    46,    41,    59,
      42,    60,    61,    84,    43,    62,   196,    63,    46,   163,
      64,    92,    93,   113,   114,   115,   116,    65,   143,   144,
     145,   146,    32,   119,   120,   121,   199,   141,   142,   110,
     201,   202,    94,   122,   205,     4,     5,     6,     7,     8,
      95,    96,    97,    98,    99,   147,   148,   212,     4,     5,
       6,     7,     8,     9,    94,   123,   125,   152,   222,    10,
     130,   137,   184,   186,   187,   229,     4,     5,     6,     7,
       8,    31,   188,   190,   191,   192,   193,   197,   198,   244,
     204,   245,   213,    52,    53,    54,    55,    56,   153,   194,
     154,   155,   156,   157,   206,   207,   158,   159,     4,     5,
       6,     7,     8,     9,    57,    58,   160,   161,   162,   208,
     209,   210,   214,   221,   226,   215,   223,   227,   232,    59,
     216,    60,    61,   218,   225,    62,   230,    63,    46,   233,
      64,    52,    53,    54,    55,    56,   182,    65,   235,   236,
     246,   242,   247,    20,    91,   248,     4,     5,     6,     7,
       8,     9,    57,    58,   249,    52,    53,    54,    55,    56,
     224,   200,   138,   140,    81,    85,     0,    59,     0,    60,
      61,     0,     0,    62,     0,    63,    57,    58,    64,    52,
      53,    54,    55,    56,     0,    65,     0,     0,     0,     0,
       0,    59,     0,    60,    61,     0,     0,    62,     0,    63,
      57,    58,    64,   128,     0,     0,     0,     0,     0,    65,
      52,    53,    54,    55,    56,    59,     0,    60,    61,     0,
       0,    62,   195,    63,     0,     0,    64,     0,     0,     0,
       0,    57,    58,    65,    52,    53,    80,    55,    56,     0,
       0,     0,     0,     0,     0,     0,    59,     0,    60,    61,
       0,     0,    62,     0,    63,    57,    58,    64,    52,    53,
     103,    55,    56,     0,    65,     0,     0,     0,     0,     0,
      59,     0,    60,   100,     0,     0,    62,     0,    63,    57,
      58,    64,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,    59,     0,    60,   100,     0,     0,
      62,     0,    63,     0,     0,    64,     0,     0,     0,     0,
       0,     0,    65
};

static const yytype_int16 yycheck[] =
{
      36,     2,     5,   156,     2,    41,    59,    60,    61,    62,
      11,     9,    65,    11,    30,     3,     4,     5,     6,     7,
      14,    15,    51,    21,     5,    54,     5,     5,    64,     0,
      30,    30,     5,    31,    50,    50,    24,    25,    93,    42,
      95,    96,    97,    98,    99,    31,    32,   100,    84,    32,
      50,    49,    52,    52,    38,    49,   209,   210,    94,    47,
      23,    42,    50,    42,    42,    48,   119,   120,   121,    42,
      40,    41,    56,   109,   227,    51,   246,    40,    54,   249,
      46,   136,    48,     3,     4,     5,     6,     7,     8,    46,
      10,    11,    12,    13,    54,   248,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    18,
      19,    20,    21,    22,    23,    46,   152,    48,    30,    39,
       5,    41,    42,    30,    54,    45,   162,    47,    48,    49,
      50,     5,    30,    33,    34,    35,    36,    57,   113,   114,
     115,   116,    51,    42,    43,    44,   182,   111,   112,    37,
     186,   187,    50,    45,   190,    18,    19,    20,    21,    22,
      58,    59,    60,    61,    62,   117,   118,   203,    18,    19,
      20,    21,    22,    23,    50,    53,     5,    30,   214,    29,
     216,    51,    55,    50,    50,   221,    18,    19,    20,    21,
      22,    23,    50,    50,    46,    46,    50,    46,    46,   235,
      10,   237,   203,     3,     4,     5,     6,     7,     8,    50,
      10,    11,    12,    13,     6,     6,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    46,
      51,    51,    50,    46,    57,    51,    48,     9,    46,    39,
      54,    41,    42,    54,    51,    45,    51,    47,    48,     5,
      50,     3,     4,     5,     6,     7,    54,    57,    46,    46,
      55,    51,    46,    11,    49,    51,    18,    19,    20,    21,
      22,    23,    24,    25,    55,     3,     4,     5,     6,     7,
     216,   184,   108,   110,    37,    43,    -1,    39,    -1,    41,
      42,    -1,    -1,    45,    -1,    47,    24,    25,    50,     3,
       4,     5,     6,     7,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    -1,    -1,    45,    -1,    47,
      24,    25,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
       3,     4,     5,     6,     7,    39,    -1,    41,    42,    -1,
      -1,    45,    46,    47,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    24,    25,    57,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,
      -1,    -1,    45,    -1,    47,    24,    25,    50,     3,     4,
       5,     6,     7,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    41,    42,    -1,    -1,    45,    -1,    47,    24,
      25,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    41,    42,    -1,    -1,
      45,    -1,    47,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,     0,    18,    19,    20,    21,    22,    23,
      29,    67,    68,    69,    70,    71,    72,    77,   114,    77,
      68,    50,     5,    42,   117,   118,    46,     5,    42,   115,
     116,    23,    51,    73,    74,    77,    30,    52,     5,   118,
      54,    30,     5,    54,    77,    46,    48,    75,    51,    54,
       5,    42,     3,     4,     5,     6,     7,    24,    25,    39,
      41,    42,    45,    47,    50,    57,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       5,   112,   118,   100,    30,   116,     5,    42,    76,    46,
      75,    74,     5,    30,    50,    58,    59,    60,    61,    62,
      42,   110,   110,     5,   110,   110,   100,   110,    38,    56,
      37,    31,    32,    33,    34,    35,    36,    40,    41,    42,
      43,    44,    45,    53,   100,     5,    78,   101,    51,    98,
     100,   101,   101,   101,   101,   101,    30,    51,   105,   100,
     106,   107,   107,   108,   108,   108,   108,   109,   109,   110,
     110,   110,    30,     8,    10,    11,    12,    13,    16,    17,
      26,    27,    28,    49,    75,    77,    79,    80,    81,    86,
      87,    88,    89,    93,    94,    95,    96,    99,   100,   114,
     119,    51,    54,   101,    55,   100,    50,    50,    50,    79,
      50,    46,    46,    50,    50,    46,   100,    46,    46,   100,
     102,   100,   100,    82,    10,   100,     6,     6,    46,    51,
      51,    83,   100,   114,    50,    51,    54,    97,    54,    79,
      79,    46,   100,    48,    98,    51,    57,     9,    84,   100,
      51,    90,    46,     5,    79,    46,    46,    14,    15,    49,
      91,    92,    51,    85,   100,   100,    55,    46,    51,    55,
      78,    79,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    66,    65,    67,    67,    68,    68,    68,    68,
      69,    70,    70,    71,    71,    72,    73,    73,    74,    74,
      74,    74,    76,    75,    77,    77,    77,    77,    77,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    82,    81,    83,    83,
      83,    84,    84,    85,    85,    86,    87,    88,    89,    90,
      90,    90,    91,    92,    93,    94,    95,    96,    97,    97,
      98,    98,    99,   100,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   103,   104,   104,   105,   105,   106,
     106,   106,   107,   107,   107,   107,   107,   108,   108,   108,
     109,   109,   109,   109,   110,   110,   110,   110,   110,   110,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   118,   118,   118,   119,   119
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     2,     1,     1,
       1,     5,     4,     5,     4,     2,     1,     3,     2,     3,
       3,     4,     0,     4,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     0,    10,     0,     1,
       1,     0,     1,     0,     1,     5,     7,     2,     7,     0,
       2,     2,     4,     3,     2,     2,     2,     6,     0,     2,
       1,     3,     8,     1,     1,     3,     4,     3,     3,     3,
       3,     3,     1,     5,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     4,     2,     3,     1,     3,     3,     4,
       1,     3,     1,     2,     3,     4,     6,     3,     2
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
#line 68 "parser/parser.y"
    {
        current_scope = create_scope(NULL, SCOPE_GLOBAL);
    }
#line 1420 "parser/parser.tab.c"
    break;

  case 3: /* program: $@1 translation_unit  */
#line 72 "parser/parser.y"
    {
        check_unused_symbols(current_scope);
        print_symbol_table(current_scope);
    }
#line 1429 "parser/parser.tab.c"
    break;

  case 15: /* function_header: datatype ID  */
#line 106 "parser/parser.y"
    {
        strncpy(current_function, (yyvsp[0].str), sizeof(current_function) - 1);
        insert_symbol_in_scope(current_scope, (yyvsp[0].str), current_type, SYM_FUNCTION, false, line_num);
    }
#line 1438 "parser/parser.tab.c"
    break;

  case 18: /* parameter_declaration: datatype ID  */
#line 120 "parser/parser.y"
    {
        // Add parameter to symbol table
        insert_symbol_in_scope(current_scope, (yyvsp[0].str), current_type, SYM_PARAMETER, false, line_num);
        // Parameters are considered initialized
        mark_symbol_initialized(current_scope, (yyvsp[0].str));
    }
#line 1449 "parser/parser.tab.c"
    break;

  case 19: /* parameter_declaration: datatype MULTIPLY ID  */
#line 127 "parser/parser.y"
    {
        // Add pointer parameter
        char pointer_type[50];
        snprintf(pointer_type, sizeof(pointer_type), "%s*", current_type);
        insert_symbol_in_scope(current_scope, (yyvsp[0].str), pointer_type, SYM_PARAMETER, false, line_num);
        mark_symbol_initialized(current_scope, (yyvsp[0].str));
    }
#line 1461 "parser/parser.tab.c"
    break;

  case 20: /* parameter_declaration: CONST datatype ID  */
#line 135 "parser/parser.y"
    {
        // Add const parameter
        char const_type[50];
        snprintf(const_type, sizeof(const_type), "const %s", current_type);
        insert_symbol_in_scope(current_scope, (yyvsp[0].str), const_type, SYM_PARAMETER, true, line_num);
        mark_symbol_initialized(current_scope, (yyvsp[0].str));
    }
#line 1473 "parser/parser.tab.c"
    break;

  case 21: /* parameter_declaration: CONST datatype MULTIPLY ID  */
#line 143 "parser/parser.y"
    {
        // Add const pointer parameter
        char const_pointer_type[50];
        snprintf(const_pointer_type, sizeof(const_pointer_type), "const %s*", current_type);
        insert_symbol_in_scope(current_scope, (yyvsp[0].str), const_pointer_type, SYM_PARAMETER, true, line_num);
        mark_symbol_initialized(current_scope, (yyvsp[0].str));
    }
#line 1485 "parser/parser.tab.c"
    break;

  case 22: /* $@2: %empty  */
#line 155 "parser/parser.y"
    {
        // Create a new scope for compound statement
        current_scope = enter_scope(current_scope, SCOPE_LOCAL);
    }
#line 1494 "parser/parser.tab.c"
    break;

  case 23: /* compound_stmt: LBRACE $@2 stmt_list RBRACE  */
#line 160 "parser/parser.y"
    {
        // Exit compound statement scope
        current_scope = exit_scope(current_scope);
    }
#line 1503 "parser/parser.tab.c"
    break;

  case 46: /* $@3: %empty  */
#line 198 "parser/parser.y"
    {
        // Create a new scope for the for loop and its init statement
        current_scope = enter_scope(current_scope, SCOPE_LOCAL);
    }
#line 1512 "parser/parser.tab.c"
    break;

  case 47: /* for_stmt: FOR LPAREN $@3 for_init SEMI for_cond SEMI for_update RPAREN stmt  */
#line 203 "parser/parser.y"
    {
        // Exit the for loop scope
        print_symbol_table(current_scope);
        current_scope = exit_scope(current_scope);
    }
#line 1522 "parser/parser.tab.c"
    break;

  case 75: /* assign_expr: ID ASSIGN assign_expr  */
#line 274 "parser/parser.y"
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
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1543 "parser/parser.tab.c"
    break;

  case 76: /* assign_expr: MULTIPLY ID ASSIGN assign_expr  */
#line 291 "parser/parser.y"
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
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1564 "parser/parser.tab.c"
    break;

  case 77: /* assign_expr: ID ADD_ASSIGN assign_expr  */
#line 308 "parser/parser.y"
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
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1585 "parser/parser.tab.c"
    break;

  case 78: /* assign_expr: ID SUB_ASSIGN assign_expr  */
#line 325 "parser/parser.y"
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
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1606 "parser/parser.tab.c"
    break;

  case 79: /* assign_expr: ID MUL_ASSIGN assign_expr  */
#line 342 "parser/parser.y"
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
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1627 "parser/parser.tab.c"
    break;

  case 80: /* assign_expr: ID DIV_ASSIGN assign_expr  */
#line 359 "parser/parser.y"
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
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1648 "parser/parser.tab.c"
    break;

  case 81: /* assign_expr: ID MOD_ASSIGN assign_expr  */
#line 376 "parser/parser.y"
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
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[-2].str), line_num);
        }
    }
#line 1669 "parser/parser.tab.c"
    break;

  case 112: /* primary_expr: ID  */
#line 445 "parser/parser.y"
    {
        // Mark the symbol as used when referenced
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].str));
        if (sym) {
            mark_symbol_used(current_scope, (yyvsp[0].str));
            
            // Also check if it's been initialized
            if (!sym->is_initialized) {
                fprintf(stderr, "Warning: Variable '%s' used before initialization at line %d\n", 
                        (yyvsp[0].str), line_num);
            }
        } else {
            fprintf(stderr, "Error: Undeclared identifier '%s' at line %d\n", (yyvsp[0].str), line_num);
        }
    }
#line 1689 "parser/parser.tab.c"
    break;

  case 128: /* const_declarator: ID ASSIGN expr  */
#line 485 "parser/parser.y"
    {
        // Add const variable to symbol table and mark as initialized
        insert_symbol_in_scope(current_scope, (yyvsp[-2].str), current_type, SYM_VARIABLE, true, line_num);
        mark_symbol_initialized(current_scope, (yyvsp[-2].str));
    }
#line 1699 "parser/parser.tab.c"
    break;

  case 132: /* declarator: ID  */
#line 499 "parser/parser.y"
    {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].str));
        if (sym) {
           
            fprintf(stderr, "error: Variable '%s' is initialized before \n", 
                        (yyvsp[0].str));
            
        } else {
            // Add variable to symbol table
        insert_symbol_in_scope(current_scope, (yyvsp[0].str), current_type, SYM_VARIABLE, is_const_declaration, line_num);
        }
    }
#line 1716 "parser/parser.tab.c"
    break;


#line 1720 "parser/parser.tab.c"

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

#line 521 "parser/parser.y"


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
