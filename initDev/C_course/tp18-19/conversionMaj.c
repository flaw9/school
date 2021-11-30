#include <stdio.h>
#include <ctype.h>

#define TAILLE 80

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
