#include <stdio.h>

int main()
{
	int a=0, b=0 ;
	char op ;
	int result;

	//Get two integers and operation from the user
	scanf("%d %d %c", &a, &b, &op);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	if(op == '+')
	{
		result = a + b;
	}
	
	else if(op == '-')
	{
		result = a - b;
	}

	else if (op == '*')
	{
		result = a * b;
	}

	else
	{
		result = a / b;
	}	
	
	//Do not add/modify anything below this line
	//Print the maximum value
	printf("%d\n", result);
	return 0;
}

