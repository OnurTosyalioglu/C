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
        ptr[i] = create_int_array_1D(x);
    }
    return ptr;
}

int*** create_int_array_3D(int z, int y, int x){
    int i;
    int ***ptr;

    ptr = (int***)malloc(z * sizeof(int**));

    for(i=0 ; i<x ; i++){
        ptr[i] = create_int_array_2D(y,x);
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
		fill_int_array_1D( &(*ptr[i]),x,ch );
	}
}

void fill_int_array_3D(int ****ptr,int z,int y,int x,int ch){
	int i;
	for(i=0 ; i<z ; i++){
		fill_int_array_2D( &(*ptr[i]),y,x,ch );
	}
}

void destroy_int_array_1D(int **ptr){
	free(*ptr);
}

void destroy_int_array_2D(int ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroy_int_array_1D( &(*ptr)[i] );
	}
	free(*ptr);
}

void destroy_int_array_3D(int ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroy_int_array_2D( &(*ptr)[i],y );
	}
}
