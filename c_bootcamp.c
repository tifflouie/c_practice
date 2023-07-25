#include <stdio.h>

int main() {

    

    // USE SCANF()
    printf("Enter your favorite number:");
    
    int num;
    scanf("%d", &num); //& symbol represents the address of the operator

    printf("Your favorite number is %d\n", num);

    return 0;
}