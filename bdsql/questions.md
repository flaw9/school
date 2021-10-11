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
À partir de la question 11, les réponses données renvoient, pour certaines, des **ERREURS** ou un **résultat non attendu / non complet** lors des essais effectués sur la base. Elles sont marquées d'une étoile.
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
SELECT nom, (salaire + comission) FROM employe WHERE comission NOT NULL AND poste = "Vendeur"
UNION
SELECT nom, salaire FROM employe WHERE comission IS NULL AND poste = "Vendeur";
```

## 18.

```sql
SELECT nom, (salaire + comission) FROM employe WHERE comission NOT NULL
UNION
SELECT nom, salaire FROM employe WHERE comission IS NULL;
```

## 19.

```sql
SELECT salaire FROM employe WHERE nom = "Jones";
```

## 20.

```sql
SELECT AVG(salaire) FROM employe WHERE poste = "Vendeur";
```

## 21.

```sql
SELECT nom FROM employe WHERE salaire > (SELECT salaire FROM employe WHERE nom = "Jones");
```

## 22

### 1.

```sql
SELECT nom FROM employe WHERE poste = (SELECT poste FROM employe WHERE nom = "Jones") AND nom != "Jones";
```

### 2.
#### 1.
```sql
SELECT nom FROM employe AS e JOIN employe AS j ON e.poste = j.poste WHERE j.nom = "Jones" AND e.nom != "Jones";
```
#### 2.
```sql
SELECT nom FROM employe AS e, employe AS j WHERE e.poste = j.poste AND j.nom = "Jones" AND e.nom != "Jones";
```

## 23

### 1.

```sql
SELECT nom FROM employe WHERE chef = (SELECT chef FROM employe WHERE nom = "Jones") AND nom != "Jones";
```

### 2.
#### 1.
```sql
SELECT e.nom FROM employe AS e JOIN employe AS j ON e.chef = j.chef WHERE j.nom = "Jones" AND e.nom != "Jones";
```
#### 2.
```sql
SELECT e.nom FROM employe AS e, employe AS j WHERE e.chef = j.chef AND j.nom = "Jones" AND e.nom != "Jones";
```

## 24

### 1.
```sql
SELECT e.nom FROM employe AS e, employe AS m WHERE e.poste = m.poste AND e.chef = m.chef AND m.nom = "Martin";
```
### 2.
```sql
SELECT e.nom FROM employe AS e JOIN employe AS m ON e.poste = m.poste AND e.chef = m.chef WHERE m.nom = "Martin";
```
### 3.
```sql
```

## 25.

```sql
SELECT nom, MAX(salaire), poste FROM employe;
```

## 26.

```sql
```

## 27.

```sql
SELECT COUNT(DISTINCT poste) FROM employe;
```

## 28.

```sql
SELECT COUNT(matricule) FROM employe WHERE numdep = 10;
```

## 29.

```sql
SELECT SUM(salaire) FROM employe WHERE numdep = 10;
```

## 30.

```sql
SELECT e.nom FROM employe AS e JOIN employe AS c WHERE e.numdep != c.numdep AND e.chef = c.matricule;
```