#include <stdio.h>

#define MAX 6

int main()
{
    int chiffres[6] = {1, 2, 3, 4, 5, 6}:
    float x[5] = {0.14, 1.22, 3, 4.5, 78};
    char couleur[3] = {'R', 'V', 'B'};

    for(int i = 0; i < MAX; i++)
    {
        if(i < sizeof(chiffres)) {
            printf("%i", chiffres[i]);
        }
        if(i < sizeof(x)) {
            printf("%f", x[i]);
        }
        if(i < sizeof(couleur)) {
            printf("%d", couleur[i]);
        }
        printf("\n");
    }
}