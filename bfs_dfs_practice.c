#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 8

struct Queue {
    int data[MAX_VERTICES];
    int front;
    int rear;
};

void createQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

void enqueue(struct Queue *queue, int value) {
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    else {
        queue->rear++;
    }

    queue->data[queue->rear] = value;
}

int dequeue(struct Queue *queue) {
    int value = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front++;
    }

    return value;
}

void breadthFirstSearch(int num, int A[][MAX_VERTICES], int size) {
    struct Queue queue;

    createQueue(&queue);
    int visitedNodes[MAX_VERTICES] = {0};

    printf("%d", num);
    visitedNodes[num] = 1;
    enqueue(&queue, num);

    while (!isEmpty(&queue)) {
        int u = dequeue(&queue);
        for (int v = 1; v <= size; v++) {
            if (A[u][v] == 1 && visitedNodes[v] == 0) {
                printf("%d", v);
                visitedNodes[v] = 1;
                enqueue(&queue, v);
            }
        }
    }

    printf("\n");

}

void depthFirstSearch(int G[][7], int start, int dimension) {
    static int visitedNodes[7] = {0};
    int j;

    if (visitedNodes[start] == 0) {
        printf("%d", start);
        visitedNodes[start] = 1;

        for (j = 1; j < dimension; j++) {
            if (G[start][j] == 1 && visitedNodes[start] == 0) {
                depthFirstSearch(G, j, dimension);
            }
        }
    }
}

int main() {

    int A[MAX_VERTICES][MAX_VERTICES] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0}};

    printf("Breadth First Search -------\n");

    printf("Vertex: 1 -> ");
    breadthFirstSearch(1, A, MAX_VERTICES);

    printf("Vertex: 4 -> ");
    breadthFirstSearch(4, A, MAX_VERTICES);

    printf("Depth First Search ---------\n");

    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    printf("Vertex: 1 -> ");
    depthFirstSearch(G, 4, 7);

    printf("\n");

    return 0;
}