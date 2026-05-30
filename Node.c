#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return NULL;
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

void freeNode(Node* n){
    if(n == NULL) return;
    free(n);
}