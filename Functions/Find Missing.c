/* Find Missing Element in an array */

#include <stdio.h>

int missing(int arr[], int size)
{
    int sum = (size * (size - 1)) / 2;
    for (int i = 0; i < size; i++)
    {
        sum -= arr[i];
    }
    return sum;
}

int main()
{
    int test1[] = {0, 1, 3, 4};
    int test2[] = {0, 1, 2, 4, 5};
    int test3[] = {1, 2, 3, 4, 5, 6};
    int test4[] = {0, 2};

    int tests[][6] = {
        {0, 1, 3, 4},
        {0, 1, 2, 4, 5},
        {1, 2, 3, 4, 5, 6},
        {0, 2}
    };

    int sizes[] = {4, 5, 6, 2};

    for (int i = 0; i < 4; i++)
    {
        int result = missing(tests[i], sizes[i]);
        printf("Test %d: Missing number = %d\n", i + 1, result);
    }

    return 0;
}



