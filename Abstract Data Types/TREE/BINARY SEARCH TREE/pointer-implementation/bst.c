#include <stdio.h>
#include <stdlib.h>
#include "../bst.h"
#include "../queue/queue.h"
#include "../adt.h"

typedef struct node {
    Data data;
    struct node* left;
    struct node* right;
}node;

typedef struct {
    node* root;
    compareData compare;
}bst;


BST newBST(compareData compare){
    if(compare == NULL) return NULL;
    bst* _bst = (bst*) malloc(sizeof(bst));
    if(_bst == NULL) return NULL;

    (*_bst).root = NULL;
    (*_bst).compare = compare;

    return _bst;
}


/*
* When inserting we must find the right place to do so. That's because we must main
* the BST property: binary tree in which for each node, data of all the nodes in left
* subtree is lesser or equal, and data of all the nodes in right subtree is greater.
*/
void insertRecursively(bst* _bst, node* currentRoot, node* newNode){

    int comparison = (*((*_bst).compare))((*newNode).data, (*currentRoot).data);

    if(comparison <= 0){ //data is less than or equal to current root's data

        if((*currentRoot).left == NULL)
            (*currentRoot).left = newNode;

        else
            insertRecursively(_bst, (*currentRoot).left, newNode);
        

    }else{ //data is greater than the current root's data
        if((*currentRoot).right == NULL)
            (*currentRoot).right = newNode;

        else
            insertRecursively(_bst, (*currentRoot).right, newNode);
    }    
}

int insertBST(BST Bst, Data data){
    if(Bst == NULL || data == NULL) return 0;
    bst* _bst = (bst*) Bst;
    
    node* newNode = (node*) malloc(sizeof(node));
    if(newNode == NULL) return 0;
    (*newNode).data = data;
    (*newNode).left = NULL;
    (*newNode).right = NULL;


    if((*_bst).root == NULL)
        (*_bst).root = newNode;
        
    else
        insertRecursively(_bst, (*_bst).root, newNode);


    return 1;
}


/*
* This is the binary search algorithm in which each step reduces the search space by half.
* It has a time complexity of O(log(n)).
*/
Data searchRecursively(bst* _bst, node* currentRoot, Data partialData){
    
    if(currentRoot == NULL) return NULL; //data has not been found (base case).

    int comparison = (*((*_bst).compare))(partialData, (*currentRoot).data);

    if(comparison == 0)     //data has been found.
        return (*currentRoot).data;

    else if(comparison < 0) //searching in the left subtree...
        return searchRecursively(_bst, (*currentRoot).left, partialData);
    else                    //searching in the right subtree...
        return searchRecursively(_bst, (*currentRoot).right, partialData);
    
}


Data searchBST(BST Bst, Data partialData){
    if(Bst == NULL || partialData == NULL) return NULL;
    bst* _bst = (bst*) Bst;

    return searchRecursively(_bst, (*_bst).root, partialData);
}


/*
* The minimum element of a BST is found at the bottom left of the tree.
*/
node* findMinRecursively(node* currentRoot){
    if((*currentRoot).left == NULL)
        return currentRoot;
    
    return findMinRecursively((*currentRoot).left); 
}

Data minBST(BST Bst){
    if(Bst == NULL) return NULL;
    bst* _bst = (bst*) Bst;
    if((*_bst).root == NULL) return NULL;

    return (*findMinRecursively((*_bst).root)).data;
}


/*
* The maximum element of a BST is found at the bottom right of the tree.
*/
Data findMaxRecursively(node* currentRoot){
    if((*currentRoot).right == NULL)
        return (*currentRoot).data;
    
    return findMaxRecursively((*currentRoot).right); 
}

Data maxBST(BST Bst){
    if(Bst == NULL) return NULL;
    bst* _bst = (bst*) Bst;
    if((*_bst).root == NULL) return NULL;

    return findMaxRecursively((*_bst).root);
}


#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

int findHeightRecursively(node* currentRoot){
    if(currentRoot == NULL) return -1; //base case

    int leftSubtreeHeight = findHeightRecursively((*currentRoot).left);
    int rightSubtreeHeight = findHeightRecursively((*currentRoot).right);

    return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}


/*
* Time taken is proportinal to the number of elements in the tree because "findHeightRecursively" is called for each tree node.
*/
int heightBST(BST Bst){
    if(Bst == NULL) return -2;
    bst* _bst = (bst*) Bst;

    return findHeightRecursively((*_bst).root);
}


//When deleting a node we must keep the BST property: in an BST for each node, data of all the nodes in left subtree 
//* is lesser or equal, and data of all the nodes in right subtree is greater.
node* deleteRecursively(bst* _bst, node* currentRoot, Data partialData, Data* data){

    if(currentRoot == NULL) return currentRoot; //node to be deleted has not been found (base case).

    int comparison = (*((*_bst).compare))(partialData, (*currentRoot).data);

    if(comparison < 0)      //searching for node to be deleted in the left subtree...
        (*currentRoot).left = deleteRecursively(_bst, (*currentRoot).left, partialData, data);  //address of left subtree root may change when deleting a node, so the latest root is always returned by deleteRecursively.
   
    else if(comparison > 0) //searching for node to be deleted in the right subtree...
        (*currentRoot).right = deleteRecursively(_bst, (*currentRoot).right, partialData, data);

    else{                   //node to be deleted has been found.
        
        //saving data that is gonna be deleted from tree.
        if(data != NULL) *data = (*currentRoot).data;

        //case 1: node to be deleted has no children. We simply delete it break the connection with its parent.
        if((*currentRoot).left == NULL && (*currentRoot).right == NULL){
            
            free(currentRoot);
            currentRoot = NULL;
        }

        //case 2: node to be deleted has only one child. We connect its parent to its child and delete it.
        else if((*currentRoot).left == NULL){

            node* temp = currentRoot;
            currentRoot = (*currentRoot).right;
            free(temp);
        }

        else if((*currentRoot).right == NULL){

            node* temp = currentRoot;
            currentRoot = (*currentRoot).left;
            free(temp);
        }

        //case 3: node to be deleted has two children.
        //We set the current root data to be the data from the minimum node in its right subtree.
        //After that we can simply go to the right subtree and delete that minimum node, which is now a duplicate.
        //By doing this we can successfully remove the disired node while maintaining the BST property.
        else{

            node* rightSubtreeMin = findMinRecursively((*currentRoot).right);
            (*currentRoot).data = (*rightSubtreeMin).data;
            (*currentRoot).right = deleteRecursively(_bst, (*currentRoot).right, (*rightSubtreeMin).data, NULL);

        }
    }

    return currentRoot;
}

