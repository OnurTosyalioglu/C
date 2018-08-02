/**
 * Author  : Kemal Onur Tosyalioglu
 * Date    : 24.12.2017
 * Email   : onurtosyalioglu@gmail.com
 * Purpose : Wrapper functions for dynamic array creation
 */

/**
 *   @header
 */

#include "dy_float_array.h"

float* create_float_array_1D(int x){
    float *ptr;

    ptr = (float*)malloc(x * sizeof(float));

    return ptr;
}

float** create_float_array_2D(int y, int x){
    int i;
    float **ptr;

    ptr = (float**)malloc(y * sizeof(float*));

    for(i=0 ; i<x ; i++){
        ptr[i] = create_float_array_1D(x);
    }
    return ptr;
}

float*** create_float_array_3D(int z, int y, int x){
    int i;
    float ***ptr;

    ptr = (float***)malloc(z * sizeof(float**));

    for(i=0 ; i<x ; i++){
        ptr[i] = create_float_array_2D(y,x);
    }
    return ptr;
}

void fill_float_array_1D(float **ptr,int x,float ch){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = ch;
	}
}

void fill_float_array_2D(float ***ptr,int y,int x,float ch){
	int i;
	for(i=0 ; i<y ; i++){
		fill_float_array_1D( &(*ptr[i]),x,ch );
	}
}

void fill_float_array_3D(float ****ptr,int z,int y,int x,float ch){
	int i;
	for(i=0 ; i<z ; i++){
		fill_float_array_2D( &(*ptr[i]),y,x,ch );
	}
}

void destroy_float_array_1D(float **ptr){
	free(*ptr);
}

void destroy_float_array_2D(float ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroy_float_array_1D( &(*ptr)[i] );
	}
	free(*ptr);
}

void destroy_float_array_3D(float ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroy_float_array_2D( &(*ptr)[i],y );
	}
}
