#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node structure
struct node{
    int value;
    struct node* next;
};

// list structure - just to hold the first node
struct circular_list{
    struct node *head;
};

// this is for a simple list
// -> is used only for pointers; here cannot because l1 is not a pointer, but above we can
void print_list_items(struct circular_list l1){
    // empty list
    if(l1.head == NULL){
        return;
    }


    printf("node value = %d\n", l1.head->value);
    // single elem in list
    if(l1.head->next == NULL){
        return;
    }

    struct node* current_node = l1.head->next;
    struct node *first_node = l1.head;
    while(current_node != first_node){
        printf("node value = %d\n", current_node->value);
        current_node = current_node->next;
    }
}


// append at the end
void append_elem_to_list(struct circular_list l1, int new_elem_value){

    // create a new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node-> value = new_elem_value;
    new_node->next = NULL;

    // empty list
    if(l1.head == NULL){
       l1.head = new_node;
       return;
    }


    // single elem in list
    if(l1.head->next == NULL){
        l1.head->next = new_node;
        return;
    }

    struct node* current_node = l1.head->next;
    struct node *first_node = l1.head;
    while(current_node->next != first_node){
        current_node = current_node->next;
    }

    current_node->next = new_node;
    new_node->next = first_node;

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
    n4->next = n1;

    struct circular_list l2;
    l2.head = n1;
    print_list_items(l2);

    append_elem_to_list(l2, 77);
    printf("\n");
    print_list_items(l2);

//    float list_elem_mean = compute_list_mean(l2);
//    printf("mean: %f\n", list_elem_mean);
//
//    append_elem_to_list(l2, 80);
//    print_plain_list_items(l2);
//    printf("mean: %f\n", compute_list_mean(l2));

    return 0;
}