/* Find the maximum and minimum element in the array. */

#include <stdio.h>
#include <math.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

void extrema(int arr[], int size) {
    int max = -2147483648; // Smallest possible int
    int min =  2147483647; // Largest possible int

    for (int i = 0; i < size; i++) {
        max = MAX(max, arr[i]);
        min = MIN(min, arr[i]);
    }

    printf("The maximum element in the array is: %d\n", max);
    printf("The minimum element in the array is: %d\n", min);
}

int main() {
    int arr[] = {5, 7, 2, 9, -3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    extrema(arr, size);
    return 0;
}

