/* Prints characters using const pointer */ 
#include <stdio.h>

void printCharacters(const char* string)
{
	printf("Characters in the string are : ");
	while(*string != '\0')
	{
		printf("%c ", *string);
		string ++;
	}
}

int main() {
    const char str1[] = "Hello";
    const char str2[] = "123 ABC xyz!";
    const char str3[] = "";

    printCharacters(str1);  // expected: H e l l o 
    printf("\n");

    printCharacters(str2);  // expected: 1 2 3   A B C   x y z ! 
    printf("\n");

    printCharacters(str3);  // expected: (no output)
    printf("\n");

    return 0;
}

