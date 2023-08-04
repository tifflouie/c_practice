#include <stdio.h>

#define SIZE 8
#define INFINITY_VAL 32767

void printAfterExecution(int edges[][SIZE - 2], int adjacencyMatrix[SIZE][SIZE]) {
    printf("Minimum Spanning Tree Edges (with cost)\n");

    int totalCost = 0;
    for (int i = 0; i < SIZE - 2; i++) {
        int cost = adjacencyMatrix[edges[0][i]][edges[1][i]];
        printf("[%d]----[%d] cost: %d\n", edges[0][i], edges[1][i], cost);
        totalCost += cost;
    }

    printf("\nTotal cost = %d\n", totalCost);
}

void executePrimProg(int adjacencyMatrix[SIZE][SIZE], int numVertices) {
    int firstVertex, secondVertex, minCost, minCostIndex;
    int track[SIZE];
    int edges[2][SIZE - 2] = {0};

    //Find the intial minimum cost edge
    minCost = INFINITY_VAL;
    for (int row = 1; row < SIZE; row++) {
        track[row] = INFINITY_VAL;
        for (int col = row; col < SIZE; col++) {
            if (adjacencyMatrix[row][col] < minCost) {
                minCost = adjacencyMatrix[row][col];
                firstVertex = row;
                secondVertex = col;
            }
        }
    }

    edges[0][0] = firstVertex;
    edges[1][0] = secondVertex;
    track[firstVertex] = 0;
    track[secondVertex] = 0;

    //Initialize edge array to track the minimum cost edges
    for (int indexInTrackArray = 1; indexInTrackArray < SIZE; indexInTrackArray++) {
        if (track[indexInTrackArray] != 0) {
            if (adjacencyMatrix[indexInTrackArray][firstVertex] < adjacencyMatrix[indexInTrackArray][secondVertex]) {
                track[indexInTrackArray] = firstVertex;
            }
            else {
                track[indexInTrackArray] = secondVertex;
            }
        }
    }

    //Repeat to find the other mininmum cost edges
    for (int indexInEdge = 1; indexInEdge < numVertices - 1; indexInEdge++) {
        minCost = INFINITY_VAL;

        for (int indexInTrackArray = 1; indexInTrackArray < SIZE; indexInTrackArray++) {
            if (track[indexInTrackArray] != 0 && adjacencyMatrix[indexInTrackArray][track[indexInTrackArray]] < minCost) {
                minCostIndex = indexInTrackArray;
                minCost = adjacencyMatrix[indexInTrackArray][track[indexInTrackArray]];
            }
        }

        edges[0][indexInEdge] = minCostIndex;
        edges[1][indexInEdge] = track[minCostIndex];
        track[minCostIndex] = 0;

        //Update track array to keep count of the minimum cost edges
        for (int trackIndex = 1; trackIndex < SIZE; trackIndex++) {
            if(track[trackIndex] != 0 && adjacencyMatrix[trackIndex][minCostIndex] < adjacencyMatrix[trackIndex][track[minCostIndex]]) {
                track[trackIndex] = minCostIndex;
            }
        }

    }

    printAfterExecution(edges, adjacencyMatrix);

}



int main() {
    int costMatrix[SIZE][SIZE] = {
        {INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL},
        {INFINITY_VAL, INFINITY_VAL, 25, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, 5, INFINITY_VAL},
        {INFINITY_VAL, 25, INFINITY_VAL, 12, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, 10},
        {INFINITY_VAL, INFINITY_VAL, 12, INFINITY_VAL, 8, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL},
        {INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, 8, INFINITY_VAL, 16, INFINITY_VAL, 14},
        {INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, 16, INFINITY_VAL, 20, 18},
        {INFINITY_VAL, 5, INFINITY_VAL, INFINITY_VAL, INFINITY_VAL, 20, INFINITY_VAL, INFINITY_VAL},
        {INFINITY_VAL, INFINITY_VAL, 10, INFINITY_VAL, 14, 18, INFINITY_VAL, INFINITY_VAL},
    };

    int numVertices = sizeof(costMatrix[0]) / sizeof(costMatrix[0][0]) - 1;

    executePrimProg(costMatrix, numVertices);

    return 0;


}