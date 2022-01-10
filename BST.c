#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node * left, * right;
};

struct node * newNode(int item) {
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

struct node * insert(struct node * node, int item) {
    if (node == NULL) 
        return newNode(item);

    if (item < node -> key)
        node -> left = insert(node -> left, item);

    else if (item > node -> key)
        node -> right = insert(node -> right, item);

    return node;
}

void inorder(struct node * node) {
    if (node != NULL) {
        inorder(node -> left);
        printf("%d ", node -> key);
        inorder(node -> right);
    }
}

struct node * search(struct node * root, int key) {
    if (root == NULL || root -> key == key)
        return root;
    
    if (key > root -> key) 
        return search(root -> right, key);
    
    return search(root -> left, key);
}

int main() {
    struct node * root = NULL;
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 60);
    insert(root, 70);
    insert(root, 65);
    printf("Inorder Traversal:\n");
    inorder(root);

    printf("\nSearching:\n");
    struct node * temp;
    temp = search(root, 70);
    printf("%f ", temp);
    return 0;
}