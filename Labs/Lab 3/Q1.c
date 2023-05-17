#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_int1(int x)
{
    x = 42;
}

void set_int2(int *p_x)
{
    *p_x = 42;
}

int main(){
    int a = 10;
    set_int1(a); //sends a copy of a to the fn. //only changes local copy
    set_int2(&a); //passes address, so pointer access original copy, changes value
    printf("%d", a);
}