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
void display(pile_t*);  /* Affiche toute la pile */
int insert(pile_t*, int, int); /* insert un element a une certaine position */
int premove(pile_t*, int*, int); /* retire un element a une certaine position */

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
  
  pile_t next;

  next = malloc(sizeof(pile_t));

  if(next==NULL)
    return -1;

  next->val = val;
  next->next = *pile;

  *pile = next;
  return 0;
}

int pop(pile_t* pile, int* val){
  
  pile_t top;

  if(is_empty(*pile))
    return -1;

  top = *pile;

  *pile = top->next;

  *val = top->val;

  free(top);

  return 0;

}

int destroy(pile_t* pile){
  
  int buff;

  while(!is_empty(*pile)){
    if(pop(pile, &buff)!=0)
      return -1;
  }

  return 0;
}

void display(pile_t* pile) {
  
  if(is_empty(*pile)){
    printf("Empty stack\n");
    return;
  }

  pile_t elem = *pile;

  while(elem != NULL){
    printf("%d", elem->val);
    if(elem->next != NULL)
      printf(" -> ");
    elem = elem->next;
  }

  printf("\n");
}

int insert(pile_t* pile, int val, int pos){
  if(pos==0)
    return push(pile, val);
  else
    return insert(&((*pile)->next), val, pos-1);
}

int premove(pile_t* pile, int* val, int pos){
  if(pos==0)
    return pop(pile, val);
  else
    return premove(&((*pile)->next), val, pos-1);
}


int main(){
   
  pile_t pile;

  init(&pile);

  display(&pile);

  printf("%d\n", push(&pile, 3));
  printf("%d\n", push(&pile, 1));

  int buff;

  display(&pile);

  insert(&pile, 2, 1);

  display(&pile);

  pop(&pile, &buff);
  printf("buff = %d\n", buff);

  display(&pile);

  premove(&pile, &buff, 1);
  printf("buff = %d\n", buff);

  display(&pile);

  destroy(&pile);

  return 0;
}

