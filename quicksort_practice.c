#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int greaterThan = low;
    int smallerThan = high;

    do {
        do {
            greaterThan++;
        } while (A[greaterThan] <= pivot);

        do {
            smallerThan--;
        } while (A[smallerThan] > pivot);

        if (greaterThan < smallerThan) {
            swap(&A[greaterThan], &A[smallerThan]);
        }

    } while (greaterThan < smallerThan);

    swap(&A[low], &A[smallerThan]);
    return smallerThan;
}

void quickSort(int A[], int low, int high) {
    int pivot;

    if (low < high) {
        pivot = partition(A, low, high);
        quickSort(A, low, pivot);
        quickSort(A, pivot + 1, high);
    }
}


int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int size = 10;

    quickSort(A, 0, size);

    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");


    return 0;
}

