#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int A[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (A[j] > A[j+1]) {
                swap(&A[j], &A[j+1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int size = 10;

    bubbleSort(A, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}