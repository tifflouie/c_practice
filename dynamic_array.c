#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 5;
    int array[5] = {1, 2, 3, 4, 5};
    int *dynamicArray;



    // Allocate memory for an array of 'size' integers
    dynamicArray = (int *)malloc(size * sizeof(int));

    // dynamicArray = array;

    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Now you can use the dynamically allocated block as if it were an array
    // for (int i = 0; i < size; i++) {
    //     dynamicArray[i] = i + 1;
    //     printf("Element %d: %d\n", i, dynamicArray[i]);
    // }

    for (int i = 0; i < size; i++) {
        dynamicArray[i] = array[i];
    }

    // Now you can use the dynamically allocated block as if it were an array
    for (int i = 0; i < size; i++) {
        printf("%d\n", dynamicArray[i]);
    }

    // for (int *da = dynamicArray, i = 0; i < size; i++) {
    //     printf("%d\n", *da);
    //     da++;
    // }

    // Don't forget to free the allocated memory when you're done with it
    free(dynamicArray);

    return 0;
}
