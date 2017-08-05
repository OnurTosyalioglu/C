/*  
 *  Author : Kemal Onur Tosyalioglu
 *  Email  : onurtosyalioglu@gmail.com
 *  Date   : 25.07.2017
 *  Topic  : redifining file functions
 *  to higher access (without modes)
 *
 */

#include "file.h"

int fileExists(char *path){
    FILE *fp;
    fp = fopen(path,"r");
    if(fp == NULL){
        return 0;
    }else{
        fclose(fp);
        return 1;
    }
}

FILE* fileRead(char *path){
    FILE *fp = fopen(path,"r");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* fileWrite(char *path){
    FILE *fp = fopen(path,"w");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* fileAppend(char *path){
    FILE *fp = fopen(path,"a");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* fileReadPlus(char *path){
    FILE *fp = fopen(path,"r+");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* fileWritePlus(char *path){
    FILE *fp = fopen(path,"w+");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

FILE* fileAppendPlus(char *path){
    FILE *fp = fopen(path,"a+");
    if( fp == NULL ){
        perror("Error :");
    }
    return fp;
}

void writeFileString(FILE *fp,char *str){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%s",str)<0 ){
            perror("Error :");
        }
    }
}

void writeFileInt(FILE *fp,int i){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%d",i)<0 ){
            perror("Error :");
        }
    }
}

void writeFileFloat(FILE *fp,float f){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%f",f)<0 ){
            perror("Error :");
        }
    }
}

void writeFileDouble(FILE *fp,double d){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%lf",d)<0 ){
            perror("Error :");
        }
    }
}

void writeFileChar(FILE *fp,char c){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"%c",c)<0 ){
            perror("Error :");
        }
    }
}

void writeFileLn(FILE *fp){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"\n")<0 ){
            perror("Error :");
        }
    }
}

void writeFileTab(FILE *fp){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp,"\t" )<0){
            perror("Error :");
        }
    }
}

void writeFileSpace(FILE *fp){
    if( fp == NULL ){
        perror("Error :");
    }else{
        if( fprintf(fp," ")<0 ){
            perror("Error :");
        }
    }
}