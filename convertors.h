#include <stdio.h>
#include <math.h>

#define MASK1111 0b11111111111111111111111111111111
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0

typedef struct {
  unsigned int bits[4];
} s21_decimal;


int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);