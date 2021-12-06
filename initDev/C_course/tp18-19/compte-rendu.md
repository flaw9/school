# 1

## 1.3

```c
#include <stdio.h>
#include <ctype.h>

#define TAILLE 60

void afficherMajs(char *tab) {
    int i;
    for(i=0;i<sizeof(tab);i++) {
        putchar(tab[i]);
    }
    printf("\n");
}

int main() {
    char lettre[TAILLE];
    char majs[TAILLE];
    int i=0;

    /* Lecture d'une ligne e */
    while(i < TAILLE && (lettre[i]=getchar()) != '\n')i++;

    /* Affichage d'une ligne de texte convertie */
    for(i=0; i < TAILLE && lettre[i] != '\n'; i++)
        majs[i] = toupper(lettre[i]);
    
    afficherMajs(majs);
    return 0;
}
```

## 1.4

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int chiffres[6] = {1, 2, 3, 4, 5, 6};
    float x[5] = {0.14, 1.22, 3, 4.5, 78};
    char couleur[3] = {'R', 'V', 'B'};
    for (int i = 0; i < 6; i++) {
        printf("chiffres[%i] = %i", i, chiffres[i]);
        if (i < 5) printf("\tx[%i] = %f", i, x[i]);
        if (i < 3) printf("\tcouleur[%i] = %c", i, couleur[i]);
        printf("\n");
    }
}
```