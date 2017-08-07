#include "dyDoubleArray.h"
//	create double type array functions
//	multi dimentional arrays depends on each other !!
//	1D <- 2D <- 3D
//	call by value & returning pointer
/*
	Example:
	
	double *p1,
	      **p2,
	     ***p3;
	   
	p1 = createDoubleArray1D(x);		->	p1[x]
	p2 = createDoubleArray2D(y,x);		->	p2[y][x]
	p3 = createDoubleArray3D(z,y,x);	->	p3[z][y][x]
	
*/

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

//	fill double type array functions
//	multi dimentional arrays depends on each other !!
//	1D <- 2D <- 3D
//	call by reference
/*
	Example:
	
	fillDoubleArray1D( &p1,x,ch );
	fillDoubleArray1D( &p2,y,x,ch );
	fillDoubleArray1D( &p3,z,y,x,ch );
*/	

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

//	destroy double type array functions
//	multi dimentional arrays depends on each other !!
//	1D <- 2D <- 3D
//	call by reference	
/*
	Example:
		
		destroyDoubleArray1D( &p1 );
		destroyDoubleArray2D( &p2,y );
		destroyDoubleArray3D( &p3,z,y );
*/

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
