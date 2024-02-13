#include <stdio.h>
#include <stdlib.h>

struct heap {
    int *val;
    int len;
};

// for heap, we create directly a dynamical one because we will change value directly into him
// (in method we want to pass by reference, not by value, otherwise when we leave the method the heap will be the same - at least len value)
struct heap* create_heap(int max_size){
    struct heap *p = malloc(sizeof(struct heap));
    p->len=0;
    p->val=malloc(sizeof(int)*max_size);
   return p;
}

int parent(int i){
    if(i==0)
        return 0;
    return (i-1)/2;
}

int left(int i){
    return 2*i+1;

}

int right (int i){
    return 2*i+2;
}

void print_heap(struct heap *p){
    for (int i=0;i<p->len;i++)
        printf("%d ", p->val[i]);
    printf("\n");
}

// insert into min heap
void insert(struct heap *h, int x){
    // add new elem at the end and increase heap used size
    h->val[h->len] = x;
    h->len++;

    int current_index = h->len-1;
    int parent_index = parent(current_index);
    while(current_index!=0){
        // if parent is smaller than the new inserted elem (so new inserted elem is bigger)
        // the heap property is already satisfied
        if(h->val[parent_index] < h->val[current_index])
            break;
        // otherwise, swap insert elem with his parent
        else {
            int tmp = h->val[current_index];
            h->val[current_index]=h->val[parent_index];
            h->val[parent_index]=tmp;
        }
        current_index=parent_index;
        parent_index=parent(current_index);
    }

}

int main(){
    struct heap *the_heap = create_heap(10);
    print_heap(the_heap);

    int vals[] = { 25, 40, 5, 72, 36, 80, 15};
    for(int i=0;i<7;i++)
        insert(the_heap, vals[i]);
    print_heap(the_heap);

}