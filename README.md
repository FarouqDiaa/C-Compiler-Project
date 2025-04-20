# Mini Compiler Project

This project is a simple compiler for C programming language developed using **Flex** and **Bison** for the  Languages and Compilers course.

## 📦 Features

- ✅ Lexical analysis using Flex
- ✅ Syntax analysis using Bison
- ✅ Symbol table with declaration and initialization checks
- ✅ Semantic analysis for variable usage
- ✅ Intermediate code generation (quadruples)
- ✅ GUI

## 🧱 Project Structure

```
compilers-project/
├── lexer/               # Flex lexer
│   └── lexer.l
├── parser/              # Bison parser
│   └── parser.y
├── src/                 # C source files
│   ├── main.c
│   ├── symbol_table.c
│   └── semantic_analyzer.c
├── include/             # Header files
│   ├── symbol_table.h
│   └── semantic_analyzer.h
├── examples/            # Sample input programs
│   └── sample1.src
├── output/              # Compiled objects and executables
├── Makefile             # Build script
└── README.md
```

## 🚀 How to Build and Run

Make sure you have `flex`, `bison`, and `gcc` installed.

```bash
make
./output/compiler < examples/sample1.src
```

## 🧠 Language Features

Currently supported:
- Integer and float variable declarations
- Assignment statements
- Basic expressions using variables and constants

Example:
```c
int x;
x = 5;
float y;
y = x;
```

## 📋 Output

The compiler produces:
- Symbol Table (with types and initialization state)
- Syntax error messages (with line numbers)
- Semantic warnings/errors for undeclared or uninitialized variables


## 🛠 Tools and Technologies

- [Flex](https://github.com/westes/flex) - Lexical analyzer
- [Bison](https://www.gnu.org/software/bison/) - Parser generator
- [GCC](https://gcc.gnu.org/) - Compiler


## 📄 License

This project is for educational use as part of CMPS403 at Cairo University.
