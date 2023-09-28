#include "../s21_matrix.h"

/**
 * @brief Функция вычисляет обратную матрицу
 * @param A Указатель на матрицу matrix_t, из которой будет высчитана обратная
 * матрица
 * @param result Указатель на matrix_t, в которую будет записана обратная
 * матрица
 * @return 0 - ОК, 1 - Ошибка, некорректная матрица, 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err_indicator = SUCCESS;
  if (s21_is_matrix_normal(*A) == 0) {
    err_indicator = INCORRECT_MATRIX;
  } else if (s21_is_square(*A) == 0) {
    err_indicator = CALCULATION_ERR;
  }

  double det = 0.0;
  s21_determinant(A, &det);

  if (fabs(det) < s21_EPS) {
    err_indicator = CALCULATION_ERR;
  }

  if (err_indicator == SUCCESS) {
    matrix_t complements, transpose_complements;
    *result = ZERO_MATRIX;

    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transpose_complements);
    s21_mult_number(&transpose_complements, 1.0 / det, result);
    s21_remove_matrix(&complements);
    s21_remove_matrix(&transpose_complements);
  }
  return err_indicator;
}