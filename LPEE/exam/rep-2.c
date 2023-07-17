#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 1024

void clearMatrix(char mtx[MAX_SIZE][MAX_SIZE]) {
    int rows, cols;

    for(rows = 0; rows < MAX_SIZE; rows++)
        for(cols = 0; cols < MAX_SIZE; cols++)
            mtx[rows][cols] = ' ';
}

void defineMatrixSize(int *maxSize) {
    int def_size;
    int notValidSize;

    do {
        printf("Entre com a dimensão máxima da matriz (Max. %d): ", MAX_SIZE);
        scanf("%d", &def_size);

        notValidSize = (def_size> MAX_SIZE || def_size < 1);

        if(notValidSize)
            printf("Valores inválidos! Tente novamente.\n");
    } while(notValidSize);

    *maxSize = def_size;
}

void defineMatrixElements(char mtx[MAX_SIZE][MAX_SIZE], int maxSize) {
    int rows, cols;

    clearMatrix(mtx);

    for(rows = 0; rows < maxSize; rows++) {
        for(cols = 0; cols < maxSize; cols++) {
            printf("[%d][%d]: ", rows + 1, cols + 1);
            scanf(" %s", &mtx[rows][cols]);
        }
    }
    printf("\n");
}

void printMatrix(char mtx[MAX_SIZE][MAX_SIZE], int maxSize) {
    int rows, cols;
    for(rows = 0; rows < maxSize; rows++) {
        for(cols = 0; cols < maxSize; cols++)
            printf("%c ", mtx[rows][cols]);
        printf("\n");
    }
    printf("\n");
}

void changeMatrixElements(char mtx[MAX_SIZE][MAX_SIZE], int maxSize) {
    int rows, cols;
    for(rows = 0; rows < maxSize; rows++) {
        for(cols = 0; cols < maxSize; cols++) {
            if(rows != cols) {
                if(mtx[rows][cols] >= '0' && mtx[rows][cols] <= '9')
                    mtx[rows][cols] = '*';
                if(mtx[rows][cols] >= 'a' && mtx[rows][cols] <= 'z')
                    mtx[rows][cols] = '#';
            }
        }
    }
}

int main() {
    char mtx[MAX_SIZE][MAX_SIZE];
    int maxSize;

    setlocale(LC_ALL, "Portuguese");

    defineMatrixSize(&maxSize);

    defineMatrixElements(mtx, maxSize);
    printMatrix(mtx, maxSize);

    changeMatrixElements(mtx, maxSize);
    printMatrix(mtx, maxSize);

    return 0;
}