//
// Created by gianc on 11/5/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main() {
    Node* head = NULL;
    Node* temp = NULL;
    int size;
    char text[50];

    printf("Enter the size of the linked-list: ");
    scanf("%d", &size);

    printf("Enter %d words:\n", size);
    for (int i=0; i<size; i++) {
        printf("Input the %d word: ", i+1);
        scanf(" %[^\n]s", text);
        Node* newNode = createNode(text);

        if (head==NULL) {
            head = newNode;
            temp = newNode;
        }else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Original linked-list");
    display(head);
    int choice;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Delete first node\n");
        printf("2. Delete last node\n");
        printf("3. Delete specific word\n");
        printf("4. Delete node at index\n");
        printf("5. Delete all nodes\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFirst(&head); break;
            case 2:
                deleteLast(&head); break;
            case 3:
                char wordDelete[50];
                printf("What word?: ");
                scanf("%[^\n]s", wordDelete);
                deleteWord(&head, wordDelete);
                break;
            case 4:
                int index;
                printf("What index: ");
                scanf("%d", &index);
                deleteIndex(&head, index);
                break;
            case 5:
                deleteAllNodes(&head); break;
        }
        printf("Updated linked-list\n");
        display(head);

    }while (choice!=6);
    printf("\n----EXITED!----\n");

    return 0;
}

