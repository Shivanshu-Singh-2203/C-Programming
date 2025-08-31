/* Count Occurences of each digit in the number */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10

void printingArray(int arr[], int size)
{
	for( int i = 0; i < size; i ++ )
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}
int main(void)
{
	int digit;
	int integer_digits[10] = {0,1,2,3,4,5,6,7,8,9};
	int digits_status[N] = {0};
	long n;

	printf("Enter your number: ");
	scanf("%ld", &n);
	while (n > 0)
	{
		digit = n % 10;
		digits_status[digit] += 1;
	
	n /= 10;
	}
	
	printingArray(integer_digits, 10);
	printingArray(digits_status, 10);
	
	return 0;
}

