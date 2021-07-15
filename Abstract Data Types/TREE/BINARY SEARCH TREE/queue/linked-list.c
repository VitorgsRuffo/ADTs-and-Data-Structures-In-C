#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/*
* Linked list is a data structure. We can use it to implement Queue abstract data type.
*/

typedef struct node {
    Data data;
    struct node* next;
}node;

typedef struct {
    int size;
    node* head;
    node* tail;
}linkedList;

Queue newQueue(void){
    linkedList* list = (linkedList*) malloc(sizeof(linkedList));
    if(list == NULL) return NULL;
    
    (*list).size = 0;
    (*list).head = NULL;
    (*list).tail = NULL;

    return list;
}

int queueSize(Queue Q){
    if(Q == NULL) return -1;
    linkedList* list = (linkedList*) Q;
    return (*list).size;
}

int isQueueEmpty(Queue Q){
    if(Q == NULL) return -1;
    linkedList* list = (linkedList*) Q;
    if((*list).head == NULL) return 1;
    else                     return 0;
}

int enqueue(Queue Q, Data data){
    if(Q == NULL || data == NULL) return 0;
    linkedList* list = (linkedList*) Q;

    node* new = (node*) malloc(sizeof(node));
    if(new == NULL) return 0;
    (*new).data = data;
    (*new).next = NULL;

    if((*list).head == NULL && (*list).tail == NULL){ //queue is empty

        (*list).head = new;
        (*list).tail = new;

    }else{ //queue is not empty  

        (*((*list).tail)).next = new;
        (*list).tail = new;

    }

    (*list).size++;
    return 1;
}

Data dequeue(Queue Q){
    if(Q == NULL) return NULL;
    linkedList* list = (linkedList*) Q;

    node* head = (*list).head;
    if(head == NULL) return NULL; //queue is empty

    if(head == (*list).tail){ //queue has only one element

        (*list).head = NULL;
        (*list).tail = NULL;

    }else //queue has more than one element
        (*list).head = (*((*list).head)).next;
    
    Data dequeueElement = (*head).data;
    free(head);
    (*list).size--;
    return dequeueElement;
}

Data peek(Queue Q){
    if(Q == NULL) return NULL;
    linkedList* list = (linkedList*) Q;

    node* head = (*list).head;
    if(head == NULL) return NULL; //queue is empty
    else             return (*head).data;
}

void printQueue(Queue Q, dataToString function){
    if(Q == NULL || function == NULL || isQueueEmpty(Q)) return;
    linkedList* list = (linkedList*) Q;

    char* dataString;
    node* current = (*list).head;
    int j = 1;
    while(current != NULL){
        
        printf("[%d](%s)\n", j, dataString =  (*function)((*current).data));
        free(dataString);
        current = (*current).next;
        j++;
    }
    printf("\n");
}

void freeQueue(Queue Q, freeData function){
    if(Q == NULL) return;
    linkedList* list = (linkedList*) Q;

    node* current = (*list).head;
    node* aux;

    while(current != NULL){

        if(function != NULL) //client also wants to free the elements in the queue.
            (*function)((*current).data);
        
        aux = current;
        current = (*current).next;

        free(aux);
    }
    
    free(list);
}