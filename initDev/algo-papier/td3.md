# 1. Manipulation de Tableaux de nombres

## 1.

### Algo:

***

<u>Variables</u>

-  |Nom|Type
---|---|--- 
(a)
t  |tableau
i  |entier
nbr|entier
nbs|entier
(b)
pp |entier
pg |entier
i  |entier

***

```
Début

# (a)

    nbr <- 1
    i <- 0
    Tant que nbr != 0 et i <= N faire
        Afficher("Saisir une valeur :")
        Saisir(nbr)
        t[i] <- nbr
        i <- i + 1
    Fin tant que
    nbs <- i - 1
    Afficher("Nombre d'éléments: ", nbs)

# (b)

    i <- 2
    pp <- t[1]
    ipp <- 1
    ipg <- 1
    pg <- t[1]
    Tant que i < nbs faire
        si pp > t[i] alors
            pp <- t[i]
            ipp <- i
        si pg <> t[i] alors
            pg <- t[i]
            ipg <- i
        i <- i + 1
    Fin Tant que

# (c)
# (d)
# (e)



# (f)

Fin
```