#ifndef DYCHARARRAY_H_
#define DYCHARARRAY_H_

char* createCharArray1D(int );
char** createCharArray2D(int , int );
char*** createCharArray3D(int , int , int );

void fillCharArray1D(char **,int ,char );
void fillCharArray2D(char ***ptr,int ,int ,char );
void fillCharArray3D(char ****ptr,int ,int ,int ,char );

void destroyCharArray1D(char **);
void destroyCharArray2D(char ***,int );
void destroyCharArray3D(char ****,int ,int );

#endif