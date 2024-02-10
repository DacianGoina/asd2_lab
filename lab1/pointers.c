#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void double_dynamically_pointer(int **a){
    **a = (**a) * 2;
}

void pow2_dynamically(int *a){
    *a = (*a) * (*a);
}

char* make_copy(char *array){
    int n = strlen(array);
    printf("%d\n",n);
    char* the_copy = malloc((n+1) * sizeof(char) );
    strcpy(the_copy, array);
    return the_copy;
}


int main() {

//    & gets the address of a variable.
//    * dereferences a pointer, accessing the value stored at the memory address it points to

   int  *pi = malloc(sizeof(int)); // memory allocation
   *pi = 15; // value assignation
   printf("value = %d\n", *pi);
   double_dynamically_pointer(&pi);
   printf("value = %d\n", *pi);
   free(pi);


   printf("\n\n");
   int a2 = 50;
   printf("value = %d\n", a2);
   pow2_dynamically(&a2);
   printf("value = %d\n", a2);


   char *text_val = malloc(20 * sizeof(char));
   strcpy(text_val, "this is a text");
   printf("text value = %s\n", text_val);
   //free(text_val);
   printf("---------------\n");
   char* res = make_copy(text_val);
   printf("result: %s\n", res);

   return 0;
}