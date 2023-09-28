#include "../s21_matrix_tests.h"

START_TEST(s21_transpose_1) {
  matrix_t a, result, result_to_compare;

  s21_create_matrix(3, 2, &a);
  s21_fill(&a, 1.0, 1);
  s21_create_matrix(2, 3, &result_to_compare);

  result_to_compare.matrix[0][0] = 1;
  result_to_compare.matrix[0][1] = 3;
  result_to_compare.matrix[0][2] = 5;

  result_to_compare.matrix[1][0] = 2;
  result_to_compare.matrix[1][1] = 4;
  result_to_compare.matrix[1][2] = 6;

  int err_detector = s21_transpose(&a, &result);
  int eq_detector = s21_eq_matrix(&result, &result_to_compare);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_to_compare);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t a, result, result_to_compare;

  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 1.0;

  s21_create_matrix(1, 1, &result_to_compare);
  result_to_compare.matrix[0][0] = 1;

  int err_detector = s21_transpose(&a, &result);
  int eq_detector = s21_eq_matrix(&result, &result_to_compare);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_to_compare);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

Suite *s21_transpose_suite() {
  Suite *s21_matrix_transpose;
  TCase *tc_transpose;
  s21_matrix_transpose = suite_create("transpose");

  tc_transpose = tcase_create("transpose");
  tcase_add_test(tc_transpose, s21_transpose_1);
  tcase_add_test(tc_transpose, s21_transpose_2);

  suite_add_tcase(s21_matrix_transpose, tc_transpose);

  return s21_matrix_transpose;
}