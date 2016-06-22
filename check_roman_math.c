#include "include/roman_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <check.h>

int i;

START_TEST(first_test)
{
    char sum[10];
    add(sum, sizeof(sum), "I", "I");

    ck_assert_str_eq(sum, "II");
}
END_TEST

START_TEST(second_test)
{
    char sum[10];
    add(sum, sizeof(sum), "I", "I");

    ck_assert_str_eq(sum, "I + I");
}

END_TEST

Suite * suite(void) {
    Suite *s;
    TCase *tc;

    s = suite_create("Roman Math Suite");
    tc = tcase_create("Roman Math Test");

    tcase_add_test(tc, first_test);
    tcase_add_test(tc, second_test);

    suite_add_tcase(s, tc);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
