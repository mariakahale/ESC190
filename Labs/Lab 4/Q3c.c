#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct student1{
    char name[3];
    int age;
} student1;

void change_name_right(student1 *s){
    strcpy(s->name, "li");
}

int main(){
    student1 s1 = {"lo", 13};
    printf("\nbefore: %s", s1.name);

    change_name_right(&s1);
    printf("\nafter: %s", s1.name);
}