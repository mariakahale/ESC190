#include <stdio.h>
#include <ctype.h>

int my_atoi(char *str){
    int i = 0;
    int res = 0;
    while (isdigit(str[i])){
        res = res * 10 + (str[i] -'0');
        i++;

    }
    return res;
}

int main(){
    char myNum[] = "123";
    int converted = my_atoi(myNum);
    printf("%d", converted);
    return converted;

}