#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#include "stack.h"

void menu(Stack stack);
void push(Stack stack);
void pop(Stack stack);
void top(Stack stack);

int main(){

    Stack stack = newStack(3);

    int option;
    do {
        menu(stack);
        scanf("%d", &option);
        switch(option){
            case 1:
                push(stack);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                top(stack);
                break;
            case 4:
                printf("\nexiting...\n\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
    }while(option != 4);

    freeStack(stack, freeAdt);
    return 0;
}

void menu(Stack stack){
    printf("\n\n------------------STACK:------------------\n");
    printStack(stack, adtToString);
    printf("\n1 - push.\n");
    printf("2 - pop.\n");
    printf("3 - top.\n");
    printf("4 - exit.\n");
    printf("------------------------------------------\n\n");
}

void push(Stack stack){
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
    stackPush(stack, adt);
}

void pop(Stack stack){
    Adt adt = stackPop(stack);
    if(adt == NULL) return;
    char* adtString = adtToString(adt);
    printf("\nPoped element:\n%s.\n", adtString);
    free(adtString);
    freeAdt(adt);
}

void top(Stack stack){
    Adt adt = stackTop(stack);
    if(adt == NULL) return;
    char* adtString = adtToString(adt);
    printf("\nTop element:\n%s.\n", adtString);
    free(adtString);
}