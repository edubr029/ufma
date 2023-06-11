#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

int countSubstrings(char *str, char *substr) {
    int count = 0;
    int str_len = strlen(str);
    int substr_len = strlen(substr);

    for (int i = 0; i <= str_len - substr_len; i++) {
        int j;
        for (j = 0; j < substr_len; j++) {
            if (str[i + j] != substr[j])
                break;
        }
        if (j == substr_len)
            count++;
    }

    return count;
}

int main() {
    char str[MAX_SIZE], substr[MAX_SIZE];

    printf("Enter the string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the substring: ");
    fgets(substr, MAX_SIZE, stdin);
    substr[strcspn(substr, "\n")] = '\0';

    int count = countSubstrings(str, substr);
    printf("The substring %s shows up %d times in the string %s.\n", substr, count, str);

    return 0;
}