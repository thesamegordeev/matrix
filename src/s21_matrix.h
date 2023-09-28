
#include <errno.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define s21_EPS 1e-8

#define SUCCESS 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERR 2

#define SUCCESS_COMPARSION 1
#define FAILURE_COMPARSION 0

#define ZERO_MATRIX \
  (matrix_t) { 0, 0, 0 }

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/*
========== СОЗДАНИЕ И УДАЛЕНИЕ МАТРИЦ ==========
*/

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

/*
========== АРИФМЕТИКА ==========
*/

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/*
========== СПЕЦИАЛЬНЫЕ ОПЕРАЦИИ ==========
*/

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

/*
========== СРАВНЕНИЕ МАТРИЦ ==========
*/

int s21_eq_matrix(matrix_t *A, matrix_t *B);

/*
========== ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ==========
*/

int s21_size_equal(matrix_t A, matrix_t B);
int s21_is_square(matrix_t A);
int s21_is_matrix_normal(matrix_t A);
int s21_order_matrix(matrix_t A);
void s21_transfer_to_minor(matrix_t A, int delete_row, int delete_column,
                           matrix_t *minor);
void s21_zero_matrix(matrix_t *A);