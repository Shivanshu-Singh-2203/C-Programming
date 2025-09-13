#include <stdio.h>

int main()
{
	int a=0;

	scanf("%d", &a);

	if (a % 17 == 0)
	{
		printf("Divisible");
	}
	else if (a % 17 != 0) 
	{
		printf("Not divisible\n");
	}	
	
	return 0;
}

