#include "s21_matrix.h"

int s21_sum_matrix(const matrix_t *A, const matrix_t *B, matrix_t *result) {
  // Проверка наличия матриц A, B и result
  if (A == NULL || B == NULL || result == NULL) {
    // Если одна из матриц отсутствует, возвращаем код ошибки NOTCORRECT
    return NOTCORRECT;
  }
  // Проверка совпадения размеров матриц A и B
  if (A->rows != B->rows || A->columns != B->columns) {
    // Если размеры матриц не совпадают, возвращаем код ошибки ERROR_CALC
    return ERROR_CALC;
  }
  // Создание матрицы result с размерами A
  int exit_status = s21_create_matrix(A->rows, A->columns, result);
  if (exit_status != OK) {
    // Если произошла ошибка при создании матрицы result, возвращаем соответствующий код ошибки
    return exit_status;
  }
  // Вычисление суммы элементов матриц A и B
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      // Суммируем элементы A и B и сохраняем результат в соответствующий элемент матрицы result
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  // Возвращаем код успеха OK
  return OK;
}
