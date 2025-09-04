#include <stdio.h>
#include <math.h>

#define  MAX(A,B) ((A) > (B) ? (A) : (B))
#define  MIN(A,B) ((A) < (B) ? (A) : (B))

void findExtrema(int* ptr, int size)
{
	int max = *ptr;
	int min = *ptr;

	for(int i = 0; i < size; i ++)
	{
		max = MAX(max, *ptr + i);
		min = MIN(min, *ptr + i);
	}

	printf("The maximum and minimum value is %d and %d", max , min);

}


int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {-10, 0, 20, -5, 15};
    int arr3[] = {100};

    printf("Test 1:\n");
    findExtrema(arr1, 5);

    printf("Test 2:\n");
    findExtrema(arr2, 5);

    printf("Test 3:\n");
    findExtrema(arr3, 1);

    return 0;
}
