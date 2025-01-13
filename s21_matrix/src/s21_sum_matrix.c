#include "s21_matrix.h"
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B)) {
    return UNCORRECT_MATRIX;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return CALCULATION_ERROR;
  }
  int error = s21_create_matrix(A->rows, A->columns, result);
  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  if (error != OK) s21_remove_matrix(result);
  return error;
}
// //- 0 - OK
// // - 1 - Ошибка, некорректная матрица
// // - 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица,
// //  для которой нельзя провести вычисления и т.д.)