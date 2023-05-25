#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int matrixX[MAX_ROWS][MAX_COLS], matrixY[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];
    int maxRows, maxCols;
    int rows, cols, sameSize;

    printf("Matrix Multiplication.\n\n");

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

    printf("Enter the elements of the first matrix:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            printf("Enter element [%d][%d]: ", rows + 1, cols + 1);
            scanf("%d", &matrixX[rows][cols]);
        }
    }
    printf("\n");

    printf("Enter the elements of the second matrix:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            printf("Enter element [%d][%d]: ", rows + 1, cols + 1);
            scanf("%d", &matrixY[rows][cols]);
        }
    }
    printf("\n");

    printf("The first matrix is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            printf("%d ", matrixX[rows][cols]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("The second matrix is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            printf("%d ", matrixY[rows][cols]);
        }
        printf("\n");
    }
    printf("\n");

    printf("The product of the two matrices is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            result[rows][cols] = 0;
            for (sameSize = 0; sameSize < maxCols; sameSize++)
                result[rows][cols] += matrixX[rows][sameSize] * matrixY[sameSize][cols];
            printf("%d\t", result[rows][cols]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}