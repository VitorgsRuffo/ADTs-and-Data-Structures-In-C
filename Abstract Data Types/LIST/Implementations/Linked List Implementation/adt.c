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
    sprintf(adtToString, "Z: %s - X: %.2f, Y: %.2f", t->z, t->x, t->y);

    return adtToString;    
}

void freeAdt(Adt T){
    adt* t = (adt*) T;
    free(t->z);
    free(t);
}