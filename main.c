#include "DoublyLinkedList.h"
#include "Node.h"
#include <stdio.h>

int main(){
    DoublyLinkedList* list = createDoublyLinkedList();
    append(list,1);
    //append(list,20);
    //printAllNodes(list);
    printf("%p\n",&list);
    printf("%p\n",list->head);
    printf("%p",list->tail);
    freeDoublyLinkedList(list);
    list = NULL;

    return 0;
}