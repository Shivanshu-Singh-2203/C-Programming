/* Bubble Sort using Pointers */ 

#include <stddef.h>
#include <stdio.h>

#include <stdio.h>

void swap(int* src, int* destination) {
    int temp = *src;
    *src = *destination;
    *destination = temp;
}

void bubbleSort(int* const arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size - 1; j++) {
            if (*arr[j] > *arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int* const arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", *arr[i]);
    }
    printf("\n");
}

int main() {
    int a = 5, b = 2, c = 9, d = 1, e = 5, f = 6;
    int* arr1[] = {&a, &b, &c, &d, &e, &f};
    size_t size1 = sizeof(arr1)/sizeof(arr1[0]);

    printf("Before sorting: ");
    printArray(arr1, size1);

    bubbleSort(arr1, size1);

    printf("After sorting:  ");
    printArray(arr1, size1);

    return 0;
}

