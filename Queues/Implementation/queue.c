#include "queue.h"
#include <stdlib.h>

Queue* initQueue(){
        Queue* temp = malloc(sizeof(Queue));
        
        if(temp ==NULL){
                printf("Queue memory allocation failed.\n");
                exit(1);
        }

        temp->size = 0;
        temp->rear = NULL;
        temp->front = NULL;
        return temp;
}

bool isEmpty(Queue* q){
        return q->size == 0;
}

void enqueue(Queue *q, int data){
        Node* temp = malloc(sizeof(Node));
        
        if(temp ==NULL){
                printf("Node memory allocation failed.\n");
                exit(1);
        }

        temp->data = data;
        temp->next = NULL;
        
        if(q->size == 0){
                q->rear = temp;
                q->front = temp;
        }

        else {
                q->rear->next = temp;
                q->rear = temp;
        }
        
        q->size ++;
        return;
}


int dequeue(Queue *q){
        if(isEmpty(q)){
                printf("Queue is empty.\n");
                exit(1);
        }

        Node* temp = q->front;
        int value = temp->data;
        q->front = temp->next;

        if(q->front == NULL){
                q->rear = NULL;
        }
        
        q->size --;

        free(temp);
        return value;
}

int front(Queue* q){
        if(q->front == NULL){
                printf("Queue is empty.\n");
        }

        return q->front->data;
}

int size(Queue* q){
        return q->size;
}

void displayhelper(Queue* q){
        if(isEmpty(q)){
                return ;
        }

        int top = dequeue(q);
        printf("%d ", top);

        display(q);
        enqueue(q, top); 

}
void  display(Queue* q){
        displayhelper(q);
        reverseQueue(q);
        return;
}

void reverseQueue(Queue *q){
        if(isEmpty(q)){
                return;
        }

        int rear = dequeue(q);
        reverseQueue(q);
        enqueue(q, rear);
}

void clear(Queue *q){
        while(!isEmpty(q)){
                dequeue(q);
        }
        return;
}

void freeQueue(Queue *q){
        if(isEmpty(q)){
                return;
        }

        Node* temp = q->front;
        dequeue(q);
        return freeQueue(q);
}

bool search(Queue *q, int data){
        if(isEmpty(q)){
                return false;
        }

        if(q->front->data == data){
                return true;
        }

        Queue* temp = initQueue();
        temp->front = q->front->next;
        temp->rear = q->rear;
        temp->size = q->size - 1;
        return search(temp, data); 
}

