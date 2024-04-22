#include <stdio.h>
#include <stdlib.h>
#include "libga.h"
#include <string.h>

int ga_set(struct ga_s* ga, unsigned int index, int val){

  if(ga == NULL)
    return -1;

  if(ga->ga_size < index){
    unsigned int* new;
    new = malloc((index+1)*sizeof(unsigned int));
    if(new==NULL)
      return -1;

    if(ga->ga_size == 0){
      for(unsigned int i=0; i<index; i++)
        new[i] = 0;
    } else {
      memcpy(new, ga->ga_element, ga->ga_size*sizeof(unsigned int));
      free(ga->ga_element);
    }
    
    ga->ga_element = new;
    ga->ga_size = index+1;


  }

  ga->ga_element[index] = val;

  return 0;
}

int ga_get(struct ga_s* ga, unsigned int index, unsigned int* val){
  if(ga == NULL)
    return -1;

  if(index >= ga->ga_size)
    return -2;

  *val = ga->ga_element[index];

  return 0;
}

int ga_new(struct ga_s* ga){
  
  if(ga == NULL)
    return -1;

  ga->ga_size = 0;
  ga->ga_element = NULL;

  return 0;
} 

int ga_del(struct ga_s* ga){
  free(ga->ga_element);
  ga->ga_size = 0;

  return 0;
} 
