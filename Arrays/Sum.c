/* Sum of elements of an array */ 

#include <stdio.h>
#define SIZE 5

int sum(int arr[])
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr1[SIZE] = {1, 2, 3, 4, 5};
    int arr2[SIZE] = {0, 0, 0, 0, 0};
    int arr3[SIZE] = {-1, -2, -3, -4, -5};
    int arr4[SIZE] = {10, 20, 30, 40, 50};
    int arr5[SIZE] = {100, -50, 25, -25, 0};

    printf("Sum of arr1: %d\n", sum(arr1));
    printf("Sum of arr2: %d\n", sum(arr2));
    printf("Sum of arr3: %d\n", sum(arr3));
    printf("Sum of arr4: %d\n", sum(arr4));
    printf("Sum of arr5: %d\n", sum(arr5));

    return 0;
}

