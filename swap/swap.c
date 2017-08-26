#include "swap.h"

void swap_int(int* x,int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap_float(float* x,float* y){
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap_double(double* x,double* y){
    double temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap_char(char* x,char* y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
