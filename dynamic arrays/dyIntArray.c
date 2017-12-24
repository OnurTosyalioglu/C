#include "dy_int_array.h"

int* create_int_array_1D(int x){
    int *ptr;

    ptr = (int*)malloc(x * sizeof(int));

    return ptr;
}

int** create_int_array_2D(int y, int x){
    int i;
    int **ptr;

    ptr = (int**)malloc(y * sizeof(int*));

    for(i=0 ; i<x ; i++){
        ptr[i] = createIntArray1D(x);
    }
    return ptr;
}

int*** create_int_array_3D(int z, int y, int x){
    int i;
    int ***ptr;

    ptr = (int***)malloc(z * sizeof(int**));

    for(i=0 ; i<x ; i++){
        ptr[i] = createIntArray2D(y,x);
    }
    return ptr;
}

void fill_int_array_1D(int **ptr,int x,int ch){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = ch;
	}
}

void fill_int_array_2D(int ***ptr,int y,int x,int ch){
	int i;
	for(i=0 ; i<y ; i++){
		fillIntArray1D( &(*ptr[i]),x,ch );
	}
}

void fill_int_array_3D(int ****ptr,int z,int y,int x,int ch){
	int i;
	for(i=0 ; i<z ; i++){
		fillIntArray2D( &(*ptr[i]),y,x,ch );
	}
}

void destroy_int_array_1D(int **ptr){
	free(*ptr);
}

void destroy_int_array_2D(int ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroyIntArray1D( &(*ptr)[i] );
	}
	free(*ptr);
}

void destroy_int_array_3D(int ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroyIntArray2D( &(*ptr)[i],y );
	}
}
