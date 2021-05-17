#include <stdlib.h>
#include <stdio.h>
#include "../stack.h"

/*
* Array is a data structure. We can use it to implement Stack abstract data type.
*/

#define INITIAL_CAPACITY 10

typedef struct {
    int capacity;
    int top;
    Data* elements;
}array;


Stack newStack(void){
    array* arr = (array*) malloc(sizeof(array));
    if(arr == NULL) return NULL;

    (*arr).capacity = INITIAL_CAPACITY;
    (*arr).top = -1;
    (*arr).elements = (Data*) malloc(INITIAL_CAPACITY * sizeof(Data));
    if((*arr).elements == NULL){
        free(arr);
        return NULL;
    }

    return arr;
}

int stackSize(Stack St){
    if(St == NULL) return -1;
    array* arr = (array*) St;
    return ((*arr).top + 1);
}

int isStackEmpty(Stack St){
    if(St == NULL) return -1;
    array* arr = (array*) St;

    if((*arr).top == -1) return 1;
    else                 return 0;
}

int stackPush(Stack St, Data data){
    if(St == NULL || data == NULL) return 0;
    array* arr = (array*) St;

    (*arr).top++;
    if((*arr).top == (*arr).capacity){ //stack is full. We need to resize it.

        Data* newArray = (Data*) malloc((2 * (*arr).capacity) * sizeof(Data));
        if(newArray == NULL) return 0;

        for(int i = 0; i<(*arr).capacity; i++)
            newArray[i] = (*arr).elements[i];
        
        free((*arr).elements);
        (*arr).elements = newArray;
    }

    *((*arr).elements + (*arr).top) = data; //arr->elements[arr->top] = data;
    return 1;
}


Data stackPop(Stack St){
    if(St == NULL) return NULL;
    array* arr = (array*) St;

    if((*arr).top == -1) return NULL;

    Data popedElement = (*arr).elements[(*arr).top];
    (*arr).top--;

    return popedElement;
}


Data stackTop(Stack St){
    if(St == NULL) return NULL;
    array* arr = (array*) St;

    if((*arr).top == -1) return NULL;

    Data element = (*arr).elements[(*arr).top];
    return element;
}

void printStack(Stack St, dataToString function){
    if(St == NULL || function == NULL) return;
    array* arr = (array*) St;

    char* dataString;
    printf("top-> ");
    for(int i = (*arr).top; i > -1; i--){
        if(i == (*arr).top) 
            printf("%s\n", dataString = (*function)((*arr).elements[i]));
        else
            printf("      %s\n", dataString = (*function)((*arr).elements[i]));
        free(dataString);
    }
    printf("\n");
}

void freeStack(Stack St, freeData function){
    if(St == NULL) return;
    array* arr = (array*) St;

    if(function != NULL) //client wants to free the data stored in the stack.
        for(int i = 0; i<=(*arr).top; i++)
            (*function)((*arr).elements[i]);
        
    free((*arr).elements);
    free(arr);
}