#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// Definição de constantes
#define MAX_SIZE 4096
#define MAX_RND countLines("words.txt")
#define MAX_ATTEMPTS 6
#define SINGLE_PLAYER 1
#define MULTI_PLAYER 2

// Definição da estrutura de dados para armazenar palavras e temas
typedef struct HangmanData {
    char word[MAX_SIZE];
    char theme[MAX_SIZE];
} hm_t;

// Protótipos de funções
int fileExists(const char *filename);
int countLines(const char *filename);
void savedWords(hm_t **word_list, int *num_words);

void defineGamemode(int *gamemode);
void defineMaxRound(int *maxRound);
void readPlayerWords(hm_t *word_list);

int rand_num();

void showTheme(hm_t *word_list, int num);
void hideLetters(hm_t *word_list, int num, char *hidden);
int checkLetter(char letter, char *guessedLetters, int attempts);

void printHangman(int attempts);
void playGame(hm_t *word_list, int gamemode);

int main() {
    // Inicialização de variáveis
    hm_t *word_list = NULL;
    int num_words = 0;

    // Configuração da localidade e semente do gerador de números aleatórios
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    // Variável para armazenar o modo de jogo escolhido pelo usuário
    int gamemode = 0;
    defineGamemode(&gamemode);

    // Verificação se o arquivo "words.txt" pode ser aberto
    if(MAX_RND == -1) {
        printf("Erro ao abrir o arquivo words.txt\n");
        return 1;
    }

    // Carregamento de palavras com base no modo de jogo escolhido
    if(gamemode == SINGLE_PLAYER)
        savedWords(&word_list, &num_words);
    else if(gamemode == MULTI_PLAYER)
        readPlayerWords(word_list);

    // Início do jogo
    playGame(word_list, gamemode);

    // Liberação de memória alocada
    free(word_list);

    return 0;
}

// Função para verificar se um arquivo existe
int fileExists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}

// Função para contar o número de linhas em um arquivo
int countLines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(!file) {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return -1;
    }

    // Contagem das linhas no arquivo
    int count = 0;
    char c;
    while((c = fgetc(file)) != EOF)
        if(c == '\n')
            count++;

    fclose(file);
    return count;
}

// Função para carregar palavras salvas de um arquivo
void savedWords(hm_t **word_list, int *num_words) {
    if(!fileExists("words.txt")) {
        printf("O arquivo words.txt não existe");
        return;
    }

    FILE *file = fopen("words.txt", "r");

    // Leitura de linhas do arquivo e extração de temas e palavras
    char line[MAX_SIZE];
    *num_words = 0;
    while(fgets(line, sizeof(line), file)) {
        char *theme = strtok(line, ";");
        char *word = strtok(NULL, "\n");

        if(theme && word) {
            // Alocação ou realocação de memória para a lista de palavras
            if(*num_words == 0)
                *word_list = malloc(sizeof(hm_t));
            else
                *word_list = realloc(*word_list, (*num_words + 1) * sizeof(hm_t));

            if(*word_list == NULL) {
                printf("Erro ao alocar memória.\n");
                return;
            }

            // Cópia de tema e palavra para a estrutura de dados
            strcpy((*word_list)[*num_words].theme, theme);
            strcpy((*word_list)[*num_words].word, word);
            (*num_words)++;
        }
    }
    fclose(file);
}

// Função para definir o modo de jogo (single ou multiplayer)
void defineGamemode(int *gamemode) {
    int maxInputTry = 0;
    do {
        // Solicitação do modo de jogo ao usuário
        printf("Digite o modo de jogo\n");
        printf("1 - Palavras salvas (1 jogador) | 2 - Palavras digitadas (2 jogadores): ");
        scanf(" %d", gamemode);

        // Validação de entrada
        if (*gamemode != 1 && *gamemode != 2) {
            printf("Digite um número válido.\n");
            maxInputTry++;
        }
        if (maxInputTry > 3) {
            printf("Você excedeu o número máximo de tentativas.\n");
            exit(1);
        }
    } while(*gamemode != 1 && *gamemode != 2);
}

// Função para definir o número máximo de rodadas
void defineMaxRound(int *maxRound) {
    do {
        // Solicitação do número máximo de rodadas ao usuário
        printf("Digite o número máximo de rodadas (1 a %d): ", MAX_RND);
        scanf("%d", maxRound);

        // Validação de entrada
        if (*maxRound < 1 || *maxRound > MAX_RND)
            printf("Digite um número válido.\n");
    } while(*maxRound < 1 || *maxRound > MAX_RND);
}

