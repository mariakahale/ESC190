
#include <stdio.h>
#include <string.h>

int my_strcmp_rec(char *str1,  char *str2){

  int length;

  if (strlen(str1) > strlen(str2)){
    length = strlen(str2);
  }
  else{
    length = strlen(str1);
  }

  int i = 0;
  //use pointer arithmetic
  while (i<length && str1[i] == str2[i]){
    i++;
    
  }
  if (str1[i]>str2[i]){
    return 1;
  }
  else if (str1[i]<str2[i]){
    return -1;}
  else{
    return 0;
  }
  }



int main(){
  char str1[] = "abcd";
  char str2[] = "abCd"; 


  int final_answer = my_strcmp_rec(str1, str2);
  printf("%d", final_answer);
  return 0;
}
