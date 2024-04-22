#include <stdio.h>

#define EX_DICHO

#ifdef EX_DIVISION
void division(int diviseur, int dividende, int* quotient, int* reste){
  *quotient = diviseur/dividende;
  *reste = diviseur%dividende;
}

int main(void){
  
  int a = 7;
  int b = 2;
  
  int q = 0;
  int r = 0;

  division(a, b, &q, &r);

  printf("%d = %d*%d+%d\n", a, q, b, r);

  return 0;
}
#endif

#ifdef EX_SKIP

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

char* skip_spaces(char* s){
  int i=0;
  while(s[i]==' ' && s[i]!='\0')
    i++;

  return &s[i];
}

int main_2(void){
  
  char* phrase1 = "une phrase sans espace au debut";
  char* phrase2 = "                  une phrase avec des espaces au debut";
  char* phrase3 = "            ";

  char* res = NULL;

  res = skip_spaces(phrase1);
  printf("res = %p-%s|\n", res, res);

  res = skip_spaces(phrase2);
  printf("res = %p-%s|\n", res, res);

  res = skip_spaces(phrase3);
  printf("res = %p-%s|\n", res, res);

  return 0;
}


int
main(int argc, char *argv[])
{
    char * strip;
    int i; 
    assert(argc == 2);

    printf("argv  : %s\n", argv[1]);
    strip = skip_spaces(argv[1]);
    printf("strip : %s\n", strip);

    for (i=0 ; strip[i]; i++)
        strip[i] = toupper(strip[i]);

    printf("strip : %s\n", strip);
    printf("argv  : %s\n", argv[1]);
    
    exit(EXIT_SUCCESS);
}

#endif

#ifdef EX_SWAP_PTR
void swap_ptr(int** a, int** b){
  int* buf = *a;
  *a = *b;
  *b = buf;
}

int main(void){
  int a = 42;
  int b = 24;

  int* ptr_a = &a;
  int* ptr_b = &b;

  printf("Avant swap : ptr_a = %p *ptr_a = %d, ptr_b = %p *ptr_b = %d\n", ptr_a, *ptr_a, ptr_b, *ptr_b);
  
  swap_ptr(&ptr_a, &ptr_b);

  printf("Apres swap : ptr_a = %p *ptr_a = %d, ptr_b = %p *ptr_b = %d\n", ptr_a, *ptr_a, ptr_b, *ptr_b);

  return 0;
}
#endif

#ifdef EX_DICHO

int g;

float* search_dicho(float* tab, int size, float v){
  
  if(size == 0)
      return NULL;
  
  int mid = size/2;

  if(tab[mid] == v)
    return &tab[mid];
  else if(tab[mid] < v)
      return search_dicho(&tab[mid+1], size-mid-1, v);
  else
      return search_dicho(tab, mid, v);
}

int main(void){

  float tab[10] = {1.0, 1.5, 2.2, 3.4, 5.5, 6.654, 6.655, 8.8, 8.9, 9.7};

  float* res = NULL;

  res = search_dicho(tab, 10, 5.5);
  printf("res = %p, *res=%f\n", res, *res);

  res = search_dicho(tab, 10, 1.0);
  printf("res = %p\n", res);

  return 0;
}

#endif

