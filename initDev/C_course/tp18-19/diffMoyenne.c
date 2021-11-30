#include <stdio.h>

int main() {
    int nbElements;
    printf("Nombre d'elements: ");
    scanf("%d", &nbElements);

    float tab[nbElements];

    for (int i = 0; i < nbElements; i++) {
        printf("Valeur n°%d: ", i+1);
        scanf("%ld\n", &tab[i]);
    }

    for (int i = 0; i < nbElements; i++) {
        printf("%ld", tab[i]);
    }
}