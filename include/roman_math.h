//
// Created by Robert Conaway on 6/21/16.
//

#ifndef ROMAN_MATH_H
#define ROMAN_MATH_H

#include <stdbool.h>

typedef char ROMAN[50];

typedef int ARABIC;

typedef enum {OK, INVALID_ROMAN_NUMBER} STATUS;

STATUS validate_roman(ROMAN number);
STATUS sum_digits(ARABIC* arabic, ROMAN roman);
STATUS simplify_roman(ROMAN simplified, ROMAN complex);
STATUS to_arabic(ARABIC* arabic, ROMAN roman);
STATUS add(char* sum, int sumLen, char* addend1, char* addend2);
STATUS subtract(char* difference, int differenceLen, char* minuend, char* subtrahend);

#endif //ROMAN_MATH_H
