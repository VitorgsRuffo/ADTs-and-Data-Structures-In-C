/* 
* Stack abstract data type. 
* It is an ordered collection of elements (variables) of some type (Data). 
* Obs: Note that this doesn't mean that the objects are in sorted order, it just means that each object has a position in the collection.
* The elements can only be inserted/removed from one specific end of the collection (i.e, stack top).
* @license as you wish
* @author Vitor Ruffo <vitor.gs.ruffo@gmail.com>
* @version 2021-05
* @file
*/

#ifndef STACK_H
#define STACK_H

/*
* A generic type of element/data that client will store on the stack.
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
* Stack type.
*/
typedef void* Stack;


/*
* Instantiates a new variable of type Stack. Time complexity: O(1).
* @return New, empty stack. Must be released with freeStack()
*/
Stack newStack(void);

/*
* Time complexity: O(1).
* @param St Stack object.
* @return stack size (i.e, stack amount of elements).
*/
int stackSize(Stack St);

/*
* Checks if stack is empty. Time complexity: O(1).
* @param St Stack object.
* @return 1 if the stack is empty, otherwise, 0.
*/
int isStackEmpty(Stack St);

/* 
* Inserts a data element to the top of the stack. Time complexity: O(1). 
* Obs: depending on the implementation (e.g, array) this may be O(n) on worst case.
* @param St Stack object.
* @param data Data object. 
* @return 1 if the element was successfully pushed to the stack, otherwise, 0.
*/
int stackPush(Stack St, Data data);

/*
* Remove the element at the top of the stack. Client must later on desalocate the returned element. Time complexity: O(1).
* @param St Stack object.
* @return Data removed from the top.
*/
Data stackPop(Stack St);

/*
* Time complexity: O(1).
* @param St Stack object.
* @return Element at the top of the stack.
*/
Data stackTop(Stack St);

/*
* Prints the stack to the standard output file. Time complexity: O(n).
* @param St Stack object.
* @param function Function that returns the string representation of a stack element.
*/
void printStack(Stack St, dataToString function);

/*
* Desalocates all memory used by the stack object. If function is passed, all elements in the stack are also desalocated from memory. Time complexity: O(n).
* @param St Stack object.
* @param function Function that desalocates an element from memory.
*/
void freeStack(Stack St, freeData function);

#endif