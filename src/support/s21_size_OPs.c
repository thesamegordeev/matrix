#include "../s21_matrix.h"

/**
 * @brief Функция проверяет матрицу на квадратность
 * @param A Матрица matrix_t
 * @return 0 - Несоответствие, 1 - ОК
 */
int s21_is_square(matrix_t A) { return A.rows == A.columns; }

/**
 * @brief Функция проверяет равенство размеров матриц
 * @param A Первая матрица matrix_t
 * @param B Вторая матрица matrix_t
 * @return 0 - Несоответствие, 1 - ОК
 */
int s21_size_equal(matrix_t A, matrix_t B) {
  return (A.rows == B.rows) && (A.columns == B.columns);
}

/**
 * @brief Функция проверяет матрицу на нормальные показатели
 * @param A Матрица matrix_t
 * @return 0 - Несоответствие, 1 - ОК
 */
int s21_is_matrix_normal(matrix_t A) { return (A.rows > 0) && (A.columns > 0); }

/**
 * @brief Функция определяет порядок квадратной матрицы
 * @param A Матрица matrix_t
 * @return Порядок матрицы
 */
int s21_order_matrix(matrix_t A) { return A.rows; }