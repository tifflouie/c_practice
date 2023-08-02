#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

struct Node {
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
};

struct Node *root = NULL;

void insert(int key) {

    struct Node *current = root;
    struct Node *temp;
    struct Node *previous;

    if (current == NULL) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->value = key;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
        root = temp;
        return;
    }

    while (current != NULL) {
        previous = current;

        if (key < current->value) {
            current = current->leftChild;
        }
        else if (key > current->value) {
            current = current->rightChild;
        }
        else {
            return;
        }
    }

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = key;
    temp->leftChild = NULL;
    temp->rightChild = NULL;

    if (key < previous->value) {
        previous->leftChild = temp;
    }
    else {
        previous->rightChild = temp;
    }
}

struct Node * recursiveInsert(struct Node *current, int key) {
    
    struct Node *temp;

    if (current == NULL) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->value = key;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
        return temp;
    }
    
    if (key < current->value) {
        current->leftChild = recursiveInsert(current->leftChild, key);
    }
    else if (key > current->value) {
        current->rightChild = recursiveInsert(current->rightChild, key);
    }

    return current;

}

void inorderTraversal(struct Node *current) {
    if (current != NULL) {
        inorderTraversal(current->leftChild);
        printf("%d ", current->value);
        inorderTraversal(current->rightChild);
    }
}

struct Node * search(int key) {
    struct Node *current = root;
    
    while (current != NULL) {
        if (key == current->value) {
            return current;
        }
        else if (key < current->value) {
            current = current->leftChild;
        }
        else if (key > current->value) {
            current = current->rightChild;
        }
    }

    return NULL;
}

int getHeight(struct Node *current) {
    int x, y;

    if (current == NULL) {
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

struct Node * inorderPredecessor(struct Node *current) {
    while (current != NULL && current->rightChild != NULL) {
        current = current->rightChild;
    }
    return current;
}

struct Node * inorderSuccessor(struct Node *current) {
    while (current != NULL && current->leftChild != NULL) {
        current = current->leftChild;
    }
    return current;
}

struct Node * deleteElement(struct Node *current, int key) {

    struct Node *temp;

    if (current == NULL) {
        return NULL;
    }

    if (current->leftChild == NULL && current->rightChild == NULL) {

        if (current == root) {
            root = NULL;
        }

        free(current);
        return NULL;
    }

    if (key < current->value) {
        current->leftChild = deleteElement(current->leftChild, key);
    }
    else if (key > current->value) {
        current->rightChild = deleteElement(current->rightChild, key);
    }
    else {

        if (getHeight(current->leftChild) > getHeight(current->rightChild)) {
            temp = inorderPredecessor(current->leftChild);
            current->value = temp->value;
            current->leftChild = deleteElement(current->leftChild, temp->value);
        }
        else {
            temp = inorderSuccessor(current->rightChild);
            current->value = temp->value;
            current->rightChild = deleteElement(current->rightChild, temp->value);
        }
    }

    return current;

}

//INCOMPLETE: still need to implement stack.h to read the top and pop a Node

// void createBSTfromPreorderTraversal(int preorderArray[], int size) {
//     struct Stack stack;
//     struct Node *temp;
//     struct Node *current;
//     int i = 0;

//     root = (struct Node *)malloc(sizeof(struct Node));
//     root->value = preorderArray[i];
//     i++;
//     root->leftChild = NULL;
//     root->rightChild = NULL;
//     current = root;

//     while (i < size) {
//         if (preorderArray[i] < current->value) {
//             temp = (struct Node *)malloc(sizeof(struct Node));
//             temp->value = preorderArray[i];
//             i++;
//             temp->leftChild = NULL;
//             temp->rightChild = NULL;
//             current->leftChild = temp;
//             push(&stack, current->value);
//             current = temp;
//         }
//         else if (preorderArray[i] > current->value && preorderArray[i] > peek(stack, 0)->data){
//             temp = (struct Node *)malloc(sizeof(struct Node));
//             temp->value = preorderArray[i];
//             i++;
//             temp->leftChild = NULL;
//             temp->rightChild = NULL;
//             current->rightChild = temp;
//             current = temp;
//         }
//         else {
//             current = pop(&stack);
//         }
//     }

// }

int main() {

    root = recursiveInsert(root, 1);
    recursiveInsert(root, 3);
    recursiveInsert(root, 2);

    printf("Binary tree inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Searching for element: ");
    struct Node *searching = search(3);

    if (searching != NULL) {
        printf("Found element!\n");
    }
    else {
        printf("Element not found.\n");
    }

    deleteElement(root, 5);

    printf("Binary tree inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    


    return 0;
}