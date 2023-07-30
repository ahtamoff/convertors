#include "convertors.h"

int get_scale(s21_decimal value) { return ((value.bits[3] >> 16) & 0xFF); }

int get_sign(s21_decimal value) { return value.bits[3] >> 31; }

int get_bit(s21_decimal value, int pos) {
  return (value.bits[pos / 32] >> (pos % 32)) & 1;
}

void set_sign_minus(s21_decimal* val) { val->bits[3] |= 1 << 31; }

void set_sign_plus(s21_decimal* val) { val->bits[3] &= ~(1 << 31); }

void set_sign(s21_decimal* val, int sign) {
  sign ? set_sign_minus(val) : set_sign_plus(val);
}

void s21_set_bit(s21_decimal *number, int bit, int value) {
  unsigned int shift = 1;
  if (bit >= 0 && bit < 128) {
    if (value)
      number->bits[bit / 32] = number->bits[bit / 32] | shift << (bit % 32);
    else
      number->bits[bit / 32] = number->bits[bit / 32] & ~(shift << (bit % 32));
  }
}

void divide_by_10(s21_decimal* buf, int scale) {
  unsigned long long u_num;  
  int tmp_int = 0;
  for (int i = 0; i < scale; i++) {
    u_num = buf->bits[2];
    int j = 2;
    for (; j >= 0; j--) {
      if (j == 0) {
        buf->bits[j] = u_num / 10;
      } else {
        tmp_int = u_num % 10;  
        buf->bits[j] = u_num / 10;                            
        u_num = tmp_int * (4294967296) + buf->bits[j - 1];
      }
    }
  }
  buf->bits[3] = 0;
}

int s21_negate(s21_decimal value, s21_decimal* result) {
  value.bits[3] ^= 0x80000000;
  *result = value;
  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  int scale = get_scale(value);
  int sign = get_sign(value);
  if (scale != 0) {
    divide_by_10(&value, scale);
    *result = value;
  } else {
    *result = value;
  }
  set_sign(result, sign);
  return 0;
}


