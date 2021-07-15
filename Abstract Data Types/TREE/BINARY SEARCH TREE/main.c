#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#include "bst.h"

void menu(BST Bst);
void insert(BST Bst);
void search(BST Bst);
void min(BST Bst);
void max(BST Bst);
void traverse(BST Bst);
void del(BST Bst);

int main(){

    BST Bst = newBST(compareAdts);

    int option;
    do {
        menu(Bst);
        scanf("%d", &option);
        switch(option){
            case 1:
                insert(Bst);
                break;
            case 2:
                search(Bst);
                break;
            case 3:
                min(Bst);
                break;
            case 4:
                max(Bst);
                break;
            case 5:
                traverse(Bst);
                break;
            case 6:
                del(Bst);
                break;
            case 7:
                printf("\nexiting...\n\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
    }while(option != 7);

    freeBST(Bst, freeAdt);
    return 0;
}

void menu(BST Bst){
    printf("\n\n------------------Binary Search Tree:------------------\n");
    printf("\nHeight: %d.\n", heightBST(Bst));
    printBST(Bst, adtToString);
    printf("\n1 - insert.\n");
    printf("2 - search.\n");
    printf("3 - minimum.\n");
    printf("4 - maximum.\n");
    printf("5 - traverse.\n");
    printf("6 - delete.\n");
    printf("7 - exit.\n");
    printf("--------------------------------------------------------\n\n");
}

void insert(BST Bst){
    double x, y;
    char z[50];
    printf("\nCreate data element:\n");
    printf("x (double): ");
    scanf("%lf", &x);
    printf("y (double): ");
    scanf("%lf", &y);
    printf("z (string): ");
    scanf("%s", z);
    Adt adt = newAdt(x, y, z);
    insertBST(Bst, adt);
}

void search(BST Bst){
    double x;
    printf("\nEnter the adt x field: ");
    scanf("%lf", &x);
    Adt partialAdt = newAdt(x, 1, "aa");

    Adt adt = searchBST(Bst, partialAdt);
    if(adt == NULL)
        printf("\nError: element not found.\n");

    else{
        char* adtString = adtToString(adt);
        printf("\nElement was found:\n%s.\n", adtString);
        free(adtString);
    }

    freeAdt(partialAdt);
}

void min(BST Bst){
    Adt adt = minBST(Bst);
    if(adt == NULL)
        printf("\nError: could not find minimum element.\n");
    else{
        char* adtString = adtToString(adt);
        printf("\nMinimum element:\n%s.\n", adtString);
        free(adtString);
    }
}

void max(BST Bst){
    Adt adt = maxBST(Bst);
    if(adt == NULL)
        printf("\nError: could not find maximum element.\n");
    else{
        char* adtString = adtToString(adt);
        printf("\nMaximum element:\n%s.\n", adtString);
        free(adtString);
    }
}

void printAdtKeyToFile(Data adt, Data File){
    FILE* file = (FILE*) File;
    fprintf(file, "%.2lf ", getX(adt));
    fflush(file);
}

void traverse(BST Bst){
    printf("\nChoose a traversal order:\n");
    printf("1 - level-order.\n");
    printf("2 - pre-order.\n");
    printf("3 - in-order.\n");
    printf("4 - post-order.\n\n");

    FILE* traversal = fopen("./traversal.txt", "a");
    if(traversal == NULL){
        printf("\nError: could not traverse the tree.\n");
        return;
    }

    int option;
    scanf("%d", &option);
    do {
        switch(option){
            case 1:
                levelOrderTraversalBST(Bst, printAdtKeyToFile, traversal);
                break;
            case 2:
                preOrderTraversalBST(Bst, printAdtKeyToFile, traversal);
                break;
            case 3:
                inOrderTraversalBST(Bst, printAdtKeyToFile, traversal);
                break;
            case 4:
                postOrderTraversalBST(Bst, printAdtKeyToFile, traversal);
                break;
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
    }while(option < 1 || option > 4);

    printf("\nTraversal complete. Please, check nodes visiting order in \"./traversal.txt\" file before it is removed.\nPress enter to continue...\n");
    getchar();
    getchar();
    fclose(traversal);
    remove("./traversal.txt");
}

void del(BST Bst){
    double x;
    printf("\nEnter the adt x field: ");
    scanf("%lf", &x);
    Adt partialAdt = newAdt(x, 1, "aa");
    Adt adt = deleteBST(Bst, partialAdt);
    if(adt == NULL)
        printf("\nError: element not found.\n");

    else{
        char* adtString = adtToString(adt);
        printf("\nElement removed from the tree:\n%s.\n", adtString);
        free(adtString);
        freeAdt(adt);
    }

    freeAdt(partialAdt);
}