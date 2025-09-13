/* Inner Product */

#include <stdio.h>

double inner_product(const double* vector1, const double* vector2, int n)
{
    double product = 0.0;

    const double* end = vector1 + n;

    while (vector1 < end)
    {
        product += (*vector1) * (*vector2);
        vector1++;
        vector2++;
    }

    return product;
}

int main(void)
{
    double a[] = {1.0, 2.0, 3.0, 4.0};
    double b[] = {2.0, 3.0, 4.0, 5.0};
    int n = 4;

    double result = inner_product(a, b, n);

    printf("Inner product = %.2f\n", result);

    return 0;
}

