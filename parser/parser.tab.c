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

void yyerror(const char *s);
int yylex();
int yywrap();

extern int line_num;

#line 84 "parser/parser.tab.c"

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
  YYSYMBOL_ADD = 39,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 40,                  /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 41,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 42,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 43,                    /* MODULO  */
  YYSYMBOL_UNARY = 44,                     /* UNARY  */
  YYSYMBOL_SEMI = 45,                      /* SEMI  */
  YYSYMBOL_NULL_TOKEN = 46,                /* NULL_TOKEN  */
  YYSYMBOL_LEFT_SQUARE_BRACE = 47,         /* LEFT_SQUARE_BRACE  */
  YYSYMBOL_RIGHT_SQUARE_BRACE = 48,        /* RIGHT_SQUARE_BRACE  */
  YYSYMBOL_ADD_ASSIGN = 49,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 50,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 51,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 52,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 53,                /* MOD_ASSIGN  */
  YYSYMBOL_LOWER_THAN_ELSE = 54,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_60_ = 60,                       /* ':'  */
  YYSYMBOL_61_ = 61,                       /* '&'  */
  YYSYMBOL_62_ = 62,                       /* '?'  */
  YYSYMBOL_63_ = 63,                       /* '!'  */
  YYSYMBOL_64_ = 64,                       /* '['  */
  YYSYMBOL_65_ = 65,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_program = 67,                   /* program  */
  YYSYMBOL_translation_unit = 68,          /* translation_unit  */
  YYSYMBOL_external_declaration = 69,      /* external_declaration  */
  YYSYMBOL_function_prototype = 70,        /* function_prototype  */
  YYSYMBOL_include_directive = 71,         /* include_directive  */
  YYSYMBOL_function_definition = 72,       /* function_definition  */
  YYSYMBOL_parameter_list = 73,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 74,     /* parameter_declaration  */
  YYSYMBOL_compound_stmt = 75,             /* compound_stmt  */
  YYSYMBOL_datatype = 76,                  /* datatype  */
  YYSYMBOL_stmt_list = 77,                 /* stmt_list  */
  YYSYMBOL_stmt = 78,                      /* stmt  */
  YYSYMBOL_if_stmt = 79,                   /* if_stmt  */
  YYSYMBOL_for_stmt = 80,                  /* for_stmt  */
  YYSYMBOL_for_init = 81,                  /* for_init  */
  YYSYMBOL_for_cond = 82,                  /* for_cond  */
  YYSYMBOL_for_update = 83,                /* for_update  */
  YYSYMBOL_while_stmt = 84,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 85,             /* do_while_stmt  */
  YYSYMBOL_expr_stmt = 86,                 /* expr_stmt  */
  YYSYMBOL_switch_stmt = 87,               /* switch_stmt  */
  YYSYMBOL_case_list = 88,                 /* case_list  */
  YYSYMBOL_case_stmt = 89,                 /* case_stmt  */
  YYSYMBOL_default_stmt = 90,              /* default_stmt  */
  YYSYMBOL_break_stmt = 91,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 92,             /* continue_stmt  */
  YYSYMBOL_decl_stmt = 93,                 /* decl_stmt  */
  YYSYMBOL_print_stmt = 94,                /* print_stmt  */
  YYSYMBOL_print_args = 95,                /* print_args  */
  YYSYMBOL_arg_list = 96,                  /* arg_list  */
  YYSYMBOL_scan_stmt = 97,                 /* scan_stmt  */
  YYSYMBOL_expr = 98,                      /* expr  */
  YYSYMBOL_assign_expr = 99,               /* assign_expr  */
  YYSYMBOL_conditional_expr = 100,         /* conditional_expr  */
  YYSYMBOL_logical_expr = 101,             /* logical_expr  */
  YYSYMBOL_logical_or_expr = 102,          /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 103,         /* logical_and_expr  */
  YYSYMBOL_equality_expr = 104,            /* equality_expr  */
  YYSYMBOL_relational_expr = 105,          /* relational_expr  */
  YYSYMBOL_additive_expr = 106,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 107,      /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 108,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 109,             /* postfix_expr  */
  YYSYMBOL_primary_expr = 110,             /* primary_expr  */
  YYSYMBOL_function_call = 111,            /* function_call  */
  YYSYMBOL_declaration = 112,              /* declaration  */
  YYSYMBOL_const_declarator_list = 113,    /* const_declarator_list  */
  YYSYMBOL_const_declarator = 114,         /* const_declarator  */
  YYSYMBOL_declarator_list = 115,          /* declarator_list  */
  YYSYMBOL_declarator = 116,               /* declarator  */
  YYSYMBOL_return_stmt = 117               /* return_stmt  */
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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


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
       2,     2,     2,    63,     2,     2,     2,     2,    61,     2,
      55,    56,     2,     2,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,     2,
       2,     2,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    58,    59,    62,    63,    64,    65,    68,
      69,    72,    75,    76,    79,    80,    83,    84,    85,    86,
      89,    92,    93,    94,    95,    96,    99,   100,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   118,   119,   122,   125,   126,   127,   130,   131,   134,
     135,   138,   141,   144,   147,   150,   151,   152,   155,   158,
     161,   164,   167,   170,   173,   174,   177,   178,   181,   184,
     187,   188,   189,   190,   191,   192,   193,   194,   197,   198,
     201,   204,   205,   208,   209,   212,   213,   214,   217,   218,
     219,   220,   221,   224,   225,   226,   229,   230,   231,   232,
     235,   236,   237,   238,   239,   240,   243,   244,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   259,   260,
     263,   264,   267,   268,   271,   272,   276,   277,   280,   281,
     282,   283,   284,   286,   287
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
  "OR", "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE", "MODULO", "UNARY", "SEMI",
  "NULL_TOKEN", "LEFT_SQUARE_BRACE", "RIGHT_SQUARE_BRACE", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "LOWER_THAN_ELSE", "'('", "')'", "','", "'{'", "'}'", "':'", "'&'",
  "'?'", "'!'", "'['", "']'", "$accept", "program", "translation_unit",
  "external_declaration", "function_prototype", "include_directive",
  "function_definition", "parameter_list", "parameter_declaration",
  "compound_stmt", "datatype", "stmt_list", "stmt", "if_stmt", "for_stmt",
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

