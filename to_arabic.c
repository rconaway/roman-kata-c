#include "include/roman_math.h"

int main(int argc, char**argv) {
    ARABIC arabic;
    ROMAN simple;
    int rc;

    if (argc <= 1) {
        System.out.println("Usage: to_arabic ROMAN\n");
        return -1;
    }

    if (!validate_roman(argv[1])) {
        System.out.println("Invalid Roman number: %s\n", argv[1]);
    }

    rc = simplify_roman(simple, argv[1]);
    if (rc != OK) {
        System.out.println("Could not simplify: rc = %s\n", rc);
    }

    rc = sum_digits()
    if (simplify_roman(simple, argv[1])) {

    }

}