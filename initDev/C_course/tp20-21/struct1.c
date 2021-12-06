#include <stdio.h>

struct temps
{
    int heures;
    int minutes;
    float secondes;
};
typedef struct temps temps;

void TempsAfficher(temps t)
    // Affiche le temps.
{
    printf("Il est %d heures, %d minutes et %f secondes.\n", t.heures, t.minutes, t.secondes);
}

temps TempsCreer(int Heures, int Minutes, float Secondes)
    // Créé le temps.
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
    temps t;
    t.heures = sec / 3600;
    t.minutes = (sec - (t.heures * 3600)) / 60;
    t.secondes = sec - (t.heures * 3600 + t.minutes * 60);

    return t;
}

float TempsEnSecondes(temps t)/*Renvoie la valeur en secondes du temps entré en paramètre.*/{return t.heures*3600+t.minutes*60+t.secondes;}

int TempsComparer(temps t1, temps t2)
    /* Compare le temps t1 et le temps t2 entré en paramètres.
    - renvoie 1 si t1 est plus long que t2 ;
    - renvoie 0 si t1 est aussi long que t2 ;
    - renvoie -1 si t1 est plus court que t2 ;
    */
{
    if (t1.heures > t2.heures) { return 1; }
    else if (t1.heures < t2.heures) { return -1; }
    else {
        if (t1.minutes > t2.minutes) { return 1; }
        else if (t1.minutes < t2.minutes) { return -1; }
        else {
            if (t1.secondes > t2.secondes) { return 1; }
            else if (t1.secondes < t2.secondes) { return -1; }
            else { return 0; }
        }
    }
}

temps TempsValider(temps t)
    // Renvoie le temps de manière lisible (minutes < 60, secondes < 60).
{
    while (t.secondes > 60)
    {
        t.minutes += 1;
        t.secondes -= 60;
    } while (t.secondes < 0)
    {
        t.minutes -= 1;
        t.secondes += 60;
    } while (t.minutes > 60)
    {
        t.heures += 1;
        t.minutes -= 60;
    } while (t.minutes < 0)
    {
        t.heures -= 1;
        t.minutes += 60;
    }
    return t;
}

temps TempsAjouter(temps t1, temps t2)
    // Additionne temps t1 et temps t2 et renvoie le résultat.
{
    temps t;
    t.heures = t1.heures + t2.heures;
    t.minutes = t1.minutes + t2.minutes;
    t.secondes = t1.secondes + t2.secondes;

    return TempsValider(t);
}

temps TempsSoustraire(temps t1, temps t2)
    // Soustrait temps t1 et temps t2 et renvoie le résultat.
{
    temps t;
    t.heures = t1.heures - t2.heures;
    t.minutes = t1.minutes - t2.minutes;
    t.secondes = t1.secondes - t2.secondes;

    return TempsValider(t);
}

int main() {
    // temps t1;
    // t1.heures = 12;
    // t1.minutes = 46;
    // t1.secondes = 38.64;
    // printf("(Sans fonction) Il est %d heures, %d minutes et %f secondes.\n", t1.heures, t1.minutes, t1.secondes);
    
    // temps t2={12,46,38.64};
    // TempsAfficher(t2);

    // temps t3 = TempsCreer(-2, 37, 3);
    // temps t4 = TempsCreer(-1, 3, 10);
    // TempsAfficher(t3);
    // TempsAfficher(t4);

    // temps t;
    // t = TempsAjouter(t3, t4);
    // TempsAfficher(t);

    // t = TempsSoustraire(t3, t4);
    // TempsAfficher(t);

    // float sec;
    // scanf("%f", &sec);

    // temps t4 = TempsCreerSecondes(sec);
    // TempsAfficher(t4);

    // float t4Secondes = TempsEnSecondes(t4);
    // printf("Secondes: %f\n", t4Secondes);

    // printf("%i\n", TempsComparer(t3, t4));

    return 0;
}
