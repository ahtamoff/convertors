#include "convertors.h"
#include <check.h>
#include <stdlib.h>



START_TEST(test_int_to_dec_1) {
  s21_decimal test_dec = {0, 0, 0, 0};
  int param = 5;

  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(test_int_to_dec_2) {
  s21_decimal test_dec = {0, 0, 0, 0};
  int param = 2147483647;

  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483647);
  ck_assert_float_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(test_int_to_dec_3) {
  s21_decimal test_dec = {0, 0, 0, 0};
  int param = -2147483648;

  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483648);
  ck_assert_float_eq(test_dec.bits[3], 2147483648);
}
END_TEST

START_TEST(test_int_to_dec_4) {
  s21_decimal test_dec = {0, 0, 0, 0};
  int param = -5;

  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 2147483648);
}
END_TEST


Suite *test_convertors(void) {
  Suite *s = suite_create("convertors");
  TCase *tc = tcase_create("convertors");

  suite_add_tcase(s, tc);


  tcase_add_test(tc, test_int_to_dec_1);
  tcase_add_test(tc, test_int_to_dec_2);
  tcase_add_test(tc, test_int_to_dec_3);
  tcase_add_test(tc, test_int_to_dec_4);

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  Suite *convertors = test_convertors();
  SRunner *s21_math_tests_runner = srunner_create(convertors);

  int failed_count = 0;

  srunner_run_all(s21_math_tests_runner, CK_NORMAL);

  failed_count = srunner_ntests_failed(s21_math_tests_runner);

  srunner_free(s21_math_tests_runner);

  if (failed_count != 0) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
