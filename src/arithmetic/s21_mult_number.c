#include "../s21_matrix.h"

/**
 * @brief Функция умножает матрицу на число
 * @param A Указатель на матрицу matrix_t
 * @param number Число, на которое будет умножена матрица
 * @param result Указатель на матрицу matrix_t, в которую будет записан
 * результат
 * @return 0 - ОК, 1 - Ошибка, некорректная матрица, 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err_indicator = SUCCESS;
  if (s21_is_matrix_normal(*A) == 0 || isinf(number) != 0 ||
      isnan(number) != 0) {
    err_indicator = INCORRECT_MATRIX;
  }

  if (err_indicator == SUCCESS &&
      s21_create_matrix(A->rows, A->columns, result) == 0) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }
  return err_indicator;
}