#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define MAX_ROWS 1024

int vectorSize() {
    int maxSize;
    scanf("%d", &maxSize);

    return maxSize;
}

void vectorElements(int vector[], int maxSize) {
    int rows;
    for(rows = 0; rows < maxSize; rows++) {
        printf("[%d]: ", rows + 1);
        scanf("%d", &vector[rows]);
    }
}

void showVector(int vector[], int maxSize) {
    int rows;
    for(rows = 0; rows < maxSize; rows++)
        printf("%d ", vector[rows]);
    printf("\n");
}

void actionsOptions() {
    printf("1 - Mostrar o vetor.\n");
    printf("2 - Mostrar o maior valor do vetor.\n");
    printf("3 - Mostrar o menor valor do vetor.\n");
    printf("4 - Mostrar a média entre os elementos do vetor.\n");
    printf("5 - Mostrar o desvio padrão do vetor.\n");
    printf("6 - Mostrar os números pares do vetor.\n");
    printf("7 - Mostrar os números ímpares do vetor.\n");

    printf("8 - Sair.\n");

    printf("\n Selecione uma das opções acima: ");
}

int findHigher(int vector[], int maxSize) {
    int rows, higher;

    higher = vector[0];

    for(rows = 0; rows < maxSize; rows++) {
        if(vector[rows] > higher)
            higher = vector[rows];
    }

    return higher;
}

int findLower(int vector[], int maxSize) {
    int rows, lower;

    lower = vector[0];

    for(rows = 0; rows < maxSize; rows++) {
        if(vector[rows] < lower)
            lower = vector[rows];
    }

    return lower;
}

float findAvarage(int vector[], int maxSize) {
    int rows, sum = 0;
    float avarege;

    for(rows = 0; rows < maxSize; rows++)
        sum += vector[rows];
    avarege = (float) sum / maxSize;

    return avarege;
}

float calcStandardDeviation(int vector[], int maxSize) {
    int rows, sum = 0;
    float mean, standardDeviation = 0.0;

    for(rows = 0; rows < maxSize; rows++)
        sum += vector[rows];

    mean = (float) sum / maxSize;

    for(rows = 0; rows < maxSize; rows++)
        standardDeviation += pow(vector[rows] - mean, 2);
    
    return sqrt(standardDeviation / maxSize);
}

void findEven(int vector[], int maxSize) {
    int i, rows, evenCount = 0;

    for(rows = 0; rows < maxSize; rows++) {
        if(vector[rows] % 2 == 0)
            evenCount++;
    }

    int even[evenCount];

    for(rows = 0, i = 0; rows < maxSize; rows++) {
        if(vector[rows] % 2 == 0) {
            even[i] = vector[rows];
            i++;
        }
    }

    //I don't like this part, but I don't know how to do it better :P
    printf("Os números pares do vetor são: ");
    for(rows = 0; rows < evenCount; rows++)
        printf("%d ", even[rows]);
    printf("\n");
}

void findOdd(int vector[], int maxSize) {
    int i, rows, oddCount = 0;

    for(rows = 0; rows < maxSize; rows++) {
        if(vector[rows] % 2 != 0)
            oddCount++;
    }

    int odd[oddCount];

    for(rows = 0, i = 0; rows < maxSize; rows++) {
        if(vector[rows] % 2 != 0) {
            odd[i] = vector[rows];
            i++;
        }
    }

    //I don't like this part, but I don't know how to do it better :P
    printf("Os números ímpares do vetor são: ");
    for(rows = 0; rows < oddCount; rows++)
        printf("%d ", odd[rows]);
    printf("\n");
}

int main() {
    int vector[MAX_ROWS];
    int maxSize, option;
    int higher, lower, even, odd;
    float avarage, standardDeviation;

    setlocale(LC_ALL, "Portuguese");

    //Defines the maximum size of the vector
    printf("Defina o tamanho do vetor: ");
    maxSize = vectorSize();

    //Defines the elements of the vector
    printf("Defina os elementos do vetor.\n\n");
    vectorElements(vector, maxSize);

    //Shows the options of the vector manipulation
    printf("Escolha como deseja manipular o vetor: \n");
    actionsOptions();

    scanf("%d", &option);

    switch(option) {
        case 1:
            showVector(vector, maxSize);
            break;
        case 2:
            higher = findHigher(vector, maxSize);
            printf("O maior valor do vetor é: %d \n", higher);
            break;
        case 3:
            lower = findLower(vector, maxSize);
            printf("O menor elemento do vetor é: %d \n", lower);
            break;
        case 4:
            avarage = findAvarage(vector, maxSize);
            printf("A média entre os elementos do vetor é: %.1f \n", avarage);
            break;
        case 5:
            standardDeviation = calcStandardDeviation(vector, maxSize);
            printf("O desvio padrão do vetor é: %.1f \n", standardDeviation);
            break;
        case 6:
            findEven(vector, maxSize);
            break;
        case 7:
            findOdd(vector, maxSize);
            break;
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
    printf("\n");
    
    return 0;
}