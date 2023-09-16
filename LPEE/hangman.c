#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_SIZE 4096
#define MAX_RND 10
#define MAX_ATTEMPTS 6

typedef struct hangman_data {
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

void defineGamemode(int *gamemode) {
    int maxInputTry = 0;
    do {
        printf("Digite o modo de jogo\n");
        printf("1 - Palavras salvas (1 jogador) | 2 - Palavras digitadas (2 jogadores): ");
        scanf(" %d", gamemode);

        if(*gamemode != 1 && *gamemode != 2) {
            printf("Digite um número válido.\n");
            maxInputTry++;
        }
        if(maxInputTry > 3) {
            printf("Você excedeu o número máximo de tentativas.\n");
            exit(1);
        }
    } while(*gamemode != 1 && *gamemode != 2);
}

void defineMaxRound(int *maxRound) {
    do {
        printf("Digite o número máximo de rodadas (1 a %d): ", MAX_RND);
        scanf("%d", maxRound);

        if(*maxRound < 1 || *maxRound > MAX_RND)
            printf("Digite um número válido.\n");
    } while(*maxRound < 1 || *maxRound > MAX_RND);
}

void readPlayerWords(hm_t *word_list) {
    int maxRound;    
    defineMaxRound(&maxRound);

    for(int i = 0; i < maxRound; i++) {
        printf("Digite a palavra da rodada %d: ", i + 1);
        scanf("%s", word_list[i].word);

        printf("Digite a tema da rodada %d: ", i + 1);
        scanf("%s", word_list[i].theme);
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

int checkLetter(char letter, char *guessedLetters, int attempts) {
    for(int i = 0; i < attempts; i++)
        if(guessedLetters[i] == letter)
            return 1;
    return 0;
}

void printHangman(int attempts) {
    switch(attempts) {
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

void game(hm_t *word_list) {
    char answer = 'S';
    int gamemode = 0;
        
    while(answer == 'S' || answer == 's') {
        int attempts = 0, num = rand_num(); 

        if(gamemode == 0)
            defineGamemode(&gamemode);
        if(gamemode == 1)
            savedWords(word_list);
        if(gamemode == 2)
            readPlayerWords(word_list);
        
        showTheme(word_list, num);

        int size = strlen(word_list[num].word);
        char hidden[size];
        for(int i = 0; i < size; i++)
            hidden[i] = '_';

        hideLetters(word_list, num, hidden);

        int correct = 0;
        char guessedLetters[MAX_ATTEMPTS];
        while(attempts < MAX_ATTEMPTS) {
            char letter;
            printf("\n\nDigite uma letra: ");
            scanf(" %c", &letter);
            int c;
            while((c = getchar()) != '\n' && c != EOF);

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
                    printHangman(attempts);
                }
            } else {
                printf("\nDigite uma letra válida.\n");
            }
        }

        if(attempts == MAX_ATTEMPTS) {
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