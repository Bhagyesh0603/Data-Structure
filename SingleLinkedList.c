#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Function prototypes
void insert_as_headnode();
void insert_as_lastnode();
void insert_after_a_node();
void delete_headnode();
void delete_after_a_node();
void delete_lastnode();
void disp();
void search();

int main() {
    int choice;
    do {
        printf("\n----- Menu -----\n");
        printf("1) Insert as Head Node\n");
        printf("2) Insert as Last Node\n");
        printf("3) Insert After a Node\n");
        printf("4) Delete Head Node\n");
        printf("5) Delete a Node After Given Node\n");
        printf("6) Delete Last Node\n");
        printf("7) Display List\n");
        printf("8) Search an Element\n");
        printf("9) Exit\n");
        printf("-----------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_as_headnode();
                break;
            case 2:
                insert_as_lastnode();
                break;
            case 3:
                insert_after_a_node();
                break;
            case 4:
                delete_headnode();
                break;
            case 5:
                delete_after_a_node();
                break;
            case 6:
                delete_lastnode();
                break;
            case 7:
                disp();
                break;
            case 8:
                search();
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);
    return 0;
}

// Insert a new node at the beginning
void insert_as_headnode() {
    printf("Enter Element: ");
    int item;
    scanf("%d", &item);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = head;
    head = newnode;
    printf("Item added as head node successfully.\n");
}

// Insert a new node at the end
void insert_as_lastnode() {
    printf("Enter Element: ");
    int item;
    scanf("%d", &item);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    printf("Item added as last node successfully.\n");
}

// Insert a new node after a given node
void insert_after_a_node() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("After which node data should the new element be inserted? ");
    int a;
    scanf("%d", &a);
    struct node* ptr = head;

    while (ptr != NULL && ptr->data != a) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with data %d not found.\n", a);
        return;
    }

    printf("Enter Element: ");
    int item;
    scanf("%d", &item);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = ptr->next;
    ptr->next = newnode;
    printf("Item added successfully after %d.\n", a);
}

// Delete the head node
void delete_headnode() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("%d is deleted from the list.\n", head->data);
    head = head->next;
    free(temp);
}

// Delete a node after a given node
void delete_after_a_node() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Position of node to delete: ");
    int a;
    scanf("%d", &a);
    struct node* ptr = head;

    for (int i = 1; ptr != NULL && i < a; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL) {
        printf("No node exists at the given position.\n");
        return;
    }

    struct node* temp = ptr->next;
    printf("%d is deleted from the list.\n", temp->data);
    ptr->next = temp->next;
    free(temp);
}

// Delete the last node
void delete_lastnode() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("%d last node deleted.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct node* ptr = head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }

    printf("%d last node deleted.\n", ptr->next->data);
    free(ptr->next);
    ptr->next = NULL;
}

// Display the list
void disp() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements:\n");
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Search for an element in the list
void search() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the element to search: ");
    int item, pos = 1;
    scanf("%d", &item);
    struct node* ptr = head;

    while (ptr != NULL) {
        if (ptr->data == item) {
            printf("Element %d found at position %d.\n", item, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", item);
}
