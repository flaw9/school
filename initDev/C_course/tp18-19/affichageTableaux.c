#include <stdio.h>

#define MAX 7

int main()
{
    int chiffres[6] = {1, 2, 3, 4, 5, 6};
    float x[5] = {0.14, 1.22, 3, 4.5, 78};
    char couleur[3] = {'R', 'V', 'B'};

    printf("%i\n", sizeof(x));
    for(int i = 0; i < MAX; i++)
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