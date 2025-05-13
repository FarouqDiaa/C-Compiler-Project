#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include "../include/symbol_table.h"

extern Scope *current_scope;
extern int line_num;

int parse_expression(); // Forward declaration

// Type compatibility definitions
typedef enum
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_BOOL,
    TYPE_UNKNOWN
} BasicType;

// Function to extract the basic type from a type string
BasicType get_basic_type(const char *type_str)
{
    if (strstr(type_str, "int") != NULL)
        return TYPE_INT;
    if (strstr(type_str, "float") != NULL)
        return TYPE_FLOAT;
    if (strstr(type_str, "double") != NULL)
        return TYPE_DOUBLE;
    if (strstr(type_str, "char") != NULL)
        return TYPE_CHAR;
    if (strstr(type_str, "void") != NULL)
        return TYPE_VOID;
    if (strstr(type_str, "bool") != NULL)    // Add this line
        return TYPE_BOOL;
    return TYPE_UNKNOWN;
}

// Function to check type compatibility in assignments
bool check_type_compatibility(const char *left_type, const char *right_type)
{
    BasicType left_basic = get_basic_type(left_type);
    BasicType right_basic = get_basic_type(right_type);

    // Same basic types are always compatible
    if (left_basic == right_basic)
        return true;

    // Allow assignment between bool and int (both directions)
    if ((left_basic == TYPE_BOOL && right_basic == TYPE_INT) ||
        (left_basic == TYPE_INT && right_basic == TYPE_BOOL)) {
        return true;
    }

    // Numeric types have some compatibility
    if ((left_basic == TYPE_INT || left_basic == TYPE_FLOAT || left_basic == TYPE_DOUBLE) &&
        (right_basic == TYPE_INT || right_basic == TYPE_FLOAT || right_basic == TYPE_DOUBLE))
    {
        // Assigning smaller types to larger types is allowed
        if (left_basic == TYPE_DOUBLE)
            return true;
        if (left_basic == TYPE_FLOAT && right_basic == TYPE_INT)
            return true;


        // Otherwise, warn about potential precision loss
        fprintf(stderr, "Warning at line %d: Possible precision loss in assignment from %s to %s\n",
            line_num, right_type, left_type);
    return true;
}

// One or both types are unknown
if (left_basic == TYPE_UNKNOWN || right_basic == TYPE_UNKNOWN)
{
    fprintf(stderr, "Error at line %d: Unknown type in assignment\n", line_num);
    return false;
}

return false;
}

// ---------------- Constant Checking ----------------

// Global pointer for parsing
const char *expr_ptr;

void skip_spaces()
{
    while (isspace(*expr_ptr))
        expr_ptr++;
}

// int parse_expression(); // +, -
// int parse_term();       // *, /
// int parse_factor();     // numbers, ()

int parse_number()
{
    skip_spaces();
    int value = 0;
    while (isdigit(*expr_ptr))
    {
        value = value * 10 + (*expr_ptr - '0');
        expr_ptr++;
    }
    return value;
}

int parse_factor()
{
    skip_spaces();
    if (*expr_ptr == '(')
    {
        expr_ptr++; // skip '('
        int result = parse_expression();
        if (*expr_ptr == ')')
            expr_ptr++;
        return result;
    }
    else
    {
        return parse_number();
    }
}
int parse_term()
{
    int result = parse_factor();
    skip_spaces();
    while (*expr_ptr == '*' || *expr_ptr == '/')
    {
        char op = *expr_ptr++;
        int right = parse_factor();
        if (op == '*')
            result *= right;
        else if (op == '/')
        {
            if (right == 0)
            {
                fprintf(stderr, "Warning at line %d: Division by zero detected\n", line_num);
                // Using a large value to indicate error
                return INT_MAX;
            }
            result /= right;
        }
    }
    return result;
}

int parse_expression()
{
    int result = parse_term();
    skip_spaces();
    while (*expr_ptr == '+' || *expr_ptr == '-')
    {
        char op = *expr_ptr++;
        int right = parse_term();
        if (op == '+')
            result += right;
        else
            result -= right;
    }
    return result;
}

