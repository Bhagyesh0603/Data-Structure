#include <stdio.h> 

#include <stdlib.h> 

 

struct node { 

    int data; 

    struct node* next; 

}; 

 

struct node* head = NULL; 

 

void insert_as_headnode() { 

    printf("Enter Element: "); 

    int item; 

    scanf("%d", &item); 

    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 

    newnode->data = item; 

    newnode->next = head; 

    head = newnode; 

    printf("Item added to the list successfully\n"); 

} 

 

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

    printf("Item added to the list successfully\n"); 

} 

 

void insert_after_a_node() { 

    if (head == NULL) { 

        printf("List is empty.\n"); 

        return; 

    } 

 

    printf("After which node data should be entered: "); 

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

    printf("Item added to the list successfully\n"); 

} 

 

void disp() { 

    if (head == NULL) { 

        printf("List is Empty\n"); 

        return; 

    } 

    struct node* ptr = head; 

    while (ptr != NULL) { 

        printf("%d \n", ptr->data); 

        ptr = ptr->next; 

    } 

} 

 

void delete_headnode() { 

    if (head == NULL) { 

        printf("List Is Empty\n"); 

        return; 

    } 

    struct node* temp = head; 

    printf("%d is deleted from the list\n", head->data); 

    head = head->next; 

    free(temp); 

} 

 

void delete_after_a_node() { 

    if (head == NULL) { 

        printf("List Is Empty\n"); 

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

    printf("%d is deleted from the list\n", temp->data); 

    ptr->next = temp->next; 

    free(temp); 

} 

 

void delete_lastnode() { 

    if (head == NULL) { 

        printf("List Is Empty\n"); 

        return; 

    } 

 

    if (head->next == NULL) { 

        printf("%d last node deleted\n", head->data); 

        free(head); 

        head = NULL; 

        return; 

    } 

 

    struct node* ptr = head; 

    while (ptr->next->next != NULL) { 

        ptr = ptr->next; 

    } 

 

    printf("%d last node deleted\n", ptr->next->data); 

    free(ptr->next); 

    ptr->next = NULL; 

} 

int main() { 

  int choice; 

    do { 

        printf("\n1) Insertion\n"); 

        printf("2) Deletion\n"); 

        printf("3) Display\n"); 

        printf("4) Exit\n"); 

        printf("Enter your choice: "); 

        scanf("%d", &choice); 

 

        switch (choice) { 

            case 1: { 

                printf("\n1) Insertion as Head Node"); 

                printf("\n2) Insertion as Last Node"); 

                printf("\n3) Insertion After a Node\n"); 

                int ch; 

                scanf("%d", &ch); 

                switch (ch) { 

                    case 1: insert_as_headnode(); break; 

                    case 2: insert_as_lastnode(); break; 

                    case 3: insert_after_a_node(); break; 

                    default: printf("Invalid choice\n"); 

                } 

                break; 

            } 

            case 2: { 

                printf("\n1) Delete Head Node"); 

                printf("\n2) Delete Last Node"); 

                printf("\n3) Delete Node After a Given Node\n"); 

                int ch1; 

                scanf("%d", &ch1); 

                switch (ch1) { 

                    case 1: delete_headnode(); break; 

                    case 2: delete_lastnode(); break; 

                    case 3: delete_after_a_node(); break; 

                    default: printf("Invalid choice\n"); 

                } 

                break; 

            } 

            case 3: 

                disp(); 

                break; 

            case 4: 

                printf("Exiting...\n"); 

                break; 

            default: 

                printf("Invalid choice\n"); 

        } 

    } while (choice != 4); 

    return 0; 

} 