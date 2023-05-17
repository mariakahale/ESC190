#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "autocomplete.h"



int compare(const void *a, const void *b){
    int city_cmp = strcmp(((term *)a)->term , ((term *)b)->term);
    if (city_cmp != 0){
        return city_cmp;
    }
    return 0;
}

int compare2(const void *a, const void *b){
    if (((term *)a)->weight > ((term *)b)->weight){
      return -1;}
    else if (((term *)a)->weight < ((term *)b)->weight){
      return 1;
    }
    else if (((term *)a)->weight == ((term *)b)->weight){
      return 0;
    }
    return 0;

}

// void removespace(char *str){
//     int count = 0;

//     for (int i = 0; str[i]; i++){
//         if (str[i] != ' '){
//             str[count++] = str[i];}}
//     str[count] = '\0';

// }


void read_in_terms(term **terms, int *pnterms, char *filename){
    //open the file
    char line[200];
    FILE *fp;
    fp = fopen(filename, "r");

    //counts the number of terms (every line)
    int counter = 0;
    while(fgets(line, sizeof(line), fp)) {
        counter++;
    }
    fclose(fp);

  
    FILE *fp1;
    fp1 = fopen(filename, "r");    
    //creates a block of memory based on the number of lines
    *pnterms = counter;
    *terms = (term *)malloc(*pnterms * sizeof(term));

    //reads in information from text file.
    int i = 0;
    char line1[200];
    fgets(line1, 200, fp1);
    while(fgets(line1, sizeof(line1), fp1)){

        double weight;
        char *word;
        weight = strtod(line1, &word);
        (*terms)[i].weight = weight;
        word[strlen(word)-1] = '\0';
        strcpy((*terms)[i].term, word+1);
        i++;
    }
    fclose(fp1);
    // print_memory_block(terms, pnterms, filename);
    qsort(*terms, *pnterms, sizeof(term), compare);

    // print_memory_block(terms, pnterms, filename);

    

}


int lowest_match(term *terms, int nterms, char *substr){
    //binary search
    int high = nterms -1;
    int low = 0;
    int lowest_match = -1;
    // printf("askjbf %d", (strcmp(terms[mid].term, substr)));

    while (high >= low){
        // Normal Binary Search Logic 
        int mid = (low + high) / 2;
        
        char cropped_string [strlen(substr) + 1];
        int i = 0;
        while ((terms[mid].term[i] != '\0') && (strlen(substr) > i)){
            cropped_string[i] = terms[mid].term[i];
            i++;
        }
        cropped_string[i] = '\0';
                
        int comparison = (strcmp(cropped_string, substr));
        if (comparison<0){
            low = mid + 1;
        }
        else if (comparison>0){
            high = mid -1;
        }
        else {
            lowest_match = mid;
            high = mid -1;
        }
    }
    return lowest_match;
}

int highest_match(term *terms, int nterms, char *substr){
    //binary search
    int high = nterms -1;
    int low = 0;
    int lowest_match = -1;
    // printf("askjbf %d", (strcmp(terms[mid].term, substr)));

    while (high >= low){
        // Normal Binary Search Logic 
        int mid = (low + high) / 2;
        
        char cropped_string [strlen(substr) + 1];
        int i = 0;
        while ((terms[mid].term[i] != '\0') && (strlen(substr) > i)){
            cropped_string[i] = terms[mid].term[i];
            i++;
        }
        cropped_string[i] = '\0';
                
        int comparison = (strcmp(cropped_string, substr));
        if (comparison<0){
            low = mid + 1;
        }
        else if (comparison>0){
            high = mid-1;
        }
        else {
            lowest_match = mid;
            low = mid+1;
        }
    }
    return lowest_match;

    }

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr){
    int lowest_index = lowest_match(terms, nterms, substr);
    int highest_index = highest_match(terms, nterms, substr);
    printf("lowest, highest:%d %d", lowest_index, highest_index);

    if (lowest_index == -1){
        *n_answer = 0;
    }
    else{
        *n_answer = highest_index - lowest_index + 1;
        *answer = (term*)malloc(*n_answer * sizeof(term));

        //https://www.youtube.com/watch?v=yoa_mMmvlMc
        memcpy(*answer, &terms[lowest_index], *n_answer * sizeof(term));
        qsort(*answer, *n_answer, sizeof(term), compare2);
    }

    for (int j = 0; j<*n_answer; j++){
        printf("\nhere: %s", ((*answer)[j]).term);

    }
    printf("\nnanser: %d", *n_answer);





  
}




int main(void)
{
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "cities.txt");
    // printf("%s/n", terms[(lowest_match(terms, nterms, "Tor"))].term);
    printf("%d/n", (lowest_match(terms, nterms, "Tor")));

    printf("%s", terms[(highest_match(terms, nterms, "Tor"))].term);
    
    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice

    free(terms);

    return 0;
}

