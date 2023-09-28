#include "../s21_matrix_tests.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t a, b, result, comp_res;

  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &b);
  s21_create_matrix(2, 2, &comp_res);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 1;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 1;
  a.matrix[1][2] = 2;

  b.matrix[0][0] = 1;
  b.matrix[0][1] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 1;
  b.matrix[2][0] = 1;
  b.matrix[2][1] = 1;

  comp_res.matrix[0][0] = 2;
  comp_res.matrix[0][1] = 3;
  comp_res.matrix[1][0] = 2;
  comp_res.matrix[1][1] = 3;

  int err_detector = s21_mult_matrix(&a, &b, &result);
  int eq_detector = s21_eq_matrix(&result, &comp_res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comp_res);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t a, b, result, comp_res;

  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &b);
  s21_create_matrix(3, 3, &comp_res);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 1;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 1;
  a.matrix[1][2] = 2;

  b.matrix[0][0] = 1;
  b.matrix[0][1] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 1;
  b.matrix[2][0] = 1;
  b.matrix[2][1] = 1;

  comp_res.matrix[0][0] = 1;
  comp_res.matrix[0][1] = 2;
  comp_res.matrix[0][2] = 1;
  comp_res.matrix[1][0] = 0;
  comp_res.matrix[1][1] = 1;
  comp_res.matrix[1][2] = 2;
  comp_res.matrix[2][0] = 1;
  comp_res.matrix[2][1] = 3;
  comp_res.matrix[2][2] = 3;

  int err_detector = s21_mult_matrix(&b, &a, &result);
  int eq_detector = s21_eq_matrix(&result, &comp_res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comp_res);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t a, b, result;

  s21_create_matrix(2, 4, &a);
  s21_create_matrix(3, 2, &b);

  int err_detector = s21_mult_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, CALCULATION_ERR);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t a, b, result;

  s21_create_matrix(2, 4, &a);
  s21_create_matrix(4, 3, &b);

  int err_detector = s21_mult_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, CALCULATION_ERR);
}
END_TEST

Suite *s21_mult_matrix_suite() {
  Suite *s21_matrix_mult_matrix;
  TCase *tc_mult_matrix;
  s21_matrix_mult_matrix = suite_create("mult_matrix");

  tc_mult_matrix = tcase_create("mult_matrix");
  tcase_add_test(tc_mult_matrix, s21_mult_matrix_1);
  tcase_add_test(tc_mult_matrix, s21_mult_matrix_2);
  tcase_add_test(tc_mult_matrix, s21_mult_matrix_3);
  tcase_add_test(tc_mult_matrix, s21_mult_matrix_4);
  suite_add_tcase(s21_matrix_mult_matrix, tc_mult_matrix);

  return s21_matrix_mult_matrix;
}