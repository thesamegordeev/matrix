#include "../s21_matrix.h"

/**
 * @brief Функция зануляет созданную матрицу нулями
 * @param A Указатель на матрицу, которая будет заполнена нулями
 * @warning Не передавать неинициализированную матрицу!
 */
void s21_zero_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = 0.0;
    }
  }
}