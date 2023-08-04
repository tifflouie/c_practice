#include <stdio.h>

#define INFINITY_VALUE 32767
#define NUM_VERTICES 7
#define NUM_EDGES 9

void printKruskalProgram(int solutionArray[2][NUM_VERTICES - 1], int matrix[3][NUM_EDGES]) {
    printf("Minimum Cost Spanning Tree Edges\n");
    for (int i = 0; i < NUM_VERTICES - 1; i++) {
        printf("[%d]-----[%d]\n", solutionArray[0][i], solutionArray[1][i]);
    }
    printf("\n");
}

void Union(int firstIndex, int secondIndex, int array[NUM_VERTICES + 1]) {
    if (array[firstIndex] < array[secondIndex]) {
        array[firstIndex] += array[secondIndex];
        array[secondIndex] = firstIndex;
    }
    else {
        array[secondIndex] += array[firstIndex];
        array[firstIndex] = secondIndex;
    }
}

int Find(int index, int array[NUM_VERTICES + 1]) {
    int parent = index;
    int temp = 0;

    while (array[parent] > 0) {
        parent = array[parent];
    }

    while (index != parent) {
        temp = array[index];
        array[index] = parent;
        index = temp;
    }

    return parent;
}

void executeKruskalProgram(int matrix[3][NUM_EDGES]) {

    int solutionArray[2][NUM_VERTICES - 1];
    int includedArray[NUM_EDGES] = {0};
    int findCycleArray[NUM_VERTICES + 1] = {-1};

    int i = 0;
    while (i < NUM_VERTICES - 1) {
        int minCost = INFINITY_VALUE;
        int firstIndex = 0;
        int secondIndex = 0;
        int indexinIncluded = 0;

        //Find the minimum cost edge
        for (int j = 0; j < NUM_EDGES; j++) {
            if (includedArray[j] == 0 && matrix[2][j] < minCost) {
                minCost = matrix[2][j];
                firstIndex = matrix[0][j];
                secondIndex = matrix[1][j];
                indexinIncluded = j;
            }
        }

        //Check if the selected minimum cost edge (firstIndex, secondIndex) forms a cycle or not
        if (Find(firstIndex, findCycleArray) != Find(secondIndex, findCycleArray)) {
            solutionArray[0][i] = firstIndex;
            solutionArray[1][i] = secondIndex;

            //Perform Union
            Union(Find(firstIndex, findCycleArray), Find(secondIndex, findCycleArray), findCycleArray);
            i++;
        }

        includedArray[indexinIncluded] = 1;
    }

    printKruskalProgram(solutionArray, matrix);
}

int main() {

    int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                       {2, 6, 3, 7, 4, 5, 7, 6, 7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};

    executeKruskalProgram(edges);

    return 0;
}