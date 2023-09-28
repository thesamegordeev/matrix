#include <check.h>

#include "../s21_matrix.h"

void s21_fill(matrix_t *matrixStruct, double value, double mnozh);

Suite *s21_sum_matrix_suite();
Suite *s21_sub_matrix_suite();
Suite *s21_mult_matrix_suite();
Suite *s21_mult_number_suite();
Suite *s21_eq_matrix_suite();
Suite *s21_create_matrix_suite();
Suite *s21_mult_calc_complements_suite();
Suite *s21_determinant_suite();
Suite *s21_inverse_suite();
Suite *s21_transpose_suite();