#include <stdio.h>
#include <stdlib.h>

#define SIZE1 (rand() % 10 + 1)
#define SIZE2 (rand() % 10 + 1)

int main()
{
    int maxSize = SIZE1;
    if(SIZE2 > maxSize) maxSize = SIZE2;

    int chiffres[SIZE1];
    int x[SIZE2];
    int couleur[3] = {'R', 'V', 'B'};

    for(int i = 0; i < 2; i++) {
        if(i == 0) {
            for(int o = 0; o < SIZE1; o++)
                chiffres[o] = rand() % 10 + 1;
        } else if(i == 1) {
            for(int o = 0; o < SIZE2; o++)
                x[o] = rand() % 100 / 10;
        }
    }

    for(int i = 0; i < maxSize; i++)
    {
        if(i < SIZE1) {
            printf("chiffres[%i] = %i", i, chiffres[i]);
        }
        if(i < SIZE2 && x[i] != 0) {
            printf("\t x[%i] = %f", i, x[i]);
        }
        if(i < sizeof(couleur)) {
            printf("\t couleur[%i] = '%c'", i, couleur[i]);
        }
        printf("\n");
    }
}