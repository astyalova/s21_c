#ifndef TESTS_DEBUG_H
#define TESTS_DEBUG_H

#include "../../s21_matrix.h"
#include "stdio.h"

void _init_matrix(int rows, int columns, matrix_t *A, double matrix[]);
void _init_range_matrix(matrix_t *A);
void _print_matrix(matrix_t *A);
void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);

#endif
