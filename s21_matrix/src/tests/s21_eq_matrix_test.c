#include "test.h"

START_TEST(eq_matrix_1) {
  matrix_t *A = NULL;
  matrix_t B;
  s21_create_matrix(5, 5, &B);

  int result = s21_eq_matrix(A, &B);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A;
  matrix_t *B = NULL;
  s21_create_matrix(5, 5, &A);

  int result = s21_eq_matrix(&A, B);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  A.rows = 0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);

  A.rows = 5;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  B.rows = 0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);

  B.rows = 5;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_7) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + i * j;
      B.matrix[i][j] = j + i * j;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_8) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + (i % 2 * 2 - 1) * i * j;
      B.matrix[i][j] = j + (i % 2 * 2 - 1) * i * j;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_9) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + i * j;
      B.matrix[i][j] = j + i * j;
    }
  }
  B.matrix[4][3] += 1.0;

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_10) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + i * j;
      B.matrix[i][j] = j + i * j;
    }
  }
  B.matrix[4][3] -= 1.0;

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_11) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (j + i * j) * 1.0e-5;
      B.matrix[i][j] = (j + i * j) * 1.0e-5;
    }
  }
  B.matrix[4][3] += 1.0e-7;

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_12) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (j + i * j) * 1.0e-5;
      B.matrix[i][j] = (j + i * j) * 1.0e-5;
    }
  }
  B.matrix[4][3] -= 1.0e-7;

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_13) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (j + i * j) * 1.0e-5;
      B.matrix[i][j] = (j + i * j) * 1.0e-5;
    }
  }
  B.matrix[4][3] += 1.0e-8;

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_14) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (j + i * j) * 1.0e-5;
      B.matrix[i][j] = (j + i * j) * 1.0e-5;
    }
  }
  B.matrix[4][3] -= 1.0e-8;

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_15) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + (i % 2 * 2 - 1) * i * j;
      B.matrix[i][j] = j + (i % 2 * 2 - 1) * i * j;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_16) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 10, &A);
  s21_create_matrix(1, 10, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + (i % 2 * 2 - 1) * i * j;
      B.matrix[i][j] = j + (i % 2 * 2 - 1) * i * j;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_17) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 1, &A);
  s21_create_matrix(10, 1, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + (i % 2 * 2 - 1) * i * j;
      B.matrix[i][j] = j + (i % 2 * 2 - 1) * i * j;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *eq_matrix_suite() {
  Suite *suite = suite_create("EQ MATRIX TEST");
  TCase *tc = tcase_create("");

  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_4);
  tcase_add_test(tc, eq_matrix_5);
  tcase_add_test(tc, eq_matrix_7);
  tcase_add_test(tc, eq_matrix_8);
  tcase_add_test(tc, eq_matrix_9);
  tcase_add_test(tc, eq_matrix_10);
  tcase_add_test(tc, eq_matrix_11);
  tcase_add_test(tc, eq_matrix_12);
  tcase_add_test(tc, eq_matrix_13);
  tcase_add_test(tc, eq_matrix_14);
  tcase_add_test(tc, eq_matrix_15);
  tcase_add_test(tc, eq_matrix_16);
  tcase_add_test(tc, eq_matrix_17);

  suite_add_tcase(suite, tc);

  return suite;
}