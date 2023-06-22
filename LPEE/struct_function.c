#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 1024

#define MAX_ROWS 1024
#define MAX_COLS 1024

#define MAX_STUDENT 5
#define MAX_NOTAS 5

struct turma {
    char nome[MAX_SIZE];
    int notas[MAX_SIZE];
    int media;
};

typedef struct turma turma;

void lerAlunos(turma aluno[MAX_STUDENT]) {
    for(int i = 0; i < MAX_STUDENT; i++) {
        printf("Aluno %d: ", i+1);
        gets(aluno[i].nome);
    }
}

void lerNota(turma aluno[MAX_STUDENT]){
    int notainvalida = 0;
    for(int i = 0; i < MAX_STUDENT; i++) {
        printf("Digite as notas do aluno %s: \n", aluno[i].nome);
        for(int j = 0; j < MAX_STUDENT; j++) {
            do {
                printf("Nota %d: ", j+1);
                scanf("%d", &aluno[i].notas[j]);

                notainvalida = aluno[i].notas[j] > 10 || aluno[i].notas[j] < 0;
                
                if(notainvalida)
                    printf("Valor inválido! Insira novamente. \n");
            } while(notainvalida);
        }
    }
}

void calcularMedia(turma aluno[MAX_STUDENT]) {
    int soma = 0;
    for(int i = 0; i < MAX_STUDENT; i++) {
        for(int j = 0; j < MAX_STUDENT; j++)
            soma += aluno[i].notas[j];
        aluno[i].media = (soma / MAX_NOTAS);
        soma = 0;
    }
}

void calcularMediaGeral(turma aluno[MAX_STUDENT], int *mediaGeral) {
    int soma = 0;
    for(int i = 0; i < MAX_STUDENT; i++)
        soma += aluno[i].media;
    *mediaGeral = (soma / MAX_STUDENT);
}

void exibirMedia(turma aluno[MAX_STUDENT]) {
    for(int i = 0; i < MAX_STUDENT; i++)
        printf("%s - Média: %d \n", aluno[i].nome, aluno[i].media);
}

void exibirMediaGeral(int mediaGeral) {
    printf("Media Geral: %d", mediaGeral);
}

int main() {
    turma aluno[MAX_STUDENT];
    int mediaGeral;

    setlocale(LC_ALL, "Portuguese");

    printf("Entre com os nomes dos alunos.\n");
    lerAlunos(aluno);

    printf("Entre com as notas dos alunos.\n");
    lerNota(aluno);

    calcularMedia(aluno);
    calcularMediaGeral(aluno, &mediaGeral);

    printf("As médias dos alunos são:\n");
    exibirMedia(aluno);
    exibirMediaGeral(mediaGeral);

    return 0;
}