#include <stdlib.h>
#include <stdio.h>
#include "../stack.h"

/*
* Linked list is a data structure. We can use it to implement Stack abstract data type.
*/

typedef struct node {
    Data data;
    struct node* next;
}node;

typedef struct {
    int size;
    node* top;
}linkedList;


Stack newStack(void){
    linkedList* list = (linkedList*) malloc(sizeof(linkedList));
    if(list == NULL) return NULL;
    
    (*list).size = 0;
    (*list).top = NULL;

    return list;
}

int stackSize(Stack St){
    if(St == NULL) return -1;
    linkedList* list = (linkedList*) St;
    return (*list).size;
}

int isStackEmpty(Stack St){
    if(St == NULL) return -1;
    linkedList* list = (linkedList*) St;

    if((*list).top == NULL) return 1;
    else                    return 0;
}

int stackPush(Stack St, Data data){
    if(St == NULL || data == NULL) return 0;
    linkedList* list = (linkedList*) St;

    node* new = (node*) malloc(sizeof(node));
    if(new == NULL) return 0;
    (*new).data = data;
    (*new).next = (*list).top;

    (*list).top = new;
    (*list).size++;
    return 1;
}


Data stackPop(Stack St){
    if(St == NULL) return NULL;
    linkedList* list = (linkedList*) St;
    if((*list).top == NULL) return NULL;

    node* top = (*list).top;
    (*list).top = (*top).next;

    Data popedElement = (*top).data;
    free(top);
    (*list).size--;
    return popedElement;
}


Data stackTop(Stack St){
    if(St == NULL) return NULL;
    linkedList* list = (linkedList*) St;
    if((*list).top == NULL) return NULL;

    return (*((*list).top)).data;
}

void printStack(Stack St, dataToString function){
    if(St == NULL || function == NULL) return;
    linkedList* list = (linkedList*) St;

    char* dataString;
    printf("top-> ");
    node* current = (*list).top;
    while(current != NULL){
        if(current == (*list).top) 
            printf("%s\n", dataString = (*function)((*current).data));
        else
            printf("      %s\n", dataString = (*function)((*current).data));
        free(dataString);
        current = (*current).next;
    }
    printf("\n");
}

void freeStack(Stack St, freeData function){
    if(St == NULL) return;
    linkedList* list = (linkedList*) St;

    node* current = (*list).top;
    while(current != NULL){
        if(function != NULL)//client also wants to free the elements in the stack.
            (*function)((*current).data);
        current = (*current).next;
        free((*list).top);
        (*list).top = current;
    }
    free(list);
}