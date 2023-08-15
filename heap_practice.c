#include <stdio.h>

void insert(int array[], int size) {
    int max = size;
    int temp = array[max];

    // value is greater than one or 
    // greater than it's children
    while (max > 1 && temp > array[max/2]) {
        array[max] = array[max/2];
        max = max/2;
    }
    array[max] = temp;
}

int delete(int array[], int size) {

    int swapTemp;

    // remove the max(root) and replace
    // with the lowest child
    int value = array[1];
    int temp = array[size];
    array[1] = array[size];
    array[size] = value;

    int max = 1;
    int child = max * 2;

    while (child <= size - 1) {

        // find which child is greater
        if (child < size - 1 && array[child + 1] > array[child]) {
            child = child + 1;
        }

        if (array[child] > array[max]) {
            //swap
            swapTemp = array[max];
            array[max] = array[child];
            array[child] = swapTemp;

            max = child;
            child = 2 * child;
        }
        else {
            break;
        }
    }

    return value;

    
}

int main() {

    int array[] = {0, 14, 15, 5, 20, 30, 8, 40};
    int i;
    for (i = 2; i <= 7; i++)
        insert(array, i);

    for (i = 7; i > 1; i--)
    {
        delete(array, i);
    }
    for (i = 1; i <= 7; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}