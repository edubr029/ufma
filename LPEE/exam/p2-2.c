#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_SIZE 1024
#define MAX_ROWS 1024
#define MAX_COLS 1024

void readString(char *str) {
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void findPalindromo(char *str, char *out) {
    char *token = strtok(str, " ");
    int str_len = strlen(str);
    int count = 0, i, j;
    
    while(token != NULL) {
        for(i = str_len; i > 1; i--) {
            for(j = 0; j < str_len; j++) {
                if(token[i] == token[j])
                    count++;
                else if(count >= 3 && count <= 5) {
                    printf("%d count / %s token \n", count, token);
                    count = 0;
                }
            }
        }

        token = strtok(NULL, " ");
    }
}

void printstr(char *str) {
    printf("%s", str);
}

int main() {
    char str[MAX_SIZE];
    char out[MAX_SIZE];

    //setlocale();

    printf("Digite uma string: ");
    readString(str);
    
    findPalindromo(str, out);
    //printstr(out);

    return 0;
}

// ovo da arara é comum? //