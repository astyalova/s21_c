#include "s21_matrix.h"
// //- 0 - OK
// // - 1 - Ошибка, некорректная матрица
// // - 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица,
// //  для которой нельзя провести вычисления и т.д.)

int s21_minor(matrix_t *A, double *result, int delete_row, int delete_col) {
  matrix_t m;
  s21_create_matrix(A->rows - 1, A->columns - 1, &m);
  int mi = 0;
  int mj = 0;
  for (int i = 0; i < A->rows; ++i) {
    if (i == delete_row) {
      continue;
    }
    mj = 0;
    for (int j = 0; j < A->columns; ++j) {
      if (j == delete_col) {
        continue;
      }
      m.matrix[mi][mj] = A->matrix[i][j];
      mj++;
    }
    mi++;
  }
  s21_determinant(&m, result);
  s21_remove_matrix(&m);
  return OK;
}

// алгебраическое дополнение
// Ответ записывается в result
int s21_complement(matrix_t *A, double *result, int delete_row,
                   int delete_col) {
  if (A->columns == 1 && A->rows == 1) {
    *result = 1;
    return OK;
  }
  if ((delete_row + delete_col) % 2 == 0) {
    // printf("even compl i=%d, j=%d\n", delete_row, delete_col);
    return s21_minor(A, result, delete_row, delete_col);
  }
  // printf("odd compl i=%d, j=%d\n", delete_row, delete_col);
  s21_minor(A, result, delete_row, delete_col);
  *result *= (double)-1;
  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  if (check_matrix(A) == UNCORRECT_MATRIX || result == NULL) {
    return UNCORRECT_MATRIX;
  }
  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  if (A->rows == 1) {
    *result = A->matrix[0][0];
    return OK;
  }
  *result = 0;
  for (int i = 0; i < A->columns; ++i) {
    double compl = 0;
    s21_complement(A, &compl, 0, i);
    *result = *result + A->matrix[0][i] * compl ;
  }
  return OK;
}
// определитель это сумма элементов, умноженных на их алгебраические дополнения