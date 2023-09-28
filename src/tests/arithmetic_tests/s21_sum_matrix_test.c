#include "../s21_matrix_tests.h"

START_TEST(s21_sum_matrix_1) {
  matrix_t a, b, result, res;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(2, 3, &res);
  s21_create_matrix(2, 3, &b);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = -2;
  a.matrix[0][2] = 0;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = -2;
  a.matrix[1][2] = 1;

  b.matrix[0][0] = 10;
  b.matrix[0][1] = -2;
  b.matrix[0][2] = 0;
  b.matrix[1][0] = -4;
  b.matrix[1][1] = -2;
  b.matrix[1][2] = 1;

  res.matrix[0][0] = 11;
  res.matrix[0][1] = -4;
  res.matrix[0][2] = 0;
  res.matrix[1][0] = 0;
  res.matrix[1][1] = -4;
  res.matrix[1][2] = 2;

  int err_detector = s21_sum_matrix(&a, &b, &result);
  int eq_detector = s21_eq_matrix(&res, &result);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t a, b, result;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = -2;
  a.matrix[0][2] = 0;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = -2;
  a.matrix[1][2] = 1;

  b.matrix[0][0] = 10;
  b.matrix[0][1] = -2;
  b.matrix[0][2] = 0;
  b.matrix[1][0] = -4;

  int err_detector = s21_sum_matrix(&a, &b, &result);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, CALCULATION_ERR);
}
END_TEST

Suite *s21_sum_matrix_suite() {
  Suite *s21_matrix_sum;
  TCase *tc_sum_matrix;
  s21_matrix_sum = suite_create("sum");

  tc_sum_matrix = tcase_create("sum");
  tcase_add_test(tc_sum_matrix, s21_sum_matrix_1);
  tcase_add_test(tc_sum_matrix, s21_sum_matrix_2);
  suite_add_tcase(s21_matrix_sum, tc_sum_matrix);

  return s21_matrix_sum;
}