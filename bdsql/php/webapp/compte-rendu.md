# Exercice 1

## 2.

```sql
CREATE TABLE IF NOT EXISTS `user` (uid INTEGER PRIMARY KEY AUTO_INCREMENT, identifiant TEXT NOT NULL, passe TEXT NOT NULL);
CREATE TABLE IF NOT EXISTS `contact` (cid INTEGER PRIMARY KEY AUTO_INCREMENT, uid INT, nom TEXT NOT NULL, entreprise TEXT, fonction TEXT, telfix TEXT, telport TEXT, email TEXT, website TEXT, adresse TEXT, rib TEXT, notes TEXT, datederniercontact TIMESTAMP);
```

## 4.

```sql
SELECT cid FROM contact JOIN user ON user.uid = contact.uid WHERE user.uid = :uid;
```

## 5.

```sql
SELECT * FROM contact WHERE cid = :cid;
```

# Exercice 2

## 1.

La fonction permet de récupérer le `cid` du/des contact(s) qui ont la valeur `$val`, ou qui a contiennent, pour le champ `$field` et qui sont les contacts de l'utilisateur dont l'uid est `$uid`.

## 2.

Lors de l'appel 
```php
get_contact_id_by_user_field_value($pdo, 1, 'email', 'univ-lorraine')
```
, la fonction renvoie le `cid` des contacts de l'utilisateur ayant l'uid `1` dont le champ `email` contient la chaine de caractères `univ-lorraine`.

## 3.

```php
function get_contact_id_by_user_id($pdo, $uid){
    $sql = "SELECT cid FROM contact WHERE uid = $uid";
    $stmt = $pdo->prepare($sql);
    return $stmt->fetchAll(PDO::FETCH_COLUMN);
}
```

## 4.

```php
function get_contact_by_contact_id($pdo, $cid){
    $sql = "SELECT * FROM contact WHERE cid = $cid";
    $stmt = $pdo->prepare($sql);
    return $stmt->fetchAll();
}
```

*Terminé à 11 heures 18 minutes*

# Exercice 3

