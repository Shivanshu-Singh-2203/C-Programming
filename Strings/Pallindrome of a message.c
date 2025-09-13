/* checks if the message is a pallindrome or not */ 

#include <stdio.h>
#include <ctype.h>

#define SIZE 50



int main(void)
{
	char array[SIZE];
	printf("Enter a message : ");
	fgets(array, 50, stdin);
	char* stringPointer;
	stringPointer = array;

	while(*(stringPointer + 1) != '\0')
	{
		stringPointer ++;
	}

	stringPointer --;
	
	char*  headPointer = array;
	int flag = 1;
	while(headPointer < stringPointer)
	{
		if(tolower(*headPointer) != tolower(*stringPointer))
		{
			printf("%d\n",tolower(*stringPointer));
			printf("Not a pallindrome\n");
			flag = 0;
			break;
		}
		headPointer ++;
		stringPointer --;
	}

	if(flag)
	{
		printf("Pallindrome\n");
	}
	return 0;
}