Data deleteBST(BST Bst, Data partialData){
    if(Bst == NULL || partialData == NULL) return NULL;
    bst* _bst = (bst*) Bst;

    Data deletedData = NULL;

    //address of root may change when deleting a node, so the latest root is always returned by deleteRecursively.
    (*_bst).root = deleteRecursively(_bst, (*_bst).root, partialData, &deletedData);

    return deletedData;
}

//Not implemented yet.
void balanceBST(BST Bst){
    return;
}


void levelOrderTraversalBST(BST Bst, visit function, Data extraData){
    if(Bst == NULL || function == NULL) return;
    bst* _bst = (bst*) Bst;
    if((*_bst).root == NULL) return;

    Queue queue = newQueue();
    enqueue(queue, (*_bst).root);
    
    while(!isQueueEmpty(queue)){

        node* current = dequeue(queue);

        (*function)((*current).data, extraData);

        if((*current).left != NULL) enqueue(queue, (*current).left);
        if((*current).right != NULL) enqueue(queue, (*current).right);
    }

    freeQueue(queue, NULL);
}

void preOrderTraversal(node* currentRoot, visit function, Data extraData){
    if(currentRoot == NULL) return; //base case

    (*function)((*currentRoot).data, extraData);                  //process current root data
    preOrderTraversal((*currentRoot).left, function, extraData);  //traverse left subtree
    preOrderTraversal((*currentRoot).right, function, extraData); //traverse right subtree
}

void preOrderTraversalBST(BST Bst, visit function, Data extraData){
    if(Bst == NULL || function == NULL) return;
    bst* _bst = (bst*) Bst;
    preOrderTraversal((*_bst).root, function, extraData);
}

void inOrderTraversal(node* currentRoot, visit function, Data extraData){
    if(currentRoot == NULL) return; //base case

    inOrderTraversal((*currentRoot).left, function, extraData);  //traverse left subtree
    (*function)((*currentRoot).data, extraData);                 //process current root data
    inOrderTraversal((*currentRoot).right, function, extraData); //traverse right subtree
}

void inOrderTraversalBST(BST Bst, visit function, Data extraData){
    if(Bst == NULL || function == NULL) return;
    bst* _bst = (bst*) Bst;
    inOrderTraversal((*_bst).root, function, extraData);
}

void postOrderTraversal(node* currentRoot, visit function, Data extraData){
    if(currentRoot == NULL) return; //base case

    postOrderTraversal((*currentRoot).left, function, extraData);  //traverse left subtree
    postOrderTraversal((*currentRoot).right, function, extraData); //traverse right subtree
    (*function)((*currentRoot).data, extraData);                   //process current root data
}

void postOrderTraversalBST(BST Bst, visit function, Data extraData){
    if(Bst == NULL || function == NULL) return;
    bst* _bst = (bst*) Bst;
    postOrderTraversal((*_bst).root, function, extraData);
}


void printBST(BST Bst, dataToString function){
    if(Bst == NULL || function == NULL) return;
    bst* _bst = (bst*) Bst;

    if((*_bst).root == NULL) return;

    Queue queue = newQueue();
    enqueue(queue, (*_bst).root);
    
    printf("\nPrinting tree in level order...\n");
    while(!isQueueEmpty(queue)){

        node* current = dequeue(queue);
        char* string;
        printf("\nNode: %s\n", string = (*function)((*current).data));
        free(string);
        
        if((*current).left != NULL){
            enqueue(queue, (*current).left);
            printf("  left: %s\n", string = (*function)((*((*current).left)).data));
            free(string);
        }else 
            printf("  left: NULL\n");

        if((*current).right != NULL){
            enqueue(queue, (*current).right);
            printf("  right: %s\n", string = (*function)((*((*current).right)).data));
            free(string);
        }else 
            printf("  right: NULL\n");
    }

    freeQueue(queue, NULL);
   
    return;
}

/*
* In order to desalocate the tree we traverse it in post-order depth-first approach desalocating visited nodes and, optinally, their Data elements.
*/
void freeRecursively(node* currentRoot, freeData function){
    if(currentRoot == NULL) return; //base case
    
    freeRecursively((*currentRoot).left, function);
    freeRecursively((*currentRoot).right, function);
    
    if(function != NULL) 
        (*function)((*currentRoot).data);
    
    free(currentRoot);
}

void freeBST(BST Bst, freeData function){
    if(Bst == NULL) return;
    bst* _bst = (bst*) Bst;

    freeRecursively((*_bst).root, function);
    free(_bst);

    return;
}