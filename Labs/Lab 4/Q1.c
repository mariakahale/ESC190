#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(){
    FILE *fp = fopen("a.txt", "r");
    char line[200];
    if (fp == NULL){
        printf("ERROR");
    }
    else{
        while(fgets(line, sizeof(line), fp)){
            printf("%s", line);
        }
    }
}

void read_file_wrong(){
    FILE *fp = fopen("c.txt", "r");


    char line[200];
    while(fgets(line, sizeof(line), fp)){
        printf("%s", line);

    }
}
int main()
{
   read_file_wrong();


}