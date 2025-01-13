#include "debug/debug.h"
#include "test.h"

START_TEST(inverse_matrix_1) {
  matrix_t *A = NULL;
  matrix_t result;

  int code = s21_inverse_matrix(A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t A;
  matrix_t result;

  A.matrix = NULL;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  A.rows = 0;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.rows = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  A.columns = 0;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.columns = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  free(A.matrix[1]);
  A.matrix[1] = NULL;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t A;
  matrix_t *result = NULL;

  s21_create_matrix(3, 3, &A);

  int code = s21_inverse_matrix(&A, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_7) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  _init_range_matrix(&A);

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_8) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 2, &A);
  _init_range_matrix(&A);

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_9) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_float_eq(result.matrix[0][0], 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_10) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 10.0;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_float_eq(result.matrix[0][0], 0.1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_11) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(2, 2, &A);
  _init_range_matrix(&A);

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, OK);

  double matrix[2][2] = {{-2, 1}, {1.5, -0.5}};
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_12) {
  matrix_t A;
  matrix_t result;

  double matrix[9] = {5, 3, 6, 2, 4, 2, 0, 6, 2};
  s21_create_matrix(3, 3, &A);
  _init_matrix(3, 3, &A, matrix);

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, OK);

  double res_matrix[3][3] = {
      {-0.1, 0.75, -0.45}, {-0.1, 0.25, 0.05}, {0.3, -0.75, 0.35}};
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], res_matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *inverse_matrix_suite() {
  Suite *suite = suite_create("INVERSE MATRIX TEST");
  TCase *tc = tcase_create("");

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);
  tcase_add_test(tc, inverse_matrix_5);
  tcase_add_test(tc, inverse_matrix_6);
  tcase_add_test(tc, inverse_matrix_7);
  tcase_add_test(tc, inverse_matrix_8);
  tcase_add_test(tc, inverse_matrix_9);
  tcase_add_test(tc, inverse_matrix_10);
  tcase_add_test(tc, inverse_matrix_11);
  tcase_add_test(tc, inverse_matrix_12);

  suite_add_tcase(suite, tc);

  return suite;
}