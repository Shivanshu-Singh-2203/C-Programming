/* Reverse an array in-place */

#include <stdio.h>

void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        // swap arr[start] and arr[end]
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);
    reverseArray(arr, size);

    printf("Reversed array: ");
    printArray(arr, size);

    return 0;
}

