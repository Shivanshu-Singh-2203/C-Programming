#include <stdio.h>

void print(int* pointer, int size)
{
    printf("Printing the array using pointer.\n");
    for(int i = 0; i < size; i ++)
    {
        printf("%d ", *(pointer + i));
    } 
    printf("\n");
}

int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30};
    int arr3[] = {7};

    print(arr1, 5);
    print(arr2, 3);
    print(arr3, 1);

    return 0;
}

