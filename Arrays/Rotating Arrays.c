/* Rotating Arrays */ 

#include <stdio.h>
#include <stdlib.h>

int* rotate(int* array, int size, int rotations)
{
    int* result = (int*)malloc(sizeof(int) * size);
    if (!result) {
        exit(1);
    }

    rotations = rotations % size;

    for (int j = 0; j < size - rotations; j++)
    {
        result[j + rotations] = array[j];
    }

    for (int j = 0; j < rotations; j++)
    {
        result[j] = array[size - rotations + j];
    }

    return result;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int rotations = 2;

    int* rotated = rotate(arr, size, rotations);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", rotated[i]);
    }
    printf("\n");

    free(rotated);
    return 0;
}

