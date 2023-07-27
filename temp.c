#include "convertors.h"
#include <math.h>
//0b01111111111111111111111111111111
//0b000000000000000000000000000000000
// param = 6442450
int main() {
  float f = 0.5;
  unsigned int param = 0b01111111100000000000000000000000;
  unsigned int fbits = *((unsigned int *)&f);
  unsigned int float_exp = 0;
  float_exp = fbits & param;
  printf("%u", float_exp >> 23);
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0;
  if (src != S21_INF && src != S21_NAN){
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    unsigned int fbits = *((unsigned int *)&src);
  }else res = 1;
  return res;
}