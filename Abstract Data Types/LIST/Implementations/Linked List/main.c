#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#include "list.h"


int main(){

    Adt t1 = newAdt(10, 20, "t1");
    Adt t2 = newAdt(20, 40, "t2");
    Adt t3 = newAdt(30, 60, "t3");
    Adt t4 = newAdt(40, 80, "t4");
    Adt t5 = newAdt(50, 100, "t5");
    List adts = newList();
    printf("Is list empty? %s\n\n.", isListEmpty(adts)?"yes":"no");


    listAdd(adts, t1);
    listAdd(adts, t2);
    listAddAt(adts, 0, t3);
    if(!listAddAt(adts, 4, t4)){
        printf("Position 4 is not valid.\n\n");
    }
    listAddAt(adts, 1, t4);
    listAddAt(adts, 4, t5);
    printList(adts, adtToString);


    printf("Is list empty? %s.\n\n", isListEmpty(adts)?"yes":"no");
    printf("List size: %d.\n\n", listSize(adts));


    Adt t = listGet(adts, 3);
    if(t != NULL){
        char* tString = adtToString(t);
        printf("getting an element: %s.\n\n", tString);
        free(tString);
    }else{
        printf("Invalid position.\n\n");
    }


    t = listRemove(adts, 4);
    char* tString = adtToString(t);
    printf("Removing element: %s.\n\n", tString);
    free(tString);
    freeAdt(t);
    printList(adts, adtToString);

    printf("Reversing the list:\n");
    listReverse(adts);
    printList(adts, adtToString);


    freeList(adts, freeAdt);
    return 0;
}