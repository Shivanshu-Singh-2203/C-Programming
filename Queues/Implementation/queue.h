#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

typedef struct Node Node ;
Queue* initQueue();
bool isEmpty(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int front(Queue* q);
int size(Queue* q);
void clear(Queue* q);

void display(Queue* q);
void reverseQueue(Queue* q);
bool search(Queue* q, int data);

void freeQueue(Queue* q);

#endif

