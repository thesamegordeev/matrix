#include "../s21_matrix_tests.h"

START_TEST(s21_sub_matrix_1) {
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

  res.matrix[0][0] = -9;
  res.matrix[0][1] = 0;
  res.matrix[0][2] = 0;
  res.matrix[1][0] = 8;
  res.matrix[1][1] = 0;
  res.matrix[1][2] = 0;

  int err_detector = s21_sub_matrix(&a, &b, &result);
  int eq_detector = s21_eq_matrix(&res, &result);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
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

  int err_detector = s21_sub_matrix(&a, &b, &result);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, CALCULATION_ERR);
}
END_TEST

Suite *s21_sub_matrix_suite() {
  Suite *s21_matrix_sub;
  TCase *tc_sub_matrix;
  s21_matrix_sub = suite_create("sub");

  tc_sub_matrix = tcase_create("sub");
  tcase_add_test(tc_sub_matrix, s21_sub_matrix_1);
  tcase_add_test(tc_sub_matrix, s21_sub_matrix_2);
  suite_add_tcase(s21_matrix_sub, tc_sub_matrix);

  return s21_matrix_sub;
}