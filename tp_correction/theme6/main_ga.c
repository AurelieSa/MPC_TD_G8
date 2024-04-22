#include "tableaux_grandissant/libga.h"
#include <stdio.h>
#include <stdlib.h>

void print_ga(struct ga_s* ga){
  printf("size : %u\n", ga->ga_size);
  for(unsigned int i=0; i<ga->ga_size; i++)
    printf("%u ", ga->ga_element[i]);
  printf("\n");
}

int main(void){
  struct ga_s ga;
  
  
  if(ga_new(&ga)!=0){
    printf("error during allocation\n");
    return -1;
  }

  print_ga(&ga);

  printf("%d\n", ga_set(&ga, 2, 4));

  print_ga(&ga);

  ga_set(&ga, 1, 7);

  print_ga(&ga);

  ga_set(&ga, 5, 42);

  print_ga(&ga);

  unsigned int val = 0;
  
  ga_get(&ga, 2, &val);

  printf("%u\n", val);

  printf("%d\n", ga_get(&ga, 7, &val));

  return 0;
}
