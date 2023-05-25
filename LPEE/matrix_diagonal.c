#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int maxRows, maxCols;
    int rows, cols;
    int i, j, temp;

    printf("Diagonal Matrix.\n\n");

    //getting the number of rows and columns of the matrix
    
    do{
        printf("Enter the number of rows (Max. %d): ", MAX_ROWS);
        scanf("%d", &maxRows);

        printf("Enter the number of columns (Max. %d): ", MAX_COLS);
        scanf("%d", &maxCols);

        if (maxRows <= 0 || maxRows > MAX_ROWS || maxCols <= 0 || maxCols > MAX_COLS) {
            printf("Invalid input. Please try again.\n");
        }
    } while (maxRows <= 0 || maxRows > MAX_ROWS || maxCols <= 0 || maxCols > MAX_COLS);
    printf("\n");

    //getting the elements of the matrix

    printf("Enter the elements of the matrix:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            printf("Enter element [%d][%d]: ", rows + 1, cols + 1);
            scanf("%d", &matrix[rows][cols]);
        }
    }
    printf("\n");

    //printing the elements of the matrix

    printf("The matrix is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            printf("%d ", matrix[rows][cols]);
        }
        printf("\n");
    }
    printf("\n");

    //showing the diagonal elements of the matrix

    printf("The diagonal matrix is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            if (rows == cols) {
                printf("%d ", matrix[rows][cols]);
            }
        }
    }
    printf("\n");
    
    //using the bubble sort to sort the diagonal elements in ascending order

    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            if (rows == cols) {
                for (i = 0; i < maxRows; i++) {
                    for (j = 0; j < maxCols; j++) {
                        if (i == j) {
                            if (matrix[rows][cols] < matrix[i][j]) {
                                temp = matrix[rows][cols];
                                matrix[rows][cols] = matrix[i][j];
                                matrix[i][j] = temp;
                            }
                        }
                    }
                }
            }
        }
    }

    //printing the diagonal elements in ascending order

    printf("The diagonal matrix in numeral ascending order is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            if (rows == cols) {
                printf("%d ", matrix[rows][cols]);
            }
        }
    }
    printf("\n");

    //using the bubble sort to sort the diagonal elements in descending order

    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            if (rows == cols) {
                for (i = 0; i < maxRows; i++) {
                    for (j = 0; j < maxCols; j++) {
                        if (i == j) {
                            if (matrix[rows][cols] > matrix[i][j]) {
                                temp = matrix[rows][cols];
                                matrix[rows][cols] = matrix[i][j];
                                matrix[i][j] = temp;
                            }
                        }
                    }
                }
            }
        }
    }

    //printing the diagonal elements in descending order

    printf("The diagonal matrix in numeral descending order is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            if (rows == cols) {
                printf("%d ", matrix[rows][cols]);
            }
        }
    }
    printf("\n");
    
    return 0;
}