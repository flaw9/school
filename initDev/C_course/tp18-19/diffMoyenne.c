#include <stdio.h>

int main() {
    float tab[];
    int nbElements;
    scanf("%i", nbElements);

    for (int i = 0; i < nbElements; i++) {
        scanf("%f", tab[i]);
    }

    for (int i = 0; i < nbElements; i++) {
        printf("%f", tab[i]);
    }
}