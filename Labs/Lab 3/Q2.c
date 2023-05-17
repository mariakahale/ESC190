#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


//Question 2
void print_student_info(student1 s1){
    printf("Name %s \n", s1.name);
    printf("student # %s \n", s1.student_number);
    printf("Year: %d \n", s1.year);
}

//Question 3 a)
void set_default_name(student1 *p_s){
    strcpy(p_s->name, "DEFAULT");
    //Q3b)
    p_s->year = 10; //this works because it is accessing the parameter (original copy)
}

//Question 3 b)
void set_default_name_wrong(student1 s1){
    strcpy(s1.name, "Jane");
    s1.year = 20; //Q3b this doesn't work because it is changing the local copy.
}
//Question 4
void create_block1(student1 **p_p_s, int n_students){
    *p_p_s = (student1*)malloc(n_students * sizeof(student1));
}

//Question 5
void set_name(student1 *p_s1, char *string){
    strcpy(p_s1->name, string);
    p_s1->name[199] = '\0';
}

//Question 6
void destroy_block1(student1 *p_p_students){
    free(p_p_students);
}

//Question 7
void create_block2(student2 **p_p_s, int num_students){
    *p_p_s = (student2 *)malloc(num_students * sizeof(student2));
    for (int i=0; i<num_students; i++){
        (*p_p_s)[i].name = 0;
        (*p_p_s)[i].student_number= 0;

    }
}

//Question 8
void set_name2(student2 *p_s2){

    printf("\nEnter the name for student 2\n");
    char temp_string[200];
    scanf("%s", temp_string);
    
    char name[200];
    int length = strlen(temp_string);
    p_s2->name = (char *)malloc((length+1) * sizeof(char));
    strcpy(p_s2->name, temp_string);
    p_s2->name[length]='\0';

}

//Question 9
void destroy_block2(student2 *p_p_students2){
    free(p_p_students2->name);
    free(p_p_students2);

}

//Question 10
void test_changing_names(student1 s1, student2 *s2){
    strcpy(s1.name, "Test1 for student1");
    strcpy(s2->name, "Test1 for student2");
}
int main(){
    //Question 2
    student1 s1 = {"Betty", "1008922339", 2};
    // print_student_info(s1);

    //Question 3 a)
    set_default_name(&s1);
    // print_student_info(s1);

    //Question 3 b)
    set_default_name_wrong(s1);
    print_student_info(s1);

    //Question 4
    int n_students = 5;
    student1 *p_p_students;
    create_block1(&p_p_students, n_students);

    // for (int i=0; i < n_students; i++){
    //     //new function it assigns the string on the right to the object on the left.
    //     sprintf(p_p_students[i].name, "A%d", i);
    //     sprintf(p_p_students[i].student_number, "10092%d", i);
    //     p_p_students[i].year = 14;
    // }

    for (int i=0; i < n_students; i++){
        char studentnames[] = "Jane ";
        studentnames[4] = i;
        strcpy(p_p_students[i].name, studentnames);
        strcpy(p_p_students[i].student_number, "10000");
        p_p_students[i].year = i;
    }

    // for (int i = 0; i < n_students; i++) {
    //     print_student_info(p_p_students[i]);
    // }

    //Question 5
    // set_name(&p_p_students[3], "Jennifer akjsbfaskjbf;askjbf");
    // printf("\nQ5 %s", p_p_students[3].name);

    //Question 6
    destroy_block1(p_p_students);

    // free(p_p_students);

    //Question 7
    int num_students = 5;
    student2 *p_p_students2;
    create_block2(&p_p_students2, num_students);    

    //Question 8
    // set_name2(&p_p_students2[0]);
    // printf("Q8 %s \n", p_p_students2[0].name);

    //Question 9
    destroy_block2(p_p_students2);

    //Question 10
    //In the structure for student1, you are passing in a copy of the structure's contents
    //In student2, you are passing the pointer, which is the address of the original contents
    //and can hence be edited.
    //Let's test this.
    // student1 s11 = {"Jane D", "0", 3};

    // student2 *s22;
    // s22 = (student2 *)malloc(sizeof(student2)*1);
    // s22->name = (char *)malloc(sizeof(char)*2);
    // strcpy(s22->name, "A");
    
    // printf("\nbefore: s1: %s \n s2: %s\n", s11.name, s22->name);

    // test_changing_names(s11, &s22[0]);
    // printf("\nafter: s1: %s \n s2: %s", s11.name, s22->name);
    // free(s22);

    
    return 0;
}

