#ifndef DYDOUBLEARRAY_H_
#define DYDOUBLEARRAY_H_

double* createCharArray1D(int );
double** createCharArray2D(int , int );
double*** createCharArray3D(int , int , int );

void fillCharArray1D(double **,int ,double );
void fillCharArray2D(double ***ptr,int ,int ,double );
void fillCharArray3D(double ****ptr,int ,int ,int ,double );

void destroyCharArray1D(double **);
void destroyCharArray2D(double ***,int );
void destroyCharArray3D(double ****,int ,int );

#endif