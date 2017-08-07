#ifndef DYINTARRAY_H_
#define DYINTARRAY_H_

int* createCharArray1D(int );
int** createCharArray2D(int , int );
int*** createCharArray3D(int , int , int );

void fillCharArray1D(int **,int ,int );
void fillCharArray2D(int ***ptr,int ,int ,int );
void fillCharArray3D(int ****ptr,int ,int ,int ,int );

void destroyCharArray1D(int **);
void destroyCharArray2D(int ***,int );
void destroyCharArray3D(int ****,int ,int );

#endif