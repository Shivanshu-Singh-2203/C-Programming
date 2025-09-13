/* Finding mean, mode and median of an array */ 

#include <stdio.h>
#include <strings.h>
#define SIZE 5

/* function prototypes */
void mean(const unsigned int answer[]);
void median(unsigned int answer[]);
void mode(const unsigned int answer[]);
void selectionSort(unsigned int a[]);
void printArray(const unsigned int arr[]);
void swap(unsigned int *first_number,unsigned int *second_number);
unsigned int minimum(unsigned int arr[], int index);

/* swap function */
void swap(unsigned int *first_number,unsigned int* second_number)
{
    unsigned int temp = *first_number;
    *first_number = *second_number;
    *second_number = temp;
}

/* minimum index */
unsigned int minimum(unsigned int arr[], int index)
{
    unsigned int least = index;
    for(int i = index; i < SIZE; i++)
        if(arr[i] < arr[least])
            least = i;
    return least;
}

/* selection sort */
void selectionSort(unsigned int arr[])
{
    for(int i = 0; i < SIZE - 1; i++)
        swap(&arr[i], &arr[minimum(arr, i)]);
}

/* print array */
void printArray(const unsigned int arr[])
{
    for(int i = 0; i < SIZE; i++)
        printf("%u ", arr[i]);
    printf("\n");
}

/* mean */
void mean(const unsigned int answer[])
{
    double sum = 0;
    for(int i = 0; i < SIZE; i++)
        sum += answer[i];
    printf("Mean : %f\n", sum / SIZE);
}

/* median */
void median(unsigned int answer[])
{
    selectionSort(answer);
    double med;
    if(SIZE % 2 == 0)
        med = (answer[SIZE/2 - 1] + answer[SIZE/2]) / 2.0;
    else
        med = answer[SIZE/2];
    printf("Median : %f\n", med);
}

/* mode */
void mode(const unsigned int arr[])
{
    unsigned int maxValue = arr[0];
    unsigned int maxCount = 0;

    for(int i = 0; i < SIZE; i++) {
        unsigned int count = 0;
        for(int j = 0; j < SIZE; j++)
            if(arr[j] == arr[i]) count++;
        if(count > maxCount) {
            maxCount = count;
            maxValue = arr[i];
        }
    }

    if(maxCount > 1)
        printf("Mode : %u (appears %u times)\n", maxValue, maxCount);
    else
        printf("No mode\n");
}

/* main test driver */
int main(void)
{
    unsigned int arr[SIZE] = {1, 2, 3, 4, 1};

    printf("Original array: ");
    printArray(arr);

    mean(arr);
    median(arr);
    mode(arr);

    selectionSort(arr);
    printf("Sorted array: ");
    printArray(arr);

    return 0;
}

