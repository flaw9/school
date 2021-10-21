# 1. Manipulation d'entiers

## 1. 

> Écrire un algo qui
>    
>     a. Demande d'entrer un nombre en 50 et 100
>     
>     b. Si le nombre est dans [50, 100] fait :
>     
>         I. lui ajoute 62 et affiche le résultat
> 
>         II. supprime le chiffre le plus à gauche et l'ajoute au nombre restant.
> 
>         III. enlève ce dernier nombre au nombre initian
> 
>         IV. vérifie que le résultat est 37, sinon affiche un message d'erreur.
>     
>     c. Sinon, affiche un message d'erreur.
>

### Algo: 

***

<u>Variables</u>

|Nom|Type|
|---|---|
|x|entier|
|y|entier|

***

```
Début
    Saisir (x)
    Si (x >= 50) et (x <= 100) alors
        y <- x+62
        Afficher(y)
        y <- y-99
        x <- x-y
        Si non (x = 37) alors
            Afficher (Erreur)
        Fin Si
    Sinon   
        Afficher (Erreur, nombre non compris entre 50 et 100)
    Fin Si
Fin
```

## 2.

> Écrire un algorithme qui affiche la table de multiplication pour un nombre donné (entré par l'utilisateur)

### Algo:

<u>Variables</u>

|Nom|Type  |
|---|---   |
|x  |entier|
|i  |entier|

***

```
Début
    Afficher("Entrez un nombre: ")
    Saisir(x)
    i <- 1
    Tant que i <= 10 faire
        t = x * i
        Afficher(t)
        i <- i + 1
    Fin tant que
Fin
```

## 3.

> Écrire un algorithme qui permet de trouver un nombre entier, qui sera affiché, inférieur à 100, qui satisfait les
conditions suivantes :
> - Le reste de sa division par 2 est 1
> - Le reste de sa division par 3 est 2
> - Le reste de sa division par 4 est 3
> - Le reste de sa division par 5 est 4

### Algo:

<u>Variables</u>

|Nom|Type  |
|---|---   |
|x  |entier|
|i  |entier|

```
Début
    i <- 0
    tant que (non (i%2 = 1)) et (non (i%3 = 2)) et (non (i%4 = 3)) et (non (i%5 = 4)) et (i < 100) faire
        i <- i + 1
    Fin tant que
    si (i < 100) alors
        Afficher(i)
    sinon
        Afficher('Introuvable')
    Fin si
Fin
```