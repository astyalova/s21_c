#include "s21_matrix.h"
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) == UNCORRECT_MATRIX || result == NULL) {
    return UNCORRECT_MATRIX;
  }
  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  if (A->rows == 1) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      double compl = 0;
      s21_complement(A, &compl, i, j);
      result->matrix[i][j] = compl ;
    }
  }
  return OK;
}
