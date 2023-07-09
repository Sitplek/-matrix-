#ifndef S21_MATRIX__H
#define S21_MATRIX__H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define NOTCORRECT 1
#define ERROR_CALC 2
#define SUCCESS 1
#define FAILURE 0

// Структура для представления матрицы
typedef struct matrix_struct {
  double **matrix; // Двумерный массив значений матрицы
  int rows;        // Количество строк матрицы
  int columns;     // Количество столбцов матрицы
} matrix_t;

// Создает матрицу заданного размера и инициализирует ее нулевыми значениями
int s21_create_matrix(int rows, int columns, matrix_t *result);

// Освобождает память, занятую матрицей
void s21_remove_matrix(matrix_t *A);

// Сравнивает две матрицы на равенство
int s21_eq_matrix(const matrix_t *A, const matrix_t *B);

// Складывает две матрицы и сохраняет результат в новую матрицу
int s21_sum_matrix(const matrix_t *A, const matrix_t *B, matrix_t *result);

// Вычитает одну матрицу из другой и сохраняет результат в новую матрицу
int s21_sub_matrix(const matrix_t *A, const matrix_t *B, matrix_t *result);

// Умножает матрицу на число и сохраняет результат в новую матрицу
int s21_mult_number(const matrix_t *A, double number, matrix_t *result);

// Умножает две матрицы и сохраняет результат в новую матрицу
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Транспонирует матрицу и сохраняет результат в новую матрицу
int s21_transpose(const matrix_t *A, matrix_t *result);

// Вычисляет дополнительные матрицы (алгебраические дополнения) для заданной матрицы
int s21_calc_complements(matrix_t *A, matrix_t *result);

// Вычисляет определитель матрицы
int s21_determinant(matrix_t *A, double *result);

// Вычисляет обратную матрицу для заданной матрицы
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // S21_MATRIX__H