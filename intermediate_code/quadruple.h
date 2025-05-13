#ifndef QUADRUPLE_H
#define QUADRUPLE_H

#include <stdio.h>

// Maximum number of quadruples
#define MAX_QUADS 1000

// Define the possible quadruple operations
typedef enum QuadOp {
    // Arithmetic operations
    QuadOp_ADD,
    QuadOp_SUB,
    QuadOp_MUL,
    QuadOp_DIV,
    QuadOp_MOD,

    // Assignment operations
    QuadOp_ASSIGN,
    QuadOp_ADD_ASSIGN,
    QuadOp_SUB_ASSIGN,
    QuadOp_MUL_ASSIGN,
    QuadOp_DIV_ASSIGN,
    QuadOp_MOD_ASSIGN,

    // Unary operations
    QuadOp_NEG,

    // Relational operations
    QuadOp_LT,
    QuadOp_GT,
    QuadOp_LTE,
    QuadOp_GTE,
    QuadOp_EQ,
    QuadOp_NE,

    // Logical operations
    QuadOp_AND,
    QuadOp_OR,
    QuadOp_NOT,

    // Control flow operations
    QuadOp_JMP,    // Unconditional jump
    QuadOp_JEQ,    // Jump if equal
    QuadOp_JNE,    // Jump if not equal
    QuadOp_JLT,    // Jump if less than
    QuadOp_JGT,    // Jump if greater than
    QuadOp_JLE,    // Jump if less than or equal
    QuadOp_JGE,    // Jump if greater than or equal
    QuadOp_LABEL,  // Label marker

    // Function call operations
    QuadOp_CALL,
    QuadOp_RET,

    // Other operations
    QuadOp_PRINT,  // For printf
    QuadOp_SCAN   // For scanf
} QuadOp;

// Define the structure for a quadruple
typedef struct Quadruple {
    QuadOp op;      // Operator (e.g., "+", "-", "*", "/", "=")
    char* arg1;    // Argument 1
    char* arg2;    // Argument 2
    char* result;  // Result
} Quadruple;

// Function prototypes
Quadruple* createQuadruple(QuadOp op, char* arg1, char* arg2, char* result);
void addQuadruple(Quadruple* quad);
void printQuadruples();
const char* quadOpToString(QuadOp op); // New function prototype

#endif