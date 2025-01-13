#include "s21_matrix.h"
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL && A->rows > 0 && A->columns > 0) {
      // освобождение каждого из массивов отдельно
      for (int i = 0; i < A->rows; i++) {
        if (A->matrix[i] != NULL) free(A->matrix[i]);
        A->matrix[i] = NULL;  // присваиваю нулл чтобы быть уверенн, что он
                              // больше не ссылается на тот участок памяти
      }
      // очистить еще указатель на массив
      free(A->matrix);
    }
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}
