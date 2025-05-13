#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int tempCount = 0;
static int labelCount = 0;

char* nextTemp() {
    char* temp = (char*)malloc(10); // Enough for "t" + number
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

char* nextLabel() {
    char* label = (char*)malloc(10); // Enough for "L" + number
    sprintf(label, "L%d", labelCount++);
    return label;
}