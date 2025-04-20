# Mini Compiler Project - CMPN403

This project is a simple compiler for a custom language built using **Flex** and **Bison**.

## Features
- Tokenization using Lex
- Grammar parsing using Yacc
- Symbol table for variable tracking
- Semantic analysis and error detection
- Intermediate code generation (quadruples) - [to be added]

## How to Run

```bash
make
./output/compiler < examples/sample1.src
```

## Output
- Symbol Table
- Semantic Warnings/Errors
- Syntax Errors

## Team Members
- Dev 1: Lexer + Language Design
- Dev 2: Parser + Integration
- Dev 3: Semantic Analysis + Symbol Table
- Dev 4: Quadruples + Testing
