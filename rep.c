#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_SIZE 1024

void readString(char *str) {
    printf("Digite uma string: ");
    scanf("%s", str);
}

char readChar() {
    char chr;
    printf("Digite um caractere: ");
scanf(" %c", &chr);
    return chr;
}

void readSymbol(char *str) {
    printf("Digite uma string substituta: ");
    scanf("%s", str);
}

void changeChar(char *str, char chr, char *symbol) {
    int i = 0, j = 0, k = 0;
    int len_s = strlen(str);
    int len_sub = strlen(symbol);
    char aux[MAX_SIZE];

    while(i < len_s) {
        if(str[i] == chr) {
            for (j = 0; j < len_sub; j++) {
                aux[k] = symbol[j];
                k++;
            }
            i++;
            len_s += len_sub - 1;
        } else {
            aux[k] = str[i];
            i++;
            k++;
        }
    }
    aux[k] = '\0';
    strcpy(str, aux);
}

void printString(char *str) {
    printf("Saída 1: %s\n", str);
}

void sortString(char *str) {
    char str_len = strlen(str);
    int i, j;
    char temp;
    for (i = 0; i < str_len - 1; i++) {
        if (str[i] == '*' || (i > 0 && str[i-1] == '*' && str[i+1] == '*')) continue;
        for (j = i + 1; j < str_len; j++) {
            if (str[j] == '*' || (j > 0 && str[j-1] == '*' && str[j+1] == '*')) continue;
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[MAX_SIZE];
    char symbol[MAX_SIZE];
    char chr;

    setlocale(LC_ALL, "Portuguese");

    readString(str);
    chr = readChar();

    readSymbol(symbol);

    changeChar(str, chr, symbol);
    printString(str);

    sortString(str);
    printString(str);

    return 0;
}