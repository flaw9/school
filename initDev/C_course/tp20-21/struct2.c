// fichier struct2.c
#include <stdio.h>
#include <stdlib.h>

struct temps
{
  int heures;
  int minutes;
  float secondes;
};
typedef struct temps temps;

temps * TempsCreer(int Heures, int Minutes, float Secondes)
{
  temps *t;
  t=malloc(sizeof(temps));
  t->heures = Heures;
  t->minutes = Minutes;
  t->secondes = Secondes;
  return t;
}

temps * TempsDetruire(temps *t)
{
   if (t) free(t);
   return (temps*)NULL;
}

void TempsAfficher(temps *t)
{
  printf("Il est %d heures, %d minutes, %f secondes\n",t->heures, t->minutes, t->secondes);
}

int main()
{
  temps *t1=malloc(sizeof(temps));
  t1->heures=12;
  t1->minutes=46;
  t1->secondes=38.64;
  printf("(Sans fonction) Il est %d heures, %d minutes, %f secondes\n",t1->heures, t1->minutes, t1->secondes);
  free(t1);
  printf("Après free: %p\n",t1);

  temps *t2=TempsCreer(0,0,0);
  *t2=(temps){12,46,38.64};
  TempsAfficher(t2);
  TempsDetruire(t2);
  printf("Après Detruire sans affectation: %p\n",t2);

  temps *t3=TempsCreer(12,46,38.64);
  TempsAfficher(t3);
  t3=TempsDetruire(t3);  
  printf("Après Detruire avec affectation: %p\n",t3);

  return 0;
}
