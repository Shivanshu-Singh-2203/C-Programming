#include "matrix.h"


int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    int** A = initialize(r1, c1);
    int** B = initialize(r2, c2);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    printf("\nMatrix A:\n");
    printMatrix(A, r1, c1);

    printf("\nMatrix B:\n");
    printMatrix(B, r2, c2);

    // ADD
    if (r1 == r2 && c1 == c2) {
        printf("\nA + B:\n");
        int** addResult = add(A, r1, c1, B, r2, c2);
        printMatrix(addResult, r1, c1);
        freeMatrix(addResult, r1);
    }

    // SUB
    if (r1 == r2 && c1 == c2) {
        printf("\nA - B:\n");
        int** subResult = sub(A, r1, c1, B, r2, c2);
        printMatrix(subResult, r1, c1);
        freeMatrix(subResult, r1);
    }

    // MULTIPLY
    if (c1 == r2) {
        printf("\nA * B:\n");
        int** mul = multiply(A, r1, c1, B, r2, c2);
        printMatrix(mul, r1, c2);
        freeMatrix(mul, r1);
    }

    // TRANSPOSE A
    printf("\nTranspose of A:\n");
    int** tA = transpose(A, r1, c1);
    printMatrix(tA, r1, c1);
    freeMatrix(tA, r1);

    // DETERMINANT
    if (r1 == c1) {
        printf("\nDeterminant of A: %d\n", determinant(A, r1, c1));
    }

    if (r2 == c2) {
        printf("Determinant of B: %d\n", determinant(B, r2, c2));
    }

    freeMatrix(A, r1);
    freeMatrix(B, r2);

    return 0;
}
