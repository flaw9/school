#include <stdio.h>

void sommeProduit(int i, int j) {
    int k=i * j; // stockage temporaire de la valeur qui ira dans j
    i = i+k; // i reçoit la somme des paramètres
    j = k; //j reçoit le produit des paramètres (stocké dans k)
    return;
}

int main() {
    int i = 3; // déclaration de i et initialisation à 3
    int j = 4; // déclaration de j et initialisation à 4;
    printf("i=%d ; j=%d\n", i, j); // affiche : i=3 : j=4
    sommeProduit(i,j); // appel de la fonction : on pourrait s'attendre a ce que ivaille 7 et j vaille 12 en sortie
    printf("i=%d ; j=%d\n", i, j); // affiche encore: i=3 ; j=4
    return 0;
}
