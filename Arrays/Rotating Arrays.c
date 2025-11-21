#include <stdio.h>
#include <stdlib.h>

int * rotateArrays(int* arr, int size, int offset){
        int* result = malloc(sizeof(int)*size);

        for(int i = 0; i < size; i ++){
                result[i] = arr[(i + offset) % size];
        }
        return result;
}

int main(void)
{
        int arr[] = {1, 2, 3, 4, 5};
        int size = sizeof(arr) / sizeof(arr[0]);
        int rotations = 2;

        int* rotated = rotateArrays(arr, size, rotations);

        for (int i = 0; i < size; i++)
        {
        printf("%d ", rotated[i]);
        }
        printf("\n");

        free(rotated);
        return 0;
}
