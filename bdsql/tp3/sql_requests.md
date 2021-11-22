# 3) Éxécution de requêtes SQL

## 1.

```sql
SELECT NomPil FROM Pilote JOIN TypeVoiture ON Pilote.NoTV = TypeVoiture.NoTV AND Moteur = "Renault";
```

```sql
SELECT NomPil FROM Pilote WHERE NoTV = (SELECT NoTV FROM TypeVoiture WHERE Moteur = "Renault");
```


## 2.

```sql
SELECT NomPil FROM Pilote JOIN GrandPrix ON Pilote.NoPil = GrandPrix.NoPil WHERE NomGP = "Monaco";
```

```sql
SELECT NomPil FROM Pilote WHERE NoPil = (SELECT NoPil FROM GrandPrix WHERE NomGP = "Monaco");
```