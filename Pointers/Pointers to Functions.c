/* Pointers to functions */ 

#include <stddef.h>
#include <stdio.h>
#define SIZE 10

int ascending(int a, int b)
{
	return a < b;
}

int descending(int a, int b)
{
	return a > b;
}

void swap(int *element1, int* element2)
{
	int temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

void bubble(int arr[], size_t size, int(*compare)(int a, int b))
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - 1; j ++)
		{
			if((*compare)(arr[j], arr[j+1]))
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}


int main(void)
{
    int order;
    size_t counter;

    int a[SIZE] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    printf("%s", "Enter 1 to sort in ascending order,\n"
                 "Enter 2 to sort in descending order: ");
    scanf("%d", &order);

    puts("\nData items in original order");
    for (counter = 0; counter < SIZE; ++counter) {
        printf("%5d", a[counter]);
    }

    if (order == 1) {
        bubble(a, SIZE, ascending);
        puts("\nData items in ascending order");
    } else {
        bubble(a, SIZE, descending);
        puts("\nData items in descending order");
    }

    for (counter = 0; counter < SIZE; ++counter) {
        printf("%5d", a[counter]);
    }

    puts("\n");
    return 0;
}
