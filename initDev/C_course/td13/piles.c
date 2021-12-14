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
int pileVide(PILE *p)
{
    return p->sommet == -1 ? 1 : 0;
}

/* Renvoie 1 si la pile est pleine, sinon 0. */
int pilePleine(PILE *p)
{
    return (p->sommet == TAILLEMAX-1) ? 1 : 0;
} 

/* Si la pile n'est pas vide, renvoie le dernier élément et décrémente le sommet. */
int depiler(PILE *p)
{
    if (pileVide(p) == 0) {
        int value = p->pile[p->sommet];
        p->sommet -= 1;
        return value;
    }
}

/* Si la pile n'est pas pleine, incrémente le sommet et ajoute l'élément à la pile. */
int empiler(PILE *p, int elt)
{
    if(pilePleine(p) == 0) {
        p->sommet += 1;
        p->pile[p->sommet] = elt;
        return 1;
    } else {
        return 0;
    }
}

int sommet(PILE *p)
{
    return p->pile[p->sommet];
}

void afficherEtat(PILE *p) {
    printf("\n");
    printf("*État de la pile*\nContenu de la pile: \n");
    for(int i = TAILLEMAX-1; i >= 0; i--) {
        printf("%d : %d\n", i+1, p->pile[i]);
    }
    (pilePleine(p) == 0) ? printf("La pile n'est pas pleine !\n") : printf("La pile est pleine !\n");
    (pileVide(p) == 0) ? printf("La pile n'est pas vide !\n") : printf("La pile est vide !\n");
    printf("\n");
}

/* Menu avec différentes options */
int mainP(int estCree)
{
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


int main()
{

    PILE p;
    int existe = 0;
    int result = -1;
    while (result != 0) {
        result = (existe == 1) ? mainP(1) : mainP(0);
        if (existe == 0) {
            if (result == 1) {
                p.sommet = -1;
                existe = 1;
            }
        } else if (result == 2) {
            int valeur;
            printf("Entrez la valeur à empiler: ");
            scanf("%d", &valeur);
            empiler(&p, valeur) == 1 ? printf("La valeur %d ajoutée à la pile.\n", valeur) : printf("La pile est pleine !\n");
        } else if (result == 3) {
            depiler(&p) == 1 ? printf("Une valeur a été retirée de la pile.\n") : printf("La pile est vide !\n");
        } else if (result == 4) {
            afficherEtat(&p);
        }
    }
    // PILE p; p.sommet = -1; p.TAILLEMAX = 5;
    return 0;
}