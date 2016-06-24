#include "include/to_arabic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

STATUS validate_arabic(ARABIC arabic) {
    if (arabic < 0) {
        return ARABIC_CANNOT_BE_NEGATIVE;
    }

    return OK;
}

struct digit_elt {
    char* digit;
    int value;
} digit_table[] = {
        {"M", 1000},
        {"D", 500},
        {"C", 100},
        {"L", 50},
        {"X", 10},
        {"V", 5},
        {"I", 1},
        {NULL, 0}
};

int extract_digit(char* rp, int remainder) {
    struct digit_elt* te;

    for (te = digit_table; te->digit != NULL; te++) {
        if (te->value <= remainder) {
            *rp = *(te->digit);
            return remainder - te->value;
        }
    }

    // should never get here
    return 0;
}

STATUS arabic_to_simplified_roman(ROMAN roman, ARABIC arabic) {
    char* rp;

    rp = roman;
    while(arabic > 0) {
        arabic = extract_digit(rp++, arabic);
    }
    *rp = 0;

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

struct compression_table_elt* findUncompressed(char* uncompressed) {
    struct compression_table_elt* te;

    for (te = compression_table; te->compressed != NULL; te++) {
        if (strncmp(uncompressed, te->uncompressed, strlen(te->uncompressed)) == 0) {
            return te;
        }
    }
    return NULL;
}

STATUS simplified_to_compressed(ROMAN compressed, ROMAN simplified) {
    char *cp, *sp;
    struct compression_table_elt* te;

    sp = simplified;
    cp = compressed;

    while(*sp) {
        te = findUncompressed(sp);
        if (te != NULL) {
            strcpy(cp, te->compressed);
            sp += strlen(te->uncompressed);
            cp += strlen(te->compressed);
        } else {
            *(cp++) = *(sp++);
        }
    }

    *cp = 0;
    return OK;

}

STATUS to_roman(ROMAN roman, ARABIC arabic) {
    STATUS status;
    ROMAN simplified;

    status = validate_arabic(arabic);

    if (status == OK) {
        status = arabic_to_simplified_roman(simplified, arabic);
    }
    if (status == OK) {
        status =  simplified_to_compressed(roman, simplified);
    }

    return OK;
}
