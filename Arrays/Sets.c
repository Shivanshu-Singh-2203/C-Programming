/* Implementation of sets using arrays */ 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MIN(a,b) ((a) > (b) ? (b): (a))
void displaySet(int set[], int size)
{
	printf("{ ");
	for(int i = 0; i < size; i ++)
	{
		i != size - 1 ? printf("%d, ", set[i]) : printf("%d ", set[i]);
	}
	printf("}\n");
}

bool isMember(int set[], int size, int element)
{
	for (int i = 0; i < size; i ++)
	{
		if(set[i] == element)
		{
			return true;
		}
	}	
	return false;
}

int* setUnion(int set1[], int size1, int set2[], int size2, int *resultSize) {
    int maxSize = size1 + size2;
    int *arr = (int*)malloc(maxSize * sizeof(int));
    if (!arr) {
        perror("Memory allocation failed");
        exit(1);
    }

    int k = 0;

    for (int i = 0; i < size1; i++)
        arr[k++] = set1[i];

    for (int i = 0; i < size2; i++) {
        if (!isMember(set1, size1, set2[i])) {
            arr[k++] = set2[i];
        }
    }

    *resultSize = k;
    return arr;
}

int* setIntersection(int set1[], int size1, int set2[], int size2, int* resultsize)
{
	int maxSize= MIN(size1,size2);
	int* arr = (int*)malloc(maxSize* sizeof(int));

	if(!arr)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	int t = 0;

	for(int k = 0; k < size1; k ++)
	{
		if(isMember(set2, size2, set1[k]))
		{
			arr[t++] = set1[k];
		}
	}
	*resultsize = t;
	return arr;
}

bool isSubset(int sub[], int size1, int super[], int size2)
{
	for(int i = 0; i < size1; i ++)
	{
		if(!isMember(super, size2, sub[i]))
		{
			return false;
		}
	}
	return true;
}


int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int sizeA = 4, sizeB = 4;

    printf("Set A: ");
    displaySet(A, sizeA);
    printf("Set B: ");
    displaySet(B, sizeB);

    // --- Union ---
    int sizeU;
    int *U = setUnion(A, sizeA, B, sizeB, &sizeU);
    printf("\nUnion of A and B: ");
    displaySet(U, sizeU);
    free(U);

    // --- Intersection ---
    int sizeI;
    int *I = setIntersection(A, sizeA, B, sizeB, &sizeI);
    printf("Intersection of A and B: ");
    displaySet(I, sizeI);
    free(I);

    // --- Subset check ---
    if (isSubset(A, sizeA, B, sizeB))
        printf("A is a subset of B\n");
    else
        printf("A is NOT a subset of B\n");

    if (isSubset(B, sizeB, A, sizeA))
        printf("B is a subset of A\n");
    else
        printf("B is NOT a subset of A\n");

    // --- Membership check ---
    int element = 3;
    if (isMember(A, sizeA, element))
        printf("%d is a member of A\n", element);
    else
        printf("%d is NOT a member of A\n", element);

    element = 6;
    if (isMember(A, sizeA, element))
        printf("%d is a member of A\n", element);
    else
        printf("%d is NOT a member of A\n", element);

    return 0;
}
