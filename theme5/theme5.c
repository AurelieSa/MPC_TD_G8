#include <stdio.h>
#include <stdlib.h>

// #define EX_1     // l 14
// #define EX_1_TAB // l 64
// #define EX_2_STRLEN // l 101
// #define EX_2_CAT // l 154
// #define EX_2_CPY //l 197
// #define EX_MEM_SET  // l 233
#define EX_MATRIX // l286
// #define EX_MAP // l 322
// #define EX_MAP_GEN // l 362
// #define EX_MEM_CMP


#ifdef EX_1

struct duo_s {
  int x;
  int y;
};

union trio_u {
  int n;
  char c;
  float x;
};

int main(){
  int tab[10];
  struct duo_s duo;
  union trio_u trio;

  printf("sizeof(int) : %lu\n", sizeof(int));
  printf("sizeot(float) : %lu\n", sizeof(float));

  printf("tab :\t%p\n", tab);
  printf("&duo :\t%p\n", &duo);
  printf("&trio :\t%p\n", &trio);
  
  getchar();

  printf("&duo.x :\t%p\n", &duo.x);
  printf("$duo.y :\t%p\n", &duo.y);
  
  getchar();

  printf("&trio.n :\t%p\n", &trio.n);
  printf("&trio.c :\t%p\n", &trio.c);
  printf("&trio.x :\t%p\n", &trio.x);

  getchar();

  printf("&trio.n+1 :\t%p\n", &trio.n+1);
  printf("&trio.c+1 :\t%p\n", &trio.c+1);
  
  getchar();
  printf("&tab[5] :\t%p\n", &tab[5]);
  printf("tab+5 :\t%p\n", tab+5);

  return 0;
}

#endif

#ifdef EX_1_TAB

