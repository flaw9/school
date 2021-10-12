# 1. Boucles

## 1.

> Écrire un algorithme qui affiche un rectangle d'étoiles "*". La largeur et la hauteur seront entrées par l'utilisateur.

### Algo:

***

<u>Variables</u>

|Nom   |Type  |Commentaire|
|---   |---   |---|
|lar   |entier|Largeur
|hau   |entier|Hauteur
|index1|entier|Indice de boucle (étoiles)
|index2|entier|Indice de boucle (lignes)

***

```
Début
    Afficher("Saisir la largeur:")
    Saisir(lar)
    Afficher("Saisir la hauteur:")
    Saisir(hau)
    index1 <- 0
    tant que (index1 < hau) faire
        index2 <- 0
        tant que (index2 < lar) faire
            Afficher("*")
            index2 <- index2 + 1
        Fin tant que
        index1 = index1 + 1
    Fin tant que
Fin
```

## 2.

> Écrire un algorithme qui affiche un triangle isocèle formé d’étoiles. La hauteur (nombre de colonnes) sera donnée en entrée et le triangle pointera vers la droite.

### Algo:

***

<u>Variables</u>

Nom    |Type  |Commentaire
---    |---   |---
taille |entier|
index1 |entier|
etoiles|entier|
index2 |entier|

***

```
Début
    Afficher("Entrez la taille:")
    Saisir(taille)
    index1 <- 0
    tant que (index1 < (taille * 2)) faire
        si (index1 <= taille) alors
            etoiles <- index1
        sinon
            etoiles <- taille - index1 
        Fin si
        index2 <- 0
        tant que (index2 < etoiles) faire
            Afficher('*')
            index2 <- index2 + 1
        Fin tant que
        index1 <- index1 + 1
    Fin tant que
Fin
```

# 2. Manipulation de réels

## 1. 

> Écrire un algorithme qui résout une équation du second degré et affiche le résultat. Les paramètres a, b et c seront
entrés par l’utilisateur de manière à résoudre l’équation ax2 + bx + c = 0.

### Algo:

***

<u>Variables</u>

Nom|Type|Commentaire
---|---|---
a|entier
b|entier
c|entier
d|entier
x1|entier
x2|entier

***

```
Début
    Afficher("Saisir a:")
    Saisir(a)
    Afficher("Saisir b:")
    Saisir(b)
    Afficher("Saisir c:")
    Saisir(c)
    d <- b² - 4*a*c
    si d < 0 alors
        Afficher("Pas de solution(s).")
    sinon si d = 0 alors
        x1 <- (-b) / (2*a)
        Afficher("La solution est:")
        Afficher(x1)
    sinon
        x1 <- ((-b) + sqrt(d)) / 2a
        x1 <- ((-b) - sqrt(d)) / 2a
        Afficher("Les solutions sont:")
        Afficher(x1)
        Afficher(x2)
    Fin si
Fin
```