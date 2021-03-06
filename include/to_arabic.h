//
// Created by Robert Conaway on 6/21/16.
//

#ifndef TO_ARABIC_H
#define TO_ARABIC_H

#include "common.h"

STATUS validate_roman(ROMAN number);
STATUS sum_digits(ARABIC* arabic, ROMAN roman);
STATUS simplify_roman(ROMAN simplified, ROMAN complex);
STATUS to_arabic(ARABIC* arabic, ROMAN roman);

#endif
