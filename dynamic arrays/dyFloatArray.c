#include "dyFloatArray.h"

float* createFloatArray1D(int x){
    float *ptr;

    ptr = (float*)malloc(x * sizeof(float));

    return ptr;
}

float** createFloatArray2D(int y, int x){
    int i;
    float **ptr;

    ptr = (float**)malloc(y * sizeof(float*));

    for(i=0 ; i<x ; i++){
        ptr[i] = createFloatArray1D(x);
    }
    return ptr;
}

float*** createFloatArray3D(int z, int y, int x){
    int i;
    float ***ptr;

    ptr = (float***)malloc(z * sizeof(float**));

    for(i=0 ; i<x ; i++){
        ptr[i] = createFloatArray2D(y,x);
    }
    return ptr;
}

void fillFloatArray1D(float **ptr,int x,float ch){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = ch;
	}
}

void fillFloatArray2D(float ***ptr,int y,int x,float ch){
	int i;
	for(i=0 ; i<y ; i++){
		fillFloatArray1D( &(*ptr[i]),x,ch ); 
	}
}

void fillFloatArray3D(float ****ptr,int z,int y,int x,float ch){
	int i;
	for(i=0 ; i<z ; i++){
		fillFloatArray2D( &(*ptr[i]),y,x,ch );
	}
}

void destroyFloatArray1D(float **ptr){
	free(*ptr);
}

void destroyFloatArray2D(float ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroyFloatArray1D( &(*ptr)[i] );
	}
	free(*ptr);
}

void destroyFloatArray3D(float ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroyFloatArray2D( &(*ptr)[i],y );
	}
}
