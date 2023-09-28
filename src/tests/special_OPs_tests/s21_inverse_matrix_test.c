#include "../s21_matrix_tests.h"

START_TEST(s21_inverse_1) {
  matrix_t a, result, result_to_compare;

  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 3;
  a.matrix[0][1] = 4;

  a.matrix[1][0] = 5;
  a.matrix[1][1] = 7;

  s21_create_matrix(2, 2, &result_to_compare);
  result_to_compare.matrix[0][0] = 7;
  result_to_compare.matrix[0][1] = -4;

  result_to_compare.matrix[1][0] = -5;
  result_to_compare.matrix[1][1] = 3;

  int err_detector = s21_inverse_matrix(&a, &result);
  int eq_detector = s21_eq_matrix(&result, &result_to_compare);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_to_compare);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_inverse_2) {
  matrix_t a, result, result_to_compare;

  s21_create_matrix(4, 4, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = 1;
  a.matrix[0][2] = 0;
  a.matrix[0][3] = 0;

  a.matrix[1][0] = 3;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 0;
  a.matrix[1][3] = 0;

  a.matrix[2][0] = 1;
  a.matrix[2][1] = 1;
  a.matrix[2][2] = 3;
  a.matrix[2][3] = 4;

  a.matrix[3][0] = 2;
  a.matrix[3][1] = -1;
  a.matrix[3][2] = 2;
  a.matrix[3][3] = 3;

  s21_create_matrix(4, 4, &result_to_compare);
  result_to_compare.matrix[0][0] = 2;
  result_to_compare.matrix[0][1] = -1;
  result_to_compare.matrix[0][2] = 0;
  result_to_compare.matrix[0][3] = 0;

  result_to_compare.matrix[1][0] = -3;
  result_to_compare.matrix[1][1] = 2;
  result_to_compare.matrix[1][2] = 0;
  result_to_compare.matrix[1][3] = 0;

  result_to_compare.matrix[2][0] = 31;
  result_to_compare.matrix[2][1] = -19;
  result_to_compare.matrix[2][2] = 3;
  result_to_compare.matrix[2][3] = -4;

  result_to_compare.matrix[3][0] = -23;
  result_to_compare.matrix[3][1] = 14;
  result_to_compare.matrix[3][2] = -2;
  result_to_compare.matrix[3][3] = 3;

  int err_detector = s21_inverse_matrix(&a, &result);
  int eq_detector = s21_eq_matrix(&result, &result_to_compare);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_to_compare);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_inverse_3) {
  matrix_t a, result;

  s21_create_matrix(3, 4, &a);

  int err_detector = s21_inverse_matrix(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, CALCULATION_ERR);
}
END_TEST

Suite *s21_inverse_suite() {
  Suite *s21_matrix_inverse;
  TCase *tc_inverse;
  s21_matrix_inverse = suite_create("inverse");

  tc_inverse = tcase_create("inverse");
  tcase_add_test(tc_inverse, s21_inverse_1);
  tcase_add_test(tc_inverse, s21_inverse_2);
  tcase_add_test(tc_inverse, s21_inverse_3);

  suite_add_tcase(s21_matrix_inverse, tc_inverse);

  return s21_matrix_inverse;
}