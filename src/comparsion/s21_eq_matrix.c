#include "../s21_matrix.h"

/**
 * @brief Функция сравнивает две матрицы matrix_t
 * @param A Первая матрица matrix_t
 * @param B Вторая матрица matrix_t
 * @return 1 - если матрицы равны, 0 - если нет
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int err_indicator = SUCCESS_COMPARSION;
  if (s21_size_equal(*A, *B) == 0) {
    err_indicator = FAILURE_COMPARSION;
  }

  if (err_indicator == SUCCESS_COMPARSION) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > s21_EPS) {
          err_indicator = FAILURE_COMPARSION;
        }
      }
    }
  }
  return err_indicator;
}