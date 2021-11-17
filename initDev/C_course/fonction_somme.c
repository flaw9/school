#include <stdio.h>

float somme(unsigned int a, short b, float c) {
    return a+b+c;
}

int main() {
    unsigned int v1 = 70000;
    short v2 = 16;
    float v3 = 0.5;

    printf("La somme de %u, %d et %f est %f\n", v1, v2, v3, somme(v1, v2, v3));
    return 0;
}
