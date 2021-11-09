# Recherche de R dans un tableau T trié et complexité

## 1

### a)

```python
def rechercheNaive(t: list, res: int) -> int:
    i = 0
    while i < len(t)-1 or t[i] < res:
        i += 1
        if t[i] == res:
            return i
    return -1
```

### b)

Le pire des cas serait que le nombre recherché soit plus grand que le dernier élément du tableau.

La complexité de l'algorithme serait alors égale à la longueur du tableau.

## 2

### a)

<pre>
[1, 3, 5, 7]    [1, 3]  [1]
     x            x      x   
2                            ][
</pre>

---|milieu|T[milieu]|deb|fn|commentaire
---|---|---|---|---|---
init|2|----|1|4
1   |2|<pre>3   2<3 =></pre>|1|3|T[milieu]>R donc fin=milieu
2   |1|<pre>1   2>1 =></pre>|1|1|FIn car deb = fin et t[deb] != 2

### b)

Dans le cas ou **R>t[milieu]**, c'est le début qui est modifié &rarr; `deb = milieu + 1`

Dans le cas ou **R<t[milieu]**, c'est la fin qui est modifiée &rarr; `fn = milieu - 1`

### c)

```python
def rechercheDichotomie(tab: list, x: int) -> int:
    debut, fin = 0, len(tab) - 1
    while debut <= fin:
        m = (debut + fin) // 2
        if x == tab[m]:
            return m
        if x > tab[m]:
            debut = m + 1
        else:
            fin = m - 1
    return -1
```

## 3

### a)

<table>
    <tr>
        <td colspan="2"></td>
        <td colspan="2">Nombre d'itérations</td> 
    </tr>
    <tr>
        <td>n</td>
        <td>N</td>
        <td>dichotomie</td>
        <td>Solution naïve</td>
    </tr>
    <tr>
        <td>1</td>
        <td>2</td>
        <td>2</td>
        <td>2</td>
    </tr>
    <tr>
        <td>2</td>
        <td>4</td>
        <td>3</td>
        <td>4</td>
    </tr>
    <tr>
        <td>3</td>
        <td>8</td>
        <td>4</td>
        <td>8</td>
    </tr>
    <tr>
        <td>4</td>
        <td>16</td>
        <td>5</td>
        <td>16</td>
    </tr>
    <tr>
        <td>5</td>
        <td>32</td>
        <td>6</td>
        <td>32</td>
    </tr>
    <tr>
        <td>6</td>
        <td>64</td>
        <td>7</td>
        <td>64</td>
    </tr>
    <tr>
        <td>7</td>
        <td>128</td>
        <td>8</td>
        <td>128</td>
    </tr>
    <tr>
        <td>8</td>
        <td>256</td>
        <td>9</td>
        <td>256</td>
    </tr>
    <tr>
        <td>9</td>
        <td>512</td>
        <td>10</td>
        <td>512</td>
    </tr>
    <tr>
        <td>10</td>
        <td>1024</td>
        <td>11</td>
        <td>1024</td>
    </tr>
</table>

### c)

Il y a relation entre la réponse *a* et la réponse *b*. Les valeurs de la colonne *dichotomie* correspondent à la valeur de **log<sub>2</sub>(N)**.

# Manipulation de fichier et formatage

```python
def Lecture_Mnemo(fichier: str) -> list:
    return open(f"{fichier}", 'r').readlines()

def Seg_Mnemo(x: int, Code_a_Executer: list) -> list:
    return Code_a_Executer[x].replace(',', ' ').replace('(', ' ').replace(')', ' ').split(' ')

def main():
    Code_a_Executer = Lecture_Mnemo('tp11-12/source.asm')
    for i in range(len(Code_a_Executer)):
        Champs_Code = Seg_Mnemo(i, Lecture_Mnemo('tp11-12/source.asm'))[:-1]
        print(Champs_Code)

if __name__ == "__main__":
    main()
```

# Tri à bulle et Complexité