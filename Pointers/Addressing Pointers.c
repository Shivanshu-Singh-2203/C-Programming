/* Using the & and * pointer operators */ 

#include <stdio.h>

int main()
{	int a = 7;
	int *aPtr = &a; /* sets aPtr to be the address of a */ 

	printf("The address of a is %p"
		"\nThe valus of aPtr is %p", &a, aPtr);

	return 0;
}

