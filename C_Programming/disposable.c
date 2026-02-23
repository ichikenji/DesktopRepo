#include <stdio.h>
#include <stdlib.h>

// %%%%%%%%%%%%%%%%%%%%%%%% (1) %%%%%%%%%%%%%%%%%%%%%%%%
void printSymbol(char symbol, unsigned int count) {
    for (int i = 0; i < count; i++)
        printf("%c", symbol);
    printf("\n");
}
void printWelcomeMsg() {
    printSymbol('%', 53);
    printf("|   Welcome to the UNIX C Programming Environment   |\n");
    printSymbol('%', 53);
    puts("");
}
// %%%%%%%%%%%%%%%%%%%%%%%% (1) END %%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%% (3.a) %%%%%%%%%%%%%%%%%%%%%%%%
void printPersonalInfo(char first[], char last[], unsigned int age) {
    printSymbol('-', 45);
    printf("-----\t\tUSER DETAILS\t\t-----\n");
    printSymbol('-', 45);

    printf("[+] Name: %s %s  | Age: %u\n", first, last, age);
    printf("[!] Welcome to the UNIX C Programming Environment, %s!\n", first);
}
int readInputKeyboard(char first[], char last[], unsigned int *age) {
    while (1) {
        printSymbol('-', 45);
        printf("-----\t\tInstructions\t\t-----\n");
        printSymbol('-', 45);

        printf("[+] Enter your first name, last name, and age\n");
        printf("[+] Example Format: Leonardo Dicaprio 21\n");
        printf("[*] Enter here: ");
        if (scanf("%49s %49s %u", first, last, age) == 3) {
            printPersonalInfo(first, last, *age);
            return 0;
        }
        printf("[!] Invalid format. Please try again.\n\n");
        int clear;
        while ((clear = getchar()) != '\n');
    }
}
// %%%%%%%%%%%%%%%%%%%%%%%% (3.a) END %%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%% (3.b) %%%%%%%%%%%%%%%%%%%%%%%%
int readInputFile(char first[], char last[], unsigned int *age) {
    FILE *file_in = fopen("data.txt", "r");
    if (!file_in) {
        perror("data.txt");
        return 1;
    }
    if (fscanf(file_in, "%49s %49s %u", first, last, age) != 3) {
        printf("\n[!] An error has occurred. File format error?");
        fclose(file_in);
        return 1;
    }
    fclose(file_in);
}

int main(int argc, char *argv[]) {
    printWelcomeMsg();  // --- (1)

    for (int i = 1; i < argc; i++)  // --- (2)
        printf("%s ", argv[i]);
    printf("\n");

    char first[50], last[50];   // --- (3.a)
    unsigned int age;
    readInputKeyboard(first, last, &age);


    return 0;
}