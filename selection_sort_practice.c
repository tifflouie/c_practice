#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int A[], int size) {
    int compareIndex;
    int smallestValueIndex;

    for (int current = 0; current < size; current++) {
        smallestValueIndex = current;
        for (compareIndex = current; compareIndex < size; compareIndex++) {
            if (A[compareIndex] < A[smallestValueIndex]) {
                smallestValueIndex = compareIndex;
            }
        }
        swap(&A[current], &A[smallestValueIndex]);
    }

}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int size = 10;

    selectionSort(A, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}