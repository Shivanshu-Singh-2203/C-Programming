#include <stdio.h>

int main()
{
	int a=0, b=0, c=0;

	scanf("%d %d %d", &a, &b, &c);

	if (b*b < 4*a*c)
	{
		printf("Complex");
	}
	else{
		printf("Real");
	}

	return 0;
}

