#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
    char * name;
    int age;
    int salary;
};

void print_person(struct person person_item){
    printf("age = %d, salary = %d, name = %s\n", person_item.age, person_item.salary, person_item.name);
}

struct person create_person(int age, int salary, char*name_value){
    struct person aux;
    aux.age = age;
    aux.salary = salary;
    strcpy(aux.name, name_value);
    return aux;
}

int main(){
    printf("success\n");
    struct person p1;
    p1.age = 25;
    p1.salary = 4000;
    p1.name = malloc(20 * sizeof(char));
    strcpy(p1.name, "Alin");
    print_person(p1);

    printf("---------------------\n");
    struct person p2 = create_person(11, 0, "Daniel");
    print_person(p2);
    return 0;
}