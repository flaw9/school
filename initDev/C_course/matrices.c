#include <stdio.h>

void saisiMat() {
    int lar, lon;
    printf("Saisir la largeur: ");
    scanf("%d", &lar);
    printf("Saisir la longueur: ");
    scanf("%d", &lon);
    float tab1[lon][lar];
    float tab2[lon][lar];
    // return tab1, tab2;
}

void afficherMat(float *mat[]) {
    int i, o;
    for(i=0;i<sizeof(mat);i++) {
        printf("|");
        for(o=0;o<sizeof(mat[i]);o++) {
            printf("%f", mat[i][o]);
        }
        printf("|\n");
    }
}

int main() {
    int N;
    printf("Saisir N: ");
    scanf("%d",&N);

    float tab1[N][N];
    float tab2[N][N];
    float tab3[N][N];
    
    printf("Size of tab1: %i\n", sizeof(tab2));

    printf("Matrices générées.\n");
    printf("Matrice n°1: \n");
    // afficherMat(tab1);
}