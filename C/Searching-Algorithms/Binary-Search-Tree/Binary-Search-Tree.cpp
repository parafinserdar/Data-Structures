#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}


void preOrder(struct TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(struct TreeNode* node) {
    if (node == NULL) return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

void postOrder(struct TreeNode* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}