#include "matrix.h"

int** initialize(int frows, int scolumns){
        int** result = malloc(sizeof(int*)*frows);
        for(int i = 0; i < frows; i ++){
                result[i] = malloc(sizeof(int)*scolumns);
        }

        return result;
}

int** multiply(int** first, int frows, int fcolumns, int** second, int srows, int scolumns){
        if(fcolumns != srows){
                printf("Matrix dimension mismatch.\n");
                exit(1);
        }

        int** result = initialize(frows, scolumns);
        for(int i = 0; i < frows; i ++){
                for(int j = 0; j < scolumns; j ++){
                        int temp = 0;
                        for(int k = 0; k < fcolumns; k ++){
                                temp += first[i][k] * second[k][j];
                        }
                        result[i][j] = temp;
                }
        }

        return result;
}

int** add(int** first, int r1, int c1, int** second, int r2, int c2){
        if(r1 != r2 && c1 != c2){
                printf("Matrix dimension mismatch.\n");
                exit(1);
        }

        int** result = initialize(r1, c1);

        for(int i = 0; i < r1; i ++){
                for(int k = 0; k < c1; k ++){
                        result[i][k] = first[i][k] + second[i][k]; 
                }
        }

        return result;
}


int** sub(int** first, int r1, int c1, int** second, int r2, int c2){
        if(r1 != r2 && c1 != c2){
                printf("Matrix dimension mismatch.\n");
                exit(1);
        }

        int** result = initialize(r1, c1);

        for(int i = 0; i < r1; i ++){
                for(int k = 0; k < c1; k ++){
                        result[i][k] = first[i][k] - second[i][k]; 
                }
        }

        return result;
}

int** transpose(int** mat, int r, int c){
        int** result = initialize(r, c);

        for(int i = 0; i < r; i ++){
                for(int k = 0; k < c; k ++){
                        result[i][k] = mat[k][i]; 
                }
        }

        return result;
}

int** getSubMatrix(int** mat, int rows, int cols, int index){
        int** temp = initialize(rows - 1, cols - 1);

        for(int i = 1 ; i < rows; i++){
                for(int j = 0; j < cols; j++){
                        if(j == index){
                                continue;
                        }

                        if(j < index){
                                temp[i-1][j] = mat[i][j];
                        }

                        else {
                                temp[i-1][j - 1] = mat[i][j];
                        }
                }
        }
        return temp;
}

int getsign(int rows, int columns){
        if((rows + columns) % 2 == 0){
                return 1;
        }
        return -1;
}

void freeMatrix(int** mat, int r){
        for(int i = 0; i < r; i++){
                free(mat[i]);
        }
        free(mat);
}

int determinant(int** mat, int rows, int columns){
        if(rows != columns){
                printf("Dimension mismatch.\n");
                exit(1);
        }
        
        if(rows == 1){
                return mat[0][0];
        }

        if(rows == 2){
                return mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1];
        }

        int result = 0;
        for(int i =0 ; i < columns; i ++){
                int** smallermat = getSubMatrix(mat, rows, columns, i);
                int sign = getsign(0,i);
                result += sign*mat[0][i]*determinant(smallermat, rows - 1, columns - 1);
                freeMatrix(smallermat, rows - 1);
        }
        return result;
}

void printMatrix(int ** mat, int r, int c){
        for(int i =0; i < r; i ++){
                for(int j = 0; j < c; j ++){
                        printf("%d ", mat[i][j]);
                }
                printf("\n");
        }
}
