#include "../include/symbol_table.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Create a new scope
Scope* create_scope(Scope* parent, ScopeType type) {
    Scope* new_scope = malloc(sizeof(Scope));
    if (!new_scope) {
        fprintf(stderr, "Memory allocation failed for scope\n");
        exit(1);
    }

    // Initialize scope attributes
    new_scope->return_count = 0;
    new_scope->depth = parent ? parent->depth + 1 : 0;
    new_scope->type = type;
    new_scope->parent = parent;

    // Allocate initial space for symbols
    new_scope->max_symbols = 10;  // Start with space for 10 symbols
    new_scope->symbols = malloc(sizeof(Symbol) * new_scope->max_symbols);
    new_scope->symbol_count = 0;

    return new_scope;
}

// Destroy a scope and free its resources
void destroy_scope(Scope* scope) {
    if (!scope) return;

    // Free the symbols array
    free(scope->symbols);
    free(scope);
}


void set_function_params(Symbol* func_sym, ParamInfo* params, int param_count) {
    if (!func_sym || func_sym->kind != SYM_FUNCTION) return;
    func_sym->params = malloc(sizeof(ParamInfo) * param_count);
    for (int i = 0; i < param_count; ++i) {
        strcpy(func_sym->params[i].type, params[i].type);
    }
    func_sym->param_count = param_count;
}

int get_function_param_count(Symbol* func_sym) {
    if (!func_sym || func_sym->kind != SYM_FUNCTION) return 0;
    return func_sym->param_count;
}

const char* get_function_param_type(Symbol* func_sym, int index) {
    if (!func_sym || func_sym->kind != SYM_FUNCTION) return NULL;
    if (index < 0 || index >= func_sym->param_count) return NULL;
    return func_sym->params[index].type;
}

bool check_function_call(Symbol* func_sym, char** arg_types, int arg_count, int call_line) {
    if (!func_sym || func_sym->kind != SYM_FUNCTION) return false;
    if (func_sym->param_count != arg_count) {
        fprintf(stderr, "Error: Function '%s' called with %d arguments but declared with %d at line %d\n",
            func_sym->name, arg_count, func_sym->param_count, call_line);
        return false;
    }
    for (int i = 0; i < arg_count; ++i) {
        if (strcmp(func_sym->params[i].type, arg_types[i]) != 0) {
            fprintf(stderr, "Error: Argument %d of function '%s' expects '%s' but got '%s' at line %d\n",
                i+1, func_sym->name, func_sym->params[i].type, arg_types[i], call_line);
            return false;
        }
    }
    return true;
}


// Insert a symbol into the given scope
void insert_symbol_in_scope(Scope* scope, const char* name, const char* type, 
                             SymbolKind kind, bool is_const, int line_number) {
    // Check if symbol already exists in this scope
    for (int i = 0; i < scope->symbol_count; i++) {
        if (strcmp(scope->symbols[i].name, name) == 0) {
            fprintf(stderr, "Error: Symbol '%s' already declared in this scope\n", name);
            return;
        }
    }

    // Resize if needed
    if (scope->symbol_count >= scope->max_symbols) {
        scope->max_symbols *= 2;
        scope->symbols = realloc(scope->symbols, sizeof(Symbol) * scope->max_symbols);
        if (!scope->symbols) {
            fprintf(stderr, "Memory reallocation failed for symbols\n");
            exit(1);
        }
    }

    // Add the new symbol
    Symbol* new_symbol = &scope->symbols[scope->symbol_count++];
    strncpy(new_symbol->name, name, sizeof(new_symbol->name) - 1);
    new_symbol->name[sizeof(new_symbol->name) - 1] = '\0';
    strncpy(new_symbol->type, type, sizeof(new_symbol->type) - 1);
    new_symbol->type[sizeof(new_symbol->type) - 1] = '\0';
    new_symbol->kind = kind;
    new_symbol->line_number = line_number;
    new_symbol->is_const = is_const;
    new_symbol->is_initialized = false;
    new_symbol->is_used = false;
    new_symbol->scope_depth = scope->depth;
    // Initialize value if needed
// Initialize value if needed


}

