//* [3.1.1] Variable Names
//! [] You can't start a variable with a digit 0-9.
//! [] You can't start a variable name with two underscores.
//! [] You can't start a variable name with an underscore followed by a capital A-Z.

//* [3.1.2] Variable Types
#include <stdio.h>
void func_0(void) {
    int i = 2;
    float f = 3.14;
    char *s = "Hello world!";

    printf("%s i = %d and f = %f!\n", s, i, f);
}

#include <stdbool.h>
void func_1() {
    bool x = false;
    float y = 3.14;

    if ((x) && (y))
        printf("Both x and y are true! :)");
    else
        printf("Both x and y aren't true! :(\n");

    printf("Output: %d (true = 0)\n", true == 12);
}

//* [3.2.2] Ternary Operator
//. An expression whose value depends on the result of a conditional embedded in it.
void func_2() {
    // example 1
    int x = 4;
    int y = 6;

    y += x > 10? 17: 37;    // If x > 10, add 17 to y (23). Otherwise, add 37 to y (43).
    printf("\nOutput: %d", y);

    // example 2
    int z = 7;
    printf("\nThe number %d is %s.", z, z % 2 == 0? "even": "odd");
}

//* [3.2.3] Pre-and-Post Increment-and-Decrement
//. i++;     - Add one to i (post-increment)
//. i--;     - Subtract one from i (post-decrement)
//. i += 1;  - Add one to i
//. i -= 1;  - Subtract one from i
//. ++i;     - Add one to i (pre-increment)
//. --i;     - Subtract one from i (pre-decrement)
void func_3() {
    // example 1
    int i = 10;
    int j = 5 + i++;
    printf("\nOutput: i = %d, j = %d", i, j);

    // example 2
    int a = 10;
    int b = 5 + ++a;
    printf("\n\nOutput: a = %d, b = %d\n", a, b);

    // example 3
    for (int i = 0; i < 10; i++)
        printf("i = %d | ", i);
}

//* [3.2.4] The COMMA operator
void func_4() {
    int x = (1, 2, 3);
    printf("\n\nx is %d\n", x);   // Prints 3, because 3 is rightmost in the comma list.

    for (int i = 0, j = 10; i < 100; i++, j++)
        printf("i = %d, j = %d\n", x, j);
}

//* [3.2.7] The SIZEOF operator
void func_5() {
    int a = 777;
    // %zu is the format specifier for type size_t.
    // %zd to print out negative size_t values.
    // if your compiler balks at the "z" part, leave it off.
    printf("\nSize of a: %zu bytes\n", sizeof a);
    printf("Size of a: %zu bytes\n", sizeof(2 + 7));
    printf("Size of a: %zu bytes\n", sizeof 3.14);
    printf("Size of int: %zu", sizeof(int));
    printf("\nSize of char: %zu", sizeof(char));
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
void func_5_1() {
    //. This operator tells you the size (in bytes) that a particular variable/data type uses in memory.
    //. [TYPE]          [MEMORY SIZE]   [RANGE]
    //. char            1 byte          -128 to 127 or 0 to 255
    //. unsigned char   1 byte          0 to 255
    //. signed char     1 byte          -128 to 127
    //. int             2 or 4 bytes    -32,768 to 32,767
    //. unsigned int    2 or 4 bytes    0 to 65,535
    //. short            2 bytes        -32,768 to 32,767
    //. unsigned short   2 bytes        0 to 65,535
    //. (unsigned) long  8 bytes
    //. float            4 bytes        6 decimal places
    //. double           8 bytes        15 decimal places
    //. long double      10 bytes       19 decimal places
    printf("\n\nCHAR_BIT  :   %d", CHAR_BIT);
    printf("\nCHAR_MIN  :   %d", CHAR_MIN);
    printf("\nCHAR_MAX  :   %d", CHAR_MAX);
    printf("\nINT_MIN   :   %d", INT_MIN);
    printf("\nINT_MAX   :   %d", INT_MAX);
    printf("\nLONG_MIN  :   %ld", (long) LONG_MIN);
    printf("\nLONG_MAX  :   %ld", (long) LONG_MAX);
    printf("\nSCHAR_MIN :   %d", SCHAR_MIN);
    printf("\nSCHAR_MAX :   %d", SCHAR_MAX);
    printf("\nSHRT_MIN  :   %d", SHRT_MIN);
    printf("\nSHRT_MAX  :   %d", SHRT_MAX);
    printf("\nUCHAR_MAX  :   %d", UCHAR_MAX);
    printf("\nUINT_MAX  :   %u", (unsigned int) UINT_MAX);
    printf("\nULONG_MAX  :   %lu", (unsigned long) ULONG_MAX);
    printf("\nUSHRT_MAX  :   %d", (unsigned short) SHRT_MAX);
}

//* [3.3] Flow Control
void func_6() {
    int x = 10;
    int y = 21;
    if (x == 10) printf("\n\nx is 10!");
    (y == 20) ? printf("\ny is 20!") : printf("\ny is not 20!\n");
}

//* [3.3.3] do-while statement
#include <stdlib.h>     // for rand()
#include <stdio.h>      // for printf()
void func_7() {
    int i = 10;
    // using a while statement.
    //. not executed because i is not less than 10.
    while (i < 10) {
        printf("while: i is %d\n", i);
        i++;
    }
    //. This is executed once, because the loop condition is not checked until
    //. after the body of the loop runs:
    //. To execute a loop at least once, no matter the loop condition, use do-while.
    do {
        printf("do-while: i is %d\n", i);
        i++;
    } while (i < 10);
    printf("All done :D\n");

    // example
    int r;
    int count = 1;
    do {
        r = rand() % 100;   // get a random number between 0 and 99.
        printf("Round %d - Random number: %d\n", count, r);
        count++;
    } while (r != 37);
    printf("THE REFEREE HAS SIGNALLED A STOP! THE MATCH IS OVER!!!\n\n");
}

//* 3.3.4 The FOR statement
void func_8() {
    for (;;) {
        printf("\nI will print this again and again and again\n");
        printf("for all eternity until the head-death of the universe.");
        printf("Or until you hit CTRL-C.");
    }
}

//* 3.3.5 The SWITCH statement
void func_9() {
    int goat_count = 2;
    switch (goat_count) {
        case 0:
            printf("You have no goats.\n"); break;
        case 1:
            printf("You have a singular goat.\n"); break;
        case 2:
            printf("You have a brace of goats.\n"); break;
        default:
            printf("You have a bona fide plethora of goats!\n"); break;
    }
    char name = 'i';
    switch (name) {
        case 't': printf("Mamoru Takamura!"); break;
        case 's' : printf("Takeshi Sendo!"); break;
        case 'i': printf("Makunouchi Ippo!"); break;
        default: printf("Prepare for death - The Dempsey Roll!"); break;
    }
}

//+ [ MAIN ] %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main() {
    func_0();
    func_1();
    func_2();
    func_3();
    func_4();
    func_5();
    func_5_1();
    func_6();
    func_7();
    // func_8();    // the forbidden function.
    func_9();

    return 0;
}
