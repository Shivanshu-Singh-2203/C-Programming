/* Finding mean, mode and median of an array */ 

#include <stdio.h>
#define SIZE 5

/* function prototypes */ 
void mean(const unsigned int answer[]);
void median(unsigned int answer[]);
void mode(const unsigned int answer[]);
void selectionSort(unsigned int a[]);
void printArray(unsigned const int arr[]);

/* bubbleSort */ 
unsigned int minimum(unsigned int arr[], int index)
{
	unsigned int least = arr[index];
	for(int i = index; i < SIZE; i ++)
	{
		if ( arr[i]  < least)
		{
			least = arr[i];
		}
	}

	return least;
}

void selectionSort(unsigned int arr[])
{
	for(int i = 0; i < SIZE; i ++)
	{
		unsigned int temp = arr[i];


/* finding mean of an array */ 
void mean(const unsigned int answer[])
{
	double sum = 0;
	for(int i = 0; i < SIZE; i ++)
	{
		sum = sum + answer[i];
	}

	printf("Mean : %f \n", sum / SIZE );
} 


int main(void)
{
	unsigned int arr[SIZE] = {1,2,3,4,1};
	printf("%d\n", minimum(arr, 2));
	return 0;
}
