#include "stack.h"
#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

int peek(int *dataPtr) {
    if (top == -1) {
        printf("Stack is empty!\n");
        return 1;
    }
    *dataPtr = stack[top];
    return 0;
}

int pop(int *dataPtr) {
    if (top == -1) {
        printf("Stack is empty!\n");
        return 1;
    }
    *dataPtr = stack[top];
    top--;
    return 0;
}

int display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return 1;
    }
    for (int temp = top; temp >= 0; temp--) {
        printf("%d ", stack[temp]);
    }
    printf("\n");
    return 0;
}

int push(int data) {
    if (top == SIZE - 1) {
        printf("Stack overflow!\n");
        return 1;
    }
    top++;
    stack[top] = data;
    return 0;
}

int is_empty() {
    return top == -1;
}

