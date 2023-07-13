#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_SIZE 1024

void clearMatrix(char mtx[MAX_SIZE][MAX_SIZE]) {
    int rows, cols;

    for(rows = 0; rows < MAX_SIZE; rows++)
        for(cols = 0; cols < MAX_SIZE; cols++)
            mtx[rows][cols] = ' ';
}

void showMatrix(char mtx[MAX_SIZE][MAX_SIZE], int maxSize) {
    int rows, cols;

    for(rows = 0; rows < maxSize; rows++) {
        for(cols = 0; cols < maxSize; cols++)
            printf("%c ", mtx[rows][cols]);
        printf("\n");
    }
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

void wordToFind(char *word) {
    do {
        printf("Qual a palavra que deseja encontrar?\n");
        scanf(" %s", word);
    } while(strlen(word) > MAX_SIZE);
}

int findWordVertical(char mtx[MAX_SIZE][MAX_SIZE], char *word, int maxSize) {
    int rows = 0, cols;
    int wordCount = 0;

        for(cols = 0; cols < maxSize; cols++) {
            for(int i = 0; i < (strlen(word)-1); i++)
                if(mtx[rows][cols] == word[i] && mtx[rows][cols] == word[i+1]) {
                    printf("MTX: %c | STR: %c\n", mtx[rows][cols], word[i]);
                    wordCount++;
                }
            rows++;
        }
    
    return wordCount;
}

int findWordHorizontal(char mtx[MAX_SIZE][MAX_SIZE], char *word, int maxSize) {
    int rows, cols = 0;
    int wordCount = 0;

        for(rows = 0; rows < maxSize; rows++) {
            for(int i = 0; i < (strlen(word)-1); i++)
                if(mtx[rows][cols] == word[i] && mtx[rows][cols] == word[i+1]) {
                    printf("MTX: %c | STR: %c\n", mtx[rows][cols], word[i]);
                    wordCount++;
                }
            cols++;
        }

    return wordCount;
}

void countHowManyWords(char mtx[MAX_SIZE][MAX_SIZE], char *word, int maxSize) {
    int wordCount = 0;

    wordCount += findWordVertical(mtx, word, maxSize);
    wordCount += findWordHorizontal(mtx, word, maxSize);

    printf("A quantidade de vezes que a palavra '%s' aparece na matriz é: %d vezes", word, wordCount);
}

int main() {
    char mtx[MAX_SIZE][MAX_SIZE];
    char word[MAX_SIZE];
    int maxSize;

    setlocale(LC_ALL, "Portuguese");

    defineMatrixSize(&maxSize);
    
    wordToFind(word);

    defineMatrixElements(mtx, maxSize);
    showMatrix(mtx, maxSize);

    countHowManyWords(mtx, word, maxSize);

    return 0;
}