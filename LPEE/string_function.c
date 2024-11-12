#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 1024

void changeNumberBySymbol(char *str, char symbol) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            str[i] = symbol;
        }
        i++;
    }
}

int main() {
    char str[MAX_SIZE];
    char symbol;

    setlocale(LC_ALL, "Portuguese");

    printf("Entre com quaisquer coisa (Max. %d): ", MAX_SIZE);
    fgets(str, MAX_SIZE, stdin);

    printf("Escolha um símbolo para substituir quaisquer números na string: ");
    scanf("%c", &symbol);

    changeNumberBySymbol(str, symbol);
    printf("String modificada: %s\n", str);

    return 0;
}
