#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int get_num_lines(char *filename){
    char line[200];
    FILE *fp;
    fp = fopen(filename, "r");

    int counter = 0;
    while (fgets(line, sizeof(line), fp)){
        //increments the counter for every new line
        counter++;
    }
    fclose(fp);
    return counter;
}

double my_atoi(const char *str)
{
    //converts the character sent into an integer, assuming it is an integer
    int i = 0;
    int sign = 1;
    if(str[i] == '-'){
        sign = -1;
        i++;
    }
    double result = 0;
    while(str[i] >='0' && str[i] <= '9'){
        result = result * 10 + (str[i] - '0');
        i++;
    }
    int dec_pnt = 0;
    if (str[i] == '.'){
        dec_pnt = 1;
    }
    i++;
    double dec_result = 0;
    int j = 0;
    if (i != strlen(str) -1){
        if (dec_pnt == 1){
            while(str[i] >='0' && str[i] <= '9'){
                dec_result = dec_result * 10 + (str[i] - '0');
                i++;
                j++;
            }
    }

    }
    printf("\nDec_result: %lf %d %f ", dec_result, j, sign * (result + (dec_result)/pow(10, j)));



return sign * (result + (double)(dec_result)/pow(10, j));
}

int check_alpha(const char *str)
{
    //relies on the fact that the character does not go through the loop
    //unless it is within the bounds.
    //if it does not go into the bounds, then it is considered non-int.
    int i = 0;

    int result = 0;
    int changed = 1;
    while(str[i] >='0' && str[i] <= '9'){
        changed = 0;
        i++;
    }
return changed;
}

double calc_sum(char *filename, int num_constants){
    char line[200];
    FILE *fp;
    fp = fopen(filename, "r");

    double nums[num_constants];
    int j = 0;
    int l = 0;

    while(fgets(line, sizeof(line), fp)){

        int line_length = strlen(line);
        int i = 0;
        while ((check_alpha(&line[i]) == 1) && i < line_length){ 
            //iterates until first num is reached
            i++;}
        printf("\ni: %d, line num: %d", i, j);
        //cuts string into substring
        char substr[line_length -i];
        strncpy(substr, line + i, (line_length - i));
        substr[line_length - i] = '\0';
        printf(" substr:%s", substr);



        //converts to integer
        printf("\nmaria: %f", my_atoi(substr));
        nums[j] = my_atoi(substr) ;
        j++;
        }
    double sum = 0;
    for (int k = 0; k < num_constants; k++){
        printf("\n output: %f %d", nums[k], k);
        sum = sum + nums[k];
            }



    return sum;
}
    
    

int main(){

    printf("\nfinal output: %lf", calc_sum("constants.txt", get_num_lines("constants.txt")));
}