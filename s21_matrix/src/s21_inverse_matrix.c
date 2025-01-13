#include "s21_matrix.h"
// если умножить изначальную матрицу на обратную матрицу то получится матрица, у
// которой
//  на главной диагонали единицы в остальных местах нули
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) == UNCORRECT_MATRIX || result == NULL) {
    return UNCORRECT_MATRIX;
  }
  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  double det = 0;
  s21_determinant(A, &det);
  if (fabs(det) < 1e-7) {
    return CALCULATION_ERROR;
  }
  if (A->rows == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = (double)1 / A->matrix[0][0];
    return OK;
  }
  matrix_t transposed;
  if (s21_transpose(A, &transposed) == UNCORRECT_MATRIX) {
    return UNCORRECT_MATRIX;
  }
  matrix_t adjugate;
  s21_calc_complements(&transposed, &adjugate);
  s21_mult_number(&adjugate, (double)1 / det, result);
  s21_remove_matrix(&transposed);
  s21_remove_matrix(&adjugate);
  return OK;
}