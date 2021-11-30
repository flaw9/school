#include <stdio.h>

int main() {
    int nbElements;
    float tab[nbElements];
    scanf("Nombre d'elements: %i", nbElements);

    for (int i = 0; i < nbElements; i++) {
        scanf("%f", tab[i]);
    }

    for (int i = 0; i < nbElements; i++) {
        printf("%f", tab[i]);
    }
}