// Check if an expression is constant and evaluate it
bool is_constant_expression(const char *expr)
{
    // Check for illegal characters
    const char *scan = expr;
    while (*scan)
    {
        if (!isdigit(*scan) && !strchr("+-*/() \t\r\n", *scan))
        {
            return false;
        }
        scan++;
    }

    expr_ptr = expr;
    int result = parse_expression();
    skip_spaces();
    return *expr_ptr == '\0'; // valid only if entire input was consumed
}

bool evaluate_constant_expression(const char *expr, int *out_result)
{
    if (!is_constant_expression(expr))
        return false;
    expr_ptr = expr;
    *out_result = parse_expression();
    return true;
}
// ---------------- End of Constant Checking ----------------
// Function to check for assignment to a constant variable
bool check_const_assignment(Symbol *sym)
{
    if (sym && sym->is_const && sym->is_initialized)
    {
        fprintf(stderr, "Error at line %d: Cannot modify constant variable '%s'\n",
                line_num, sym->name);
        return false;
    }
    return true;
}

// Function to check if variable is used before initialization
bool check_initialization(Scope *scope, const char *name)
{
    Symbol *sym = lookup_symbol(scope, name);
    if (sym && !sym->is_initialized)
    {
        fprintf(stderr, "Warning at line %d: Variable '%s' may be used before initialization\n",
                line_num, name);
        return false;
    }
    return true;
}

// Function to check for multiple declarations in the same scope
bool check_duplicate_declaration(Scope *scope, const char *name)
{
    // Check if symbol exists in the current scope (not parent scopes)
    for (int i = 0; i < scope->symbol_count; i++)
    {
        if (strcmp(scope->symbols[i].name, name) == 0)
        {
            fprintf(stderr, "Error at line %d: Redeclaration of '%s' in the same scope\n",
                    line_num, name);
            return false;
        }
    }
    return true;
}

// Function to verify assignment compatibility
bool check_assignment_compatibility(Scope *scope, const char *left_var, const char *right_expr)
{
    Symbol *left_sym = lookup_symbol(scope, left_var);
    if (!left_sym)
    {
        fprintf(stderr, "Error at line %d: Undeclared variable '%s'\n", line_num, left_var);
        return false;
    }

    // Check for assignment to a constant
    if (!check_const_assignment(left_sym))
    {
        return false;
    }

    // Mark the variable as initialized
    mark_symbol_initialized(scope, left_var);

    // For a proper type check, we need to know the type of the right expression
    Symbol *right_sym = lookup_symbol(scope, right_expr);
    if (right_sym)
    {
        // If right expression is a variable, check its type
        return check_type_compatibility(left_sym->type, right_sym->type);
    }

    // Default case for literals and complex expressions
    return true;
}

// Function to analyze a binary operation
bool analyze_binary_operation(Scope *scope, const char *left, const char *op, const char *right)
{
    Symbol *left_sym = lookup_symbol(scope, left);
    Symbol *right_sym = lookup_symbol(scope, right);

    // Check if operands are declared
    if (left_sym == NULL && !is_constant_expression(left))
    {
        fprintf(stderr, "Error at line %d: Undeclared identifier '%s'\n", line_num, left);
        return false;
    }

    if (right_sym == NULL && !is_constant_expression(right))
    {
        fprintf(stderr, "Error at line %d: Undeclared identifier '%s'\n", line_num, right);
        return false;
    }

    // Check if variables are initialized
    if (left_sym && !left_sym->is_initialized)
    {
        fprintf(stderr, "Warning at line %d: Variable '%s' may be used before initialization\n",
                line_num, left);
    }

    if (right_sym && !right_sym->is_initialized)
    {
        fprintf(stderr, "Warning at line %d: Variable '%s' may be used before initialization\n",
                line_num, right);
    }

    // Mark variables as used
    if (left_sym)
        mark_symbol_used(scope, left);
    if (right_sym)
        mark_symbol_used(scope, right);

    return true;
}

// Main entry point for semantic analysis
void semantic_analysis()
{
    printf("Starting semantic analysis...\n");

    // At this point, the parser has already built the symbol table
    // and performed basic semantic checks during parsing

    // Additional semantic checks could be done here, such as
    // more complex type compatibility rules, function call validation, etc.

    printf("Semantic analysis completed.\n");
}
