#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt.h"

typedef struct {
    char* z;
    double x;
    double y;
}adt;

Adt newAdt(double x, double y, char* z){

    adt* t = (adt*) malloc(sizeof(adt));
    if(t == NULL) return NULL;

    t->z = (char*) malloc((strlen(z) + 1) * sizeof(char));
    strcpy(t->z, z);
    t->x = x;
    t->y = y;

    return t;
}

char* getZ(Adt T){
    adt* t = (adt*) T;
    return t->z;
}

void setZ(Adt T, char* z){
    adt* t = (adt*) T;
    strcpy(t->z, z);
}

double getX(Adt T){
    adt* t = (adt*) T;
    return t->x;
}

double getY(Adt T){
    adt* t = (adt*) T;
    return t->y;
}

char* adtToString(Adt T){
    adt* t = (adt*) T;

    char* adtToString = (char*) malloc(50*sizeof(char));
    if(t == NULL)
        sprintf(adtToString, "NULL");
    else
        sprintf(adtToString, "Z: %s - X: %.2f, Y: %.2f", t->z, t->x, t->y);

    return adtToString;    
}

//int compareAdts(Adt T1, Adt T2){
//    adt* t1 = (adt*) T1;
//    adt* t2 = (adt*) T2;
//    return strcmp(t1->z, t2->z);
//}
int compareAdts(Adt T1, Adt T2){
    adt* t1 = (adt*) T1;
    adt* t2 = (adt*) T2;
         if(t1->x > t2->x) return 1;
    else if(t1->x < t2->x) return -1;
    else                   return 0;
}

void freeAdt(Adt T){
    adt* t = (adt*) T;
    free(t->z);
    free(t);
}