_thème 7_ — Structures autoréférentes
=====================================

> [Université de Lille](https://www.univ-lille.fr/)  
> [Licence d'informatique, 2e année](https://portail.fil.univ-lille1.fr/ls4)  
> [Module de MPC — Maîtrise de la Programmation en C](https://portail.fil.univ-lille1.fr/ls4/mpc)  
> Équipe pédagogique de MPC, avec des emprunts à des documents CC-BY de Philippe Marquet, 2004-2018.  
> mai 2021  
> [CC BY](https://creativecommons.org/licenses/by/4.0/)

Une version PDF pour impression est accessible sur [nextcloud.univ-lille.fr](https://nextcloud.univ-lille.fr/index.php/s/KPpFdnfCPTaRGcj).

Ce document est le support d'exercices de TD et TP.

Le thème 7 traite des structures autoréférentes via la manipulation de
+listes chaînées, piles, files.

→ Implémentation de piles d'entiers — _exercices de TD_
-------------------------------------------------------

On veut réaliser une structure de donnée de type pile, stockant des entiers
`int`, et implémentée sous forme d'une liste chainée.

On se propose de donner les définitions des fonctions de prototypes :

```c
int is_empty(pile_t);     /* vraie ssi la pile est vide */
int init(pile_t *);       /* initialise la pile */
int push(pile_t *, int);  /* empile une valeur */
int pop(pile_t *, int *); /* dépile une valeur */
int destroy(pile_t *);    /* désalloue toute la pile */
```

Les fonctions renvoient une valeur nulle pour indiquer un succès, une
valeur non nulle sinon.

1. Donnez la définition du type `pile_t`

2. Comment est représentée la pile vide ?

3. Expliquez les paramètres des prototypes ci-dessus.

4. Donnez une définition de la fonction `init()`

5. Donnez une définition du prédicat `is_empty()`

6. Donnez une définition de la fonction `push()`

7. Donnez une définition de la fonction `pop()`

8. Donnez une définition de la fonction `destroy()`

On souhaite maintenant étendre les fonctionnalités de notre structure
de données pour permettre l'affichage de tous ses éléments,
l'insertion et la suppression d'éléments à une position passée en
paramètre (contrairement aux fonctions `push()` et `pop()` qui opèrent
sur le sommet de la pile).

Les fonctions `insert()` et `remove()` renvoient 0 en cas de
succès, -1 en cas d'échec. 

```c
void display(pile_t); /* parcourt la pile et affiche les éléments */
int insert(pile_t *p, int val, int pos); /* insère un nouvel élément à la position demandée */
int remove(pile_t *p, int *val, int pos); /* supprime l'élément à la position demandée */
```

9. Donnez une définition de la fonction `display()`. 

10. Donnez une définition de la fonction `insert()`.  
   La position d'insertion dans la pile est telle que
   `insert (p, v, 0)` est équivalent à `push(p, v)`.

valeur du paramètre `pos` doit être com
11. Donnez une définition de la fonction `remove()`.
   La position de suppression dans la pile est telle que
   `remove (p, v, 0)` est équivalent à `pop(p, v)`. 

<!-- eof --> 

<!--  LocalWords:  autoréférentes
 -->
