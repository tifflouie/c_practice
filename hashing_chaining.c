#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **head_ref, int value) {
    struct Node *new_node, *previous = NULL, *current = *head_ref;

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node; // Insert as the first node in the empty list
    } else {
        while (current && current->data < value) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) {
            new_node->next = *head_ref; // Insert as the new first node
            *head_ref = new_node;
        } else {
            new_node->next = previous->next; // Insert after the previous node
            previous->next = new_node;
        }
    }
}

struct Node *Search(struct Node *head, int key) {
    while (head != NULL) {
        if (key == head->data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int hash(int key) {
    return key % 10;
}

void Insert(struct Node *hash_table[], int key) {
    int index = hash(key);
    SortedInsert(&hash_table[index], key);
}

int main() {
    struct Node *hash_table[10];
    struct Node *temp;
    int i;

    for (i = 0; i < 10; i++)
        hash_table[i] = NULL;

    Insert(hash_table, 12);
    Insert(hash_table, 22);
    // Insert(hash_table, 42);

    temp = Search(hash_table[hash(22)], 22);

    if (temp == NULL) {
        printf("Item not found.\n");
    } else {
        printf("Item found: %d\n", temp->data);
    }

    return 0;
}
