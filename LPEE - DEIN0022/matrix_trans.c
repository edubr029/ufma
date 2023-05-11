#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int maxRows, maxCols;
    int rows, cols;

    printf("Transposted Matrix.\n\n");

    do {
        printf("Enter the number of rows (Max. %d): ", MAX_ROWS);
        scanf("%d", &maxRows);

        printf("Enter the number of columns (Max. %d): ", MAX_COLS);
        scanf("%d", &maxCols);

        if (maxRows <= 0 || maxRows > MAX_ROWS || maxCols <= 0 || maxCols > MAX_COLS) {
            printf("Invalid input. Please try again.\n");
        }
    } while (maxRows <= 0 || maxRows > MAX_ROWS || maxCols <= 0 || maxCols > MAX_COLS);
    printf("\n");

    printf("Enter the elements of the matrix:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            printf("Enter element [%d][%d]: ", rows + 1, cols + 1);
            scanf("%d", &matrix[rows][cols]);
        }
    }
    printf("\n");

    printf("The matrix is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            printf("%d ", matrix[rows][cols]);
        }
        printf("\n");
    }
    printf("\n");

    printf("The transposed matrix is:\n");
    for (cols = 0; cols < maxCols; cols++) {
        for (rows = 0; rows < maxRows; rows++) {
            printf("%d ", matrix[rows][cols]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}