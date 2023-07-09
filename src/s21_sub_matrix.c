#include "s21_matrix.h"

int s21_sub_matrix(const matrix_t *A, const matrix_t *B, matrix_t *result) {
  // Проверка наличия матриц A, B и result
  if (A == NULL || B == NULL || result == NULL) {
    // Если одна из матриц отсутствует, возвращаем код ошибки NOTCORRECT
    return NOTCORRECT;
  }
  // Проверка соответствия размеров матриц A и B
  if (A->rows != B->rows || A->columns != B->columns) {
    // Если размеры матриц не совпадают, возвращаем код ошибки ERROR_CALC
    return ERROR_CALC;
  }
  // Создание матрицы result с размерами, равными размерам матриц A и B
  int exit_status = s21_create_matrix(A->rows, A->columns, result);
  if (exit_status != OK) {
    // Если произошла ошибка при создании матрицы result, возвращаем соответствующий код ошибки
    return exit_status;
  }
  // Вычитание матриц B из матрицы A
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      // Записываем разность соответствующих элементов матриц A и B в матрицу result
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  // Возвращаем код успеха OK
  return OK;
}
