/*  
* Binary Search Tree (BST) abstract data type. 
* This is specific type of binary tree. 
* A binary tree is a tree in which each node has at most two children.
* Moreover, in an BST for each node, data of all the nodes in left subtree 
* is lesser or equal, and data of all the nodes in right subtree is greater.
*
* The time taken by many BST operations are proportional to the height of the tree 
* (i.e, number of edges in the longest path from root to a leaf node).
* That's why is extremely important to maintain the tree balanced.
* A BST is called balanced when, for every node, the absolute difference between 
* the height of left and right subtrees is less or equal to some value k (usually k == 1).
* If nodes are concentrated on one side of the tree, its height will be greater than it should be,
* slowing down operations that depend on it.
* That height is given by int(log(n)), that's why most operations time complexities are O(log(n)).
*
* @license as you wish
* @author Vitor Ruffo <vitor.gs.ruffo@gmail.com>
* @version 2021-07
* @file
*/

#ifndef BST_H
#define BST_H

/*
* A generic type of element/data that client will store on the bst.
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
* Prototype of the client's function that returns a string representing an element's key.
*/
//typedef char* (*getDataKey)(Data); 

/*
* Prototype of the client's function takes two data objects and returns...
* 0        if data1 == data2
* negative if data1 <  data2
* positive if data1 >  data2
*/
typedef int (*compareData)(Data, Data); 

/*
* Prototype of the client's function that is executed for every node Data in a traversal operation. 
* The first parameter refers to the Data stored in the current node that is being visited. 
* The second one refers to some extra data that might be useful inside the function (optional).
*/
typedef void (*visit)(Data, Data); 

/*
* Binary Search Tree (BST) type.
*/
typedef void* BST;


/*
* Instantiates a new variable of type BST. Time complexity: O(1).
* @param compare Function that compares two elements.
* @return New, empty binary search tree. Must be released with freeBST()
*/
BST newBST(compareData compare);

/* 
* Inserts a data element in the tree. Time complexity: O(log(n)). 
* @param Bst BST object.
* @param data Data object. 
* @return 1 if the element was successfully inserted in the tree, otherwise, 0.
*/
int insertBST(BST Bst, Data data);

/* 
* Searches for a data element in the tree. Time complexity: O(log(n)). 
* partialData argument is an object that must be instantiated before using this function. 
* Client must set that object's internal fields that are used when comparing two data objects with "compareData" function. 
* Those fields values should be equal to the element that is being searched's correponding fields. 
* So, make sure those fields are properly set before calling this function.
* @param Bst BST object.
* @param partialData Data object. 
* @return The element if it has been found, otherwise, NULL.
*/
Data searchBST(BST Bst, Data partialData);

/* 
* Finds the minimum element in the tree. Time complexity: O(log(n)). 
* @param Bst BST object.
* @return The minimum element in the tree if no errors occured, otherwise, NULL.
*/
Data minBST(BST Bst);

/* 
* Finds the maximum element in the tree. Time complexity: O(log(n)). 
* @param Bst BST object.
* @return The maximum element in the tree if no errors occured, otherwise, NULL.
*/
Data maxBST(BST Bst);

/* 
* Calculates the height of the tree. Time complexity: O(n). 
* Height is defined as being the number of edges in the longest path from root to a leaf node. 
* If tree is empty height is -1, If tree has only one node height is 0. 
* @param Bst BST object.
* @return Height of the tree.
*/
int heightBST(BST Bst);

/* 
* Deletes a data element node from the tree.
* partialData argument is an object that must be instantiated before using this function. 
* Client must set that object's internal fields that are used when comparing two data objects with "compareData" function. 
* Those fields values should be equal to the element that's gonna be deleted's correponding fields. 
* So, make sure those fields are properly set before calling this function.
* @param Bst BST object.
* @param partialData Data object. 
* @return The data element which node was deleted from the tree. If the data element node could not be deleted NULL is returned.
*/
Data deleteBST(BST Bst, Data partialData);

/* 
* Balances the tree. Time complexity: O(n). 
* As many operations depends on tree height it is important to keep it balanced.
* @param Bst BST object.
*/
void balanceBST(BST Bst);

/*
* Tree traversal: process of visiting each node in the tree exactly once in some order.
*        
*   - breadth-first approach: 
*       - level-order: visits all nodes in one level (from left to right), then visits all nodes in next level, ...
*        
*   - depth-first approach:
*       - Pre-order: visits root, then its left subtree and finally its right subtree (the subtrees are visited in the same manner).
*       - In-order: visits left subtree, followed by root, then right subtree (the subtrees are visited in the same manner).
*       - Post-order: visits left subtree, right substree, then root (the subtrees are visited in the same manner).
*/ 

/*
* Visits each tree node in level-order breadth-first approach. The visit function is called for each visited node. 
* That function takes the current visited node Data element and the extraData element and performs some operation on the former. 
* Time complexity: O(n).
* @param Bst BST object.
* @param function Function that is executed for every node Data in a traversal operation. 
* @param extraData Data object (optional).
*/
void levelOrderTraversalBST(BST Bst, visit function, Data extraData);

/*
* Visits each tree node in pre-order depth-first approach. The visit function is called for each visited node. 
* That function takes the current visited node Data element and the extraData element and performs some operation on the former. 
* Time complexity: O(n).
* @param Bst BST object.
* @param function Function that is executed for every node Data in a traversal operation. 
* @param extraData Data object (optional).
*/
void preOrderTraversalBST(BST Bst, visit function, Data extraData);

/*
* Visits each tree node in in-order depth-first approach. The visit function is called for each visited node. 
* That function takes the current visited node Data element and the extraData element and performs some operation on the former. 
* Time complexity: O(n).
* @param Bst BST object.
* @param function Function that is executed for every node Data in a traversal operation. 
* @param extraData Data object (optional).
*/
void inOrderTraversalBST(BST Bst, visit function, Data extraData);

/*
* Visits each tree node in post-order depth-first approach. The visit function is called for each visited node. 
* That function takes the current visited node Data element and the extraData element and performs some operation on the former. 
* Time complexity: O(n).
* @param Bst BST object.
* @param function Function that is executed for every node Data in a traversal operation. 
* @param extraData Data object (optional).
*/
void postOrderTraversalBST(BST Bst, visit function, Data extraData);

/*
* Prints the BST to the standard output file. Time complexity: O(n).
* @param Bst BST object.
* @param function Function that returns the string representation of a tree element.
*/
void printBST(BST Bst, dataToString function);

/*
* Desalocates all memory used by the binary search tree object. If function is passed, all elements in the tree are also desalocated from memory. Time complexity: O(n).
* @param Bst BST object.
* @param function Function that desalocates an element from memory.
*/
void freeBST(BST Bst, freeData function);

     
#endif

/* To do list:
    - balance().
*/