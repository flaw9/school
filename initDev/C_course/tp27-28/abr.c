#include "abr.h"
#include <stdio.h>
#include <stdlib.h>

const ABR arbre_vide; // = (ABR)NULL

// Fonctions sur les Node

// allocation d'un Node
// @param
// id: Identite à stocker
// sag, sad: ABR gauche et droit
// @return
// le Node alloué

Node *nodeNew(Identite *id, ABR sag, ABR sad)
{
    if (!identiteIsValid(id)) return (Node *)NULL;
    Node *ret = malloc(sizeof(Node));
    if (ret) {
        ret->id = id;
        ret->sag = sag;
        ret->sad = sad;
    }

    return ret;
}
// désallocation d'un Node
// @param
// n: Node à libérer
// @return
// (Node *)NULL
// @note : désalloue l'Identite stockée dans le Node
Node *nodeDelete(Node *n)
{
    if (n) {
        identiteDelete(n->id);
        free(n);
    }
}

// désallocation d'un ABR
// @param
// a: l'ABR à libérer
// @return arbre_vide
ABR abrDelete(ABR a)
{
    if (a)
    {
        a->sag = abrDelete(a->sag);
        a->sad = abrDelete(a->sad);
        nodeDelete(a);
    }
    return arbre_vide;
}

// insère une Identite dans un ABR
// @param
// a: l'ABR dans lequel l'insertion est faite
// id: l'Identite à insérer
// @return l'ABR mis à jour
// @note : Une Identite invalide n'est pas insérée et l'ABR est renvoyé sans modification
ABR abrInsert(ABR a, Identite *id)
{
    return arbre_vide;
}

// calcule la taille d'un ABR
// @param
// a: l'ABR dont on veut connaître la taille
// @return la taille de l'ABR
unsigned int abrSize(ABR a)
{
    if (!a) return 0;
    if (!a->sad && !a->sag) {
        return 1;
    }
    return 1 + abrSize(a->sad) + abrSize(a->sag);
}

// calcule la hauteur d'un ABR
// @param
// a: l'ABR dont on veut connaître la hauteur
// @return la hauteur de l'ABR
unsigned int abrHeight(ABR a)
{
    return 0;
}
/*
abrLNR (Left Node Right) (infixe)
NLR (prefixe)
LRN (postfixe)
*/

// parcours en profondeur d'abord, ordre infixe
// @param
// a: l'ABR à parcourir
// f: fonction à appliquer à chaque Node
// @return None
void abrLNR(ABR a, void (*f)(Identite *))
{
    printf("None\n");
}

// lis les Identites d'un fichier CSV
// et les stocke dans un ABR
// @param
// fname: nom du fichier à lire
// @return
// un ABR
ABR abrReadFromCSV(char *fname){
    return arbre_vide;
}