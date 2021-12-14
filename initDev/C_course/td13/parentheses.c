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

void checkSyntax(char *str) {
    char ch;
    PILE p;
    p.sommet = -1;
    for(int i = 0; i < strlen(str); i++) {
        ch = str[i];
        if (ch == '(') {
            empiler(&p, 1);
        } else if(ch == ')') {
            if (depiler(&p) == -1){
                printf("Incorrect !\n");
            }
        }
    }
    (pileVide(p)) ? printf("Correct !\n") : printf("Incorrect !\n");
}


int main()
{
    // char ch;
    // PILE p;
    // p.sommet = -1;
    // do {
    //     ch = getchar();
    //     if (ch == '(') {
    //         empiler(&p, 1);
    //     } else if(ch == ')') {
    //         if (depiler(&p) == -1){
    //             printf("Incorrect !\n");
    //             return 0;
    //         }
    //     }
    // } while (ch != '\n');
    // (pileVide(p)) ? printf("Correct !\n") : printf("Incorrect !\n");
    checkSyntax("(((()()))()");
    return 0;
}