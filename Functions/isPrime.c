/* Tests whether a number is a prime. */

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    if (n <= 1) 
        return false;   // 0 and 1 are not prime
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;   // divisible → not prime
    }
    return true; // if no divisor found, it's prime
}

int main(void)
{
    int nums[] = { -5, 0, 1, 2, 3, 4, 5, 16, 17, 19, 20, 97, 100 };
    int size = sizeof(nums)/sizeof(nums[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%d → %s\n", nums[i], isPrime(nums[i]) ? "Prime" : "Not Prime");
    }

    return 0;
}

