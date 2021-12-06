// déclaration des fonctions externes
#include <stdio.h>  // nécessaire pour printf
#include <stdlib.h> // nécessaire pour malloc et free

// DEFINITION D'UN TYPE BOOLEEN
#include <stdbool.h> // type booléen (bool: true/false)

// Définit un type Element, ainsi que
// - la constante element_invalide
// - 4 opérations (fonctions):
//   - bool ElementEstValide(Element E): renvoie true si E est valide, faux
//   sinon
//   - void ElementAfficher(Element E): affiche E, gère le cas où E est invalide
//   - bool ElementComparer(Element E1, Element E2): renvoie true si E1 et E2
//   sont égaux, faux sinon
//   - Element ElementLire(char *s): lit un élément à partir d'une chaîne de
//   caractères
#include "Element.c"

// DEFINITION DES SORTES POUR LA LISTE CHAINEE
// La cellule
struct Cellule {
  Element data;
  struct Cellule *next;
};
typedef struct Cellule Cellule;

// la liste
typedef Cellule *Liste;
Liste liste_vide = (Liste)NULL;

// OPERATIONS SUR LA SORTE
bool EstVide(Liste L) {
  return L == liste_vide ? true : false;
} // simple comparaison de pointeurs. Usage de l'opérateur ternaire.

Element GetContenu(Liste L) {
  if (EstVide(L)) // on suit la spécification de comportement pour la liste vide
    return element_invalide;
  return L->data;
}

void SetContenu(Liste L, Element E) {
  if (!EstVide(L) && ElementEstValide(E))
    // modification uniquement si élément valide et liste non vide
    // (évite un segmentation fault lors du L->data qui suit)
    L->data = E;
}

Liste GetSucc(Liste L) {
  if (EstVide(L)) // on suit la spécification de comportement pour la liste vide
    return liste_vide;
  return L->next;
}

void SetSucc(Liste L, Liste N) {
  if (!EstVide(L)) // modification uniquement si liste non vide (évite un
                   // segmentation fault lors du L->next qui suit)
    L->next = N;
}

Liste Creer(Element E, Liste L) {
  if (!ElementEstValide(E)) // cas de l'élément invalide : on ne crée rien car
                            // on ne peut pas le stocker
    return liste_vide;

  Liste ret = malloc(sizeof(Cellule)); // allocation de la mémoire pour stocker
                                       // une cellule (Liste=Cellule*)
  ret->data = E; // stockage de E. Rappel: le type Liste est un pointeur, donc
                 // ret->data <=> (*ret).data
  ret->next = L; // on place la nouvelle cellule en tête de liste
  return ret;    // on renvoie la nouvelle liste (la tête a changé)
}

Liste Detruire(Liste L) {
  if (EstVide(L)) // on suit la spécification si la liste est vide
    return liste_vide;
  Liste tmp = GetSucc(L); // mise en mémoire tampon de la suite de la liste, qui
                          // sera renvoyée par la fonction
  free(L);    // on peut libérer la mémoire de L sans problème. L n'est plus
              // accessible
  return tmp; // on renvoie le pointeur L->next gardé en mémoire
}

// FONCTIONS VUES EN TD:
unsigned int Longueur(Liste L) {
  int n = 0;
  while (!EstVide(L)) {
    n++;
    L = GetSucc(L);
    // On incrémente le compteur tant que L a un successeur.
  }
  return n;
}

void Afficher(Liste L) {
  while (!EstVide(L)) {
    ElementAfficher(GetContenu(L));
    L = GetSucc(L);
  }
}

Liste Rechercher(Liste L, Element E) {
  while (!EstVide(L) && !ElementComparer(GetContenu(L), E)) { // On continue de parcourir la liste jusqu'à temps qu'on trouve l'élément E ou qu'on arrive à la fin de la liste.
    L = GetSucc(L);
  }
  return L;
}

bool EstDans(Liste L, Element E) {& return !(EstVide(Rechercher(L, E))); }

Liste Dernier(Liste L) {
  while (!EstVide(GetSucc(L))) {
    L = GetSucc(L);
  }
  return L;
}

Liste Supprimer(Liste L, int r) {
  if (r = 0 || EstVide(L))
    return Detruire(L);
  
  int i = 0;
  while (!EstVide(GetSucc(L)) && i < r-1) {
    L = GetSucc(L);
    i++;
  }
}

// Liste Concatener(Liste L1, Liste L2) {}

// Liste Ajouter(Liste L, Element E, int r) {}

// Liste Inverser(Liste L) {}

// Liste Copier(Liste L) {}

// Liste Vider(Liste L) {}

// EXEMPLE DE MAIN
int main(int argc, char *argv[]) {
  // création et affichage

  int i;
  Liste L = liste_vide;
  for (i = 1; i < argc; i++) {
    Element E = ElementLire(argv[i]);
    L = Creer(E, L); // gère le cas où E est invalide
  }
  return 0;
}
