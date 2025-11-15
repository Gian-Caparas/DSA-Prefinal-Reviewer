#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createNode(int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void display(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
}

void deleteFirst(Node** head) {
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(Node** head){
    Node* temp = *head;
    Node* prev = NULL;

    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteEven(Node** head){
    Node* current = *head;
    Node* prev = NULL;

    while(current!=NULL){
        if(current->data % 2 ==0){
            if(current==*head){
                *head = (*head)->next;
                free(current);
                current = *head;
            }else{
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        }else{
            prev = current;
            current = current->next;
        }
    }

}

void deleteOdd(Node** head){
    Node* current = *head;
    Node* prev = NULL;

    while(current!=NULL){
        if(current->data % 2 !=0){
            if(current==*head){
                *head = (*head)->next;
                free(current);
                current = *head;
            }else{
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        }else{
            prev = current;
            current = current->next;
        }
    }
}

void deleteSelect(Node** head, int select){
    if (*head == NULL){printf("Empty linked-list");}

    Node* temp = *head;
    Node* prev = NULL;

    if (temp->data == select) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = temp->next;

    while (current!=NULL) {
        if (current->data == select) {
            prev->next = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

void deleteAtIndex(Node** head, int index){
    if (*head == NULL){printf("Empty linked-list");}

    Node* temp = *head;
    Node* prev = NULL;
    if(index==1){
        *head = (*head)->next;
        free(temp);
        return;
    }
    int count = 1;
    while(temp!=NULL && count!=index){
        prev = temp;
        count++;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);

}

void deleteAll(Node** head) {
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