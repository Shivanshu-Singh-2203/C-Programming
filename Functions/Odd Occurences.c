/* Find the Number Occurring Odd Number of Times */

#include <stdio.h>

int odd(int arr[], int size)
{
	int res = 0;
	for(int i = 0; i < size; i ++)
	{
		res = res ^ arr[i];
	}
	
	return res;
}

int main()
{
    int test1[] = {1, 2, 3, 2, 3, 1, 3};
    int test2[] = {4, 4, 5, 5, 6};
    int test3[] = {7};
    int test4[] = {10, 10, 20, 20, 30, 30, 40};

    int tests[][7] = {
        {1, 2, 3, 2, 3, 1, 3},
        {4, 4, 5, 5, 6},
        {7},
        {10, 10, 20, 20, 30, 30, 40}
    };

    int sizes[] = {7, 5, 1, 7};

    for (int i = 0; i < 4; i++)
    {
        int result = odd(tests[i], sizes[i]);
        printf("Test %d: Number occurring odd times = %d\n", i + 1, result);
    }

    return 0;
}

