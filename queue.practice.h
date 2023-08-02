#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void createQueue(struct Queue *queue, int size) {
    queue->size = size;
    queue->front = 0;
    queue->rear = 0;
    queue->Q = (struct Node **)malloc(queue->size * sizeof(struct Node *));
}

void enqueue(struct Queue *queue, struct Node *x) {
    if ((queue->rear + 1) % queue->size == queue ->front) {
        printf("Queue is full.");
    }
    else {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->Q[queue->rear] = x;
    }
}

struct Node *dequeue(struct Queue *queue) {
    struct Node *removedNode = NULL;

    if (queue->front == queue->rear) {
        printf("Queue is Empty.");
    }
    else {
        queue->front = (queue->front + 1) % queue->size;
        removedNode = queue->Q[queue->front]; 
    }
    
    return removedNode;
}

int isEmpty(struct Queue *queue) {
    return queue->front == queue->rear;
}