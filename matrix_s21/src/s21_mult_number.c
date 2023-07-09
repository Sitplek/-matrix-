#include "s21_matrix.h"

int s21_mult_number(const matrix_t *A, double number, matrix_t *result) {
  // Проверка наличия матриц A и result
  if (A == NULL || result == NULL) {
    return NOTCORRECT;
  }
  // Создание матрицы result с теми же размерами, что и матрица A
  int exit_status = s21_create_matrix(A->rows, A->columns, result);
  if (exit_status != OK) {
    return exit_status;
  }
  // Умножение каждого элемента матрицы A на заданное число number
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return OK;
}
