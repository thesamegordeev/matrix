#include "../s21_matrix.h"

/**
 * @brief Функция динамически создает матрицу указанных параметров на указателе
 * result
 * @param rows Количество строк в создаваемой матрице
 * @param columns Количество столбцов в создаваемой матрице
 * @param result Указатель на структуру, в которую будет записан результат
 * @return 0 - ОК, 1 - rows и/или columns меньше 0, 2 - ОС не выделила память
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err_indicator = SUCCESS;
  if (rows <= 0 || columns <= 0) {
    err_indicator = INCORRECT_MATRIX;
  }

  if (err_indicator == SUCCESS) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      err_indicator = CALCULATION_ERR;
    } else {
      result->columns = columns;
      result->rows = rows;
    }
  }
  if (err_indicator == SUCCESS) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        err_indicator = CALCULATION_ERR;
      }
    }
  }
  return err_indicator;
}