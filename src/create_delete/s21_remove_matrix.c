#include "../s21_matrix.h"

/**
 * @brief Функция очищает память, выделенную на матрицу
 * @param A Указатель на matrix_t, который будет вычищен
 */
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
  }
}