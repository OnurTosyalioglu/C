/**
 *  Author : Kemal Onur Tosyalioglu
 *  Email : onurtosyalioglu@gmail.com
 *  Date : 28.11.2017
 *  Subject : Dynamic double array implementation  
 */

/**
 *   header file
 */

#include "dyDoubleArray.h"

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

double* createDoubleArray1D(int x){
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

double** createDoubleArray2D(int y, int x){
    int i;
    double **ptr;

    ptr = (double**)malloc(y * sizeof(double*));

    for(i=0 ; i<x ; i++){
        ptr[i] = createDoubleArray1D(x);
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

double*** createDoubleArray3D(int z, int y, int x){
    int i;
    double ***ptr;

    ptr = (double***)malloc(z * sizeof(double**));

    for(i=0 ; i<x ; i++){
        ptr[i] = createDoubleArray2D(y,x);
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

void fillDoubleArray1D(double **ptr,int x,double number){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = number;
	}
}

void fillDoubleArray2D(double ***ptr,int y,int x,double number){
	int i;
	for(i=0 ; i<y ; i++){
		fillDoubleArray1D( &(*ptr[i]),x,number ); 
	}
}

void fillDoubleArray3D(double ****ptr,int z,int y,int x,double number){
	int i;
	for(i=0 ; i<z ; i++){
		fillDoubleArray2D( &(*ptr[i]),y,x,number);
	}
}

void destroyDoubleArray1D(double **ptr){
	free(*ptr);
}

void destroyDoubleArray2D(double ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroyDoubleArray1D( &(*ptr)[i] );
	}
	free(*ptr);
}

void destroyDoubleArray3D(double ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroyDoubleArray2D( &(*ptr)[i],y );
	}
}
