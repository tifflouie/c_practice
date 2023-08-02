#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    int height;
    struct Node *leftChild;
    struct Node *rightChild;
};

struct Node *root = NULL;

int getHeight(struct Node *current) {
    
    int left = 0;
    int right = 0;

    if (current == NULL) {
        return 0;
    }

    left = getHeight(current->leftChild);
    right = getHeight(current->rightChild);

    if (left > right) {
        return left + 1;
    }
    else {
        return right + 1;
    }

}

struct Node * LLRotation(struct Node *current) {

    struct Node *currentLeft = current->leftChild;
    struct Node *currentLeftRight = currentLeft->rightChild;

    currentLeft->rightChild = current;
    current->leftChild = currentLeftRight;

    current->height = getHeight(current);
    currentLeft->height = getHeight(currentLeft);

    if (root == current) {
        root = currentLeft;
    }

    return currentLeft;

}

struct Node * LRRotation(struct Node *current) {

    struct Node *currentLeft = current->leftChild;
    struct Node *currentLeftRight = currentLeft->rightChild;

    //take care of currentLeftRight's left and right child
    current->leftChild = currentLeftRight->rightChild;
    currentLeft->rightChild = currentLeftRight->leftChild;
    
    //bring currentLeftRight to the root
    //currrent to the right child, currentleft to the left child
    currentLeftRight->leftChild = currentLeft;
    currentLeftRight->rightChild = current;

    if (root == current) {
        root = currentLeftRight;
    }

    return currentLeftRight;

}

struct Node * RRRotation(struct Node *current) {

    struct Node *currentRight = current->rightChild;
    struct Node *currentRightLeft = currentRight->leftChild;

    currentRight->leftChild = current;
    current->rightChild = currentRightLeft;

    current->height = getHeight(current);
    currentRight->height = getHeight(currentRight);

    if (root == current) {
        root = currentRight;
    }

    return currentRight;

}

struct Node * RLRotation(struct Node *current) {

    struct Node *currentRight = current->rightChild;
    struct Node *currentRightLeft = currentRight->leftChild;

    //take care of currentRightLeft's left and right child
    current->rightChild = currentRightLeft->leftChild;
    currentRight->leftChild = currentRightLeft->rightChild;
    
    //bring currentRightLeft to the root
    //currrent to the left child, currentRight to the right child
    currentRightLeft->rightChild = currentRight;
    currentRightLeft->leftChild = current;

    if (root == current) {
        root = currentRightLeft;
    }

    return currentRightLeft;

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

    // rotation
    int leftNodeHeight = getHeight(current->leftChild) + 1;
    int rightNodeHeight = getHeight(current->rightChild) + 1;

    current->height = leftNodeHeight - rightNodeHeight;

    if (current->height == 2 && current->leftChild->height == 1) {
        return LLRotation(current);
    }
    else if (current->height == 2 && current->leftChild->height == -1) {
        return LRRotation(current);
    }
    else if (current->height == -2 && current->rightChild->height == -1) {
        return RRRotation(current);
    }
    else if (current->height == -2 && current->rightChild->height == 1) {
        return RLRotation(current);
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

int main() {

    root = recursiveInsert(root, 30);
    recursiveInsert(root, 40);
    recursiveInsert(root, 35);
    recursiveInsert(root, 31);
    recursiveInsert(root, 37);


    printf("Print: ");
    inorderTraversal(root);
    printf("\n");


    return 0;
}
