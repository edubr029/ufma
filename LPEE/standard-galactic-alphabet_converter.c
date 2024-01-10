#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100

typedef struct {
    char standard;
    char* galactic;
} Alphabet;

Alphabet* create_alphabet(){
    char standard_alphabet[] = "abcdefghijklmnopqrstuvwxyz. ";
    char *galactic_alphabet[] = {"ᔑ", "ʖ", "ᓵ", "⟍̅", "ᒷ", "⎓", "˧", "⍑", "¦", "⋮",
                                 "ꖌ", "ꖎ", "ᒲ", "リ", "𝙹", "!¡", "ᑑ", "∷", "ᓭ", "ℸ ̣",
                                 "⚍", "⍊", "∴", "̇/", "ǁ", "⨅", ".", " "};

    Alphabet* alphabet = (Alphabet*)malloc(sizeof(Alphabet)*28);
    if(alphabet == NULL){
        fprintf(stderr, "\033[31mMemory allocation failed\033[0m\n");
        return NULL;
    }

    for(int i = 0; i < 28; i++){
        alphabet[i].standard = standard_alphabet[i];
        alphabet[i].galactic = galactic_alphabet[i];
    }

    return alphabet;
}

void str_read(char* str){
    printf("\033[37mEnter a string: \033[90m");
    fgets(str, MAX_STR_LEN, stdin);
    str[strcspn(str, "\n")] = 0;
    printf("\033[0m");
}

void str_to_lower(char* str){
    int i = 0;
    while(str[i]){
        str[i] = tolower((unsigned char)str[i]);
        i++;
    }
}

char* str_encode(char* str, Alphabet* alphabet){
    str_to_lower(str);

    char* result = (char*)malloc(sizeof(char)*MAX_STR_LEN*4);
    if(result == NULL){
        fprintf(stderr, "\033[31mMemory allocation failed\033[0m\n");
        return NULL;
    }

    int i = 0, j = 0;
    while(str[i]){
        for(int k = 0; k < 28; k++){
            if(str[i] == alphabet[k].standard){
                j += sprintf(result + j, "%s", alphabet[k].galactic);
                break;
            }
        }
        i++;
    }

    return result;
}

char* str_decode(char* str, Alphabet* alphabet){
    char* result = (char*)malloc(sizeof(char)*MAX_STR_LEN);
    if(result == NULL){
        fprintf(stderr, "\033[31mMemory allocation failed\033[0m\n");
        return NULL;
    }

    int i = 0, j = 0;
    while(str[i]){
        for(int k = 0; k < 28; k++){
            if(strncmp(str + i, alphabet[k].galactic, strlen(alphabet[k].galactic)) == 0){
                result[j++] = alphabet[k].standard;
                i += strlen(alphabet[k].galactic) - 1;
                break;
            }
        }
        i++;
    }
    result[j] = '\0';

    return result;
}

void print_result(char* result){
    if(result != NULL){
        printf("\033[92m%s\033[0m\n", result);
    }
}

int main(){
    char* str = (char*)malloc(sizeof(char)*MAX_STR_LEN);
    if(str == NULL){
        fprintf(stderr, "\033[31mMemory allocation failed\033[0m\n");
        return 1;
    }

    Alphabet* alphabet = create_alphabet();
    if(alphabet == NULL){
        free(str);
        return 1;
    }

    int option;
    do{
        printf("\033[37m1.\033[90m Encode\n");
        printf("\033[37m2.\033[90m Decode\n");
        printf("\033[37m3.\033[90m Exit\n");
        printf("\033[90mEnter your choice: \033[37m");

        scanf("%d", &option);
        getchar(); // To consume the newline character
        printf("\033[0m");

        switch(option){
            case 1:
                str_read(str);
                char* encoded = str_encode(str, alphabet);
                print_result(encoded);
                if(encoded != NULL){
                    free(encoded);
                }
                break;
            case 2:
                str_read(str);
                char* decoded = str_decode(str, alphabet);
                print_result(decoded);
                if(decoded != NULL){
                    free(decoded);
                }
                break;
            case 3:
                printf("\033[91mExiting...\033[0m\n");
                break;
            default:
                printf("\033[31mInvalid option. Please try again.\033[0m\n");
        }
    } while(option != 3);

    free(str);
    free(alphabet);

    return 0;
}