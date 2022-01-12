#include <stdio.h>    // nécessaire pour printf
#include <stdlib.h> // nécessaire pour malloc et free
#include <time.h>
#include <stdbool.h> // type booléen (bool: true/false)

#include "Element.c"

struct Cellule {
    Element data;
    struct Cellule *next;
    struct Cellule *prev;
};
typedef struct Cellule Cellule;

typedef Cellule *Liste;
Liste liste_vide = (Liste)NULL;

// OPERATIONS SUR LA SORTE
bool EstVide(Liste L) { return L == liste_vide ? true : false; }

Element GetContenu(Liste L) {
    if (EstVide(L))
        return element_invalide;

    return L->data;
}

void Ecraser(Liste L, Element E) {
    if (!EstVide(L) && ElementEstValide(E))
        L->data = E;
}

Liste GetSucc(Liste L) {
    if (EstVide(L))
        return liste_vide;
    return L->next;
}

Liste GetPred(Liste L) {
    if (EstVide(L))
        return liste_vide;
    return L->prev;
}
void SetSucc(Liste L, Liste N) {
    if (!EstVide(L))
        L->next = N;
}

Liste Creer(Element E, Liste L) {
    if (!ElementEstValide(E))
        return liste_vide;
    
    Liste ret = malloc(sizeof(Cellule));
    ret->data = E;
    ret->next = L;
    ret->prev = liste_vide;
    if(!EstVide(L)) L->prev = ret;
    return ret;
}

Liste Detruire(Liste L) {
    if (EstVide(L))
        return liste_vide;
    Liste tmp = GetSucc(L);
    free(L);
    return tmp;
}

// FONCTIONS VUES EN TD
unsigned int Longueur(Liste L) {
    Liste tmpL = L;
    int n = 0;
    while (!EstVide(tmpL)) {
        n++;
        tmpL = GetSucc(tmpL);
    }
    return n;
}

void Afficher(Liste L, bool sens) {
    Liste tempL = L;
    if(EstVide(tempL)) {
        printf("La liste est vide !\n");
    }
    if (sens) {
        while (!EstVide(tempL)) {
            printf("%d;", GetContenu(tempL));
            tempL = GetSucc(tempL);
        }
    } else {
        while (!EstVide(tempL)) {
            tempL = GetSucc(tempL);
        }
        tempL = GetPred(L);
        while(!EstVide(tempL)) {
            printf("%d;", GetContenu(tempL));
            tempL = GetPred(tempL);
        }
    }
    printf("\n");
}

void AfficherPred(Liste L) {
    Liste tmpL = L;
    while (!EstVide(tmpL)) {
        ElementAfficher(GetContenu(tmpL));
        tmpL = GetPred(tmpL);
    }
}

Liste Rechercher(Liste L, Element E) {
    Liste tmpL = L;
    while (!EstVide(tmpL) && !ElementComparer(GetContenu(tmpL), E))
        tmpL = GetSucc(tmpL);
    return tmpL;
}

bool EstDans(Liste L, Element E) { return !(EstVide(Rechercher(L, E))); }

Liste Dernier(Liste L) {
    Liste tmpL = L;
    while (!EstVide(GetSucc(tmpL)))
        tmpL = GetSucc(tmpL);
    return tmpL;
}

void Echange(Liste L1, Liste L2) {
    Element e;
    if(EstVide(L1) || EstVide(L2)) return;
     e = GetContenu(L1);
     Ecraser(L1, GetContenu(L2));
     Ecraser(L2, e);
}

Liste imin(Liste L) {
    Liste tmpL = L;
    Liste tamp = tmpL;
    while(!EstVide(tmpL)){ 
        if(GetContenu(tamp) > GetContenu(tmpL))
            tamp = tmpL;
        tmpL = GetSucc(tmpL);
    }
    return tamp;
}
void TriBulle(Liste L) {
    Liste tmpL = L;
    bool sorted = true;
    Liste alrs;
    while(sorted) {
        sorted = false;
        while(!EstVide(GetSucc(L))) {
            if (GetContenu(L) > GetContenu(GetSucc(L))) {
                Element tempE; tempE = GetContenu(L);
                Ecraser(L, GetContenu(GetSucc(L)));
                Ecraser(GetSucc(L), tempE);
                sorted = true;
            }
            L = GetSucc(L);
        }
        while(!EstVide(GetPred(L))) {L = GetPred(L);}
    }
}

