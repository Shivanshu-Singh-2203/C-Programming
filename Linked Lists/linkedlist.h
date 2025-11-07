#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Node structure with generic data */
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

/* Linked list structure */
typedef struct LinkedList {
    Node* head;
} LinkedList;

/* Function declarations */

/* Initialize an empty linked list */
void initList(LinkedList* list);

/* Create a new node with given data pointer */
Node* createNode(void* data);

/* Insert node at the beginning */
void insertAtHead(LinkedList* list, void* data);

/* Insert node at the end */
void insertAtTail(LinkedList* list, void* data);

/* Insert node at a specific position (0-based index) */
int insertAtPosition(LinkedList* list, void* data, int position);

/* Delete first occurrence of a node with matching data (comparison via function pointer) */
int deleteNode(LinkedList* list, void* data, bool (*cmp)(void*, void*));

/* Delete node at a specific position */
int deleteAtPosition(LinkedList* list, int position);

/* Search for a value in the list using a comparison function */
Node* search(LinkedList* list, void* data, bool (*cmp)(void*, void*));

/* Get length of the linked list */
int getLength(LinkedList* list);

/* Reverse the linked list */
void reverseList(LinkedList* list);

/* Print the linked list using a print function */
void printList(const LinkedList* list, void (*printFunc)(void*));

/* Free all nodes (but not the data itself) */
void freeList(LinkedList* list);

#endif // LINKEDLIST_H

