#include "s21_matrix.h"
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (check_matrix(A)) {
    return UNCORRECT_MATRIX;
  }
  int error = s21_create_matrix(A->rows, A->columns, result);
  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  if (error != OK) s21_remove_matrix(result);
  return error;
}