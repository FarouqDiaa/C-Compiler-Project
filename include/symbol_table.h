#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

// Enum for symbol kinds
typedef enum {
    SYM_VARIABLE,
    SYM_FUNCTION,
    SYM_PARAMETER,
} SymbolKind;

// Enum for scope types
typedef enum {
    SCOPE_GLOBAL,
    SCOPE_LOCAL,
    SCOPE_FUNCTION
} ScopeType;

// Structure to represent a symbol in the symbol table
typedef struct Symbol {
    char name[50];           // Symbol name
    char type[50];           // Full type (can include const, pointer, etc.)
    SymbolKind kind;         // Kind of symbol
    int line_number;         // Line of declaration
    bool is_const;           // Const-ness
    bool is_initialized;     // Whether the symbol has been initialized
    bool is_used;            // Whether the symbol has been used
    int scope_depth;         // Depth of scope
} Symbol;

// Structure to represent a scope
typedef struct Scope {
    int depth;               // Scope depth 
    ScopeType type;          // Type of scope
    struct Scope* parent;    // Parent scope
    Symbol* symbols;         // Symbols in this scope
    int symbol_count;        // Number of symbols in this scope
    int max_symbols;         // Maximum capacity of symbols
} Scope;

// Initialize the symbol table system
void init_symbol_table();

// Create a new scope
Scope* create_scope(Scope* parent, ScopeType type);

// Destroy a scope and free its resources
void destroy_scope(Scope* scope);

// Insert a symbol into the current scope
void insert_symbol_in_scope(Scope* scope, const char* name, const char* type, 
                             SymbolKind kind, bool is_const, int line_number);

// Lookup a symbol in the current and parent scopes
Symbol* lookup_symbol(Scope* current_scope, const char* name);


// Print the entire symbol table (for debugging)
void print_symbol_table(Scope* root_scope);

// Mark a symbol as initialized
void mark_symbol_initialized(Scope* current_scope, const char* name);

// Mark a symbol as used
void mark_symbol_used(Scope* current_scope, const char* name);

// Check if a symbol is initialized
bool is_symbol_initialized(Scope* current_scope, const char* name);

// Check for unused variables in a scope
void check_unused_symbols(Scope* scope);

// Get the type of a symbol
bool get_symbol_type(Scope* current_scope, const char* name, char* type_buffer);

// Enter a new scope
Scope* enter_scope(Scope* current_scope, ScopeType type);

// Exit the current scope
Scope* exit_scope(Scope* current_scope);


#endif // SYMBOL_TABLE_H