#include "../s21_matrix_tests.h"

START_TEST(s21_eq_matrix_1) {
  matrix_t a, b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 2;
  a.matrix[0][1] = 5;
  a.matrix[1][0] = 6;
  a.matrix[1][1] = 3;

  b.matrix[0][0] = 2;
  b.matrix[0][1] = 5;
  b.matrix[0][2] = 5;
  b.matrix[1][0] = 6;
  b.matrix[1][1] = 3;
  b.matrix[1][2] = 3;
  b.matrix[2][0] = 6;
  b.matrix[2][1] = 3;
  b.matrix[2][2] = 3;

  int err_detector = s21_eq_matrix(&a, &b);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, FAILURE_COMPARSION);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t a, b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  s21_zero_matrix(&a);
  s21_zero_matrix(&b);

  int err_detector = s21_eq_matrix(&a, &b);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t a, b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 2;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 5;
  a.matrix[1][0] = 6;
  a.matrix[1][1] = 3;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 6;
  a.matrix[2][1] = 3;
  a.matrix[2][2] = 3;

  b.matrix[0][0] = 2;
  b.matrix[0][1] = 5;
  b.matrix[0][2] = 5;
  b.matrix[1][0] = 6;
  b.matrix[1][1] = 3;
  b.matrix[1][2] = 3;
  b.matrix[2][0] = 6;
  b.matrix[2][1] = 3;
  b.matrix[2][2] = 3;

  int err_detector = s21_eq_matrix(&a, &b);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, SUCCESS_COMPARSION);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t a, b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 2;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 5;
  a.matrix[1][0] = 6;
  a.matrix[1][1] = 3;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 6;
  a.matrix[2][1] = 3;
  a.matrix[2][2] = 3;

  b.matrix[0][0] = 6;
  b.matrix[0][1] = 3;
  b.matrix[0][2] = 3;
  b.matrix[1][0] = 2;
  b.matrix[1][1] = 5;
  b.matrix[1][2] = 5;
  b.matrix[2][0] = 6;
  b.matrix[2][1] = 3;
  b.matrix[2][2] = 3;

  int err_detector = s21_eq_matrix(&a, &b);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, FAILURE_COMPARSION);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_fill(&temp, 1.0, 1);
  s21_fill(&temp2, 1.0, 1);
  temp2.matrix[1][1] = 0;
  temp2.matrix[1][2] = 77;
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), FAILURE_COMPARSION);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(2, 3, &temp2);
  s21_fill(&temp, 1.0, 1);
  s21_fill(&temp2, 1.0, 1);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), FAILURE_COMPARSION);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(s21_eq_matrix_7) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 21, &temp2);
  s21_fill(&temp, 1.0, 1);
  s21_fill(&temp2, 1.0, 1);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), FAILURE_COMPARSION);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(s21_eq_matrix_8) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_fill(&temp, 1.0, 1);
  s21_fill(&temp2, 1.0, 1);
  temp.matrix[0][1] = 4.67773;
  temp2.matrix[0][1] = 4.67774;
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), FAILURE_COMPARSION);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(s21_eq_matrix_9) {
  matrix_t a, b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 2;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 5;
  a.matrix[1][0] = 6;
  a.matrix[1][1] = 3;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 6;
  a.matrix[2][1] = 3;
  a.matrix[2][2] = 3.0;

  b.matrix[0][0] = 2;
  b.matrix[0][1] = 5;
  b.matrix[0][2] = 5;
  b.matrix[1][0] = 6;
  b.matrix[1][1] = 3;
  b.matrix[1][2] = 3;
  b.matrix[2][0] = 6;
  b.matrix[2][1] = 3;
  b.matrix[2][2] = 3.001;

  int err_detector = s21_eq_matrix(&a, &b);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, FAILURE_COMPARSION);
}
END_TEST

Suite *s21_eq_matrix_suite() {
  Suite *s21_matrix_eq;
  TCase *tc_eq_matrix;
  s21_matrix_eq = suite_create("eq");

  tc_eq_matrix = tcase_create("eq");
  tcase_add_test(tc_eq_matrix, s21_eq_matrix_1);
  tcase_add_test(tc_eq_matrix, s21_eq_matrix_2);
  tcase_add_test(tc_eq_matrix, s21_eq_matrix_3);
  tcase_add_test(tc_eq_matrix, s21_eq_matrix_4);
  tcase_add_test(tc_eq_matrix, s21_eq_matrix_5);
  tcase_add_test(tc_eq_matrix, s21_eq_matrix_6);
  tcase_add_test(tc_eq_matrix, s21_eq_matrix_7);
  tcase_add_test(tc_eq_matrix, s21_eq_matrix_8);
  tcase_add_test(tc_eq_matrix, s21_eq_matrix_9);
  suite_add_tcase(s21_matrix_eq, tc_eq_matrix);

  return s21_matrix_eq;
}