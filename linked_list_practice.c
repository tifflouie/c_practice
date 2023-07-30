#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void insertHead(int num) {
    if (head != NULL) {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->value = num;
        temp->next = head;
        head = temp;
    }
}

void createLinkedList(int array[], int size) {
    int i;
    struct Node *temp;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->value = array[0];
    head->next = NULL;
    tail = head;

    for (i = 1; i < size; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->value = array[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void deleteElement(int index) {

    // Q: Why can't I free the memory of current? 

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));

    if (index == 0) {
        temp = head->next;
        head = temp;
    }
    else {
        current = head;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }

        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
    free(current);

}

void display(struct Node *p) {
    while (p != NULL) {
        printf("%d\n", p->value);
        p = p->next;
    }
}

int main() {
    int array[] = {1, 2, 3};
    createLinkedList(array, sizeof(array) / sizeof(array[0]));
    insertHead(0);
    display(head);

    printf("----\n");

    deleteElement(1);
    display(head);

    return 0;
}