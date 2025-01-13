#include "debug/debug.h"
#include "test.h"

START_TEST(determinant_1) {
  matrix_t* A = NULL;
  double result = 0;

  int code = s21_determinant(A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A;
  double result = 0;

  A.matrix = NULL;

  int code = s21_determinant(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(3, 3, &A);
  A.rows = 0;

  int code = s21_determinant(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.rows = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(3, 3, &A);
  A.columns = 0;

  int code = s21_determinant(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.columns = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(3, 3, &A);
  free(A.matrix[1]);
  A.matrix[1] = NULL;

  int code = s21_determinant(&A, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_6) {
  matrix_t A;
  double* result = NULL;

  s21_create_matrix(3, 3, &A);

  int code = s21_determinant(&A, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_7) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(3, 3, &A);
  _init_range_matrix(&A);

  int code = s21_determinant(&A, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_float_eq(result, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_8) {
  matrix_t A;
  double result = 0;

  double matrix[9] = {4, 2, 6.3, 1.2, -53, 1.32, 9.6, 34, 0.62};
  s21_create_matrix(3, 3, &A);
  _init_matrix(3, 3, &A, matrix);

  int code = s21_determinant(&A, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_float_eq(result, 3175.376);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_9) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 23.2;

  int code = s21_determinant(&A, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_float_eq(result, 23.2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_10) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(2, 2, &A);
  _init_range_matrix(&A);

  int code = s21_determinant(&A, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_float_eq(result, -2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_11) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(3, 2, &A);
  _init_range_matrix(&A);

  int code = s21_determinant(&A, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite* determinant_suite() {
  Suite* suite = suite_create("DETERMINANT TEST");
  TCase* tc = tcase_create("");

  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);
  tcase_add_test(tc, determinant_6);
  tcase_add_test(tc, determinant_7);
  tcase_add_test(tc, determinant_8);
  tcase_add_test(tc, determinant_9);
  tcase_add_test(tc, determinant_10);
  tcase_add_test(tc, determinant_11);

  suite_add_tcase(suite, tc);

  return suite;
}