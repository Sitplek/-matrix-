#ifndef TEST_FILES_S21_TEST_DECIMAL_H_
#define TEST_FILES_S21_TEST_DECIMAL_H_

#include <check.h>

#include "../s21_decimal.h"

#define is_fin(x) __builtin_isfinite(x)
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)

#endif  // TEST_FILES_S21_TEST_DECIMAL_H_