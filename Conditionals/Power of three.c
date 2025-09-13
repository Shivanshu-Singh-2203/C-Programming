#include <stdio.h>

int main()
{
	int a = 0;

	scanf("%d", &a);

	int current = 1;
	if(a == 0)
	{                        printf("Not power of 3\n");
	}
	while( current < a) 
	{
		if (a%(current) != 0)
		{
			printf("Not power of 3\n");
			break;
		}
		current  = current * 3;
	}
	if (current == a)
	{
		printf("Power of 3\n");
	}
	return 0;
}

