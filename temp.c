#include "convertors.h"

int main(){
    float f = 50;
    s21_decimal d = {0,0,0,0};
    float v = s21_from_float_to_decimal(f, &d);
    
    printf("%u\n", d.bits[0]);
    printf("%d\n",(d.bits[3]<< 1) >> 17);
    return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0;
  if (src != S21_INF && src != S21_NAN) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    int scale = 0;
    int sign = 0;
    if (src < 0) sign = 1;
    //src *= -1;
    if (src) {
      unsigned int fbits = *((unsigned int *)&src);
      int float_exp = 0;
      float_exp = (((fbits) << 1) >> 24) - 127;

      if (float_exp > 95) res = 1;
      if (float_exp < 95) {
      float less_one_check = src;
       int norm_flag = 0; 
        for (; !((int)src); src *= 10, scale++) {
        }
        int temp = 0;
        if(less_one_check != src){
          int norm_flag = 1; 
          temp = roundf(src);
        for (; !(int)(temp / 1000000); temp *= 10, scale++) {
        }
        src = (float)temp;
        }else{
          for (; !(int)(src / 1000000); src *= 10, scale++) {
        }
        }
        // if(!((int)(src/10000000))){
        //   while(!((int)src % 10)){
        //     src = src/10.0;
        //     scale--;
        //   }
        // }   
        unsigned int fbits = *((unsigned int *)&src);
        float_exp = (((fbits) << 1) >> 24) - 127;
        if (float_exp < -94 || scale > 28) res = 1;

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
      }
    }

  } else
    res = 1;
  return res;
}