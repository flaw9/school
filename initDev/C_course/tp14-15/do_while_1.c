#include <stdio.h>

int main() {
    int i=0;
    i=0;
    while (i < 0) {
        printf("(1) %02de instruction de la boucle\n", i);
    }
    i=0;
    do {
        printf("(2) %02de instruction de la boucle\n", i);
    } while (i < 0);
    return 0;
}
