#include <stdio.h>
#include <assert.h>
#include "binary-search-tree.h"

// Helper to capture traversal output
void test_insert_and_traversals() {
    Node* root = NULL;

    root = insertElement(root, 50);
    root = insertElement(root, 30);
    root = insertElement(root, 70);
    root = insertElement(root, 20);
    root = insertElement(root, 40);
    root = insertElement(root, 60);
    root = insertElement(root, 80);

    // Inorder traversal of BST must be sorted
    printf("InOrder Traversal: (Expected: 20 30 40 50 60 70 80)\n");
    inOrderTraversal(root);
    printf("\n");

    // Preorder traversal
    printf("PreOrder Traversal (Expected: 50 30 20 40 70 60 80)\n");
    preOrderTraversal(root);
    printf("\n");

    // Postorder traversal
    printf("PostOrder Traversal (Expected: 20 40 30 60 80 70 50)\n");
    postOrderTraversal(root);
    printf("\n");

    freeTree(root);
}

void test_find_smallest_largest() {
    Node* root = NULL;
    int arr[] = {50, 25, 75, 10, 30, 60, 80};
    for (int i = 0; i < 7; i++) root = insertElement(root, arr[i]);

    Node* small = findSmallest(root);
    Node* large = findLargest(root);

    assert(small->data == 10);
    assert(large->data == 80);

    printf("✔ findSmallest & findLargest OK\n");

    freeTree(root);
}

void test_search() {
    Node* root = NULL;

    root = insertElement(root, 15);
    root = insertElement(root, 10);
    root = insertElement(root, 20);

    assert(findNode(root, 10) != NULL);
    assert(findNode(root, 100) == NULL);

    printf("✔ findNode OK\n");

    freeTree(root);
}

void test_delete() {
    Node* root = NULL;
    int arr[] = {40, 20, 10, 30, 60, 50, 70};
    for (int i = 0; i < 7; i++) root = insertElement(root, arr[i]);

    deleteElement(&root, 20);
    assert(findNode(root, 20) == NULL);

    
    deleteElement(&root, 10);
    assert(findNode(root, 10) == NULL);

    deleteElement(&root, 60);
    assert(findNode(root, 60) == NULL);
    inOrderTraversal(root);
    printf("✔ deleteElement OK\n");

    freeTree(root);
}

void test_counts_and_height() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) root = insertElement(root, arr[i]);

    assert(totalNodes(root) == 7);
    assert(totalExternalNodes(root) == 4); // leaves: 20, 40, 60, 80
    assert(totalInternalNodes(root) == 3); // 50, 30, 70
    assert(height(root) == 3); // height = longest path count

    printf("✔ totalNodes / totalExternalNodes / totalInternalNodes / height OK\n");

    freeTree(root);
}

// void test_mirror() {
//     Node* root = NULL;
//     int arr[] = {40, 20, 10, 30, 60, 50, 70};
//     for (int i = 0; i < 7; i++) root = insertElement(root, arr[i]);

//     Node* mirrored = mirrorImage(root);

//     // After mirror, smallest becomes largest
//     Node* smallest_mirror = findSmallest(mirrored);
//     Node* largest_mirror = findLargest(mirrored);

//     assert(smallest_mirror->data == 70);
//     assert(largest_mirror->data == 10);

//     printf("✔ mirrorImage OK\n");

//     freeTree(mirrored);
// }

int main() {
    printf("========== BST UNIT TESTS ==========\n");

    test_insert_and_traversals();
    test_find_smallest_largest();
    test_search();
    test_delete();
    // test_counts_and_height();
    // test_mirror();

    printf("========== ALL TESTS PASSED ==========\n");
    return 0;
}
