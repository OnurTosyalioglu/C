#ifndef DY_INT_ARRAY_H_
#define DY_INT_ARRAY_H_

int* create_int_array_1D(int );
int** create_int_array_2D(int , int );
int*** create_int_array_3D(int , int , int );

void fill_int_array_1D(int **,int ,int );
void fill_int_array_2D(int ***ptr,int ,int ,int );
void fill_int_array_3D(int ****ptr,int ,int ,int ,int );

void destroy_int_array_1D(int **);
void destroy_int_array_2D(int ***,int );
void destroy_int_array_3D(int ****,int ,int );

#endif
