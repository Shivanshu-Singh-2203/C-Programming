/* Majority Element in the array */

#include <stdio.h>

int majorityElement(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > size / 2) {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    int test1[] = {3, 3, 4, 2, 3};
    int test2[] = {1, 2, 3, 4};
    int test3[] = {2, 2, 1, 1, 2};
    int test4[] = {5, 5, 5, 5, 5, 1, 2};
    
    int tests[][7] = {
        {3, 3, 4, 2, 3},
        {1, 2, 3, 4},
        {2, 2, 1, 1, 2},
        {5, 5, 5, 5, 5, 1, 2}
    };
    
    int sizes[] = {5, 4, 5, 7};

    for (int i = 0; i < 4; i++) {
        int result = majorityElement(tests[i], sizes[i]);
        if (result != -1)
            printf("Test %d: Majority element = %d\n", i + 1, result);
        else
            printf("Test %d: No majority element\n", i + 1);
    }

    return 0;
}

