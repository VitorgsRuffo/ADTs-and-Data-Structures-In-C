#include <stdlib.h>
#include <stdio.h>
#include "../queue.h"

/*
* Circular array is a data structure. We can use it to implement Queue abstract data type.
* Obs: this array is called circular because we consider the first element as next of the last element (index after capacity-1 is 0). 
*      In order to get the index of the next element we do (i + 1) % N, N being array capacity.
*
* Disadvantages: 
*       - most of the times not all allocated space is gonna be used;
*       - when queue gets full we've got to create a larger one and copy all elements to it. 
*/

#define INITIAL_CAPACITY 3

typedef struct {
    int capacity;   //maximum number of elements that can be enqueued.
    int size;       //current number of enqueued elements.
    int head, tail; //front and rear of the queue, respectively.
    Data* elements;
}array;

/*  example:
*    0 1 2 3 4 5
*   [? ? a b c ?]
*   capacity = 6, head = 2, tail = 4.
*/

Queue newQueue(void){
    array* arr = (array*) malloc(sizeof(array));
    if(arr == NULL) return NULL;

    (*arr).capacity = INITIAL_CAPACITY;
    (*arr).size = 0;
    (*arr).head = -1;
    (*arr).tail = -1;
    (*arr).elements = (Data*) malloc(INITIAL_CAPACITY * sizeof(Data));
    if((*arr).elements == NULL){
        free(arr);
        return NULL;
    }

    return arr;
}

int isQueueEmpty(Queue Q){
    if(Q == NULL) return 1;
    array* arr = (array*) Q;
    if((*arr).size <= 0) return 1;
    else                 return 0;
}

int queueSize(Queue Q){
    if(Q == NULL) return -1;
    array* arr = (array*) Q;
    return (*arr).size;
}

//private function
int isQueueFull(array* arr){
    if( (((*arr).tail + 1) % (*arr).capacity) == (*arr).head ) return 1; //if head of queue is one position after tail of queue, queue is full.
    else return 0;
}

int enqueue(Queue Q, Data data){
    if(Q == NULL || data == NULL) return 0;
    array* arr = (array*) Q;
    
    if(isQueueFull(arr)) 
        return 0; //increase array size (obs: this functionality hasn't been implemented)

    else if(isQueueEmpty(Q)){
        (*arr).head = 0;
        (*arr).tail = 0;
    
    }else
        (*arr).tail = ((*arr).tail + 1) % (*arr).capacity;
    
    (*arr).elements[(*arr).tail] = data;
    (*arr).size++;
    return 1;
}

Data dequeue(Queue Q){
    if(Q == NULL) return NULL;
    array* arr = (array*) Q;

    if(isQueueEmpty(Q))  
        return NULL;
    
    Data headElement = (*arr).elements[(*arr).head];
    
    if((*arr).head == (*arr).tail){ //there is only one element in the queue
        
        (*arr).head = -1;
        (*arr).tail = -1;
    
    }else
        (*arr).head = ((*arr).head + 1) % (*arr).capacity;
    
    (*arr).size--;
    return headElement;
}

Data peek(Queue Q){
    if(Q == NULL || isQueueEmpty(Q)) return NULL;
    array* arr = (array*) Q;
    return (*arr).elements[(*arr).head];
}

void printQueue(Queue Q, dataToString function){
    if(Q == NULL || function == NULL || isQueueEmpty(Q)) return;
    array* arr = (array*) Q;

    char* string;
    int i = (*arr).head, j = 1;
    while(1){
    
        printf("[%d](%s)\n", j, string =  (*function)((*arr).elements[i]));
        free(string);

        if(i == (*arr).tail) break;

        i = (i + 1) % (*arr).capacity;
        j++;
    }
    printf("\n\n");
}

void freeQueue(Queue Q, freeData function){
    if(Q == NULL) return;
    array* arr = (array*) Q;

    if(function != NULL && !isQueueEmpty(Q)){ //client also wants to desalocate data elements.
        int i = (*arr).head;
        while(1){

            (*function)((*arr).elements[i]);
            
            if(i == (*arr).tail) break;

            i = (i + 1) % (*arr).capacity;
        }
    }

    free((*arr).elements);
    free(arr);
}