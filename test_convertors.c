#include "convertors.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_int_to_dec_1)
{
  s21_decimal test_dec = { {0, 0, 0, 0} };
  int param = 5;

  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(test_int_to_dec_2)
{
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int param = 2147483647;

  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483647);
  ck_assert_float_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(test_int_to_dec_3)
{
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int param = -2147483648;

  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483648);
  ck_assert_float_eq(test_dec.bits[3], 2147483648);
}
END_TEST

START_TEST(test_int_to_dec_4)
{
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int param = -5;

  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 2147483648);
}
END_TEST

START_TEST(test_dec_to_int_1)
{
  s21_decimal test_dec = {{20, 0, 0, 0}};
  int param = 0, need_param = 20, error = 0;
  int func_error = s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(param, need_param);
  ck_assert_int_eq(error, func_error);
}
END_TEST

START_TEST(test_dec_to_int_2)
{
  s21_decimal test_dec = {{20, 0, 0, 2147483648}};
  int param;
  s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(param, -20);
}
END_TEST

START_TEST(test_dec_to_int_3)
{
  s21_decimal test_dec = {{2147483648, 0, 0, 2147483648}};
  int param, need_param = -2147483648;
  s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(param, need_param);
}
END_TEST

START_TEST(test_dec_to_int_4)
{
  s21_decimal test_dec = {{2147483647, 0, 1, 2147483648}};
  int param;
  int error = s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(test_dec_to_int_5)
{
  s21_decimal test_dec = {{2147483647, 1, 0, 2147483648}};
  int param;
  int error = s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(test_dec_to_int_6)
{
  s21_decimal test_dec = {{2147483647, 1, 0, 0x30000}}; // exp = 3
  int param;
  s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(param, 6442450);
}
END_TEST

START_TEST(test_float_to_dec_1) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 5.0, need_param = 5.0;
  int need_3_bit = 0;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], need_param);
  ck_assert_float_eq(test_dec.bits[3], need_3_bit);
}
END_TEST

START_TEST(test_float_to_dec_2) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 0.05;

  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 131072);
}
END_TEST

START_TEST(test_float_to_dec_3) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 0.005;

  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 196608);
}
END_TEST

START_TEST(test_float_to_dec_4) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = -0.5;

  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 2147549184);
}
END_TEST

START_TEST(test_float_to_dec_5) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = -0.05;

  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 2147614720);
}
END_TEST

START_TEST(test_float_to_dec_6) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 50;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 50);
  ck_assert_float_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(test_float_to_dec_7) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 5000;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5000);
  ck_assert_float_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(test_float_to_dec_8) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 2147483;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483);
  ck_assert_float_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(test_float_to_dec_9) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 0.2147483;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483);
  ck_assert_float_eq(test_dec.bits[3], 458752);
}
END_TEST

START_TEST(test_float_to_dec_10) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = -0.2147483;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483);
  ck_assert_float_eq(test_dec.bits[3], 458752 + 2147483648);
}
END_TEST

START_TEST(test_float_to_dec_11) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = -2147483;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483);
  ck_assert_float_eq(test_dec.bits[3], 2147483648);
}
END_TEST

Suite *test_convertors(void)
{
  Suite *s = suite_create("convertors");
  TCase *tc = tcase_create("convertors");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_int_to_dec_1);
  tcase_add_test(tc, test_int_to_dec_2);
  tcase_add_test(tc, test_int_to_dec_3);
  tcase_add_test(tc, test_int_to_dec_4);
  tcase_add_test(tc, test_dec_to_int_1);
  tcase_add_test(tc, test_dec_to_int_2);
  tcase_add_test(tc, test_dec_to_int_3);
  tcase_add_test(tc, test_dec_to_int_4);
  tcase_add_test(tc, test_dec_to_int_5);
  tcase_add_test(tc, test_dec_to_int_6);
  tcase_add_test(tc, test_float_to_dec_1);
  tcase_add_test(tc, test_float_to_dec_4);
  tcase_add_test(tc, test_float_to_dec_2);
  tcase_add_test(tc, test_float_to_dec_3);
  tcase_add_test(tc, test_float_to_dec_5);
  tcase_add_test(tc, test_float_to_dec_6);
  tcase_add_test(tc, test_float_to_dec_7);
  tcase_add_test(tc, test_float_to_dec_8);
  tcase_add_test(tc, test_float_to_dec_9);
  tcase_add_test(tc, test_float_to_dec_10);
  tcase_add_test(tc, test_float_to_dec_11);


  suite_add_tcase(s, tc);
  return s;
}

int main(void)
{
  Suite *convertors = test_convertors();
  SRunner *s21_math_tests_runner = srunner_create(convertors);

  int failed_count = 0;

  srunner_run_all(s21_math_tests_runner, CK_NORMAL);

  failed_count = srunner_ntests_failed(s21_math_tests_runner);

  srunner_free(s21_math_tests_runner);

  if (failed_count != 0)
  {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
