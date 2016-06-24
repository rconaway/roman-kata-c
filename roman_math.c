#include "include/roman_math.h"
#include "include/to_arabic.h"
#include "include/to_roman.h"

STATUS add(ROMAN result, char* addend1, char* addend2) {
    ARABIC a1, a2;
    STATUS status;

    status = to_arabic(&a1, addend1);
    if (status == OK) {
        status = to_arabic(&a2, addend2);
    }
    if (status == OK) {
        status = to_roman(result, a1 + a2);
    }

    return status;
}

STATUS subtract(ROMAN result, char* minuend, char* subtrahend) {
    ARABIC a1, a2;
    STATUS status;

    status = to_arabic(&a1, minuend);
    if (status == OK) {
        status = to_arabic(&a2, subtrahend);
    }
    if (status == OK) {
        status = to_roman(result, a1 - a2);
    }

    return status;
}
