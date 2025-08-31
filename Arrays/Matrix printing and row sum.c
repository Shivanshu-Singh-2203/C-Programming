/* Reads n*n matrix and find rows sum */

#include <stdio.h>

void getMatrix(int n, int a[n][n]) {
    for (int i = 0; i < n; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void printRowTotals(int n, int a[n][n]) {
    printf("\nRow totals: ");
    for (int i = 0; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += a[i][j];
        }
        printf("%d ", row_sum);
    }
}

void printColTotals(int n, int a[n][n]) {
    printf("\nColumn totals: ");
    for (int j = 0; j < n; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++) {
            col_sum += a[i][j];
        }
        printf("%d ", col_sum);
    }
}

int main(void) {
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int a[n][n];  // variable-length array (VLA in C99)

    getMatrix(n, a);
    printRowTotals(n, a);
    printColTotals(n, a);

    printf("\n");
    return 0;
}

