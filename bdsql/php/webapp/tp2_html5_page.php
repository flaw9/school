<?php
function begin_html($title) {
  print('<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>'.$title.'</title>
</head>
<body>');
}

function menu_appli($user='Votre Nom'){
  print('<style>
nav {
	background-color: #FFF;
	margin: 0;
	overflow: hidden;
}
nav ul {
	background: gray;
	margin: 0;
	padding: 0;
	list-style: none;
	width: 100%;
}
nav li {
	float: left;
	position: relative
	margin: 0;
	padding: 0;
	width:auto;
}
nav li:hover a {
	background: #000000;
}
nav a {
	background: #30A6E6;
	color: #FFFFFF;
	display: block;
	font: bold 12px/20px sans-serif;
	padding: 10px 25px;
	text-align: center;
	text-decoration: none;
}
</style>
<nav><ul>
  <li><a href="index.php">Home</a></li><li><a href="liste_contact.php">Liste des contacts</a></li>
  <li><a href="ajout_contact.php">Ajouter un contact</a></li><li><a href="recherche_contact.php">Rechercher un contact</a></li>
  <li><a href="deconnexion.php?user='.$user.'">'.$user.' : Déconnexion</a></li>
</ul></nav>');
}
function end_html(){
  print('</body>
</html>');
}
