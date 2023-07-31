#include <stdio.h>
#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

int probe(int hashTable[], int key) {

    int i = 0;
    int index = hash(key);

    while (hashTable[(index + i)%SIZE] != 0) {
        i++;
    }
    return (index + i) % SIZE;
}

void insert(int hashTable[], int key) {
    int currentIndex = hash(key);
    int newIndex;

    if (hashTable[currentIndex] == 0) {
        hashTable[currentIndex] = key;
    }
    else {
        newIndex = probe(hashTable, key);
        hashTable[newIndex] = key;
    }
}

int search(int hashTable[], int key) {
    int index = hash(key);
    
    int i = 0;

    while (hashTable[(index + i) % SIZE] != key) {
        if (hashTable[(index + i) % SIZE] != 0) {
            i++;
        }
        else {
            return -1;
        }
    }

    return (index + i) % SIZE;
}

void display(int hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}


int main() {
    int hashTable[10] = {0};

    insert(hashTable, 1);
    insert(hashTable, 2);

    display(hashTable);

    printf("Key found at %d\n", search(hashTable, 3));

    return 0;
}