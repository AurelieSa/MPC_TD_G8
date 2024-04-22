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

### Autour des variables d'environnement – _exercice de TP_ ###

La variable globale

```c
extern char **environ;
```

est un pointeur sur le premier élément d'un tableau.  
Chacun des éléments de ce tableau est une chaîne de caractères, donc
un pointeur `char *`.  
Une valeur `(char *) 0` indique la fin du tableau.

Chacune des chaînes est de la forme `"VAR=valeur"`, `VAR` correspondant
à une des variables d'environnement. Cette variable `environ` est par
exemple exploitée par la commande Unix `printenv` qui affiche
l'ensemble des variables d'environnement et leur valeur :

```console
% printenv | head
SHELL=/bin/bash
LANGUAGE=en_US:
PWD=/home/l2/duchmol
LOGNAME=duchmol
HOME=/home/l2/duchmol
LANG=en_US.UTF-8
TERM=xterm-256color
USER=duchmol
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
SSH_TTY=/dev/pts/0
```

1. Proposez une fonction `nvar()` qui exploite cette variable
   `environ` et renvoie le nombre de variables d'environnement
   définies.

    Proposez un programme qui fait appel à cette fonction et affiche
    ce nombre de variables. 

    On pourra comparer le résultat avec celui fourni par la commande 

    ```console
    % printenv | wc -l
    ```

2. Proposez une commande `mprintenv` qui reproduit le comportement de
   `printenv`.

3. La commande `printenv` admet des paramètres qu'elle considère comme
   des noms de variables d'environnement donc elle affiche la valeur :
   
    ```console
    % printenv USER SHELL
    duchmol
    /bin/bash
    ```

    Proposez une nouvelle version de votre commande `mprintenv` pour
    inclure cette fonctionnalité.

### Nouvelle recherche dichotomique — _exercice de TP_ ###

1. Proposez une fonction récursive qui recherche par dichotomie une
   valeur `v` dans un tableau trié `tab` : 

    ```c
    float * search_interval(float v, float *tab, float *end);
    ```

    L'argument `end` pointe sur le dernier élément du tableau.

2. On pourra reprendre le programme principal utilisé pour la fonction
   `search_dicho()` du TP précédent, _thème 4_ pour valider cette
   nouvelle fonction de recherche.

→ Pointeurs génériques `void *`
-------------------------------

### Copie générique — _exercice de TP_ ###

1. Proposez une fonction qui copie un objet d'adresse `from`, de type
   non spécifié, et de taille `size`, à l'adresse `to` :

   ```c
   void mmemcpy(void *to, const void *from, unsigned int size);
   ```
   
2. Testez votre proposition, par exemple avec le code suivant

   ```c
   #include <stdlib.h>             /* pour rand() */
   #include <string.h>             /* pour memcmp() */
   #include <assert.h>             /* pour assert() */
   
   #define SIZE    1021
   
   void
   test_mmemcpy()
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
   ```

_Pour information._ La bibliothèque `string.h` propose une fonction
`memcpy()` qui réalise une telle copie.

### Échange générique — _exercice de TP_ ###

1. Proposez une fonction `memswap()` qui réalise un échange générique
   entre deux variables de même taille.  
   Dans un premier temps, on pourra supposer que les deux objets ne se
   recouvrent pas en mémoire. 

2. Testez votre proposition avec une fonction semblable à celle
   proposée pour l'exercice précédent.

### Filtrer les éléments d'un tableau d'entiers — _exercice de TP_ ###

Étant donnée une fonction `f` à un paramètre entier qui renvoie une
valeur entière, la fonction `filter_int()` recopie certains éléments
d'un tableau d'entiers source dans un tableau d'entiers destination.  
Les éléments `e` recopiés sont ceux pour lesquels `f(e)` est non nul.  
La fonction renvoie le nombre d'éléments copiés.

1. Proposez un prototype de la fonction `filter_int()`.

2. Proposez une définition de la fonction `filter_int()`.

3. Proposez un programme de test qui utilise `filter_int()`pour
   recopier uniquement les entiers pairs d'un tableau tableau source
   vers un tableau destination. 
→ Pointeurs de fonction
-----------------------

