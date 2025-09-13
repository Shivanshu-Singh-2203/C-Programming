/* demonstrating sscanf */ 

/* like scanf but takes string */ 

#include <math.h>
#include <stdio.h>

int main(void)
{
	char s[] = "31298 87.375";
	int x = 0;
	double y = 0;

	sscanf(s, "%d%lf", &x, &y);
	puts("The values stored in the x and y are : ");
	printf("integer:%6d\ndouble:%8.3f\n", x, y);
	return 0;

}
