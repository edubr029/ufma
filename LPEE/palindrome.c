#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_SIZE 512

// Proof of concept para algoritmo de palíndromo

// Lê uma string do usuário
void readString(char *str){
    printf("Digite uma string: ");
    fgets(str, MAX_SIZE, stdin);

    // Remove o \n do final da string
    str[strlen(str) - 1] = '\0';
    fflush(stdin);
}

// Retorna 1 se a string for um palíndromo e 0 se não for
int isPalindrome(char *str){
    int start = 0;
    int end = strlen(str) - 1;

    while(start <= end){
        // Se o caractere no ininio for diferente do caractere no final, retorna 0
        if(tolower(str[start]) != tolower(str[end]))
            return 0;
        // Incrementa o início e decrementa o final
        start++;
        end--;
    }
    // Se o loop terminar, significa que a string é um palíndromo então retorna 1
    return 1;
}

int main(){
    char str[MAX_SIZE];
    setlocale(LC_ALL, "Portuguese");

    // Lê uma string do usuário
    readString(str);

    // Verifica se a string é um palíndromo
    if(isPalindrome(str))
        printf("A string \"%s\" é um palíndromo\n", str);
    else
        printf("A string \"%s\" não é um palíndromo\n", str);

    return 0;
}