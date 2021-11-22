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
SELECT p.NomPil, v.NomTV FROM Pilote as p, TypeVoiture as v, GrandPrix as gp JOIN resultat as r ON gp.NoGP = r.NoGP WHERE r.NoPil = p.NoPil AND r.PtObt = max(r.PtObt);
```