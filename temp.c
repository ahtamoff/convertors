#include "convertors.h"
#include <math.h>
//0b01111111111111111111111111111111
int main() {
  s21_decimal test_dec = {{2147483647, 1, 0, 0x30000}}; // exp = 3
  int param;
  s21_from_decimal_to_int(test_dec, &param);

  printf("%d", param);
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  int sign = (src.bits[3]>>31);
  int scale = (src.bits[3]<< 1)>>17;

  int temp = 0;
  if(scale){ 
    int zero_digits = 1;
    for(int i = src.bits[0]; i > 10; i /= 10){zero_digits++;}

    int first_digits = 1;
    for(int i = src.bits[1]; i > 10; i /= 10){first_digits++;}

    int second_digits = 1;
    for(int i = src.bits[2]; i > 10; i /= 10){second_digits++;}

    temp = (src.bits[0] + src.bits[1] * pow(10, zero_digits)) / pow(10, scale);
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