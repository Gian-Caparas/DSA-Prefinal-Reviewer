//
// Created by gianc on 11/5/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

Node* createNode(char text[]){
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->word, text);
    newNode->next = NULL;

    return newNode;
}

void display(Node* head){
    printf("Original linked-list:\n");
    while (head!=NULL) {
        printf("%s", head->word);
        if (head->next!=NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
}

void deleteFirst(Node** head){
    if(head == NULL){
        printf("Empty linked-list\n");
        return;
    }
    Node* current = (*head)->next;
    free(*head);
    *head = current;
}

void deleteLast(Node** head){
    if(head == NULL){
        printf("Empty linked-list\n");
        return;
    }

    Node* current = *head;
    Node* prev = NULL;
    while(current->next!=NULL){   
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

void deleteWord(Node** head, char wordDelete[]){
    if(head == NULL){
        printf("Empty linked-list\n");
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    while(current!=NULL && strcmp(current->word, wordDelete) != 0){
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    free(current);
}

void deleteIndex(Node** head, int index){
    if(head == NULL){
        printf("Empty linked-list\n");
        return;
    }

    Node* current = *head;
    Node* prev = NULL;
    int count = 1;

    if(index == count){
        *head = (*head)->next;
        free(current);
        return;
    }

    while(current!=NULL && index != count){
        prev = current;
        count++;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
}

void deleteAllNodes(Node** head){
    Node* current = *head;
    Node* nextNode = NULL;
    while (current!=NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
    printf("All nodes are deleted!");
}
