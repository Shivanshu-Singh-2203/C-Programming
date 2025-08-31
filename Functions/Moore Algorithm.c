/* Moore Algorithm */

#include <stdio.h>

int majorityElement(int arr[], int size)
{
    int candidate = -1;
    int vote = 0;  // initialize vote
    int ans = -1;

    for (int i = 0; i < size; i++)
    {
        if (vote == 0)
        {
            candidate = arr[i];
            vote = 1;
        }
        else if (arr[i] == candidate)
        {
            vote++;
        }
        else
        {
            vote--;
        }
    }

    int count = 0;  // initialize count
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == candidate)
            count++;
    }

    if (count > size / 2)
        ans = candidate;

    return ans;
}


int main()
{
    int arr1[] = {3, 3, 4, 2, 3};
    int arr2[] = {1, 2, 3, 4};
    int arr3[] = {2, 2, 1, 1, 2};
    int arr4[] = {5, 5, 5, 5, 5, 1, 2};

    int tests[][7] = {
        {3, 3, 4, 2, 3},
        {1, 2, 3, 4},
        {2, 2, 1, 1, 2},
        {5, 5, 5, 5, 5, 1, 2}
    };

    int sizes[] = {5, 4, 5, 7};

    for (int i = 0; i < 4; i++)
    {
        int result = majorityElement(tests[i], sizes[i]);
        if (result != -1)
            printf("Test %d: Majority element = %d\n", i + 1, result);
        else
            printf("Test %d: No majority element\n", i + 1);
    }

    return 0;
}

