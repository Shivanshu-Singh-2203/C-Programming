#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Linked list structure */
typedef struct LinkedList {
    Node* head;
} LinkedList;

/* Function declarations */

/* Initialize an empty linked list with data in the node equals to zero*/
void initList(LinkedList* list);

/* Create a new node */
Node* createNode(int data);

/* Insert node at the beginning */
void insertAtHead(LinkedList* list, int data);

/* Insert node at the end */
void insertAtTail(LinkedList* list, int data);

/* Insert node at a specific position (0-based index) */
int insertAtPosition(LinkedList* list, int data, int position);

/* Delete first occurence of the node by value */
int deleteNode(LinkedList* list, int data);

/* Delete node at a specific position */
int deleteAtPosition(LinkedList* list, int position);

/* Search for a value in the list */
Node* search(LinkedList* list, int data);

/* Get length of the linked list */
int getLength(LinkedList* list);

/* Reverse the linked list */
void reverseList(LinkedList* list);

/* Print the linked list */
void printList(const LinkedList* list);

/* Free all nodes */
void freeList(LinkedList* list);

#endif // LINKEDLIST_H

