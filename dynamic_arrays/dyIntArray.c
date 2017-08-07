#include "dyIntArray.h"
//	create int type array functions
//	multi dimentional arrays depends on each other !!
//	1D <- 2D <- 3D
//	call by value & returning pointer
/*
	Example:
	
	int *p1,
	   **p2,
	  ***p3;
	   
	p1 = createIntArray1D(x);		->	p1[x]
	p2 = createIntArray2D(y,x);		->	p2[y][x]
	p3 = createIntArray3D(z,y,x);		->	p3[z][y][x]
	
*/

int* createIntArray1D(int x){
    int *ptr;

    ptr = (int*)malloc(x * sizeof(int));

    return ptr;
}
int** createIntArray2D(int y, int x){
    int i;
    int **ptr;

    ptr = (int**)malloc(y * sizeof(int*));

    for(i=0 ; i<x ; i++){
        ptr[i] = createIntArray1D(x);
    }
    return ptr;
}
int*** createIntArray3D(int z, int y, int x){
    int i;
    int ***ptr;

    ptr = (int***)malloc(z * sizeof(int**));

    for(i=0 ; i<x ; i++){
        ptr[i] = createIntArray2D(y,x);
    }
    return ptr;
}

//	fill int type array functions
//	multi dimentional arrays depends on each other !!
//	1D <- 2D <- 3D
//	call by reference
/*
	Example:
	
	fillIntArray1D( &p1,x,ch );
	fillIntArray1D( &p2,y,x,ch );
	fillIntArray1D( &p3,z,y,x,ch );
*/	

void fillIntArray1D(int **ptr,int x,int ch){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = ch;
	}
}
void fillIntArray2D(int ***ptr,int y,int x,int ch){
	int i;
	for(i=0 ; i<y ; i++){
		fillIntArray1D( &(*ptr[i]),x,ch ); 
	}
}
void fillIntArray3D(int ****ptr,int z,int y,int x,int ch){
	int i;
	for(i=0 ; i<z ; i++){
		fillIntArray2D( &(*ptr[i]),y,x,ch );
	}
}

//	destroy int type array functions
//	multi dimentional arrays depends on each other !!
//	1D <- 2D <- 3D
//	call by reference	
/*
	Example:
		
		destroyIntArray1D( &p1 );
		destroyIntArray2D( &p2,y );
		destroyIntArray3D( &p3,z,y );
*/

void destroyIntArray1D(int **ptr){
	free(*ptr);
}
void destroyIntArray2D(int ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroyIntArray1D( &(*ptr)[i] );
	}
	free(*ptr);
}
void destroyIntArray3D(int ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroyIntArray2D( &(*ptr)[i],y );
	}
}
