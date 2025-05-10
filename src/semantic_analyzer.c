#include "../include/semantic_analyzer.h"
#include "../include/symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// External line number from lexer
extern int line_num;

// Track variable usage for unused variable warnings
typedef struct
{
    char name[50];
    int used;
} VariableUsage;

#define MAX_VARIABLES 100
static VariableUsage var_usage[MAX_VARIABLES];
static int usage_count = 0;

// Initialize semantic analyzer
void init_semantic_analyzer()
{
    usage_count = 0;
}

// Check if two types are compatible for assignment and operations
int is_type_compatible(const char *type1, const char *type2)
{
    // Same types are always compatible
    if (strcmp(type1, type2) == 0)
    {
        return 1;
    }

    // Allow int-to-float conversion (implicit widening)
    if (strcmp(type1, "float") == 0 && strcmp(type2, "int") == 0 ||
        strcmp(type1, "int") == 0 && strcmp(type2, "float") == 0)
    {
        return 1;
    }

    // Allow char-to-int conversion
    if (strcmp(type1, "int") == 0 && strcmp(type2, "char") == 0 ||
        strcmp(type1, "char") == 0 && strcmp(type2, "int") == 0)
    {
        return 1;
    }

    // Other combinations are incompatible
    return 0;
}

// Check if a variable's type is compatible with an expression's type
void check_type_compatibility(const char *var_name, const char *expr_type)
{
    char var_type[20];

    // Get the variable's type from the symbol table
    if (get_symbol_type(var_name, var_type) == 0)
    {
        printf("Error at line %d: Variable '%s' not declared.\n", line_num, var_name);
        return;
    }

    // Check compatibility
    if (!is_type_compatible(var_type, expr_type))
    {
        printf("Error at line %d: Type mismatch in assignment to '%s'. Cannot convert from '%s' to '%s'.\n",
               line_num, var_name, expr_type, var_type);
        return;
    }

    // Record that the variable was used in an assignment
    record_variable_usage(var_name);
}

// Determine the resulting type of a binary operation
const char *check_binary_op_types(const char *left_type, const char *right_type, const char *op)
{
    // For arithmetic operators (+, -, *, /, %)
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 ||
        strcmp(op, "*") == 0 || strcmp(op, "/") == 0)
    {

        // Two floats yield a float
        if (strcmp(left_type, "float") == 0 || strcmp(right_type, "float") == 0)
        {
            return "float";
        }

        // Two ints yield an int
        if (strcmp(left_type, "int") == 0 && strcmp(right_type, "int") == 0)
        {
            return "int";
        }

        // Char operations are promoted to int
        if ((strcmp(left_type, "char") == 0 || strcmp(left_type, "int") == 0) &&
            (strcmp(right_type, "char") == 0 || strcmp(right_type, "int") == 0))
        {
            return "int";
        }
    }

    // For modulo operator (%), both operands must be integers
    if (strcmp(op, "%") == 0)
    {
        if (strcmp(left_type, "int") == 0 && strcmp(right_type, "int") == 0)
        {
            return "int";
        }
        else
        {
            printf("Error at line %d: Modulo operator requires integer operands.\n", line_num);
            return "int"; // Default to prevent cascading errors
        }
    }

    // For comparison operators, result is always an int (boolean)
    if (strcmp(op, "<") == 0 || strcmp(op, ">") == 0 ||
        strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0 ||
        strcmp(op, "==") == 0 || strcmp(op, "!=") == 0)
    {

        // Check if types are comparable
        if (!is_type_compatible(left_type, right_type) &&
            !is_type_compatible(right_type, left_type))
        {
            printf("Error at line %d: Cannot compare '%s' with '%s'.\n",
                   line_num, left_type, right_type);
        }

        return "int"; // Comparison result is always a boolean (int)
    }

    // For logical operators (&&, ||)
    if (strcmp(op, "&&") == 0 || strcmp(op, "||") == 0)
    {
        return "int"; // Logical result is always a boolean (int)
    }

    // Default case - incompatible types
    printf("Error at line %d: Incompatible types '%s' and '%s' for operator '%s'.\n",
           line_num, left_type, right_type, op);
    return "int"; // Default to prevent cascading errors
}

// Record variable usage to track unused variables
void record_variable_usage(const char *name)
{
    // Check if variable is already in the usage table
    for (int i = 0; i < usage_count; i++)
    {
        if (strcmp(var_usage[i].name, name) == 0)
        {
            var_usage[i].used = 1; // Mark as used
            return;
        }
    }

    // Add variable to usage table if not found
    if (usage_count < MAX_VARIABLES)
    {
        strcpy(var_usage[usage_count].name, name);
        var_usage[usage_count].used = 1; // Mark as used
        usage_count++;
    }
}

// Check for unused variables and generate warnings
void check_unused_variables()
{
    char var_type[20];

    for (int i = 0; i < symbol_count; i++)
    {
        // Skip function names and other non-variables
        get_symbol_type(symbols[i].name, var_type);
        if (strcmp(var_type, "function") == 0)
        {
            continue;
        }

        // Check if variable has been used
        int used = 0;
        for (int j = 0; j < usage_count; j++)
        {
            if (strcmp(var_usage[j].name, symbols[i].name) == 0)
            {
                used = var_usage[j].used;
                break;
            }
        }

        // Warn about unused variables
        if (!used)
        {
            printf("Warning: Variable '%s' declared but never used.\n", symbols[i].name);
        }
    }
}

// Perform full semantic analysis
void semantic_analysis()
{
    // Check for unused variables
    check_unused_variables();

    // Print the symbol table
    print_symbol_table();
}