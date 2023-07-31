#include <stdlib.h>
#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
};

void sortedInsert(struct Node **head, int value) {
    struct Node *previous = NULL, *current = *head;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = value;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    }
    else {
        while (current != NULL && current->value < value) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) {
            temp->next = *head;
            *head = temp;
        }
        else {
            previous->next = temp;
        }
    }

}

struct Node *search(struct Node *head, int key) {
    while (head != NULL) {
        if (key == head->value) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int hash(int key) {
    return key % 10;
}

void insertIntoHashTable(struct Node *hashTable[], int key) {
    int index = hash(key);
    sortedInsert(&hashTable[index], key);
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->value);
        temp = temp->next;
    }

    printf("\n");
}

void displayBucket(struct Node *hashTable[], int size) {

    for (int i = 0; i < size; i++) {
        printf("bucket %d: ", i);
        display(hashTable[i]);
    }

}


int main() {
    struct Node *hashTable[10];
    
    for (int i = 0; i < sizeof(hashTable) / sizeof(hashTable[0]); i++) {
        hashTable[i] = NULL;
    }

    insertIntoHashTable(hashTable, 1);
    insertIntoHashTable(hashTable, 2);

    displayBucket(hashTable, 10);

    struct Node *temp = search(hashTable[hash(3)], 3);

    if (temp == NULL) {
        printf("Item not found.\n");
    }
    else {
        printf("%d\n", temp->value);
    }

    return 0;
}


