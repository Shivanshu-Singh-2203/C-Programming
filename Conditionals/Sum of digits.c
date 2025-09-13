#include <stdio.h>

int main()
{
	int a = 0;
	int sum = 0;

	scanf("%d", &a);

	int digi = 0;
	while(a > 0)
	{
		digi = a % 10;
		sum = sum + digi;
		a /= 10;
	}
	printf("%d\n", sum);
	return 0;
}

