/* 
* Queue abstract data type. 
* It is an ordered collection of elements (variables) of some type (Data). 
* Obs: Note that this doesn't mean that the objects are in sorted order, it just means that each object has a position in the collection.
* The insertion happens on one end of the collection (tail), and deletion happens on the opposite end (head).
* @license as you wish
* @author Vitor Ruffo <vitor.gs.ruffo@gmail.com>
* @version 2021-05
* @file
*/

#ifndef QUEUE_H
#define QUEUE_H

/*
* A generic type of element/data that client will store on the queue.
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
* Queue type.
*/
typedef void* Queue;


/*
* Instantiates a new variable of type Queue. Time complexity: O(1).
* @return New, empty queue. Must be released with freeQueue()
*/
Queue newQueue(void);


/*
* Checks if queue is empty. Time complexity: O(1).
* @param Q Queue object.
* @return 1 if the queue is empty, otherwise, 0.
*/
int isQueueEmpty(Queue Q);

/*
* Time complexity: O(1).
* @param Q Queue object.
* @return queue size (i.e, amount of enqueued elements).
*/
int queueSize(Queue Q);

/* 
* Inserts a data element to the end of the queue (tail). Time complexity: O(1). 
* Obs: depending on the implementation (e.g, array) this may be O(n) on worst case.
* @param Q Queue object.
* @param data Data object. 
* @return 1 if the element was successfully enqueued, otherwise, 0.
*/
int enqueue(Queue Q, Data data);

/*
* Remove the element at the front of the queue (head). Client must later on desalocate the returned element. Time complexity: O(1).
* @param Q Queue object.
* @return Data removed from the front.
*/
Data dequeue(Queue Q);

/*
* Time complexity: O(1).
* @param Q Queue object.
* @return Element at the front of the queue.
*/
Data peek(Queue Q);

/*
* Prints the queue to the standard output file. Time complexity: O(n).
* @param Q Queue object.
* @param function Function that returns the string representation of a queue element.
*/
void printQueue(Queue Q, dataToString function);

/*
* Desalocates all memory used by the queue object. If function is passed, all elements in the queue are also desalocated from memory. Time complexity: O(n).
* @param Q Queue object.
* @param function Function that desalocates an element from memory.
*/
void freeQueue(Queue Q, freeData function);

#endif