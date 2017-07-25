/*  
 *  Author : Kemal Onur Tosyalioglu
 *  Email  : onurtosyalioglu@gmail.com
 *  Date   : 25.07.2017
 *  Topic  : redifining printf functions
 *	to higher access (without placeholers)
 *
 */

#include "print.h"

void printChar(char ch){
    printf("%c",ch);
}

void printInt(int number){
    printf("%d",number);
}

void printFloat(float number){
    printf("%f",number);
}

void printDouble(double number){
    printf("%lf",number);
}
/*
 *	param -> total : total digits
 *		  -> prec  : fraction
 *
 */	
void printFormFloat(float number,int total,int prec){
    printf("%*.*lf",total,prec,number);
}

/*
 *	param -> total : total digits
 *		  -> prec  : fraction
 *
 */	

void printFormDouble(double number,int total,int prec){
    printf("%*.*lf",total,prec,number);
}

/*	
 *	exponential form of float
 *	param -> total : total digits
 *		  -> prec  : fraction
 *
 */	

void printExpoFormFloat(float number,int total,int prec){
    printf("%*.*e",total,prec,number);
}

/*	
 *	exponential form of double
 *	param -> total : total digits
 *		  -> prec  : fraction
 *
 */	

void printExpoFormDouble(double number,int total,int prec){
    printf("%*.*e",total,prec,number);
}

void printString(char *str){
    printf("%s",str);
}

void printSpace(){
    printf(" ");
}

void printLn(){
    printf("\n");
}

void printTab(){
    printf("\t");
}