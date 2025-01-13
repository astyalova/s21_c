#include "debug/debug.h"
#include "test.h"

START_TEST(mult_number_test_1) {
  matrix_t *A = NULL;
  matrix_t result;
  double number = 2.45;

  int code = s21_mult_number(A, number, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_number_test_2) {
  matrix_t A;
  A.matrix = NULL;
  matrix_t result;
  double number = 2.45;

  int code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_number_test_3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  double number = 2.45;

  A.rows = 0;
  int code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.rows = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test_4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  double number = 2.45;

  A.columns = 0;
  int code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.columns = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test_5) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t *result = NULL;
  double number = 2.45;

  int code = s21_mult_number(&A, number, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test_6) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  double number = 2.45;

  free(A.matrix[2]);
  A.matrix[2] = NULL;

  int code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test_7) {
  double matrix[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  matrix_t A;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  _init_matrix(rows, columns, &A, matrix);

  matrix_t result;
  double number = 2.45;

  int code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], matrix[j + columns * i] * number);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test_8) {
  double matrix[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  matrix_t A;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  _init_matrix(rows, columns, &A, matrix);

  matrix_t result;
  double number = 0;

  int code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], matrix[j + columns * i] * number);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test_9) {
  double matrix[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  matrix_t A;
  int rows = 9;
  int columns = 1;
  s21_create_matrix(rows, columns, &A);
  _init_matrix(rows, columns, &A, matrix);

  matrix_t result;
  double number = 2.45;

  int code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], matrix[j + columns * i] * number);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test_10) {
  double matrix[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  matrix_t A;
  int rows = 1;
  int columns = 9;
  s21_create_matrix(rows, columns, &A);
  _init_matrix(rows, columns, &A, matrix);

  matrix_t result;
  double number = 2.45;

  int code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_float_eq(result.matrix[i][j], matrix[j + columns * i] * number);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_number_suite() {
  Suite *suite = suite_create("MULT NUMBER TEST");
  TCase *tc = tcase_create("");

  tcase_add_test(tc, mult_number_test_1);
  tcase_add_test(tc, mult_number_test_2);
  tcase_add_test(tc, mult_number_test_3);
  tcase_add_test(tc, mult_number_test_4);
  tcase_add_test(tc, mult_number_test_5);
  tcase_add_test(tc, mult_number_test_6);
  tcase_add_test(tc, mult_number_test_7);
  tcase_add_test(tc, mult_number_test_8);
  tcase_add_test(tc, mult_number_test_9);
  tcase_add_test(tc, mult_number_test_10);

  suite_add_tcase(suite, tc);

  return suite;
}