int main() {
  int tab[10];
  
  // on remplit le tableau de 100 
  for(int i=0; i<10; i++){
    tab[i] = 100;
  }

  // on affiche le tableau
  printf("Tableau avant la mise a 0\n");
  for(int i=0; i<10; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");

  int *ptr;
  ptr = &tab[0];

  for(int i=0; i<10; i++){
    *(ptr+i) = 0;
    // on peut aussi faire ptr[i] = 0
  }

  // on réaffiche le tableau
  printf("\nTableau après la mise a 0\n");
  for(int i=0; i<10; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");

  return 0;
}

#endif

#ifdef EX_2_STRLEN

char* strend_v1(char* str){
  while(*str != '\0'){
    str++;
  }

  return str;
}

char* strend_v2(char* str){
  while(*str){
    str++;
  }

  return str;
}

char* strend_v3(char* str){
  while(*str++)
    ;
  return str-1;
}

int mstrlen(char *str){
  return (int)(strend_v1(str)-str)/sizeof(char);
}

int main(){

  char* str_test_1 = "coucou";
  char* str_test_2 = "";
  
  printf("len of str_test_1 : %d\n", mstrlen(str_test_1));
  printf("len of str_test_2 : %d\n", mstrlen(str_test_2));
  
  printf("\n\n");

  printf("strend_v1(str_test_1) :\t%p\t%p\n", str_test_1, strend_v1(str_test_1));
  printf("strend_v2(str_test_1) :\t%p\t%p\n", str_test_1, strend_v2(str_test_1));
  printf("strend_v3(str_test_1) :\t%p\t%p\n", str_test_1, strend_v3(str_test_1));

  printf("\n\n");

  printf("strend_v1(str_test_2) :\t%p\t%p\n", str_test_2, strend_v1(str_test_2));
  printf("strend_v2(str_test_2) :\t%p\t%p\n", str_test_2, strend_v2(str_test_2));
  printf("strend_v3(str_test_2) :\t%p\t%p\n", str_test_2, strend_v3(str_test_2));
 
  return 0;
}

#endif

#ifdef EX_2_CAT

char * mstrcat(char* dest, char* src){
  
  // on se met à la fin de dest
  while(*dest != '\0')
    dest++;

  //while((*dest++ = *src++) != '\0');
  while(*src != '\0'){
    *dest = *src;
    dest++;
    src++;
  }

  return dest;
}

int main(void){
  
  char str_test_1[] = "abcdef";
  char str_test_2[] = "123456";
  char str_test_3[] = "xyz";
  

  printf("----Avant mstrcat------\n");
  printf("str_test_1 :\t%p\t%s\n", str_test_1, str_test_1);
  printf("str_test_2 :\t%p\t%s\n", str_test_2, str_test_2);
  printf("str_test_3 :\t%p\t%s\n", str_test_3, str_test_3);

  mstrcat(str_test_1, str_test_3);

  printf("----Apres mstrcat------\n");
  printf("str_test_1 :\t%s\n", str_test_1);
  printf("str_test_2 :\t%s\n", str_test_2);
  printf("str_test_3 :\t%s\n", str_test_3);
  
  return 0;
}
 
#endif

#ifdef EX_2_CPY

char * mstrcpy(char* dest, const char* src){
  while(*src != '\0'){
    (*dest) = (*src);
    dest++;
    src++;
  }

  return dest;
}

int main(void){
  
  char str_test_1[] = "abcdef";
  char str_test_2[] = "123456";
  char str_test_3[] = "xyz";
  

  printf("----Avant mstrcpy------\n");
  printf("str_test_1 :\t%p\t%s\n", str_test_1, str_test_1);
  printf("str_test_2 :\t%p\t%s\n", str_test_2, str_test_2);
  printf("str_test_3 :\t%p\t%s\n", str_test_3, str_test_3);

  mstrcpy(str_test_2, str_test_1);

  printf("----Apres mstrcpy------\n");
  printf("str_test_1 :\t%s\n", str_test_1);
  printf("str_test_2 :\t%s\n", str_test_2);
  printf("str_test_3 :\t%s\n", str_test_3);
  
  mstrcpy(str_test_3, str_test_1);
  printf("----Apres mstrcpy------\n");
  printf("str_test_1 :\t%s\n", str_test_1);
  printf("str_test_2 :\t%s\n", str_test_2);
  printf("str_test_3 :\t%s\n", str_test_3);
  
  return 0;
}

#endif

#ifdef EX_MEM_SET 

void memzero(void* addr, unsigned int size){
  int i=0;
  char *ptr;

  for(i=0, ptr=addr; i<size; i++, ptr++){
    *ptr = 0;
  }

}

int main(){

  int tab1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  char tab2[5] = {10, 11, 12, 13, 14};
  short int a = 0x4242;

  printf("---Avant memzero---\n");
  printf("tab1 : [");
  for(int i=0; i<10; i++)
    printf("%d ", tab1[i]);
  printf("]\n");
  
  printf("tab2 : [");
  for(int i=0; i<5; i++)
    printf("%d ", tab2[i]);
  printf("]\n");
  
  printf("a : %x\n", a);

  memzero(tab1, 10*sizeof(int));
  memzero(tab2, 5*sizeof(char));
  memzero(&a, sizeof(short int));

  printf("---Apres memzero---\n");
  printf("tab1 : [");
  for(int i=0; i<10; i++)
    printf("%d ", tab1[i]);
  printf("]\n");
  
  printf("tab2 : [");
  for(int i=0; i<5; i++)
    printf("%d ", tab2[i]);
  printf("]\n");

  printf("a : %x\n", a);

  return 0;
}

#endif

#ifdef EX_MATRIX

void print_tab(unsigned int n_row, unsigned int n_col, int tab[n_row][n_col]){
  for(unsigned int i=0; i<n_row; i++){
    for(unsigned int j=0; j<n_col; j++)
      printf("tab[%d][%d] : \t %d \t\t %p\n ",i, j, tab[i][j], &tab[i][j]);
  }
}

int main(){
  
  int b[3][5];
  int* a = *b;
  int i;
  
  printf("adresse b = %p\n", b);
  printf("a = %p\n", a);
  
  printf("\n\n\n");

  print_tab(3, 5, b);

  printf("\n\n\n");
  
  getchar();

  for(i=0; i<15; *a++ = i++)
    ;

  print_tab(3, 5, b);

  printf("\n\n\n");

  getchar();

  **b = 15;           
  **(b+1) = 16;        
  *(b[0]+1) = 17;
  *(*b+8) = 18;       
  *(b[1]+2) = 19;      
  *(*(b+1)+5) = 20;
  *(b[2]+3) = 21;     
  *(*(b+2)+2) = 22;
  
  print_tab(3, 5, b);
  return 0;
}

#endif

#ifdef EX_MAP

typedef int (func_t)(int);
typedef void(func_gen_t)(const void*, void*);

int carre(int n){
  return n*n;
}

void carre_gen(const int* n, int* res){
  *res = *n * *n;
}

void map_int(const int arg[], int res[], unsigned int size, func_t *f){
  for(int i=0; i<size; i++){
    res[i] = f(arg[i]);
  }
}

void map_gen(const void* arg, void* res, unsigned int nb_elem, unsigned int elem_size, func_gen_t *f){
  for(int i=0; i<nb_elem; i++){
    f(&arg[i], &res[i]);
    arg = elem_size + (char *) arg; 
    res = elem_size + (char *) res;
  }
}

int main(){
  int tab1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int tab2[10];

  map_int(tab1, tab2, 10, carre);

  for(int i=0; i<10; i++)
    printf("%d * %d = %d\n", tab1[i], tab1[i], tab2[i]);

  return 0;
}
#endif

#ifdef EX_MAP_GEN

typedef void(func_gen_t)(const void*, void*);

void carre_gen(const void* n, void* res){
  int* n_int = (int*)n;
  int* res_int = (int*)res;
  *res_int = *n_int * *n_int;
}

void map_gen(const void* arg, void* res, unsigned int nb_elem, unsigned int elem_size, func_gen_t *f){
  for(unsigned int i=0; i<nb_elem; i++){
    f(arg, res);
    arg = elem_size + (char *) arg; 
    res = elem_size + (char *) res;
  }
}

int main(){
  short int tab1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  short int tab2[10];

  map_gen(tab1, tab2, 10, sizeof(short int), carre_gen);

  for(int i=0; i<10; i++)
    printf("%d * %d = %d\n", tab1[i], tab1[i], tab2[i]);

  return 0;
}
#endif

#ifdef EX_MEM_CMP

void* mmemcmp(void* addr1, void* addr2, unsigned int size){
  char* ptr1 = (char *)addr1;
  char* ptr2 = (char *)addr2;
  
  for(int i=0; i<size; i++){
    if(*ptr1 != *ptr2)
      return (void *)ptr1;
    ptr1++;
    ptr2++;
  }

  return NULL;

}

int main(void){
  char tab[2] = {1, 2};
  char tab2[2] = {3, 4};
  short int v = 0x0201;

  printf("tab = tab2? : %p\n", mmemcmp(tab, tab2, 2));
  printf("tab = v? : %p\n", mmemcmp(tab, &v, 2));
}

#endif
