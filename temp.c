#include "convertors.h"
#include <math.h>
//0b01111111111111111111111111111111
//0b000000000000000000000000000000000
// param = 6442450
int main() {
  s21_decimal test_dec = {0, 0, 0, 0x30000}; // exp = 3
  int param;
  s21_from_decimal_to_int(test_dec, &param);

  //printf("%d", test);
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  int sign = (src.bits[3]>>31);
  int scale = (src.bits[3]<< 1)>>17;

  int temp = 0;
  if(scale){ 
    s21_decimal trunc = {0, 0, 0, 0};
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