#define YYPACT_NINF (-167)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     142,  -167,  -167,  -167,  -167,  -167,   321,  -167,     3,   142,
    -167,   -38,  -167,  -167,     4,   -24,    26,  -167,  -167,  -167,
      23,    42,    24,  -167,  -167,    54,    28,    35,  -167,   186,
     119,    11,    -3,  -167,    42,   186,    82,    26,  -167,  -167,
      97,  -167,  -167,  -167,  -167,   283,   327,   283,  -167,   186,
     283,   283,  -167,  -167,  -167,  -167,    -4,    95,   -19,    69,
      59,   125,  -167,    75,  -167,  -167,   321,    85,    53,  -167,
      66,    89,    93,  -167,  -167,   186,  -167,   186,   186,   186,
     186,   186,   186,    45,   283,  -167,   -25,  -167,  -167,    98,
    -167,  -167,   283,   186,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,  -167,    70,  -167,  -167,
      85,   335,  -167,   165,   144,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,    60,  -167,   186,  -167,    95,   122,   -19,
      69,    69,    59,    59,    59,    59,   125,   125,  -167,  -167,
    -167,  -167,   179,   196,  -167,  -167,  -167,   186,  -167,   186,
    -167,   283,  -167,   130,   131,   133,   257,   139,   150,   152,
     143,   170,    90,  -167,  -167,    42,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,   183,   184,
    -167,  -167,  -167,  -167,   186,   186,    19,   221,   186,  -167,
    -167,   237,   238,  -167,   200,  -167,  -167,   190,   192,   205,
    -167,  -167,   197,   202,   199,   209,  -167,   257,   257,   186,
     186,   195,   186,   215,   233,   286,  -167,   251,  -167,   243,
    -167,   245,   255,   299,   257,   186,   260,    14,  -167,   250,
    -167,   253,  -167,  -167,   186,   254,  -167,  -167,  -167,   265,
     257,   256,  -167,  -167,  -167,  -167,   257,   257
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,    22,    24,    23,    25,     0,    11,     0,     2,
       3,     0,     8,     5,     0,     0,     0,     1,     4,     7,
     128,     0,   120,   126,     6,     0,     0,   121,   122,     0,
       0,     0,   128,   129,     0,     0,     0,     0,   109,   110,
     108,   111,   112,   113,   114,     0,     0,     0,   115,     0,
       0,     0,   130,    69,    80,    70,    78,    81,    83,    85,
      88,    93,    96,   100,   106,   117,     0,    10,     0,    14,
       0,   108,     0,   127,   124,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   108,   103,   101,     0,
     105,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,    26,    13,
       9,     0,    16,     0,   131,   125,    71,    73,    74,    75,
      76,    77,   118,     0,    66,     0,   116,    82,     0,    84,
      86,    87,    91,    92,    90,    89,    94,    95,    97,    98,
      99,    18,     0,     0,    12,    15,    17,     0,   119,     0,
      72,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    28,     0,    27,    29,    30,    31,
      32,    34,    33,    39,    40,    35,    36,    37,     0,     0,
      38,   132,    67,    79,     0,     0,    44,     0,     0,    60,
      61,     0,     0,   134,     0,    53,    62,     0,     0,     0,
      45,    46,     0,     0,    64,     0,   133,     0,     0,    47,
       0,     0,     0,     0,     0,    41,    51,     0,    48,     0,
      55,    65,     0,     0,     0,    49,     0,     0,    63,     0,
      42,     0,    50,    52,     0,     0,    54,    56,    57,     0,
       0,     0,    26,    68,    43,    26,    59,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,   302,  -167,  -167,  -167,  -167,   206,   -48,
       2,  -166,  -152,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
     101,  -167,   -29,    44,   168,  -167,  -167,   229,   228,    33,
      79,    71,   188,  -167,   294,  -167,     1,  -167,   289,  -167,
      56,  -167
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    13,    68,    69,   164,
     165,   143,   166,   167,   168,   199,   217,   231,   169,   170,
     171,   172,   227,   237,   238,   173,   174,   175,   176,   213,
     123,   177,   178,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   179,    27,    28,    22,
      23,   180
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    15,    14,    17,   187,   125,    74,    19,    16,    20,
      15,    14,    95,    96,    38,    39,    71,    41,    42,   109,
      89,    24,    38,    39,    40,    41,    42,    29,   234,   235,
      83,    25,    70,    36,    92,    43,    44,     1,     2,     3,
       4,     5,     6,    43,    44,    21,   115,    32,    38,    39,
      40,    41,    42,    29,   124,   215,   216,    48,    93,    45,
      46,    31,   144,    47,   128,    48,    49,    26,   107,    43,
      44,   112,   230,   236,    49,   141,   246,    33,    30,   247,
      50,    34,    51,    21,    35,    45,    46,    31,   244,    47,
      73,    48,    37,    38,    39,    40,    41,    42,   101,   102,
      49,   122,    97,    98,    99,   100,    50,   113,    51,   110,
     111,   142,    75,    70,    43,    44,   148,   149,   181,   106,
     182,   116,   117,   118,   119,   120,   121,    77,   130,   131,
      45,    46,    94,   194,    47,   193,    48,     1,     2,     3,
       4,     5,    66,   108,    83,    49,    78,    79,    80,    81,
      82,    50,    83,    51,   126,   197,   198,   200,   114,   203,
       1,     2,     3,     4,     5,     6,   103,   104,   105,   150,
     146,     7,   136,   137,   147,    67,   132,   133,   134,   135,
     218,   219,   151,   124,   152,   184,   185,   201,   186,    38,
      39,    40,    41,    42,   188,   189,   232,   190,   191,    38,
      39,    40,    41,    42,   153,   241,   154,   155,   156,   157,
      43,    44,   158,   159,     1,     2,     3,     4,     5,     6,
      43,    44,   160,   161,   162,   192,    45,    46,   195,   196,
      47,   202,    48,    85,    87,    88,    45,    46,    90,    91,
      47,    49,    48,   204,   205,   206,   207,    50,   208,    51,
     209,    49,   210,   220,   108,   163,   212,    50,   211,    51,
      38,    39,    40,    41,    42,   153,   214,   154,   155,   156,
     157,   222,    87,   158,   159,     1,     2,     3,     4,     5,
       6,    43,    44,   160,   161,   162,    38,    39,    71,    41,
      42,   138,   139,   140,   223,   224,   225,    45,    46,   226,
     228,    47,   149,    48,   229,   233,   239,    43,    44,   240,
     243,    18,    49,   221,   242,   108,   245,   145,    50,   183,
      51,   127,   129,    45,    84,    72,    76,    47,     0,    48,
      38,    39,    86,    41,    42,     0,     0,     0,    49,     1,
       2,     3,     4,     5,    50,     0,    51,     0,     0,     0,
       0,    43,    44,     1,     2,     3,     4,     5,    66,     0,
       0,     0,     0,     0,     0,     0,     0,    45,    84,     0,
       0,    47,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,    50,     0,
      51
};

