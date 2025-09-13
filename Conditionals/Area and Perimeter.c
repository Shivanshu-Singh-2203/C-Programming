#include <stdio.h>

int main()
{
	float a=0, b=0;
	float area, perimeter;

	scanf("%f %f", &a, &b);

	if ((a > 0) && (b > 0))
	{	
		area = a * b;
		perimeter = 2*(a + b);
                printf("%.3f %.3f",area, perimeter);                                                  
	}
	else {
		printf("Invalid Input");
	}
	return 0;
}

