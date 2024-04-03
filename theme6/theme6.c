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

// void foo(){
//   static int a = 0;
//   a++;
//   printf("%d\n", a);
// }

// void goo(){
//   static int a = 0;
//   a++;
//   printf("\t%d\n", a);
// }

// int main(){
//   
//   foo();
//   foo();
//   goo();
//   goo();
//   return 0;
// }
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

  g++; s++; l++;
  printf("main > g, s, l %d %d %d\n", g, s, l);

  return 0;
}

#endif

#ifdef EX_TEMP_NAME

char* temproray_name(void) {
  static int i = -1;

  i++;
  
  if(i==100)
    i=0;

  // char name[7];

  char* name = malloc(7*sizeof(char));

  if(name==NULL)
    return NULL;

  name[0] = 't';
  name[1] = 'e';
  name[2] = 'm';
  name[3] = 'p';
  name[4] = '0'+(i/10);
  name[5] = '0'+(i%10);
  name[6] = '\0';

  return name;
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
  int tab[10];

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
  struct point_s* point;

  point = malloc(sizeof(struct point_s));
  
  if(point==NULL)
    return NULL;

  point->p_x = x;
  point->p_y = y;

  return point;
}

void free_point(struct point_s* p){
  free(p);
}

int main(){

  struct point_s* point;

  point = new_point(-1, 2);

  printf("point->p_x = %d\npoint->p_y = %d\n", point->p_x, point->p_y);
  
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
  
  struct etudiant_s* etu;
  
  etu = malloc(sizeof(struct etudiant_s));

  if(etu==NULL)
    return NULL;
  
  etu->etu_nom = malloc(strlen(nom)*sizeof(char));
  
  if(etu->etu_nom==NULL){
    free(etu);
    return NULL;
  }

  etu->etu_prenom = malloc(strlen(prenom)*sizeof(char));
  
  if(etu->etu_prenom==NULL){
    free(etu->etu_nom);
    free(etu);
    return NULL;
  }

  strcpy(etu->etu_nom, nom);
  strcpy(etu->etu_prenom, prenom);

  etu->etu_no_etudiant = no_etudiant;

  return etu;
}


void free_etudiant(struct etudiant_s* etu){
  
  free(etu->etu_nom);
  free(etu->etu_prenom);
  free(etu);
}

int main(){

  struct etudiant_s* etu;

  etu = new_etudiant("saulquin", "aureliiiie", 123456);

  printf("Nom : %s\nPrenom : %s\nNumero etudiant : %d\n", etu->etu_nom, etu->etu_prenom, etu->etu_no_etudiant);
  
  free_etudiant(etu);
}

#endif
