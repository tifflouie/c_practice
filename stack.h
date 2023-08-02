#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
    struct Node *leftChild;
    struct Node *rightChild;
} *top = NULL;

void push(struct Node *stack, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->value = x;
        t->next = top;
        top = t;
    }
}
struct Node * pop()
{
    struct Node *t;
    int x = -1;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t;
        free(t);
    }
    return x;
}


