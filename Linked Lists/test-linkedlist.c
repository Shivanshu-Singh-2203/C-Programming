#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

/* Comparison function for integers */
bool intCompare(void* a, void* b) {
    return *(int*)a == *(int*)b;
}

/* Print function for integers */
void printInt(void* data) {
    printf("%d", *(int*)data);
}

/* Helper to check list contents against expected array */
void assertListEquals(LinkedList* list, int expected[], int size) {
    Node* curr = list->head;
    for (int i = 0; i < size; i++) {
        assert(curr != NULL);                    // list shorter than expected
        assert(*(int*)curr->data == expected[i]); // compare actual value
        curr = curr->next;
    }
    assert(curr == NULL); // list longer than expected
}

/* Test insertion */
void testInsert() {
    LinkedList list;
    initList(&list);

    int a = 10, b = 20, c = 30, d = 5, e = 15;

    insertAtTail(&list, &a);
    insertAtTail(&list, &b);
    insertAtTail(&list, &c);
    insertAtHead(&list, &d);
    insertAtPosition(&list, &e, 2);

    int expected[] = {5, 10, 15, 20, 30};
    assertListEquals(&list, expected, 5);

    freeList(&list);
}

/* Test deletion by value */
void testDeleteValue() {
    LinkedList list;
    initList(&list);

    int a = 1, b = 2, c = 3, d = 4, x = 999;

    insertAtTail(&list, &a);
    insertAtTail(&list, &b);
    insertAtTail(&list, &c);
    insertAtTail(&list, &d);

    int ret = deleteNode(&list, &b, intCompare);
    assert(ret == 0); // deletion succeeded

    int expected[] = {1, 3, 4};
    assertListEquals(&list, expected, 3);

    ret = deleteNode(&list, &x, intCompare);
    assert(ret == 1); // non-existent value

    freeList(&list);
}

/* Test deletion by position */
void testDeletePosition() {
    LinkedList list;
    initList(&list);

    int a = 10, b = 20, c = 30;

    insertAtTail(&list, &a);
    insertAtTail(&list, &b);
    insertAtTail(&list, &c);

    int ret = deleteAtPosition(&list, 0);
    assert(ret == 0); // head deleted
    int expected1[] = {20, 30};
    assertListEquals(&list, expected1, 2);

    ret = deleteAtPosition(&list, 1); // tail deleted
    assert(ret == 0);
    int expected2[] = {20};
    assertListEquals(&list, expected2, 1);

    ret = deleteAtPosition(&list, 10); // invalid position
    assert(ret == 1);

    freeList(&list);
}

/* Test search */
void testSearch() {
    LinkedList list;
    initList(&list);

    int a = 5, b = 10, c = 15, x = 999;

    insertAtTail(&list, &a);
    insertAtTail(&list, &b);
    insertAtTail(&list, &c);

    Node* n = search(&list, &b, intCompare);
    assert(n != NULL && *(int*)n->data == 10);

    n = search(&list, &x, intCompare);
    assert(n == NULL);

    freeList(&list);
}

/* Test reverse */
void testReverse() {
    LinkedList list;
    initList(&list);

    int a = 1, b = 2, c = 3;

    insertAtTail(&list, &a);
    insertAtTail(&list, &b);
    insertAtTail(&list, &c);

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

    int a = 1, b = 2;
    insertAtTail(&list, &a);
    insertAtTail(&list, &b);

    assert(getLength(&list) == 2);

    freeList(&list);
}

/* Run all tests */
int main() {
    printf("Running Generic LinkedList Unit Tests...\n");

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

    printf("All generic linked list tests passed successfully!\n");
    return 0;
}

