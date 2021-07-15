/*
* A generic abstract data type. It can be used when testing other ADTs implementations.
*/ 

#ifndef ADT_H
#define ADT_H

/*
* generic abstract data type. 
*/
typedef void* Adt;

Adt newAdt(double x, double y, char* z);

void setZ(Adt T, char* z);

char* getZ(Adt T);

double getX(Adt T);

double getY(Adt T);

char* adtToString(Adt T);

int compareAdts(Adt T1, Adt T2);

void freeAdt(Adt T);

#endif