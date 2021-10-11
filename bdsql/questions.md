# 1.

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

## !!!
À partir de la question 11, les réponses données renvoient, pour certaines, des **ERREURS** ou un **résultat non attendu / non complet** lors des essais effectués sur la base. Elles sont marquées d'une étoile.
## !!!

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
SELECT nom, (salaire + commission) FROM employe WHERE commission NOT NULL AND poste = "Vendeur"
UNION
SELECT nom, salaire FROM employe WHERE commission IS NULL AND poste = "Vendeur";
```

## 18.

```sql
SELECT nom, (salaire + commission) FROM employe WHERE commission NOT NULL
UNION
SELECT nom, salaire FROM employe WHERE commission IS NULL;
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
> La date n'étant pas enregistrée au bon format dans la base ...

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

# 2.

## 1.

```sql
CREATE TABLE "departement" (
	"dnum" INTEGER NOT NULL UNIQUE,
	"dnom" TEXT NOT NULL,
	"localisation" TEXT NOT NULL,
	PRIMARY KEY("dnum")
);
```

## 2.

```sql
CREATE TABLE IF NOT EXISTS "employe" (
	"matricule"	INTEGER NOT NULL UNIQUE,
	"nom" TEXT NOT NULL,
	"poste"	TEXT NOT NULL,
	"chef" INTEGER,
	"dateembauche" TEXT NOT NULL,
	"salaire" INTEGER NOT NULL,
	"commission" INTEGER,
	"numdep" INTEGER NOT NULL,
	PRIMARY KEY("matricule")
);
```

*Bonus: Insérer les valeurs utilisée pour l'exercice.*

> Table `employe`

```sql
INSERT INTO employe VALUES (7499, "Allen", "Vendeur", 7698, "20/02/2001", 1600, 300, 30);
INSERT INTO employe VALUES (7521, "Ward", "Vendeur", 7698, "21/02/2011", 1200, 700, 30);
INSERT INTO employe VALUES (7566, "Jones", "Chef Service", 7839, "02/04/1991", 2900, NULL, 20);
INSERT INTO employe VALUES (7654, "Martin", "Vendeur", 7698, "18/09/2008", 1200, 1000, 30);
INSERT INTO employe VALUES (7698, "Blake", "Chef Service", 7839, "01/05/2002", 2800, NULL, 30);
INSERT INTO employe VALUES (7788, "Scott", "Analyste", 7566, "09/12/1990", 3000, NULL, 20);
INSERT INTO employe VALUES (7839, "King", "PDG", NULL, "17/11/2003", 5000, , 10);
INSERT INTO employe VALUES (7876, "Adams", "Secrétaire", 7788, "12/01/2012", 1100, NULL, 20);
INSERT INTO employe VALUES (7934, "Miller", "Secrétaire", 7839, "23/01/1998", 1300, NULL, 10);
```

> Table `departement`

```sql
INSERT INTO departement VALUES (10, "Compatbilité", "Paris");
INSERT INTO departement VALUES (20, "Recherche", "Paris");
INSERT INTO departement VALUES (30, "Vente", "Saint-Dié");
```