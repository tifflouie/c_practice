#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int num) {

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = num;
    temp->next = NULL;

    if(front == NULL) {
        front = temp;
        rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }

}

int dequeue() {

    struct Node *temp;
    
    temp = front;
    front = front->next;
    int num = temp->data;
    
    free(temp);
    return num;
    
}

void displayQueue() {

    struct Node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    displayQueue();

    printf("-----\n");

    printf("%d ", dequeue());

    printf("-----\n");

    displayQueue();

    return 0;


}