#include "include/to_arabic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

STATUS add(char* sum, int sumLen, char* addend1, char* addend2) {
    strcpy(sum, addend1);
    strcat(sum, " + ");
    strcat(sum, addend2);
    return OK;
}

STATUS subtract(char* difference, int differenceLen, char* minuend, char* subtrahend) {
    strcpy(difference, minuend);
    strcat(difference, " - ");
    strcat(difference, subtrahend);
    return OK;
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

STATUS sum_digits(ARABIC *arabic, ROMAN roman) {
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

struct compression_table_elt* findCompression(char* compressed) {
    struct compression_table_elt* te;

    for (te = compression_table; te->compressed != NULL; te++) {
        if (strncmp(compressed, te->compressed, strlen(te->compressed)) == 0) {
            return te;
        }
    }
    return NULL;
}

STATUS simplify_roman(ROMAN simplified, ROMAN complex) {
    char *cp, *sp;
    struct compression_table_elt* te;

    sp = simplified;
    cp = complex;

    while(*cp) {
        te = findCompression(cp);
        if (te != NULL) {
            strcpy(sp, te->uncompressed);
            sp += strlen(te->uncompressed);
            cp += strlen(te->compressed);
        } else {
            *(sp++) = *(cp++);
        }
    }

    *sp = 0;
    return OK;
}

char* valid_digits = "IVXLCDM";

bool validate_digits(ROMAN number) {
    char* cp;

    for (cp = number; *cp; cp++) {
        if (strchr(valid_digits, *cp) == NULL) {
            return false;
        }
    }

    return true;
}

char* prohibited_repetitions[] = {
        "IIII", "XXXX", "CCCC", "VV", "LL", "DD", NULL
};

bool validate_repetitions(ROMAN number) {
    char * cp;
    char ** rp;

    for (cp = number; *cp; cp++) {
        for (rp = prohibited_repetitions; *rp; rp++) {
            if (strncmp(cp, *rp, strlen(*rp)) == 0) {
                return false;
            }
        }
    }
    return true;
}

STATUS validate_roman(ROMAN number) {
    if (validate_digits(number) && validate_repetitions(number)) {
        return OK;
    } else {
        return INVALID_ROMAN_NUMBER;
    }
}

STATUS to_arabic(ARABIC* arabic, ROMAN roman) {
    STATUS status;
    ROMAN simple;

    status = validate_roman(roman);
    if (status == OK) {
        status = simplify_roman(simple, roman);
    }

    if (status == OK) {
        status = sum_digits(arabic, simple);
    }

    return status;
}
