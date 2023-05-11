#include <stdio.h>
#include <stdlib.h>

int main() {
    char string[3];
    int i, count = 3;

    printf("Enter a string: ");
    for (i = 0; i < count; i++)
    {
        scanf("%c", &string[i]);
    }

    printf("The string is: ");
    for (i = 0; i < count; i++)
    {
        printf("%c ", string[i]);
    }
    
    return 0;
}