#include <stdio.h>
#include <stdlib.h>

/**
 * [1,2,3,4]
 *
 * mergeSort([4,1,3,2]) {1}
 *	a: [4,1]
 *	b: [3,2]
 *	a_sorted: mergeSort([4,1]) {2} -> [1,4]
 *		a:[4]
 *		b:[1]
 *		a_sorted: mergeSort([4]){3} -> [4]
 *		b_sorted: mergeSort([1]){3} -> [1]
 *		merged: [1,4]
*	b_sorted: mergeSort([3,2]) {2} -> [2,3]
 *		a:[3]
 *		b:[2]
 *		a_sorted: mergeSort([3]){3} -> [3]
 *		b_sorted: mergeSort([2]){3} -> [2]
 *		merged: [2,3]
 *	merged: [1,2,3,4]
 * 
 */

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int leftPos = 0, rightPos = 0, mergedPos = 0;
    
    while (leftPos < leftSize || rightPos < rightSize) {
        if (leftPos >= leftSize) {
            arr[mergedPos++] = right[rightPos++];
        } else if (rightPos >= rightSize) {
            arr[mergedPos++] = left[leftPos++];
        } else {
            if (left[leftPos] < right[rightPos]) {
                arr[mergedPos++] = left[leftPos++];
            } else {
                arr[mergedPos++] = right[rightPos++];
            }
        }
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    
    int halfSize = size / 2;
    int *left = (int *)malloc(sizeof(int) * halfSize);
    int *right = (int *)malloc(sizeof(int) * (size - halfSize));
    
    for (int i = 0; i < halfSize; i++) {
        left[i] = arr[i];
    }
    for (int i = halfSize; i < size; i++) {
        right[i - halfSize] = arr[i];
    }
    
    mergeSort(left, halfSize);
    mergeSort(right, size - halfSize);
    merge(arr, left, halfSize, right, size - halfSize);
    
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
