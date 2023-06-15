#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_ROWS 1024
#define MAX_COLS 1024

void defineMatrixSize(int *maxRows, int *maxCols) {
    int def_Rows, def_Cols;
    int notValidSize;

    do {
        printf("Entre com o número de linhas (Max. %d): ", MAX_ROWS);
        scanf("%d", &def_Rows);

        printf("Entre com o número de colunas (Max. %d): ", MAX_COLS);
        scanf("%d", &def_Cols);

        notValidSize = (def_Rows > MAX_ROWS || def_Cols > MAX_COLS || def_Rows < 1 || def_Cols < 1);

        if(notValidSize)
            printf("Valores inválidos! Tente novamente.\n");
    } while(notValidSize);

    *maxRows = def_Rows;
    *maxCols = def_Cols;
}

void clearMatrix(char mtx[MAX_ROWS][MAX_COLS]) {
    int rows, cols;

    for(rows = 0; rows < MAX_ROWS; rows++)
        for(cols = 0; cols < MAX_COLS; cols++)
            mtx[rows][cols] = ' ';
}
void defineMatrixElements(char mtx[MAX_ROWS][MAX_COLS], int maxRows, int maxCols) {
    int rows, cols;

    clearMatrix(mtx);

    for (rows = 0; rows < maxRows; rows++) {
        for (cols = 0; cols < maxCols; cols++) {
            printf("[%d][%d]: ", rows + 1, cols + 1);
            scanf("%s", &mtx[rows][cols]);
        }
    }
    printf("\n");
}

void showMatrix(char mtx[MAX_ROWS][MAX_COLS], int maxRows, int maxCols) {
    int rows, cols;

    for(rows = 0; rows < maxRows; rows++) {
        for(cols = 0; cols < maxCols; cols++)
            printf("%c ", mtx[rows][cols]);
        printf("\n");
    }
}

int countMatrixPattern(char mtx[MAX_ROWS][MAX_COLS], int maxRows, int maxCols) {
    int rows, cols;
    int count = 0, i, j;
    
    for(rows = 0; rows < maxRows; rows++)
        for(cols = 0; cols < maxCols; cols++) {
            i = rows;
            j = cols;
            if(mtx[i][j] == '*') {
                i++;
                if(mtx[i][j] == '*') {
                    j++;
                    if(mtx[i][j] == '*');
                        count++;
                }
            }
        }

    return count;
}

void showHowManyPattern(int count) {
    printf("a quantidades de L de * é de: %d", count);
}

int main() {
    char mtx[MAX_ROWS][MAX_COLS];
    int maxRows, maxCols;

    printf("Defina a dimensão da matriz. \n");
    defineMatrixSize(&maxRows, &maxCols);

    printf("Entre com os elementos da matriz. \n");
    defineMatrixElements(mtx, maxRows, maxCols);

    printf("A matriz definida foi: \n");
    showMatrix(mtx, maxRows, maxCols);

    showHowManyPattern(countMatrixPattern(mtx, maxRows, maxCols));

    return 0;   
}