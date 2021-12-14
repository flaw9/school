#include <stdio.h>
#include <stdlib.h>

struct pile {
    int TAILLEMAX;
    int *pile;
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
    return (p.sommet == p.TAILLEMAX) ? 1 : 0;
} 

/* Si la pile n'est pas vide, renvoie le dernier élément et décrémente le sommet. */
int depiler(PILE p)
{
    if (!pileVide(p)) {
        int value = p.pile[p.sommet];
        p.sommet -= 1;
        return value;
    }
}

/* Si la pile n'est pas pleine, incrémente le sommet et ajoute l'élément à la pile. */
void empiler(PILE p, int elt)
{
    if(!pilePleine(p)) {
        p.sommet += 1;
        p.pile[p.sommet] = elt;
    }
}

int main()
{

    PILE p; p.sommet = -1; p.TAILLEMAX = 5;
    return 0;
}