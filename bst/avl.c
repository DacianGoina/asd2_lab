#include<stdlib.h>
#include<stdio.h>

struct node {
    int key, height;
    struct node *left, *right, *parent;
};

struct tree {
    struct node *root;
};

// not complete insertion for avl tree
void insert(struct tree *a, int k) {
    struct node *iterator = a->root;
    struct node *parent = NULL;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = k;
    new_node->left = NULL;
    new_node->parent = NULL;
    new_node->right = NULL;
    new_node->height = 0;

    if (a->root == NULL) {
        a->root = new_node;
        return;
    }

    // travel until find a free spot
    while (iterator != NULL) {
        parent = iterator;
        if (k < iterator->key)
            iterator = iterator->left;
        else
            iterator = iterator->right;
    }
    // assign the parent of the new node
    new_node->parent = parent;

    // update the left or right child of the parent
    if (k < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;
}

// here you should pass the tree, alongside with the root node of the subtree that cause the imbalance
// e.g for the case
// 1
//  \
//    2
//      \
//       3
//
// you should use rotation on node 1

void rotate_left(struct tree *a, struct node *n) {
    struct node *pivot = n->right;
    if (n->parent == NULL) {
        a->root = pivot;
    } else if (n == n->parent->left) {
        n->parent->left = pivot;
    } else {
        n->parent->right = pivot;
    }
    n->right = pivot->left;
    pivot->left = n;
    n->parent = pivot;
}

// here you should pass the tree, alongside with the root node of the subtree that cause the imbalance
void rotate_right(struct tree *a, struct node *n) {
    struct node * pivot = n->left;
    if(n->parent == NULL)
        a->root = pivot;
    else if(n == n->parent->left)
        n->parent->left = pivot;
    else
        n->parent->right = pivot;
    n->left = pivot->right;
    pivot->right = n;
    n->parent = pivot;
}

void print_bst_preorder(struct node* n){
    if(n==NULL)
        return;
    printf("%d ", n->key);
    print_bst_preorder(n->left);
    print_bst_preorder(n->right);
}


int main(){
    printf("success !\n");

    // create a tree and insert some nodes
    struct tree *t = malloc(sizeof(struct tree));
    insert(t, 1);
    insert(t, 2);
    insert(t, 3);
    print_bst_preorder(t->root);
    printf("\n");

    // perform a left rotation
    struct node *n = t->root;
    rotate_left(t, n);
    print_bst_preorder(t->root);

    return 0;
}