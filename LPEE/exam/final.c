#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void clearMatrix(int mtx[MAX_ROWS][MAX_COLS]) {
    int rows, cols;

    for(rows = 0; rows < MAX_ROWS; rows++)
        for(cols = 0; cols < MAX_COLS; cols++)
            mtx[rows][cols] = 0;
}

void defineMatrixSize(int *maxSize) {
    int def_rows, def_cols;
    int notValidSize;

    do {
        printf("Entre com o número de linhas da matriz (Max. %d): ", MAX_ROWS);
        scanf(" %d", &def_rows);

        printf("Entre com o número de colunas da matriz (Max. %d): ", MAX_COLS);
        scanf(" %d", &def_cols);

        notValidSize = (def_rows > MAX_ROWS || def_rows < 1 || def_cols > MAX_COLS || def_cols < 1);

        if(notValidSize)
            printf("Valores inválidos! Tente novamente.\n");
    } while(notValidSize);

    maxSize[0] = def_rows;
    maxSize[1] = def_cols;
}

void defineMatrixElements(int mtx[MAX_ROWS][MAX_COLS], int *maxSize) {
    int rows, cols;

    clearMatrix(mtx);

    for(rows = 0; rows < maxSize[0]; rows++) {
        for(cols = 0; cols < maxSize[1]; cols++) {
            printf("[%d][%d]: ", rows + 1, cols + 1);
            scanf(" %d", &mtx[rows][cols]);
        }
    }
    printf("\n");
}

void matrixSqr(int mtx[MAX_ROWS][MAX_COLS], int mtxSqr[MAX_ROWS][MAX_COLS], int *maxSize) {
    int rows, cols, sameSize;

    clearMatrix(mtxSqr);

    for(rows = 0; rows < maxSize[0]; rows++) {
        for(cols = 0; cols < maxSize[1]; cols++) {
            mtxSqr[rows][cols] = 0;
            for(sameSize = 0; sameSize < maxSize[0]; sameSize++)
                mtxSqr[rows][cols] += mtx[rows][sameSize] * mtx[sameSize][cols];
        }
    }
}

void matrixTrans(int mtx[MAX_ROWS][MAX_COLS], int mtxTrans[MAX_ROWS][MAX_COLS], int *maxSize) {
    int rows, cols;

    clearMatrix(mtxTrans);

    for(cols = 0; cols < maxSize[1]; cols++)
        for(rows = 0; rows < maxSize[0]; rows++)
            mtxTrans[cols][rows] = mtx[rows][cols];
}

void matrixMultiplication(int mtxX[MAX_ROWS][MAX_COLS], int mtxY[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int *maxSize) {
    int rows, cols, sameSize;

    clearMatrix(result);

    for(rows = 0; rows < maxSize[0]; rows++) {
        for(cols = 0; cols < maxSize[1]; cols++) {
            result[rows][cols] = 0;
            for(sameSize = 0; sameSize < maxSize[1]; sameSize++)
                result[rows][cols] += mtxX[rows][sameSize] * mtxY[sameSize][cols];
        }
    }
}

void printMatrix(int mtx[MAX_ROWS][MAX_COLS], int *maxSize) {
    int rows, cols;
    for(rows = 0; rows < maxSize[0]; rows++) {
        for(cols = 0; cols < maxSize[1]; cols++)
            printf("%d ", mtx[rows][cols]);
        printf("\n");
    }
    printf("\n");
}

void printMatrixTrans(int mtx[MAX_ROWS][MAX_COLS], int *maxSize) {
    int rows, cols;
    
    for(cols = 0; cols < maxSize[1]; cols++) {      
        for(rows = 0; rows < maxSize[0]; rows++) 
            printf("%d ", mtx[rows][cols]);
        printf("\n");
    }
    printf("\n");
}

void mtxSqrTrans(int mtx[MAX_ROWS][MAX_COLS], int *maxSize) {
    int mtxTrans[MAX_ROWS][MAX_COLS];
    int mtxSqr[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];
    
    matrixSqr(mtx, mtxSqr, maxSize);
    printf("MTX SQR:\n");
    printMatrix(mtxSqr, maxSize);
    
    matrixTrans(mtx, mtxTrans, maxSize);
    printf("MTX TRANS:\n");
    printMatrixTrans(mtxTrans, maxSize);

    int rows, cols, sameSize;
    
    clearMatrix(result);

    for(rows = 0; rows < maxSize[0]; rows++) {
        for(cols = 0; cols < maxSize[1]; cols++) {
            result[rows][cols] = 0;
            for(sameSize = 0; sameSize < maxSize[1]; sameSize++)
                result[rows][cols] += mtxTrans[rows][sameSize] * mtxSqr[sameSize][cols];
        }
    }

    printf("RESULT:\n");
    printMatrix(result, maxSize);
}

void isSimetric(int mtx[MAX_ROWS][MAX_COLS], int *maxSize) {
    int rows, cols;

    for(rows = 0; rows < maxSize[0]; rows++) {
        for(cols = 0; cols < maxSize[1]; cols++) {
            if(mtx[rows][cols] != mtx[cols][rows]) {
                printf("A matriz não é simétrica.\n");
                return;
            }
        }
    }
    printf("A matriz é simétrica.\n");
}

int main() {
    int mtx[MAX_ROWS][MAX_COLS];
    int maxSize[2];
    
    defineMatrixSize(maxSize);
    defineMatrixElements(mtx, maxSize);

    printMatrix(mtx, maxSize);

    mtxSqrTrans(mtx, maxSize);

    isSimetric(mtx, maxSize);
    
    return 0;
}