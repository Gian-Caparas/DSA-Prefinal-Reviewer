#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    Node* head = NULL;
    Node* temp = NULL;
    int size, val;

    printf("Enter size of the linked list: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Original linked-list: ");
    display(head);

    int choice;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Delete first node\n");
        printf("2. Delete last node\n");
        printf("3. Delete even numbers\n");
        printf("4. Delete odd numbers\n");
        printf("5. Delete specific node\n");
        printf("6. Delete node at index\n");
        printf("7. Delete all nodes\n");
        printf("8. Exit menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: deleteFirst(&head); break;
            case 2: deleteLast(&head); break;
            case 3: deleteEven(&head); break;
            case 4: deleteOdd(&head); break;
            case 5:
                int select;
                printf("What data?: ");
                scanf("%d", &select);
                deleteSelect(&head, select);
                break;
            case 6:
                int index;
                printf("At what index?: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7: deleteAll(&head); break;
        }
        printf("Updated linked list: ");
        display(head);
    }while (choice!=8);

    printf("\n----EXITED!----\n");

    return 0;
}
