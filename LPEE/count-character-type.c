#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 128
#define VOWELS "aeiouáéíóúAEIOUÁÉÍÓÚ"

// Estrutura para armazenar as contagens de diferentes tipos de caracteres
typedef struct {
    int vowels;     // Contagem de vogais
    int consonants; // Contagem de consoantes
    int numbers;    // Contagem de números
    int specials;   // Contagem de caracteres especiais
} Counts;

// Função para verificar se um caractere é uma vogal
bool isVowel(char c){
    // Retorna verdadeiro se o caractere estiver na string VOWELS
    return strchr(VOWELS, c) != NULL;
}

// Função para atualizar as contagens de diferentes tipos de caracteres
void updateCounts(char c, Counts* counts){
    // Se o caractere for um dígito, incrementa a contagem de números
    if(isdigit(c))
      counts->numbers++;
    // Verifica se é um caractere alfanumérico
    else if(isalpha(c)) {               
      if(isVowel(c)) counts->vowels++;  // Se for uma vogal, incrementa a contagem de vogais
      else counts->consonants++;        // Se não for uma vogal (ou seja, é uma consoante), incrementa a contagem de consoantes
    }
    // Se o caractere não for alfanumérico nem espaço em branco nem nova linha, incrementa a contagem de caracteres especiais
    else if(!isalnum(c) && c != ' ' && c != '\n')
      counts->specials++; 
}

// Função para contar os diferentes tipos de caracteres em uma string
void countCharacterTypes() {
  char str[MAX_SIZE];  // String para armazenar a entrada do usuário
  Counts counts = {0}; // Inicializa as contagens
  
  printf("Insira uma string: ");
  if(fgets(str, MAX_SIZE, stdin) == NULL) {
      // Lê a string do usuário. Se houver um erro, imprime uma mensagem e retorna.
      printf("Erro ao ler a string.\n");
      return;
  }
  
  // Loop através da string do usuário e atualiza as contagens para cada caractere
  for(int i = 0; str[i] != '\0' && i < MAX_SIZE; i++)
    updateCounts(str[i], &counts);
  
  // Imprime as contagens
  printf("Número de vogais: %d\n", counts.vowels);
  printf("Número de consoantes: %d\n", counts.consonants);
  printf("Número de caracteres especiais: %d\n", counts.specials);
}

// Função para perguntar ao usuário se ele deseja reiniciar o programa
bool askRestart() {
    char restart[4]; // String para armazenar a resposta do usuário
    
    printf("Você deseja reinicar o programa?\n");
    printf("Sim (S/s) | Não (N/n): ");
    
    if(scanf("%3s", restart) != 1){ // Lê a resposta do usuário. Se houver um erro, imprime uma mensagem e retorna falso.
        printf("Erro ao ler a entrada.\n");
        return false;
    }
    
    while((getchar()) != '\n'); // Limpa o buffer de entrada
    
    if(strcmp(restart, "s") != 0 && strcmp(restart, "n") != 0 && strcmp(restart, "sim") != 0 && strcmp(restart, "não") != 0){ 
      // Se a entrada do usuário não for válida, imprime uma mensagem e retorna verdadeiro.
      printf("Opção Inválida! Tente novamente.\n");
      return true;
    }
    
    return strcmp(restart, "s") == 0 || strcmp(restart, "sim") == 0; // Retorna verdadeiro se o usuário quiser reiniciar o programa.
}

int main(){
  setlocale(LC_ALL, "Portuguese"); // Define o locale para Português

  do{
    countCharacterTypes(); // Conta os diferentes tipos de caracteres na string do usuário
  } while(askRestart());   // Pergunta ao usuário se ele deseja reiniciar o programa. Se sim, repete o processo.

  return 0;
}
