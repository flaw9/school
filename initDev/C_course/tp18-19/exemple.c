#include <stdio.h>

void afficherTab(int *tab) {
    int i;
    for(i=0;i<sizeof(tab);i++) {
        printf("%d", tab[i]);
    }
    printf("\n");
}

int main()
{
    int tab[] = { [0] = 42, [1] = 64, [99] = 100 };
    afficherTab(tab);
}

