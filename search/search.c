#include "search.h"

int linear_search(int *arr,int size,int value){
    if(arr == NULL || size < 0){
        return -1;
    }

    int counter;

    for(counter=0 ; counter<size ; counter++){
        if( arr[counter]==value ){
            return counter;
        }
    }
    return -1;
}

int binary_search(int *arr,int size,int value){

    if(arr == NULL || size < 0){
        return -1;
    }

    int lo,mid,hi;
    lo = 0;
    hi = size;
    mid = 0;

    while( lo<=hi ){
        mid = lo + (hi-lo)/2;
        if( arr[mid]==value ){
            return mid;
        }
        if( arr[mid]>value ){
            hi = mid-1;
        }
        if( arr[mid]<value ){
            lo = mid+1;
        }
    }
    return -1;
}

int binary_search_recursive(int *arr,int lo,int hi,int value){

    int mid;

    mid = lo + (hi-lo)/2;

    if( lo>hi || arr == NULL || size < 0){
        return -1;
    }

    if( arr[mid]==value ){
        return mid;

    }
    else if( arr[mid]<value ){

        return binarySearchRecursive(arr,mid+1,hi,value);

    }
    else{

        return binarySearchRecursive(arr,lo,mid-1,value);

    }
}

int ternary_search(int *arr,int size,int value){

    if(arr == NULL || size < 0){
        return -1;
    }

    int lo,mid1,mid2,hi;
    lo = 0;
    mid1 = 0;
    mid2 = 0;
    hi = size;

    while(lo<=hi){

        mid1 = lo + (hi-lo)/3;
        mid2 = lo + 2*(hi-lo)/3;

        if( arr[mid1] == value ){
            return mid1;
        }
        if( arr[mid2] == value ){
            return mid2;
        }
        if( arr[mid1]>value ){
            hi = mid1-1;
        }else if( arr[mid1]<value && arr[mid2]>value){
            lo = mid1+1;
            hi = mid2-1;
        }else{
            lo = mid2+1;
        }
    }
    return -1;
}

int ternary_search_recursive(int *arr,int lo,int hi,int value){

    int mid1;
    int mid2;
    mid1 = lo + (hi-lo)/3;
    mid2 = lo + 2*(hi-lo)/3;

    if( lo>hi ){
        return -1;
    }
    if( arr[mid1] == value || arr == NULL || hi < 0){
        return mid1;
    }
    if( arr[mid2] == value ){
        return mid2;
    }
    if( arr[mid1]>value ){
        return ternarySearchRecursive(arr,lo,mid1-1,value);
    }else if( arr[mid2]<value ){
        return ternarySearchRecursive(arr,mid2+1,hi,value);
    }else{
        return ternarySearchRecursive(arr,mid1+1,mid2-1,value);
    }
}

int* binary_search_interval(int *arr,int size,int number){

    int *boundaries = (int*)malloc(2* sizeof(int));

    boundaries[0] = -1;
    boundaries[1] = -1;

    if( arr == NULL || size < 0 ){
        return boundaries;
    }

    int leftSide = -1;
    int rightSide = -1;

    int firstMatch = binarySearchRecursive(arr,0,size,number);
    leftSide = firstMatch;
    rightSide = firstMatch;

    if( firstMatch == -1){
        return boundaries;
    }

    int result = 0;

    while((result = binarySearchRecursive(arr, 0, leftSide - 1, number)) != -1){
        leftSide = result;
        result = binarySearchRecursive(arr, 0, leftSide - 1, number);
    }

    while((result = binarySearchRecursive(arr, rightSide + 1, size, number)) != -1){
        rightSide = result;
        result = binarySearchRecursive(arr, rightSide + 1, size, number);
    }

    boundaries[0] = leftSide;
    boundaries[1] = rightSide;

    return boundaries;
}
