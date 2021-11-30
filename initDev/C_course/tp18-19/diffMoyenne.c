#include <stdio.h>

int main() {
    int nbElements;
    scanf("Nombre d'elements: %d", &nbElements);
    
    printf("%i", nbElements);

    float tab[nbElements];

    for (int i = 0; i < nbElements; i++) {
        scanf("Valeur n°%d: %f", i+1, tab[i]);
    }

    for (int i = 0; i < nbElements; i++) {
        printf("%f", tab[i]);
    }
}