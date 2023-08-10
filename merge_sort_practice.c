#include <stdio.h>
#include <stdlib.h>

void merge(int sorted[], int left[], int leftSize, int right[], int rightSize) {
    int leftPosition = 0;
    int rightPosition = 0;
    int sortedPosition = 0;

    while (leftPosition < leftSize || rightPosition < rightSize) {
        if (leftPosition >= leftSize) {
            sorted[sortedPosition] = right[rightPosition];
            sortedPosition++;
            rightPosition++;
        }
        else if (rightPosition >= rightSize) {
            sorted[sortedPosition] = left[leftPosition];
            sortedPosition++;
            leftPosition++;
        }
        else if (left[leftPosition] < right[rightPosition]) {
            sorted[sortedPosition] = left[leftPosition];
            sortedPosition++;
            leftPosition++;
        }
        else {
            sorted[sortedPosition] = right[rightPosition];
            sortedPosition++;
            rightPosition++;
        }
    }
}

void mergeSort(int array[], int size) {
    // break
    if (size == 1) {
        return;
    }

    //spit into half
    int halfSize = size/2;          //this is integer division
    int *left = (int *)malloc(sizeof(int) * halfSize);
    int *right = (int *)malloc(sizeof(int) * size - halfSize);

    for (int i = 0; i < halfSize; i++) {
        left[i] = array[i];
    }
    for (int i = halfSize; i < size; i++) {
        right[i - halfSize] = array[i]; 
    }

    //recurse
    mergeSort(left, halfSize);
    mergeSort(right, size - halfSize);
    
    //merge
    //left and right are pointers but why isn't the paremeter
    //of the merge function a pointer?
    merge(array, left, halfSize, right, size - halfSize);

    free(left);
    free(right);

}

int main() {

    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int size = 10;

    mergeSort(A, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}