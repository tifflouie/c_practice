#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[], int size) {

    int value;
    int compareIndex;

    for (int i = 1; i < size; i++) {
        value = A[i];
        compareIndex = i - 1;

        while (compareIndex > -1 && A[compareIndex] > value) {
            A[compareIndex + 1] = A[compareIndex];
            compareIndex--;
        }
        A[compareIndex + 1] = value;
    }
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int size = 10;

    insertionSort(A, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;

}