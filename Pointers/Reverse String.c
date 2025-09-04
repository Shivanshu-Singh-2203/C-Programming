#include <stdio.h>

void swap(char *string, int src, int destination) {
    char *p1 = string + src;        // pointer to src character
    char *p2 = string + destination; // pointer to destination character

    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    char str[] = "hello";
    printf("Before: %s\n", str);

    swap(str, 1, 3);  // swap 'e' (index 1) and 'l' (index 3)

    printf("After: %s\n", str);
    return 0;
}

