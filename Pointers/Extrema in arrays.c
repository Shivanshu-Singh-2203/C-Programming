/* Finding extremas */ 

#include <stdio.h>
#include <limits.h>

/* Function to find maximum using pointers */
double find_max(const double* arr, int n)
{
    const double* end = arr + n;
    double max = *arr;

    while (arr < end)
    {
        if (*arr > max)
            max = *arr;
        arr++;
    }

    return max;
}

/* Function to find minimum using pointers */
double find_min(const double* arr, int n)
{
    const double* end = arr + n;
    double min = *arr;

    while (arr < end)
    {
        if (*arr < min)
            min = *arr;
        arr++;
    }

    return min;
}

/* Function to find second maximum using pointers */
double find_second_max(const double* arr, int n)
{
    double max1 = -__DBL_MAX__;   // negative infinity
    double max2 = -__DBL_MAX__;   // second largest

    const double* end = arr + n;

    while (arr < end)
    {
        if (*arr > max1)
        {
            max2 = max1;
            max1 = *arr;
        }
        else if (*arr > max2 && *arr < max1)
        {
            max2 = *arr;
        }
        arr++;
    }

    return max2;
}

/* Function to find second minimum using pointers */
double find_second_min(const double* arr, int n)
{
    double min1 = __DBL_MAX__;    
    double min2 = __DBL_MAX__;   

    const double* end = arr + n;

    while (arr < end)
    {
        if (*arr < min1)
        {
            min2 = min1;
            min1 = *arr;
        }
        else if (*arr < min2 && *arr > min1)
        {
            min2 = *arr;
        }
        arr++;
    }

    return min2;
}

int main(void)
{
    double arr[] = {12.5, 7.3, 19.8, 7.3, 5.1, 19.8, 15.0};
    int n = sizeof(arr) / sizeof(arr[0]);

    double max_val = find_max(arr, n);
    double min_val = find_min(arr, n);
    double second_max_val = find_second_max(arr, n);
    double second_min_val = find_second_min(arr, n);

    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    printf("Maximum: %.2f\n", max_val);
    printf("Minimum: %.2f\n", min_val);

    if (second_max_val == -__DBL_MAX__)
        printf("Second Maximum: Not found (all elements equal)\n");
    else
        printf("Second Maximum: %.2f\n", second_max_val);

    if (second_min_val == __DBL_MAX__)
        printf("Second Minimum: Not found (all elements equal)\n");
    else
        printf("Second Minimum: %.2f\n", second_min_val);

    return 0;
}

