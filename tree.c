#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
}Node;

Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}


void insert(Node** root, int data) {
    if(*root == NULL) {
        Node* node = createNode(data);
        *root = node;
        return;
    }
    if(data < (*root)->data) {
        insert(&(*root)->left, data);
    }
    if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }
}

void preorder(Node** root) {
    if(*root == NULL) {
        return;
    }
    printf("%d\t", (*root)->data);
    preorder(&(*root)->left);
    preorder(&(*root)->right);
}

void inorder(Node** root) {
    if(*root == NULL) {
        return;
    }
    inorder(&(*root)->left);
    printf("%d\t", (*root)->data);
    inorder(&(*root)->right);
}

void postorder(Node** root) {
    if(*root == NULL) {
        return;
    }
    postorder(&(*root)->left);
    postorder(&(*root)->right);
    printf("%d\t", (*root)->data);
}

int main() {
    Node* head = NULL;
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 20);
    insert(&head, 10);
    insert(&head, 25);
    insert(&head, 50);
    preorder(&head);
    printf("\n");
    inorder(&head);
    printf("\n");
    postorder(&head);
}
