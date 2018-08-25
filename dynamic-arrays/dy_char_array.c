#include "dy_char_array.h"

void create_char_array_1D(char *ptr, int x)
{
    ptr = (char*)malloc(x * sizeof(char));

    return ptr;
}

void create_char_array_2D(char **ptr, int y, int x){
    int i;

    ptr = (char**)malloc(y * sizeof(char*));

    for(i=0 ; i<x ; i++){
        create_char_array_1D(*ptr,x);
    }
    return ptr;
}

void create_char_array_3D(char ***ptr, int z, int y, int x){
    int i;

    ptr = (char***)malloc(z * sizeof(char**));

    for(i=0 ; i<x ; i++){
        create_char_array_2D(y,x);
    }

    return ptr;
}

void fill_char_array_1D(char **ptr,int x,char ch){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = ch;
	}
}

void fill_char_array_2D(char ***ptr,int y,int x,char ch){
	int i;
	for(i=0 ; i<y ; i++){
		fill_char_array_1D( &(*ptr[i]),x,ch );
	}
}

void fill_char_array_3D(char ****ptr,int z,int y,int x,char ch){
	int i;
	for(i=0 ; i<z ; i++){
		fill_char_array_2D( &(*ptr[i]),y,x,ch );
	}
}

void destroy_char_array_1D(char **ptr){
	free(*ptr);
}

void destroy_char_array_2D(char ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroy_char_array_1D( &(*ptr)[i] );
	}
	free(*ptr);
}

void destroy_char_array_3D(char ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroy_char_array_2D( &(*ptr)[i],y );
	}
}
