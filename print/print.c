/*
 *  Author : Kemal Onur Tosyalioglu
 *  Email  : onurtosyalioglu@gmail.com
 *  Date   : 25.07.2017
 *  Topic  : redifining printf functions
 *	to higher access (without placeholers)
 *
 */

#include "print.h"

void print_char(char ch){
    printf("%c",ch);
}

void print_int(int number){
    printf("%d",number);
}

void print_float(float number){
    printf("%f",number);
}

void print_double(double number){
    printf("%lf",number);
}
/*
 *	param -> total : total digits
 *		  -> prec  : fraction
 *
 */
void print_float_formed(float number,int total,int prec){
    printf("%*.*lf",total,prec,number);
}

/*
 *	param -> total : total digits
 *		  -> prec  : fraction
 *
 */

void print_double_formed(double number,int total,int prec){
    printf("%*.*lf",total,prec,number);
}

/*
 *	exponential form of float
 *	param -> total : total digits
 *		  -> prec  : fraction
 *
 */

void print_float_formed_expo(float number,int total,int prec){
    printf("%*.*e",total,prec,number);
}

/*
 *	exponential form of double
 *	param -> total : total digits
 *		  -> prec  : fraction
 *
 */

void print_double_formed_expo(double number,int total,int prec){
    printf("%*.*e",total,prec,number);
}

void print_string(char *str){
    printf("%s",str);
}

void print_space(){
    printf(" ");
}

void print_line(){
    printf("\n");
}

void print_tab(){
    printf("\t");
}
