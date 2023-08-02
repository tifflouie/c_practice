#include <stdio.h>
#include <stdlib.h>
#include "queue.practice.h"

struct Node *root = NULL;

void createBinaryTree() {
    struct Node *current, *temp;
    int value;
    struct Queue queue;
    createQueue(&queue, 100);

    printf("Enter a root value: ");
    scanf("%d", &value);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->value = value;
    root->rightChild = NULL;
    root->leftChild = NULL;
    enqueue(&queue, root);

    while (!isEmpty(&queue)) {
        current = dequeue(&queue);
        
        // left child
        printf("Enter the left child of %d node: ", current->value);
        scanf("%d", &value);

        if (value != -1) {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->value = value;
            temp->rightChild = NULL;
            temp->leftChild = NULL;

            current->leftChild = temp;
            enqueue(&queue, temp);
        }

        // right child
        printf("Enter the right child of %d node: ", current->value);
        scanf("%d", &value);

        if (value != -1) {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->value = value;
            temp->rightChild = NULL;
            temp->leftChild = NULL;

            current->rightChild = temp;
            enqueue(&queue, temp);
        }
    }
}

void preorder(struct Node *current) {

    if (current != NULL) {
        printf("%d", current->value);
        preorder(current->leftChild);
        preorder(current->rightChild);
    }
    
}

void inorder(struct Node *current) {

    if (current != NULL) {
        inorder(current->leftChild);
        printf("%d", current->value);
        inorder(current->rightChild);
    }
    
}

void postorder(struct Node *current) {

    if (current != NULL) {
        postorder(current->leftChild);
        postorder(current->rightChild);
        printf("%d", current->value);
    }
    
}

void levelorder(struct Node *current) {
    struct Queue queue;
    createQueue(&queue, 100);

    printf("%d", current->value);
    enqueue(&queue, current);

    while (!isEmpty(&queue)) {
        current = dequeue(&queue);
        
        if (current->leftChild != NULL) {
            printf("%d", current->leftChild->value);
            enqueue(&queue, current->leftChild);
        }
        if (current->rightChild != NULL) {
            printf("%d", current->rightChild->value);
            enqueue(&queue, current->rightChild);
        }
    }

}

int countNode(struct Node *current) {
    if (current != NULL) {
        return countNode(current->leftChild) + countNode(current->rightChild) + 1;
    }
    return 0;
}

// REVIEW THIS (confirm what the x and y are doing)
int getHeight(struct Node *current) {
    int x = 0;
    int y = 0;

    if (current == 0) {
        return 0;
    }

    x = getHeight(current->leftChild);
    y = getHeight(current->rightChild);

    if (x > y) {
        return x + 1;
    }
    else {
        return y + 1;
    }

}

int main() {
    createBinaryTree();

    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Level Order: ");
    levelorder(root);
    printf("\n");

    printf("\n");
    printf("Number of Nodes: ");
    printf("%d", countNode(root));
    printf("\n");

    printf("Height: ");
    printf("%d", getHeight(root));
    printf("\n");



}