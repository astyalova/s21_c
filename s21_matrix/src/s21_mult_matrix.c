#include "s21_matrix.h"
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B)) {
    return UNCORRECT_MATRIX;
  }
  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }
  int error = s21_create_matrix(A->rows, B->columns, result);
  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->rows; k++) {
          result->matrix[i][j] += A->matrix[i][j] * B->matrix[i][j];
        }
      }
    }
  }
  if (error != OK) s21_remove_matrix(result);
  return error;
}