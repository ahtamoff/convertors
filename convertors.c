#include "convertors.h"


int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (src != S21_INF && src != S21_NAN){
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
  if (src < 0) {
    if (src == -2147483648) {
      src += 1;
    }
    dst->bits[3] = (1 << 31);
    src *= -1;
  }
  dst->bits[0] = src;
  }else res = 1;  
  return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  int sign = (src.bits[3]>>31);
  int scale = (src.bits[3]<< 1)>>17;
  int temp = 0;
  if(scale){ 
    s21_decimal trunc = {{0, 0, 0, 0}};
    s21_truncate(src, &trunc);
    if(src.bits[1] || src.bits[2] || ((src.bits[0]>>31))){res = 1;}
    temp = trunc.bits[0];
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