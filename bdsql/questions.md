## 1.

```sql
SELECT nom, salaire, poste FROM employe;
```

## 2.

```sql
SELECT dnom, localisation FROM departement;
```

## 3.

```sql
SELECT e.nom, e.poste, e.salaire FROM employe AS e WHERE poste = "Vendeur";
```

## 4.

```sql
SELECT matricule, nom, salaire FROM employe WHERE salaire > 1800;
```

## 5.

```sql
SELECT COUNT(*) FROM employe WHERE poste = "Vendeur";
```

## 6.

```sql
SELECT COUNT(*) FROM departement WHERE localisation = "Paris";
```

## 7.

```sql
SELECT COUNT(*) FROM employe WHERE salaire > 2000;
```

## 8.

```sql
SELECT SUM(salaires) FROM employe WHERE poste = "Vendeur";
```

## 9.

```sql
SELECT nom, salaire, poste FROM employe WHERE numdep = (SELECT numdep FROM employe WHERE nom = "Martin");
```

## 10.

```sql
SELECT DISTINCT poste FROM employe;
```

# !!!
À partir de la question 11, les réponses données renvoient, pour certaines, des **ERREURS** ou un **résultat non attendu / nom complet** lors des essais effectués sur la base. Elles sont marquées d'une étoile.
# !!!

## 11.

```sql
SELECT e.nom, c.nom FROM employe AS e JOIN employe AS c ON e.chef = c.matricule;
```

## 12. *
> *Résultat non attendu*

```sql
SELECT e.nom, c.nom FROM employe AS e JOIN employe AS c ON e.chef = c.matricule OR e.chef IS NULL;
```

## 13.

```sql
SELECT nom, poste, localisation FROM employe, departement WHERE numdep = dnum;
```

## 14.

```sql
SELECT dnom, COUNT(*) FROM departement, employe WHERE dnum = numdep GROUP BY dnom;
```

## 15. *
> *Résultat non attendu*

```sql
SELECT DISTINCT e.poste, count(m.nom) FROM employe AS e JOIN employe AS m ON m.poste = e.poste GROUP BY e.poste;
```

## 16.

```sql
SELECT g.poste, AVG(e.salaire) FROM employe AS g JOIN employe AS e ON g.poste = e.poste GROUP BY g.poste;
```

## 17.

```sql
SELECT nom, (salaire + comission) FROM employe WHERE comission NOT NULL
UNION
SELECT nom, salaire FROM employe WHERE comission IS NULL;
```