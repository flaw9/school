# Tris

## 1. Tri à bulles

### Algo:

```
Début
    i <- 0
    tant que i < taille faire
        o <- 1
        tant que o < taille - i faire
            si t[o] > t[o+1] alors
                bigger <- t[o+1]
                t[o+1] <- t[o]
                t[o] <- bigger
            Fin Si
            o <- o + 1
        Fin Tant que
        i < i + 1
    Fin Tant que
Fin
```

## 2. Tri par insertion

### Algo:

```
Début
    i <- 1
    tant que i < taille faire
        o <- i
        smaller <- t[i]
        tant que o > 1 et smaller < t[o] faire
            o <- o - 1
            t[o] <- t[o-1]
        Fin Tant que
        t[o] <- smaller
    i <- i + 1 
    Fin Tant que
Fin
```

## Tri par sélection

### Algo:

```
Début
    i <- 1
    tant que i < taille faire
        imin <- i
        o <- i + 1
        tant que o < taille faire
            si t[o] < t[imin] alors
                imin = o
            Fin Si
            o <- o + 1
        Fin Tant que
        temp <- t[imin]
        t[imin] <- t[i]
        t[i] <- temp
        i <- i + 1
    Fin Tant que
Fin
```

## Tri par compteur

### Algo:

```
Début
    compteur = [0,0,0,0,0,0,0,0,0,0]
    i <- 1
    tant que i < taille faire
        compteur[t[i]] <- compteur[t[i]] + 1
    Fin Tant que
    t = []
    i <- 1
    tant que i < tailleCompteur faire
        nb <- 1
        tant que nb < compteur[i] faire
            AJouter(t, i)
        Fin Tant que
    Fin Tant que 
Fin
```

## Tri Radix

### Algo:

```
Début
    digits <- (Tableau de 10 tableaux)
    i <- 1
    Tant que i < taille faire
          
    Fin Tant que
Fin
```