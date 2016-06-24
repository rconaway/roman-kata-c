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

#define ASSERT_VALID_ROMAN(number) ASSERT_OK(validate_roman(number))
#define ASSERT_INVALID_ROMAN(number) ASSERT_ERROR(validate_roman(number), INVALID_ROMAN_NUMBER)

START_TEST(rejects_non_roman_digits) {
    ASSERT_INVALID_ROMAN("A");
} END_TEST

START_TEST(accepts_a_roman_number_with_all_valid_digits) {
    ASSERT_VALID_ROMAN("IVXLCDM");
} END_TEST

START_TEST(unit_digits_may_not_have_more_than_3_repetitions) {
    ASSERT_INVALID_ROMAN("IIII");
    ASSERT_INVALID_ROMAN("XXXX");
    ASSERT_INVALID_ROMAN("CCCC");
} END_TEST

START_TEST(five_digits_may_not_have_repetitions) {
    ASSERT_INVALID_ROMAN("VV");
    ASSERT_INVALID_ROMAN("LL");
    ASSERT_INVALID_ROMAN("DD");
} END_TEST

#define ASSERT_SUM_DIGITS(a, r) rc = sum_digits(&arabic, r); ck_assert_int_eq(arabic, a)

START_TEST(converts_each_digit_to_its_correct_arabic_value) {
    ASSERT_SUM_DIGITS(1, "I");
    ASSERT_SUM_DIGITS(5, "V");
    ASSERT_SUM_DIGITS(10, "X");
    ASSERT_SUM_DIGITS(50, "L");
    ASSERT_SUM_DIGITS(100, "C");
    ASSERT_SUM_DIGITS(500, "D");
    ASSERT_SUM_DIGITS(1000, "M");
} END_TEST

START_TEST(converts_sequence_of_digits_by_adding_their_corresponding_arabic_values) {
    ASSERT_SUM_DIGITS(1666, "IVXLCDM");
} END_TEST

#define ASSERT_SIMPLIFY(s, c) ASSERT_OK(simplify_roman(roman, c)); ck_assert_str_eq(roman, s)

START_TEST(lesser_number_modifies_larger_number) {
    ASSERT_SIMPLIFY("IIII", "IV");
    ASSERT_SIMPLIFY("VIIII", "IX");
    ASSERT_SIMPLIFY("XXXX", "XL");
    ASSERT_SIMPLIFY("LXXXX", "XC");
    ASSERT_SIMPLIFY("CCCC", "CD");
    ASSERT_SIMPLIFY("DCCCC", "CM");
} END_TEST

START_TEST(simplifies_birthday) {
    ASSERT_SIMPLIFY("MDCCCCLVIII","MCMLVIII");
} END_TEST

#define ASSERT_TO_ARABIC(a, roman) ASSERT_OK(to_arabic(&arabic, roman)); ck_assert_int_eq(arabic, a)

START_TEST(converts_birthday_to_arabic) {
    ASSERT_TO_ARABIC(1958, "MCMLVIII");
} END_TEST

Suite* suite(void) {
    Suite * suite;
    TCase *tc_validate_roman, *tc_sum_digits, *tc_simplify_roman, *tc_to_arabic;

    suite = suite_create("Roman Math Suite");

    tc_validate_roman = tcase_create("Validate Roman number");
    tcase_add_test(tc_validate_roman, rejects_non_roman_digits);
    tcase_add_test(tc_validate_roman, accepts_a_roman_number_with_all_valid_digits);
    tcase_add_test(tc_validate_roman, unit_digits_may_not_have_more_than_3_repetitions);
    tcase_add_test(tc_validate_roman, five_digits_may_not_have_repetitions);
    suite_add_tcase(suite, tc_validate_roman);

    tc_sum_digits = tcase_create("Sum digits of Roman number");
    tcase_add_test(tc_sum_digits, converts_each_digit_to_its_correct_arabic_value);
    tcase_add_test(tc_sum_digits, converts_sequence_of_digits_by_adding_their_corresponding_arabic_values);
    suite_add_tcase(suite, tc_sum_digits);

    tc_simplify_roman = tcase_create("Simplify Roman numeral to a simple sequence of digits");
    tcase_add_test(tc_simplify_roman, lesser_number_modifies_larger_number);
    tcase_add_test(tc_simplify_roman, simplifies_birthday);
    suite_add_tcase(suite, tc_simplify_roman);

    tc_to_arabic = tcase_create("Convert Roman to Arabic");
    tcase_add_test(tc_to_arabic, converts_birthday_to_arabic);
    suite_add_tcase(suite, tc_to_arabic);

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
