#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLEMAX 5

struct pile {
    int pile[TAILLEMAX];
    int sommet;
};
typedef struct pile PILE;

/* Renvoie 1 si la pile est vide, sinon 0. */
int pileVide(PILE p)
{
    return p.sommet == -1 ? 1 : 0;
}

/* Renvoie 1 si la pile est pleine, sinon 0. */
int pilePleine(PILE p)
{
    return (p.sommet == TAILLEMAX-1) ? 1 : 0;
} 

/* Si la pile n'est pas vide, renvoie le dernier élément et décrémente le sommet. */
int depiler(PILE *p)
{
    if (pileVide(*p) == 0) {
        int value = p->pile[p->sommet];
        p->sommet -= 1;
        return value;
    }
    else {
        return -1;
    }
}

/* Si la pile n'est pas pleine, incrémente le sommet et ajoute l'élément à la pile. */
int empiler(PILE *p, int elt)
{
    if(pilePleine(*p) == 0) {
        p->sommet += 1;
        p->pile[p->sommet] = elt;
        return 1;
    } else {
        return 0;
    }
}

int sommet(PILE p)
{
    return p.pile[p.sommet];
}

void afficherEtat(PILE p) {
    printf("\n");
    printf("Contenu de la pile: \n");
    for(int i = TAILLEMAX-1; i >= 0; i--) {
        printf("%d : %d\n", i+1, p.pile[i]);
    }
    (pilePleine(p) == 0) ? ((pileVide(p) == 0) ? printf("La pile n'est ni vide ni pleine !\n") : printf("La pile est vide !\n")) : printf("La pile est pleine !\n");
    printf("Indice du sommet: %d\n", p.sommet+1);
    
    printf("\n");
}

/* Menu avec différentes options */
int mainP(int estCree)
{
    system("clear");
    printf("-----\n");
    estCree == 0 ? printf("1: Créer une pile\n\n") : printf("La pile existe déjà !\n\n");
    if (estCree == 0) {
        printf("La pile doit d'abord être crée !\n");
    } else {
        printf("2: Empiler une valeur\n");
        printf("3: Dépiler une valeur\n");
        printf("4: Afficher état.\n");
    }
    printf("0: Quitter.\n");
    printf("-----\n");
    int request;
    scanf("%i", &request);
    return request;
}

long int fact(int n) {
    if (n>=1)
        return n*fact(n-1);
    else
        return 1;
}

void factPile(int n) {
    PILE p;
    p->sommet = -1;
    while (n > 0) {
        empiler(p, n);
        n -= 1;
    }
    afficherEtat(p)

    int r = 1;
    while (!pileVide(p)) {
        r = r*depiler(p);
    }

    printf("factPile(%d) = %d", n, r);
}

int main()
{

    printf("Factorielle(5) = %d\n",fact(5));

    int valeur;
    printf("Entrez la valeur à empiler: ");
    scanf("%d", &valeur);

    factPile(valeur);

    return 0;
}