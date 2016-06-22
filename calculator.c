#include "include/roman_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    char result[50];

    if (argc != 3) {
        printf("Please enter NUMBER + NUMBER or NUMBER - NUMBER\n");
        return -1;
    }

    if (strcmp(argv[1], "+") == 0) {
        add(result, sizeof(result), argv[0], argv[2]);
    } else if (strcmp(argv[1], "-") == 0) {
        subtract(result, sizeof(result), argv[0], argv[2]);
    } else {
        printf("Operator must be + or -, found %s\n", argv[1]);
    }

    printf("%s\n", result);
    return 0;

}
