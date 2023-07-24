#include "convertors.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (src == S21_INF || src == S21_NAN) res = 1;
  if (src < 0) {
    if (src == -2147483648) {
      src += 1;
    }
    dst->bits[3] = (1 << 31);
    src *= -1;
  }
  dst->bits[0] = src;
  return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst){
  int res = 0;
  if (src.bits[1] || src.bits[2] || src.bits[0] >> 31){
    res = 1;
  }
  src.bits[0] = *dst;
  if (src.bits[3] >> 31){
     *dst *= -1;
  }
  return res;
}