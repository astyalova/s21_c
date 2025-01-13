#include "test.h"

START_TEST(create_matrix_1) {
  int rows = 5;
  int columns = 5;
  matrix_t matrix;
  int result = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix.matrix[i][j] = 0;
    }
  }
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_2) {
  int rows = 0;
  int columns = 5;
  matrix_t matrix;
  int result = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(result, UNCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_3) {
  int rows = 5;
  int columns = 0;
  matrix_t matrix;
  int result = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(result, UNCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_4) {
  int rows = -1;
  int columns = 7;
  matrix_t matrix;
  int result = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(result, UNCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_5) {
  int rows = 5;
  int columns = 5;
  matrix_t *matrix = NULL;
  int result = s21_create_matrix(rows, columns, matrix);
  ck_assert_int_eq(result, UNCORRECT_MATRIX);
  s21_remove_matrix(matrix);
}
END_TEST

START_TEST(create_matrix_6) {
  int rows = 1;
  int columns = 10;
  matrix_t matrix;
  int result = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix.matrix[i][j] = 0;
    }
  }
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_7) {
  int rows = 10;
  int columns = 1;
  matrix_t matrix;
  int result = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix.matrix[i][j] = 0;
    }
  }
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_8) {
  int rows = 7;
  int columns = 4;
  matrix_t matrix;
  int result = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix.matrix[i][j] = 0;
    }
  }
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_9) {
  int rows = 1;
  int columns = 1;
  matrix_t matrix;
  int result = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);
  matrix.matrix[0][0] = 0;
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *create_matrix_suite() {
  Suite *suite = suite_create("CREATE MATRIX TEST");
  TCase *tc = tcase_create("");

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);
  tcase_add_test(tc, create_matrix_5);
  tcase_add_test(tc, create_matrix_6);
  tcase_add_test(tc, create_matrix_7);
  tcase_add_test(tc, create_matrix_8);
  tcase_add_test(tc, create_matrix_9);

  suite_add_tcase(suite, tc);

  return suite;
}