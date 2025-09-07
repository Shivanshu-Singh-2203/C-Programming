#include <stdio.h>

// Function to test
void convertToUppercase(char* str)
{
    while(*str != '\0')
    {
        if(65 <= *str && *str <= 90)
        {
            *str = *str + 32;
        }
        str++;
    }
}

int main() {
    char test1[] = "HELLO WORLD";
    char test2[] = "Test123";
    char test3[] = "already lowercase";
    char test4[] = "MIXED Case 456";

    printf("Before: %s\n", test1);
    convertToUppercase(test1);
    printf("After:  %s\n\n", test1);

    printf("Before: %s\n", test2);
    convertToUppercase(test2);
    printf("After:  %s\n\n", test2);

    printf("Before: %s\n", test3);
    convertToUppercase(test3);
    printf("After:  %s\n\n", test3);

    printf("Before: %s\n", test4);
    convertToUppercase(test4);
    printf("After:  %s\n\n", test4);

    return 0;
}

