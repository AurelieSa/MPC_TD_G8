#include <stdio.h>
#include <stdlib.h>
#include "ififo_lib.h"


struct ififo_s* ififo_new(void) {
  struct ififo_s* fifo;

  fifo = malloc(sizeof(struct ififo_s));

  if(fifo==NULL)
    return NULL;

  fifo->head = NULL;
  fifo->tail = NULL;

  return fifo;
}

int ififo_is_empty(struct ififo_s* fifo){
  return fifo->head == NULL;
}

int ififo_enqueue(struct ififo_s* fifo, int val){
  struct ififo_node_s* new_node;

  new_node = malloc(sizeof(struct ififo_node_s));

  if(new_node==NULL)
    return -1;
  
  new_node->val = val;

  if(ififo_is_empty(fifo)){
    new_node->next = NULL;
    fifo->head = new_node;
    fifo->tail = new_node;
  } else {
    new_node->next = NULL;
    fifo->tail->next = new_node;
    fifo->tail = new_node;
  }
  return 0;
} 

int ififo_dequeue(struct ififo_s* fifo, int* val){
  if(ififo_is_empty(fifo))
    return -1;
  
  struct ififo_node_s* head;

  head = fifo->head;

  *val = head->val;

  fifo->head = head->next;
  
  free(head);
  return 0;
}

int ififo_head(const struct ififo_s* fifo){
  return fifo->head->val;
}

void ififo_apply(struct ififo_s *fifo, func_t *fn){
  struct ififo_node_s* node;

  node = fifo->head;
  while(node->next!=NULL){
    node->val = fn(node->val);
    node = node->next;
  }

}

void ififo_del(struct ififo_s* fifo){
  int buff;

  while(!ififo_is_empty(fifo))
    ififo_dequeue(fifo, &buff);

  free(fifo);
}

