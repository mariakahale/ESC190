#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    if(str[i] == '-'){
        sign = -1;
        i++;
    }
    int result = 0;
    int changed = 1;
    while(str[i] >='0' && str[i] <= '9'){
        changed = 0;
        result = result * 10 + (str[i] - '0');
        i++;
    }
return result * sign;
}
int check_alpha(const char *str)
{
    int i = 0;

    int result = 0;
    int changed = 1;
    while(str[i] >='0' && str[i] <= '9'){
        changed = 0;
        i++;
    }
return changed;
}
int main(){
    printf("%d", my_atoi(" 100"));
}