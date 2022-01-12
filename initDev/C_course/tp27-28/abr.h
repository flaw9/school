#include "Identite.h"

typedef struct _Node
{
    Identite *id;
    struct _Node *sag;
    struct _Node *sad;
}  Node;

typedef Node *ABR;

extern const ABR arbre_vide; // = (ABR)NULL

// Fonctions sur les Node

// allocation d'un Node
// @param
// id: Identite à stocker
// sag, sad: ABR gauche et droit
// @return
// le Node alloué

extern Node *nodeNew(Identite *id, ABR sag, ABR sag);

// désallocation d'un Node
// @param
// n: Node à libérer
// @return
// (Node *)NULL
// @note : désalloue l'Identite stockée dans le Node
extern Node *nodeDelete(Node *n);

// désallocation d'un ABR
// @param
// a: l'ABR à libérer
// @return arbre_vide
extern ABR abrDelete(ABR a);

// insère une Identite dans un ABR
// @param
// a: l'ABR dans lequel l'insertion est faite
// id: l'Identite à insérer
// @return l'ABR mis à jour
// @note : Une Identite invalide n'est pas insérée et l'ABR est renvoyé sans modification
extern ABR abrInsert(ABR a, Identite *id);

// calcule la taille d'un ABR
// @param
// a: l'ABR dont on veut connaître la taille
// @return la taille de l'ABR
extern unsigned int abrSize(ABR a);

// calcule la hauteur d'un ABR
// @param
// a: l'ABR dont on veut connaître la hauteur
// @return la hauteur de l'ABR
extern unsigned int abrHeight(ABR a);