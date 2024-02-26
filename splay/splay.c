#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
    struct node *parent;
};
struct tree {
    struct node *root;
};

struct node* create_node(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

void insert(struct tree *a, int k) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = k;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    if (a->root == NULL) {
        a->root = new_node;
        return;
    }

    struct node *current = a->root;
    struct node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (k < current->key) {
            current = current->left;
        } else if (k > current->key) {
            current = current->right;
        } else {
            free(new_node); // Duplicate key, ignore insertion
            return;
        }
    }

    new_node->parent = parent;

    if (k < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

void rotate_left(struct tree *a, struct node *n) {
    if (n == NULL || n->right == NULL)
        return;

    struct node *pivot = n->right;
    n->right = pivot->left;

    if (pivot->left != NULL)
        pivot->left->parent = n;

    pivot->parent = n->parent;

    if (n->parent == NULL)
        a->root = pivot;
    else if (n == n->parent->left)
        n->parent->left = pivot;
    else
        n->parent->right = pivot;

    pivot->left = n;
    n->parent = pivot;
}

int main(){
    printf("success\n");
}