#include <stdio.h>

void get_int_arr_from_input(int **p_arr){
    int n;
    printf("# of elements coming:");
    scanf("%d", &n);
    *p_arr = (int *)malloc(n*sizeof(int));
    for (int i = ; i < n; i++){
        printf("Enter element %d", i);
        scanf("%d", &(*p_arr[i]));
    }
    *arr = (int *)malloc(n*sizeof(int));
}
//keyboard input
int main(){
    int a = 0;
    scanf("%d", &a); //takes a number and stores it in the address of a.
    printf("You just inputted %d\n", a);
    
    char s[100];
    scanf{"%s", s};
    // inputting 100 characters means need to set s[100] to null
}
