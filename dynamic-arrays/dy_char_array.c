/**
 *  Author  : Kemal Onur Tosyalioglu
 *  Email   : onurtosyalioglu@gmail.com
 *  Date    : 28.11.2017
 *  Purpose : Wrapper functions for dynamic array creation
 */

/**
 *   @header
 */

#include "dy_char_array.h"

/**
 *  @description
 *  	Creating 1D dynamic char array
 *
 *	@param int x
 *		Size of first dimension
 *
 *	@return char *ptr
 *		returns char type dynamicly allocated pointer (ptr)
 */

char* create_char_array_1D(int x){
    char *ptr;

    ptr = (char*)malloc(x * sizeof(char));

    return ptr;
}

/**
 *  @description
 *  	Creating 2D dynamic char array
 *
 *	@param int x
 *		Size of first dimension
 *
 *  @param int y
 *		Size of second dimension
 *
 *	@return char **ptr
 *		returns char type dynamicly allocated pointer (ptr)
 */

char** create_char_array_2D(int y, int x){
    int i;
    char **ptr;

    ptr = (char**)malloc(y * sizeof(char*));

    for(i=0 ; i<x ; i++){
        ptr[i] = create_char_array_1D(x);
    }
    return ptr;
}

/**
 *  @description
 *  	Creating 3D dynamic char array
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
 *	@return char ***ptr
 *		returns char type dynamicly allocated pointer (ptr)
 */

char*** create_char_array_3D(int z, int y, int x){
    int i;
    char ***ptr;

    ptr = (char***)malloc(z * sizeof(char**));

    for(i=0 ; i<x ; i++){
        ptr[i] = create_char_array_2D(y,x);
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
 *	@param char ch
 *		Intended character
 */

void fill_char_array_1D(char **ptr,int x,char ch){
	int i;
	for(i=0 ; i<x ; i++){
		(*ptr)[i] = ch;
	}
}

/**
 *  @description
 * 		Filling 2D char array with intended character
 *
 *	@param char ***ptr
 *		2D char array passing by reference
 *
 *  @param int x
 *		Size of first dimension
 *
 *	@param int y
 *		Size of second dimension
 *
 *	@param char ch
 *		Intended character
 */

void fill_char_array_2D(char ***ptr,int y,int x,char ch){
	int i;
	for(i=0 ; i<y ; i++){
		fill_char_array_1D( &(*ptr[i]),x,ch );
	}
}

/**
 *  @description
 * 		Filling 3D char array with intended character
 *
 *	@param char ***ptr
 *		3D char array passing by reference
 *
 *  @param int x
 *		Size of first dimension
 *
 *	@param int y
 *		Size of second dimension
 *
 *	@param int z
 *		Size of third dimension
 *
 *	@param char ch
 *		Intended character
 */

void fill_char_array_3D(char ****ptr,int z,int y,int x,char ch){
	int i;
	for(i=0 ; i<z ; i++){
		fill_char_array_2D( &(*ptr[i]),y,x,ch );
	}
}

/**
 *  @description
 *		Destroying 1D char array
 *
 *	@param char **ptr
 *		1D char array passing by reference
 */

void destroy_char_array_1D(char **ptr){
	free(*ptr);
}

/**
 *  @description
 *		Destroying 2D char array
 *
 *	@param char **ptr
 *		2D char array passing by reference
 *
 *	@param int y
 *		Second dimension of array
 */

void destroy_char_array_2D(char ***ptr,int y){
	int i;
	for(i=0 ; i<y ; i++){
		destroy_char_array_1D( &(*ptr)[i] );
	}
	free(*ptr);
}

/**
 *  @description
 *		Destroying 2D char array
 *
 *	@param char **ptr
 *		2D char array passing by reference
 *
 *	@param int y
 *		Second dimension of array
 *
 *	@param int z
 *		Third dimension of array
 */

void destroy_char_array_3D(char ****ptr,int z,int y){
	int i;
	for(i=0 ; i<z ; i++){
		destroy_char_array_2D( &(*ptr)[i],y );
	}
}
