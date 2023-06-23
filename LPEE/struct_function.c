#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_SIZE 1024

#define MAX_ROWS 1024
#define MAX_COLS 1024

#define MAX_STUDENT 5
#define MAX_GRADE 5

typedef struct class {
    char name[MAX_SIZE];
    float grade[MAX_SIZE];
    float average;
} class_t;

void readStudents(class_t *student) {
    for(int i = 0; i < MAX_STUDENT; i++) {
        printf("Aluno %d: ", i+1);
        if(fgets(student[i].name, MAX_SIZE, stdin) == NULL) {
            printf("Erro ao ler o nome do aluno.\n");
            exit(1);
        }
        student[i].name[strcspn(student[i].name, "\n")] = '\0';
    }
}

void readGrade(class_t *student){
    int invalidGrade = 0;
    for(int i = 0; i < MAX_STUDENT; i++) {
        printf("Digite as notas do aluno %s: \n", student[i].name);
        for(int j = 0; j < MAX_GRADE; j++) {
            do {
                printf("Nota %d: ", j+1);
                if(scanf("%f", &student[i].grade[j]) != 1) {
                    printf("Erro ao ler a nota do aluno.\n");
                    exit(1);
                }

                invalidGrade = student[i].grade[j] > 10.0 || student[i].grade[j] < 0.0;
                
                if(invalidGrade)
                    printf("Valor inválido! Insira novamente. \n");
            } while(invalidGrade);
        }
    }
}

void calculateAverage(class_t *student) {
    float sum = 0.0;
    for(int i = 0; i < MAX_STUDENT; i++) {
        for(int j = 0; j < MAX_GRADE; j++)
            sum += student[i].grade[j];
        student[i].average = (sum / MAX_GRADE);
        sum = 0.0;
    }
}

void calculateOverallAverage(class_t student[MAX_STUDENT], float *averageGrade) {
    float sum = 0.0;
    for(int i = 0; i < MAX_STUDENT; i++)
        sum += student[i].average;
    *averageGrade = (sum / MAX_STUDENT);
}

void showAverage(class_t student[MAX_STUDENT]) {
    for(int i = 0; i < MAX_STUDENT; i++)
        printf("%s - Média: %.2f \n", student[i].name, student[i].average);
}

void showOverallAverage(float averageGrade) {
    printf("Média Geral: %.2f \n", averageGrade);
}

int main() {
    class_t student[MAX_STUDENT];
    float averageGrade;

    setlocale(LC_ALL, "Portuguese");

    printf("Entre com os nomes dos alunos.\n");
    readStudents(student);

    printf("Entre com as notas dos alunos.\n");
    readGrade(student);

    calculateAverage(student);
    calculateOverallAverage(student, &averageGrade);

    printf("As médias dos alunos são:\n");
    showAverage(student);
    showOverallAverage(averageGrade);

    return 0;
}