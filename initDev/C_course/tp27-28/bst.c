#include "abr.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    ABR a = abrReadFromCSV(argv[1]);
    printf("Taille: %u, hauteur: %u\n", abrSize(a), abrHeight(a));
    abrLNR(a, identitePrint);
    a = abrDelete(a);
    return 0;
}
