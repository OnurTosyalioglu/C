/**
 *  Author  : Kemal Onur Tosyalioglu
 *  Email   : onurtosyalioglu@gmail.com
 *  Date    : 28.11.2017
 *  Purpose : Wrapper functions for dynamic array creation
 */

/**
 *   @header
 */

#include "dy_double_array.h"

/**
 *  @description
 *  	Creating 1D dynamic double array
 *
 *	@param int x
 *		Size of first dimension
 *
 *	@return double *ptr
 *		returns double type dynamicly allocated pointer (ptr)
 */

double* create_double_array_1D(int x){
    double *ptr;

    ptr = (double*)malloc(x * sizeof(double));

    return ptr;
}

/**
 *  @description
 *  	Creating 2D dynamic double array
 *
 *	@param int x
 *		Size of first dimension
 *
 *  @param int y
 *		Size of second dimension
 *
 *	@return double **ptr
 *		returns double type dynamicly allocated pointer (ptr)
 */

double** create_double_array_2D(int y, int x){
    int i;
    double **ptr;

    ptr = (double**)malloc(y * sizeof(double*));

    for(i=0 ; i<x ; i++){
        ptr[i] = create_double_array_1D(x);
    }
    return ptr;
}

/**
 *  @description
 *  	Creating 3D dynamic double array
 *
 *	@param int x
 *		Size of first dimension
 *
 *  @param int y
 *		Size of second dimension
 *
 *	@param int z
 *		Size of third dimension
 *
 *	@return double ***ptr
 *		returns double type dynamicly allocated pointer (ptr)
 */

double*** create_double_array_3D(int z, int y, int x){
    int i;
    double ***ptr;

    ptr = (double***)malloc(z * sizeof(double**));

    for(i=0 ; i<x ; i++){
        ptr[i] = create_double_array_2D(y,x);
    }
    return ptr;
}

/**
 *  @description
 * 		Filling 1D char array with intended character
 *
 *	@param char **ptr
 *		1D char array passing by reference
 *
 *  @param int x
 *		Size of first dimension
 *
 *	@param double
 *		Intended character
 */

void fill_double_array_1D(double **ptr,int x,double number){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = number;
	}
}

/**
 *  @description
 *      Filling 1D char array with intended character
 *
 *  @param char **ptr
 *      1D char array passing by reference
 *
 *  @param int x
 *      Size of first dimension
 *
 *  @param int y
 *      Size of second dimension
 *
 *  @param double
 *      Intended character
 */

void fill_double_array_2D(double ***ptr,int y,int x,double number){
	int i;
	for(i=0 ; i<y ; i++){
		fill_double_array_1D( &(*ptr[i]),x,number );
	}
}

/**
 *  @description
 *      Filling 1D char array with intended character
 *
 *  @param char **ptr
 *      1D char array passing by reference
 *
 *  @param int x
 *      Size of first dimension
 *
 *  @param int y
 *      Size of second dimension
 *
 *  @param int z
 *      Size of third dimension
 *
 *  @param double
 *      Intended character
 */

void fill_double_array_3D(double ****ptr,int z,int y,int x,double number){
	int i;
	for(i=0 ; i<z ; i++){
		fill_double_array_2D( &(*ptr[i]),y,x,number);
	}
}

/**
 *  @description
 *      Destroying 2D double array
 *
 *  @param double **ptr
 *      1D double array passing by reference
 */

void destroy_double_array_1D(double **ptr){
	free(*ptr);
}

/**
 *  @description
 *      Destroying 2D double array
 *
 *  @param double ***ptr
 *      3D double array passing by reference
 *
 *  @param int y
 *      Second dimension of array
 */

void destroy_double_array_2D(double ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroy_double_array_1D( &(*ptr)[i] );
	}
	free(*ptr);
}

/**
 *  @description
 *      Destroying 2D double array
 *
 *  @param double ****ptr
 *      3D double array passing by reference
 *
 *  @param int y
 *      Second dimension of array
 *
 *  @param int z
 *      Third dimension of array
 */

void destroy_double_array_3D(double ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroy_double_array_2D( &(*ptr)[i],y );
	}
}
