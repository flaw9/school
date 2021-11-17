#include <stdio.h>

int suivant(int i) {
    int j = i+1;
    return j;
}

int main() {
    int k = 3, j;

    j = suivant(k);
    printf("Le nombre suivant de %d est %d\n", k, j);
    return 0;
}
