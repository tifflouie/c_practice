#include <stdio.h>

#define MAX_VERTICES 8

typedef struct
{
    int data[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = q->rear = -1;
}

int isEmpty(Queue *q)
{
    return (q->front == -1 && q->rear == -1);
}

void enqueue(Queue *q, int value)
{
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }

    q->data[q->rear] = value;
}

int dequeue(Queue *q)
{
    int value = q->data[q->front];

    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }

    return value;
}

void BFS(int vtx, int A[][MAX_VERTICES], int n)
{
    Queue Q;
    initQueue(&Q);
    int visited[MAX_VERTICES] = {0};

    // Initial
    printf("%d, ", vtx); // Visit vertex
    visited[vtx] = 1;
    enqueue(&Q, vtx);

    // Explore
    while (!isEmpty(&Q))
    {
        int u = dequeue(&Q); // Vertex u for exploring
        for (int v = 1; v <= n; v++)
        { // Adjacent vertices of vertex u
            if (A[u][v] == 1 && visited[v] == 0)
            {                      // Adjacent vertex and not visited
                printf("%d, ", v); // Visit vertex
                visited[v] = 1;
                enqueue(&Q, v);
            }
        }
    }
    printf("\n");
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    int j;

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;

        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int main()
{
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
    BFS(1, A, MAX_VERTICES);

    printf("Vertex: 4 -> ");
    BFS(4, A, MAX_VERTICES);

    printf("Depth First Search ---------\n");

    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    printf("Vertex: 1 -> ");
    DFS(G, 4, 7);

    printf("\n");

    return 0;
}
