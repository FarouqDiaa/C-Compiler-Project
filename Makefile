# all:
# 	bison -d parser/parser.y -o output/y.tab.c
# 	flex -o output/lex.yy.c lexer/lexer.l
# 	gcc output/y.tab.c output/lex.yy.c src/*.c -Iinclude -o output/compiler

all:
	bison -d parser/parser.y -o parser/parser.tab.c
	flex -o lexer/lex.yy.c lexer/lexer.l
	gcc parser/parser.tab.c lexer/lex.yy.c src/*.c intermediate_code/*.c -Iinclude -o compiler
	./compiler < examples/sample1.src intermediate_code/*.c
