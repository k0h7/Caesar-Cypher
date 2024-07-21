#include <stdio.h>
#include <ctype.h>

int main(){
	char word[400];
	char letter;
	int key;
	int choice;
	
	printf("1. Encrypt\n2. Decrypt\n");
	scanf("%d", &choice);
	
	printf("Enter a message: ");
	scanf("%s", word);
	
	printf("Enter a key: ");
	scanf("%d", &key);
	
	if(choice == 1){
		for(int i = 0; word[i] != '\0'; i++){
			letter = word[i];
		
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
			else{
				printf("YOU IDIOT");
			}
			
			word[i] = letter;
		}
		printf("Encrypted message: %s", word);
	}
	
	if(choice == 2){
		for(int i = 0; word[i] != '\0'; i++){
		letter = word[i];
		
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
			word[i] = letter;
		}
		printf("Decrypted message: %s", word);
	}
}