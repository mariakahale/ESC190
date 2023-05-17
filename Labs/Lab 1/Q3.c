#include <stdio.h>

void change_array(char *arr) {
    arr[1] = 'A';
}
int main() {
    char arr [] = {'1','2','3'};
    change_array(arr);
    printf("New array: %c %c %c", arr[0],arr[1],arr[2]);
    
}