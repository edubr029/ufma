#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_SIZE 4096
#define MAX_RND 6

typedef struct hangman {
    char word[MAX_SIZE];
    char theme[MAX_SIZE];
} hm_t;

void savedWords(hm_t *word_list) {
    char themes[MAX_RND][MAX_SIZE] = {"Alimento", "Alimento", "Animal", "Animal", "Cores", "Cores", "Profissão", "Profissão", "Transporte", "Transporte"};
    char words[MAX_RND][MAX_SIZE] = {"Melancia", "Castanha", "Hamster", "Crocodilo", "Vermelho", "Marrom", "Encanador", "Médico", "Empilhadeira", "Bicicleta"};

    for(int i = 0; i < MAX_RND; i++) {
        strcpy(word_list[i].theme, themes[i]);
        strcpy(word_list[i].word, words[i]);
    }
}

int rand_num() {
    return rand() % MAX_RND;
}

void showTheme(hm_t *word_list, int num) {
    printf("\nTema: %s\n", word_list[num].theme);
}

void hideLetters(hm_t *word_list, int num, char *hidden) {
    int size = strlen(word_list[num].word);

    for(int i = 0; i < size; i++)
        printf("%c ", hidden[i]);
}

void hangman(int attempts) {
    switch (attempts) {
        case 0:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
        break;
        case 1:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
        break;
        case 2:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
        break;
        case 3:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
        break;
        case 4:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
        break;
        case 5:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
        break;
        case 6:
            printf("\n\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
        break;
    }
}

int checkLetter(char letter, char *guessedLetters, int attempts) {
    for(int i = 0; i < attempts; i++)
        if(guessedLetters[i] == letter)
            return 1;
    return 0;
}

void game(hm_t *word_list) {
    char answer = 'S';
    while(answer == 'S' || answer == 's') {
        int attempts = 0, num = rand_num();
        savedWords(word_list);
        
        showTheme(word_list, num);

        int size = strlen(word_list[num].word);
        char hidden[size];
        for(int i = 0; i < size; i++)
            hidden[i] = '_';

        hideLetters(word_list, num, hidden);

        int correct = 0;
        char guessedLetters[6];
        while(attempts < 6) {
            char letter;
            printf("\n\nDigite uma letra: ");
            scanf(" %c", &letter);

            if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
                if(checkLetter(letter, guessedLetters, attempts)) {
                    printf("\nVocê já digitou essa letra. Tente outra.\n");
                    continue;
                }

                guessedLetters[attempts] = letter;

                int found = 0;
                for(int i = 0; i < size; i++) {
                    if(letter == word_list[num].word[i] || letter == word_list[num].word[i] + 32 || letter == word_list[num].word[i] - 32) {
                        hidden[i] = word_list[num].word[i];
                        found = 1;
                    }
                    printf("%c ", hidden[i]);
                }

                if(found) {
                    correct = 0;
                    for(int i = 0; i < size; i++)
                        if(hidden[i] != '_')
                            correct++;
                    if(correct == size) {
                        printf("\n\nVocê ganhou!\n");
                        break;
                    }
                } else {
                    attempts++;
                    hangman(attempts);
                }
            } else {
                printf("\nDigite uma letra válida.\n");
            }
        }

        if(attempts == 6) {
            printf("\n\nVocê perdeu!\n");
            printf("A palavra era: %s\n", word_list[num].word);
        }

        printf("\n\n");

        printf("Deseja jogar novamente? (S/N): ");
        scanf(" %c", &answer);
    }
}

int main() {
    hm_t word_list[MAX_RND];

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    game(word_list);

    return 0;
}
