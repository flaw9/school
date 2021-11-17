#include <stdio.h>

int main() {
    int i=0;
    while (i < 20) {
        printf("%02de instruction de la boucle\n", i);
        i++;
    }
    return 0;
}