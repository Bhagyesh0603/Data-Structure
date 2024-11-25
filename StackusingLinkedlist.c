#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

int isempty(struct node *top) {
    return (top == NULL);
}

struct node *push(struct node *top) {
    printf("Enter element to push: ");
    int a;
    scanf("%d", &a);

    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = a;
    new->next = top;
    top = new;
    return top;
}

struct node *pop(struct node *top) {
    if (isempty(top)) {
        printf("Stack is empty\n");
        return top;
    }

    struct node *ptr = top;
    printf("Data deleted: %d\n", top->data);
    top = top->next;
    free(ptr);
    return top;
}

void display(struct node *top) {
    if (isempty(top)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    struct node *ptr = top;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}