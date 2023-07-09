#include "s21_matrix.h"

int s21_transpose(const matrix_t *A, matrix_t *result) {
  // Проверка наличия матрицы A и result
  if (A == NULL || result == NULL) {
    // Если одна из матриц отсутствует, возвращаем код ошибки NOTCORRECT
    return NOTCORRECT;
  }
  // Создание матрицы result с размерами, обратными размерам матрицы A
  int exit_status = s21_create_matrix(A->columns, A->rows, result);
  if (exit_status != OK) {
    // Если произошла ошибка при создании матрицы result, возвращаем соответствующий код ошибки
    return exit_status;
  }
  // Транспонирование матрицы A
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      // Записываем элементы матрицы A в обратном порядке в матрицу result
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  // Возвращаем код успеха OK
  return OK;
}
