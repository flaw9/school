#include <stdio.h>

void ajouter(float *tab, int N)
{
    for(int i;i<N;i++)
        tab[i] = tab[i] + 1;
    return;
}


int main()
{
    int N = 10;
    float tab[N];

    for(int i=0; i<N; i++) tab[i] = i;

    for(int i=0; i<N; i++) printf("%f\n", tab[i]);
    
    printf("---\n");
    ajouter(tab, N);

    for(int i=0; i<N; i++) printf("%f\n", tab[i]);

    return 0;
}
