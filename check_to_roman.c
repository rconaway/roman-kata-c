#include "include/to_roman.h"
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

START_TEST(allows_positive_numbers) {
    ASSERT_OK(validate_arabic(1));
} END_TEST

START_TEST(does_not_allow_negative_arabic) {
    ASSERT_ERROR(validate_arabic(-1), ARABIC_CANNOT_BE_NEGATIVE);
} END_TEST

START_TEST(allows_zero) {
    ASSERT_OK(validate_arabic(0));
} END_TEST

#define ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN(r, a) ASSERT_OK(arabic_to_simplified_roman(roman, a)); ck_assert_str_eq(r, roman)
START_TEST(converts_single_digit_cases) {
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("I", 1);
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("V", 5);
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("X", 10);
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("L", 50);
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("C", 100);
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("D", 500);
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("M", 1000);
} END_TEST

START_TEST(converts_repeated_digit_cases) {
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("MMMM", 4000);
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("CCC", 300);
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("XX", 20);
} END_TEST

START_TEST(converts_birthday) {
    ASSERT_ARABIC_TO_SIMPLIFIED_ROMAN("MDCCCCLVIII", 1958);
} END_TEST

Suite * suite(void) {
    Suite * suite;
    TCase *tc_validate_arabic, *tc_arabic_to_simplified_roman, *tc_simplified_to_compressed, *tc_to_roman;

    suite = suite_create("To Roman");

    tc_validate_arabic = tcase_create("Validate Arabic number");
    tcase_add_test(tc_validate_arabic, allows_positive_numbers);
    tcase_add_test(tc_validate_arabic, does_not_allow_negative_arabic);
    tcase_add_test(tc_validate_arabic, allows_zero);
    suite_add_tcase(suite, tc_validate_arabic);

    tc_arabic_to_simplified_roman = tcase_create("Arabic to simplified Roman");
    tcase_add_test(tc_arabic_to_simplified_roman, converts_single_digit_cases);
    tcase_add_test(tc_arabic_to_simplified_roman, converts_repeated_digit_cases);
    tcase_add_test(tc_arabic_to_simplified_roman, converts_birthday);
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
