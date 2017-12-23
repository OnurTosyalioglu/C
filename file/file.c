/*
 *  Author : Kemal Onur Tosyalioglu
 *  Email  : onurtosyalioglu@gmail.com
 *  Date   : 25.07.2017
 *  Topic  : wrapper functions for file access
 */

#include "file.h"

int file_exists(char *path){
    FILE *fp;
    fp = fopen(path,"r");
    if(fp == NULL){
        return 0;
    }else{
        fclose(fp);
        return 1;
    }
}

FILE* file_read(char *path){
    FILE *fp = fopen(path,"r");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* file_write(char *path){
    FILE *fp = fopen(path,"w");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* file_append(char *path){
    FILE *fp = fopen(path,"a");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* file_read_plus(char *path){
    FILE *fp = fopen(path,"r+");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* file_write_plus(char *path){
    FILE *fp = fopen(path,"w+");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* file_append_plus(char *path){
    FILE *fp = fopen(path,"a+");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

void write_string(FILE *fp,char *str){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%s",str)<0 ){
            perror("Error :");
        }
    }
}

void write_int(FILE *fp,int i){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%d",i)<0 ){
            perror("Error :");
        }
    }
}

void write_float(FILE *fp,float f){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%f",f)<0 ){
            perror("Error :");
        }
    }
}

void write_double(FILE *fp,double d){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%lf",d)<0 ){
            perror("Error :");
        }
    }
}

void write_char(FILE *fp,char c){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%c",c)<0 ){
            perror("Error :");
        }
    }
}

void write_ln(FILE *fp){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"\n")<0 ){
            perror("Error :");
        }
    }
}

void write_tab(FILE *fp){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"\t" )<0){
            perror("Error :");
        }
    }
}

void write_space(FILE *fp){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp," ")<0 ){
            perror("Error :");
        }
    }
}