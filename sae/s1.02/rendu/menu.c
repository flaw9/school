/* Fonction qui affiche le menu si le booléen est vrai, et qui récupère la commande entrée par l'utilisateur afin de la renvoyer. */
int displayMenu(bool showMenu)
{
    if(showMenu) {
        printf("-----\n");
        printf("0: Afficher ce menu\n");
        printf("1: Nombre de naissances\n");
        printf("2: Nombre de prénoms\n");
        printf("3: Statistiques sur un prénom.\n");
        printf("4: Quitter.\n");
        printf("-----\n");
    }
    printf("Instruction (0 pour afficher le menu): ");
    int request;
    scanf("%i", &request);
    return request;
}