void TriSelection(Liste L){
    while (!EstVide(L)){
        Echange(L,imin(L));
        L = GetSucc(L);
        }
}

void TriInsertion(Liste L){
    TriBulle(L);
}

Liste Supprimer(Liste L, int r) {
    if (r == 0 || EstVide(L))
        return Detruire(L);

    int i = 0;
    Liste tmpL = L;
    while (!EstVide(GetSucc(tmpL)) && i < r - 1) {
        tmpL = GetSucc(tmpL);
        i++;
    }
    SetSucc(tmpL, Detruire(GetSucc(tmpL)));
    return L;
}

Liste Concatener(Liste L1, Liste L2) {
    if (EstVide(L1))
        return L2;
    if (!EstVide(L2))
        SetSucc(Dernier(L1), L2);
    return L1;
}

Liste Ajouter(Liste L, Element E, int r) {
    if (!ElementEstValide(E))
        return L;
    if (r == 0 || EstVide(L) == true)
        return Creer(E, L);
    int i = 0;
    Liste tmpL = L;
    while (!EstVide(GetSucc(tmpL)) && i < r - 1) {
        tmpL = GetSucc(tmpL);
        i++;
    }
    SetSucc(tmpL, Creer(E, GetSucc(tmpL)));
    return L;
}

Liste Inverser(Liste L) {
    Liste Linv = liste_vide;
    Liste tmpL = L;
    while (!EstVide(tmpL)) {
        Linv = Creer(GetContenu(tmpL), Linv);
        tmpL = GetSucc(tmpL);
    }
    return Linv;
}

Liste Copier(Liste L) {
    Liste Lcopie = Creer(GetContenu(L), liste_vide);
    Liste tmpL = GetSucc(L), tmpC = Lcopie;
    while (!EstVide(tmpL)) {
        SetSucc(tmpC, Creer(GetContenu(tmpL), liste_vide));
        tmpC = GetSucc(tmpC);
        tmpL = GetSucc(tmpL);
    }
    return Lcopie;
}

Liste Vider(Liste L) {
    while (!EstVide(L))
        L = Detruire(L);
    return L;
}

int displayMenu(bool listeExiste, bool displayMenu)
{
        if(displayMenu) {
            if(listeExiste) {
                    printf("-----\n");
                    printf("0: Quitter\n");
                    printf("2: Tri à bulles\n");
                    printf("3: Tri par insertion.\n");
                    printf("4: Tri par sélection.\n");
                    printf("5: Afficher la liste.\n");
                    printf("6: Afficher ce menu.\n");
                    printf("-----\n");
            } else {
                    printf("-----\n");
                    printf("0: Quitter\n");
                    printf("1: Créer la liste\n");
                    printf("6: Afficher ce menu.\n");
                    printf("-----\n");
            }
        }
        printf("Instruction (6 pour afficher le menu): ");
        int request;
        scanf("%i", &request);
        return request;
}

int main() {
    Liste L = liste_vide;
    int result;
    bool listeExiste = false; bool afficherMenu = true;
    while (result != 0) {
        result = displayMenu(listeExiste, afficherMenu);
        afficherMenu = false;
        if (!listeExiste && result != 1) {
            printf("Vous devez d'abord créer une liste !\n");
        } else if (listeExiste && result == 1) {
            printf("Une liste existe déjà !\n");
        } else {
            switch(result) {
                case 1:
                    if (!listeExiste) {
                        int size = 10;
                        long d; time(&d); srand(d);
                        int e;
                        for(int i = 0; i < size; i++) {
                            e = rand() % 100;
                            L = Creer(e,L);
                        }
                        listeExiste = true;
                        afficherMenu = true;
                        break;
                    }
                case 2:
                    TriBulle(L);
                    break;
                case 3:
                    TriInsertion(L);
                    break;
                case 4:
                    TriSelection(L);
                    break;
                case 5:
                    Afficher(L, true);
                    Afficher(L, false);
                    break;
                case 6:
                    afficherMenu = true;
                default:
                    break;
            }
        }
    }
}