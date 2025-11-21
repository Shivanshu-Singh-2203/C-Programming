#include <endian.h>
#include <stdio.h>
#include <stdlib.h>

int* concatenation(int* arrays, int size){
        int* newArrays = malloc(sizeof(int)*(2*size));
        for(int i = 0; i < 2 * size; i ++){
                newArrays[i] = arrays[i % size];
        }
        return newArrays;       
}

void printArrays(int* arrays, int size){
        for (int i = 0 ; i < size; i ++) {
                printf("Arrays elemets at index %d : %d\n", i, arrays[i]);
        }
}

int main(){
        int arrays[3] = {1, 2, 1};
        int* newArrays = concatenation(arrays, 3);
        printArrays(newArrays, 6);
        return 0;
}
