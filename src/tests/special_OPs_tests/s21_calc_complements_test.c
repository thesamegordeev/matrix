#include "../s21_matrix_tests.h"

START_TEST(s21_calc_complements_1) {
  matrix_t a, result, result_to_compare;

  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &result_to_compare);

  a.matrix[0][0] = 5;
  a.matrix[0][1] = 7;
  a.matrix[0][2] = 1;

  a.matrix[1][0] = -4;
  a.matrix[1][1] = 1;
  a.matrix[1][2] = 0;

  a.matrix[2][0] = 2;
  a.matrix[2][1] = 0;
  a.matrix[2][2] = 3;

  result_to_compare.matrix[0][0] = 3;
  result_to_compare.matrix[0][1] = 12;
  result_to_compare.matrix[0][2] = -2;

  result_to_compare.matrix[1][0] = -21;
  result_to_compare.matrix[1][1] = 13;
  result_to_compare.matrix[1][2] = 14;

  result_to_compare.matrix[2][0] = -1;
  result_to_compare.matrix[2][1] = -4;
  result_to_compare.matrix[2][2] = 33;

  int err_detector = s21_calc_complements(&a, &result);
  int eq_detector = s21_eq_matrix(&result, &result_to_compare);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_to_compare);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t a, result, result_to_compare;

  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &result_to_compare);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;

  a.matrix[1][0] = 0;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 2;

  a.matrix[2][0] = 5;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 1;

  result_to_compare.matrix[0][0] = 0;
  result_to_compare.matrix[0][1] = 10;
  result_to_compare.matrix[0][2] = -20;

  result_to_compare.matrix[1][0] = 4;
  result_to_compare.matrix[1][1] = -14;
  result_to_compare.matrix[1][2] = 8;

  result_to_compare.matrix[2][0] = -8;
  result_to_compare.matrix[2][1] = -2;
  result_to_compare.matrix[2][2] = 4;

  int err_detector = s21_calc_complements(&a, &result);
  int eq_detector = s21_eq_matrix(&result, &result_to_compare);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_to_compare);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t a, result;

  s21_create_matrix(3, 4, &a);

  int err_detector = s21_calc_complements(&a, &result);
  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, CALCULATION_ERR);
}
END_TEST

Suite *s21_mult_calc_complements_suite() {
  Suite *s21_matrix_calc_complements;
  TCase *tc_calc_complements;
  s21_matrix_calc_complements = suite_create("calc_complements");

  tc_calc_complements = tcase_create("calc_complements");
  tcase_add_test(tc_calc_complements, s21_calc_complements_1);
  tcase_add_test(tc_calc_complements, s21_calc_complements_2);
  tcase_add_test(tc_calc_complements, s21_calc_complements_3);
  suite_add_tcase(s21_matrix_calc_complements, tc_calc_complements);

  return s21_matrix_calc_complements;
}