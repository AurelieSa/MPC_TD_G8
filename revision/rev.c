#include <stdio.h>
#include <stdlib.h>

// #define EX1
// #define EX2
#define EX3

#ifdef EX1

int main(void){
  int a[8] = {5, 15, 34, 54, 14, 2, 52, 72};
  int* p;
  int* q;
  int** r;

  p = &(a[1]);
  q = &(a[5]);
  r = &p;

  printf("%d\n", *p);

  *p=42;

  printf("%d\n", *p);

  printf("*(p+3) = %d, a[4] = %d\n", *(p+3), a[4]);

  printf("q-p = %ld\n", q-p);
  
  printf("p < q = %d\n", p<q);

  printf("q = %p - a+5 = %p\n", q, a+5);
  
  printf("&p = %p - r = %p\n", &p, r);
  
  *r = NULL;

  printf("p = %p\n", p);

  return 0;
}

#endif

#ifdef EX2

void get(void* tab, int elem_size, int idx, void* dst){
  
  char* tab_char = (char *)tab;
  char* dst_char = (char *)dst;

  tab_char += idx*elem_size;

  for(int i=0; i<elem_size; i++)
    dst_char[i] = tab_char[i];

}

int main() {
  int tab[3] = {42, 51, 53};
  int v;

  get(tab, sizeof(int), 1, &v);

  printf("v = %d - tab[1] = %d\n", v, tab[1]);

  //printf("%ld\n", sizeof(void*));

  return 0;
}
#endif

#ifdef EX3

struct noeud_s {
  int val;
  struct noeud_s* next;
  struct noeud_s* prev;
};

struct liste_s {
  struct noeud_s* first;
  struct noeud_s* last;
};

int is_empty(struct liste_s* list){
  return list->first==NULL && list->last==NULL;
}

void init(struct liste_s* list){
  
  if(list==NULL)
    return;

  list->first = NULL;
  list->last = NULL;
}

struct noeud_s* ajout_debut(struct liste_s* list, int val){
  struct noeud_s* node;

  if(list==NULL)
    return NULL;

  node = malloc(sizeof(struct noeud_s));

  if(node==NULL)
    return NULL;

  node->val = val;
  node->next = list->first;
  node->prev = NULL;

  if(is_empty(list)){
    list->first = node;
    list->last = node;
  } else {
    list->first->prev = node;
    list->first = node;
  }

  return node;
}

void afficher_inverse(struct liste_s* liste){
  
  struct noeud_s* node;

  if(liste==NULL)
    return;

  if(is_empty(liste)){
    printf("empty lsit\n");
    return;
  }

  node = liste->last;

  while(node!=NULL){
    printf("%d\n", node->val);
    node = node->prev;
  }

  printf("\n");
}

void supprimer(struct liste_s* liste, struct noeud_s* noeud){
  
  noeud->prev->next = noeud->next;
  noeud->next->prev = noeud->prev;

  free(noeud);

}

int main(void){

  struct liste_s list;
  
  struct noeud_s* n1;
  struct noeud_s* n2;
  struct noeud_s* n3;
  struct noeud_s* n4;

  init(&list);

  printf("%d\n", is_empty(&list));
  
  n1 = ajout_debut(&list, 1);

  afficher_inverse(&list);

  n2 = ajout_debut(&list, 2);
  
  afficher_inverse(&list);

  n3 = ajout_debut(&list, 3);
  
  afficher_inverse(&list);

  n4 = ajout_debut(&list, 4);

  afficher_inverse(&list);

  supprimer(&list, n2); // on supprime un noeud au milieu
  
  afficher_inverse(&list);
  
  supprimer(&list, n1); // supp du dernier noeud

  afficher_inverse(&list);
  
  supprimer(&list, n4); // sup du premier noeud
  
  afficher_inverse(&list);
  
  supprimer(&list, n3);

  afficher_inverse(&list);
  return 0;
}

#endif
