/* Power */ 

#include <stdio.h>

int main()
{
	int a, b, pow, counter;
	printf("Enter a, b: ");
	scanf("%d %d", &a, &b);
	
	pow = 1;
	counter = 0;

	while(counter < b)
	{
		pow = pow* a;
		counter = counter + 1;
	}

	printf("%d\n", pow);
	return  0;
}
