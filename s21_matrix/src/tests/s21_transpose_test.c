#include "debug/debug.h"
#include "test.h"

START_TEST(transpose_1) {
  matrix_t *A = NULL;
  matrix_t result;

  int code = s21_transpose(A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A;
  matrix_t result;

  A.matrix = NULL;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  A.rows = 0;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.rows = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  A.columns = 0;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_5) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  free(A.matrix[1]);
  A.matrix[1] = NULL;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_6) {
  matrix_t A;
  matrix_t *result = NULL;

  s21_create_matrix(3, 3, &A);

  int code = s21_transpose(&A, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_7) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  _init_range_matrix(&A);

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], i + result.rows * j + 1);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_8) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, OK);

  ck_assert_float_eq(result.matrix[0][0], 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_9) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(10, 1, &A);
  _init_range_matrix(&A);

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], i + result.rows * j + 1);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_10) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(1, 10, &A);
  _init_range_matrix(&A);

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], i + result.rows * j + 1);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *transpose_suite() {
  Suite *suite = suite_create("TRANSPOSE TEST");
  TCase *tc = tcase_create("");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);
  tcase_add_test(tc, transpose_5);
  tcase_add_test(tc, transpose_6);
  tcase_add_test(tc, transpose_7);
  tcase_add_test(tc, transpose_8);
  tcase_add_test(tc, transpose_9);
  tcase_add_test(tc, transpose_10);

  suite_add_tcase(suite, tc);

  return suite;
}