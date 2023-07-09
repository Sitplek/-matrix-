#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int exit_status = OK;
  // Проверка наличия и корректных размеров матрицы A
  if (!(A->rows > 0 && A->columns > 0)) {
    exit_status = NOTCORRECT;
  } else {
    // Проверка наличия и корректных размеров матрицы A и result
    if (A != NULL && result != NULL && A->rows == A->columns) {
      double det = 0;
      exit_status = s21_determinant(A, &det);
      // Проверка, что определитель не равен нулю
      if (det != 0 && exit_status == OK) {
        matrix_t buffer = {0};
        exit_status = s21_create_matrix(A->rows, A->rows, &buffer);
        // Создание промежуточной матрицы и вычисление комплементарной матрицы
        if (exit_status == OK) {
          exit_status = s21_calc_complements(A, result);
          // Транспонирование комплементарной матрицы
          if (exit_status == OK) {
            exit_status = s21_transpose(result, &buffer);
            // Умножение на обратный определитель
            if (exit_status == OK) {
              s21_mult_number(&buffer, (1 / det), result);
            }
          }
          // Освобождение памяти промежуточной матрицы
          s21_remove_matrix(&buffer);
        }
      } else {
        exit_status = ERROR_CALC;
      }
    } else {
      exit_status = ERROR_CALC;
    }
  }
  return exit_status;
}
