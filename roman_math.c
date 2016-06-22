#include "include/roman_math.h"
#include <stdlib.h>
#include <string.h>

char* add(char* sum, int sumLen, char* addend1, char* addend2) {
    strcpy(sum, addend1);
    strcat(sum, " + ");
    strcat(sum, addend2);
    return sum;
}

char* subtract(char* difference, int differenceLen, char* minuend, char* subtrahend) {
    strcpy(difference, minuend);
    strcat(difference, " - ");
    strcat(difference, subtrahend);
    return difference;
}

