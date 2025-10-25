#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

/* Helper macro for clear test output */
#define TEST(name) printf("\n=== %s ===\n", name)

int main() {
    Queue* q = initQueue();
    assert(q != NULL);
    assert(isEmpty(q) == true);

    TEST("Test Enqueue and Display");
    for (int i = 1; i <= 5; i++) {
        enqueue(q, i * 10);
    }
    display(q);
    printf("\nExpected: 10 20 30 40 50\n");

    TEST("Test Front and Size");
    assert(front(q) == 10);
    assert(size(q) == 5);
    printf("Front: %d | Size: %d\n", front(q), size(q));

    TEST("Test Dequeue");
    int val = dequeue(q);
    printf("Dequeued: %d\n", val);
    assert(val == 10);
    printf("New Front: %d | New Size: %d\n", front(q), size(q));

    TEST("Test Search");
    assert(search(q, 30) == true);
    assert(search(q, 99) == false);
    printf("Search(30): Found | Search(99): Not Found\n");

    TEST("Test Reverse Queue");
    printf("Before Reverse: ");
    display(q);
    reverseQueue(q);
    printf("\nAfter Reverse:  ");
    display(q);
    printf("\n");

    TEST("Test Clear Queue");
    clear(q);
    assert(isEmpty(q));
    printf("Queue cleared successfully.\n");

    TEST("Test Enqueue after Clear");
    enqueue(q, 100);
    enqueue(q, 200);
    display(q);
    printf("\nExpected: 100 200\n");

    TEST("Test Free Queue");
    freeQueue(q);
    printf("Queue memory freed successfully.\n");

    printf("\n✅ All tests passed successfully!\n");
    return 0;
}

