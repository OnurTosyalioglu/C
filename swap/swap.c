/*  
 *  Author : Kemal Onur Tosyalioglu
 *  Email  : onurtosyalioglu@gmail.com
 *  Date   : 25.07.2017
 *  Topic  : swap functions with call by 
 *  reference at primitive data types as
 *  a library 
 */

#include "swap.h"

void swapInt(int* x,int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapFloat(float* x,float* y){
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapDouble(double* x,double* y){
    double temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapChar(char* x,char* y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}