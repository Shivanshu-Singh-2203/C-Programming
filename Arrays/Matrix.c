/* Matrix Operations */
#include <stdio.h>

void inputMatrix(int rows, int cols, int mat[rows][cols]) {
    printf("Enter elements of %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int mat[rows][cols]) {
    printf("Printing Matrix ...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

void add(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2]) {
    if (r1 == r2 && c1 == c2) {
        printf("Adding Matrices ...\n");
        int res[r1][c1];
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                res[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        printMatrix(r1, c1, res);
    } else {
        printf("Dimension mismatch.\n");
    }
}

void subtract(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2]) {
    if (r1 == r2 && c1 == c2) {
        printf("Subtracting Matrices ...\n");
        int res[r1][c1];
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                res[i][j] = mat1[i][j] - mat2[i][j];
            }
        }
        printMatrix(r1, c1, res);
    } else {
        printf("Dimension mismatch.\n");
    }
}

void multiply(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2]) {
    if (c1 == r2) {
        printf("Multiplying Matrices ...\n");
        int res[r1][c2];
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                res[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    res[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        printMatrix(r1, c2, res);
    } else {
        printf("Dimension mismatch for multiplication.\n");
    }
}

void transpose(int rows, int cols, int mat[rows][cols]) {
    printf("Transpose:\n");
    int res[cols][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[j][i] = mat[i][j];
        }
    }
    printMatrix(cols, rows, res);
}

int determinant(int n, int mat[n][n]) {
    if (n == 1)
        return mat[0][0];
    if (n == 2)
        return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

    int det = 0;
    int submat[n-1][n-1];

    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }

        int sign = (x % 2 == 0) ? 1 : -1;
        det += sign * mat[0][x] * determinant(n-1, submat);
    }
    return det;
}

int main() {
    int mat1[2][2] = {{1, 2}, {3, 4}};
    int mat2[2][2] = {{5, 6}, {7, 8}};

    printf("Matrix 1:\n");
    printMatrix(2, 2, mat1);
    printf("Matrix 2:\n");
    printMatrix(2, 2, mat2);

    add(2, 2, mat1, 2, 2, mat2);
    subtract(2, 2, mat1, 2, 2, mat2);
    multiply(2, 2, mat1, 2, 2, mat2);
    transpose(2, 2, mat1);

    printf("Determinant of Matrix 1 = %d\n", determinant(2, mat1));
    printf("Determinant of Matrix 2 = %d\n", determinant(2, mat2));

    printf("\n---\n");

    int mat3[3][2] = {{1, 0}, {0, 1}, {2, 2}};
    int mat4[3][2] = {{2, 2}, {1, 0}, {3, 3}};

    printf("Matrix 3:\n");
    printMatrix(3, 2, mat3);
    printf("Matrix 4:\n");
    printMatrix(3, 2, mat4);

    add(3, 2, mat3, 3, 2, mat4);
    subtract(3, 2, mat3, 3, 2, mat4);

    printf("\n---\n");

    int mat5[2][3] = {{1, 2, 3}, {4, 5, 6}};
    add(2, 2, mat1, 2, 3, mat5); // mismatch check
    multiply(2, 2, mat1, 2, 3, mat5); // valid

    printf("\n---\n");

    int mat6[3][3] = {{1, 2, 3}, {0, 4, 5}, {1, 0, 6}};
    printf("Matrix 6:\n");
    printMatrix(3, 3, mat6);
    printf("Determinant of Matrix 6 = %d\n", determinant(3, mat6));

    return 0;
}

