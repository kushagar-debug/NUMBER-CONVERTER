#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert Decimal to Binary
void decimalToBinary(int num) {
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    int binary[32], i = 0;
    while (num > 0) {
        binary[i++] = num % 2;
        num /= 2;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    printf("\n");
}

// Function to convert Decimal to Octal
void decimalToOctal(int num) {
    if (num == 0) {
        printf("Octal: 0\n");
        return;
    }

    int octal[32], i = 0;
    while (num > 0) {
        octal[i++] = num % 8;
        num /= 8;
    }

    printf("Octal: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", octal[j]);
    printf("\n");
}

// Function to convert Decimal to Hexadecimal
void decimalToHex(int num) {
    if (num == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    char hex[32];
    int i = 0;
    while (num > 0) {
        int rem = num % 16;
        hex[i++] = (rem < 10) ? rem + '0' : rem - 10 + 'A';
        num /= 16;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
    printf("\n");
}

void showMenu() {
    int choice;
    int number;

    while (1) {
        printf("\n--- Number System Converter ---\n");
        printf("1. Decimal to Binary\n");
        printf("2. Decimal to Octal\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter a Decimal number: ");
        if (scanf("%d", &number) != 1 || number < 0) {
            printf("Invalid number! Only positive integers allowed.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                decimalToBinary(number);
                break;
            case 2:
                decimalToOctal(number);
                break;
            case 3:
                decimalToHex(number);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    showMenu();
    return 0;
}
