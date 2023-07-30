#include <math.h>

#include "convertors.h"

int main() {
  float f = 0.1;
  // for (int i = 31; i >= 0; i--) {
  //   printf("%d", (fbits & (1 << i))>>i);
  // }
  s21_decimal d = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(f, &d);
  printf("%d", d.bits[0]);
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0;
  int sign = 0;
  if (src < 0) sign = 1;
  src *= -1;
  if (src != S21_INF && src != S21_NAN) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    int scale = 0;
    if (src) {
      unsigned int fbits = *((unsigned int *)&src);
      int float_exp = 0;
      float_exp = (((fbits) << 1) >> 24) - 127;
      if (float_exp > 95) res = 1;
      if (float_exp < 95) {
        for (; !((int)src); src *= 10, scale++) {
        }
        for (; !(int)(src / 10000000); src *= 10, scale++) {
        }
        if (float_exp < -94 || scale > 28) res = 1;

        unsigned int fbits = *((unsigned int *)&src);
        float_exp = (((fbits) << 1) >> 24) - 127;

        s21_set_bit(dst, float_exp, 1);
        for (int i = 22; i >= 0; i--) {
          float_exp--;
          if ((fbits & 1 << i) >> i) {
            s21_set_bit(dst, float_exp, 1);
          }
        }
        if (sign) {
          dst->bits[3] |= 1 << 31;
        }
        if (scale) {
          dst->bits[3] |= scale << 16;
        }
        s21_truncate(*dst, dst);
      }
    }

  } else
    res = 1;
  return res;
}