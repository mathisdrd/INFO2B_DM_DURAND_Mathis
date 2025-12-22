# Devoir Maison INFO2b
DURAND Mathis, 22/12/2025
 
## Question 0
Le mot clé `const` signifie "en lecture seule" :
* après la déclaration d'une méthode, cela signifie que la méthode ne modifiera pas les attributs de l'objet sur lequel la méthode est appelée
* avant un paramètre dans l'appel de la méthode, cela signifie que l'objet mis en paramètre ne sera pas modifié

Cette précision permet au code ne pas compiler si on modifie par erreur un objet passé en `const`. C'est une sécurité.

## Question 2
Le mot clé `virtual` précise que la méthode n'est pas implémentée et qu'elle devra l'être dans la classe fille, auquel cas elle sera également virtuelle et aucun objet de la classe fille ne pourra être créé.
Il faut obligatoirement mettre le mot clé `virtual` avant la délcaration du destructeur de la classe abstraite mère afin d'éviter les fuites de données. Si une classe fille déclare une variable alloué dynamiquement, le destructeur de la classe mère (appelé si on a mis le mot clé `virtual`) ne détruira par cette variable allouée dynamiquement et on aura une fuite de mémoire.
