/* implementing strcpy and strncpy */ 

#include <stdio.h>
#include <string.h>
#define LENGHT 25
#define SIZE 15

int main(void)
{
	char string[] = "Happy birthday Shivam" ;
	char first_copy[LENGHT] = "" ; 
	char second_copy[SIZE] = "" ;

	/* copying string to first_copy */ 
	printf("first_copy : %s.\n", strcpy(first_copy, string));

	/* copying first 14 elements to second_copy */
	strncpy(second_copy, string, SIZE-1);
	second_copy[SIZE-1]= '\0';
	printf("second_copy : %s.\n", second_copy);
	return 0;
}

