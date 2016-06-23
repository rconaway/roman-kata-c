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

int digit_to_arabic(char digit) {
    switch(digit) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return -1;
}

int sum_digits(ARABIC *arabic, ROMAN roman) {
    char* cp;
    int digit;

    *arabic = 0;

    for (cp = roman; *cp; cp++) {
        digit = digit_to_arabic(*cp);
        if (digit < 0) {
            return INVALID_ROMAN_NUMBER;
        }
        *arabic += digit;
    }

    return OK;
}

struct compression_table_elt {
    char* compressed;
    char* uncompressed;
} compression_table[] = {
        {"IV", "IIII"},
        {"IX", "VIIII"},
        {"XL", "XXXX"},
        {"XC", "LXXXX"},
        {"CD", "CCCC"},
        {"CM", "DCCCC"},
        {NULL, NULL}
};

int simplify_roman(ROMAN simplified, ROMAN complex) {
    char *cp, *sp;
    struct compression_table_elt* te;

    sp = simplified;
    cp = complex;

    outer:
    while(*cp) {
        for (te = compression_table; te->compressed; te++) {
            if (strncmp(cp, te->compressed, strlen(te->compressed)) == 0) {
                strcpy(sp, te->uncompressed);
                sp += strlen(te->uncompressed);
                cp += strlen(te->compressed);
                goto outer;
            }
        }

        *(cp++) = *(sp++);
    }

    *sp = 0;
    return OK;
}



