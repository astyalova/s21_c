#include "s21_matrix.h"
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (check_matrix(A)) {
    return UNCORRECT_MATRIX;
  }
  int error = s21_create_matrix(A->columns, A->rows, result);
  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
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