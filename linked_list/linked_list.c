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

// compute mean of elements from the list
float compute_list_mean(struct simple_list l){
    struct node *current_node = l.head;
    int sum = 0;
    int counter = 0;
    while(current_node != NULL){
        sum = sum + current_node->value;
        counter++;
        current_node = current_node->next;
    }

    if(counter == 0)
        return 0.0;

    float mean_value = (float)sum/counter;
    return mean_value;
}

// append at the end
void append_elem_to_list(struct simple_list l, int new_elem_value){
    struct node *current_node = l.head;
    // go to the end of the list
    while(current_node->next != NULL){
        current_node = current_node->next;
    }

    // create a new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node-> value = new_elem_value;
    new_node->next = NULL;

    // add new node to the end of the list
    current_node->next = new_node;

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

    float list_elem_mean = compute_list_mean(l2);
    printf("mean: %f\n", list_elem_mean);

    append_elem_to_list(l2, 80);
    print_plain_list_items(l2);
    printf("mean: %f\n", compute_list_mean(l2));

    return 0;
}