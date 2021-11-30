#include <stdio.h>
#include <ctype.h>

#define TAILLE 80

void afficherMat(char *mat) {
    int i;
    for(i=0;i<sizeof(mat);i++) {
        printf("%s", mat[i]);
    }
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
    
    afficherMat(majs);
    return 0;
}
