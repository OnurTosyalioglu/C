/**
 * Author  : Kemal Onur Tosyalioglu
 * Date    : 24.12.2017
 * Email   : onurtosylioglu@gmail.com
 * Purpose : Header file
 */

#ifndef DYDOUBLEARRAY_H_
#define DYDOUBLEARRAY_H_

double* create_double_array_1D(int );
double** create_double_array_2D(int , int );
double*** create_double_array_3D(int , int , int );

void fill_double_array_1D(double **,int ,double );
void fill_double_array_2D(double ***ptr,int ,int ,double );
void fill_double_array_3D(double ****ptr,int ,int ,int ,double );

void destroy_double_array_1D(double **);
void destroy_double_array_2D(double ***,int );
void destroy_double_array_3D(double ****,int ,int );

#endif
