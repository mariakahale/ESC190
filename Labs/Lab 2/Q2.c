
#include <stdio.h>
#include <string.h>

void concatenate_strings_1(char *str1, char *str2){

  int total_length = strlen(str1) + strlen(str2);
  char conc_string[total_length +1];

  for (int i = 0; i < strlen(str1); i++){
    conc_string[i] = str1[i];
    
  }
  for (int j = strlen(str1); j < total_length; j++){
    conc_string[j] = str2[j-strlen(str1)];
    
  }

  conc_string[total_length] = '\0';

  printf("From 1 %s \n", conc_string);
}

void concatenate_strings_2(char *str1, char *str2){
  unsigned total_length = (strlen(str1) + strlen(str2));
  char conc_string[total_length +1];

  char *p;  
  p = &conc_string[0];

  int i = 0;

  while(i<(strlen(str1))){
    *p = str1[i];
    p++;
    i++;
  }

  int j = strlen(str1);
  while(j<total_length){
    *p = str2[j-strlen(str1)];
    p++;
    j++;
  }

  *p = '\0';

  printf("From 2 %s \n", conc_string);
  }

  
  



int main(){
  char str1[] = "Hello ";
  char str2[] = "World"; 

  concatenate_strings_1(str1, str2);
  concatenate_strings_2(str1, str2);
    
}