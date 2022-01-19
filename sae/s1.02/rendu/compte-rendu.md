# SAÉ 01.02 - Comparaison d'approches algorithmiques - Naissances multiples

## Procédé

Pour réaliser la SAÉ, j'ai tout d'abord réalisé, au brouillon, un bainstorming des informations à garder, de celles à éliminer et de comment je souhaitais m'y prendre.

La solution qui m'a paru évidente était d'utiliser une liste chaînée, qui contiendrait un ensemble de structures, une par prénom, avec les informations relatives à ce dernier.

J'ai donc commencé à rédiger les premières lignes de codes, c'est à dire le menu et le programme principal. Ce dernier contient la vérification du nombre d'arguments ainsi qu'une étape qui confirme l'existence du fichier ainsi que la possibilité de le lire.

Ensuite, j'ai entamé le développement du fichier `data.c`, j'ai récupéré une partie des codes réalisés en classe lors des TP sur les listes chaînées, et l'ai adapté à l'utilisation que je souhaitais en faire. J'ai ainsi créé les fonction relatives à la structure `Prénom`, afin de pouvoir récupérer les données, les comparer et les modifier (Première et dernière années, comparaison de prénoms).

Puis je me suis attaqué à la lecture du fichier. Pour ce faire, j'ai décidé de le lire ligne par ligne, et soit de compléter une structure déja présente dans la liste, soit ajouter un nouveau chaînon. J'ai aussi isolé la première ligne qui contient l'intitulé des colonnes. La lecture prennant quelques secondes, j'ai pensé judicieux d'ajouter un petit message indiquant que le programme était bien fonctionnel. Chaque passage, en plus de compléter la liste, incrémente une variable contenant le nombre total de naissances. Lors de cette étape, j'ai rencontré plusieurs difficultés, notamment lorsqu'il s'agissait de retrouver un prénom dans la liste afin de compléter la structure y étant associé. Mais, après plusieurs tentatives infructueuses, j'ai trouvé la solution en ajoutant `tempL`, qui me permet de compléter un élément déjà présent sans pour autant perdre la tête de la liste. Toutefois, bien qu'on ai maintenant les naissances masculines et féminines réunies, les femmes dont l'année n'est pas XXXX ne sont malheureusement pas comptées. La solution a été testée sur deux échantillons (Malheureusement le deuxième a effacé le premier).

## Fonctionnalités et limites

Le programme rempli les fonctions suivantes:

- Affichage d'un menu ;
- Lecture d'une entrée utilisateur (Instruction & Prénom)
- Lecture d'un fichier csv
- Stockage et affichage des données
  - Nombre total de naissances
  - Nombre total de prénoms
    - Nombre de naissances par prénom (Hommes & Femmes / Totales)
    - Première année d'apparition
    - Dernière année d'apparition
- Message d'erreur en cas d'absence de données pour un prénom

Les quelques limitations et problèmes encontrés:

- Un certain temps est nécessaire pour la lecture du fichier.
- Lorsque l'utilisateur entre des caractères autres que des entiers en tant qu'instruction le programme s'emballe.
- Un grand nombre de boucles ... Une complexité qui pourrait être améliorée.
- Il semblerait que certaines lignes (Les femmes dont l'année n'est pas XXXX) ne soient pas comptabilisées dans les nombres de naissances ... Je n'en ai pas trouvé la cause, malgré un grand nombre de test et un long moment de recherche.
