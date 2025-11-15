#ifndef C_PROGRAMMIN_LANGUAGE_MAIN_H
#define C_PROGRAMMIN_LANGUAGE_MAIN_H

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int val);
void display(Node* head);
void deleteFirst(Node** head);
void deleteLast(Node** head);
void deleteEven(Node** head);
void deleteOdd(Node** head);
void deleteSelect(Node** head, int select);
void deleteAtIndex(Node** head, int index);
void deleteAll(Node** head);

#endif // C_PROGRAMMIN_LANGUAGE_MAIN_H
