#include "linkedlist.h"
#include <stdlib.h>

void initList(LinkedList *list){
        Node* temp = malloc(sizeof(Node));
        list->head = NULL;
}

Node* createNode(int val){
        Node* temp = malloc(sizeof(Node)); 
        temp->data = val;
        temp->next = NULL;
        return temp;
}

void insertAtHead(LinkedList *list, int data){
        Node* temp = createNode(data);
        temp->next = list->head;
        list->head = temp;
}

void insertAtTail(LinkedList *list, int data){
        Node* temp = createNode(data);
        Node* current = list->head;

        if(current == NULL){
                list->head = temp;
                return;
        }
        while(current->next != NULL){
                current = current->next;
        }
        current->next = temp;
}

int getLength(LinkedList *list){
        int count = 0;
        Node* temp = list->head;
        while(temp != NULL){
                count ++;
                temp = temp->next;
        }
        return count;
}

int insertAtPosition(LinkedList *list, int data, int position){
        int len = getLength(list);
        if(len <= position){
                printf("Index out of range.\n");
                return 1;
        }
        Node* temp = createNode(data);
        Node* current = list->head ;
        int count = 0;
        while(count < position - 1){
                current = current->next;
                count ++;
        }

        Node* rest = current->next;
        current->next = temp;
        temp->next = rest;
        return 0;
}

int deleteAtPosition(LinkedList *list, int position){
        if(list->head == NULL){
                return 1;
        }

        if(position == 0){
                Node* temp = list->head;
                list->head = temp->next;
                free(temp);
                return 0;
        }

        int count = 0;  
        Node* current = list->head;
        while(current != NULL && count < position - 1){
                current = current->next;
                count ++;
        }

        if(current == NULL || current->next == NULL){
                return 1;
        }

        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        return 0;
}

int deleteNode(LinkedList *list, int val){
        if(list->head == NULL){
                return 1;
        }

        int count = 0;
        Node* curr = list->head;        
        while(curr != NULL && curr->data != val){
                count ++;
                curr = curr->next;
        }
        return deleteAtPosition(list, count);
}

Node* search(LinkedList* list, int data){
        Node* curr = list->head;
        while(curr != NULL && curr->data != data){
                curr = curr->next;
        }

        return curr;
}

void reverseList(LinkedList *list){
        Node* curr = list->head;
        Node* prev  =NULL;
        while(curr != NULL){
                Node* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
        }
        list->head = prev;
}

void printList(const LinkedList *list){
        if(list->head == NULL){
                printf("NULL\n");
                return;
        }

        printf("%d-->", list->head->data);


        LinkedList tempList = {list->head->next};
        printList(&tempList); 
}

void freeList(LinkedList *list){
        if(list->head == NULL){
                return;
        }
        LinkedList l = {list->head->next};
        freeList(&l);
        free(list->head);
        list->head = NULL;
}
