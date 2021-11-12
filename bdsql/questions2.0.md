# 1.

## 1.

```sql
SELECT enom, esal, eposte FROM employe;
```

## 2.

```sql
SELECT dnom, DLoc FROM departement;
```

## 3.

```sql
SELECT enom, eposte, esal FROM employe WHERE eposte = "Vendeur";
```

## 4.

```sql
SELECT matricule, enom, esal FROM employe WHERE esal > 1800;
```

## 5.

```sql
SELECT COUNT(*) FROM employe WHERE eposte = "Vendeur";
```

## 6.

```sql
SELECT COUNT(*) FROM departement WHERE DLoc = "Paris";
```

## 7.

```sql
SELECT COUNT(*) FROM employe WHERE esal > 2000;
```

## 8.

```sql
SELECT SUM(salaires) FROM employe WHERE eposte = "Vendeur";
```

## 9.

```sql
SELECT enom, esal, eposte FROM employe WHERE enumdep = (SELECT enumdep FROM employe WHERE enom = "Martin");
```

## 10.

```sql
SELECT DISTINCT eposte FROM employe;
```

## !!!
À partir de la question 11, les réponses données renvoient, pour certaines, des **ERREURS** ou un **résultat non attendu / non complet** lors des essais effectués sur la base. Elles sont marquées d'une étoile.
## !!!

## 11.

```sql
SELECT e.enom, c.enom FROM employe AS e JOIN employe AS c ON e.chef = c.matricule;
```

## 12. *
> *Résultat non attendu*

```sql
SELECT e.enom, c.enom FROM employe AS e JOIN employe AS c ON e.chef = c.matricule OR e.chef IS NULL;
```

## 13.

```sql
SELECT enom, eposte, DLoc FROM employe, departement WHERE enumdep = dnum;
```

## 14.

```sql
SELECT dnom, COUNT(*) FROM departement, employe WHERE dnum = enumdep GROUP BY dnom;
```

## 15. *
> *Résultat non attendu*

```sql
SELECT DISTINCT e.eposte, count(m.enom) FROM employe AS e JOIN employe AS m ON m.eposte = e.eposte GROUP BY e.eposte;
```

## 16.

```sql
SELECT g.eposte, AVG(e.esal) FROM employe AS g JOIN employe AS e ON g.eposte = e.eposte GROUP BY g.eposte;
```

## 17.

```sql
SELECT enom, (esal + ecomm) FROM employe WHERE ecomm NOT NULL AND eposte = "Vendeur"
UNION
SELECT enom, esal FROM employe WHERE ecomm IS NULL AND eposte = "Vendeur";
```

## 18.

```sql
SELECT enom, (esal + ecomm) FROM employe WHERE ecomm NOT NULL
UNION
SELECT enom, esal FROM employe WHERE ecomm IS NULL;
```

## 19.

```sql
SELECT esal FROM employe WHERE enom = "Jones";
```

## 20.

```sql
SELECT AVG(esal) FROM employe WHERE eposte = "Vendeur";
```

## 21.

```sql
SELECT enom FROM employe WHERE esal > (SELECT esal FROM employe WHERE enom = "Jones");
```

## 22

### 1.

```sql
SELECT enom FROM employe WHERE eposte = (SELECT eposte FROM employe WHERE enom = "Jones") AND enom != "Jones";
```

### 2.
#### 1.
```sql
SELECT enom FROM employe AS e JOIN employe AS j ON e.eposte = j.eposte WHERE j.enom = "Jones" AND e.enom != "Jones";
```
#### 2.
```sql
SELECT enom FROM employe AS e, employe AS j WHERE e.eposte = j.eposte AND j.enom = "Jones" AND e.enom != "Jones";
```

## 23

### 1.

```sql
SELECT enom FROM employe WHERE chef = (SELECT chef FROM employe WHERE enom = "Jones") AND enom != "Jones";
```

### 2.
#### 1.
```sql
SELECT e.enom FROM employe AS e JOIN employe AS j ON e.chef = j.chef WHERE j.enom = "Jones" AND e.enom != "Jones";
```
#### 2.
```sql
SELECT e.enom FROM employe AS e, employe AS j WHERE e.chef = j.chef AND j.enom = "Jones" AND e.enom != "Jones";
```

## 24

### 1.
```sql
SELECT e.enom FROM employe AS e, employe AS m WHERE e.eposte = m.eposte AND e.chef = m.chef AND m.enom = "Martin" AND e.enom != "Martin";
```
### 2.
```sql
SELECT e.enom FROM employe AS e JOIN employe AS m ON e.eposte = m.eposte AND e.chef = m.chef WHERE m.enom = "Martin" AND e.enom != "Martin";
```
### 3.
```sql
```

## 25.

```sql
SELECT enom, MAX(esal), eposte FROM employe;
```

## 26.
> La date n'étant pas enregistrée au bon format dans la base ...

```sql
```

## 27.

```sql
SELECT COUNT(DISTINCT eposte) FROM employe;
```

## 28.

```sql
SELECT COUNT(matricule) FROM employe WHERE enumdep = 10;
```

## 29.

```sql
SELECT SUM(esal) FROM employe WHERE enumdep = 10;
```

## 30.

```sql
SELECT e.enom FROM employe AS e JOIN employe AS c WHERE e.enumdep != c.enumdep AND e.chef = c.matricule;
```

# 2.

## 1.

```sql
CREATE TABLE "departement" (
	"dnum" INTEGER NOT NULL UNIQUE,
	"dnom" TEXT NOT NULL,
	"DLoc" TEXT NOT NULL,
	PRIMARY KEY("dnum")
);
```

## 2.

```sql
CREATE TABLE IF NOT EXISTS "employe" (
	"matricule"	INTEGER NOT NULL UNIQUE,
	"enom" TEXT NOT NULL,
	"eposte"	TEXT NOT NULL,
	"chef" INTEGER,
	"dateembauche" TEXT NOT NULL,
	"esal" INTEGER NOT NULL,
	"ecomm" INTEGER,
	"enumdep" INTEGER NOT NULL,
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
INSERT INTO employe VALUES (7839, "King", "PDG", NULL, "17/11/2003", 5000, NULL, 10);
INSERT INTO employe VALUES (7876, "Adams", "Secrétaire", 7788, "12/01/2012", 1100, NULL, 20);
INSERT INTO employe VALUES (7934, "Miller", "Secrétaire", 7839, "23/01/1998", 1300, NULL, 10);
```

> Table `departement`

```sql
INSERT INTO departement VALUES (10, "Compatbilité", "Paris");
INSERT INTO departement VALUES (20, "Recherche", "Paris");
INSERT INTO departement VALUES (30, "Vente", "Saint-Dié");
```

# 3.

## 1.

```sql
UPDATE employe SET esal = esal * 1.10 WHERE ecomm > 0.5 * esal;
```