#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int maxRows, maxCols;
    int rows, cols, chosenRow;
    int notValidSize, notValidRow;
    int i, j, temp;

    printf("\n\n");

    do {
        printf("Define the size of the Matrix.\n\n");

        printf("Enter the number of rows (Max. %d): ", MAX_ROWS);
        scanf("%d", &maxRows);
        
        printf("Enter the number of columns (Max. %d): ", MAX_COLS);
        scanf("%d", &maxCols);

        notValidSize = (maxRows < 1 || maxRows > MAX_ROWS || maxCols < 1 || maxCols > MAX_COLS);

        if(notValidSize)
            printf("Invalid size! Please try again.\n\n");
        
    } while(notValidSize);
    printf("\n");

    printf("Please, enter the elements of the matrix:\n");
    for (rows = 0; rows < maxRows; rows++)
        for (cols = 0; cols < maxCols; cols++) {
            printf("[%d][%d]: ", rows + 1, cols + 1);
            scanf("%d", &matrix[rows][cols]);
        }
    printf("\n");
    
    printf("The matrix is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++)
            printf("%d ", matrix[rows][cols]);
        printf("\n");
    }
    printf("\n");

    do {
        printf("Choose row to sort elements in ascending order (from 1 to %d): ", maxRows);
        scanf("%d", &chosenRow);
        
        chosenRow--;
        notValidRow = (chosenRow > maxRows);

        if (notValidRow)
            printf("Invalid row! Please try again.\n\n");
    } while(notValidRow);

    for (j = 0; j < maxCols; j++) {
        for (cols = 0; cols < maxCols - 1; cols++) {
            if (matrix[chosenRow][cols] > matrix[chosenRow][cols + 1]) {
                temp = matrix[chosenRow][cols];
                matrix[chosenRow][cols] = matrix[chosenRow][cols + 1];
                matrix[chosenRow][cols + 1] = temp;
            }
        }
    }
    
    printf("The new matrix is:\n");
    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++)
            printf("%d ", matrix[rows][cols]);
        printf("\n");
    }
    printf("\n");

    return 0;
}
