#include <stdio.h> // Header file that has a C compiler
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Note: If you want to include your own header file, use quotations
// instead of <>

// Note: If there is an asterisks (*), it's a pointer

/*
    NOTES:
    - Local variables declared inside of a function 
      are allocated memory in the STACK
    - Malloc function allocates space in the HEAP

    HOW CODE TURNS INTO A RUNABLE PROGRAM:
    Stage 1: The Preprocessor
             - Handles commands with hash characters (#)
    Stage 2: The Compiler
             - Creates intermediate object files to prepare code for stage 3
    Stage 3: The Linker
             - Puts the code together into an executable file
             - Allows the program to run on the operating system
    
    static function = private 
    static local variable = keeps their value after changes even after 
    exiting the function

*/

// #define MAXSTRLEN 100
// char greeting[MAXSTRLEN];

// char* string_function_using_maxstrlen(char s[]) {
//     strcat(greeting, "hello ");
//     strcat(greeting, s);
//     strcat(greeting, "\n");
//     return greeting;
// }

// char* string_function(char s[]) {
//     char* result = malloc(strlen(s) + 1);  //plus 1 because C adds a null after each string
//     strcpy(result, s);
//     strcat(result, " Louie");
//     return result;
// }

// ******************************************************************************

// char mystring[] = "T12";

// void chartypes() {
//     int i;
//     char c;
//     int numDigits = 0;
//     int numLetters = 0;

//     for (i = 0; i < strlen(mystring); i++) {
//         if (isdigit(mystring[i])) {
//             numDigits++;
//         }
//         else if (isalpha(mystring[i])){
//             numLetters++;
//         }
//     }

//     printf("numDigits = %d, numLetters = %d\n", numDigits, numLetters);
// }

// *****************************************************************************

// #define NUMBER_OF_CDS 2

// struct cd {
//     char name[50];
//     int rating;
// };

// enum score {
//     Terrible, Bad, Average, Good, Excellent 
//     // 0       1      2      3       4
// };

// // USING TYPEDEF
// typedef char Str50[50];

// typedef struct cd {
//     Str50 name;
//     enum score rating;
// } CD;

// CD cd_collection[NUMBER_OF_CDS];

// // struct cd cd_collection[NUMBER_OF_CDS];

// void create_cdcollection() {
//     strcpy(cd_collection[0].name, "Stream of Praise");
//     cd_collection[0].rating = Excellent;

//     strcpy(cd_collection[1].name, "Amazing Grace");
//     cd_collection[1].rating = Good;
// }

// void display_cdcollection() {
//     int i;
//     // struct cd thiscd;
//     CD thiscd; //if using typedef
//     for (i = 0; i < NUMBER_OF_CDS; i++) {
//         thiscd = cd_collection[i];
//         printf("CD#%d, CD Name = %s, CD rating = %d\n", i, thiscd.name, thiscd.rating);
//     }
// }

// *****************************************************************************

// #define MAXSTRLEN 200
// #define FILENAME "test.txt"

// void readlines() {
//     FILE *fp = fopen( FILENAME, "r");
//     char line[MAXSTRLEN];
//     if (fp != 0) {
//         while (fgets (line, sizeof(line), fp) != 0) {
//             fputs(line, stdout);
//         }
//         fclose(fp);
//     } else {
//         printf ("File %s cannot be opened.", FILENAME);
//     }
// }

// void writelines() {
//     FILE *fp;
//     fp = fopen(FILENAME, "w");
//     fputs("Hello Tiffany\n", fp);
//     fclose(fp);
// }

// void deletefile() {
//     if (remove(FILENAME) == 0) {
//         printf("%s file deleted.\n", FILENAME);
//     } else {
//         printf("Unable to delete the file: %s\n", FILENAME);
//     }
// }

int main(int argc, char **argv) {

    /*
        Special letters when printing:
        x = hexadecimal number
        d = decimal integer
        s = string
        p = pointer value 
    */

    // PRINT HELLO WORLD -----------------------------
    // Q: How can I print everything in the for loop below? 
    // int i;
    // for (i = 0; i < argc; i++) {
    //     printf("Hello world. argc = %d arg %d is %s\n", argc, i, argv[i]);
    // }

    // Play around with variables ------------------------
    // int a = 3;
    // int b = 2;
    // int c = a + b;

    // printf("c = %d\n", c); // Q: Why can't I do %c, or %w instead of %d?

    // USE DEFINE ---------------------------------------
    // replace pi with 3.151593
    // #define PI 3.141593
    // printf("%f\n", PI);

    // USE FGETS() --------------------------------------
    // Q: Why doesn't this let me put my last name?
    // char firstname[5];
    // char lastname[5];

    // printf("Enter your first name");
    // fgets(firstname, 5, stdin);
    // printf("Enter your last name");
    // fflush(stdin); 
    // fgets(lastname, 5, stdin);

    // printf("Hello, %s, %s\n", firstname, lastname);

    // ARRAYS --------------------------------------
    // int array[5];
    // int i;

    // for (i = 0; i < 5; i++) {
    //     array[i] = i;
    //     printf("array[%d] = %d \n", i, i);
    // }

    // STRING ---------------------------------------------
    // Note: There's no such "string" type, only char arrays
    // char str1[] = "Hello";
    // char str2[] = "Goodbye\0 Friend";

    // printf("str1 = %s\n", str1);    
    // printf("str2 = %s\n", str2);

    // ADDRESS & POINTERS -----------------------------------

    // char str1[] = "Hello";
    // char *str2 = "Goodbye";

    // printf("%p\n", (void*) str1);
    // printf("%p %p %s\n", (void*) str1, str1, str1);  
    // printf("%p %p %s\n", (void*) str2, str2, str2);

    // MALLOC: Allocate memory even when the program is closed ---------
    // Q: How do you know how much memory you need to allocate?
    /*
       A: Strings = use strlen()
          Arrays = use sizeof()
          Structs = sizeof()
          Unknown size = malloc() or calloc()
          Find Total memory = size of each element by the total # of elements
    */

    // printf("%s\n", string_function_using_maxstrlen("Fred"));
    // printf("%s\n", string_function("Tiffany"));

    // CHAR FUNCTIONS -----------------------------------------
    // chartypes();

    // STRUCTS & ENUM ------------------------------------------------
    // kind of like a class
    // create_cdcollection();
    // display_cdcollection();

    // FILES ---------------------------------------------------------
    /*
        Key Letters:
        "r" = opens for reading
        "w" = opens an empty file for writing
        "a" = opens for writing
        "r+" = opens for both reading & writing
        "w+" = opens an empty file for both reading & writing
        "a+" = opens for reading and appending

        Binary Files = add a b after the letter
    */
    // writelines();
    // readlines();
    // // deletefile();

    // BINARY FILES ----------------------------------------------------
    /*
        f = pointer
        fseek = seek the end of the file
        ftell = find the position of the file pointer
        rewind = move the pointer back to the start of the file 
        fread = reads the number of bytes or characters loaded from the file

        Memory Leaks: In order to fix this, when you allocate memory that
        you no longer need, be sure to free it with free().

        -> used to reference fields in a struuct that are pointed 
        to by a pointer to that struct 
    */


    return 0;
}

