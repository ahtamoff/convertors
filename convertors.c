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

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  int sign = (src.bits[3]>>31);
  int scale = (src.bits[3]<< 1)>>17;

  int temp = 0;
  if(scale){ //значение мантиссы
    int zero_digits = 1;
    for(int i = src.bits[0]; i > 10; i /= 10){zero_digits++;}
    int first_digits = 1;
    for(int i = src.bits[1]; i > 10; i /= 10){first_digits++;}
    temp = (src.bits[0] + src.bits[1] * pow(10, zero_digits) + src.bits[2]* pow(10, zero_digits + first_digits))/ pow(10, scale);
    printf("%d", temp);
    
  }else {
    if(src.bits[1] || src.bits[2] || ((src.bits[0]>>31))){res = 1;}
    temp = src.bits[0];
  }
  *dst = temp;
  if(sign){
      *dst *= (-1);
    }

  return res;
}