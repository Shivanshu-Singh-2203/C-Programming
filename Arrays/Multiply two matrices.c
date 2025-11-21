#include <stdio.h>
#include <stdlib.h>

int** multiply(int** first, int frows, int fcolumns, int** second, int srows, int scolumns){
        if(fcolumns != srows){
                printf("Matrix dimension mismatch.\n");
                exit(1);
        }

        int** result = malloc(sizeof(int*)*frows);
        for(int i = 0; i < frows; i ++){
                result[i] = malloc(sizeof(int)*scolumns);
        }
        
        for(int i = 0; i < frows; i ++){
                for(int j = 0; j < scolumns; j ++){
                        int temp = 0;
                        for(int k = 0; k < fcolumns; k ++){
                                temp += first[i][k] + second[k][j];
                        }
                        result[i][j] = temp;
                }
        }

        return result;
}

