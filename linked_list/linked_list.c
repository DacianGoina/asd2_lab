#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node structure
struct node{
    int value;
    struct node* next;
};

// list structure - just to hold the first node
struct simple_list{
    struct node *head;
};

// this is for a list passed as pointer
void print_list_items(struct simple_list **l){
    struct node* current_node = (*l)->head;
    while(current_node != NULL){
        printf("node value = %d\n", current_node->value);
        current_node = current_node->next;
    }
}


// this is for a simple list
// -> is used only for pointers; here cannot because l1 is not a pointer, but above we can
void print_plain_list_items(struct simple_list l1){
    struct node* current_node = l1.head;
    while(current_node != NULL){
        printf("node value = %d\n", current_node->value);
        current_node = current_node->next;
    }
}

int main(){
    printf("success\n");

    // declare nodes
    struct node* n1 = malloc(sizeof(struct node));
    struct node* n2 = malloc(sizeof(struct node));
    struct node* n3 = malloc(sizeof(struct node));
    struct node* n4 = malloc(sizeof(struct node));

    // assign values
    n1->value = 5;
    n1->next = n2;

    n2->value = 7;
    n2->next = n3;

    n3->value = 1;
    n3->next = n4;

    n4->value = 10;
    n4->next = NULL;

    struct simple_list *l1 = malloc(sizeof(struct simple_list));
    l1->head = n1;
    print_list_items(&l1);
    printf("-------------------------\n");
    struct simple_list l2;
    l2.head = n1;
    print_plain_list_items(l2);
    return 0;
}