#include <stdio.h>
#include <stdlib.h>
#define max 5

int stack1[max], top1 = -1;
int stack2[max], top2 = -1;

// Function to check if a stack is empty
int isempty(int top) {
    return top == -1;
}

// Function to check if a stack is full
int isfull(int top) {
    return top == max - 1;
}

// Function to enqueue an element
void enqueue(int value) {
    if (isfull(top1)) {
        printf("Queue is full\n");
        return;
    }
    stack1[++top1] = value;
}

// Function to dequeue an element
int dequeue() {
    if (isempty(top2)) {
        if (isempty(top1)) {
            printf("Queue underflow\n");
            return -1; // Return -1 to indicate underflow
        } else {
            // Transfer all elements from stack1 to stack2
            while (!isempty(top1)) {
                stack2[++top2] = stack1[top1--];
            }
        }
    }
    return stack2[top2--]; // Pop from stack2
}

// Function to display the queue elements
void display() {
    if (isempty(top1) && isempty(top2)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: \n");
    
    // Print elements from stack2 in reverse order
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    // Print elements from stack1 in forward order
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Using Two Stacks (Menu)");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
