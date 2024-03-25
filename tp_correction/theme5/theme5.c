#include <stdio.h>
#include <stdlib.h>

// #define EX_ENV // l14
// #define EX_DICHO // l78
// #define EX_MEMCPY // l113
// #define EX_MEM_SWAP // l 158
#define EX_FILTER // l 204





#ifdef EX_ENV

extern char **environ; 

int nvar(){
  int n=0;
  char **envp = environ;

  while(*envp++ != NULL){
    n++;
  }

  return n;
}

void printenv(){
  char **envp = environ;

  while(*envp != NULL){
    printf("%s\n", *envp);
    envp++;
  }
}

int comp_variable_name(char* name, char* env_line){

  while(*name != '\0'){
    if(*name != *env_line)
      return 0;
    name++;
    env_line++;
  }
  
  if(*env_line != '=')
    return 0;
  return 1;
}


void mprintenv(int argc, char* argv[]){
  char **envp = environ;

  while(*envp != NULL){
    for(int i=0; i<argc; i++){
      if(comp_variable_name(argv[i], *envp)){
        printf("%s\n", *envp);
        break;
      }
    }
    envp++;
  }

}

int main(int argc, char** argv){
  printf("%d\n", nvar());
  //printenv();
  
  mprintenv(argc, argv);

  return 0;
}
#endif

#ifdef EX_DICHO

const float* search_interval(float v, const float *tab, const float *end){

  const float* med;

  if(end<tab) // tableau vide
    return NULL;

  med = tab + (end-tab)/2; //(tab + len(tab)/2)

  if(*med == v)
    return med;
  else if(v < *med)
    return search_interval(v, tab, med-1);
  else
    return search_interval(v, med+1, end);
}

int main(){

  float tab1[10] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  float tab2[4] = {0.5, 1.6, 2.7, 3.8};
  
  const float* res1 = search_interval(9.8, tab1, &tab1[9]);
  const float* res2 = search_interval(4.4, tab1, &tab1[9]);
  const float* res3 =search_interval(0.5, tab2, &tab2[3]);

  printf("%p\n", res1);
  printf("%p\t%f\n", res2, *res2);
  printf("%p\t%f\n", res3, *res3);
}

#endif

#ifdef EX_MEMCPY

#define SIZE 1021
#include <assert.h>
#include <string.h>

void mmemcpy(void* to, const void* from, unsigned int size){

  char* char_to = (char *)to;
  char* char_from = (char *)from;

  for(unsigned int i=0; i<size; i++)
    char_to[i] = char_from[i];
}
   
void test_mmemcpy()
{
   char     tc_orig[SIZE], tc_dest[SIZE];
   long int ti_orig[SIZE], ti_dest[SIZE];
   int i;

   /* initialisation */
   for(i=0 ; i<SIZE ; i++) {
       tc_orig[i] = rand() % 256;
       tc_dest[i] = rand() % 256;
       ti_orig[i] = rand(); 
       ti_dest[i] = rand();
   }

   /* copie */
   mmemcpy(tc_dest, tc_orig, SIZE);
   mmemcpy(ti_dest, ti_orig, SIZE * sizeof(long int));

   /* vérification */
   assert(memcmp(tc_orig, tc_dest, SIZE) == 0); 
   assert(memcmp(ti_orig, ti_dest, SIZE * sizeof(long int)) == 0);
}

int main(){
  test_mmemcpy();
  printf("Tout est ok\n");
}

#endif

#ifdef EX_MEM_SWAP
  
void memswap(void* a, void* b, unsigned int size){
  char* char_a = (char*)a;
  char* char_b = (char*)b;
  char buf;

  for(unsigned int i=0; i<size; i++){
    buf = char_a[i];
    char_a[i] = char_b[i];
    char_b[i] = buf;
  }
}

int main(){
  int tab1[5] = {1, 2, 3, 4, 5};
  int tab2[5] = {11, 12, 13, 14, 15};

  printf("-----Avant swap----\n");
  printf("tab1 = [");
  for(int i=0; i<5; i++)
      printf("%d ", tab1[i]);
  printf("]\n");
  
  printf("tab2 = [");
  for(int i=0; i<5; i++)
      printf("%d ", tab2[i]);
  printf("]\n");
  
  memswap(tab1, tab2, 5*sizeof(int));

  printf("-----Avant swap----\n");
  printf("tab1 = [");
  for(int i=0; i<5; i++)
      printf("%d ", tab1[i]);
  printf("]\n");
  
  printf("tab2 = [");
  for(int i=0; i<5; i++)
      printf("%d ", tab2[i]);
  printf("]\n");
  
  return 0;
}
#endif

#ifdef EX_FILTER

typedef int(func_t)(int);

int even(int a){
  if(a%2==0)
    return 1;
  else
    return 0;
}

int filter_int(int* arg, int* res, unsigned int size, func_t* f){
  int j=0;
  for(unsigned int i=0; i<size; i++){
    if(f(arg[i]) != 0){
      res[j] = arg[i];
      j++;
    }
  }

  return j;
}

int main(){

  int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int tab_filt[10];

  int n = filter_int(tab, tab_filt, 10, even);

  for(int i=0; i<n; i++){
    printf("%d ", tab_filt[i]);
  }
  printf("\n");

  return 0;
}

#endif
