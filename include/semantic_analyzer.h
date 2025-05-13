#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include <stdbool.h>
#include "../include/symbol_table.h"

// Type compatibility definitions
typedef enum
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_UNKNOWN
} BasicType;

// Function to extract the basic type from a type string
BasicType get_basic_type(const char *type_str);

// Function to check type compatibility in assignments
bool check_type_compatibility(const char *left_type, const char *right_type);

// Functions for constant expression evaluation
void skip_spaces();
int parse_number();
int parse_factor();
int parse_term();
int parse_expression();

// Function to check if an expression is constant
bool is_constant_expression(const char *expr);

// Function to evaluate a constant expression
bool evaluate_constant_expression(const char *expr, int *out_result);

// Function to check for assignment to a constant variable
bool check_const_assignment(Symbol *sym);

// Function to check if variable is used before initialization
bool check_initialization(Scope *scope, const char *name);

// Function to check for multiple declarations in the same scope
bool check_duplicate_declaration(Scope *scope, const char *name);

// Function to verify assignment compatibility
bool check_assignment_compatibility(Scope *scope, const char *left_var, const char *right_expr);

// Function to analyze a binary operation
bool analyze_binary_operation(Scope *scope, const char *left, const char *op, const char *right);

// Main entry point for semantic analysis
void semantic_analysis();

#endif