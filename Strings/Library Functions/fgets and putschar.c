/* Demonstrate fgets and putschar */ 

#include <stdio.h>
#define SIZE  80

void reverse(const char* const ptr);

int main(void)
{

	/* defining string sentence as an array of strings */
	char sentence[SIZE] = "" ;

	/* like printf */ 
	puts("Enter a line of text : ");

	/* gets the string inserted in stdin with length SIZE */ 
	fgets(sentence,SIZE,stdin);

	printf("\n%s", "The line printed backward is : ");
	reverse(sentence);
	puts("");

	return 0;
}

void reverse(const char* const ptr)
{
	if('\0' == ptr[0])
	{
		return;
	}

	/* recursive step */ 
	reverse(&ptr[1]);
	putchar(ptr[0]);
	return;	
}
