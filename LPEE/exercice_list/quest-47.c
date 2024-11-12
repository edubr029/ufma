#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_SIZE 30
#define MAX_CHAR 15
#define MAX_USR 3

typedef struct user_info {
    char name[MAX_SIZE];
    int age;
} user_t;

void readUserName(user_t *usr) {
    int invalidSize;
    for(int i = 0; i < MAX_USR; i++) {
        do {
            printf("Usuário %d: ", i+1);
            if(fgets(usr[i].name, MAX_SIZE, stdin) == NULL) {
                printf("Erro ao ler o nome do usuário.\n");
                exit(1);
            }

            usr[i].name[strcspn(usr[i].name, "\n")] = '\0';
            invalidSize = strlen(usr[i].name) > MAX_CHAR; 

            if(invalidSize)
                printf("Tamanho de nome inválido! Tente novamente.\n");
        } while(invalidSize);
    }
    printf("\n");
}

void readUserAge(user_t *usr) {
    int invalidAge;
    int result;
    for(int i = 0; i < MAX_USR; i++) {
        do {
            printf("%s: ", usr[i].name);
            result = scanf("%d", &usr[i].age);

            invalidAge = usr[i].age < 1 || result != 1;

            if(invalidAge)
                printf("Idade inválida! Tente novamente.\n");

            while(getchar() != '\n');
        } while(invalidAge);            
    }
    printf("\n");
}

void showUserData(user_t *usr) {
    for(int i = 0; i < MAX_USR; i++)
        printf("- %s, %d anos.\n", usr[i].name, usr[i].age);
    printf("\n");
}

int main() {
    user_t usr[MAX_USR];

    setlocale(LC_ALL, "Portuguese");

    printf("Entre com o(s) nome do(s) %d usuário(s) (Max. %d caracteres)\n", MAX_USR, MAX_CHAR);
    readUserName(usr);

    printf("Entre com a(s) idade(s) do(s) usuários\n");
    readUserAge(usr);

    printf("Todos os usuários cadastrado são:\n");
    showUserData(usr);
        
    return 0;
}