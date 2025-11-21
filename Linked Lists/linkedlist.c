#include "linkedlist.h"

void initList(LinkedList *list) {
    list->head = NULL;
}

Node* createNode(void* data) {
    Node* node = malloc(sizeof(Node));
    if (!node) {
        perror("Failed to allocate node");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAtHead(LinkedList *list, void* data) {
    Node* node = createNode(data);
    node->next = list->head;
    list->head = node;
}

void insertAtTail(LinkedList *list, void* data) {
    Node* node = createNode(data);
    if (!list->head) {
        list->head = node;
        return;
    }
    Node* curr = list->head;
    while (curr->next)
        curr = curr->next;
    curr->next = node;
}

int getLength(LinkedList *list) {
    int count = 0;
    Node* curr = list->head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

int insertAtPosition(LinkedList *list, void* data, int position) {
    if (position < 0 || position > getLength(list)) {
        printf("Index out of range.\n");
        return 1;
    }
    if (position == 0) {
        insertAtHead(list, data);
        return 0;
    }

    Node* curr = list->head;
    for (int i = 0; i < position - 1 && curr; i++)
        curr = curr->next;

    Node* node = createNode(data);
    node->next = curr->next;
    curr->next = node;
    return 0;
}

int deleteAtPosition(LinkedList *list, int position) {
    if (!list->head)
        return 1;

    if (position == 0) {
        Node* temp = list->head;
        list->head = temp->next;
        free(temp);
        return 0;
    }

    Node* curr = list->head;
    for (int i = 0; i < position - 1 && curr; i++)
        curr = curr->next;

    if (!curr || !curr->next)
        return 1;

    Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return 0;
}

int deleteNode(LinkedList *list, void* data, bool (*cmp)(void*, void*)) {
    if (!list->head)
        return 1;

    Node* curr = list->head;
    Node* prev = NULL;

    while (curr && !cmp(curr->data, data)) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr)
        return 1;  // Not found

    if (!prev)
        list->head = curr->next;
    else
        prev->next = curr->next;

    free(curr);
    return 0;
}

Node* search(LinkedList* list, void* data, bool (*cmp)(void*, void*)) {
    Node* curr = list->head;
    while (curr && !cmp(curr->data, data))
        curr = curr->next;
    return curr;
}

void reverseList(LinkedList *list) {
    Node* prev = NULL;
    Node* curr = list->head;
    Node* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

void printList(const LinkedList *list, void (*printFunc)(void*)) {
    Node* curr = list->head;
    while (curr) {
        printFunc(curr->data);
        printf(" -> ");
        curr = curr->next;
    }
    printf("NULL\n");
}

void freeList(LinkedList *list) {
    Node* curr = list->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    list->head = NULL;
}

