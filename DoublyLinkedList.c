#include "DoublyLinkedList.h"
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

DoublyLinkedList* createDoublyLinkedList(){
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if(list == NULL) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
void append(DoublyLinkedList* list, int value){
    if(list == NULL) return;
    Node* newNode = createNode(value);
    if(newNode == NULL) return;

    if(list->size == 0){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void freeDoublyLinkedList(DoublyLinkedList* list){
    if(list == NULL) return;
    while(list->head){
        Node* temp = list->head;
        list->head = list->head->next;
        freeNode(temp);
    }
    free(list);
}

void printAllNodes(DoublyLinkedList* list){
    Node* temp = list->head;
    for(int i = 0; i < list->size; i++){
        printf("Node #%d: %d\n",i+1,temp->value);
        temp = temp->next;
    }
}




