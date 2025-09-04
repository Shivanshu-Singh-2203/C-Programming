#include <stdio.h>

int length(char str[])
{
    char* temp = str;
    int length = 0;
    while (*temp != '\0')
    {
        temp++;
        length++;
    }
    return length ;
}

int main(void)
{
    char str1[] = "Hello";
    char str2[] = "C programming";
    char str3[] = "";
    char str4[] = "Test123";

    printf("String: \"%s\" | Reported length: %d\n", str1, length(str1));
    printf("String: \"%s\" | Reported length: %d\n", str2, length(str2));
    printf("String: \"%s\" | Reported length: %d\n", str3, length(str3));
    printf("String: \"%s\" | Reported length: %d\n", str4, length(str4));

    return 0;
}

