#include <stdio.h>
//remember, strings are stored as {'h','e','l','l','o','\0'}
int main() {
    int string_length = 0;
    int i = 0;
    char *string = "hello";
    for (i=0; string[i] != '\0'; i++) {
        string_length++;

    }
    printf("%d", string_length);
    return 0;
}