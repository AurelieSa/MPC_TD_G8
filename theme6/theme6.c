#include <stdio.h>
#include <stdlib.h>

// #define EX_ALLOC_AFF_1
// #define EX_ALLOC_AFF_2
// #define EX_TEMP_NAME
// #define EX_TAB
// #define EX_POINT
#define EX_ETU

#ifdef EX_ALLOC_AFF_1

int var = 42;

void f(int var) {
  printf("f > var %d\n", var);
  var = 271;
}

void g(int arg){
  printf("g > arg %d\n", arg);
  printf("g > var %d\n", var);
  var = 141;
}

int main(){
  int var;

  var = 341;

  f(var);
  g(var);
  f(var);
  g(var);

  printf("main > var %d\n", var);

  return 0;
}

#endif


#ifdef EX_ALLOC_AFF_2

static int g = 42;

void f(int a){
  static int s = 314;
  int l  = 141;

  printf("f > a %d\n", a);
  g++;
  s++;
  l++;

  printf("f > g, s, l %d, %d, %d\n", g, s, l);

  if(a>10)
    f(a/10);

  printf("f > a %d\n", a);

}

int main(){
  static int s = 314;
  int l = 141;

  f(l);

  printf("main > g, s, l %d %d %d\n", g, s, l);

  return 0;
}

#endif

#ifdef EX_TEMP_NAME

char* temproray_name(void) {
  // a faire en live
}

int main(){
    
  printf("%s\n", temproray_name());

  for(int i=0; i<100; i++){
    printf("%d %s\n", i, temproray_name());
  }

  return 0;
}

#endif

#ifdef EX_TAB

int* creer_sequence_10(void){
  int t[10];
  for(int i=0; i<10; i++)
    t[i] = i;

  return t;
}

int main(void){
  int *tab;
  
  tab = creer_sequence_10();

  for(int i=0; i<10; i++)
    printf("tab[%d] = %d\n", i, tab[i]);

  return 0;
}

#endif

#ifdef EX_POINT

struct point_s {
  int p_x;
  int p_y;
};

struct point_s* new_point(int x, int y){
  // a faire en live
  
}

void free_point(struct point_s* p){
  // a faire en live

}

int main(){

  struct point_s* point;

  point = new_point(-1, 2);

  printf("point.p_x = %d\npoint.p_y = %d\n", ..., ...);
  
  free_point(point);

  return 0;
}

#endif

#ifdef EX_ETU

#include  <string.h>

struct etudiant_s {
  char* etu_nom;
  char* etu_prenom;
  int etu_no_etudiant;
};

struct etudiant_s* new_etudiant(const char* nom, const char* prenom, int no_etudiant){
  // a faire en live
  struct etudiant_s* etu;

  return etu;
}


void free_etudiant(struct etudiant_s* etu){
  
}

int main(){

  struct etudiant_s* etu;

  etu = new_etudiant("saulquin", "aureliiiie", 123456);

  printf("Nom : %s\nPrenom : %s\nNumero etudiant : %d\n", etu->etu_nom, etu->etu_prenom, etu->etu_no_etudiant);
  
  free_etudiant(etu);
}

#endif
