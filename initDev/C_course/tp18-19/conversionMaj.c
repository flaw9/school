#include <stdio.h>
#include <ctype.h>

#define TAILLE 80

int main() {
    char lettre[TAILLE];
    int i=0;

    /* Lecture d'une ligne e */
    while(i < TAILLE && (lettre[i]=getchar()) != '\n')i++;

    /* Affichage d'une ligne de texte convertie */
    for(i=0; i < TAILLE && lettre[i] != '\n'; i++)
        putchar(toupper(lettre[i]));
    printf("\n");
    return 0;
}
