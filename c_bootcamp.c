#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// typedef enum {
//     None = 0,
//     Low = 5,
//     Medium = 9,
//     High = 12,
//     Maximum = 20,
// } Thrust;

// **************************************************************************

// void swap (int *const value_1, int *const value_2) {

//     int temp = *value_1;        // Q: Why don't I need an asterisks for temp?
//     *value_1 = *value_2;
//     *value_2 = temp;

// }

// **************************************************************************

// void decompose (float num, int *const integer, float *const fraction) {

//     *integer = (int) num;
//     *fraction = num - *integer;
// }

// **************************************************************************

// void valid_num(int num, int limit) {
//     bool valid_num = false;

//     while (valid_num == false){

//         if (num <= 1 || num > limit) {
//             printf("Please enter another number: ");
//             scanf("%d", &num); 
//         }
//         else {
//             valid_num = true;
//         }
//     }
// }

// void make_array (const int col, const int row, int upper_limit, int matrix[row][col]) {

//     for (int r = 0; r < row; r++) {
//         for (int c = 0; c < col; c++) {
//             matrix[r][c] = rand() % upper_limit;
//             printf("%d ", matrix[r][c]);
//         }
//         printf("\n");
//     }
// }

// **************************************************************************
// void print_positions(char[] current_postion, char possible_moves[row][col]) {

// }



