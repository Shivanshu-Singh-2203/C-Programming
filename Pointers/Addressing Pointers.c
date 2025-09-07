/* Using the & and * pointer operators */ 

#include <stddef.h>
#include <stdio.h>
#define ARRAY_SIZE 4

int main()
{	int a = 7;
	int *aPtr = &a; /* sets aPtr to be the address of a */ 

	printf("The address of a is %p"
		"\nThe valus of aPtr is %p", &a, aPtr);
	
	int b[] = {10, 20, 30, 40};
	int *bPtr = b; /* create bPtr and point it to array b */ 
	puts("\nArray b printed with:\nArray index notation");

	for(unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		printf("b[%u] = %d\n", i, b[i]);
	}

	puts("\nPointer offfset notation.\nThe pointer is the array name");
	for(unsigned j = 0; j < ARRAY_SIZE; j ++)
	{
		printf("*(b+%u) = %d\n", j, *(b+j));
	}

	puts("\nPointer index Notaion");

	for(unsigned k = 0; k < ARRAY_SIZE; k++)
	{
		printf("bPtr[%u] = %d\n", k , bPtr[k]);
	}

	puts("\nPointer offset notaion");

	for(unsigned offset = 0; offset < ARRAY_SIZE; offset ++)
	{
		printf("*(bPtr + %u) = %d\n", offset, *(bPtr + offset));
	}

	return 0;
}

