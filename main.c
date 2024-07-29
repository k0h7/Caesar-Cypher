#include <stdio.h>
#include <ctype.h>

const int SIZE = 248;

int userChoice(){
	int choice;

	printf("1. Encrypt\n2. Decrypt\n");
	scanf("%d", &choice);

	return choice;
}

void userMessage(char *message){
	printf("Enter a message: ");
	scanf("%s", message);
}

int userKey(){
	int key;

	printf("Enter a key: ");
	scanf("%d", &key);

	return key;
}

void encrypt(char *message, int key){
	char letter;
	for(int i = 0; message[i] != '\0'; i++){
		letter = message[i];
	
		if(isalnum(letter)){
			if(islower(letter)){
				letter = (letter - 'a' + key) % 26 + 'a';
			}
			if(isupper(letter)){
				letter = (letter - 'A' + key) % 26 + 'A';
			}
			if(isdigit(letter)){
				letter = (letter - '0' + key) % 10 + '0';
			}
		}
		message[i] = letter;
	}

	printf("Encrypted message: %s", message);
}

void decrypt(char *message, int key){
	char letter;
	for(int i = 0; message[i] != '\0'; i++){
		letter = message[i];
		
		if(isalnum(letter)){
			if(islower(letter)){
				letter = (letter - 'a' - key + 26) % 26 + 'a';
			}
			if(isupper(letter)){
				letter = (letter - 'A' - key + 26) % 26 + 'A';
			}
			if(isdigit(letter)){
				letter = (letter - '0' - key + 10) % 10 + '0';
			}
		}
		message[i] = letter;
	}

	printf("Decrypted message: %s", message);
}

void result(int choice, char *message, int key){
	if(choice == 1){
		encrypt(message, key);
	}
	
	if(choice == 2){
		decrypt(message, key);
	}
}


int main(){
	char message[SIZE];
	int key;
	int choice;
	
	choice = userChoice();
	userMessage(message);
	key = userKey();

	result(choice, message, key);

	return 0;
}
