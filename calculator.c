#include "include/to_arabic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    char result[50];

    if (argc != 4) {
        printf("Please enter NUMBER + NUMBER or NUMBER - NUMBER\n");
        return -1;
    }

    if (strcmp(argv[2], "+") == 0) {
        add(result, argv[1], argv[3]);
    } else if (strcmp(argv[2], "-") == 0) {
        subtract(result, argv[1], argv[3]);
    } else {
        printf("Operator must be + or -, found %s\n", argv[2]);
    }

    printf("%s\n", result);
    return 0;

}