// Função para coletar palavras digitadas pelo jogador
void readPlayerWords(hm_t *word_list) {
    int maxRound;
    defineMaxRound(&maxRound);

    // Loop para coletar palavras e temas digitados pelo jogador
    for(int i = 0; i < maxRound; i++) {
        printf("Digite a palavra da rodada %d: ", i + 1);
        scanf("%s", word_list[i].word);

        printf("Digite o tema da rodada %d: ", i + 1);
        scanf("%s", word_list[i].theme);
    }
}

// Função para gerar um número aleatório entre 0 e MAX_RND
int rand_num() {
    return rand() % MAX_RND;
}

// Função para exibir o tema da rodada
void showTheme(hm_t *word_list, int num) {
    printf("\nTema: %s\n", word_list[num].theme);
}

// Função para ocultar letras não adivinhadas
void hideLetters(hm_t *word_list, int num, char *hidden) {
    int size = strlen(word_list[num].word);

    // Loop para exibir letras ou espaços ocultos
    for(int i = 0; i < size; i++)
        printf("%c ", hidden[i]);
}

// Função para verificar se uma letra já foi adivinhada
int checkLetter(char letter, char *guessedLetters, int attempts) {
    // Loop para verificar se a letra já foi adivinhada
    for(int i = 0; i < attempts; i++)
        if(guessedLetters[i] == letter)
            return 1;
    return 0;
}

// Função para imprimir o estado atual do enforcado
void printHangman(int attempts) {
    // Switch para imprimir mensagens com base no número de tentativas
    switch(attempts){
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

// Função principal para jogar o jogo
void playGame(hm_t *word_list, int gamemode) {
    char answer = 'S';

    // Loop principal do jogo
    while(answer == 'S' || answer == 's') {
        int attempts = 0, num = rand_num();

        // Exibe o tema da rodada
        showTheme(word_list, num);

        int size = strlen(word_list[num].word);
        char hidden[size];

        // Inicializa as letras ocultas
        for(int i = 0; i < size; i++) {
            if(word_list[num].word[i] == ' ')
                hidden[i] = ' ';
            else
                hidden[i] = '_';
        }

        int correct = 0;
        char guessedLetters[MAX_ATTEMPTS];

        // Exibe o estado atual do enforcado
            for(int i = 0; i < size; i++)
                printf("%c ", hidden[i]);

        // Loop principal do jogo enquanto há tentativas disponíveis
        while(attempts < MAX_ATTEMPTS) {
            char inputLetter;

            // Solicitação de uma letra ao jogador
            printf("\n\nDigite uma letra: ");
            scanf(" %c", &inputLetter);
            int c;

            // Limpa o buffer de entrada
            while((c = getchar()) != '\n' && c != EOF);

            // Validação de entrada: a letra deve ser uma letra do alfabeto
            if((inputLetter >= 'a' && inputLetter <= 'z') || (inputLetter >= 'A' && inputLetter <= 'Z')) {
                // Verifica se a letra já foi digitada
                if(checkLetter(inputLetter, guessedLetters, attempts)) {
                    printf("\nVocê já digitou essa letra. Tente outra.\n");
                    continue;
                }

                guessedLetters[attempts] = inputLetter;

                int found = 0;

                // Loop para verificar se a letra está na palavra
                for(int i = 0; i < size; i++) {
                    if(word_list[num].word[i] == ' ') {
                        hidden[i] = ' ';
                        printf("%c ", hidden[i]);
                        continue;
                    }

                    // Verifica se a letra está na palavra
                    if(inputLetter == word_list[num].word[i] || inputLetter == word_list[num].word[i] + 32) {
                        hidden[i] = word_list[num].word[i];
                        found = 1;
                    }
                    printf("%c ", hidden[i]);
                }

                // Verifica se todas as letras foram adivinhadas
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

        // Verifica se o jogador perdeu
        if(attempts == MAX_ATTEMPTS) {
            printf("\n\nVocê perdeu!\n");
            printf("A palavra era: %s\n", word_list[num].word);
        }

        printf("\n\n");

        // Pergunta se o jogador deseja jogar novamente
        printf("Deseja jogar novamente? (S/N): ");
        scanf(" %c", &answer);
    }
}