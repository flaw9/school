#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Prénom */

// Structure contenant les informations qu'on souhaite réutiliser par la suite 
struct Prenom {
	char prenom[26]; // La chaîne contenant le prénom
	long int nbHommes; // Le nombre d'hommes
	long int nbFemmes; // Le nombre de femmes
	int premiereAnnee; // La première année ou ce prénom est apparu
	int derniereAnnee; // La dernière année ou ce prénom est apparu
};

typedef struct Prenom Prenom;

/* Fonction qui permet d'initialiser une structure prénom. */
Prenom initPrenom(char *prenom) {
	Prenom p;
	strcpy(p.prenom, prenom);
	p.nbHommes = 0;
	p.nbFemmes = 0;
	p.premiereAnnee = 10000;
	p.derniereAnnee = 0;

	return p;
}

int naissancesHommes(Prenom p) {
	return p.nbHommes;
}

int naissancesFemmes(Prenom p) {
	return p.nbFemmes;
}

int naissancesTotal(Prenom p) {
	return (p.nbHommes + p.nbFemmes);
}

bool PrenomComparer(Prenom p1, Prenom p2) {
	return strcmp(p1.prenom, p2.prenom) == 0;
}

/* Liste */

struct Cellule {
	Prenom data;
	struct Cellule *next;
};
typedef struct Cellule Cellule;

typedef Cellule *Liste;
Liste liste_vide = (Liste)NULL;

bool IsVide(Liste L) {
	return L == liste_vide ? true : false;
} // simple comparaison de pointeurs. Usage de l'opérateur ternaire.

Prenom GetContenu(Liste L) {
	return L->data;
}

Liste SetContenu(Liste L, Prenom p) {
	L->data = p;
	return L;
}

Liste GetSucc(Liste L) {
	if (IsVide(L)) 
	return liste_vide;
	return L->next;
}

Liste Creer(Liste L, Prenom p) {
	Liste ret = malloc(sizeof(Cellule)); // 1llocation de la mémoire pour stocker une Cellule.
	ret->data = p; // On stocke les données.
	ret->next = L; // On place la nouvelle cellule en tête de liste.
	return ret;	// On renvoie la nouvelle liste (la tête a changé).
}

unsigned int Longueur(Liste tempL) {
	int n = 0;
	while (!IsVide(tempL)) {
		n++;
		tempL = GetSucc(tempL);
		// On incrémente le compteur tant que L a un successeur.
	}
	return n;
}

/* Cherche un élément dans la liste, si on ne le trouve pas, renvoie une liste vide. */
Liste Rechercher(Liste L, Prenom p) {
	while (!IsVide(L) && !PrenomComparer(GetContenu(L), p)) { // On continue de parcourir la liste jusqu'à temps qu'on trouve l'élément E ou qu'on arrive à la fin de la liste.
		L = GetSucc(L);
	}
	return L;
}

/* On regarde si un élément donné est dans la liste */
bool IsDans(Liste L, Prenom p) {
	return !(IsVide(Rechercher(L, p)));
}

/* On regarde si un prénom est dans la liste. */
bool prenomDedans(Liste L, char *prenom) {
	Prenom p = initPrenom(prenom);
	return IsDans(L, p);
}

/* Fonction qui compare les années enregistrées avec celles stockées dans la structure prénom de la Liste entrée en paramètre. */
void comparerAnnees(Liste L, char annee[5]) {
	if (annee[0] != 'X') {
		char vraieAnnee[4];
		vraieAnnee[0] = annee[0];
		vraieAnnee[1] = annee[1];
		vraieAnnee[2] = annee[2];
		vraieAnnee[3] = annee[3];
		int k;
		sscanf(vraieAnnee, "%d", &k);
		if (k > L->data.derniereAnnee) {
			L->data.derniereAnnee = k;
		}
		if (k < L->data.premiereAnnee) {
			L->data.premiereAnnee = k;
		}
	}
}


/* Donnees */

struct Donnees {
    long int nbNais;
    Liste data;
};

typedef struct Donnees Donnees;

/* Fonction principale qui lit le fichier et renvoie une structure Donnees contenant:
- Le nombre total de naissances ;
- La liste de toutes les structures prénoms et leur contenu.
 */
Donnees readFile(const char *filename)
{
    Donnees toReturn;
    toReturn.nbNais = -1;
    FILE *file;
    file = fopen(filename,"r"); // Ouverture du fichier csv
    
    if(file != NULL){
        Liste L = liste_vide;
        Liste tempL = liste_vide;
        int totNais;
        totNais = 0;
        int sexe;
        char prenom[26];
        char annee[5];
        char dpt[5];
        int nbNais;
        char titres[100];
		printf("Lecture des données en cours ...\n");
		// On lit le contenu du fichier ligne par ligne (sexe, prenom, annee, dpt, nbNais) et on isole la première ligne.
        fscanf(file, "%s", titres);
        while(fscanf(file, "%ld;%[^;];%[^;];%[^;];%d", &sexe, prenom, annee, dpt, &nbNais) != EOF){
            // printf("Annee: %s ; Prenom: %s ; Nb de naissances: %d\n", annee, prenom, nbNais);
			Prenom p = initPrenom(prenom);
			/*
				Prénom actuel / Prénom existe: On complète
				Sinon: Nouveau prénom + création
			*/
			if (IsVide(L) || !prenomDedans(L, prenom)) {
				L = Creer(L, p);
				tempL = liste_vide; // On remet à zéro la Liste temporaire puisqu'un nouveau prénom apparaît.
			}
			else if (!PrenomComparer(GetContenu(L), p)) {
				tempL = Rechercher(L, p); // On utilise une Liste temporaire afin de ne pas perdre la tête de la Liste.
			}

			p = IsVide(tempL) ? L->data : tempL->data;

			if (sexe == 1) {
				p.nbHommes += nbNais;
			} else {
				p.nbFemmes += nbNais;
			}

			SetContenu(L, p);

			comparerAnnees(L, annee);

            totNais += nbNais;
        }
        fclose(file);
        toReturn.nbNais = totNais;
        toReturn.data = L;

		// printf("Dernier prénom enregistré: '%s'\n", GetContenu(L).prenom);

		printf("Lecture des données finie !\n\n");
	}
	return toReturn;
}
