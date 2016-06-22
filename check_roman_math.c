#include "include/roman_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstTest() {
    char sum[10];
    add(sum, sizeof(sum), "I", "I");

    if (strcmp(sum, "II") != 0) {
        printf("firstTest failed\n");
        return 1;
    }

    printf("firstTest succeeded\n");
    return 0;
}

int secondTest() {
    char sum[10];
    add(sum, sizeof(sum), "I", "I");

    if (strcmp(sum, "I + I") != 0) {
        printf("secondTest failed\n");
        return 1;
    }

    printf("secondTest succeeded\n");
    return 0;
}

int main() {

    int failures = 0;

    failures += firstTest();

    if (failures == 0) {
        printf("success\n");
    } else {
        printf("%d failures\n", failures);
    }

}
