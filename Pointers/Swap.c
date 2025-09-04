#include <stdio.h>

void swap(int *pointer1, int *pointer2) {
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

int main(void) {
    int a = 10, b = 5;
    int *pointer1 = &a;
    int *pointer2 = &b;

    printf("Before Swapping:\n");
    printf("a : %d\n", a);
    printf("b : %d\n", b);

    swap(pointer1, pointer2);

    printf("After Swapping:\n");
    printf("a : %d\n", a);
    printf("b : %d\n", b);

    return 0;
}

