#include <stdio.h>
#include <stdlib.h>

int main()
{

    int maxSize = 1;
    for(int i = 0; i < 3; i++) {
        int taille = rand() % 10 + 1;
        if (taille > maxSize) maxSize = taille;
        if(i == 0) {
            int chiffres[taille];
            for(int o = 0; o < taille; o++)
                chiffres[o] = rand() % 10 + 1;
        } else if(i == 1) {
            float x[taille];
            for(int o = 0; o < taille; o++)
                x[o] = rand() % 100 / 10;
        } else if(i == 2) {
            char couleur[3] = {'R', 'V', 'B'};
        }
    }

    for(int i = 0; i < maxSize; i++)
    {
        if(i < sizeof(chiffres)) {
            printf("chiffres[%i] = %i", i, chiffres[i]);
        }
        if(i < sizeof(x) && x[i] != '\n') {
            printf("\tx[%i] = %f", i, x[i]);
        }
        if(i < sizeof(couleur)) {
            printf("\tcouleur[%i] = '%c'", i, couleur[i]);
        }
        printf("\n");
    }
}