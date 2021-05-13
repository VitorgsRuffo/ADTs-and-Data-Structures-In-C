/* 
* LIST abstract data type. 
* It is an ordered collection of elements (variables) of some type (Data). 
* Obs: Note that this doesn't mean that the elements are in sorted order, it just means that each element has a position in the List, starting with position zero.
*/

#ifndef LIST_H
#define LIST_H

/*
* Pointer to an element.
*/
typedef void* Data;

/*
* Pointer to function that desalocates an element from memory.
*/
typedef void (*freeData)(Data); 

/*
* Pointer to function that returns a string representation of an element.
*/
typedef char* (*dataToString)(Data); 

/*
* Pointer to a instance of List.
*/
typedef void* List;


/*
* Instantiates a new variable of type List.
*/
List newList();

/*
* Returns the number of elements in the list.
*/
int listSize(List Li);

/*
* Returns 1 if the list is empty, otherwise, returns 0.
*/
int isListEmpty(List Li);

/*
* Adds an element to the end of the list.
* Returns 1 if the element was successfully added to the list, otherwise, returns 0.
*/
int listAdd(List Li, Data data);

/*
* Adds an element at the specified position in the list.
* Returns 1 if the element was successfully added to the list, otherwise, returns 0.
*/
int listAddAt(List Li, int position, Data data);

/*
* Returns the element at the specified position in the list. 
*/
Data listGet(List Li, int position);

/*
* Removes and returns the element at the specified position in the list. 
*/
Data listRemove(List Li, int position);

/*
*   Reverses the list.
*   e.g, [a b c d] becomes [d c b a].
*/
void listReverse(List Li);

/*
* Prints the list to the standard output file. 
* Requires a function that returns the string representation of a list element.
*/
void printList(List Li, dataToString function);

/*
* Desalocates all memory used by list variable. 
* If function is passed, all elements in the list are also desalocated from memory.
*/
void freeList(List Li, freeData function);

#endif
