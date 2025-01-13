#include "test.h"

START_TEST(remove_matrix_1) {
  matrix_t matrix;
  s21_create_matrix(5, 5, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

START_TEST(remove_matrix_2) {
  matrix_t matrix;
  s21_create_matrix(5, 5, &matrix);
  free(matrix.matrix[3]);
  matrix.matrix[3] = NULL;
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

START_TEST(remove_matrix_3) {
  matrix_t *matrix = NULL;
  s21_remove_matrix(matrix);
}
END_TEST

START_TEST(remove_matrix_4) {
  matrix_t matrix;
  matrix.rows = 5;
  matrix.columns = 5;
  matrix.matrix = NULL;
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

START_TEST(remove_matrix_5) {
  matrix_t matrix;
  s21_create_matrix(1, 1, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}

START_TEST(remove_matrix_6) {
  matrix_t matrix;
  s21_create_matrix(1, 10, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

START_TEST(remove_matrix_7) {
  matrix_t matrix;
  s21_create_matrix(10, 1, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

Suite *remove_matrix_suite() {
  Suite *suite = suite_create("REMOVE MATRIX TEST");
  TCase *tc = tcase_create("");

  tcase_add_test(tc, remove_matrix_1);
  tcase_add_test(tc, remove_matrix_2);
  tcase_add_test(tc, remove_matrix_3);
  tcase_add_test(tc, remove_matrix_4);
  tcase_add_test(tc, remove_matrix_5);
  tcase_add_test(tc, remove_matrix_6);
  tcase_add_test(tc, remove_matrix_7);

  suite_add_tcase(suite, tc);

  return suite;
}