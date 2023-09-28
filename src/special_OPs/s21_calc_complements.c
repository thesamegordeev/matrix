#include "../s21_matrix.h"

/**
 * @brief Функция находит миноры матрицы и создает матрицу алгебраических
 * дополнений
 * @param A Указатель на матрицу matrix_t
 * @param result Указатель на матрицу matrix_t, в которую будет записан
 * результат
 * @return 0 - ОК, 1 - Ошибка, некорректная матрица, 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err_indicator = SUCCESS;
  if (s21_is_matrix_normal(*A) == 0) {
    err_indicator = INCORRECT_MATRIX;
  } else if (s21_is_square(*A) == 0) {
    err_indicator = CALCULATION_ERR;
  }

  if (err_indicator == SUCCESS) {
    *result = ZERO_MATRIX;
    matrix_t minor = ZERO_MATRIX;
    double det = 0.0;
    s21_create_matrix(A->rows, A->columns, result);
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        s21_transfer_to_minor(*A, i, j, &minor);
        s21_determinant(&minor, &det);
        result->matrix[i][j] = (int)pow(-1, i + j) * det;
        s21_zero_matrix(&minor);
      }
    }
    s21_remove_matrix(&minor);
  }
  return err_indicator;
}
