#include <stdio.h>

void change_value(int *num) {
    *num = 10;
}
int main() {
    int a = 5;
    change_value(&a);
    printf("New value: %d", a);
    
}

