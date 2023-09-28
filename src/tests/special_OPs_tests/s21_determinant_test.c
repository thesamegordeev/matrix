#include "../s21_matrix_tests.h"

START_TEST(s21_determinant_1) {
  matrix_t a;
  double result = 0.0, result_to_compare = -12.0;

  s21_create_matrix(3, 3, &a);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 3;
  a.matrix[0][2] = 4;

  a.matrix[1][0] = 0;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 1;

  a.matrix[2][0] = 1;
  a.matrix[2][1] = 5;
  a.matrix[2][2] = -1;

  int err_detector = s21_determinant(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_double_eq(result, result_to_compare);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t a;
  double result = 0.0, result_to_compare = -1926.0;

  s21_create_matrix(4, 4, &a);

  a.matrix[0][0] = -4;
  a.matrix[0][1] = -2;
  a.matrix[0][2] = -7;
  a.matrix[0][3] = 8;

  a.matrix[1][0] = 2;
  a.matrix[1][1] = 7;
  a.matrix[1][2] = 4;
  a.matrix[1][3] = 9;

  a.matrix[2][0] = 2;
  a.matrix[2][1] = 0;
  a.matrix[2][2] = 6;
  a.matrix[2][3] = -3;

  a.matrix[3][0] = 6;
  a.matrix[3][1] = 4;
  a.matrix[3][2] = -10;
  a.matrix[3][3] = -4;

  int err_detector = s21_determinant(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_double_eq(result, result_to_compare);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t a;
  double result = 0.0, result_to_compare = 64.0;

  s21_create_matrix(5, 5, &a);

  a.matrix[0][0] = 4;
  a.matrix[0][1] = 1;
  a.matrix[0][2] = 1;
  a.matrix[0][3] = 2;
  a.matrix[0][4] = 1;

  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = -1;
  a.matrix[1][3] = 1;
  a.matrix[1][4] = 1;

  a.matrix[2][0] = 3;
  a.matrix[2][1] = 1;
  a.matrix[2][2] = 1;
  a.matrix[2][3] = 1;
  a.matrix[2][4] = 1;

  a.matrix[3][0] = 2;
  a.matrix[3][1] = 1;
  a.matrix[3][2] = 1;
  a.matrix[3][3] = 4;
  a.matrix[3][4] = 1;

  a.matrix[4][0] = 2;
  a.matrix[4][1] = -1;
  a.matrix[4][2] = 1;
  a.matrix[4][3] = 1;
  a.matrix[4][4] = 5;

  int err_detector = s21_determinant(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_double_eq(result, result_to_compare);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t a;
  double result = 0.0;

  s21_create_matrix(3, 4, &a);

  int err_detector = s21_determinant(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, CALCULATION_ERR);
}
END_TEST

Suite *s21_determinant_suite() {
  Suite *s21_matrix_determinant;
  TCase *tc_determinant;
  s21_matrix_determinant = suite_create("determinant");

  tc_determinant = tcase_create("determinant");
  tcase_add_test(tc_determinant, s21_determinant_1);
  tcase_add_test(tc_determinant, s21_determinant_2);
  tcase_add_test(tc_determinant, s21_determinant_3);
  tcase_add_test(tc_determinant, s21_determinant_4);
  suite_add_tcase(s21_matrix_determinant, tc_determinant);

  return s21_matrix_determinant;
}