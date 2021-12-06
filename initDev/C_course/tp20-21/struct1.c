#include <stdio.h>

struct temps
{
    int heures;
    int minutes;
    float secondes;
};
typedef struct temps temps;

void TempsAfficher(temps t)
{
    printf("Il est %d heures, %d minutes et %f secondes.\n", t.heures, t.minutes, t.secondes);
}

temps TempsCreer(int Heures, int Minutes, float Secondes)
{
    temps t;
    t.heures = Heures;
    t.minutes = Minutes;
    t.secondes = Secondes;
    
    return t;
}

temps TempsCreerSecondes(float sec)
    // Fonction qui renvoie une structure temps à partir d'un nombre de secondes passé en paramètre.
{
    printf("%f", sec);
    temps t;
    t.heures = sec / 3600;
    t.minutes = (sec - (t.heures * 3600)) / 60;
    t.secondes = sec - (t.heures * 3600 + t.minutes * 60);

    return t;
}

int main() {
    // temps t1;
    // t1.heures = 12;
    // t1.minutes = 46;
    // t1.secondes = 38.64;
    // printf("(Sans fonction) Il est %d heures, %d minutes et %f secondes.\n", t1.heures, t1.minutes, t1.secondes);
    
    // temps t2={12,46,38.64};
    // TempsAfficher(t2);

    // temps t3 = TempsCreer(12, 46, 38.64);
    // TempsAfficher(t3);

    float sec;
    scanf("%f", sec);

    temps t4 = TempsCreerSecondes(sec);
    TempsAfficher(t4);

    return 0;
}
