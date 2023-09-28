#include "../s21_matrix.h"

/**
 * @brief Функция вычитает из матрицы А матрицу B одинаковых размеров
 * @param A Указатель на первую матрицу matrix_t
 * @param B Указатель на вторую матрицу matrix_t
 * @param result Указатель на матрицу matrix_t, в которую будет записан
 * результат
 * @return 0 - ОК, 1 - Ошибка, некорректная матрица, 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err_indicator = SUCCESS;
  if (s21_is_matrix_normal(*A) == 0 || s21_is_matrix_normal(*B) == 0) {
    err_indicator = INCORRECT_MATRIX;
  }
  if (s21_size_equal(*A, *B) == 0) {
    err_indicator = CALCULATION_ERR;
  }

  if (err_indicator == SUCCESS &&
      s21_create_matrix(A->rows, A->columns, result) == 0) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return err_indicator;
}