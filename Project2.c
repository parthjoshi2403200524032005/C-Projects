#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

void encryptFile(const char *inputFilename, const char *outputFilename, const char *key) {
    FILE *inputFile = fopen(inputFilename, "rb");
    FILE *outputFile = fopen(outputFilename, "wb");
    char buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;

    if (!inputFile || !outputFile) {
        printf("Error opening files.\n");
        return;
    }

    size_t keyLength = strlen(key);
    size_t keyIndex = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[keyIndex];
            keyIndex = (keyIndex + 1) % keyLength;
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char *inputFilename, const char *outputFilename, const char *key) {
    encryptFile(inputFilename, outputFilename, key); // Encryption and decryption are symmetric
}

int main() {
    char inputFilename[MAX_FILENAME_LENGTH];
    char outputFilename[MAX_FILENAME_LENGTH];
    char key[MAX_FILENAME_LENGTH];

    printf("Enter input filename: ");
    scanf("%s", inputFilename);
    printf("Enter output filename: ");
    scanf("%s", outputFilename);
    printf("Enter encryption/decryption key: ");
    scanf("%s", key);

    printf("Choose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encryptFile(inputFilename, outputFilename, key);
            printf("File encrypted successfully.\n");
            break;
        case 2:
            decryptFile(inputFilename, outputFilename, key);
            printf("File decrypted successfully.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
