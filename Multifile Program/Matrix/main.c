#include <stdio.h>
#include "matrix.h"

int main(void) {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int result[2][2];

    printf("Matrix A:\n"); 
    print_matrix(A, 2, 2);

    printf("Matrix B:\n"); 
    print_matrix(B, 2, 2);

    add_matrix(A, B, result, 2, 2);
    printf("A + B:\n"); 
    print_matrix(result, 2, 2);

    multiply_matrix(A, B, result, 2, 2, 2);
    printf("A * B:\n"); 
    print_matrix(result, 2, 2);

    return 0;
}

