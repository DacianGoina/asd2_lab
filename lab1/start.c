#include <stdio.h>

int double_value(int x){
    return x*2;
}

void double_all_from_array(int a[], int n){
    for(int i=0;i<n;i++)
        a[i] = 2*a[i];
}

void print_array(int a[], int n){
     for(int i=0;i<n;i++)
        printf("%d ",a[i]);
     printf("\n");
}

int main() {
   // printf() displays the string inside quotation

    int v[] = {2, 4, 5, 8, 10};
    int n = 5;
    print_array(v, n);
    double_all_from_array(v, n);
    print_array(v,n);


   return 0;
}
