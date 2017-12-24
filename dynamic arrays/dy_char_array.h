/**
 * Author  : Kemal Onur Tosyalioglu
 * Date    : 24.12.2017
 * Email   : onurtosylioglu@gmail.com
 * Purpose : Header file
 */

#ifndef DY_CHAR_ARRAY_H_
#define DY_CHAR_ARRAY_H_

char* create_char_array_1D(int );
char** create_char_array_2D(int , int );
char*** create_char_array_3D(int , int , int );

void fill_char_array_1D(char **,int ,char );
void fill_char_array_2D(char ***ptr,int ,int ,char );
void fill_char_array_3D(char ****ptr,int ,int ,int ,char );

void destroy_char_array_1D(char **);
void destroy_char_array_2D(char ***,int );
void destroy_char_array_3D(char ****,int ,int );

#endif
