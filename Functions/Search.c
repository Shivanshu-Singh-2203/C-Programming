/* Search in a Sorted and Rotated Array */

#include <stdio.h>
#include <stdbool.h>

bool searchRotated(int arr[], int size, int target)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return true;

        // Left half is sorted
        if (arr[low] <= arr[mid])
        {
            if (target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else
        {
            if (target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return false;
}

int main()
{
    int arr1[] = {4, 5, 6, 1, 2, 3};
    int arr2[] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};

    printf("Search 2 in arr1: %s\n", searchRotated(arr1, 6, 2) ? "Found" : "Not Found");
    printf("Search 5 in arr1: %s\n", searchRotated(arr1, 6, 5) ? "Found" : "Not Found");
    printf("Search 10 in arr2: %s\n", searchRotated(arr2, 10, 10) ? "Found" : "Not Found");
    printf("Search 11 in arr2: %s\n", searchRotated(arr2, 10, 11) ? "Found" : "Not Found");

    return 0;
}

