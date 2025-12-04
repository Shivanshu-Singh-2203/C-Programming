#ifndef BINARYSEARCHTREE_H

#define BINARYSEARCHTREE_H
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node* left;
        struct node* right;
};

typedef struct node Node;

Node* createTree(int);
Node* insertElement(Node*, int);
void preOrderTraversal(Node*);
void inOrderTraversal(Node*);
void postOrderTraversal(Node*);
Node* findSmallest(Node*);
int deleteElement(Node**, int);
Node* mirrorImage(Node*);
int totalNodes(Node*);
int totalExternalNodes(Node*);
int totalInternalNodes(Node*);
int height(Node*);
void deleteTree(Node*, Node*);
Node* findNode(Node*, int);
int isLeaf(Node* );
void freeTree(Node*);
Node* findLargest(Node*);
Node* findInOrderSuccessor(Node*);
#endif 