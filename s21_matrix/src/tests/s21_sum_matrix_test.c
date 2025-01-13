#include "debug/debug.h"
#include "test.h"

START_TEST(sum_matrix_1) {
  matrix_t* A;
  matrix_t B;
  matrix_t* result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  A = NULL;
  s21_create_matrix(3, 3, &B);
  _init_matrix(3, 3, &B, matrix_1);

  int code = s21_sum_matrix(A, &B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t A;
  matrix_t* B;
  matrix_t* result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  B = NULL;
  s21_create_matrix(3, 3, &A);
  _init_matrix(3, 3, &A, matrix_1);

  int code = s21_sum_matrix(&A, B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(B);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t* result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  A.rows = 3;
  A.columns = 3;
  A.matrix = NULL;
  s21_create_matrix(3, 3, &B);
  _init_matrix(3, 3, &B, matrix_1);

  int code = s21_sum_matrix(&A, &B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t A;
  matrix_t B;
  matrix_t* result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  B.rows = 3;
  B.columns = 3;
  B.matrix = NULL;
  s21_create_matrix(3, 3, &A);
  _init_matrix(3, 3, &A, matrix_1);

  int code = s21_sum_matrix(&A, &B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_5) {
  matrix_t A;
  matrix_t B;
  matrix_t* result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  double matrix_2[9] = {2.5, -3.456, 2.2, 4.2, 3.22, 8.2, 1.23, 43.2, 2.2};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  _init_matrix(3, 3, &A, matrix_1);
  _init_matrix(3, 3, &B, matrix_2);
  result = NULL;

  int code = s21_sum_matrix(&A, &B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_6) {
  matrix_t A;
  matrix_t B;
  matrix_t* result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  double matrix_2[9] = {2.5, -3.456, 2.2, 4.2, 3.22, 8.2, 1.23, 43.2, 2.2};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  _init_matrix(3, 3, &A, matrix_1);
  _init_matrix(3, 3, &B, matrix_2);
  A.rows = 0;

  int code = s21_sum_matrix(&A, &B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.rows = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_7) {
  matrix_t A;
  matrix_t B;
  matrix_t* result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  double matrix_2[9] = {2.5, -3.456, 2.2, 4.2, 3.22, 8.2, 1.23, 43.2, 2.2};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  _init_matrix(3, 3, &A, matrix_1);
  _init_matrix(3, 3, &B, matrix_2);
  B.rows = 0;

  int code = s21_sum_matrix(&A, &B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  B.rows = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_8) {
  matrix_t A;
  matrix_t B;
  matrix_t* result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  double matrix_2[9] = {2.5, -3.456, 2.2, 4.2, 3.22, 8.2, 1.23, 43.2, 2.2};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  _init_matrix(3, 3, &A, matrix_1);
  _init_matrix(3, 3, &B, matrix_2);
  A.columns = 0;

  int code = s21_sum_matrix(&A, &B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  A.columns = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_9) {
  matrix_t A;
  matrix_t B;
  matrix_t* result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.columns = 0;

  int code = s21_sum_matrix(&A, &B, result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  B.columns = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_10) {
  matrix_t A;
  matrix_t B;
  matrix_t* result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(5, 3, &B);

  int code = s21_sum_matrix(&A, &B, result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_11) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 5, &B);

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_12) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  free(A.matrix[2]);
  A.matrix[2] = NULL;

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_13) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  free(B.matrix[2]);
  B.matrix[2] = NULL;

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, UNCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_14) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  double matrix_2[9] = {2.5, -3.456, 2.2, 4.2, 3.22, 8.2, 1.23, 43.2, 2.2};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  _init_matrix(3, 3, &A, matrix_1);
  _init_matrix(3, 3, &B, matrix_2);

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(result.matrix[i][j],
                         matrix_1[j + 3 * i] + matrix_2[j + 3 * i]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_15) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 2.3;
  B.matrix[0][0] = 7.6;

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_float_eq(result.matrix[0][0], A.matrix[0][0] + B.matrix[0][0]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_16) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  double matrix_2[9] = {2.5, -3.456, 2.2, 4.2, 3.22, 8.2, 1.23, 43.2, 2.2};

  int rows = 9;
  int columns = 1;

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  _init_matrix(rows, columns, &A, matrix_1);
  _init_matrix(rows, columns, &B, matrix_2);

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_float_eq(result.matrix[i][j],
                         matrix_1[j + columns * i] + matrix_2[j + columns * i]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_17) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  double matrix_1[9] = {7.0, 4.7, 1.0, -6.0, 3.4, 2.7, 5.9, -11.4, 2.23};
  double matrix_2[9] = {2.5, -3.456, 2.2, 4.2, 3.22, 8.2, 1.23, 43.2, 2.2};

  int rows = 1;
  int columns = 9;

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  _init_matrix(rows, columns, &A, matrix_1);
  _init_matrix(rows, columns, &B, matrix_2);

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_float_eq(result.matrix[i][j],
                         matrix_1[j + columns * i] + matrix_2[j + columns * i]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite* sum_matrix_suite() {
  Suite* suite = suite_create("SUM MATRIX TEST");
  TCase* tc = tcase_create("");

  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2);
  tcase_add_test(tc, sum_matrix_3);
  tcase_add_test(tc, sum_matrix_4);
  tcase_add_test(tc, sum_matrix_5);
  tcase_add_test(tc, sum_matrix_6);
  tcase_add_test(tc, sum_matrix_7);
  tcase_add_test(tc, sum_matrix_8);
  tcase_add_test(tc, sum_matrix_9);
  tcase_add_test(tc, sum_matrix_10);
  tcase_add_test(tc, sum_matrix_11);
  tcase_add_test(tc, sum_matrix_12);
  tcase_add_test(tc, sum_matrix_13);
  tcase_add_test(tc, sum_matrix_14);
  tcase_add_test(tc, sum_matrix_15);
  tcase_add_test(tc, sum_matrix_16);
  tcase_add_test(tc, sum_matrix_17);

  suite_add_tcase(suite, tc);

  return suite;
}