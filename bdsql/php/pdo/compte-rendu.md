# Exercice 2

- Ligne 1

Ouverture de la balise `php`.

- Ligne 2

On essaye d'exécuter la suite du code, en cas d'erreur on se dirige vers la ligne 9.

- Ligne 4

On définit les variables `$user` et `$pass`.

- Ligne 5

On se connecte à la base de données.

- Ligne 7

On ferme la connexion.

- Ligne 9

On exécute ce code en cas d'erreur.

# Exercice 3

Les 2 méthodes de la classe PDO qui construisent un objet de la `classe` PDOStatement sont `query()` et `prepare()`
La méthode `query()` renvoie un objet PDOStatement avec un jeu de données. Cet objet peut donc
exécuter ses méthodes `fetch()`, `fetchAll()` , `fetchObject()` et `fetchColumn()` qui permettent de récupérer des
données dans son `jeu d'enregistrement`.
La méthode `prepare()` renvoie un objet PDOStatement qui contient une requête « compilée » mais
pas de jeu de données car la requête SQL n’a pas été `éxécutée` Il ne peut donc pas utiliser les
méthodes dont le nom commence par `fetch` et qui nécessitent un jeu de données.
Dans tous les cas, cet objet PDOStatement doit d’abord exécuter sa méthode `execute()` en lui
passant un `ensemble de` paramètres.
S’il s’agit d’une requête SELECT, cela lui permettra de récupérer un `jeu de données`.

# Exercice 4

