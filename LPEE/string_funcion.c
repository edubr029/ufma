#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 1024

void readString(char *str) {
    gets(str);
}

void readSymbol(char *s) {
    scanf("%c", &s);
}

void changeNumber(char *str, char s) {
    for(int i = 0; *str != '\0'; i++) {
        if(*str >= 0 && *str <= 9)
            *str = s;
        str++;
    }
}

int main() {
    char str[MAX_SIZE];
    char symbol;

    setlocale(LC_ALL, "Portuguese");

    printf("Entre com quaisquer coisa (Max. %d Caracteres): ", MAX_SIZE);
    readString(str);
    
    printf("Escolha um simbolo para substituir quaisquer números na string: ");
    readSymbol(&symbol);
    
    changeNumber(str, symbol);
    printf("%s", str);

    return 0;
}