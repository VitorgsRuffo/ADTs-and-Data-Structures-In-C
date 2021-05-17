/* 
* LIST abstract data type. 
* It is an ordered collection of elements (variables) of some type (Data). 
* Obs: Note that this doesn't mean that the objects are in sorted order, it just means that each object has a position in the List, starting with position zero.
* @license as you wish
* @author Vitor Ruffo <vitor.gs.ruffo@gmail.com>
* @version 2021-05
* @file
*/

#ifndef LIST_H
#define LIST_H

/*
* A generic type of element/data that client will store in the list.
*/
typedef void* Data;

/*
* Prototype of the client's function that desalocates an element from memory.
*/
typedef void (*freeData)(Data); 

/*
* Prototype of the client's function that returns a string representation of an element.
*/
typedef char* (*dataToString)(Data); 

/*
* List type.
*/
typedef void* List;


/*
* Instantiates a new variable of type List. Time complexity: O(1).
* @return New, empty list. Must be released with freeList()
*/
List newList(void);

/*
* @param Li List object. Time complexity: O(1).
* @return Number of elements in the list.
*/
int listSize(List Li);

/*
* Checks if list is empty. Time complexity: O(1).
* @param Li List object.
* @return 1 if the list is empty, otherwise, 0.
*/
int isListEmpty(List Li);

/*
* Adds an element to the end of the list. Time complexity: O(n).
* @param Li List object.
* @param data Data object.
* @return 1 if the element was successfully added to the list, otherwise, 0.
*/
int listAdd(List Li, Data data);

/*
* Adds an element at the specified position in the list. Time complexity: O(n).
* @param Li List object.
* @param position List position in which the element is going to be added.
* @param data Data object (or, element).
* @return 1 if the element was successfully added to the list, otherwise, 0.
*/
int listAddAt(List Li, int position, Data data);

/* 
* Time complexity: O(n) for linked list implementation, O(1) for array implementatino.
* @param Li List object.
* @param position List position of an element.
* @return Element at the specified position in the list. If position is invalid NULL is returned.
*/
Data listGet(List Li, int position);

/*
* Removes the element at the specified position in the list. Time complexity: O(n).
* @param Li List object.
* @param position List position of an element.
* @return Removed element. If position is invalid NULL is returned.
*/
Data listRemove(List Li, int position);

/*
* Reverses the list (e.g, [a b c d] becomes [d c b a]). Time complexity: O(n).
* @param Li List object.
*/
void listReverse(List Li);

/*
* Prints the list to the standard output file. Time complexity: O(n).
* @param Li List object.
* @param function Function that returns the string representation of a list element.
*/
void printList(List Li, dataToString function);

/*
* Desalocates all memory used by the list object. If function is passed, all elements in the list are also desalocated from memory. Time complexity: O(n).
* @param Li List object.
* @param function Function that desalocates an element from memory.
*/
void freeList(List Li, freeData function);

#endif