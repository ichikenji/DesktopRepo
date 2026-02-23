//* ARRAYS in C
//. A data structure that can store a fixed-size sequential collection of elements of the same data type.
//. User-defined types (struct/pointers) can be stored in an array.
//. Size of array cannot be changed once declared.
//. When declared, the compiler allocates a continuous block of memory required
//.   to store the declared number of elements.

//* Array Main Properties
//. Collection of same data type
//. Contiguous memory allocation
//. Fixed size
//. Length depends on type
//. Indexing
//. Pointer relationship
//. Lower and Upper Bounds
//. Multi-dimensional arrays
//. Implementation of complex data structures.

//. example: Use of an array
#include <stdio.h>
void func_0() {
    int marks[10] = {50, 55, 67, 73, 45, 21, 39, 70, 49, 51};
    int i, sum = 0;
    int size = (sizeof(marks) / sizeof(int));
    float avg;

    for (i = 0; i <= size; i++)
        sum += marks[i];

    avg = (float) sum / size;
    printf("Average marks from array: %f\n", avg);
}

//. Declaring an array in C
#include <stdio.h>
void func_1() {
    int arr[5], i;
    int size = (sizeof(arr) / sizeof(int));
    for (i = 1; i <= size; i++)
        printf("array[%d] = %d\n", i, arr[i]);
}

//* Fixed Size (Acceptable Ways)
//. #define SIZE = 10;
//. int arr[SIZE];

//. const SIZE = 10;
//. int arr[SIZE];

//. int SIZE = 10;
//. int arr[SIZE];

//* Length Depends on Type
void func_2() {
    int num[10] = {50, 55, 67, 73, 45, 21, 39, 70, 49, 51};
    int size = (sizeof(num) / sizeof(int));

    printf("\n[] Element at lower bound num[0]: %d\n", num[0]);
    printf("[] Element at upper bound num[size - 1]: %d\n", num[size - 1]);
    printf("Length of int array: %llu\n", sizeof(num));

    double nm[10] = {50, 55, 67, 73, 45, 21, 39, 70, 49, 51};
    int size1 = (sizeof(nm) / sizeof(int));
    printf("[] Element at lower bound nm[0]: %f\n", nm[0]);
    printf("[] Element at upper bound nm[size - 1]: %f\n", nm[size1 - 1]);
    printf("Byte length of double array: %llu\n", sizeof(nm));
}

//* Pointer Relationship
void func_3() {
    int num[] = {50, 55, 67, 73, 45};
    int size = sizeof(num) / sizeof(int);
    for (int i = 1; i <= size; i++)
        printf("num[%d]: %d (Memory Address: %p)\n", i, num[i], &num[i]);
}

//* Multi-dimensional Array
void func_4() {
    int arr[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8} };
    int i, j;
    puts("");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}

void func_5() {
    int arr[3][5] = {1,2,3,4,5, 10,20,30,40,50, 5,10,15,20,25};
    int i, j;
    puts("");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

//* Three-dimensional Array
void func_6() {
    int arr[3][3][3] = {
        {
            {11, 12, 13},
            {14, 15, 16},
            {17, 18, 19}
        },
        {
             {21, 22, 23},
             {24, 25, 26},
             {27, 28, 29}
        },
        {
             {31, 32, 33},
             {34, 35, 36},
             {37, 38, 39}
        },
     };
    int i, j, k;
    printf("\n[] Printing 3D Array Elements!\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%5d", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

//* Row-wise Sum of Multidimensional Array Elements
void func_7() {
    int arr[3][5] = {{1,2,3,4,5}, {10,20,30,40,50}, {5,10,15,20,25}};
    int i, j, sum;

    printf("\n[] Printing Sum of Multidimensional Array Elements!\n");
    for (i = 0; i < 3; i++) {
        sum = 0;
        for (j = 0; j < 5; j++) {
            sum += arr[i][j];
        }
        printf("   Sum of row %d: %d\n", i, sum);
    }
}

//* Matrix Multiplication
void func_8() {
    int mat1[3][3] = { {2, 4, 1} , {2, 3, 9} , {3, 1, 8} };
    int mat2[3][3] = { {1, 2, 3} , {3, 6, 1} , {2, 4, 7} };
    int mat3[3][3], sum = 0, i, j, k;

    printf("\n[] Printing Multiplied 3D Array Elements!\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum = 0;
            for (k = 0; k < 3; k++)
                sum += mat1[i][k] * mat2[k][j];
            mat3[i][j] = sum;
        }
    }
    printf("[] Matrix 1 ...\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d\t", mat1[i][j]);
        printf("\n");
    }

    printf("[] Matrix 2 ...\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d\t", mat2[i][j]);
        printf("\n");
    }

    printf("[] Mulitplication of the two given Matrices: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d\t", mat3[i][j]);
        printf("\n");
    }
}

