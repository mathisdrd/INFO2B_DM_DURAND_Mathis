# Devoir Maison INFO2b
DURAND Mathis, 22/12/2025

# Partie 1 : Vectors

## Question 0
Le mot clé `const` signifie "en lecture seule" :
* après la déclaration d'une méthode, cela signifie que la méthode ne modifiera pas les attributs de l'objet sur lequel la méthode est appelée
* avant un paramètre dans l'appel de la méthode, cela signifie que l'objet mis en paramètre ne sera pas modifié

Cette précision permet au code ne pas compiler si on modifie par erreur un objet passé en `const`. C'est une sécurité.

## Question 2
Le mot clé `virtual` précise que la méthode n'est pas implémentée et qu'elle devra l'être dans la classe fille, auquel cas elle sera également virtuelle et aucun objet de la classe fille ne pourra être créé.
Il faut obligatoirement mettre le mot clé `virtual` avant la délcaration du destructeur de la classe abstraite mère afin d'éviter les fuites de données. Si une classe fille déclare une variable alloué dynamiquement, le destructeur de la classe mère (appelé si on a mis le mot clé `virtual`) ne détruira par cette variable allouée dynamiquement et on aura une fuite de mémoire.

## Question 3
L'utilisation d'un `unique_ptr` pour pointer sur les tableaux se justifie car lors de la copie, lorsque le pointeur sur le tableau sera détruit, la case mémoire associée sera détruite automatiquement et aucune perte de mémoire n'aura lieu.

## Question 6
Le passage par référence plutôt que par copie permet d'avoir un processus beaucoup plus rapide.

## Question 8
L'implémentation de l'opérateur [] permet d'ajouter de la lisibilité et de la praticité à la classe.
Le renvoie d'une référence constante est intéressant car il permet d'être plus rappide qu'une copie, mais pour ne pas donner la possiblité de modifier l'élément retourné, on utilise le mot clé `const`.

## Question 10
Un constructeur de copie est obligatoire car le constructeur de copie par défaut copierait le pointeur storage, mais comme c'est un `unique_ptr`, c'est impossible. Il faut donc faire une copie profonde afin de ne pas avoir de problèmes.

# Partie 2 : PriorityQueues

## Question 11
Le chaînage entre les noeuds par des `unique_ptr` imposerait une copie en profondeur et non superficielle des noeuds à chaque intervertion des noeuds selon la règle de priorité lors de l'ajout d'un élément. Ceci peut impliquer beaucoup de copies à chaque push.

## Question 12
La règle de priorité impose que le type T supporte l'opérateur de comparaison. Des pointeurs ou des types spéciaux issus de bibliothèques comme potentiellement des comlpexes ne pourront pas être stockés dans une `PriorityQueue`.

## Question 13
Il est intéressant d'utiliser un `Vector` au lieu d'une liste car ce dernier va dynamiquement changer de taille en fonction du nombre de noeuds de la `PriorityQueue`.
L'utilisation d'un `unique_ptr` impliquerait de devoir réimplémenter toutes les méthodes d'allocation dynamique, ce qui a déjà été fait dans la classe `Vector`.

## Question 18
Les méthodes `push()` et `pop()` sont toutes deux de complexité $\mathcal O(\log_2(n))$ car dans les pires des cas, l'élément ajouté doit remonter tout l'arbre et l'élément déplacé en tête de l'arbre après le pop doit redescendre tout l'arbre. Cependant c'est un arbre binaire, qui a donc $\log_2(n)$ étages, d'où la complexité en $\mathcal O(\log_2(n))$