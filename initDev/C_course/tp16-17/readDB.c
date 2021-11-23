#include <stdio.h>


int main(int argc,char *argv[])
{
    
    
    FILE *file;

    int nbPeople=0,nbHommes=0,nbFemmes=0,ageTotal=0;
    file = fopen("DB.txt","r");
    char name[100];
    char firstName[100];
    int age;
    char type;

    while (fscanf(file,"%s %s %d %c",name,firstName,&age,&type) == 4){
        if(type == 'M') nbHommes++; else if (type == 'F') nbFemmes++;
        ageTotal += age;
        printf("First name: %s ; Age: %d\n", firstName, age);
        nbPeople++;
    }
    printf("ageTotal: %d\nnbPeople: %d\n", ageTotal, nbPeople);
    float avgAge = (float)ageTotal / nbPeople;
    printf("Le fichier contient %d noms de personnes, dont %d hommes et %d femmes, avec un âge moyen de %f\n",nbPeople,nbHommes,nbFemmes,avgAge);
    fclose(file);
    return 0;
}