/* Find missing number in a a sorted array containing from 1 to n */

#include <stdio.h>

int findMissingNaturalNumber(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid) {
            // missing number is on the right
            low = mid + 1;
        } else {
            // missing number is on the left
            high = mid - 1;
        }
    }
    return low; // low points to the missing number
}

int main() {
    int arr[] = {0, 1, 2, 3, 5, 6, 7}; // missing 4
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Missing number: %d\n", findMissingNaturalNumber(arr, n));
    return 0;
}

