/**
 * Author  : Kemal Onur Tosyalioglu
 * Date    : 24.12.2017
 * Email   : onurtosyalioglu@gmail.com
 * Purpose : Header file
 */

#ifndef DY_FLOAT_ARRAY_H_
#define DY_FLOAT_ARRAY_H_

float* create_float_array_1D(int );
float** create_float_array_2D(int , int );
float*** create_float_array_3D(int , int , int );

void fill_float_array_1D(float **,int ,float );
void fill_float_array_2D(float ***ptr,int ,int ,float );
void fill_float_array_3D(float ****ptr,int ,int ,int ,float );

void destroy_float_array_1D(float **);
void destroy_float_array_2D(float ***,int );
void destroy_float_array_3D(float ****,int ,int );

#endif
