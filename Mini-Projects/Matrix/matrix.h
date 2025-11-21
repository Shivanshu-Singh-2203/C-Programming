#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

int** initialize(int, int);
void printMatrix(int** , int, int);
int** sub(int** , int , int , int**, int, int);
int** multiply(int** , int , int , int**, int, int);
int** add(int** , int , int , int**, int, int);
int** transpose(int**, int , int);
int** getSubMatrix(int**, int , int , int);
void freeMatrix(int**, int);
int determinant(int**, int, int);

#endif // !MATRIX_H
