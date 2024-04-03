#include <stdio.h>
#include <stdlib.h>

struct pile_elem_s {
  int val;
  struct pile_elem_s* next;
};

typedef struct pile_elem_s* pile_t;

#define PILE_VIDE ((pile_t) 0)

int is_empty(pile_t);     /* vraie ssi la pile est vide */
int init(pile_t*);       /* initialise la pile */
int push(pile_t*, int);  /* empile une valeur */
int pop(pile_t*, int*); /* dépile une valeur */
int destroy(pile_t*);    /* désalloue toute la pile */


int is_empty(pile_t pile){
  return pile==PILE_VIDE;
}

int init(pile_t* pile){
  
  if(pile==NULL)
    return -1;

  *pile = PILE_VIDE;

  return 0;
}

int push(pile_t* pile, int val){
  // TODO
}

int pop(pile_t* pile, int* val){
  // TODO
}

int destroy(pile_t* pile){
  // TODO  
}


int main(){

  pile_t pile;

  init(&pile);

  printf("%d\n", is_empty(pile));
  
  push(&pile, 1);
  
  printf("%d\n", is_empty(pile));
  
  push(&pile, 2);

  int val = 0;
  
  pop(&pile, &val);
  printf("%d\n", val);

  pop(&pile, &val);
  printf("%d\n", val);

  printf("%d\n", is_empty(pile));
  
  push(&pile, 1);
  push(&pile, 2);

  printf("%d\n", is_empty(pile));

  destroy(&pile);
  printf("%d\n", is_empty(pile));

  return 0;
}


