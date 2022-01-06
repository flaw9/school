#include <stdio.h>
#include <stdlib.h>

#include "element.c"

struct Cellule {
    Element data;
    struct Cellule *next;
    struct Cellule *prev;
};

typedef struct Cellule Cellule;

typedef Cellule *Liste;
Liste liste_vide = (Liste)NULL