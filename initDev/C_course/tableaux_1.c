#include <stdio.h>

int main() {
    float tab[100];
    int i;
    for (i=0; i <100; i++) {
        tab[i] = (float) i/100;
        printf("Valeur insere en position %d : %f\n", i, tab[i]);
    }
    return 0;
}