#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>

/* Helper to check list contents against expected array */
void assertListEquals(LinkedList* list, int expected[], int size) {
    Node* curr = list->head;
    for(int i = 0; i < size; i++) {
        assert(curr != NULL);                 // list shorter than expected
        assert(curr->data == expected[i]);   // value mismatch
        curr = curr->next;
    }
    assert(curr == NULL); // list longer than expected
}

/* Test insertion */
void testInsert() {
    LinkedList list;
    initList(&list);

    insertAtTail(&list, 10);
    insertAtTail(&list, 20);
    insertAtTail(&list, 30);
    insertAtHead(&list, 5);
    insertAtPosition(&list, 15, 2);

    int expected[] = {5, 10, 15, 20, 30};
    assertListEquals(&list, expected, 5);

    freeList(&list);
}

/* Test deletion by value */
void testDeleteValue() {
    LinkedList list;
    initList(&list);
    insertAtTail(&list, 1);
    insertAtTail(&list, 2);
    insertAtTail(&list, 3);
    insertAtTail(&list, 4);

    int ret = deleteNode(&list, 2);
    assert(ret == 0); // deletion succeeded

    int expected[] = {1, 3, 4};
    assertListEquals(&list, expected, 3);

    ret = deleteNode(&list, 999);
    assert(ret == 1); // non-existent value

    freeList(&list);
}

/* Test deletion by position */
void testDeletePosition() {
    LinkedList list;
    initList(&list);
    insertAtTail(&list, 10);
    insertAtTail(&list, 20);
    insertAtTail(&list, 30);

    int ret = deleteAtPosition(&list, 0);
    assert(ret == 0); // head deleted
    int expected1[] = {20, 30};
    assertListEquals(&list, expected1, 2);

    ret = deleteAtPosition(&list, 1); // tail
    assert(ret == 0);
    int expected2[] = {20};
    assertListEquals(&list, expected2, 1);

    ret = deleteAtPosition(&list, 10); // invalid
    assert(ret == 1);

    freeList(&list);
}

/* Test search */
void testSearch() {
    LinkedList list;
    initList(&list);
    insertAtTail(&list, 5);
    insertAtTail(&list, 10);
    insertAtTail(&list, 15);

    Node* n = search(&list, 10);
    assert(n != NULL && n->data == 10);

    n = search(&list, 999);
    assert(n == NULL);

    freeList(&list);
}

/* Test reverse */
void testReverse() {
    LinkedList list;
    initList(&list);
    insertAtTail(&list, 1);
    insertAtTail(&list, 2);
    insertAtTail(&list, 3);

    reverseList(&list);

    int expected[] = {3, 2, 1};
    assertListEquals(&list, expected, 3);

    freeList(&list);
}

/* Test length */
void testLength() {
    LinkedList list;
    initList(&list);
    assert(getLength(&list) == 0);

    insertAtTail(&list, 1);
    insertAtTail(&list, 2);
    assert(getLength(&list) == 2);

    freeList(&list);
}

/* Run all tests */
int main() {
    printf("Running LinkedList Unit Tests...\n");

    testInsert();
    printf("testInsert passed.\n");

    testDeleteValue();
    printf("testDeleteValue passed.\n");

    testDeletePosition();
    printf("testDeletePosition passed.\n");

    testSearch();
    printf("testSearch passed.\n");

    testReverse();
    printf("testReverse passed.\n");

    testLength();
    printf("testLength passed.\n");

    printf("All tests passed successfully!\n");
    return 0;
}

