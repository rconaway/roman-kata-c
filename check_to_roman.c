#include "include/to_arabic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <check.h>

int rc;
ARABIC arabic;
ROMAN roman;

#define ASSERT_OK(ex) ck_assert_int_eq(ex, OK)
#define ASSERT_ERROR(ex, error) ck_assert_int_eq(ex, error)

Suite* suite(void) {
    Suite * suite;
    TCase *tc_validate_arabic, *tc_arabic_to_simplified_roman, *tc_simplified_to_compressed, *tc_to_roman;

    suite = suite_create("To Roman");

    tc_validate_arabic = tcase_create("Validate Arabic number");
    suite_add_tcase(suite, tc_validate_arabic);

    tc_arabic_to_simplified_roman = tcase_create("Arabic to simplified Roman");
    suite_add_tcase(suite, tc_arabic_to_simplified_roman);

    tc_simplified_to_compressed = tcase_create("Simplified Roman to compressed");
    suite_add_tcase(suite, tc_simplified_to_compressed);

    tc_to_roman = tcase_create("To Roman");
    suite_add_tcase(suite, tc_to_roman);

    return suite;
}

int main(void) {
    int number_failed;
    Suite * s;
    SRunner *sr;

    s = suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
