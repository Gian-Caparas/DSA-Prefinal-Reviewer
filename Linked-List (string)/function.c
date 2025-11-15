//
// Created by gianc on 11/5/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

Node* createNode(char text[]) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->word, text);
    newNode->next = NULL;

    return newNode;
}

void display(Node* head) {
    printf("Original linked-list:\n");
    while (head!=NULL) {
        printf("%s", head->word);
        if (head->next!=NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
}