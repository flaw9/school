#include <stdio.h>
#include<stdlib.h>

// #define SIZE1 abs(rand() % 10 + 1)
// #define SIZE2 abs(rand() % 10 + 1)

// int main()
// {
//     printf("%i ; %i\n", SIZE1, SIZE2);
//     int max = SIZE1;
//     if (SIZE2 > max) max = SIZE2;

//     int chiffres[SIZE1];
//     for (int i = 0; i < SIZE1; i++) {
//         chiffres[i] = abs(rand() % 10 + 1);
//     }
//     float x[SIZE2];
//     for (int i = 0; i < SIZE1; i++) {
//         x[i] = abs(rand() % 100);
//     }
//     char couleur[3] = {'R', 'V', 'B'};

//     for(int i = 0; i < max; i++)
//     {
//         if(i < SIZE1) {
//             printf("chiffres[%i] = %i", i, chiffres[i]);
//         }
//         if(i < SIZE2) {
//             printf("\tx[%i] = %f", i, x[i]);
//         }
//         if(i < 3) {
//             printf("\tcouleur[%i] = '%c'", i, couleur[i]);
//         }
//         printf("\n");
//     }
// }

int main() {
    int chiffres[6] = {1, 2, 3, 4, 5, 6};
    float x[5] = {0.14, 1.22, 3, 4.5, 78};
    char couleur[3] = {'R', 'V', 'B'};
    for (int i = 0; i < 6; i++) {
        printf("chiffres[%i] = %i", i, chiffres[i]);
        if (i < 5) printf("\tx[%i] = %f", i, x[i]);
        if (i < 3) printf("\tcouleur[%i] = %c", i, couleur[i]);
        printf("\n");
    }
}