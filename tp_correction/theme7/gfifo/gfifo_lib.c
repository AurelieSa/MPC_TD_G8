#include <stdio.h>
#include <stdlib.h>
#include "gfifo_lib.h"

struct gfifo_s* gfifo_new(void) {
  struct gfifo_s* fifo;

  fifo = malloc(sizeof(struct gfifo_s));
  
  if(fifo==NULL)
    return NULL;

  fifo->head = NULL;
  fifo->tail = NULL;
  
  return fifo;
}

int gfifo_is_empty(struct gfifo_s* fifo){
  return fifo->head == NULL;
}

int gfifo_enqueue(struct gfifo_s* fifo, void* val){
  struct gfifo_node_s* new_node;

  new_node = malloc(sizeof(struct gfifo_node_s));

  if(new_node==NULL)
    return -1;
  
  new_node->val = val;

  if(gfifo_is_empty(fifo)){
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

int gfifo_dequeue(struct gfifo_s* fifo, void** val){
  
  if(gfifo_is_empty(fifo))
    return -1;
  
  struct gfifo_node_s* head;
  
  head = fifo->head;

  *val = head->val;

  fifo->head = head->next;
  
  free(head);
  return 0;
}

void* gfifo_head(const struct gfifo_s* fifo){
  return fifo->head->val;
}

void gfifo_apply(struct gfifo_s *fifo, gfunc_t *fn){
  struct gfifo_node_s* node;

  node = fifo->head;
  while(node->next!=NULL){
    fn(node->val);
    node = node->next;
  }

}

void gfifo_del(struct gfifo_s* fifo){
  void* buff;

  while(!gfifo_is_empty(fifo))
    gfifo_dequeue(fifo, &buff);

  free(fifo);
}

int gfifo_size(struct gfifo_s* fifo){
  
  struct gfifo_node_s* node;
  int size = 0;

  node = fifo->head;
  
  if(node==NULL)
    return 0;

  while(node->next!=NULL){
    node = node->next;
    size++;
  }

  return size+1;

}

