# Adressage et réseaux IP

## Exercice

### 1.

> Adresse IP: 134.141.7.11

> Masque: 255.255.0.0

Catégorie|Contenu
---|--
Numéro de réseau|**B**
Adresse broadcast|**134.141.255.255**
Adresse réseau|**134.141.0.0**
Adresses IP assignables|**134.141.0.1 &rarr; 134.141.255.254**

<u>**Explications:**</u>

Réseau de type **B** de forme `R.R.H.H`, donc les valeurs qui sont positionnées au niveau des `R` ne bougent pas `(134.141.H.H)`.

Pour l'adresse broadcast, on remplace tous les `H` par `255` `(R.R.255.255)`.

Pour l'adresse réseau, on remplace tous les `H` par `0` `(R.R.0.0)`.

Pour les IPs assignables, on les situe entre l'adresse réseau et l'adresse broadcast.

***

### 2.

> Adresse IP: 193.193.7.7

> Masque: 255.255.255.0

Catégorie|Contenu
---|---
Numéro de réseau|**C**
Adresse broadcast|**193.193.7.255**
Adresse réseau|**193.193.7.0**
Adresses IP assignables|**193.193.7.1 &rarr; 193.193.7.254**

<u>**Explications:**</u>

Réseau de type **C** de forme `R.R.R.H`, donc les valeurs qui sont positionnées au niveau des `R` ne bougent pas `(193.193.7.H)`.

Pour l'adresse broadcast, on remplace tous les `H` par `255` `(R.R.R.255)`.

Pour l'adresse réseau, on remplace tous les `H` par `0` `(R.R.R.0)`.

Pour les IPs assignables, on les situe entre l'adresse réseau et l'adresse broadcast.

***

### 3.

> Adresse IP: 200.1.1.130

> Masque: 255.255.255.0

Catégorie|Contenu
---|---
Numéro de réseau|**C**
Adresse broadcast|**200.1.1.255**
Adresse réseau|**200.1.1.0**
Adresses IP assignables|**200.1.1.1 &rarr; 200.1.1.254**

<u>**Explications:**</u>

Réseau de type **C** de forme `R.R.R.H`, donc les valeurs qui sont positionnées au niveau des `R` ne bougent pas `(200.1.1.H)`.

Pour l'adresse broadcast, on remplace tous les `H` par `255` `(R.R.R.255)`.

Pour l'adresse réseau, on remplace tous les `H` par `0` `(R.R.R.0)`.

Pour les IPs assignables, on les situe entre l'adresse réseau et l'adresse broadcast.

***

### 4.

> Adresse IP: 98.45.36.73

> Masque: 255.0.0.0

Catégorie|Contenu
---|---
Numéro de réseau|**A**
Adresse broadcast|**98.255.255.255**
Adresse réseau|**98.0.0.0**
Adresses IP assignables|**98.0.0.1 &rarr; 98.255.255.254**

<u>**Explications:**</u>

Réseau de type **C** de forme `R.H.H.H`, donc les valeurs qui sont positionnées au niveau des `R` ne bougent pas `(98.H.H.H)`.

Pour l'adresse broadcast, on remplace tous les `H` par `255` `(R.255.255.255)`.

Pour l'adresse réseau, on remplace tous les `H` par `0` `(R.0.0.0)`.

Pour les IPs assignables, on les situe entre l'adresse réseau et l'adresse broadcast.

***