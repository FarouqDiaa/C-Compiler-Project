#include "quadruple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array to store quadruples
Quadruple* quadruples[MAX_QUADS];
int quadCount = 0;

// Function to create a new quadruple
Quadruple* createQuadruple(QuadOp op, char* arg1, char* arg2, char* result) {
    Quadruple* quad = (Quadruple*)malloc(sizeof(Quadruple));
    if (quad == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for quadruple\n");
        exit(EXIT_FAILURE);
    }

    quad->op = op; // Assign the enum value directly

    quad->arg1 = (arg1 != NULL) ? strdup(arg1) : NULL;
    if (arg1 != NULL && quad->arg1 == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for arg1 string\n");
        exit(EXIT_FAILURE);
    }

    quad->arg2 = (arg2 != NULL) ? strdup(arg2) : NULL;
    if (arg2 != NULL && quad->arg2 == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for arg2 string\n");
        exit(EXIT_FAILURE);
    }

    quad->result = (result != NULL) ? strdup(result) : NULL;
    if (result != NULL && quad->result == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for result string\n");
        exit(EXIT_FAILURE);
    }

    return quad;
}

// Function to add a quadruple to the array
void addQuadruple(Quadruple* quad) {
    if (quadCount < MAX_QUADS) {
        quadruples[quadCount++] = quad;
    } else {
        fprintf(stderr, "Error: Maximum number of quadruples reached\n");
        exit(EXIT_FAILURE);
    }
}

// Function to convert QuadOp enum to string
const char* quadOpToString(QuadOp op) {
    switch (op) {
        case QuadOp_ADD: return "ADD";
        case QuadOp_SUB: return "SUB";
        case QuadOp_MUL: return "MUL";
        case QuadOp_DIV: return "DIV";
        case QuadOp_MOD: return "MOD";
        case QuadOp_ASSIGN: return "ASSIGN";
        case QuadOp_ADD_ASSIGN: return "ADD_ASSIGN";
        case QuadOp_SUB_ASSIGN: return "SUB_ASSIGN";
        case QuadOp_MUL_ASSIGN: return "MUL_ASSIGN";
        case QuadOp_DIV_ASSIGN: return "DIV_ASSIGN";
        case QuadOp_MOD_ASSIGN: return "MOD_ASSIGN";
        case QuadOp_LT: return "LT";
        case QuadOp_GT: return "GT";
        case QuadOp_LTE: return "LTE";
        case QuadOp_GTE: return "GTE";
        case QuadOp_EQ: return "EQ";
        case QuadOp_NE: return "NE";
        case QuadOp_AND: return "AND";
        case QuadOp_OR: return "OR";
        case QuadOp_NOT: return "NOT";
        case QuadOp_JMP: return "JMP";
        case QuadOp_NEG: return "NEG";
        case QuadOp_JEQ: return "JEQ";
        case QuadOp_JNE: return "JNE";
        case QuadOp_JLT: return "JLT";
        case QuadOp_JGT: return "JGT";
        case QuadOp_JLE: return "JLE";
        case QuadOp_JGE: return "JGE";
        case QuadOp_LABEL: return "LABEL";
        case QuadOp_CALL: return "CALL";
        case QuadOp_RET: return "RET";
        case QuadOp_PRINT: return "PRINT";
        case QuadOp_SCAN: return "SCAN";
        case QuadOp_FUNC_LABEL: return "FUNC_LABEL";
        case QuadOp_LOOP_START: return "LOOP_START";
        case QuadOp_LOOP_END: return "LOOP_END";
        default: return "UNKNOWN";
    }
}

void rearrangeQuadrupleLoops(int loopDepth) {
    for (int i = 0; i < quadCount; i++) {
        // check if the quadruple is a loop end
        if (quadruples[i]->op == QuadOp_LOOP_START) {
            // move it backward until the nearest ComparisonOp
            for (int j = i - 1; j >= 0; j--) {
                if (quadruples[j]->op == QuadOp_LT || quadruples[j]->op == QuadOp_GT || quadruples[j]->op == QuadOp_LTE || quadruples[j]->op == QuadOp_GTE || quadruples[j]->op == QuadOp_EQ || quadruples[j]->op == QuadOp_NE) {
                    Quadruple* temp = quadruples[j];
                    quadruples[j] = quadruples[j + 1];
                    quadruples[j + 1] = temp;
                    break;
                }
                else {
                    // move the quadruple to the new position
                    Quadruple* temp = quadruples[j];
                    quadruples[j] = quadruples[j + 1];
                    quadruples[j + 1] = temp;
                }
            }
        }
        else if (quadruples[i]->op == QuadOp_JEQ) {
            for (int j = i - 1; j >= 0; j--) {
                if (quadruples[j]->op == QuadOp_LT || quadruples[j]->op == QuadOp_GT || quadruples[j]->op == QuadOp_LTE || quadruples[j]->op == QuadOp_GTE || quadruples[j]->op == QuadOp_EQ || quadruples[j]->op == QuadOp_NE) {
                    break;
                }
                else {
                    // move the quadruple to the new position
                    Quadruple* temp = quadruples[j];
                    quadruples[j] = quadruples[j + 1];
                    quadruples[j + 1] = temp;
                }
            }
        }
    }
}

// Function to print all quadruples
void printQuadruples() {
    printf("Quadruples:\n");
    for (int i = 0; i < quadCount; i++) {
        printf("%d:  %s, %s, %s, %s\n", i, quadOpToString(quadruples[i]->op), quadruples[i]->arg1, quadruples[i]->arg2, quadruples[i]->result);
    }
}

void writeQuadruplesToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename);
        return;
    }

    for (int i = 0; i < quadCount; i++) {
        fprintf(file, "%d: %s, %s, %s, %s\n", i, quadOpToString(quadruples[i]->op), quadruples[i]->arg1 ? quadruples[i]->arg1 : "NULL", quadruples[i]->arg2 ? quadruples[i]->arg2 : "NULL", quadruples[i]->result ? quadruples[i]->result : "NULL");
    }

    fclose(file);
}