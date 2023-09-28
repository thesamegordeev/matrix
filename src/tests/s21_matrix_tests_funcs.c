#include "s21_matrix_tests.h"

void s21_fill(matrix_t *A, double value, double mnozh) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = value * mnozh;
      value++;
    }
  }
}
