#include "../s21_matrix_tests.h"

START_TEST(s21_create_matrix_1) {
  matrix_t result;
  int check = s21_create_matrix(5, 5, &result);
  s21_remove_matrix(&result);

  ck_assert_int_eq(check, SUCCESS);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t result;
  int check = s21_create_matrix(-10, 0, &result);
  ck_assert_int_eq(check, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t result;
  int check = s21_create_matrix(2, 1, &result);
  s21_remove_matrix(&result);

  ck_assert_int_eq(check, SUCCESS);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t result;
  int check = s21_create_matrix(1, 1, &result);
  s21_remove_matrix(&result);

  ck_assert_int_eq(check, SUCCESS);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t result;
  int check = s21_create_matrix(2000, 1000, &result);
  s21_remove_matrix(&result);

  ck_assert_int_eq(check, SUCCESS);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  matrix_t result;
  int check = s21_create_matrix(0, 0, &result);
  ck_assert_int_eq(check, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  matrix_t result;
  int check = s21_create_matrix(1, 0, &result);
  ck_assert_int_eq(check, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  matrix_t result;
  int check = s21_create_matrix(0, 1, &result);
  ck_assert_int_eq(check, INCORRECT_MATRIX);
}
END_TEST

Suite *s21_create_matrix_suite() {
  Suite *s21_matrix_create;
  TCase *tc_create_matrix;

  s21_matrix_create = suite_create("create");

  tc_create_matrix = tcase_create("create");
  tcase_add_test(tc_create_matrix, s21_create_matrix_1);
  tcase_add_test(tc_create_matrix, s21_create_matrix_2);
  tcase_add_test(tc_create_matrix, s21_create_matrix_3);
  tcase_add_test(tc_create_matrix, s21_create_matrix_4);
  tcase_add_test(tc_create_matrix, s21_create_matrix_5);
  tcase_add_test(tc_create_matrix, s21_create_matrix_6);
  tcase_add_test(tc_create_matrix, s21_create_matrix_7);
  tcase_add_test(tc_create_matrix, s21_create_matrix_8);
  suite_add_tcase(s21_matrix_create, tc_create_matrix);

  return s21_matrix_create;
}