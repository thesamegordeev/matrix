#include "s21_matrix_tests.h"

int main() {
  Suite *suites[] = {s21_sum_matrix_suite(),
                     s21_sub_matrix_suite(),
                     s21_mult_matrix_suite(),
                     s21_mult_number_suite(),
                     s21_eq_matrix_suite(),
                     s21_create_matrix_suite(),
                     s21_mult_calc_complements_suite(),
                     s21_determinant_suite(),
                     s21_inverse_suite(),
                     s21_transpose_suite(),
                     NULL};

  for (int i = 0; suites[i] != NULL; i++, puts("")) {
    SRunner *runner = srunner_create(suites[i]);

    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }
}
