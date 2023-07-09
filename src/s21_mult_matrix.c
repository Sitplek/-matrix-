#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  // Проверка наличия матриц A, B и result
  if (A == NULL || B == NULL || result == NULL) {
    return NOTCORRECT;
  }
  // Проверка совместимости размеров матриц для умножения
  if (A->rows == B->columns && A->columns == B->rows) {
    // Создание матрицы result с размерами, соответствующими результату умножения
    int exit_status = s21_create_matrix(A->rows, B->columns, result);
    if (exit_status != OK) {
      return exit_status;
    }
    // Выполнение умножения матриц
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = 0;
        for (int q = 0; q < A->columns; q++) {
          result->matrix[i][j] += A->matrix[i][q] * B->matrix[q][j];
        }
      }
    }
    return OK;
  } else {
    return ERROR_CALC;
  }
}
