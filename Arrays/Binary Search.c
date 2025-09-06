/* Binary Search */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (high - low) / 2 + low;
        if (arr[mid] == element) {
            return 1;
        } else {
            if (arr[mid] > element) {
                high = mid - 1;
            }
            if (arr[mid] < element) {
                low = mid + 1;
            }
        }
    }
    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr1[] = {1, 3, 5, 7, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Array 1: ");
    printArray(arr1, size1);
    printf("Search 5: %d\n", binarySearch(arr1, size1, 5));
    printf("Search 2: %d\n", binarySearch(arr1, size1, 2));

    int arr2[] = {10, 20, 30, 40, 50, 60};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nArray 2: ");
    printArray(arr2, size2);
    printf("Search 40: %d\n", binarySearch(arr2, size2, 40));
    printf("Search 100: %d\n", binarySearch(arr2, size2, 100));

    srand(time(NULL));
    int size3 = 10;
    int arr3[10];
    for (int i = 0; i < size3; i++) {
        arr3[i] = i * 2;
    }

    printf("\nArray 3 (random search values): ");
    printArray(arr3, size3);

    for (int t = 0; t < 5; t++) {
        int x = rand() % 25;
		printf("Search %d: %d\n", x, binarySearch(arr3, size3, x));
    }

    return 0;
}

