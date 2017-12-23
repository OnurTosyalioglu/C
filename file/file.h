/*
 *  Author : Kemal Onur Tosyalioglu
 *  Email  : onurtosyalioglu@gmail.com
 *  Date   : 25.07.2017
 *  Topic  : function prototypes of file.c
 */

#ifndef FILE_H_
#define FILE_H_

int file_exists(char *);
FILE* file_read(char *);
FILE* file_write(char *);
FILE* file_append(char *);
FILE* file_read_plus(char *);
FILE* file_write_plus(char *);
FILE* file_append_plus(char *);
void write_string(FILE *,char *);
void write_char(FILE *,char );
void write_int(FILE *,int );
void write_float(FILE *,float );
void write_double(FILE *,double );
void write_ln(FILE *);
void write_tab(FILE *);
void write_space(FILE *);

#endif