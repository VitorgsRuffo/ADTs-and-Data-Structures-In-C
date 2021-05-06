#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*
* Linked list is a data structure. We can use it to implement LIST abstract data type.
*/

typedef struct node {
    Data data;
    struct node* next;
}node;

typedef struct {
    int size;
    node* first;
    node* last;
}list;


List newList(){
    list* li = (list*) malloc(sizeof(list));
    if(li == NULL) return NULL;

    (*li).size = 0;
    (*li).first = NULL;
    (*li).last = NULL;

    return li;
}


int listSize(List Li){
    if(Li == NULL) return -1;
    list* li = (list*) Li;
    return (*li).size;
}


int isListEmpty(List Li){
    if(Li == NULL) return 1;
    list* li = (list*) Li;
    if((*li).size == 0) return 1;
    else                return 0;
}


int listAdd(List Li, Data data){
    if(Li == NULL || data == NULL) return 0;
    list* li = (list*) Li;

    node* newNode = (node*) malloc(sizeof(node));
    (*newNode).data = data;
    (*newNode).next = NULL;
    
    if((*li).last == NULL){ //If list is empty.
        
        (*li).first = newNode;
        (*li).last = newNode;

    }else{ 

        (*((*li).last)).next = newNode;
    }

    (*li).size++;
    return 1;
}


int listAddAt(List Li, int position, Data data){
    if(Li == NULL || data == NULL) return 0;
    list* li = (list*) Li;
    if(position < 0 || position > (*li).size) return 0; //if (position is invalid)
    
    node* newNode = (node*) malloc(sizeof(node));
    (*newNode).data = data;
    
    if(position == 0){ //insertion at the beginning
        (*newNode).next = (*li).first;
        (*li).first = newNode;
    
    }else{ //insertion at the middle or end

        //Firstly we need a reference to the position-1 node:
        node* currentNode = (*li).first;
        for(int i = 0; i <= position-2; i++)
            currentNode = (*currentNode).next;

        
        (*newNode).next = (*currentNode).next;
        (*currentNode).next = newNode;
    }

    (*li).size++;
    return 1;
}


Data listGet(List Li, int position){
    if(Li == NULL) return NULL;
    list* li = (list*) Li;
    if(position < 0 || position >= (*li).size) return NULL; //if (position is invalid)

    node* currentNode = (*li).first;
    int i = 0;
    while(currentNode != NULL){
        
        if(i == position)
            return (*currentNode).data;        
        
        currentNode = (*currentNode).next;
        i++;
    }

    return NULL;
}

Data listRemove(List Li, int position){
    if(Li == NULL) return NULL;
    list* li = (list*) Li;
    if(position < 0 || position >= (*li).size) return NULL; //if (position is invalid)

    Data removedData = NULL;
    node* currentNode = (*li).first;

    if(position == 0){ //deletion at the beginning

        (*li).first = (*((*li).first)).next;
        removedData = (*currentNode).data;
        free(currentNode);

    }else{ //deletion at the middle or end

        //Firstly we need a reference to the position-1 node:
        for(int i = 0; i <= position-2; i++)
            currentNode = (*currentNode).next;

        node* temp = (*currentNode).next;
        (*currentNode).next = (*temp).next;

        removedData = (*temp).data;
        free(temp);

    }

    return removedData;
}

void reverseIteratively(list* li);
void reverseRecursively(list* li, node* n);

void listReverse(List Li){
    if(Li == NULL) return;
    list* li = (list*) Li;

    reverseIteratively(li);
    //reverseRecursively(li, (*li).first);
}

void reverseIteratively(list* li){

    node* first; node* current; node* previous; node* next;
    first = (*li).first;
    current = (*li).first;
    previous = NULL;

    while(current != NULL){

        next = (*current).next;
        (*current).next = previous;
        previous = current;
        current = next;
    }

    (*li).first = previous;
    (*li).last = first;
}

void reverseRecursively(list* li, node* n){ //there is a problem in this function: at the end the (*li).last pointer is not adjusted and keeps pointing to the first node.
    
    if((*n).next == NULL){ //exit condition
        (*li).first = n;
        return;
    }

    reverseRecursively(li, (*n).next);

    node* tempN = (*n).next;
    (*tempN).next = n;
    (*n).next = NULL;
}

void printList(List Li, dataToString function){
    if(Li == NULL || function == NULL) return;
    list* li = (list*) Li;

    printf("List:\n->");
    char* string;
    node* currentNode = (*li).first;
    while(currentNode != NULL){
        
        printf("[%s]->", string = (*function)((*currentNode).data));
        free(string);
        currentNode = (*currentNode).next;
    }
    printf("\n\n");
}

void freeList(List Li, freeData function){
    if(Li == NULL) return;
    list* li = (list*) Li;

    node* currentNode = (*li).first;
    node* temp;

    while(currentNode != NULL){
        
        if(function != NULL) //user also wants to free the list elements.
            (*function)((*currentNode).data);
        
        temp = currentNode;
        currentNode = (*currentNode).next;
        free(temp);
    }
    
    free(li);
}