#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
int hash_table[TABLE_SIZE];
int EMPTY = -1;

// Initialize the hash table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = EMPTY;
    }
}

// Hash function
int hash_function(int key) {
    return key % TABLE_SIZE;
}

// Insert a key into the hash table
void insert(int key) {
    int original_index = hash_function(key);
    int index = original_index;

    // Linear probing to find an empty slot
    while (hash_table[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) { // Full loop means the table is full
            printf("HashTable is Full\n");
            return;
        }
    }
    hash_table[index] = key;
    printf("Insertion successful at index: %d\n", index);
}

// Search for a key in the hash table
int search(int key) {
    int original_index = hash_function(key);
    int index = original_index;

    // Linear probing to search for the key
    while (hash_table[index] != EMPTY) {
        if (hash_table[index] == key) {
            return index; // Key found
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) { // Full loop means the key is not found
            break;
        }
    }
    return -1; // Key not found
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != EMPTY) {
            printf("Index %d: %d\n", i, hash_table[i]);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}

// Main function with menu-driven implementation
int main() {
    int choice, key;
    initialize();

    do {
        printf("\n--Menu--\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            int result = search(key);
            if (result == -1) {
                printf("Key not found.\n");
            } else {
                printf("Key found at index: %d\n", result);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid input! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
