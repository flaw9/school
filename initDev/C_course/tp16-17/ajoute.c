#include <stdio.h>

void ajouter(float *tab, int N)
    /* Incrémente tous les éléments d'un tableau de nombre flottants de 1. */
{
    for(int i;i<N;i++)
        tab[i] = tab[i] + 1;
    return;
}

void printTab(float *tab, int N)
    /* Fonction qui affiche le contenu d'un tableau de nombres flottants. */
{
    for(int i=0; i<N; printf("%f\n", tab[i++]));
}

int main()
{
    int N = 10;
    float tab[N];

    for(int i=0; i<N; i++) tab[i] = i; // Initialise les valeurs du tableau tab de 10 éléments.

    printTab(tab, N);

    printf("---\n");
    ajouter(tab, N);

    printTab(tab, N);

    return 0;
}