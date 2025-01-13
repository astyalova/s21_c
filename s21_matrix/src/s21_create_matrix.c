#include "s21_matrix.h"
int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (result == NULL ||
      s21_check_rows_columns(rows, columns) == CALCULATION_ERROR) {
    return UNCORRECT_MATRIX;
  }
  double** matrix = malloc(rows * sizeof(double*));
  for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(columns * sizeof(double));
    for (int j = 0; j < columns; j++) {
      // matrix[i][j] = 0;
    }
  }
  result->matrix = matrix;
  result->columns = columns;
  result->rows = rows;
  return OK;
}
// int main() {
//     matrix_t result;
//     int check = s21_create_matrix(3, 3, &result);
//     if(check != 0) {
//         printf("Failed to allocate memory");
//         return 1;
//     } else
//     for(int i = 0; i < result.rows; i++) {
//         //printf("%d \n", result.matrix[i]);
//         printf("\n");
//         for(int j = 0; j < result.columns; j++) {
//             printf("%d ", result.matrix);

//         }
//     }
//     //printf("ilovemotkidudu");
//     return 0;
// }
//- 0 - OK
// - 1 - Ошибка, некорректная матрица
// - 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица,
//  для которой нельзя провести вычисления и т.д.)