//* Pass array with call by value method
float average(int arr[5]);
void func_9() {
    int arr[] = { 10, 34, 21, 78, 5 };
    float avg = average(arr);
    printf("Average: %f\n", avg);
}
float average(int arr[5]) {
    int i, sum = 0;
    puts("");

    for (i = 0; i < 5; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
        sum += arr[i];
    }
    return (float) sum / 5;
}

//. Another example
int max(int *arr, int length);
void func_10() {
    int arr[] = { 10, 34, 21, 78, 5 };
    int length = sizeof(arr) / sizeof(int);
    int maxnum = max(arr, length);
    printf("Maximum Number: %d\n", maxnum);
}
int max(int *arr, int length) {
    int i, max = *arr;
    puts("");

    for (i = 0; i < length; i++) {
        printf("arr[%d]: %d\n", i, (*arr));
        if ((*arr) > max)
            max = (*arr);
        arr++;
    }
    return max;
}

//. Another example
#include <string.h>
#include <stdio.h>
int compare( char *, char *);
void func_11() {
    char a[] = "Takamura";
    char b[] = "Sendo";
    int result = compare(a, b);
}
int compare( char *x, char *y ) {
    int val;
    if (strlen(x) > strlen(y))
        printf("\n[] Length of string A (%s) is greater than/equal to of string B (%s)!", x, y);
    else
        printf("\n[] Length of string A (%s) is less than length of string B (%s)!", x, y);
}

//* Return Array from Function in C
#include <stdio.h>
#include <math.h>
int arrFunction(int, float *);
void func_12() {
    int x = 100;
    float arr[3];
    arrFunction(x, arr);
    printf("\nSquare of %d: %f\n", x, arr[0]);
    printf("Cube of %d: %f\n", x, arr[1]);
    printf("Square root of %d: %f\n", x, arr[2]);
}
int arrFunction(int x, float *arr) {
    arr[0] = pow(x, 2);
    arr[1] = pow(x, 3);
    arr[2] = pow(x, 0.5);
}

//* Return static array
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int * getRandom();
void func_13() {
    int *pointer, i;
    pointer = getRandom();
    for (i = 0; i < 10; i++)
        printf("*(pointer + %d) : %d\n", i, *(pointer + i));
}
int * getRandom() {
    static int random[10];
    int i;
    // Set the seed
    srand((unsigned) time(NULL));
    for (i = 0; i < 10; ++i) {
        random[i] = rand();
        printf("random[%d] = %d\n", i, random[i]);
    }
    return random;
}

//* Using malloc() Function
//. The malloc() function is available as a library function in <stdlib.h> header.
//. It dynamically allocates a block of memory during the runtime of the program.
//. Normal declaration of variables causes the memory to be allocated at the compile time.
//! void *malloc(size_t size);
//. Returns a generic void pointer.
//. Must be typecast to the required type when assigning values of a certain data type in the allocated memory.
//. E.G. to store an int data, it must be typecast to int * as follows:
//! int *x = (int*) malloc(sizeof(int))

//. Example
#include <math.h>
#include <stdlib.h>
float *arrayFunction(int);
void func_14() {
    int x = 16, i;
    float *arr = arrayFunction(x);
    printf("\nSquare of %d: %f\n", x, arr[0]);
    printf("Cube of %d: %f\n", x, arr[1]);
    printf("Square root of %d: %f\n", x, arr[2]);
}
float *arrayFunction(int x) {
    float *arr = (float*) malloc(3 * sizeof(float));
    arr[0] = pow(x, 2);
    arr[1] = pow(x, 3);
    arr[2] = pow(x, 0.5);
    return arr;
}

//* Using Array Element in struct
struct myStruct {
    float arr[3];
};
struct myStruct myFunction(int x);
void func_15() {
    int x = 9;
    struct myStruct s1 = myFunction(x);
    printf("\nSquare of %d: %f\n", x, s1.arr[0]);
    printf("Cube of %d: %f\n", x, s1.arr[1]);
    printf("Square root of %d: %f\n", x, s1.arr[2]);
}

struct myStruct myFunction(int x) {
    struct myStruct s1;
    s1.arr[0] = pow(x, 2);
    s1.arr[1] = pow(x, 3);
    s1.arr[2] = pow(x, 0.5);
    return s1;
}

//* Return String from Function
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * hellomsg(char *);
void func_16() {
    char *name = "-restart from this night";
    char *arr = hellomsg(name);
    printf("\n%s\n", arr);
}
char * hellomsg(char *x) {
    char *arr = (char*) malloc(50*sizeof(char));
    strcpy(arr, "TONIGHT");
    strcat(arr, x);
    return arr;
}

//+ [ MAIN ] %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main() {
    func_0();
    func_1();
    func_2();
    func_3();
    func_4();
    func_5();
    func_6();
    func_7();
    func_8();
    func_9();
    func_10();
    func_11();
    func_12();
    func_13();
    func_14();
    func_15();
    func_16();

    return 0;
}