#include <stdio.h>


int main(int argc,char *argv[])
{   
    FILE *file;

    int nbPeople=0,nbHommes=0,nbFemmes=0,ageTotal=0; // Initialisation des variables qui serviront à compter.
    file = fopen("DB.txt","r"); // Ouverture du fichier dans une liste.
    char name[100]; char firstName[100]; int age; char type; // Initialisation des variables qui serviront à séparer en plusieurs champs les lignes.

    while (fscanf(file,"%s %s %d %c",name,firstName,&age,&type) == 4){ // On parcours le fichier ligne par ligne.
        if(type == 'M') nbHommes++; else if (type == 'F') nbFemmes++; // Incrémentation du compteur correspondant au sexe de l'individu.
        ageTotal += age; nbPeople++; // Incrémentation des variables nécessaires au calcul de l'âge moyen.
    }
    float avgAge = (float)ageTotal / nbPeople; // Calcul de l'âge moyen
    printf("Le fichier contient %d noms de personnes, dont %d hommes et %d femmes, avec un âge moyen de %f\n",nbPeople,nbHommes,nbFemmes,avgAge);
    fclose(file);
    return 0;
}