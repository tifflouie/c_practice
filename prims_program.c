#include <stdio.h>
#define VERTICES 8
#define INFINITY_VAL 32767

void PrintMST(int MSTEdges[][VERTICES - 2], int Graph[VERTICES][VERTICES]) {
    printf("\nMinimum Spanning Tree Edges (with cost)\n\n");
    int totalCost = 0;
    for (int i = 0; i < VERTICES - 2; i++) {
        int cost = Graph[MSTEdges[0][i]][MSTEdges[1][i]];
        printf("[%d]---[%d] cost: %d\n", MSTEdges[0][i], MSTEdges[1][i], cost);
        totalCost += cost;
    }
    printf("\nTotal cost of MST: %d\n", totalCost);
}

void PrimsMST(int Graph[VERTICES][VERTICES], int numVertices) {
    int u, v, minCost, k;
    int minEdge[VERTICES];
    int MSTEdges[2][VERTICES - 2] = {0};

    // Find the initial min cost edge
    minCost = INFINITY_VAL;
    for (int i = 1; i < VERTICES; i++) {
        minEdge[i] = INFINITY_VAL;  // Initialize minEdge array with INFINITY_VAL
        for (int j = i; j < VERTICES; j++) {
            if (Graph[i][j] < minCost) {
                minCost = Graph[i][j];
                u = i;
                v = j;
            }
        }
    }
    MSTEdges[0][0] = u;
    MSTEdges[1][0] = v;
    minEdge[u] = minEdge[v] = 0;

    // Initialize minEdge array to track min cost edges
    for (int i = 1; i < VERTICES; i++) {
        if (minEdge[i] != 0) {
            if (Graph[i][u] < Graph[i][v]) {
                minEdge[i] = u;
            } else {
                minEdge[i] = v;
            }
        }
    }

    // Repeat to find other min cost edges
    for (int i = 1; i < numVertices - 1; i++) {
        minCost = INFINITY_VAL;
        for (int j = 1; j < VERTICES; j++) {
            if (minEdge[j] != 0 && Graph[j][minEdge[j]] < minCost) {
                k = j;
                minCost = Graph[j][minEdge[j]];
            }
        }
        MSTEdges[0][i] = k;
        MSTEdges[1][i] = minEdge[k];
        minEdge[k] = 0;

        // Update minEdge array to track min cost edges
        for (int j = 1; j < VERTICES; j++) {
            if (minEdge[j] != 0 && Graph[j][k] < Graph[j][minEdge[j]]) {
                minEdge[j] = k;
            }
        }
    }
    PrintMST(MSTEdges, Graph);
}

int main() {
    int costMatrix[VERTICES][VERTICES] = {
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

    PrimsMST(costMatrix, numVertices);

    return 0;
}
