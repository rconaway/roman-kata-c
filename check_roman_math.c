#include "include/roman_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <check.h>

int rc;
ROMAN roman;

#define ASSERT_OK(ex) ck_assert_int_eq(ex, OK)
#define ASSERT_ERROR(ex, error) ck_assert_int_eq(ex, error)

START_TEST(calculate_year_from_birthday_and_age) {
    ASSERT_OK(add(roman, "MCMLVIII", "LVIII"));
    ck_assert_str_eq(roman, "MMXVI");
} END_TEST

START_TEST(calculate_age_from_current_and_birthday) {
    ASSERT_OK(subtract(roman, "MMXVI", "MCMLVIII"));
    ck_assert_str_eq(roman, "LVIII");
} END_TEST

Suite * suite(void) {
    Suite * suite;
    TCase *tc_add, *tc_subtract;

    suite = suite_create("Roman Math");

    tc_add = tcase_create("Add Roman numbers");
    tcase_add_test(tc_add, calculate_year_from_birthday_and_age);
    suite_add_tcase(suite, tc_add);

    tc_subtract = tcase_create("Subtract Roman numbers");
    tcase_add_test(tc_subtract, calculate_age_from_current_and_birthday);
    suite_add_tcase(suite, tc_subtract);

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
