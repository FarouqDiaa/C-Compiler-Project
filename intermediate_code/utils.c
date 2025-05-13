#include "utils.h"
#include <stdio.h>

int tempCount = 0;
int labelCount = 0;

int nextTemp() {
    return tempCount++;
}

int nextLabel() {
    return labelCount++;
}