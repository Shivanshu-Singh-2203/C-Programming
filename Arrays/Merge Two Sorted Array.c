#include <stdio.h>
#include <stdlib.h>

int* mergeArrays(int arr1[], int size1, int arr2[], int size2) {
	int leftPointer = 0, rightPointer = 0, index = 0;
	int* result = (int*)malloc((size1 + size2) * sizeof(int));

  	if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
}

	while (leftPointer < size1 && rightPointer < size2) {
        if (arr1[leftPointer] <= arr2[rightPointer]) {
            result[index++] = arr1[leftPointer++];
        } else {
            result[index++] = arr2[rightPointer++];
        }
    }

	while (leftPointer < size1) {
        result[index++] = arr1[leftPointer++];
    }

    while (rightPointer < size2) {
        result[index++] = arr2[rightPointer++];
    	}

    return result;
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int* merged = mergeArrays(arr1, size1, arr2, size2);

    printf("Merged array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    free(merged); 
    return 0;
}

