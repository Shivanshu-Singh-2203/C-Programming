/* Factorial Number */

#include <stdio.h>

int factorial(int a)
{
    if (a < 0) {
        printf("Factorial not defined for negative numbers.\n");
        return -1; 
    }

    if (a == 0) 
        return 1;

    return a * factorial(a - 1);
}

int main()
{
    int test_cases[] = {0, 1, 5, 7, -3, 12, 13};
    int n_tests = sizeof(test_cases)/sizeof(test_cases[0]);

    for (int i = 0; i < n_tests; i++) {
        int n = test_cases[i];
        int result = factorial(n);
        if (result != -1)
            printf("factorial(%d) = %d\n", n, result);
    }

    return 0;
}

