#include "../s21_matrix.h"

/**
 * @brief Функция заполняет минор матрицы
 * @param A Основная матрица matrix_t
 * @param delete_row Номер строки, которая должна быть "вычеркнута" при записи в
 * минор (номер строки элемента, для которого минор вычисляется)
 * @param delete_coloumn Номер столбца, который должен быть "вычеркнут" при
 * записи в минор (номер столбца элемента, для которого минор вычисляется)
 * @param minor Указатель на matrix_t, в которую будет записан
 * результат
 * @warning Матрица minor передается уже созданной и зануленной, в инициализации
 * не нуждается
 */
void s21_transfer_to_minor(matrix_t A, int delete_row, int delete_column,
                           matrix_t *minor) {
  for (int i_minor = 0, i_A = 0; i_minor < minor->rows; i_minor++, i_A++) {
    for (int j_minor = 0, j_A = 0; j_minor < minor->columns; j_minor++, j_A++) {
      if (i_A == delete_row) i_A++;
      if (j_A == delete_column) j_A++;
      minor->matrix[i_minor][j_minor] = A.matrix[i_A][j_A];
    }
  }
}