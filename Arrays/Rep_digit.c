/* Finds which element in the number is repeated. */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10

int main(void)
{
    long n;
    int digit;
    bool flag = false;
    bool digit_seen[N] = {false};

    printf("Enter your number: ");
    scanf("%ld", &n);

    while (n > 0)
    {
        digit = n % 10;

        if (digit_seen[digit])  
        {
            printf("%d ", digit);   // Print the repeated digit
            flag = true;
        }
        else
        {
            digit_seen[digit] = true; // Mark digit as seen
        }

        n /= 10;
    }

    if (!flag)
    {
        printf("No digits are repeated.");
    }

    printf("\n");
    return 0;
}

