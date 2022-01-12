#include "Identite.h"
#include <stdlib.h>
#include <stdbool.h>

// allocation d'une Identite
// @param
// nom, prenom : chaînes de caractère qui seront stockées
// @return
// la nouvelle Identite
// renvoie(Identite *)NULL si om ou prenom sont des pointeurs invalides ou en cas d'échec d'allocation mémoire
// @note
// nom et prenom sont copiés par deep copy
Identite *identiteNew(char *nom, char *prenom)
{
    if(!nom || !prenom) return (Identite *)NULL;
    Identite *ret = malloc(sizeof(Identite));
}

// libération mémoire d'une Identite
// @paam
// id: l'Identite à libérer
// @return (Identite *)NULL
// fonctionne même si id, id->nom ou id->prenom sont nuls
extern Identite *identiteDelete(Identite *id);

// vérifie la validité d'une Identite
// @param
// id: l'Identite à vérifier
// @return
// false si l'Identite est invalide, càd id->nom ou id->prenom est NULL
// true sinon
extern bool identiteIsValid(Identite *id);

// affiche une Identite sous la forme
// "Nom: <nom> ; Prenom: <prenom>"
// @param
// id: l'Identite à afficher
// @return Rien
// @note affiche "Identite invalide" si l'Identite est invalide
extern void identitePrint(Identite *id);

// compare deux Identites
// @param
// a,b : les Identites à comparer
// @return
// - une valeur négative si a vient avant b
// - 0 si a=b
// - une valeur positive si a vient après b
// une Identite inalide vient avant toute autre
// deux Identite invalides sont égales
extern int identiteCmp(Identite *a, Identite *b);
