#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float aleat () {
    return (float)rand() / RAND_MAX;
}

int main() {
    srand(time(NULL)); // initialisation du generateur de nombres aleatoires
    int N = rand()%200+1; // generation d'un nombre aleatoire entre 1 et 200 inclus
    float tab[N]; // declaration d'un tableau de N float
    // remplissage du tableau avec des nombres entre 0 et 1
    int i;
    for (i=0; i<N; i++)
        tab[i] = aleat ();
    // calcul de la moyenne des nombres dans le tableau
    float m = 0;
    for (i=0; i<N; i++)
        mt= tab[i];
    m /= N;
    printf("La moyenne est: %f\n", m);
    // recherche du premier element plus grand que 0.9
    for (i=0; i <1 && tab[i] < 0.9; i++);
    if (i <N)
        printf("Élement trouvé %f en position_%d\n", tab[i], i);
    else
        printf("Aucun élément trouvé \n");
    return 0;
}
