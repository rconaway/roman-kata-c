#include "include/roman_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <check.h>

int rc;
ARABIC arabic;
ROMAN roman;

START_TEST(rejects_non_roman_numbers) {
    rc = sum_digits(&arabic, "A");
    ck_assert_int_eq(rc, INVALID_ROMAN_NUMBER);
}

END_TEST

START_TEST(accepts_a_roman_number_with_all_valid_digits) {
    rc = sum_digits(&arabic, "IVXLCDM");
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(converts_each_digit_to_its_correct_arabic_value) {
    rc = sum_digits(&arabic, "I");
    ck_assert_int_eq(arabic, 1);

    rc = sum_digits(&arabic, "V");
    ck_assert_int_eq(arabic, 5);

    rc = sum_digits(&arabic, "X");
    ck_assert_int_eq(arabic, 10);

    rc = sum_digits(&arabic, "L");
    ck_assert_int_eq(arabic, 50);

    rc = sum_digits(&arabic, "C");
    ck_assert_int_eq(arabic, 100);

    rc = sum_digits(&arabic, "D");
    ck_assert_int_eq(arabic, 500);

    rc = sum_digits(&arabic, "M");
    ck_assert_int_eq(arabic, 1000);
}
END_TEST

START_TEST(converts_sequence_of_digits_by_adding_their_corresponding_arabic_values) {
    rc = sum_digits(&arabic, "IVXLCDM");
    ck_assert_int_eq(arabic, 1666);
}
END_TEST

Suite* suite(void) {
    Suite * s;
    TCase *tc_sum_digits;

    s = suite_create("Roman Math Suite");
    tc_sum_digits = tcase_create("Sum digits of Roman numeral");

    tcase_add_test(tc_sum_digits, rejects_non_roman_numbers);
    tcase_add_test(tc_sum_digits, accepts_a_roman_number_with_all_valid_digits);
    tcase_add_test(tc_sum_digits, converts_each_digit_to_its_correct_arabic_value);
    tcase_add_test(tc_sum_digits, converts_sequence_of_digits_by_adding_their_corresponding_arabic_values);

    suite_add_tcase(s, tc_sum_digits);

    return s;
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
