#include "../s21_matrix_tests.h"

START_TEST(s21_mult_number_1) {
  matrix_t a, result, comp_res;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &comp_res);
  double num = 123;
  s21_fill(&a, 12, 1);
  s21_fill(&comp_res, 12, num);

  int err_detector = s21_mult_number(&a, num, &result);
  int eq_detector = s21_eq_matrix(&result, &comp_res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comp_res);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t a, result, comp_res;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &comp_res);
  double num = -1;
  s21_fill(&a, 12, 1);
  s21_fill(&comp_res, 12, num);

  int err_detector = s21_mult_number(&a, num, &result);
  int eq_detector = s21_eq_matrix(&result, &comp_res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comp_res);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_mult_number_3) {
  matrix_t a, result, comp_res;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &comp_res);
  double num = 0.0;
  s21_fill(&a, 12, 1);
  s21_fill(&comp_res, 0.0, 0.0);

  int err_detector = s21_mult_number(&a, num, &result);
  int eq_detector = s21_eq_matrix(&result, &comp_res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comp_res);

  ck_assert_int_eq(err_detector, SUCCESS);
  ck_assert_int_eq(eq_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_mult_number_4) {
  matrix_t a, result;
  s21_create_matrix(3, 3, &a);
  double num = 0.0 / 0.0;
  s21_fill(&a, 12, 1);

  int err_detector = s21_mult_number(&a, num, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number_5) {
  matrix_t a, result;
  s21_create_matrix(3, 3, &a);
  double num = 1.0 / 0.0;
  s21_fill(&a, 12, 1);

  int err_detector = s21_mult_number(&a, num, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number_6) {
  matrix_t a, result;
  s21_create_matrix(3, 3, &a);
  double num = -1.0 / 0.0;
  s21_fill(&a, 12, 1);

  int err_detector = s21_mult_number(&a, num, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, INCORRECT_MATRIX);
}
END_TEST

Suite *s21_mult_number_suite() {
  Suite *s21_matrix_mult_number;
  TCase *tc_mult_number;
  s21_matrix_mult_number = suite_create("mult_number");

  tc_mult_number = tcase_create("mult_number");
  tcase_add_test(tc_mult_number, s21_mult_number_1);
  tcase_add_test(tc_mult_number, s21_mult_number_2);
  tcase_add_test(tc_mult_number, s21_mult_number_3);
  tcase_add_test(tc_mult_number, s21_mult_number_4);
  tcase_add_test(tc_mult_number, s21_mult_number_5);
  tcase_add_test(tc_mult_number, s21_mult_number_6);
  suite_add_tcase(s21_matrix_mult_number, tc_mult_number);

  return s21_matrix_mult_number;
}