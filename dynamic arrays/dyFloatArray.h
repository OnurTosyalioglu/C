/**
 * Author  : Kemal Onur Tosyalioglu
 * Date    : 24.12.2017
 * Email   : onurtosyalioglu@gmail.com
 * Purpose : Header file
 */

#ifndef DYCHARARRAY_H_
#define DYFLOATARRAY_H_

float* createCharArray1D(int );
float** createCharArray2D(int , int );
float*** createCharArray3D(int , int , int );

void fillCharArray1D(float **,int ,float );
void fillCharArray2D(float ***ptr,int ,int ,float );
void fillCharArray3D(float ****ptr,int ,int ,int ,float );

void destroyCharArray1D(float **);
void destroyCharArray2D(float ***,int );
void destroyCharArray3D(float ****,int ,int );

#endif
