#include "convertors.h"

int main() {
  s21_decimal graz = {1234, 0, 0, 0};
  int knaz = 0;
  s21_from_decimal_to_int(graz, &knaz);
  printf("%d", knaz);

  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  
  *dst = src.bits[0];

  return res;
}