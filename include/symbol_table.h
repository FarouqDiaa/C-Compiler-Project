#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SYMBOLS 100

typedef struct {
    char name[50];
    char type[20];
    int initialized;
} Symbol;

void insert_symbol(const char* name, const char* type);
void check_assignment(const char* name);
void check_initialization(const char* name);
void print_symbol_table();

#endif
