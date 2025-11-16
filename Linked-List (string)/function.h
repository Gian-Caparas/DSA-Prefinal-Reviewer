//
// Created by gianc on 11/5/2025.
//

#ifndef PREFINALS_DSA_FUNCTION_H
#define PREFINALS_DSA_FUNCTION_H

typedef  struct node {
    char word[50];
    struct node* next;
}Node;

Node* createNode(char text[]);
void display(Node* head);
void deleteFirst(Node** head);
void deleteLast(Node** head);
void deleteWord(Node** head, char wordDelete[]);
void deleteIndex(Node** head, int index);
void deleteAllNodes(Node** head);
#endif //PREFINALS_DSA_FUNCTION_H
