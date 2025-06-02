#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int tempCount = 0;
static int labelCount = 0;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        perror("Failed to create stack");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, void* data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        perror("Failed to push element");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

void* pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        return NULL;
    }
    StackNode* temp = stack->top;
    void* data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

void* peek(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->top->data;
}

bool isEmpty(Stack* stack) {
    return stack->size == 0;
}

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

// Utility functions
char* nextTemp() {
    static int counter = 0;
    char* temp = malloc(10);
    if (!temp) {
        perror("Failed to allocate temp");
        exit(EXIT_FAILURE);
    }
    snprintf(temp, 10, "t%d", counter++);
    return temp;
}

char* nextLabel() {
    static int counter = 0;
    char* label = malloc(10);
    if (!label) {
        perror("Failed to allocate label");
        exit(EXIT_FAILURE);
    }
    snprintf(label, 10, "L%d", counter++);
    return label;
}