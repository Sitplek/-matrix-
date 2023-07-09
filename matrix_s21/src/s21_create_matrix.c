#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return NOTCORRECT;
  }
  // Выделение памяти под указатели на строки матрицы
  result->rows = rows;
  result->columns = columns;
  result->matrix = calloc(rows, sizeof(double *));
  if (result->matrix == NULL) {
    return ERROR_CALC;
  }
  // Выделение памяти под элементы матрицы в каждой строке
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      s21_remove_matrix(result);
      return ERROR_CALC;
    }
  }
  return OK;
}