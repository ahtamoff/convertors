#include "convertors.h"
int s21_from_int_to_decimal(int src, s21_decimal *dst);

int main() { return 0; }

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (src == S21_INF || src == S21_NAN) res = 1;
  if (src < 0) {
    dst->bits[3] = (1 << 31);
    src *= -1;
  }
  dst->bits[0] = src;
  return res;
}