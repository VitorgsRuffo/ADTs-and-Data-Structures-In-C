#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#include "list.h"

void menu(List list);
void add(List list);
void addAt(List list);
void get(List list);
void removeIth(List list);
void reverse(List list);

int main(){

    List list = newList();

    int option;
    do {
        menu(list);
        scanf("%d", &option);
        switch(option){
            case 1:
                add(list);
                break;
            case 2:
                addAt(list);
                break;
            case 3:
                get(list);
                break;
            case 4:
                removeIth(list);
                break;
            case 5:
                reverse(list);
                break;
            case 6:
                printf("\nexiting...\n\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
    }while(option != 6);

    freeList(list, freeAdt);
    return 0;
}

void menu(List list){
    printf("\n\n------------------LIST:------------------\n");
    printList(list, adtToString);
    printf("Size: %d\n\n", listSize(list));
    printf("1 - add at end.\n");
    printf("2 - add at ith position.\n");
    printf("3 - get ith element.\n");
    printf("4 - remove ith element.\n");
    printf("5 - reverse.\n");
    printf("6 - exit.\n");
    printf("------------------------------------------\n\n");
}

Adt createDataElement(){
    double x, y;
    char z[50];
    printf("\nCreate data element:\n");
    printf("x (double): ");
    scanf("%lf", &x);
    printf("y (double): ");
    scanf("%lf", &y);
    printf("z (string): ");
    scanf("%s", z);
    return newAdt(x, y, z);
}

void add(List list){
    Adt adt = createDataElement();
    listAdd(list, adt);
}

void addAt(List list){
    Adt adt = createDataElement();
    printf("\n\ni: ");
    int i;
    scanf("%d", &i);
    int result = listAddAt(list, i, adt);
    if(!result){
        printf("\n\nInvalid position. Insertion failed.\n\n");
        freeAdt(adt);
    }
}

void get(List list){
    printf("\n\ni: ");
    int i;
    scanf("%d", &i);
    Adt adt = listGet(list, i);
    if(adt == NULL){
        printf("\n\nInvalid position. Get failed.\n\n");
        return;
    }
    char* adtString = adtToString(adt);
    printf("\n\nith lement: %s.\n", adtString);
    free(adtString);
}

void removeIth(List list){
    printf("\n\ni: ");
    int i;
    scanf("%d", &i);
    Adt adt = listRemove(list, i);
    if(adt == NULL){
        printf("\n\nInvalid position. Remove failed.\n\n");
        return;
    }
    char* adtString = adtToString(adt);
    printf("\n\nRemoved element: %s.\n", adtString);
    free(adtString);
    freeAdt(adt);
}

void reverse(List list){
    listReverse(list);
}
