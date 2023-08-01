#include <stdio.h>
#include <math.h>

#define MASK1111 0b11111111111111111111111111111111
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0

typedef struct {
  unsigned int bits[4];
} s21_decimal;



int get_scale(s21_decimal value);
int get_sign(s21_decimal value);
int get_bit(s21_decimal value, int pos);
void set_sign_minus(s21_decimal* val);
void set_sign_plus(s21_decimal* val);
void set_sign(s21_decimal* val, int sign);
void s21_set_bit(s21_decimal *number, int bit, int value);


int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal* result);







int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);