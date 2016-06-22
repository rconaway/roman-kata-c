//
// Created by Robert Conaway on 6/21/16.
//

#ifndef ROMANNUMERALS_ROMANNUMERALS_H
#define ROMANNUMERALS_ROMANNUMERALS_H

#define OK 0
#define INVALID_ROMAN_NUMBER 1

typedef char ROMAN[50];

typedef int ARABIC;

int sum_digits(ARABIC* arabic, ROMAN roman);

char* add(char* sum, int sumLen, char* addend1, char* addend2);

char* subtract(char* difference, int differenceLen, char* minuend, char* subtrahend);

int prompt(int argc, char** argv);

#endif //ROMANNUMERALS_ROMANNUMERALS_H
