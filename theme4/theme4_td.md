_thème 4_ — Références et pointeurs
=================================

> [Université de Lille](https://www.univ-lille.fr/)  
> [Licence d'informatique, 2e année](https://portail.fil.univ-lille.fr/ls2)  
> [Module de MPC — Maîtrise de la Programmation en C](https://portail.fil.univ-lille.fr/ls2/mpc)  
> Équipe pédagogique de MPC, d'après un document CC BY-SA de Gilles
    Grimaud Philippe Marquet, 2018-2020.  
> mars 2021  
> [CC BY-SA](https://creativecommons.org/licenses/by-sa/4.0/)

Une version PDF pour impression est accessible sur [nextcloud.univ-lille.fr](https://nextcloud.univ-lille.fr/index.php/s/8Pr5ooXNZ4gAArq)

Ce document est le support d'exercices de TD et TP.

Le thème 4 traite des références et pointeurs en C, des opérateurs
de référence `&`, et `*` de déréférencement. (L'arithmétique des
pointeurs n'est pas abordée ici, elle fera l'objet de futurs thèmes).

### Mettre 42 — _exercice de TD_ ###

Soit une variable de type `int` que l'on désire affecter à la
valeur 42. 

1. Pourquoi est-ce qu'une fonction de prototype

    ```c
    void mettre42_bogus(int n);
    ```

    ne peut être utilisée pour modifier la valeur de la variable. 

1. Donner le prototype d'une fonction `mettre42()` qui permet de
   modifier la valeur d'une variable entière désignée par un
   paramètre. 

1. Soient les déclarations suivantes :

    ```c
    int n;
    int t[12];
    ```

    Donner les appels de la fonction `mettre42()` permettant
    d'affecter la valeur 42 à `n` d'une part, à l'élément `t[3]` du
    tableau d'autre part.

### Chercher dans un tableau — _exercice de TD_ ###

* Réalisez une fonction `chercher()` qui accepte en paramètre un
tableau d'entiers `tab`, et une valeur `v`, et qui renvoie une
référence vers le premier élement du tableau égal à `v`.  
Quelle valeur peut renvoyer la fonction si la valeur n'est pas
présente dans le tableau ? 

### Arguments de `main()` – _exercice de TD et TP_ ###

Le prototype de la fonction `main()` d'un programme C est le suivant :

```c
int main (int argc, char *argv[]);
```

Les paramètres `argc` et `argv` permettent de récupérer les arguments
de la ligne de commande.

* `argc` correspond au nombre d'arguments +1
* `argv[0]` est une chaîne de caractères correspondant au nom de la
  commande. Autrement dit, c'est une référence sur le 1er caractère de
  cette chaîne de caractères. 
* de manière plus générale, `char *argv[]` est un tableau de références
  vers des caractères. Autrement dit, un tableau de chaînes de
  caractères.

  Chacune de ces chaînes de caractères correspond à un argument de la
  ligne de commande. 

1. Représentez par un dessin la valeur du paramètre `argv` de `main()`
   lors de l'exécution des commandes suivantes d'un programme
   C compilé en une commande `mecho` :

    ```console
    % mecho "Hello world !"
    % mecho Hello world !
    ```

2. Expliquez, compilez et exécutez le programme suivant :

    ```c
    /* Ma commande echo */
    
    #include <stdio.h>
    #include <stdlib.h>
    
    int
    main (int argc, char *argv[])
    {
        int i; 
    
        for(i = 1; i < argc ; i++) {
            printf("%s ", argv[i]); 
        } 
        putchar('\n');
    
        exit(EXIT_SUCCESS); 
    }
    ```
	
### Pointeur sur un pointeur — _exercice de TD_ ###

Un pointeur est aussi une variable. De la même manière que nous
pouvons manipuler une référence sur une variable entière, nous pouvons
manipuler une référence sur un pointeur.

Considérez le code suivant:

```c
int n, m;
int * foo;
foo = &n;
```

1. En utilisant la règle de typage des pointeurs (un pointeur qui
   référence quelque chose de type `TOTO` a pour type `TOTO*`),
   déduire le type d'un pointeur `bar` pouvant contenir une référence
   vers `foo`.

1. Comment déclarer un tel pointeur, et y affecter une référence sur
   `foo` ? 

1. Une fois l'affectation précédente réalisée, comment faire pointer
   `foo` sur `m` en utilisant le pointeur `bar` et l'opérateur de 
   déréférencement ? 


### Recherche dichotomique — _exercice de TD et TP_ ###

1. Proposez une fonction récursive qui recherche par dichotomie une
  valeur `v` dans un tableau trié `tab` de `size` éléments : 

    ```c
    float * search_dicho(float v, float *tab, int size);
    ```

2. Proposez une fonction `main()` pour tester cette fonction
   de recherche dichotomique.

<!-- eof --> 