static const yytype_int16 yycheck[] =
{
      29,     0,     0,     0,   156,    30,    35,    45,     6,     5,
       9,     9,    31,    32,     3,     4,     5,     6,     7,    67,
      49,    45,     3,     4,     5,     6,     7,    30,    14,    15,
      55,     5,    30,     5,    38,    24,    25,    18,    19,    20,
      21,    22,    23,    24,    25,    41,    75,     5,     3,     4,
       5,     6,     7,    30,    83,   207,   208,    46,    62,    40,
      41,    64,   110,    44,    93,    46,    55,    41,    66,    24,
      25,     5,   224,    59,    55,     5,   242,    21,    55,   245,
      61,    57,    63,    41,    30,    40,    41,    64,   240,    44,
      34,    46,    57,     3,     4,     5,     6,     7,    39,    40,
      55,    56,    33,    34,    35,    36,    61,    41,    63,    56,
      57,    41,    30,   111,    24,    25,    56,    57,   147,    44,
     149,    77,    78,    79,    80,    81,    82,    30,    95,    96,
      40,    41,    37,   162,    44,    45,    46,    18,    19,    20,
      21,    22,    23,    58,    55,    55,    49,    50,    51,    52,
      53,    61,    55,    63,    56,   184,   185,   186,    65,   188,
      18,    19,    20,    21,    22,    23,    41,    42,    43,   125,
       5,    29,   101,   102,    30,    56,    97,    98,    99,   100,
     209,   210,    60,   212,     5,    55,    55,   186,    55,     3,
       4,     5,     6,     7,    55,    45,   225,    45,    55,     3,
       4,     5,     6,     7,     8,   234,    10,    11,    12,    13,
      24,    25,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    55,    40,    41,    45,    45,
      44,    10,    46,    45,    46,    47,    40,    41,    50,    51,
      44,    55,    46,     6,     6,    45,    56,    61,    56,    63,
      45,    55,    55,    58,    58,    59,    57,    61,    56,    63,
       3,     4,     5,     6,     7,     8,    57,    10,    11,    12,
      13,    56,    84,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     3,     4,     5,     6,
       7,   103,   104,   105,    61,     9,    45,    40,    41,    56,
      45,    44,    57,    46,     5,    45,    56,    24,    25,    56,
      45,     9,    55,   212,    60,    58,    60,   111,    61,   151,
      63,    92,    94,    40,    41,    31,    37,    44,    -1,    46,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    55,    18,
      19,    20,    21,    22,    61,    -1,    63,    -1,    -1,    -1,
      -1,    24,    25,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    19,    20,    21,    22,    23,    29,    67,    68,
      69,    70,    71,    72,    76,   112,    76,     0,    69,    45,
       5,    41,   115,   116,    45,     5,    41,   113,   114,    30,
      55,    64,     5,   116,    57,    30,     5,    57,     3,     4,
       5,     6,     7,    24,    25,    40,    41,    44,    46,    55,
      61,    63,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    23,    56,    73,    74,
      76,     5,   110,   116,    98,    30,   114,    30,    49,    50,
      51,    52,    53,    55,    41,   108,     5,   108,   108,    98,
     108,   108,    38,    62,    37,    31,    32,    33,    34,    35,
      36,    39,    40,    41,    42,    43,    44,    76,    58,    75,
      56,    57,     5,    41,    65,    98,    99,    99,    99,    99,
      99,    99,    56,    96,    98,    30,    56,   103,    98,   104,
     105,   105,   106,   106,   106,   106,   107,   107,   108,   108,
     108,     5,    41,    77,    75,    74,     5,    30,    56,    57,
      99,    60,     5,     8,    10,    11,    12,    13,    16,    17,
      26,    27,    28,    59,    75,    76,    78,    79,    80,    84,
      85,    86,    87,    91,    92,    93,    94,    97,    98,   112,
     117,    98,    98,   100,    55,    55,    55,    78,    55,    45,
      45,    55,    55,    45,    98,    45,    45,    98,    98,    81,
      98,   112,    10,    98,     6,     6,    45,    56,    56,    45,
      55,    56,    57,    95,    57,    78,    78,    82,    98,    98,
      58,    96,    56,    61,     9,    45,    56,    88,    45,     5,
      78,    83,    98,    45,    14,    15,    59,    89,    90,    56,
      56,    98,    60,    45,    78,    60,    77,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    69,    70,
      70,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      75,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    81,    81,    81,    82,    82,    83,
      83,    84,    85,    86,    87,    88,    88,    88,    89,    90,
      91,    92,    93,    94,    95,    95,    96,    96,    97,    98,
      99,    99,    99,    99,    99,    99,    99,    99,   100,   100,
     101,   102,   102,   103,   103,   104,   104,   104,   105,   105,
     105,   105,   105,   106,   106,   106,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     116,   116,   116,   117,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     1,     5,
       4,     1,     6,     5,     1,     3,     2,     3,     3,     4,
       3,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     7,     9,     0,     1,     1,     0,     1,     0,
       1,     5,     7,     2,     7,     0,     2,     2,     4,     3,
       2,     2,     2,     6,     0,     2,     1,     3,     8,     1,
       1,     3,     4,     3,     3,     3,     3,     3,     1,     5,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     4,
       2,     3,     1,     3,     3,     4,     1,     3,     1,     2,
       3,     4,     6,     3,     2
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

#line 1396 "parser/parser.tab.c"

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

#line 290 "parser/parser.y"


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
