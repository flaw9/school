#include "identite.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    if (!nom || !prenom) return (Identite *)NULL;
    Identite *ret = malloc(sizeof(Identite));
    if (ret)
    {
        ret->nom = strdup(nom);
        ret->prenom = strdup(prenom);
    }
    return ret;
}

// libération mémoire d'une Identite
// @paam
// id: l'Identite à libérer
// @return (Identite *)NULL
// fonctionne même si id, id->nom ou id->prenom sont nuls
Identite *identiteDelete(Identite *id)
{
    if (id)
    {
        if (id->nom) free(id->nom);
        if (id->prenom) free(id->prenom);
        free(id);
    }
    return (Identite *)NULL;
}

// vérifie la validité d'une Identite
// @param
// id: l'Identite à vérifier
// @return
// false si l'Identite est invalide, càd id->nom ou id->prenom est NULL
// true sinon
bool identiteIsValid(Identite *id)
{
    return id && id->nom && id->prenom ? true : false;
}

// affiche une Identite sous la forme
// "Nom: <nom> ; Prenom: <prenom>"
// @param
// id: l'Identite à afficher
// @return Rien
// @note affiche "Identite invalide" si l'Identite est invalide
void identitePrint(Identite *id)
{
    if (identiteIsValid(id))
        printf("Nom: %s ; Prenom: %s\n", id->nom, id->prenom);
    else
        printf("Identite invalide\n");
}

// compare deux Identites
// @param
// a,b : les Identites à comparer
// @return
// - une valeur négative si a vient avant b
// - 0 si a=b
// - une valeur positive si a vient après b
// une Identite inalide vient avant toute autre
// deux Identite invalides sont égales
int identiteCmp(Identite *a, Identite *b)
{
    if (identiteIsValid(a))
    {
        if (identiteIsValid(b))
        {
            int cn = strcmp(a->nom, b->nom); // évite un double appel à strcmp
            return cn ? cn : strcmp(a->prenom, b->prenom);
        }
    // a est valide et b est invalide
    return 1;
    }
    if (identiteIsValid(b)) return -1; // a invalide, b valide
    return 0; // a invalide, b invalide
}
