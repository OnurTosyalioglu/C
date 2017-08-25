#include "dyCharArray.h"

//	create char type array functions
//	multi dimentional arrays depends on each other !!
//	1D <- 2D <- 3D
//	call by value & returning pointer
/*
	Example:
	
	char *p1,
		**p2,
	   ***p3;
	   
	p1 = createCharArray1D(x);		->	p1[x]
	p2 = createCharArray2D(y,x);	->	p2[y][x]
	p3 = createCharArray3D(z,y,x);	->	p3[z][y][x]
	
*/

char* createCharArray1D(int x){
    char *ptr;

    ptr = (char*)malloc(x * sizeof(char));

    return ptr;
}
char** createCharArray2D(int y, int x){
    int i;
    char **ptr;

    ptr = (char**)malloc(y * sizeof(char*));

    for(i=0 ; i<x ; i++){
        ptr[i] = createCharArray1D(x);
    }
    return ptr;
}
char*** createCharArray3D(int z, int y, int x){
    int i;
    char ***ptr;

    ptr = (char***)malloc(z * sizeof(char**));

    for(i=0 ; i<x ; i++){
        ptr[i] = createCharArray2D(y,x);
    }
    return ptr;
}

//	fill char type array functions
//	multi dimentional arrays depends on each other !!
//	1D <- 2D <- 3D
//	call by reference
/*
	Example:
	
	fillCharArray1D( &p1,x,ch );
	fillCharArray1D( &p2,y,x,ch );
	fillCharArray1D( &p3,z,y,x,ch );
*/	

void fillCharArray1D(char **ptr,int x,char ch){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = ch;
	}
}
void fillCharArray2D(char ***ptr,int y,int x,char ch){
	int i;
	for(i=0 ; i<y ; i++){
		fillCharArray1D( &(*ptr[i]),x,ch ); 
	}
}
void fillCharArray3D(char ****ptr,int z,int y,int x,char ch){
	int i;
	for(i=0 ; i<z ; i++){
		fillCharArray2D( &(*ptr[i]),y,x,ch );
	}
}

//	destroy char type array functions
//	multi dimentional arrays depends on each other !!
//	1D <- 2D <- 3D
//	call by reference	
/*
	Example:
		
		destroyCharArray1D( &p1 );
		destroyCharArray2D(	&p2,y );
		destroyCharArray3D(	&p3,z,y );
*/

void destroyCharArray1D(char **ptr){
	free(*ptr);
}
void destroyCharArray2D(char ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroyCharArray1D( &(*ptr)[i] );
	}
	free(*ptr);
}
void destroyCharArray3D(char ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroyCharArray2D( &(*ptr)[i],y );
	}
}