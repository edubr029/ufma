#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <locale.h>

#define MAX_SIZE 1024

#define MAX_CHAR 8
#define MAX_USR 10

#define MIN_PASSWD_LENGTH 8
#define MAX_PASSWD_LENGTH 20

typedef struct user_info {
    char username[MAX_SIZE];
    char passwd[MAX_SIZE];
} login_t;

int readPassword(char *password) {
	const int fd = fileno(stdin);
	
	if(fd == -1)
		return -1;
	
	struct termios attributes = {0};
	
	if(tcgetattr(fd, &attributes) == -1)
		return -1;
	
	// Faça uma cópia dos atributos originais com o propósito de restaurá-los mais tarde
	struct termios attributes_copy = attributes;
	
	cfmakeraw(&attributes);
	
	attributes.c_cc[VTIME] = 0;
	attributes.c_cc[VMIN] = 1;
	
	if(tcsetattr(fd, TCSAFLUSH, &attributes) == -1)
		return -1;
	
	if(fflush(stdin) == EOF)
		return -1;
	
	char input;
	
	while(1) {
		const ssize_t size = read(fd, &input, 1);
		
		if(size == -1)
			return -1;
		
		if(input == 13)
			break;
		
		if(input == 127) {
			password[strlen(password)-1] = '\0';
			printf("\b \b");
			fflush(stdout);
			continue;
		}
		
		strncat(password, &input, 1);
		
		const int fd = fileno(stdout);
		if(write(fd, "*", 1) == -1)
			return -1;
		
		fflush(stdout);
	}
	
	// Restaure o stdin ao que era antes
	if(tcsetattr(fd, TCSAFLUSH, &attributes_copy) == -1)
		return -1;
	
	printf("\n");

	int isValid = 1;
	for(int i = 0; i < strlen(password); i++) {
		if(!isalnum(password[i])) {
			isValid = 0;
			break;
		}
	}
	if(!isValid) {
		printf("A senha deve conter apenas caracteres alfanuméricos.\n");
		return -1;
	}

	int hasNumber = 0;
	for(int i = 0; i < strlen(password); i++) {
		if(isdigit(password[i])) {
			hasNumber = 1;
			break;
		}
	}
	if(!hasNumber) {
		printf("A senha deve conter pelo menos um número.\n");
		return -1;
	}
	
	int password_length = strlen(password);
	if (password_length < MIN_PASSWD_LENGTH || password_length > MAX_PASSWD_LENGTH) {
		fflush(stdout);
		printf("A senha deve ter entre %d e %d caracteres.\n", MIN_PASSWD_LENGTH, MAX_PASSWD_LENGTH);
		return -1;
	}
	
	return 0;
}

int main() {
    login_t usr[MAX_USR];
	char password[MAX_SIZE] = {'\0'};

    setlocale(LC_ALL, "Portuguese");

    if(readPassword(password) == -1) {
		printf("Ocorreu um erro ao ler a senha.\n");
		return -1;
	}

	printf("A senha é: %s\n", password);
    
    return 0;
}