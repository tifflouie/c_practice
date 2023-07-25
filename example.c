#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int f(int x, int y) {
    return x + y;
}

int main()
{
    int i = 1;

    //char* s = "abc";
    //char first = s[0];

  

    int j = 2;


    int k = f(i, j);

    printf("Hello World 3 \n");
    //printf("str = %s \n", first);
    // printf("first %s", s[0]);

    int a = 0;
    // @assert a > 0;
    int x = j / a;

    printf("%i \n", x);

    int power = POW(2,3);
    printf("%i \n", power);


    printf("%i \n", k);

    i = 4567;
    printf("%i \n", i);
    
    return 1;
}