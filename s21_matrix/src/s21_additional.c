#include "s21_matrix.h"

int s21_check_rows_columns(int rows, int columns) {
  if (rows <= 0 || columns <= 0) {
    return CALCULATION_ERROR;
  }
  return OK;
}
void _init_matrix(int rows, int columns, matrix_t *A, double matrix[]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A->matrix[i][j] = matrix[j + i * columns];
    }
  }
}

int check_matrix(matrix_t *A) {
  int retrn_code = OK;

  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0)
    retrn_code = UNCORRECT_MATRIX;

  for (int i = 0; retrn_code == OK && i < A->rows; i++) {
    if (A->matrix[i] == NULL) retrn_code = UNCORRECT_MATRIX;
  }

  return retrn_code;
}