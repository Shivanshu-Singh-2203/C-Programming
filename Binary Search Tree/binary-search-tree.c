#include "binary-search-tree.h"

Node* createTree(int data){
    Node* newTree = malloc(sizeof(Node));
    if(newTree == NULL){
        perror("Memory Allocation Failure.\n");

        exit(1);
    }
    newTree->data = data;
    newTree->left = NULL;
    newTree->right = NULL;
    return newTree;
}

Node* insertElement(Node* root, int val){
    if(root == NULL){
        return createTree(val);
    }

    Node* parentPtr, *nodePtr, *ptr;

    ptr = createTree(val);
    parentPtr = NULL;
    nodePtr = root;
    while(nodePtr != NULL){
        parentPtr = nodePtr;
        if(nodePtr->data > val){
            nodePtr = nodePtr->left;
        }
        else if(nodePtr->data < val){
            nodePtr = nodePtr->right;
        }
        else {
            free(ptr);
            return root;
        }
    }

    if(val < parentPtr->data){
        parentPtr->left = ptr;
    }
    else {
        parentPtr->right = ptr;
    }
    return root;
}

void preOrderTraversal(Node *root){
    if(root == NULL){
        return;
    }
    printf("%d -> ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node * root){
    if(root == NULL){
        return;
    }
    preOrderTraversal(root->left);
    printf("%d -> ", root->data);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node * root){
    if(root == NULL){
        printf("NULL");
        return;
    }
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    printf("%d -> ", root->data);
    
}

Node* findLargest(Node* root){
    if(root == NULL || root->right == NULL){
        return root;
    }
    return findLargest(root->right);
}


Node* findSmallest(Node* root){
    if(root == NULL || root->left == NULL){
        return root;
    }
    return findSmallest(root->left);
}

Node* findNode(Node* root, int val){
    if (root == NULL || root->data == val) {
        return root;
    }
    if (root->data < val) {
        return findNode(root->right, val);
    }
    else {
        return findNode(root->left, val);
    }
}


int isLeaf(Node *node){
    if(node != NULL && node->right == NULL && node->left){
        return 0;
    }
    return 1;
}

Node* findInorderSuccesor(Node* curr){
    if (curr == NULL || curr->right == NULL) {
        return NULL;
    }

    Node* temp = curr->right;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

int deleteElement(Node** root, int val){
    if (*root == NULL) {
        return 1;
    }
    else if ((*root)->data < val) {
        return deleteElement(&((*root)->right), val);
    }
    else if ((*root)->data > val) {
        return deleteElement(&((*root)->left), val);
    }

    Node* temp;
    if ((*root)->left == NULL) {
        temp = (*root)->right;
        free(*root);
        *root = temp;
        return 0;
    }

    if ((*root)->right == NULL) {
        temp = (*root)->left;
        free(*root);
        *root = temp;
        return 0;
    }
    Node* succ = findInorderSuccesor(*root);
    (*root)->data = succ->data;
    
    return 0;
}

void mirrorTree(Node* root, Node* ptr){
    if(root == NULL){
        return;
    }

    mirrorTree(root->left, ptr);
    mirrorTree(root->right,ptr);
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}
Node* mirrorImages(Node* root){
    Node* ptr = malloc(sizeof(Node));
    mirrorTree(root, ptr);
    return ptr;
}

int height(Node *root){
    if(root == NULL){
        return 0;
    }

    int right = height(root->right);
    int left = height(root->left);
    int max = right > left ? right : left;
    return max + 1;
}

int totalNodes(Node * root){
    if(root == NULL){
        return 0;
    }
    return totalNodes(root->left ) + totalNodes(root->right) + 1;
}

int totalInternalNodes(Node *root){
    if (root== NULL) {
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    return totalInternalNodes(root->left ) + totalInternalNodes(root->right) + 1;
}

int totalExternalNodes(Node *root){
    if (root== NULL) {
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return totalExternalNodes(root->left ) + totalExternalNodes(root->right) ;
}

void deleteTree(Node* root, Node* node){
    Node* curr = findNode(root, node->data);
    freeTree(curr);
}

void freeTree(Node* root){
    if(root == NULL){
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}