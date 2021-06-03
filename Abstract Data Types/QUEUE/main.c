#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#include "queue.h"

void menu(Queue queue);
void enq(Queue queue);
void deq(Queue queue);
void pk(Queue queue);

int main(){

    Queue queue = newQueue();

    int option;
    do {
        menu(queue);
        scanf("%d", &option);
        switch(option){
            case 1:
                enq(queue);
                break;
            case 2:
                deq(queue);
                break;
            case 3:
                pk(queue);
                break;
            case 4:
                printf("\nexiting...\n\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
    }while(option != 4);

    freeQueue(queue, freeAdt);
    return 0;
}

void menu(Queue queue){
    printf("\n\n------------------QUEUE:------------------\n\n");
    printQueue(queue, adtToString);
    printf("\n1 - enqueue.\n");
    printf("2 - dequeue.\n");
    printf("3 - peek.\n");
    printf("4 - exit.\n");
    printf("------------------------------------------\n\n");
}

void enq(Queue queue){
    double x, y;
    char z[50];
    printf("\nCreate data element:\n");
    printf("x (double): ");
    scanf("%lf", &x);
    printf("y (double): ");
    scanf("%lf", &y);
    printf("z (string): ");
    scanf("%s", z);
    Adt adt = newAdt(x, y, z);
    enqueue(queue, adt);
}

void deq(Queue queue){
    Adt adt = dequeue(queue);
    if(adt == NULL) return;
    char* adtString = adtToString(adt);
    printf("\nDequeued element:\n%s.\n", adtString);
    free(adtString);
    freeAdt(adt);
}

void pk(Queue queue){
    Adt adt = peek(queue);
    if(adt == NULL) return;
    char* adtString = adtToString(adt);
    printf("\nFront element:\n%s.\n", adtString);
    free(adtString);
}