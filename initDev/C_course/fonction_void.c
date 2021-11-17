#include <stdio.h>

void message(char t[], char s[]) {
    printf("Message (%s) : %s\n", t, s);
    return; // optionnel
}

int main() {
    message("Erreur", "Ceci est une erreur grave!!");
    message("Avertissement", "Bon je vais laisser courir pour cette fois.");
    return 0;
}
