
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define EX_COMPTEUR
#define EX_STRDUP

#ifdef EX_COMPTEUR

int compteur(){
  static int cpt = -1;

  cpt++;

  return cpt;
}

int main(void){
  for(int i=0; i<10; i++){
    printf("%d : %d\n", i, compteur());
  }

  return 0;
}

#endif

#ifdef EX_STRDUP

char* mstrdup(char* src){
  char* dest = malloc(strlen(src)*sizeof(char));
  char* dest_ptr =  dest;

  if(dest==NULL){
    return NULL;
  }

  while(*src!='\0'){
    *dest_ptr++ = *src++;
  }

  return dest;
}

int main(int argc, char** argv){

  for(int i=0; i<argc; i++){
    char* cpy;
    cpy = mstrdup(argv[i]);
    printf("%d : %s\n", i, cpy);
    free(cpy);
  }

  return 0;
}

#endif

