#include "../s21_matrix.h"

/**
 * @brief Функция находит определитель матрицы
 * @param A Указатель на матрицу matrix_t, из которой будет высчитан
 * определитель
 * @param result Указатель на double, в который будет записан
 * результат
 * @return 0 - ОК, 1 - Ошибка, некорректная матрица, 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_determinant(matrix_t *A, double *result) {
  int err_indicator = SUCCESS;
  double tmp = 0.0;
  if (s21_is_matrix_normal(*A) == 0) {
    err_indicator = INCORRECT_MATRIX;
  } else if (s21_is_square(*A) == 0) {
    err_indicator = CALCULATION_ERR;
  }

  if (err_indicator == SUCCESS) {
    int order = s21_order_matrix(*A);
    if (order == 1) {
      tmp = A->matrix[0][0];
    } else if (order == 2) {
      tmp +=
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    } else if (order > 2) {
      matrix_t minor = ZERO_MATRIX;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      for (int j = 0; j < A->columns; j++) {
        s21_transfer_to_minor(*A, 0, j, &minor);
        double determinant = 0.0;
        s21_determinant(&minor, &determinant);
        tmp += (int)pow(-1, j) * A->matrix[0][j] * determinant;
      }
      s21_remove_matrix(&minor);
    }
  }
  *result = tmp;
  return err_indicator;
}