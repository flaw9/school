# 2) Création et modélisation de la BD

## b.

```sql
CREATE TABLE IF NOT EXISTS Pilote (
    NoPil int NOT NULL PRIMARY KEY,
    NomPil text NOT NULL,
    NatPil text NOT NULL,
    NoTV int NOT NULL,
);
```

# 3) Éxécution de requêtes SQL

## 1.

```sql
SELECT NomPil FROM Pilote JOIN TypeVoiture ON Pilote.NoTV = TypeVoiture.NoTV AND Moteur = "Renault";
```

```sql
SELECT NomPil FROM Pilote WHERE NoTV IN (SELECT NoTV FROM TypeVoiture WHERE Moteur = "Renault");
```


## 2.

```sql
SELECT NomPil FROM Pilote JOIN GrandPrix ON Pilote.NoPil = GrandPrix.NoPil WHERE NomGP = "Monaco";
```

```sql
SELECT NomPil FROM Pilote WHERE NoPil = (SELECT NoPil FROM GrandPrix WHERE NomGP = "Monaco");
```

## 3.

```sql
SELECT p.NomPil, v.NomTV FROM Pilote as p, TypeVoiture as v, GrandPrix as gp WHERE gp.NoPil = p.NoPil AND gp.LieuCirc = "Monza" AND p.NoTV = v.NoTV;
```

## 4.

```sql
SELECT DISTINCT NatPil FROM Pilote as p JOIN TypeVoiture as t ON p.NoTV = t.NoTV WHERE NomTV = "Williams";
```

## 5.

```sql
SELECT g.NomGP, g.DateGP, p.NomPil, t.NomTV FROM GrandPrix as g, Pilote as p, TypeVoiture as t WHERE g.NoPil = p.NoPil AND p.NoTV = t.NoTV ORDER BY g.DateGP;
```

## 6.

```sql
SELECT COUNT(r.NoGP), p.NomPil FROM Pilote as p, Resultat as r WHERE r.NoPil = p.NoPil GROUP BY p.NomPil;
```

## 7.

```sql
SELECT COUNT(r.NoGP), p.NomPil FROM Pilote as p, Resultat as r WHERE r.NoPil = p.NoPil AND r.Place = 1 GROUP BY p.NomPil
```

## 8.

```sql
SELECT COUNT(g.RecTour), p.NomPil, v.NomTV FROM Pilote as p, GrandPrix as g, TypeVoiture as v WHERE g.NoPil = p.NoPil AND p.NoTV = v.NoTV GROUP BY p.NomPil;
```

## 9.

>> Fonctionne pas

```sql
SELECT p.NomPil, v.NomTV, COUNT(*) from Pilote as p, TypeVoiture as v, Resultat as r  WHERE p.NoTV = v.NoTV AND r.NoPil = p.NoPil WHERE r.Place >= 99 GROUP BY p.NomPil HAVING COUNT(*) >= 2
```

## 10.

```sql
SELECT v.NomTV, AVG(r.PtObt) FROM TypeVoiture as v, Resultat as r, Pilote as p WHERE r.NoPil = p.NoPil AND p.NoTV = v.NoTV GROUP BY v.NomTV
```

## 11.

```sql
SELECT p.NomPil, r.PtObt FROM Pilote as p, Resultat as r, GrandPrix as g WHERE p.NoPil = r.NoPil AND r.NoGP = g.NoGP AND g.NomGP = "Italie" ORDER BY r.PtObt DESC;
```

## 12.

```sql
SELECT p.NomPil, r.PtObt 
```