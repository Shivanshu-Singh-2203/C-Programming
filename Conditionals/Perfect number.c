#include <stdio.h>

int main()
{
	long a=0, factor_sum = 0;

	scanf("%ld", &a);

	for(  long i = 1; i < a; i++)
		
	{
		if (a%i == 0)
		{
			factor_sum  = factor_sum + i;
		}
	}
	if (factor_sum == a)
	{ printf("Yes");  }
	else 
	{		printf("No");}
	
	return 0;
}

