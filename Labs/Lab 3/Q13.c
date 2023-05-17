#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printfile(char filename[15]){
    char line[200];
    FILE *fp; 
    fp = fopen(filename, "r");
    for(int i = 0; i < 2; i++){
        fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
        //(including ’\0’) into line.
        printf("%s", line);
        }
    fclose(fp);

}

int printintegerfile(char filename[15]){
    char line[200];
    FILE *fp;
    fp = fopen(filename, "r");

    int num_lines = 0;
    int sum = 0;
    while(fgets(line, sizeof(line), fp)) {
        sum = sum + atoi(line);
        num_lines++;
    }
    // int num_array[num_lines];
    // *num_array = (int *)malloc(num_lines * sizeof(int));

    fclose(fp);
    // free(num_array);
    return sum/num_lines;
}
int main(){
    char filename[15] = "mariakaren.txt";
    strcpy(filename, "mariakaren.txt");
    printfile(filename);

    printf("\n%d\n", printintegerfile("integer.txt"));
}
