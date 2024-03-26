#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + key) % 26;
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + key) % 26;
        }
    }
}

void decrypt(char message[], int key) {
    encrypt(message, 26 - key); 
}

int main() {
    char message[100];
    int key;

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key (an integer between 0 and 25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}