#include <stdio.h>
#include <stdlib.h>


struct node{
    float val;
    struct node *left;
    struct node *right;
};

struct bst{
    struct node *root;
};

void insert_into_bst(struct bst t, float new_node_val){

     // create new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node->val = new_node_val;

    if(t.root == NULL){
        t.root = new_node;
        return;
    }

    struct node *current = t.root;
    struct node *parent = NULL;

    // travel until find a free spot; also respect tree properties
    while(current != NULL){
        parent = current;
        if(new_node_val< parent->val){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }

    // now we are in a parent that have a free spot
    // just append the node
    if (new_node_val < parent->val)
        parent->left = new_node;
    else
        parent->right = new_node;
}
// pre : so the root is first (in the "pre" position): (root left right)
// for inorder, the root is "in" / in the middle: (left root right)
// in post order, the root is post / after: (left right root)
// the initial passed node n must to be the root of the tree
void print_bst_preorder(struct node* n){
    if(n==NULL)
        return;
    printf("%.2f ", n->val);
    print_bst_preorder(n->left);
    print_bst_preorder(n->right);
}

void print_bst_inorder(struct node *n){
    if(n==NULL)
        return;

    print_bst_inorder(n->left);
    printf("%.2f ", n->val);
    print_bst_inorder(n->right);
}

 // search for the parent of the node with the given value
struct node* search_parent(struct bst a, float k){
    struct node *iterator = a.root;
    struct node *parent;
    int ok = 0;
    while(iterator != NULL && iterator->val != k)
        {
            parent = iterator;
            if(k < iterator->val)
                iterator = iterator->left;
            else
                iterator = iterator->right;
        }
    if(parent == NULL)
        return NULL;
    else
        return parent;
}

 // search for the node with the given value
struct node* search(struct bst a, int k){
    struct node *iterator = a.root;
    int ok = 0;
    while(iterator != NULL)
    {
        if(iterator->val == k)
            return iterator;
        if(k < iterator->val)
            iterator = iterator->left;
        else
            iterator = iterator->right;
    }
    if(iterator == NULL)
        return NULL;
}

float successor(struct bst a,float val){
    // search for the node with the given value
    struct node *n = search(a,val);

    // is node is not in the tree, return something dummy
    if(n == NULL){
        return 10000000.0;
    }

    // check for right subtree
    if(n->right != NULL) {
        struct node *iterator = n->right;
        while (iterator->left != NULL)
            iterator = iterator->left;
        return iterator->val;
    }
    // travel the tree up
    else {
        struct node *parent = search_parent(a,n->val);
        while(parent != NULL && parent->right == n)
        {
            n = parent;
            parent = search_parent(a,n->val);
        }
        return parent->val;
    }
}


int main(){
    printf("success\n");
    int l = 9;
    float v[] = {8,11,7,9,10.5,12,5,7.5,13};

    struct bst t1;
    struct node *n1 = malloc(sizeof(struct node));
    n1->val = 10.0;
    t1.root = n1;

    for(int i=0;i<l;i++){
        insert_into_bst(t1, v[i]);
    }

    float x = 9;
    printf("successor of %.2f is %.2f\n", x, successor(t1,x));


}