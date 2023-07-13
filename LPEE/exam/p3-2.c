#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_SIZE 1024

typedef struct word_list {
    char list[MAX_SIZE];
} wl_t;


void wordQuantity(int *numberOfWords) {
    scanf("%d", numberOfWords);
}

void readStrings(wl_t *word, int numberOfWords) {
    int maxWords = 0;
    do {
        printf("Palavra %d: ", maxWords+1);
        scanf(" %s", &word[maxWords].list);
        ++maxWords;
    } while(maxWords < numberOfWords);
}

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

    for (rows = 0; rows < maxSize; rows++) {
        for (cols = 0; cols < maxSize; cols++) {
            printf("[%d][%d]: ", rows + 1, cols + 1);
            scanf(" %s", &mtx[rows][cols]);
        }
    }
    printf("\n");
}

void showMatrix(char mtx[MAX_SIZE][MAX_SIZE], int maxSize) {
    int rows, cols;

    for(rows = 0; rows < maxSize; rows++) {
        for(cols = 0; cols < maxSize; cols++)
            printf("%c ", mtx[rows][cols]);
        printf("\n");
    }
}

void sensorMatrix(char mtx[MAX_SIZE][MAX_SIZE], wl_t *word, int maxSize) {
    int rows = 0, cols;

    for(cols = 0; cols < maxSize; cols++) {
        for(int i = 0; i < (strlen(word[cols].list)-1); i++) {
            if(mtx[rows][cols] == word[i].list && mtx[rows+1][cols] == word[i+1].list) {
                printf("MTX: %c | STR: %c\n", mtx[rows][cols], word[i].list); //just for debug
                mtx[rows][cols] = '*';
                mtx[rows+1][cols] = '*';
            }
        }
        rows++;
    }
}

int main() {
    char mtx[MAX_SIZE][MAX_SIZE];
    wl_t word[MAX_SIZE/2];
    int maxSize, numberOfWords = 0;

    setlocale(LC_ALL, "Portuguese");

    printf("Quantas palavras você deseja procurar?\n");
    wordQuantity(&numberOfWords);

    printf("Entre com as palavras para procurar na matriz: \n");
    readStrings(word, numberOfWords);

    defineMatrixSize(&maxSize);

    defineMatrixElements(mtx, maxSize);
    showMatrix(mtx, maxSize);
    
    sensorMatrix(mtx, word, maxSize);
    showMatrix(mtx, maxSize);

    return 0;
}