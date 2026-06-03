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

void prepend(DoublyLinkedList* list, int value){
    if(list == NULL) return;

    Node* newNode = createNode(value);
    if (newNode == NULL) return;

    newNode->next = list->head;
    if(list->head != NULL){
        list->head->prev = newNode;
    }
    else{
        list->tail = newNode;
    }
    list->head = newNode;
    list->size++;
}

void deleteNode(DoublyLinkedList* list , int index){
    if(list == NULL || index < 0 || index >= list->size){
        return;
    }
    Node* curr = list->head;
    for(int i = 0; i < index; i++){
        curr = curr->next;
    }
    if(curr == list->head){
        list->head = list->head->next;
    }
    else{
        curr->prev->next = curr->next;
    }
    if(curr == list->tail){
        list->tail = curr->prev;
    }
    else{
        curr->next->prev = curr->next;
    }
    free(curr);
    list->size--;
}
void insertNode(DoublyLinkedList* list, int index, int value){
    if(list == NULL || index < 0 || index > list->size){
        return;
    }
    if(index == 0){
        prepend(list,value);
        return;
    }
    if(index == list->size){
        append(list,value);
        return;
    }
    Node* newNode = createNode(value);
    if(newNode == NULL){
        return;
    }
    int i = 0;
    Node* curr = list->head;
    while(i < index){
        curr = curr->next;
        i++;
    }
    curr->prev->next = newNode;
    newNode->prev = curr->prev;
    newNode->next = curr;
    curr->prev = newNode;
    list->size++;
}
