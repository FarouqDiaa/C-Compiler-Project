#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

// Type compatibility check
int is_type_compatible(const char *type1, const char *type2);

// Check assignment type compatibility
void check_type_compatibility(const char *var_name, const char *expr_type);

// Check if types are valid for a binary operation
const char *check_binary_op_types(const char *left_type, const char *right_type, const char *op);

// Perform full semantic analysis after parsing
void semantic_analysis();

// Record a variable usage to track unused variables
void record_variable_usage(const char *name);

// Check for unused variables (called at the end)
void check_unused_variables();

// Initialize semantic analyzer
void init_semantic_analyzer();

#endif