/* Find sum of elements in the row. */

#include <stdio.h> 

int sum(int arr[], int size)
{
	int sum = 0;
	for(int i = 0; i < size ; i ++ )
	{
		sum = sum + arr[i];
	}
	
	return sum;
}

int main()
{
    int arr[] = { 12, 3, 4, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of given array is %d", sum(arr, n));
    return 0;
}

