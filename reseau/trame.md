# Exercice 1

## a) Faire la mise en trame de chaque fichier

Nombre de trames: 7

- Fichier A: 3 trames (1500 + 1500 + 1036)
- Fichier B: 2 trames (1500 + 548)
- Fichier C: 2 trames (1500 + 548)

Total des octets: 

## d)

Si les différentes trames ne sont pas envoyées les unes à la suite des autres, alors un temps de retard s'accumelera dès lors qu'une trame est précédée d'une trame non liée à ce fichier, plus le traffic est important, plus la vitesse sera réduite.

**Détail des événements lors des émissions**

Temps | Status
---|---
t0 | A veut émettre
t0+0.05 | A émet T-A1 après avoir écouté le silence *négligé par la suite*
t0+0.05+1.21 | Fin d'émission de T-A1
t0+0.05+1.21.0.05 | A émet T6A2 après avoir écouté le silence *négligé par la suite*
t0+2 | B et C veulent émettre mais détectent une porteuse et sont bloqués
t0+2.42 | Fin d'émission de T-A2 et A, B et C veulent émettre
t0+2.42+0.05 | A, B et C émettent et détectent une collision X1

