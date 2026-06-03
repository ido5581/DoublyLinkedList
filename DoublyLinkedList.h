#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"

typedef struct DoublyLinkedList{
    int size;
    Node* tail;
    Node* head;
}DoublyLinkedList;

DoublyLinkedList* createDoublyLinkedList();
void freeDoublyLinkedList(DoublyLinkedList* list);
void prepend(DoublyLinkedList* list, int value);
void append(DoublyLinkedList* a, int value);
void printAllNodes(DoublyLinkedList* list);
void deleteNode(DoublyLinkedList* list, int index);
void insertNode(DoublyLinkedList* list, int index, int value);
#endif