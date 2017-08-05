/*  
 *  Author : Kemal Onur Tosyalioglu
 *  Email  : onurtosyalioglu@gmail.com
 *  Date   : 25.07.2017
 *  Topic  : function prototypes of file.c
 *
 */

#ifndef FILE_H_
#define FILE_H_

int fileExists(char *);
FILE* fileRead(char *);
FILE* fileWrite(char *);
FILE* fileAppend(char *);
FILE* fileReadPlus(char *);
FILE* fileWritePlus(char *);
FILE* fileAppendPlus(char *);
void writeFileString(FILE *,char *);
void writeFileChar(FILE *,char );
void writeFileInt(FILE *,int );
void writeFileFloat(FILE *,float );
void writeFileDouble(FILE *,double );
void writeFileLn(FILE *);
void writeFileTab(FILE *);
void writeFileSpace(FILE *);

#endif