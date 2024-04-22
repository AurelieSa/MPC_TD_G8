_thème 5_ — Arithmétique des pointeurs
======================================

> [Université de Lille](https://www.univ-lille.fr/)  
> [Licence d'informatique, 2e année](https://portail.fil.univ-lille1.fr/ls4)  
> [Module de MPC — Maîtrise de la Programmation en C](https://portail.fil.univ-lille1.fr/ls4/mpc)  
> Équipe pédagogique de MPC, d'après un document CC BY-SA de Gilles
    Grimaud Philippe Marquet, 2018-2020.  
> mars 2021  
> [CC BY-SA](https://creativecommons.org/licenses/by-sa/4.0/)

Une version PDF pour impression est accessible sur [nextcloud.univ-lille.fr](https://nextcloud.univ-lille.fr/index.php/s/zrWxCeBefzewJWH)

Ce document est le support d'exercices de TD et TP.

Le thème 5 traite de l'arithmétique des pointeurs, de l'équivalence
tableaux/pointeurs, de la possible généricité des pointeurs `void *`,
de la représentation des tableaux à plusieurs dimensions, et enfin des
pointeurs de fonctions.

→ Adresses et arithmétique de pointeurs
---------------------------------------

### Adresses mémoires des types construits — _exercice de TD_ ###

Soit le programme `tab_duo_trio.c` suivant

```c
 #include <stdlib.h>
 #include <stdio.h>
 
 struct duo_s {
     int x;
     int y;
 };
 
 union trio_u {
     int n;
     char c;
     float x;
 };
 
 int
 main()
 {
     int tab[10];
     struct duo_s duo;
     union trio_u trio;
 
     printf("sizeof(int) : %lu\n", sizeof(int));
     printf("tab :\t%p\n", tab);
     printf("&duo :\t%p\n", &duo);
     printf("&trio :\t%p\n", &trio);
 
     exit(EXIT_SUCCESS);
 }
```

dont une exécution produit :

```console
% ./tab_duo_trio
sizeof(int) : 4
tab :   0x7ffeebe6a6d0
&duo :  0x7ffeebe6a6c8
&trio : 0x7ffeebe6a6c0
```

1. Quelle est l'adresse du champ `duo.x` ? `duo.y` ?

2. Quelle est l'adresse du champ `trio.n` ? `trio.c` ? `trio.x` ?

3. Quelles sont les valeurs des expressions suivantes

    * `&trio.n + 1`
	* `&trio.c + 1`

4. Quelle est l'adresse de l'élément `tab[5]` du tableau ?   
   De manière générale, quelle est l'adresse de l'élément `tab[i]` ? 

5. Soit la déclaration et initialisation :

    ```c
    int *ptr;
    ptr = tab;
    ```

    En utilisant uniquement la variable `ptr`, et l'arithmétique des
    pointeurs, proposez une boucle qui va écrire la valeur `0` dans
    toutes les cases du tableau. 

### Pointeurs et chaînes de caractères — _exercice de TD_ ###

1. Écrire une fonction `char *strend(char *str)` qui renvoie
   l'adresse du zéro terminal de la chaîne `str`.

2. (Pourquoi le prototype de cette fonction ne peut-il être
   `char *strend(const char *str)` ?) 

3. En utilisant la fonction `strend()`, proposez une fonction qui
   renvoie le nombre de caractères d'une chaîne donnée - le caractère
   `'\0'` final non compris : 

    ```c
    int mstrlen(char *str);
    ```

    _Pour information_. Cette fonction `mstrlen()` est similaire à la
    fonction `strlen()` fournie par la bibliothèque standard
    `string.h`.

4. La bibliothèque `string.h` fournie également les fonctions suivantes :

    ```c
    /* recopie le contenu de src dans dest 
       renvoie dest */
    char *strcpy(char *dest, const char *src); 
    
    /* recopie src à la fin de dest (concat) 
       renvoie dest */
    char *strcat(char *dest, const char *src);
    ```

    Proposez des fonctions `mstrcpy()` et `mstrcat()`, réécritures de
    ces fonctions. 

→ Pointeurs génériques `void *`
-------------------------------

### Mise à zéro — _exercice de TD_ ###

1. Proposez une fonction "générique" qui prend l'adresse d'un entier de
   type non spécifié, ainsi que sa taille, et met cet entier à zéro :

   ```c
   void memzero(void *addr, unsigned int size);
   ```

   Exemples d'utilisations de la fonction :

   ```c
   int a;
   short int b;
   memzero(&a, sizeof(int));            /* équivalent à a = 0 */
   memzero(&b, sizeof(short int));      /* équivalent à b = 0 */
   ```

2. Cette fonction peut-elle être utilisée pour mettre à zéro
   l'ensemble des valeurs d'un tableau, par exemple :

   ```c
   #define MAX    128
   int t[MAX];
   ```

_Pour information._ La bibliothèque `string.h` propose une fonction
`memset()` qui est généralement utilisée pour mettre à zéro une zone
mémoire donnée. 

### Comparaison générique — _exercice de TD_ ###

L'objet de l'exercice est de proposer une fonction `mmemcmp()` qui
compare deux zones mémoire octet par octet. 

1. Donnez un prototype possible pour cette fonction. 

2. Donnez une définition de cette fonction.  
   La fonction renverra une valeur nulle si et seulement si les deux
   zones sont égales.

_Pour information._ La bibliothèque `string.h` propose une fonction
`memcmp()` qui réalise une telle comparaison.

→ Tableaux à plusieurs dimensions
---------------------------------

### Arrangement mémoire des éléments d'un tableau à plusieurs dimensions — _exercice de TD_ ###

Soit la déclaration d'un tableau 

```c
int b[3][5];
```

En considérant que l'allocation du tableau se fait linéairement en
mémoire (les 3 "tranches" de `b` sont allouées à des adresses contiguës),
donnez l'état du tableau `b` après
l'exécution du code C suivant :

```c
int b[3][5];
int *a = *b, i;

for (i=0 ; i<15 ; *a++ = i++)
    ;
**b = 15;           **(b+1) = 16;        *(b[0]+1) = 17;
*(*b+8) = 18;       *(b[1]+2) = 19;      *(*(b+1)+5) = 20;
*(b[2]+3) = 21;     *(*(b+2)+2) = 22;
```

→ Pointeurs de fonction
-----------------------

### Appliquer une fonction à un tableau d'entiers — _exercice de TD_ ###

Soit `func_t` le type des fonctions à un paramètre entier qui
renvoient une valeur entière :

```c
typedef int (func_t)(int); 
```

L'objet de la fonction `map_int()` que nous allons écrire est
d'appliquer une fonction de type `func_t` à chacun des éléments d'un
tableau d'entiers.  
Le résultat sera produit dans autre tableau d'entiers.

1. Étant données cette fonction `map_int()` qui produit dans le tableau
   `res` l'application de la fonction `f` à chacun des `size` éléments
   du tableau `arg` : 

   ```c
   void map_int(const int arg[], int res[], unsigned int size, func_t *f);
   ```

   et les définitions suivantes : 

   ```c
   #define MAX      128

   int t[MAX], t2[MAX];
   
   int
   carre(int n)
   {
       return n*n;
   }
   ```

   En supposant le tableau `t` initialisé, donnez le code d'un appel
   à `map_int()` pour produire dans  `t2` les carrés des valeurs de
   `t`.

2. Proposez une définition de `map_int()`. 

### Map générique — _exercice de TD_ ###

La fonction `map_gen()` est une version générique de la fonction
`map_int()`, capable de traiter des tableaux de type quelconque.

Cette fonction `map_gen()` utilise une fonction de type `funcgen_t`
pour appliquer une opération sur chaque élément d'un tableau : 

```c
typedef void (funcgen_t)(const void*, void*); 
```

Le principe d'une telle fonction est de considérer son premier
paramètre comme une référence vers un argument, et renvoyer son
résultat via le second paramètre. 

Le prototype de `map_gen()` est le suivant :

```c
void map_gen(const void *arg, void *res, unsigned int nbelem, unsigned int elemsize, funcgen_t *f);
```

Les paramètres `arg` et `res` sont des tableaux de `nbelem` élements,
chaque éléments occupe `elemsize` octets.  
La fonction produit la valeur `f(arg[i])` dans l'élément `i` du
tableau `res`. 

1. Soient les définitions suivantes : 

   ```c
   #define MAX      128

   int t[MAX], t2[MAX];
   
   void
   carre_int_v1(const void *src, void *dst)
   {
       int* src_int = (int*) src;
       int* dst_int = (int*) dst;
       *dst_int = *src_int * *src_int;
   }
   ```

   En supposant le tableau `t` initialisé, donnez le code d'un appel
   à `map_gen()` pour produire dans  `t2` les carrés des valeurs de
   `t`.

2. Faites de même en utilisant maintenant la fonction suivante :

   ```c
   void
   carre_int_v2(const int *src, int *dst)
   {
       *dst = *src * *src;
   }
   ```

3. Donnez la définition de fonctions et le code permettant de produire
   un tableaux des carrés de valeur de type `float`. 

4. Proposez une définition de la fonction `map_gen()`.

...
---

_suite à venir..._
<!-- eof --> 