int main() {

    

    // USE SCANF() ----------------------------------------------------------
    // Q: What's the difference between using scanf() and fgets()?

    // printf("Enter your favorite number:");
    
    // int num;
    // scanf("%d", &num); //& symbol represents the address of the operator

    // printf("Your favorite number is %d\n", num);
    // printf("Convert to hexadecimal number %x\n", num);

    // DATA TYPES -------------------------------------------------------------
    /*
        int = positive and negative #s
        unsigned int = numbers >= 0

    */

   // PRACTICE - SPACESHIP THRUST ----------------------------------------------
//    Thrust level = None;
//    printf("Ready to go level %d\n", level);
//    level = Maximum;
//    printf("Take off level %d\n", level);
//    level = Medium;
//    printf("Entering into the ionosphere %d\n", level);
//    level = Low;
//    printf("Traveling to deep space %d\n", level);

    // BITWISE OPERATORS
    /*
        & = Bitwise AND
        | = Bitwise OR
        ^ = BITWISE XOR
        ~ = BITWISE complement (not)
        << = Shift left
        >> = Shift right  (B = A >> N) shift N bits to the right
    */

   // BITMASKS 
   // ** review **
   /*
        Operator    Bitmask         Description
            &       Bit Clearing    Mask is 0 -> result is 0
            &       Bit Testing     Mask is 1 -> input pass
            |       Bit Setting     Mask is 1 -> result is 1
            ^       Bit Toggling    Mask is 1 -> input toggle
   */

  // PRACTICE  - CALCULATE THE SURFACE AND VOLUME OF A SPHERE ------------------
//   printf("Enter the radius: ");
//   double radius;             // Q: Why can't I make this a double 
//   scanf("%lf", &radius);

//   #define PI 3.14159265359
//   double surface_area = 4 * PI * pow(radius, 2);
//   double volume = (4 / 3) * PI * pow(radius, 3);

//   printf("Radius of the sphere: %.2f\n", radius);
//   printf("Surface Area of the sphere: %.2f\n", surface_area);
//   printf("Volume of the sphere: %.3e\n", volume);

   // PRACTICE - BIT SELECTOR --------------------------------------------------
   // ** review **

   // PRACITCE - PRIME NUMBER --------------------------------------------------
//    #define MAX 1000

//    printf("Enter a upper limit: ");
//    int upper_limit;
//    scanf("%d", &upper_limit);

//    //check upper limit lower than 2 or greater than MAX 
//    if ((upper_limit < 2) || (upper_limit > MAX)) {
//        goto cleanup;
//    }

//       //check if x is a prime number
//    for (int i = 2; i < upper_limit; i++) {
//        bool isPrime = true;
//        for (int j = 2; j < i; j++) {
//            if (i % j == 0) {
//                isPrime = false;
//                break;
//            }
//        }
//        if (isPrime) {
//            printf("%d\n", i);
//        }

//    }

//    cleanup:
//         printf("Error \n");
//         return EXIT_SUCCESS;

    // POINTERS
    // Q: What's the difference between assigning ptr = &b and *prt = 'C'?
    // Both lines are pointing to the addresses right?

    // char a = 'A';
    // char *ptr = &a;
    // printf(" 1 | %c, %c, %llu\n", a, *ptr, (uint64_t) ptr);
    
    // char b = 'B';
    // ptr = &b;          
    // printf(" 2 | %c, %c, %llu\n", b, *ptr, (uint64_t) ptr);

    // *ptr = 'C';
    // printf(" 3 | %c, %c, %llu\n", b, *ptr, (uint64_t) ptr);

    // (*ptr)++; // Q: what does adding one mean? Adding one to the ascii letter, making it bump up to 'D'?
    // printf(" 4 | %c, %c, %llu\n", b, *ptr, (uint64_t) ptr);

    // printf("---\n");

    // unsigned x = 'A'; //unsigned takes up more memory than char
    // ptr = (char *)&x;
    // printf(" 5 | %u, %c, %llu\n", x, *ptr, (uint64_t) &x);
    
    // unsigned y = 'B'; 
    // ptr = (char *)&y;
    // printf(" 6 | %u, %c, %llu\n", y, *ptr, (uint64_t) &y);

    // *ptr = 'C';
    // printf(" 7 | %u, %c, %llu\n", y, *ptr, (uint64_t) &y);

    // (*ptr)++; 
    // printf(" 8 | %u, %c, %llu\n", y, *ptr, (uint64_t) &y);

    // AVOID POINTER CRASH (SEGMENT FAULT) -----------------------------
    // int *ptr = NULL;

    // if (ptr) { //ptr != NULL
    //     printf(" 1 | Pointed Value: %d\n", *ptr);
    // }

    // int someValue = 123;

    // if (!ptr) { //ptr == NULL
    //     ptr = &someValue;
    // }

    // if (ptr) {
    //     printf(" 2 | Pointed Value: %d\n", *ptr);
    // }

    // return 0;

    // CONSTANT POINTER AND COSTANT DATA
    // ** review **

    /*
        Q: What is the difference between these?

        int *const ptr = &some_data;
        const int *ptr = &some_data;
        const int *cont ptr = &some_data;
    */

    /*
        Note: if you want to change a variable not within the scope
        of the function, then you need to create a pointer parameter
    */

   // PRACTICE - SIMPLE SWAPPER -----------------------------------------
//    int value_1 = 1;
//    int value_2 = 2;

//    int *val_1 = &value_1;
//    int *val_2 = &value_2;


//    swap(val_1, val_2);

//    printf("value 1 = %d\n", value_1);
//    printf("value 2 = %d\n", value_2);

    // PRACTICE - FLOAT DECOMPOSITION ------------------------------------

    // printf("Enter a floating point number: ");
    // float floating_num;
    // scanf("%f", &floating_num);

    // int integer;
    // float fraction;

    // decompose(floating_num, &integer, &fraction);
    // printf("Integer number = %d\n", integer);
    // printf("Fraction part = %f\n", fraction);

   // ARRAYS --------------------------------------------------------------

    /*
        Note:
        - sizeof() tells you how many bytes an array occupies
        - get the number of elements of an array is sizeof(the_array) / sizeof(one_element)
        - move pointer by 1 to move to next element
    */

   // PRACTICE - RANDOM MATRIX --------------------------------------------
   // ** review ** 
   // Q: How do you use a conditional operator (condition ? expression1 : expression2)?

    // printf("Enter the number of rows: ");
    // int row;
    // scanf("%d", &row);
    // valid_num(row, 10);

    // printf("Enter the number of columns: ");
    // int col;
    // scanf("%d", &col);
    // valid_num(col, 10);

    // printf("Enter an upper limit: ");
    // int upper_limit;
    // scanf("%d", &upper_limit);
    // valid_num(upper_limit, 1000);

    // int matrix[row][col];
    // make_array(col, row, upper_limit, matrix);


    // PRACTICE - MOVE THE ROOK N CHESS ------------------------------------

    #define NUM 8
    #define LETTER 8
    char possible_move[NUM][LETTER];
    char number_str[NUM];
    // char *start = 'a';

    char c = 'A';

    for (int r = 0; r < NUM; r++) {
        for (int c = 0; c < LETTER; c++) {
            sprintf(number_str, "%d", c + 1);
            strcat("a", number_str);
            printf("%s\n", number_str);
           //possible_move[r][c] = strcat("a", number_str);
        }
    }

    // char str[100] = "The number is: ";
    // int number = 42;

    // // Convert the integer to a string using sprintf
    // char number_str[20]; // Make sure the character array is large enough
    // sprintf(number_str, "%d", number);

    // // Concatenate the string and the integer-as-a-string using strcat
    // strcat(str, number_str);

    // printf("%s\n", str); // Output: "The number is: 42"

    return 0;












}