#include <stdio.h>

int main() {
    int nbElements;
    scanf("Nombre d'elements: %i", nbElements);
    
    printf("%i", nbElements);

    float tab[nbElements];

    for (int i = 0; i < nbElements; i++) {
        scanf("Valeur n°%i: %f", i+1, tab[i]);
    }

    for (int i = 0; i < nbElements; i++) {
        printf("%f", tab[i]);
    }
}