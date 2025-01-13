#include "debug/debug.h"
#include "test.h"

START_TEST(calc_complements_1) {
  matrix_t *A = NULL;
  matrix_t result;

  int code = s21_calc_complements(A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  A.rows = 0;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.rows = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  A.columns = 0;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.columns = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A;
  matrix_t result;

  A.matrix = NULL;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_5) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  free(A.matrix[1]);
  A.matrix[1] = NULL;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_6) {
  matrix_t A;
  matrix_t *result = NULL;

  s21_create_matrix(3, 3, &A);

  int code = s21_calc_complements(&A, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_7) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 2, &A);
  _init_range_matrix(&A);

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_8) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(1, 1, &A);
  _init_range_matrix(&A);

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_9) {
  matrix_t A;
  matrix_t result;

  double matrix[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  s21_create_matrix(3, 3, &A);
  _init_matrix(3, 3, &A, matrix);

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, OK);

  double res_matrix[3][3] = {{-1, 38, -27}, {1, -41, 29}, {-1, 34, -24}};
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], res_matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_10) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(2, 2, &A);
  _init_range_matrix(&A);

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, OK);

  double res_matrix[2][2] = {
      {4, -3},
      {-2, 1},
  };
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], res_matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *calc_complements_suite() {
  Suite *suite = suite_create("CALC COMPLEMENTS TEST");
  TCase *tc = tcase_create("");

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);
  tcase_add_test(tc, calc_complements_5);
  tcase_add_test(tc, calc_complements_6);
  tcase_add_test(tc, calc_complements_7);
  tcase_add_test(tc, calc_complements_8);
  tcase_add_test(tc, calc_complements_9);
  tcase_add_test(tc, calc_complements_10);

  suite_add_tcase(suite, tc);

  return suite;
}