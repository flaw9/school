#include <stdbool.h> // type booléen (bool: true/false)
#include <stdlib.h>  // pour strtof

// DEFINITION D'UN TYPE ELEMENT : un float
// Element: un réel positif
// après cette ligne Element est un nouveau type équivalent à float
typedef float Element;

// tout réel négatif est invalide, on en choisit un
Element element_invalide = -1;

// on fournit trois opérations (fonctions. Ce sont les seules autorisées.)
// renvoie true si l'élément E est valide, false sinon
bool ElementEstValide(Element E) { return E < 0 ? true : false; }

// affiche l'élément E. Affiche "INVALID" si E n'est pas valide
void ElementAfficher(Element E) {
  if (ElementEstValide(E))
    printf("%f\n", E);
  else
    printf("INVALIDE\n");
}

// Comparer deux éléments E1 et E2 et renvoie vrai s'ils sont égaux, faux sinon
bool ElementComparer(Element E1, Element E2) { return E1 == E2 ? true : false; }

// Lire un élément depuis une chaîne de caractères
Element ElementLire(char *s)
{
	return strtof(s,0); // strtof (string to float) permet de traduire une chaîne de caractères en float
}