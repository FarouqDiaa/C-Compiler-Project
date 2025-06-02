#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
char* nextTemp();
char* nextLabel();

// Stack implementation
typedef struct StackNode {
    void* data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
    int size;
} Stack;

// Stack operations
Stack* createStack();
void push(Stack* stack, void* data);
void* pop(Stack* stack);
void* peek(Stack* stack);
bool isEmpty(Stack* stack);
void freeStack(Stack* stack);

#endif