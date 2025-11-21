#include <stdio.h>
#include <stdlib.h>

int* mergeArrays(int* first, int fsize, int *second, int ssize){
        int* result = malloc(sizeof(int)*(fsize + ssize));

        int leftPointer = 0;
        int rightPointer = 0;
        int current = 0;

        while(leftPointer < fsize && rightPointer < ssize){
                if(first[leftPointer] <  second[rightPointer]){
                        result[current] = first[leftPointer];
                        leftPointer ++;
                        current ++;
                }

                else  {
                        result[current] = second[rightPointer];
                        rightPointer ++;
                        current ++;
                }
        }

        while(leftPointer < fsize){
                result[current] = first[leftPointer];
                leftPointer ++;
                current ++;
        }
        
        while(rightPointer < ssize){
                result[current] = second[rightPointer];
                rightPointer ++;
                current ++;
        }
        return result;
}

void printArray(int* arr, int size){
        for(int i = 0 ; i < size; i ++){
                printf("%d ", arr[i]);
        }
        return;
}

int main() {
        int arr1[] = {1, 3, 5, 7};
        int arr2[] = {2, 4, 6, 8, 10};
        int size1 = sizeof(arr1) / sizeof(arr1[0]);
        int size2 = sizeof(arr2) / sizeof(arr2[0]);

        int* merged = mergeArrays(arr1, size1, arr2, size2);
        printArray(merged, size1 + size2);
        free(merged);
        return 0;
}
