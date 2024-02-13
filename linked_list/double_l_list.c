#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node structure - for double linked list
struct node{
    int value;
    struct node* next;
    struct node* prev;
};

// list structure
struct double_l_list{
    struct node *head;
    struct node *tail;
};

// this is for a simple list
// -> is used only for pointers; here cannot because l1 is not a pointer, but above we can
void print_double_l_list_items_forward(struct double_l_list l1){
    struct node* current_node = l1.head;
    while(current_node != NULL){
        printf("node value = %d\n", current_node->value);
        current_node = current_node->next;
    }
}

void print_double_l_list_items_backward(struct double_l_list l1){
    struct node* current_node = l1.tail;
    while(current_node != NULL){
        printf("node value = %d\n", current_node->value);
        current_node = current_node->prev;
    }
}

// append at the end
void append_elem_to_list(struct double_l_list l, int new_elem_value){
    struct node *last_node = l.tail;

    // create a new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node-> value = new_elem_value;
    new_node->next = NULL;
    new_node->prev = last_node;

    last_node-> next = new_node;

    // add new node to the end of the list
    l.tail = new_node;
}


int main(){
    printf("success\n");

    // declare nodes
    struct node* n1 = malloc(sizeof(struct node));
    struct node* n2 = malloc(sizeof(struct node));
    struct node* n3 = malloc(sizeof(struct node));
    struct node* n4 = malloc(sizeof(struct node));
    struct node* n5 = malloc(sizeof(struct node));

    // assign values
    n1->value = 5;
    n1->next = n2;
    n1->prev = NULL;

    n2->value = 7;
    n2->next = n3;
    n2->prev = n1;

    n3->value = 1;
    n3->next = n4;
    n3->prev = n2;

    n4->value = 10;
    n4->next = n5;
    n4->prev = n3;

    n5->value = 15;
    n5->next = NULL;
    n5->prev = n4;

    struct double_l_list l2;
    l2.head = n1;
    l2.tail = n5;
    print_double_l_list_items_forward(l2);
    printf("-------------------\n");
    print_double_l_list_items_backward(l2);

    printf("-------------------\n");

    append_elem_to_list(l2, 56);
    print_double_l_list_items_forward(l2);

//    float list_elem_mean = compute_list_mean(l2);
//    printf("mean: %f\n", list_elem_mean);
//
//    append_elem_to_list(l2, 80);
//    print_plain_list_items(l2);
//    printf("mean: %f\n", compute_list_mean(l2));

    return 0;
}