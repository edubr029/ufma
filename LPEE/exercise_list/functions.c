#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int invertNumber(int number) {
    int invertedNumber = 0, rest;  

    while(number != 0) {
        rest = number % 10;
        invertedNumber = invertedNumber * 10 + rest;
        number /= 10;
    }

    return invertedNumber;
}

double power(double base, double exponent) {
    double result = 1;

    if (exponent < 0) {
        exponent *= -1;
        base = 1 / base;
    }

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int main() {
    int invertedNumber, number;
    double base, exponent, result;

    setlocale(LC_ALL, "Portuguese");

    //Número inteiro invertido

    printf("Digite um número: ");
    scanf("%d", &number);

    invertedNumber = invertNumber(number);

    printf("O número invertido é: %d\n", invertedNumber);

    //Função potência  

    printf("Digite a base: ");
    scanf("%lf", &base);

    printf("Digite o expoente: ");
    scanf("%lf", &exponent);

    result = power(base, exponent);

    printf("O resultado é: %.2lf\n", result);

    return 0;
}
