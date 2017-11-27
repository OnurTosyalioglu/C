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

double* createDoubleArray1D(int x){
    double *ptr;

    ptr = (double*)malloc(x * sizeof(double));

    return ptr;
}

double** createDoubleArray2D(int y, int x){
    int i;
    double **ptr;

    ptr = (double**)malloc(y * sizeof(double*));

    for(i=0 ; i<x ; i++){
        ptr[i] = createDoubleArray1D(x);
    }
    return ptr;
}

double*** createDoubleArray3D(int z, int y, int x){
    int i;
    double ***ptr;

    ptr = (double***)malloc(z * sizeof(double**));

    for(i=0 ; i<x ; i++){
        ptr[i] = createDoubleArray2D(y,x);
    }
    return ptr;
}

void fillDoubleArray1D(double **ptr,int x,double ch){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = ch;
	}
}

void fillDoubleArray2D(double ***ptr,int y,int x,double ch){
	int i;
	for(i=0 ; i<y ; i++){
		fillDoubleArray1D( &(*ptr[i]),x,ch ); 
	}
}

void fillDoubleArray3D(double ****ptr,int z,int y,int x,double ch){
	int i;
	for(i=0 ; i<z ; i++){
		fillDoubleArray2D( &(*ptr[i]),y,x,ch );
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
