all:
	bison -d parser/parser.y -o output/y.tab.c
	flex -o output/lex.yy.c lexer/lexer.l
	gcc output/y.tab.c output/lex.yy.c src/*.c -Iinclude -o output/compiler
