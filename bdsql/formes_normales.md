# 1.

entités|attributs|associations & cardinalités
---|---|---
pâtes|code, désignation, nombre de balles / unité, pays d'origine|
société|code, type, nom, details|
commandes|id, code société fournisseur, code pate, date du contrat, quantité (Précision au millième), prix à la tonne, port de départ, code société transport, date mise à disposition|Pâtes,sociétés
transports|id, type, code société, prix tonne, nb camion, lieu enlèvement, date dechargement|commandes, sociétés

# 2.

    

# 3.

## Laissez moi mes requêtes SQL

```sql
CREATE TABLE IF NOT EXISTS pates(
    TYPE UNIQUE NOT NULL PRIMARY KEY,
);
```