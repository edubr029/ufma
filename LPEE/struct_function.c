#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 1024

#define MAX_ROWS 1024
#define MAX_COLS 1024

#define MAX_STUDENT 5
#define MAX_GRADE 5

typedef struct class {
    char name[MAX_SIZE];
    int grade[MAX_SIZE];
    int avarage;
} class_t;

void readStudents(class_t student[MAX_STUDENT]) {
    for(int i = 0; i < MAX_STUDENT; i++) {
        printf("Aluno %d: ", i+1);
        gets(student[i].name);
    }
}

void readGrade(class_t student[MAX_STUDENT]){
    int invalidGrade = 0;
    for(int i = 0; i < MAX_STUDENT; i++) {
        printf("Digite as notas do aluno %s: \n", student[i].name);
        for(int j = 0; j < MAX_STUDENT; j++) {
            do {
                printf("Nota %d: ", j+1);
                scanf("%d", &student[i].grade[j]);

                invalidGrade = student[i].grade[j] > 10 || student[i].grade[j] < 0;
                
                if(invalidGrade)
                    printf("Valor inválido! Insira novamente. \n");
            } while(invalidGrade);
        }
    }
}

void calculateAvarage(class_t student[MAX_STUDENT]) {
    int sum = 0;
    for(int i = 0; i < MAX_STUDENT; i++) {
        for(int j = 0; j < MAX_STUDENT; j++)
            sum += student[i].grade[j];
        student[i].avarage = (sum / MAX_GRADE);
        sum = 0;
    }
}

void calculateOverallAvarage(class_t student[MAX_STUDENT], int *avarageGrade) {
    int sum = 0;
    for(int i = 0; i < MAX_STUDENT; i++)
        sum += student[i].avarage;
    *avarageGrade = (sum / MAX_STUDENT);
}

void showAvarage(class_t student[MAX_STUDENT]) {
    for(int i = 0; i < MAX_STUDENT; i++)
        printf("%s - Média: %d \n", student[i].name, student[i].avarage);
}

void showOverallAvarage(int avarageGrade) {
    printf("Media Geral: %d", avarageGrade);
}

int main() {
    class_t student[MAX_STUDENT];
    int avarageGrade;

    setlocale(LC_ALL, "Portuguese");

    printf("Entre com os nomes dos alunos.\n");
    readStudents(student);

    printf("Entre com as notas dos alunos.\n");
    readGrade(student);

    calculateAvarage(student);
    calculateOverallAvarage(student, &avarageGrade);

    printf("As médias dos alunos são:\n");
    showAvarage(student);
    showOverallAvarage(avarageGrade);

    return 0;
}