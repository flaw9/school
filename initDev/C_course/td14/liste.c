// PAS TOUT FINIS , J'AVAIS LA FLEMME 

// déclaration des fonctions externes
#include <stdio.h>  // nécessaire pour printf
#include <stdlib.h> // nécessaire pour malloc et free

// DEFINITION D'UN TYPE BOOLEEN
#include <stdbool.h> // type booléen (bool: true/false)

// Définit un type Element, ainsi que
// - la constante element_invalide
// - 3 opérations (fonctions):
//   - bool ElementEstValide(Element E): renvoie true si E est valide, faux
//   sinon
//   - void ElementAfficher(Element E): affiche E, gère le cas où E est invalide
//   - bool ElementComparer(Element E1, Element E2): renvoie true si E1 et E2
//   sont égaux, faux sinon
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
bool EstVide(Liste L) { return L == liste_vide ? true : false; }

Element GetContenu(Liste L) {
  if (EstVide(L))
    return element_invalide;

  return L->data;
}

void SetContenu(Liste L, Element E) {
  if (!EstVide(L) && ElementEstValide(E))
    L->data = E;
}

Liste GetSucc(Liste L) {
  if (EstVide(L))
    return liste_vide;
  return L->next;
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
// principe de récursivité :
// la liste_vide a une longueur nulle
// la longueur d'une liste non vide est 1 + la longueur de la liste
// qui débute au successeur
unsigned int Longueur(Liste L) {
  return EstVide(L) ? 0 : 1+Longueur(GetSucc(L));
}

// principe de récursivité. 
// Si la liste est vide, on ne fait rien
// Sinon, on affiche l'élément stocké en tête de liste, et on affiche la suite
void Afficher(Liste L) {
  if (!EstVide(L))
  {
    ElementAfficher(GetContenu(L));
    Afficher(GetSucc(L));
  }
}
//principe de récursivité
// si la liste est vide ou si l'élément stocké en tête de liste est
// celui recherché, renvoyer la liste courante
// sinon renvoyé le résultat de la recherche dans la liste débutant
// au successeur
Liste Rechercher(Liste L, Element E) {
  return (EstVide(L) || ElementComparer(GetContenu(L), E)) ? L : Rechercher(GetSucc(L),E);
}

bool EstDans(Liste L, Element E) { return !(EstVide(Rechercher(L, E))); }

// principe de récursivité
// si la liste ou son successeur est vide, renvoyer la liste
// sinon renvoyer le dernier de la liste débutant au successeur
// On utilise le fait que GetSucc renvoie la liste vide si la liste ou son 
// successeur est vide
Liste Dernier(Liste L) {
  return EstVide(GetSucc(L)) ? L : Dernier(GetSucc(L));
}
// principe de récursivité
// si la liste est vide, on renvoie liste vide
// si le rang est 0, on détruit la première cellule et on renvoie la suivante
// ces deux cas sont traités par un appel à Detruire(L), comme dans la version itérative
// sinon, on supprime l'élément de rang r-1 dans la liste débutant au successeur
Liste Supprimer(Liste L, int r) {
  if (r == 0 || EstVide(L))
    return Detruire(L);
  SetSucc(L,Supprimer(GetSucc(L),r-1));
  return L;
}
// ici, pas de boucle, donc pas de récursivité intéressante.
// On fait appel à Dernier, implémentée de manière récursive
Liste Concatener(Liste L1, Liste L2) {
  if (EstVide(L1))
    return L2;
  if (EstVide(L2) == false)
    SetSucc(Dernier(L1), L2);
  return L1;
}

// principe de récursivité.
// similaire à Supprimer. On ajoute en tête si le rang est nul ou la liste est vide,
// sinon, on ajoute dans la liste commençant au successeur, avec le rang r-1
Liste Ajouter(Liste L, Element E, int r) {
  if (ElementEstValide(E) == false)
    return L;
  if (r == 0 || EstVide(L) == true)
    return Creer(E, L);
  SetSucc(L, Ajouter(GetSucc(L),E,r-1));
  return L;
}

// principe de récursivité: dans cette version, il n'y a pas recopie des cellules de la liste,
// mais une inversion "sur place". La liste originale n'existe donc plus.
// Si la liste est vide ou a une seule cellule, on renvoie la liste
// Sinon, la liste a au moins deux cellules.
// on commence par inverser la liste qui commence à la deuxième 
// et on stocke le résultat dans la liste Linv
// ensuite, on place L à la fin de Linv. 
// La difficulté à éviter est qu'il faudrait a priori appeler Dernier pour
// récupérer la dernière cellule de Linv. 
// Mais une anayse fine nous permet d'éviter ça. Suivez, car c'est subtil:
// comme on n'a pas modifié la première cellule (L), le champ next contient 
// l'adresse la cellule qui, après inversion du reste, se retrouve en dernière position
// dans Linv. Donc pas besoin de la déterminer en appelant Dernier !
// Voyons ça sur un exemple.
// L est ma liste qui contient les cellules successives
// L -> 1 -> 2 -> 3 -> 4 -> null
// on inverse à partir de 2 pour obtenir Linv. Ca donne
// L -> 1 -> 2 <- 3 <- 4 <- Linv
// et même plus précisément, comme on n'a pas modifié le successeur de la dernière cellule
// L -> 1 -> 2 <-> 3 <- 4 <- Linv
// on peut alors faire
// s= GetSucc(L)  // s pointe vers 2
// SetSucc(s,L) 
// on inverse la flèche entre 2 et 1, et ce faisant on retire la flèche allant de 2 vers 3, 
// ce qui donne
// L -> 1 <-> 2 <- 3 <- 4 <- Linv
//(on a une double flèche entre 1 et 2 car on n'a pas modifié L)
// il suffit alors d'indiquer que L est la dernière cellule de la liste inversée
// SetSucc(L,liste_vide)
// ce qui donne
// null <- 1 <- 2 <- 3 <- 4 <- Linv
// on renvoie alors Linv
Liste Inverser(Liste L) {
  if (EstVide(GetSucc(L))) return L; // liste vide ou à un seul élément
  // on inverse le reste de la liste
  Liste Linv = Inverser(GetSucc(L));
  // comme on n'a pas modifié L, GetSucc(L) indique le dernier élément de Linv.
  // on va donc pouvoir y placer L
  SetSucc(GetSucc(L),L);
  // puis on indique que L est la dernière cellule
  SetSucc(L,liste_vide);

  return Linv;
}

// principe de récursivité
// si la liste est vide, on ne fait rien
// sinon on crée une liste avec le premier élément comme contenu
// et comme successeur le résultat de la copie de la suite de la liste
Liste Copier(Liste L) {
  return EstVide(L) ? L : Creer(GetContenu(L), Copier(GetSucc(L)));
}

// principe de récursivité
// si la liste est vide, on ne fait rien, on la renvoie
// sinon, on detruit la cellule et on vide le sucesseur
Liste Vider(Liste L) {
  return EstVide(L) ? L : Vider(Detruire(L));
}

// EXEMPLE DE MAIN
int main(int argc, char *argv[]) {
  // création et affichage

  int i;
  Liste L = liste_vide;
  for (i = 1; i < argc; i++) {
    Element E = ElementLire(argv[i]);
    L = Ajouter(L, E, 0); // gère le cas où E est invalide
  }

  // test de Longueur
  printf("La longueur de la liste est : %d\n", Longueur(L));

  // Afficher
  printf("Affichage de la liste\n");
  Afficher(L);

  // Ajouter
  printf("Ajout au début\n");
  L = Ajouter(L, (Element)123.4, 0);
  Afficher(L);

  printf("Ajout au milieu\n");
  unsigned int len = Longueur(L);
  if (len >= 2) {
    L = Ajouter(L, (Element)42.36, len / 2);
    Afficher(L);
    len++; // on incrémente pour ne pas avoir à recalculer la longueur,
           // nécessaire pour ajouter un élément à la fin
  } else
    printf("La liste doit avoir au moins deux éléments pour une insertion "
           "entre deux éléments existants\n");

  printf("Ajout en fin de liste\n");
  L = Ajouter(L, (Element)98.76, len);
  Afficher(L);

  printf("Ajouter après la fin de la liste\n");
  L = Ajouter(L, (Element)10.10, len + 100);
  Afficher(L);

  // Supprimer
  len = Longueur(L);
  if (len > 2) // devrait toujours être vrai, vu ce qui précède...
  {
    printf("Suppression élément milieu\n");
    L = Supprimer(L, len / 2);
    Afficher(L);
  } else
    printf(
        "La liste n'est pas assez longue pour supprimer un élément médian\n");

  printf("Suppression élément après la fin\n"); // ne doit rien faire !
  L = Supprimer(L, len + 10);
  Afficher(L);

  printf("Suppression dernier élément\n");
  L = Supprimer(L, Longueur(L) - 1); // dernier élément => rang=Longueur(L)-1
  Afficher(L);

  printf("Suppression premier élément\n");
  L = Supprimer(L, 0);
  Afficher(L);

  // Copier
  printf("Copier\n");
  Liste Lcopie = Copier(L);
  Afficher(Lcopie);

  // Inverser
  printf("Inverser\n");
  L = Inverser(L); // inversion sur place, il faut donc mettre à jour L
  Afficher(L);

  // Vider
  printf("Vider\n");
  L = Vider(L);
  Lcopie = Vider(Lcopie);
  if (EstVide(L) == false)
    Afficher(L);
  else
    printf("Liste vide\n");
  // inutile d'afficher autre chose car on vérifie juste ici que Vider renvoie
  // bien la liste vide...

  return 0;
}
