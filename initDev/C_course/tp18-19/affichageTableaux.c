#include <stdio.h>
#include<stdlib.h>

#define SIZE1 abs(rand() % 10 + 1)
#define SIZE2 abs(rand() % 10 + 1)

int main()
{
    int chiffres[SIZE1];
    for (int i = 0; i < SIZE1; i++) {
        chiffres[i] = abs(rand() % 10 + 1);
    }
    float x[SIZE2];
    for (int i = 0; i < SIZE1; i++) {
        x[i] = abs(rand() % 100 / 10);
    }
    char couleur[3] = {'R', 'V', 'B'};

    printf("%i\n", sizeof(x));
    for(int i = 0; i < 6; i++)
    {
        if(i < SIZE1) {
            printf("chiffres[%i] = %i", i, chiffres[i]);
        }
        if(i < SIZE2) {
            printf("\tx[%i] = %f", i, x[i]);
        }
        if(i < 3) {
            printf("\tcouleur[%i] = '%c'", i, couleur[i]);
        }
        printf("\n");
    }
}