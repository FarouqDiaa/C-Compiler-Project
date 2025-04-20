#include <stdio.h>
#include "semantic_analyzer.h"

extern int yyparse();

int main() {
    yyparse();
    semantic_analysis();
    return 0;
}
