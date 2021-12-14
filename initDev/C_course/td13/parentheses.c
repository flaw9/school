#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pile {
    int pile[50];
    int sommet;
};
typedef struct pile PILE;

/* Renvoie 1 si la pile est vide, sinon 0. */
int pileVide(PILE p)
{
    return p.sommet == -1 ? 1 : 0;
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
void empiler(PILE *p, int elt)
{
    p->sommet += 1;
    p->pile[p->sommet] = elt;
}

int main()
{
    char ch;
    PILE p;
    p.sommet = -1;
    do {
        ch = getchar();
        if (ch == '(') {
            empiler(&p, 1);
        } else if(ch == ')') {
            (depiler(&p) == -1) ? printf("Plus aucune parenthèse à fermer !\n") : NULL;
        }
    } while (ch != '\n');
    (pileVide(p)) ? printf("La syntaxe est correcte !\n") : printf("Il y a %i parenthèses incorrectes.");
    return 0;
}