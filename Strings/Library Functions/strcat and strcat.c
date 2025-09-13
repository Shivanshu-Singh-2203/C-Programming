/* demonstrates the function of strcat and strncat */ 

#include <stdio.h>
#include <string.h>

int main(void)
{
	char first_string[50] = "radheshyam";
	char second_string[50] = "Siyaram";
	char third_string[50] = "sitaram";

	/* using strcat */ 
	/* concatnating second_string to first_string */ 
	printf("%s\n", strcat(first_string, second_string));
	
	/* concatnating second_string to first_string */
	printf("%s\n", strcat(first_string, third_string));

	/* using strncat */ 
	/* concatnating first 4 letters third_string to second_string */ 
	printf("%s\n", strncat(second_string, third_string, 4));
	
	return 0;
}
