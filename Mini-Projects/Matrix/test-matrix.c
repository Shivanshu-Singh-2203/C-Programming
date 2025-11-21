#include "matrix.h"

int** allocAndFill(int r, int c, int arr[r][c]) {
    int** mat = malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i++) {
        mat[i] = malloc(sizeof(int) * c);
        for (int j = 0; j < c; j++) {
            mat[i][j] = arr[i][j];
        }
    }
    return mat;
}


int main() {

    // ---------- Test matrices ----------
    int a_arr[2][2] = {
        {1, 2},
        {3, 4}
    };

    int b_arr[2][2] = {
        {5, 6},
        {7, 8}
    };

    int c_arr[3][3] = {
        {1, 2, 3},
        {0, 4, 5},
        {1, 0, 6}
    };

    // Convert to dynamic matrices
    int** A = allocAndFill(2, 2, a_arr);
    int** B = allocAndFill(2, 2, b_arr);
    int** C = allocAndFill(3, 3, c_arr);

    printf("Matrix A:");
    printMatrix(A, 2, 2);

    printf("Matrix B:");
    printMatrix(B, 2, 2);

    printf("Matrix C:");
    printMatrix(C, 3, 3);

    // ---------- Addition ----------
    printf("A + B:");
    int** addRes = add(A, 2, 2, B, 2, 2);
    printMatrix(addRes, 2, 2);

    // ---------- Subtraction ----------
    printf("A - B:");
    int** subRes = sub(A, 2, 2, B, 2, 2);
    printMatrix(subRes, 2, 2);

    // ---------- Multiplication ----------
    printf("A * B:");
    int** mulRes = multiply(A, 2, 2, B, 2, 2);
    printMatrix(mulRes, 2, 2);

    // ---------- Transpose ----------
    printf("Transpose of A:");
    int** tA = transpose(A, 2, 2);
    printMatrix(tA, 2, 2);

    // ---------- Determinant ----------
    printf("det(A) = %d\n", determinant(A, 2, 2));
    printf("det(C) = %d\n", determinant(C, 3, 3));

    // ---------- Submatrix ----------
    printf("\nSubmatrix of C (removing row 0, col 1):");
    int** subC = getSubMatrix(C, 3, 3, 1);
    printMatrix(subC, 2, 2);

    // Free everything
    freeMatrix(A, 2);
    freeMatrix(B, 2);
    freeMatrix(C, 3);
    freeMatrix(addRes, 2);
    freeMatrix(subRes, 2);
    freeMatrix(mulRes, 2);
    freeMatrix(tA, 2);
    freeMatrix(subC, 2);

    return 0;
}

