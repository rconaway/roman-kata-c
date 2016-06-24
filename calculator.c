#include "include/roman_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    STATUS status;
    ROMAN result;

    if (argc != 4) {
        printf("Please enter NUMBER + NUMBER or NUMBER - NUMBER\n");
        return -1;
    }

    if (strcmp(argv[2], "+") == 0) {
        status = add(result, argv[1], argv[3]);
        if (status != OK) {
            printf("Invalid number\n");
            return -1;
        }
    } else if (strcmp(argv[2], "-") == 0) {
        status = subtract(result, argv[1], argv[3]);
        if (status != OK) {
            printf("Invalid number\n");
            return -1;
        }
    } else {
        printf("Operator must be + or -, found %s\n", argv[2]);
        return -1;
    }

    printf("%s\n", result);
    return 0;

}
