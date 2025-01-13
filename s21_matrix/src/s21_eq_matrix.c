#include "s21_matrix.h"
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL ||
      (A->rows != B->rows || A->columns != B->columns)) {
    return FAILURE;
  }
  int res = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7)  // 0.0000001
        return FAILURE;
      // i = A->rows;
      // j = A->columns;
    }
  }

  return res;
}