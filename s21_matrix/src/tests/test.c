#include "test.h"

#ifdef LEAK_CHECK
#define FORK_STATUS CK_NOFORK
#else
#define FORK_STATUS CK_FORK
#endif

int main() {
  Suite *suite_list[] = {
      create_matrix_suite(), remove_matrix_suite(),  eq_matrix_suite(),
      sum_matrix_suite(),    sub_matrix_suite(),     mult_number_suite(),
      determinant_suite(),   inverse_matrix_suite(), calc_complements_suite(),
      mult_matrix_suite(),   transpose_suite(),      NULL};
  int failed_count = 0;

  for (Suite **suite_ptr = suite_list; *suite_ptr != NULL; suite_ptr++) {
    SRunner *runner = srunner_create(*suite_ptr);
    srunner_set_fork_status(runner, FORK_STATUS);
    srunner_run_all(runner, CK_NORMAL);
    failed_count += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return failed_count;
}
void _init_range_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = j + A->columns * i + 1;
    }
  }
}