// Lookup a symbol in the current and parent scopes
Symbol* lookup_symbol(Scope* current_scope, const char* name) {
    Scope* scope = current_scope;

    while (scope) {
        // Search in current scope
        for (int i = 0; i < scope->symbol_count; i++) {
            if (strcmp(scope->symbols[i].name, name) == 0) {
                return &scope->symbols[i];
            }
        }
        // Move to parent scope
        scope = scope->parent;
    }

    return NULL;  // Symbol not found
}
// Helper function to recursively print scopes
void print_scope(Scope* scope, int indent) {
        if (!scope) return;

        // Print scope information
        printf("%*cScope (Depth: %d, Type: %d)\n", 
               indent, ' ', scope->depth, scope->type);

        // Print symbols in this scope
        for (int i = 0; i < scope->symbol_count; i++) {
            Symbol* sym = &scope->symbols[i];
            printf("%*c - Name: %s, Type: %s, Kind: %d, Line: %d, Const: %s, Initialized: %s, Used: %s\n", 
                   indent + 2, ' ', 
                   sym->name, 
                   sym->type, 
                   sym->kind,
                   sym->line_number,
                   sym->is_const ? "Yes" : "No",
                   sym->is_initialized ? "Yes" : "No",
                   sym->is_used ? "Yes" : "No");
        }

        // Recursive printing is complex with our current structure
        // In a more advanced implementation, we'd track child scopes
}
// Print the entire symbol table (for debugging)
void print_symbol_table(Scope* root_scope) {
    if (!root_scope) return;

    printf("Symbol Table:\n");
    printf("-------------\n");

    

    print_scope(root_scope, 0);
}

// Mark a symbol as initialized
void mark_symbol_initialized(Scope* current_scope, const char* name) {
    Symbol* symbol = lookup_symbol(current_scope, name);
    if (symbol) {
        symbol->is_initialized = true;
    }
}

// Mark a symbol as used
void mark_symbol_used(Scope* current_scope, const char* name) {
    Symbol* symbol = lookup_symbol(current_scope, name);
    if (symbol) {
        symbol->is_used = true;
    }
}

// Check if a symbol is initialized
bool is_symbol_initialized(Scope* current_scope, const char* name) {
    Symbol* symbol = lookup_symbol(current_scope, name);
    return symbol ? symbol->is_initialized : false;
}

// Check for unused variables in a scope
void check_unused_symbols(Scope* scope) {
    if (!scope) return;

    for (int i = 0; i < scope->symbol_count; i++) {
        Symbol* sym = &scope->symbols[i];
        
        // Ignore function symbols
        if (sym->kind == SYM_FUNCTION) {
         printf("Warning: Unused declared at line\n");
            continue
        ;
        }

        // Warn about unused symbols
        if (!sym->is_used) {
            printf("Warning: Unused %s '%s' declared at line %d\n", 
                   sym->is_const ? "constant" : "variable", 
                   sym->name, 
                   sym->line_number);
        }
    }
}

// Get the type of a symbol
bool get_symbol_type(Scope* current_scope, const char* name, char* type_buffer) {
    Symbol* symbol = lookup_symbol(current_scope, name);
    if (symbol) {
        strncpy(type_buffer, symbol->type, 50);
        type_buffer[49] = '\0';
        return true;
    }
    return false;
}

// Enter a new scope
Scope* enter_scope(Scope* current_scope, ScopeType type) {
    Scope* new_scope = create_scope(current_scope, type);
    return new_scope;
}

// Exit the current scope
Scope* exit_scope(Scope* current_scope) {
    if (!current_scope || !current_scope->parent) {
        fprintf(stderr, "Cannot exit global scope\n");
        return current_scope;
    }

    // Check for unused symbols before exiting
    check_unused_symbols(current_scope);

    // Return to parent scope
    return current_scope->parent;
}
