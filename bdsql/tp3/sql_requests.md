# 3) Éxécution de requêtes SQL

## 1.

```sql
SELECT NomPil FROM Pilote JOIN TypeVoiture ON Pilote.NoTV = TypeVoiture.NoTV AND Moteur = "Renault";
```