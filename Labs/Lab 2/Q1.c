
#include <stdio.h>
#include <stdlib.h>

void getString(char **input, int *length){
  printf("Enter number of chars in string");
  scanf("%d", &(*length));

  *input = (char *)malloc((*length + 1) * sizeof(char));
  
  printf("Enter chars of string");
  for (int i = 0; i < *length; i++) {
      scanf(" %c", &(*input)[i]);
  }
  (*input)[*length] = '\0';

  
}

int main(){
  int length;
  char *input;

  getString(&input, &length);

  printf("Final string is %s", input);
  free(input);
  return 0;
}