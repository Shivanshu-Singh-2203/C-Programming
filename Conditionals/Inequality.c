#include <stdio.h>

int main()
{
	int a=0, b=0;

	scanf("%d %d", &a, &b);

	if (a == b)
	{
		printf("a = b");
	}
	else if (a > b )
	{
		printf("a > b");
	}
	else 
	{
		printf("a < b");
	}
	return 0;
}

