#include "s21_matrix.h"

const double EPSILON = 1e-06;

int s21_eq_matrix(const matrix_t *A, const matrix_t *B) {
  // Проверка наличия и корректных размеров матриц A и B
  if (A == NULL || B == NULL || A->rows != B->rows || A->columns != B->columns) {
    return FAILURE;
  }
  // Сравнение элементов матриц A и B с учетом погрешности
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
        return FAILURE;
      }
    }
  }
  return SUCCESS;
}

