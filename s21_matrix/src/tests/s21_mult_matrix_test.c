#include "debug/debug.h"
#include "test.h"

START_TEST(mult_matrix_test_1) {
  matrix_t *A = NULL;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(k, n, &B);

  int code = s21_mult_matrix(A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_2) {
  matrix_t A;
  matrix_t *B = NULL;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);

  int code = s21_mult_matrix(&A, B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_matrix_test_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  A.matrix = NULL;
  s21_create_matrix(k, n, &B);

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  B.matrix = NULL;
  s21_create_matrix(m, k, &A);

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_matrix_test_5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);
  s21_create_matrix(k, n, &B);

  A.rows = 0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.rows = m;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);
  s21_create_matrix(k, n, &B);

  A.columns = 0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.columns = k;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_7) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);
  s21_create_matrix(k, n, &B);

  B.rows = 0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  B.rows = k;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_8) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);
  s21_create_matrix(k, n, &B);

  B.columns = 0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  B.columns = n;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_9) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);
  s21_create_matrix(k, n, &B);

  free(A.matrix[2]);
  A.matrix[2] = NULL;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_10) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);
  s21_create_matrix(k, n, &B);

  free(B.matrix[2]);
  B.matrix[2] = NULL;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_11) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);
  s21_create_matrix(n, n, &B);

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_12) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);
  s21_create_matrix(n, k, &B);

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_13) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(k, m, &A);
  s21_create_matrix(n, k, &B);

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_15) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int k = 1;
  int m = 1;
  int n = 1;

  s21_create_matrix(m, k, &A);
  _init_range_matrix(&A);
  s21_create_matrix(k, n, &B);
  _init_range_matrix(&B);

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);

  ck_assert_float_eq(result.matrix[0][0], 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test_17) {
  matrix_t A;
  matrix_t B;
  matrix_t *result = NULL;

  int k = 5;
  int m = 3;
  int n = 4;

  s21_create_matrix(m, k, &A);
  s21_create_matrix(k, n, &B);

  int code = s21_mult_matrix(&A, &B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *mult_matrix_suite() {
  Suite *suite = suite_create("MULT MATRIX TEST");
  TCase *tc = tcase_create("");

  tcase_add_test(tc, mult_matrix_test_1);
  tcase_add_test(tc, mult_matrix_test_2);
  tcase_add_test(tc, mult_matrix_test_3);
  tcase_add_test(tc, mult_matrix_test_4);
  tcase_add_test(tc, mult_matrix_test_5);
  tcase_add_test(tc, mult_matrix_test_6);
  tcase_add_test(tc, mult_matrix_test_7);
  tcase_add_test(tc, mult_matrix_test_8);
  tcase_add_test(tc, mult_matrix_test_9);
  tcase_add_test(tc, mult_matrix_test_10);
  tcase_add_test(tc, mult_matrix_test_11);
  tcase_add_test(tc, mult_matrix_test_12);
  tcase_add_test(tc, mult_matrix_test_13);
  tcase_add_test(tc, mult_matrix_test_15);
  tcase_add_test(tc, mult_matrix_test_17);

  suite_add_tcase(suite, tc);

  return suite;
}