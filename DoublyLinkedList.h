#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"

typedef struct DoublyLinkedList{
    int size;
    Node* tail;
    Node* head;
}DoublyLinkedList;

DoublyLinkedList* createDoublyLinkedList();
void append(DoublyLinkedList* a, int value);
void freeDoublyLinkedList(DoublyLinkedList* list);
void printAllNodes(DoublyLinkedList* list);
void prepend(DoublyLinkedList* list, int value);
void deleteNode(DoublyLinkedList* list , int index);
#endif