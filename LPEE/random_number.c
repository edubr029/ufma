#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_SIZE 1024

#define MAX_USR 5

#define MIN_RND 1
#define MAX_RND 999

typedef struct user_info {
    char id[MAX_SIZE];
    char number[MAX_SIZE];
} user_t;

void generateRandomNumber(char *generatedNumber) {
    int min = MIN_RND;
    int max = MAX_RND;

    int range = max - min + 1;
    
    int random_number = rand() % range + min;
    int digits = snprintf(NULL, 0, "%d", max);
    char *result = malloc(digits+1);

    sprintf(result, "%0*d", digits, random_number);
    strcpy(generatedNumber, result);
    free(result);
}

void registeringUserRndNumber(user_t *user) {
    char generatedNumber[MAX_SIZE];
    char previousNumber[MAX_SIZE] = "";

    for(int i = 0; i < MAX_USR; i++) {
        do
            generateRandomNumber(generatedNumber);
        while(strcmp(generatedNumber, previousNumber) == 0);

        strcpy(user[i].number, generatedNumber);
        strcpy(previousNumber, generatedNumber);
    }
}

void showUserNumber(user_t user[]) {
    for(int i = 0; i < MAX_USR; i++)
        printf("Usuario %d - %s \n", i+1, user[i].number);
}

int main() {
    user_t user[MAX_SIZE];

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    registeringUserRndNumber(user);
    showUserNumber(user);

    return 0;
}
