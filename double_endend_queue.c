#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Check if the deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Insert at the front of the deque
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = value;
}

// Insert at the rear of the deque
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}

// Delete from the front of the deque
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1; // Reset deque
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete from the rear of the deque
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from rear: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1; // Reset deque
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Display the elements of the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", deque[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nDouble-Ended Queue (Deque) Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
