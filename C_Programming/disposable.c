#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char first[50], last[20];
    unsigned int age;
} User;

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
void printKeyboardMenu() {
    printSymbol('-', 45);
    printf("-----\t\tInstructions\t\t-----\n");
    printSymbol('-', 45);

    printf("[+] Enter your first name, last name, and age.\n");
    printf("[+] Example Format: Leonardo Dicaprio 21\n");
    printf("\n[*] Enter here: ");
}

int readInputKeyboard(User *user) {
    while (1) {
        printKeyboardMenu();
        if (scanf("%49s %49s %u", user->first, user->last, &user->age) == 3) {
            printPersonalInfo(user->first,user->last, user->age);
            return 0;
        }
        printf("[!] Invalid format. Please try again.\n\n");
        int clear;
        while ((clear = getchar()) != '\n' && clear != EOF);
    }
}
// %%%%%%%%%%%%%%%%%%%%%%%% (3.a) END %%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%% (3.b) %%%%%%%%%%%%%%%%%%%%%%%%
void createInputFile(char file_name[]) {
    printf("[!] Creating new file: %s\n", file_name);
    FILE *file = fopen(file_name, "w");
    if (file) {
        fprintf(file, "Mamoru Takamura 31\n");
        fclose(file);
    }
    printf("[!] New file created: %s\n", file_name);
}
int reopenInputFile(FILE **file_in, char file_name[]) {
    *file_in = fopen(file_name, "r");
    if (!*file_in) {
        printf("\n[!] Failed to open file %s even after creation\n", file_name);
        return 1;
    }
    return 0;
}

char checkInputFileFormat(FILE *file_in, User *user) {
    if (fscanf(file_in, "%49s %49s %u", user->first, user->last, &user->age) != 3) {
        printf("\n[!] File format error\n");
        return 1;
    }
    return 0;
}

User readInputFile(char file_name[]) {
    User user = {"", "", 0};

    FILE *file_in = fopen(file_name, "r");

    if (!file_in) {
        printf("\n[!] CRITICAL ERROR\n |  \"%s\": No such file or directory\n", file_name);
        createInputFile(file_name);

        if (reopenInputFile(&file_in, file_name) != 0)
            return user;
    }
    if (checkInputFileFormat(file_in, &user) != 0) {
        fclose(file_in);
        return user;
    }

    printf("\nReading input from %s... [STATUS: OK]\n", file_name);
    fclose(file_in);
    return user;
}
// %%%%%%%%%%%%%%%%%%%%%%%% (3.b END) %%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%% (3.c) %%%%%%%%%%%%%%%%%%%%%%%%
void printBanner() {
    printSymbol('=', 45);
    printf("-----\t\tMODIFIED DATA\t\t-----\n");
    printSymbol('=', 45);
}

void printOriginalInput(User user1, User user2) {
    printf("[BEFORE] --- \n");
    printf("[+] Current User: %s %s | Age: %u\n", user1.first, user1.last, user1.age);
    printf("[+]    File User: %s %s | Age: %u\n", user2.first, user2.last, user2.age);
}

void printModifiedInput(User user1, User user2, int years) {
    printf("\n[UPDATED] --- \n");
    printf("[+] Current User: %s %s | New age: %u  (+%d years)\n", user1.first, user1.last, user1.age, years);
    printf("[+]    File User: %s %s | New age: %u  (+%d years)\n", user2.first, user2.last, user2.age, years);
}

void modifyInput(User *user1, User *user2, int years) {
    printBanner();
    printOriginalInput(*user1, *user2);
    user1->age += years;
    user2->age += years;
}
// %%%%%%%%%%%%%%%%%%%%%%%% (3.c END) %%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%% (3.d) %%%%%%%%%%%%%%%%%%%%%%%%
void printFormattedOutput(User *user1, User *user2, int years) {
    printModifiedInput(*user1, *user2, years);
}
// %%%%%%%%%%%%%%%%%%%%%%%% (3.d END) %%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%% (3.e) %%%%%%%%%%%%%%%%%%%%%%%%
void writeModifiedDataToFile(char file_name[], User *user1, User *user2, int years) {
    FILE *file_out = fopen(file_name, "w");
    if (file_out) {
        fprintf(file_out, "[MODIFIED] Current User: %s %s, age %u  (+%d years)\n", user1->first, user1->last, user1->age, years);
        fprintf(file_out, "[MODIFIED] File User: %s %s, age %u  (+%d years)\n", user2->first, user2->last, user2->age, years);
        fclose(file_out);
    }
    printf("\n[!] Modified data saved to %s.", file_name);

}
// %%%%%%%%%%%%%%%%%%%%%%%% (3.e END) %%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%% MAIN %%%%%%%%% MAIN %%%%%%%%% MAIN %%%%%%%%% MAIN %%%%%%%%% MAIN %%%%%%%%%
int main(int argc, char *argv[]) {
    char data_file[] = "input.txt", output_file[] = "output.txt";
    int years = 10;

    printWelcomeMsg();  // --- (1)

    for (int i = 1; i < argc; i++)  // --- (2)
        printf("%s ", argv[i]);
    printf("\n");

    User current_user;   // --- (3.a)
    readInputKeyboard(&current_user);

    User file_user = readInputFile(data_file);     // --- (3.b)

    modifyInput(&current_user, &file_user, years);     // --- (3.c)

    printFormattedOutput(&current_user, &file_user, years);     // --- (3.d)

    writeModifiedDataToFile(output_file, &current_user, &file_user, years);     // --- (3.e)

    return 0;
}