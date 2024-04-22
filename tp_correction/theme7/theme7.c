#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "./ififo/ififo_lib.h"
#include "./gfifo/gfifo_lib.h"

int print_int(int i) {
  printf("%d ", i);
  return i;
}

void test_fifo_int() {
    struct ififo_s *fifo;
    int i;

    fifo = ififo_new();

    ififo_enqueue(fifo, 12);   /* → 12 → */
    ififo_enqueue(fifo, 13);   /* → 13 → 12 → */

    ififo_apply(fifo, print_int); putchar('\n');
    
    ififo_enqueue(fifo, 14);   /* → 14 → 13 → 12 → */
    ififo_dequeue(fifo, &i);   /* 12 & → 14 → 13 → */

    printf("i = %d \n", i);
    ififo_apply(fifo, print_int); putchar('\n');
  
    ififo_dequeue(fifo, &i);   /* 13 & → 14 → */
    ififo_dequeue(fifo, &i);   /* 14 & → → */
    ififo_apply(fifo, print_int); putchar('\n');
  
    ififo_del(fifo);
}

struct ififo_s* ififo_merge(struct ififo_s* fifo1, struct ififo_s* fifo2){
  
  struct ififo_s* merged_fifo = ififo_new();
  
  if(merged_fifo == NULL)
    return NULL;

  int buff;

  while(!ififo_is_empty(fifo1) || !ififo_is_empty(fifo2)){
    if(ififo_is_empty(fifo1)){ // queue 1 deja vide -> on vide la queue 2
      ififo_dequeue(fifo2, &buff);
    } else if(ififo_is_empty(fifo2)) { // queue 2 deja vide -> on vide la queue 1
      ififo_dequeue(fifo1, &buff);
    } else { // aucune des queue n'est vide
      if(ififo_head(fifo1) > ififo_head(fifo2))
        ififo_dequeue(fifo1, &buff);
      else
        ififo_dequeue(fifo2, &buff);
    }
    ififo_enqueue(merged_fifo, buff);
  }
  return merged_fifo;
}

int fifo_sort(int* array, unsigned int size) {

  struct gfifo_s* fifo;
  
  fifo = gfifo_new();
  
  if(fifo==NULL)
    return -1;
  
  // fifo initiliazation
  for(unsigned int i=0; i<size; i++){
    struct ififo_s* fifo_node = ififo_new();

    if(fifo_node==NULL)
      return -1;

    ififo_enqueue(fifo_node, array[i]);
  
    gfifo_enqueue(fifo, (void *)fifo_node);
  }
  
  while(gfifo_size(fifo)>1){
  
    struct ififo_s* fifo_node_1 = ififo_new();
    struct ififo_s* fifo_node_2 = ififo_new();
    
    gfifo_dequeue(fifo, &fifo_node_1);

    gfifo_dequeue(fifo, &fifo_node_2);
    
    struct ififo_s* ififo_merged_node = ififo_merge(fifo_node_1, fifo_node_2);
    
    if(ififo_merged_node==NULL)
      return -1;
    
    gfifo_enqueue(fifo, (void *)ififo_merged_node);
  }
  
  struct ififo_s* final_fifo = ififo_new();

  gfifo_dequeue(fifo, &final_fifo);

  for(unsigned int i=0; i<size; i++){
    ififo_dequeue(final_fifo, &array[i]);
  }

  return 0;
}

int main(void){
  // test_fifo_int();
  // 
  // struct ififo_s* fifo1 = ififo_new();
  // struct ififo_s* fifo2 = ififo_new();

  // assert(fifo1!=NULL);
  // assert(fifo2!=NULL);

  // ififo_enqueue(fifo1, 1);
  // ififo_enqueue(fifo1, 3);
  // 
  // ififo_enqueue(fifo2, 2);
  // ififo_enqueue(fifo2, 5);

  // printf("%d\n", ififo_head(fifo2));
  // printf("%d\n", ififo_head(fifo1));

  // struct ififo_s* merge_fifo = ififo_merge(fifo1, fifo2);

  // assert(merge_fifo!=NULL);
  // 
  // ififo_apply(merge_fifo, print_int);
  // 
  // printf("\n");
  // printf("%d\n", ififo_is_empty(merge_fifo));
  
  int a[5] = {4, 3, 1, 5, 2};
  
  fifo_sort(a, 5);

  for(int i=0; i<5; i++)
    printf("%d ", a[i]);
  
  printf("\n");
  return 0;
}
