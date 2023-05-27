#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int invertNumber() {
    int number, invertedNumber = 0, rest;

    printf("Digite um número: ");
    scanf("%d", &number);

    while(number != 0) {
        rest = number % 10;
        invertedNumber = invertedNumber * 10 + rest;
        number /= 10;
    }

    return invertedNumber;    
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int invertedNumber = invertNumber();

    printf("O número invertido é: %d\n", invertedNumber);

    return 0;
}