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
