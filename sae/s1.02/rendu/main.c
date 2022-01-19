#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "menu.c"
#include "data.c"

/* Fonction permet de vérifier si le fichier existe et peut être lu. */
int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return true;
    }
    return false;
}


int main(int argc, char *argv[])
{
    /* Vérification du fichier entré en argument :
        - Bon nombre d'arguments (1) ;
        - Fichier existant et autorisé en ouverture ;
    */
    if (argc == 2) {
        if (!exists(argv[1])) {
            printf("Impossible d'ouvrir fichier, vérifiez le nom et réessayez !\n");
            return 0;
        }
    } else if (argc > 2) {
        printf("trop d'arguments !\n");
        return 0;
    } else {
        printf("Pas assez d'arguments !\n");
        return 0;
    }
    
    // Récupération de la commande entrée par l'utilisateur.

    char *file = argv[1];
    Donnees L = readFile(file);
    int result;
    bool showMenu;
    showMenu = true;
    while (result != 4) { // Si le résultat est 4 ou n'est pas un int, on quitte la boucle.
        result = displayMenu(showMenu); // Récupération du résultat.
        showMenu = false;
        switch(result) { // Études des différentes propositions.
            case 0: // 0: On affiche le menu
                showMenu = true;
                break;
            case 1: // 1: On affiche le nombre de naissances
                printf("Nombre total de naissances: %d\n", L.nbNais);
                break;
            case 2: // 2: On affiche le nombre de prénoms
                printf("Nombre total de prénoms: %d\n", Longueur(L.data));
                break;
            case 3: // 3: On affiche les données relatives à un prénom spécifique.
                char prenom[50];
                printf("---| Statistiques par prénom |---\n\nPrénom: ");
                scanf("\n%[^\n ]", prenom);
                printf("Prénom choisi: %s\n", prenom);
                Liste doesExist;
                doesExist = Rechercher(L.data, initPrenom(prenom));
                if(IsVide(doesExist)) {
                    printf("Aucune donnée(s) trouvée(s) pour le prénom '%s' !\n", prenom);
                } else {
                    Prenom prenomDonnee;
                    prenomDonnee = GetContenu(doesExist);
                    int diffSexe = 0;
                    while (diffSexe != 1 && diffSexe != 2) { // On demande à l'utilisateur s'il souhaite avoi les données des deux sexes séparés ou réunis.
                        printf("Voulez-vous différencier les sexes ? (1: Oui, 2: Non): ");
                        scanf("%d", &diffSexe);
                    }
                    if (diffSexe == 1) {
                        printf("Prénom sélectionné: %s\nNombre d'hommes: %d\nNombre de femmes: %d\nPremière année d'apparition: %d\nDernière année d'apparition: %d\n", prenomDonnee.prenom, naissancesHommes(prenomDonnee), naissancesFemmes(prenomDonnee), (prenomDonnee.premiereAnnee == 10000 ? -1 : prenomDonnee.premiereAnnee), (prenomDonnee.derniereAnnee == 0 ? -1 : prenomDonnee.derniereAnnee));
                    } else if (diffSexe == 2) {
                        printf("Prénom sélectionné: %s\nNombre de naissances: %d\nPremière année d'apparition: %d\nDernière année d'apparition: %d\n", prenomDonnee.prenom, naissancesTotal(prenomDonnee), (prenomDonnee.premiereAnnee == 10000 ? -1 : prenomDonnee.premiereAnnee), (prenomDonnee.derniereAnnee == 0 ? -1 : prenomDonnee.derniereAnnee));
                    }
                }
                printf("---| Fin |---\n\n");
                break;
            case 4: // 4: On quitte le programme
                return 0;
                break;
            default: // Traitement des propositions non supportée par le programme (int seulement).
                printf("Instruction inconnue!\n");
                break;
        }
    }
}

/* Comment exécuter le fichier:
    Réunissez dans le même répertoire les fichiers 
    - main.c
    - data.h
    - menu.h
    Et le fichier csv

    Ensuite, il vous suffira de compiler le tout en utilisant la commande

    gcc -o program main.c

    Pour l'exécuter, vous devrez executer le programme en spécifiant le nom du fichier csv tel que :

    ./program <nom_du_fichier>.csv

    ou <nom_du_fichier> est le nom de votre fichier .csv.
 */