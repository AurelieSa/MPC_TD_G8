#include <stdio.h>
#include <stdlib.h>

#define EX_METTRE42 // l 11
// #define EX_INC // l 40
// #define EX_CHERHCER // l 59
// #define EX_MAIN // l 84
// #define EX_DOUBLE_POINTER // l 98


#ifdef EX_METTRE42
void mettre42(int *p){
  *p = 42;
}

void mettre42_bis(int n){
  n = 14;
}

int main(void){
  int n=1;
  int t[12];

  t[0] = 3;

  printf("Avant appelle: n=%d, t[3]=%d\n", n, t[3]);

  mettre42(&n);
  mettre42(&t[3]);
  // mettre42_bis(n);

  printf("Apres appelle : n=%d, t[3]=%d\n", n, t[3]);

  return 0;
}


#endif

#ifdef EX_INC
void inc(int *p){
  *p = *p + 1;
}

int main(void) {
  int n=0;

  printf("Avant inc : %d\n", n);

  inc(&n);

  printf("Apres inc : %d\n", n);

  return 0;
}
#endif


#ifdef EX_CHERHCER
int* chercher(int* tab, int tab_size, int v){
  for(int i=0; i<tab_size; i++){
    if(*(tab+i) == v){
      return &tab[i];
    }
  }
  
  return NULL;

}

int main(void){
  int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int* res = NULL;

  res = chercher(tab, 10, 4);
  printf("res = %p = %d\n", res, *res);

  res = chercher(tab, 10, 11);
  printf("res = %p\n", res);
}
#endif

#ifdef EX_MAIN

int main(int argc, char** argv){
  
  for(int i=0; i<argc; i++){
    printf("%s\n", argv[i]);
  }
  putchar('\n');

  exit(EXIT_SUCCESS);
}

#endif

#ifdef EX_DOUBLE_POINTER

int main(void){
  int n = 42;
  int* foo = &n;
  int truc = 0; // on définis truc pour que les variables ne se suivent pas
  int** bar = &foo;

  printf("n = %d\n", n);
  printf("foo = %p, *foo = %d\n", foo, *foo);
  printf("bar = %p, *bar = %p, **bar = %d\n", bar, *bar, **bar);

  return 0;
}
#endif

