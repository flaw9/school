# Exercice 1

## 2.

```sql
CREATE TABLE IF NOT EXISTS `user` (uid INTEGER PRIMARY KEY AUTO_INCREMENT, identifiant TEXT NOT NULL, passe TEXT NOT NULL);
CREATE TABLE IF NOT EXISTS `contact` (cid INTEGER PRIMARY KEY AUTO_INCREMENT, uid INT, nom TEXT NOT NULL, entreprise TEXT, fonction TEXT, telfix TEXT, telport TEXT, email TEXT, website TEXT, adresse TEXT, rib TEXT, notes TEXT, datederniercontact TIMESTAMP);
```

## 3.

```sql
SELECT cid FROM contact JOIN user ON user.uid = contact.uid WHERE user.uid = :uid;
```

## 4.

```sql
SELECT * FROM contact WHERE cid = :cid;
```