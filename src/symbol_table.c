// #include "symbol_table.h"
// #include <string.h>
// #include <stdio.h>

// Symbol symbols[MAX_SYMBOLS];
// int symbol_count = 0;

// void insert_symbol(const char* name, const char* type) {
//     for (int i = 0; i < symbol_count; ++i) {
//         if (strcmp(symbols[i].name, name) == 0) {
//             printf("Error: Variable '%s' already declared.\n", name);
//             return;
//         }
//     }
//     strcpy(symbols[symbol_count].name, name);
//     strcpy(symbols[symbol_count].type, type);
//     symbols[symbol_count].initialized = 0;
//     symbol_count++;
// }

// void check_assignment(const char* name) {
//     for (int i = 0; i < symbol_count; ++i) {
//         if (strcmp(symbols[i].name, name) == 0) {
//             symbols[i].initialized = 1;
//             return;
//         }
//     }
//     printf("Error: Variable '%s' not declared.\n", name);
// }

// void check_initialization(const char* name) {
//     for (int i = 0; i < symbol_count; ++i) {
//         if (strcmp(symbols[i].name, name) == 0) {
//             if (!symbols[i].initialized) {
//                 printf("Warning: Variable '%s' used before initialization.\n", name);
//             }
//             return;
//         }
//     }
//     printf("Error: Variable '%s' not declared.\n", name);
// }

// void print_symbol_table() {
//     printf("\nSymbol Table:\n");
//     printf("Name\tType\tInitialized\n");
//     for (int i = 0; i < symbol_count; ++i) {
//         printf("%s\t%s\t%s\n", symbols[i].name, symbols[i].type, symbols[i].initialized ? "Yes" : "No");
//     }
// }
