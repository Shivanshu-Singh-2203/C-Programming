#include <stdio.h>
#include <strings.h>
#define  MAX(A,B) ((A) > (B) ? (A) : (B))
#define  MIN(A,B) ((A) < (B) ? (A) : (B))

int minima(int* ptr, int size, int starting_index)
{
	int min = *ptr;
	int current = 0;
	for (int i = index; i < size; i ++) 
	{
		if(min > *ptr + size)
		{
			current = i;
			min = *ptr + i;
		}
	}
	return current;
}

void selectionSort(int * ptr, int size)
{	
	int minimumIndex;
	for(int i = 0; i < size; i ++)
	{
		minimumIndex = minima(ptr,size,i);
		int temp = *ptr + minimumIndex;
		*(ptr + minimumIndex) = *(ptr + i);
		*(ptr + i) = temp;
	}

	for(int i = 0;i < size; i ++)
	{
		printf("%d ", *ptr + i);
	}
	printf("\n");
}

	int main(void)
{
    int arr1[] = {5, 2, 8, 1, 3};
    int arr2[] = {10, 9, 8, 7, 6};
    int arr3[] = {42};

    printf("Test 1:\n");
    selectionSort(arr1, 5);

    printf("Test 2:\n");
    selectionSort(arr2, 5);

    printf("Test 3:\n");
    selectionSort(arr3, 1);

    return 0;
}

