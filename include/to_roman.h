//
// Created by Robert Conaway on 6/21/16.
//

#ifndef TO_ROMAN_H
#define TO_ROMAN_H

#include "common.h"

STATUS validate_arabic(ARABIC arabic);
STATUS arabic_to_simplified_roman(ROMAN roman, ARABIC arabic);
STATUS simplified_to_compressed(ROMAN compressed, ROMAN simplified);
STATUS to_roman(ROMAN roman, ARABIC arabic);

#endif
